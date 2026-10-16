"""Support fixtures and compilation helpers for trade action stream helpers."""

import hashlib
from io import BytesIO
import subprocess
from pathlib import Path

import pytest
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/trade_action_stream_helpers.cpp"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = ROOT / "build/tools/wibo"
LINKER = ROOT / "build/mips_binutils/mips-linux-gnu-ld"

FILE_OFFSET = 0x7DDB0
START_ADDRESS = FILE_OFFSET + 0xFFE20  # 0x17DBD0
SLICE_SIZE = 0x210  # 528 bytes
ORIGINAL_SHA1 = "7ef65f0eb256213440a9326f4dbf0fbbb79dd0bc"

FDBD0_OFFSET, FDBD0_SIZE = 0x000, 0x064
PAD1_OFFSET, PAD1_SIZE = 0x064, 0x00C
FDC40_OFFSET, FDC40_SIZE = 0x070, 0x058
PAD2_OFFSET, PAD2_SIZE = 0x0C8, 0x008
FDCA0_OFFSET, FDCA0_SIZE = 0x0D0, 0x04C
PAD3_OFFSET, PAD3_SIZE = 0x11C, 0x004
FDCF0_OFFSET, FDCF0_SIZE = 0x120, 0x018
PAD4_OFFSET, PAD4_SIZE = 0x138, 0x008
FDD10_OFFSET, FDD10_SIZE = 0x140, 0x080
FDD90_OFFSET, FDD90_SIZE = 0x1C0, 0x034
PAD5_OFFSET, PAD5_SIZE = 0x1F4, 0x00C
FDDD0_OFFSET, FDDD0_SIZE = 0x200, 0x010

FUNCTIONS = (
    ("func_0017dbd0", START_ADDRESS + FDBD0_OFFSET, FDBD0_SIZE),
    ("func_0017dc40", START_ADDRESS + FDC40_OFFSET, FDC40_SIZE),
    ("func_0017dca0", START_ADDRESS + FDCA0_OFFSET, FDCA0_SIZE),
    ("func_0017dcf0", START_ADDRESS + FDCF0_OFFSET, FDCF0_SIZE),
    ("func_0017dd10", START_ADDRESS + FDD10_OFFSET, FDD10_SIZE),
    ("func_0017dd90", START_ADDRESS + FDD90_OFFSET, FDD90_SIZE),
    ("func_0017ddd0", START_ADDRESS + FDDD0_OFFSET, FDDD0_SIZE),
)

EXTERNAL_SYMBOLS = {
    "D_004E2DA0": 0x4E2DA0,
    "D_004E2DA8": 0x4E2DA8,
    "D_0038FB10": 0x38FB10,
    "D_004E3070": 0x4E3070,
    "D_004E3074": 0x4E3074,
    "D_004E3078": 0x4E3078,
    "D_004E307C": 0x4E307C,
    "D_004E3098": 0x4E3098,
    "D_004E30BC": 0x4E30BC,
    "D_004E30D4": 0x4E30D4,
    "D_004E30D8": 0x4E30D8,
    "D_004E30DC": 0x4E30DC,
    "D_004E30E0": 0x4E30E0,
    "D_004E30E4": 0x4E30E4,
    "D_004E30E8": 0x4E30E8,
    "D_004E30F0": 0x4E30F0,
    "D_004E30F4": 0x4E30F4,
    "D_004E30F8": 0x4E30F8,
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
    assert hashlib.sha1(data[FILE_OFFSET:FILE_OFFSET + SLICE_SIZE]).hexdigest() == ORIGINAL_SHA1
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


def compile_helpers(directory):
    cmd = [
        str(WRAPPER), str(COMPILER), "-c", "-O3", "-inline", "on",
        "-msext", "on", "-char", "signed", "-sym", "off",
        "-Iinclude", "-lang=c++", str(SOURCE), "-o",
        str(directory / "trade_action_stream_helpers.o"),
    ]
    subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, check=True)
    return directory / "trade_action_stream_helpers.o"


def link_helpers(directory, object_file):
    linker_script = directory / "helpers.ld"
    definitions = "".join(f"{name} = {address:#x};\n" for name, address in EXTERNAL_SYMBOLS.items())
    linker_script.write_text(
        definitions + "SECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n", encoding="utf-8",
    )
    linked_path = directory / "helpers.elf"
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
def helper_code(tmp_path_factory, original_image):
    directory = tmp_path_factory.mktemp("helpers")
    object_file = compile_helpers(directory)
    with object_file.open("rb") as stream:
        object_elf = ELFFile(stream)
        assert_function_symbols(object_elf)
        undefined = {s.name for s in object_elf.get_section_by_name(".symtab").iter_symbols()
                     if s.name and s["st_shndx"] == "SHN_UNDEF"}
    assert undefined == set(EXTERNAL_SYMBOLS) - {"_gp"}
    return link_helpers(directory, object_file)


def read_original(original_image, offset, size):
    return original_image[FILE_OFFSET + offset:FILE_OFFSET + offset + size]


def assert_same_code(actual, expected, address):
    assert len(actual) == len(expected), f"Code length differs at {address:#x}"
    difference = next((i for i, pair in enumerate(zip(actual, expected)) if pair[0] != pair[1]), None)
    assert difference is None, f"Instruction bytes differ at {address + difference:#x}"
