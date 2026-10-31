"""Fresh MWCC compilation and relocation-aware RenderPaletteTable comparison."""

import hashlib
from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
ORIGINAL_PATH = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER_PATH = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER_PATH = PROJECT_ROOT / "build/tools/wibo"

FUNCTIONS = {
    "__ct__18RenderPaletteTableFPv": (0x189480, 0x138),
    "__ct__18RenderPaletteTableFP8SubObj6CiPC18RenderPaletteColorPCUc": (0x1895C0, 0x1F8),
    "__dt__18RenderPaletteTableFv": (0x1897C0, 0x70),
}

CALLEES = {
    "func_226D90": 0x226D90,
    "func_100730": 0x100730,
    "func_21BC30": 0x21BC30,
    "func_0021BC30": 0x21BC30,
    "func_117AF8": 0x117AF8,
    "func_1AE350": 0x1AE350,
    "func_00189260": 0x189260,
    "func_100630": 0x100630,
    "func_100670": 0x100670,
    "__dl__FPv": 0x100670,
    "free": 0x100630,
    "malloc": 0x100730,
}

SYMBOLS_ABS = {
    "__vt__18RenderPaletteTable": 0x004D7EE8,
    "D_003921F4": 0x003921F4,
    "D_01ED7000": 0x01ED7000,
}


def require_original():
    """Skip absent licensed input, but reject a binary whose pinned hash differs."""
    if not ORIGINAL_PATH.is_file():
        pytest.skip("requires licensed SLES-50282 original ELF")
    pinned = (PROJECT_ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == pinned


def compile_palette_table(output_directory):
    """Compile current C++ source with the registered compiler, rejecting failures."""
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")
    output_path = output_directory / "render_manager_palette_table.o"
    subprocess.run(
        [str(WRAPPER_PATH), str(COMPILER_PATH), "-O3", "-inline", "on",
         "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
         "-lang=c++", "-c", "src/render/render_manager_palette_table.cpp", "-o", str(output_path)],
        cwd=PROJECT_ROOT, capture_output=True, text=True, check=True,
    )
    return output_path


def original_bytes(address, size):
    """Read complete original ranges through PT_LOAD, failing outside file data."""
    with ORIGINAL_PATH.open("rb") as stream:
        elf = ELFFile(stream)
        for segment in elf.iter_segments():
            offset = address - segment["p_vaddr"]
            if segment["p_type"] == "PT_LOAD" and 0 <= offset <= segment["p_filesz"] - size:
                return segment.data()[offset:offset + size]
    raise AssertionError(f"Original range outside loadable file data: {address:#x}")


def relocate_symbol(data, relocation, symbols):
    """Resolve R_MIPS_26, R_MIPS_HI16, and R_MIPS_LO16 relocations."""
    r_type = relocation["r_info_type"]
    offset = relocation["r_offset"]
    symbol_name = symbols.get_symbol(relocation["r_info_sym"]).name
    if r_type == 4:
        target = CALLEES[symbol_name]
        w = struct.unpack_from("<I", data, offset)[0]
        relocated = (w & 0xFC000000) | ((target >> 2) & 0x03FFFFFF)
        struct.pack_into("<I", data, offset, relocated)
    elif r_type == 5:
        addr = SYMBOLS_ABS[symbol_name]
        hi = (addr >> 16) + (1 if (addr & 0x8000) else 0)
        struct.pack_into("<H", data, offset, hi)
    elif r_type == 6:
        addr = SYMBOLS_ABS[symbol_name]
        lo = addr & 0xFFFF
        struct.pack_into("<H", data, offset, lo)
    else:
        raise AssertionError(f"Unexpected relocation type {r_type} at offset {offset:#x}")


def relocate_section(elf, section_index, data):
    """Apply relocations to the selected code section."""
    for section in elf.iter_sections():
        if section["sh_type"] != "SHT_REL" or section["sh_info"] != section_index:
            continue
        symbols = elf.get_section(section["sh_link"])
        for relocation in section.iter_relocations():
            relocate_symbol(data, relocation, symbols)


def compiled_bytes(object_path, name):
    """Select the function by st_shndx, resolve relocations, and return its sized bytes."""
    with object_path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab").get_symbol_by_name(name)
        assert symbols is not None and len(symbols) == 1, name
        symbol = symbols[0]
        section_index = symbol["st_shndx"]
        data = bytearray(elf.get_section(section_index).data())
        relocate_section(elf, section_index, data)
        start = symbol["st_value"]
        return bytes(data[start:start + symbol["st_size"]])
