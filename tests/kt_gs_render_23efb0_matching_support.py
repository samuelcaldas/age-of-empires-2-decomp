"""Fresh MWCC compilation and relocation-aware kt_gs_render_23efb0 comparison."""

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
    "func_0023EFB0": (0x0023EFB0, 0x01F8),
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
            "src/kcet/kt_gs_render_23efb0.cpp",
            "-o",
            str(output_path),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    return output_path

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
        offset = sym["st_value"]
        size = FUNCTIONS[name][1]
        return bytes(data[offset:offset + size])
