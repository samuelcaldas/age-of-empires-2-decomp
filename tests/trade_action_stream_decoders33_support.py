"""Support fixtures and compilation helpers for trade action stream decoders33."""

import hashlib
from io import BytesIO
import subprocess
from pathlib import Path

import pytest
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/trade_action_stream_decoders33.cpp"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = ROOT / "build/tools/wibo"
LINKER = ROOT / "build/mips_binutils/mips-linux-gnu-ld"

FILE_OFFSET = 0x68090
START_ADDRESS = FILE_OFFSET + 0xFFE20  # 0x167EB0
SLICE_SIZE = 0x2D0  # 720 bytes
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"

F7EB0_OFFSET = 0x000
F7EB0_SIZE = 0x08C

PAD1_OFFSET = 0x08C
PAD1_SIZE = 0x004

F7F40_OFFSET = 0x090
F7F40_SIZE = 0x0B4

PAD2_OFFSET = 0x144
PAD2_SIZE = 0x00C

F8000_OFFSET = 0x150
F8000_SIZE = 0x0B4

PAD3_OFFSET = 0x204
PAD3_SIZE = 0x00C

F80C0_OFFSET = 0x210
F80C0_SIZE = 0x0B4

PAD4_OFFSET = 0x2C4
PAD4_SIZE = 0x00C

FUNCTIONS = (
    ("func_00167EB0", START_ADDRESS + F7EB0_OFFSET, F7EB0_SIZE),
    ("func_00167F40", START_ADDRESS + F7F40_OFFSET, F7F40_SIZE),
    ("func_00168000", START_ADDRESS + F8000_OFFSET, F8000_SIZE),
    ("func_001680C0", START_ADDRESS + F80C0_OFFSET, F80C0_SIZE),
)

EXTERNAL_SYMBOLS = {
    "func_001522C0": 0x1522C0,
    "D_004E2DA0": 0x4E2DA0,
    "D_004E2DB0": 0x4E2DB0,
    "D_004E2DB4": 0x4E2DB4,
    "_gp": 0x4EA7C0,
}


def require_private_inputs():
    missing = [str(p) for p in (ORIGINAL, COMPILER, WRAPPER, LINKER) if not p.is_file()]
    if missing:
        pytest.skip(f"Required inputs missing: {missing}")


def original_load_mapping(original_bytes):
    with BytesIO(original_bytes) as stream:
        elf = ELFFile(stream)
        segments = [
            s for s in elf.iter_segments()
            if s["p_type"] == "PT_LOAD"
            and s["p_vaddr"] <= START_ADDRESS
            and START_ADDRESS + SLICE_SIZE <= s["p_vaddr"] + s["p_filesz"]
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
    data = ORIGINAL.read_bytes()
    assert hashlib.sha1(data).hexdigest() == ORIGINAL_SHA1, "Original ELF SHA1 mismatch"
    original_load_mapping(data)
    return data


def assert_function_symbols(elf, linked=False):
    symbol_table = elf.get_section_by_name(".symtab")
    assert symbol_table is not None, "Missing .symtab section"
    for name, expected_address, expected_size in FUNCTIONS:
        matches = [s for s in symbol_table.iter_symbols() if s.name == name]
        assert len(matches) == 1, f"expected exactly one symbol for {name}"
        symbol = matches[0]
        assert symbol["st_info"]["type"] == "STT_FUNC"
        assert symbol["st_size"] == expected_size
        if linked:
            assert symbol["st_value"] == expected_address
            assert symbol["st_shndx"] != "SHN_UNDEF"
        else:
            assert symbol["st_shndx"] not in ("SHN_UNDEF", "SHN_COMMON")


def compile_decoders(directory):
    cmd = [
        str(WRAPPER), str(COMPILER), "-c", "-O3", "-inline", "on",
        "-msext", "on", "-char", "signed", "-sym", "off",
        "-Iinclude", "-lang=c++", str(SOURCE), "-o",
        str(directory / "trade_action_stream_decoders33.o"),
    ]
    subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, check=True)
    return directory / "trade_action_stream_decoders33.o"


def link_decoders(directory, object_file):
    linker_script = directory / "decoders33.ld"
    definitions = "".join(f"{name} = {address:#x};\n" for name, address in EXTERNAL_SYMBOLS.items())
    linker_script.write_text(
        definitions + "SECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n", encoding="utf-8",
    )
    linked_path = directory / "decoders33.elf"
    subprocess.run(
        [str(LINKER), "-EL", "-m", "elf32ltsmip", "--no-undefined", "-T",
         str(linker_script), "-o", str(linked_path), str(object_file)],
        cwd=ROOT, capture_output=True, text=True, check=True,
    )
    with linked_path.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf.header["e_type"] == "ET_EXEC"
        symbols = elf.get_section_by_name(".symtab")
        unresolved = [s.name for s in symbols.iter_symbols()
                      if s.name and s["st_shndx"] == "SHN_UNDEF"]
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
    directory = tmp_path_factory.mktemp("decoders33")
    object_file = compile_decoders(directory)
    with object_file.open("rb") as stream:
        object_elf = ELFFile(stream)
        assert_function_symbols(object_elf)
        undefined = {s.name for s in object_elf.get_section_by_name(".symtab").iter_symbols()
                     if s.name and s["st_shndx"] == "SHN_UNDEF"}
    assert undefined == set(EXTERNAL_SYMBOLS) - {"_gp"}
    return link_decoders(directory, object_file)


def read_original(original_image, offset, size):
    return original_image[FILE_OFFSET + offset:FILE_OFFSET + offset + size]


def assert_same_code(actual, expected, address):
    assert len(actual) == len(expected), f"Code length differs at {address:#x}"
    difference = next((i for i, pair in enumerate(zip(actual, expected)) if pair[0] != pair[1]), None)
    assert difference is None, f"Instruction bytes differ at {address + difference:#x}"
