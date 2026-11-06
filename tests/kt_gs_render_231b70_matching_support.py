"""Fresh MWCC compilation and relocation-aware kt_gs_render_231b70 comparison."""

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
    "func_00231B70": (0x00231B70, 0x01F0),
}

CALLEES = {
    "func_00231920": 0x00231920,
    "func_002323A0": 0x002323A0,
    "func_0011ACD0": 0x0011ACD0,
    "strcpy": 0x0011ABBC,
    "strcat": 0x0011A7BC,
}

def require_original():
    if not ORIGINAL_PATH.is_file():
        pytest.skip(f"Original ELF is required: {ORIGINAL_PATH}")

def original_bytes(address: int, size: int) -> bytes:
    offset = 0x131D50 + (address - 0x00231B70)
    with open(ORIGINAL_PATH, "rb") as f:
        f.seek(offset)
        return f.read(size)

def compile_gs_render_231b70(tmp_path: Path) -> Path:
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")

    output_path = tmp_path / "kt_gs_render_231b70.o"
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
            "src/kcet/kt_gs_render_231b70.cpp",
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
