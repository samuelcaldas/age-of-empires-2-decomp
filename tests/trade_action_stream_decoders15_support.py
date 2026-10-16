"""Support fixtures and compilation helpers for trade action stream decoders15."""

import hashlib
from io import BytesIO
import subprocess
from pathlib import Path

import pytest
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/trade_action_stream_decoders15.cpp"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = ROOT / "build/tools/wibo"
LINKER = ROOT / "build/mips_binutils/mips-linux-gnu-ld"

# PT_LOAD VRAM derivation:
# p_vaddr = 0x100000, p_offset = 0x1E0 -> VRAM = file_offset + 0xFFE20.
# decoders15 slice: file 0x5FF50 to 0x605E0 (size 0x690 = 1,680 bytes).
FILE_OFFSET = 0x5FF50
START_ADDRESS = FILE_OFFSET + 0xFFE20  # 0x15FD70
SLICE_SIZE = 0x690
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"

# Function offsets and sizes (excluding alignment padding):
# func_0015FD70: 0x15FD70, 392 bytes (0x188) + 8B pad = 400 bytes (0x190)
# func_0015FF00: 0x15FF00, 336 bytes (0x150) + 0B pad = 336 bytes (0x150)
# func_00160050: 0x160050, 404 bytes (0x194) + 12B pad = 416 bytes (0x1A0)
# func_001601F0: 0x1601F0, 524 bytes (0x20C) + 4B pad = 528 bytes (0x210)
FD70_OFFSET = 0x000
FD70_SIZE = 0x188

PAD1_OFFSET = 0x188
PAD1_SIZE = 0x008

FF00_OFFSET = 0x190
FF00_SIZE = 0x150

F0050_OFFSET = 0x2E0
F0050_SIZE = 0x194

PAD3_OFFSET = 0x474
PAD3_SIZE = 0x00C

F01F0_OFFSET = 0x480
F01F0_SIZE = 0x20C

PAD4_OFFSET = 0x68C
PAD4_SIZE = 0x004

FUNCTIONS = (
    ("func_0015FD70", START_ADDRESS + FD70_OFFSET, FD70_SIZE),
    ("func_0015FF00", START_ADDRESS + FF00_OFFSET, FF00_SIZE),
    ("func_00160050", START_ADDRESS + F0050_OFFSET, F0050_SIZE),
    ("func_001601F0", START_ADDRESS + F01F0_OFFSET, F01F0_SIZE),
)

EXTERNAL_SYMBOLS = {
    "_gp": 0x4EA7C0,
    "D_004E2DA0": 0x4E2DA0,
    "D_004E2DA4": 0x4E2DA4,
    "D_004E2DAC": 0x4E2DAC,
    "D_004E2DB4": 0x4E2DB4,
    "func_001522C0": 0x1522C0,
}


def require_private_inputs():
    required = (ORIGINAL, COMPILER, WRAPPER, LINKER)
    missing = [str(path) for path in required if not path.is_file()]
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))


def original_load_mapping(original_bytes):
    with BytesIO(original_bytes) as stream:
        elf = ELFFile(stream)
        segments = [
            segment for segment in elf.iter_segments()
            if segment["p_type"] == "PT_LOAD"
            and segment["p_vaddr"] <= START_ADDRESS
            and START_ADDRESS + SLICE_SIZE <= segment["p_vaddr"] + segment["p_filesz"]
        ]
        assert len(segments) == 1, f"expected one file-backed PT_LOAD, got {len(segments)}"
        segment = segments[0]
        file_offset = segment["p_offset"] + START_ADDRESS - segment["p_vaddr"]
        mapping = segment["p_offset"], segment["p_vaddr"], segment["p_filesz"]
    assert file_offset == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= mapping[0] + mapping[2]
    return mapping


@pytest.fixture(scope="module")
def original_image():
    require_private_inputs()
    original_bytes = ORIGINAL.read_bytes()
    assert hashlib.sha1(original_bytes).hexdigest() == ORIGINAL_SHA1, "AOK.ELF SHA1 mismatch"
    original_load_mapping(original_bytes)
    return original_bytes


def assert_function_symbols(elf_file, linked=False):
    symbol_table = elf_file.get_section_by_name(".symtab")
    assert symbol_table is not None
    section_indices = []
    for name, address, size in FUNCTIONS:
        matches = symbol_table.get_symbol_by_name(name)
        assert matches is not None and len(matches) == 1, name
        symbol = matches[0]
        assert symbol["st_info"]["type"] == "STT_FUNC" and symbol["st_size"] == size
        section_index = symbol["st_shndx"]
        assert isinstance(section_index, int) and section_index > 0
        section = elf_file.get_section(section_index)
        assert section.name == ".text"
        if not linked:
            assert section["sh_size"] == size
        if linked:
            assert symbol["st_value"] == address
            start = address - section["sh_addr"]
        else:
            start = symbol["st_value"]
            section_indices.append(section_index)
        assert len(section.data()[start:start + size]) == size
    if not linked:
        assert len(set(section_indices)) == len(FUNCTIONS), "expected homonymous MWCC .text sections"


def compile_decoders(directory):
    subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
         "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++", "-c",
         str(SOURCE), "-o", str(directory)],
        cwd=ROOT, capture_output=True, text=True, check=True,
    )
    return directory / "trade_action_stream_decoders15.o"


def link_decoders(directory, object_file):
    linker_script = directory / "decoders15.ld"
    definitions = "".join(f"{name} = {address:#x};\n" for name, address in EXTERNAL_SYMBOLS.items())
    linker_script.write_text(
        definitions + "SECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n", encoding="utf-8",
    )
    linked_path = directory / "decoders15.elf"
    subprocess.run(
        [str(LINKER), "-EL", "-m", "elf32ltsmip", "--no-undefined", "-T",
         str(linker_script), "-o", str(linked_path), str(object_file)],
        cwd=ROOT, capture_output=True, text=True, check=True,
    )
    with linked_path.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf.header["e_type"] == "ET_EXEC"
        symbols = elf.get_section_by_name(".symtab")
        unresolved = [symbol.name for symbol in symbols.iter_symbols()
                      if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"]
        assert not unresolved, f"unresolved symbols: {unresolved}"
        for name, address in EXTERNAL_SYMBOLS.items():
            matches = symbols.get_symbol_by_name(name)
            assert matches is not None and len(matches) == 1, name
            assert matches[0]["st_value"] == address, name
        assert_function_symbols(elf, linked=True)
        section = elf.get_section_by_name(".text")
        assert section["sh_addr"] == START_ADDRESS
        code = section.data()
        assert len(code) == SLICE_SIZE
        return code


@pytest.fixture(scope="module")
def decoder_code(tmp_path_factory, original_image):
    directory = tmp_path_factory.mktemp("decoders15")
    object_file = compile_decoders(directory)
    with object_file.open("rb") as stream:
        object_elf = ELFFile(stream)
        assert_function_symbols(object_elf)
        undefined = {symbol.name for symbol in object_elf.get_section_by_name(".symtab").iter_symbols()
                     if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"}
    assert undefined == set(EXTERNAL_SYMBOLS) - {"_gp"}
    return link_decoders(directory, object_file)


def read_original(original_image, offset, size):
    return original_image[FILE_OFFSET + offset:FILE_OFFSET + offset + size]


def assert_same_code(actual, expected, address):
    assert len(actual) == len(expected), f"Code length differs at {address:#x}: {len(actual)} vs {len(expected)}"
    difference = next((i for i, pair in enumerate(zip(actual, expected)) if pair[0] != pair[1]), None)
    assert difference is None, f"Instruction bytes differ at {address + difference:#x}"
