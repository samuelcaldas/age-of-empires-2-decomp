"""Fresh MWCC compilation and kt_gs_render_232300 comparison."""

from pathlib import Path
import subprocess

import pytest
from elftools.elf.elffile import ELFFile

PROJECT_ROOT = Path(__file__).resolve().parents[1]
ORIGINAL_PATH = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER_PATH = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER_PATH = PROJECT_ROOT / "build/tools/wibo"

FUNCTIONS = {
    "func_00232300": (0x00232300, 0x00A0),
}

def require_original():
    if not ORIGINAL_PATH.is_file():
        pytest.skip(f"Original ELF is required: {ORIGINAL_PATH}")

def original_bytes(address: int, size: int) -> bytes:
    offset = 0x1324E0 + (address - 0x00232300)
    with open(ORIGINAL_PATH, "rb") as f:
        f.seek(offset)
        return f.read(size)

def compile_gs_render_232300(tmp_path: Path) -> Path:
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")

    output_path = tmp_path / "kt_gs_render_232300.o"
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
            "src/kcet/kt_gs_render_232300.cpp",
            "-o",
            str(output_path),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    return output_path

def compiled_bytes(object_path: Path, name: str) -> bytes:
    with object_path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab").get_symbol_by_name(name)
        assert symbols is not None and len(symbols) == 1, name
        symbol = symbols[0]
        section_index = symbol["st_shndx"]
        data = elf.get_section(section_index).data()
        start = symbol["st_value"]
        return bytes(data[start : start + symbol["st_size"]])
