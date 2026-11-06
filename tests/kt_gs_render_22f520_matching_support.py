"""Fresh MWCC compilation and relocation-aware kt_gs_render_22f520 comparison."""

from pathlib import Path
import struct
import subprocess

import pytest
from elftools.elf.elffile import ELFFile

PROJECT_ROOT = Path(__file__).resolve().parents[1]
ORIGINAL_PATH = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER_PATH = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER_PATH = PROJECT_ROOT / "build/tools/wibo"

FUNCTIONS = {
    "func_0022F520": (0x0022F520, 0x0320),
}

CALLEES = {
    "func_00100850": 0x00100850,
    "func_0021A310": 0x0021A310,
    "func_002240B0": 0x002240B0,
    "func_00227480": 0x00227480,
    "func_002276D0": 0x002276D0,
    "func_00227830": 0x00227830,
    "func_00227900": 0x00227900,
    "func_00228A40": 0x00228A40,
    "func_0022B2B0": 0x0022B2B0,
    "func_0022C1F0": 0x0022C1F0,
    "func_0022CF90": 0x0022CF90,
    "func_0022F950": 0x0022F950,
    "func_00231670": 0x00231670,
    "func_00231760": 0x00231760,
    "func_00232430": 0x00232430,
    "func_00235220": 0x00235220,
    "func_00236F50": 0x00236F50,
    "func_01D98080": 0x01D98080,
}

def require_original():
    if not ORIGINAL_PATH.is_file():
        pytest.skip(f"Original ELF is required: {ORIGINAL_PATH}")

def original_bytes(address: int, size: int) -> bytes:
    offset = 0x12F700 + (address - 0x0022F520)
    with open(ORIGINAL_PATH, "rb") as f:
        f.seek(offset)
        return f.read(size)

def compile_gs_render_22f520(tmp_path: Path) -> Path:
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")

    output_path = tmp_path / "kt_gs_render_22f520.o"
    subprocess.run(
        [
            str(WRAPPER_PATH),
            str(COMPILER_PATH),
            "-O3",
            "-inline",
            "on",
            "-msext",
            "on",
            "-char",
            "signed",
            "-sym",
            "off",
            "-Iinclude",
            "-lang=c++",
            "-c",
            "src/kcet/kt_gs_render_22f520.cpp",
            "-o",
            str(output_path),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    return output_path

def relocate_symbol(data, relocation, symbols):
    r_type = relocation["r_info_type"]
    offset = relocation["r_offset"]
    symbol_name = symbols.get_symbol(relocation["r_info_sym"]).name
    if r_type == 4:  # R_MIPS_26
        target = CALLEES[symbol_name]
        w = struct.unpack_from("<I", data, offset)[0]
        relocated = (w & 0xFC000000) | ((target >> 2) & 0x03FFFFFF)
        struct.pack_into("<I", data, offset, relocated)

def relocate_section(elf, section_index, data):
    for section in elf.iter_sections():
        if section["sh_type"] != "SHT_REL" or section["sh_info"] != section_index:
            continue
        symbols = elf.get_section(section["sh_link"])
        for relocation in section.iter_relocations():
            relocate_symbol(data, relocation, symbols)

def compiled_bytes(object_path: Path, name: str) -> bytes:
    with object_path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab").get_symbol_by_name(name)
        assert symbols is not None and len(symbols) == 1, name
        symbol = symbols[0]
        section_index = symbol["st_shndx"]
        data = bytearray(elf.get_section(section_index).data())
        relocate_section(elf, section_index, data)
        start = symbol["st_value"]
        return bytes(data[start : start + symbol["st_size"]])
