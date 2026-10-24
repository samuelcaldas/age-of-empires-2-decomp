"""Fresh MWCC compilation and relocation-aware RenderManager state comparison."""

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
    "func_001853e0": (0x1853E0, 0x08),
    "func_001853f0": (0x1853F0, 0x34),
    "func_00185430": (0x185430, 0x24),
    "func_00185460": (0x185460, 0x44),
}
CALLEES = {
    "func_2264A0": 0x2264A0,
    "func_1F32D0": 0x1F32D0,
}
GPREL_SYMBOLS = {
    "D_004E8624": 0x8624,
    "D_004E8940": 0x8940,
}
HI_LO_SYMBOLS = {
    "func_001842f0": 0x001842F0,
    "func_00A80BB0": 0x00A80BB0,
}


def require_original():
    """Skip absent licensed input, but reject a binary whose pinned hash differs."""
    if not ORIGINAL_PATH.is_file():
        pytest.skip("requires licensed SLES-50282 original ELF")
    pinned = (PROJECT_ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == pinned


def compile_state(output_directory):
    """Compile current C++ source with the registered compiler, rejecting failures."""
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")
    output_path = output_directory / "render_manager_state.o"
    subprocess.run(
        [str(WRAPPER_PATH), str(COMPILER_PATH), "-O3", "-inline", "on",
         "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
         "-lang=c++", "-c", "src/render/render_manager_state.cpp", "-o", str(output_path)],
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
    """Resolve R_MIPS_26, HI16/LO16, and GPREL16 relocations."""
    r_type = relocation["r_info_type"]
    offset = relocation["r_offset"]
    symbol_name = symbols.get_symbol(relocation["r_info_sym"]).name
    if r_type == 4:  # R_MIPS_26
        target = CALLEES[symbol_name]
        w = struct.unpack_from("<I", data, offset)[0]
        relocated = (w & 0xFC000000) | ((target >> 2) & 0x03FFFFFF)
        struct.pack_into("<I", data, offset, relocated)
    elif r_type == 5:  # R_MIPS_HI16
        target = HI_LO_SYMBOLS[symbol_name]
        val = ((target + 0x8000) >> 16) if (target & 0x8000) else (target >> 16)
        struct.pack_into("<H", data, offset, val & 0xFFFF)
    elif r_type == 6:  # R_MIPS_LO16
        target = HI_LO_SYMBOLS[symbol_name]
        struct.pack_into("<H", data, offset, target & 0xFFFF)
    elif r_type == 7:  # R_MIPS_GPREL16
        struct.pack_into("<H", data, offset, GPREL_SYMBOLS[symbol_name])
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
