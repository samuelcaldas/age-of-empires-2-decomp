"""Fresh MWCC compilation and relocation-aware kt_gs_render_23a050 comparison."""

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
    "func_0023A050": (0x0023A050, 0x0030),
    "func_0023A080": (0x0023A080, 0x0008),
}

CALLEES = {
    "strcpy": 0x0011ABBC,
}

def require_original():
    if not ORIGINAL_PATH.exists():
        pytest.skip(f"Original binary {ORIGINAL_PATH} not found.")

def require_compiler():
    if not COMPILER_PATH.exists():
        pytest.skip(f"MWCC compiler {COMPILER_PATH} not found.")
    if not WRAPPER_PATH.exists():
        pytest.skip(f"Wibo wrapper {WRAPPER_PATH} not found.")

def compile_source(output_path: Path) -> Path:
    require_compiler()
    output_path.parent.mkdir(parents=True, exist_ok=True)
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
            "src/kcet/kt_gs_render_23a050.cpp",
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
        if section.header["sh_type"] == "SHT_REL" and section.header["sh_info"] == section_index:
            symbols = elf.get_section(section.header["sh_link"])
            for relocation in section.iter_relocations():
                relocate_symbol(data, relocation, symbols)

def read_original_bytes(vram: int, size: int) -> bytes:
    file_offset = vram - 0x000FFE20
    with open(ORIGINAL_PATH, "rb") as f:
        f.seek(file_offset)
        return f.read(size)

def extract_function_bytes(obj_path: Path, name: str) -> bytes:
    with open(obj_path, "rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        sym = symtab.get_symbol_by_name(name)[0]
        section_idx = sym["st_shndx"]
        section = elf.get_section(section_idx)
        data = bytearray(section.data())
        relocate_section(elf, section_idx, data)
        offset = sym["st_value"]
        size = FUNCTIONS[name][1]
        return bytes(data[offset:offset + size])
