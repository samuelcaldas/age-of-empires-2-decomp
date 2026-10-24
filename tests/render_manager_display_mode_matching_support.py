"""Fresh MWCC compilation and relocation-aware RenderManager display mode comparison."""

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
    "func_00188740": (0x188740, 0x128),
    "func_00188870": (0x188870, 0x10),
    "func_00188880": (0x188880, 0x10),
    "func_00188890": (0x188890, 0x14),
    "func_001888b0": (0x1888B0, 0x44),
    "func_00188900": (0x188900, 0x34),
    "func_00188940": (0x188940, 0x40),
    "func_00188980": (0x188980, 0x08),
    "func_00188990": (0x188990, 0x08),
}
CALLEES = {
    "func_1DB4E0": 0x1DB4E0,
    "func_1AAF80": 0x1AAF80,
    "func_188A40": 0x188A40,
    "func_2264E0": 0x2264E0,
    "func_2254D0": 0x2254D0,
    "func_225450": 0x225450,
    "func_1F2CB0": 0x1F2CB0,
    "func_25D2D0": 0x25D2D0,
    "func_25D060": 0x25D060,
}
SYMBOLS_ABS = {
    "func_00A80BB0": 0x00A80BB0,
    "D_00491A28": 0x00491A28,
}
GP_DISP = {
    "D_004E89EC": -0x7674,
}


def require_original():
    """Skip absent licensed input, but reject a binary whose pinned hash differs."""
    if not ORIGINAL_PATH.is_file():
        pytest.skip("requires licensed SLES-50282 original ELF")
    pinned = (PROJECT_ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == pinned


def compile_display_mode(output_directory):
    """Compile current C++ source with the registered compiler, rejecting failures."""
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")
    output_path = output_directory / "render_manager_display_mode.o"
    subprocess.run(
        [str(WRAPPER_PATH), str(COMPILER_PATH), "-O3", "-inline", "on",
         "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
         "-lang=c++", "-c", "src/render/render_manager_display_mode.cpp", "-o", str(output_path)],
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
    """Resolve R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, and R_MIPS_GPREL16 relocations."""
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
    elif r_type == 7:
        struct.pack_into("<h", data, offset, GP_DISP[symbol_name])
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
