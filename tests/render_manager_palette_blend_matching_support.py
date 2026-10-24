"""Fresh MWCC compilation and complete ELF-byte checks for palette blending."""

import hashlib
from pathlib import Path
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
ORIGINAL_PATH = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER_PATH = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER_PATH = PROJECT_ROOT / "build/tools/wibo"
FUNCTIONS = {"func_00189260": (0x189260, 0x220)}


def require_original():
    """Skip missing licensed input and reject a mismatched pinned SHA-1."""
    if not ORIGINAL_PATH.is_file():
        pytest.skip("requires licensed SLES-50282 original ELF")
    pinned = (PROJECT_ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == pinned


def compile_palette_blend(output_directory):
    """Compile current C++ afresh; raise for compiler failures."""
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")
    output_path = output_directory / "render_manager_palette_blend.o"
    subprocess.run(
        [str(WRAPPER_PATH), str(COMPILER_PATH), "-O3", "-inline", "on",
         "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
         "-lang=c++", "-c", "src/render/render_manager_palette_blend.cpp", "-o", str(output_path)],
        cwd=PROJECT_ROOT, capture_output=True, text=True, check=True,
    )
    return output_path


def original_bytes(address, size):
    """Read the full file-backed PT_LOAD range or raise for invalid boundaries."""
    with ORIGINAL_PATH.open("rb") as stream:
        elf = ELFFile(stream)
        for segment in elf.iter_segments():
            offset = address - segment["p_vaddr"]
            if segment["p_type"] == "PT_LOAD" and 0 <= offset <= segment["p_filesz"] - size:
                return segment.data()[offset:offset + size]
    raise AssertionError(f"Original range outside loadable file data: {address:#x}")


def compiled_bytes(object_path, name):
    """Select the function by st_shndx and reject unexpected leaf relocations."""
    with object_path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab").get_symbol_by_name(name)
        assert symbols is not None and len(symbols) == 1, name
        symbol = symbols[0]
        section_index = symbol["st_shndx"]
        start = symbol["st_value"]
        end = start + symbol["st_size"]
        for section in elf.iter_sections():
            if section["sh_type"] != "SHT_REL" or section["sh_info"] != section_index:
                continue
            for relocation in section.iter_relocations():
                assert not start <= relocation["r_offset"] < end, "Unexpected palette leaf relocation"
        return elf.get_section(section_index).data()[start:end]
