"""Fresh MWCC compilation and relocation-aware kt_gs_render_2272a0 comparison."""

import hashlib
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
    "func_002272A0": (0x002272A0, 0x100),
    "func_002273A0": (0x002273A0, 0x0D0),
    "func_00227470": (0x00227470, 0x010),
    "func_00227480": (0x00227480, 0x160),
    "func_002275E0": (0x002275E0, 0x060),
    "func_00227640": (0x00227640, 0x090),
    "func_002276D0": (0x002276D0, 0x160),
    "func_00227830": (0x00227830, 0x080),
    "func_002278B0": (0x002278B0, 0x050),
    "func_00227900": (0x00227900, 0x090),
    "func_00227990": (0x00227990, 0x050),
}

CALLEES = {
    "func_001CB6A0": 0x001CB6A0,
    "func_001CB6B0": 0x001CB6B0,
    "func_001CB6C0": 0x001CB6C0,
    "func_002276D0": 0x002276D0,
    "func_002275E0": 0x002275E0,
    "func_00227990": 0x00227990,
    "func_00227830": 0x00227830,
    "func_00227640": 0x00227640,
    "func_00100670": 0x00100670,
    "func_00227470": 0x00227470,
    "func_0018AFE0": 0x0018AFE0,
    "func_01D98180": 0x01D98180,
    "func_01D981D0": 0x01D981D0,
    "func_00227900": 0x00227900,
    "func_002278B0": 0x002278B0,
}


def require_original():
    """Skip absent licensed input, but reject a binary whose pinned hash differs."""
    if not ORIGINAL_PATH.is_file():
        pytest.skip("requires licensed SLES-50282 original ELF")
    pinned = (PROJECT_ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == pinned


def compile_gs_render_2272a0(output_directory):
    """Compile current C++ source with the registered compiler, rejecting failures."""
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")
    output_path = output_directory / "kt_gs_render_2272a0.o"
    subprocess.run(
        [str(WRAPPER_PATH), str(COMPILER_PATH), "-O3", "-inline", "on",
         "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
         "-lang=c++", "-c", "src/kcet/kt_gs_render_2272a0.cpp", "-o", str(output_path)],
        cwd=PROJECT_ROOT, capture_output=True, text=True, check=True,
    )
    return output_path


def original_bytes(address, size):
    """Read original bytes from binary."""
    offset = 0x127480 + (address - 0x002272A0)
    with open(ORIGINAL_PATH, "rb") as f:
        f.seek(offset)
        return f.read(size)


def relocate_symbol(data, relocation, symbols):
    """Resolve R_MIPS_26 relocations."""
    r_type = relocation["r_info_type"]
    offset = relocation["r_offset"]
    symbol_name = symbols.get_symbol(relocation["r_info_sym"]).name
    if r_type == 4:  # R_MIPS_26
        target = CALLEES[symbol_name]
        w = struct.unpack_from("<I", data, offset)[0]
        relocated = (w & 0xFC000000) | ((target >> 2) & 0x03FFFFFF)
        struct.pack_into("<I", data, offset, relocated)


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
