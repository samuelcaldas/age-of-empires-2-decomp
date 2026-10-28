"""Fresh MWCC compilation and relocation-aware kt_iop_init_220dd0 comparison."""

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
    "func_00220DD0": (0x220DD0, 0xB8),
    "func_00220E90": (0x220E90, 0xD4),
}

CALLEES = {
    "func_388710": 0x388710,
    "func_388690": 0x388690,
    "func_111710": 0x111710,
    "func_102828": 0x102828,
    "func_103948": 0x103948,
    "func_102688": 0x102688,
    "func_1237E8": 0x1237E8,
    "func_123888": 0x123888,
    "func_25D060": 0x25D060,
    "func_25D320": 0x25D320,
    "func_12D648": 0x12D648,
    "func_1296D8": 0x1296D8,
    "func_129FE0": 0x129FE0,
    "func_129F68": 0x129F68,
    "func_12A058": 0x12A058,
    "func_12A0E8": 0x12A0E8,
    "func_21BDE0": 0x21BDE0,
    "func_388000": 0x388000,
}

SYMBOLS = {
    "D_00492EE0": 0x492EE0,
    "D_00492DE0": 0x492DE0,
    "D_00392BF0": 0x392BF0,
    "D_00392C50": 0x392C50,
    "D_00392C80": 0x392C80,
    "D_00C82510": 0xC82510,
    "D_00C92510": 0xC92510,
}


def require_original():
    """Skip absent licensed input, but reject a binary whose pinned hash differs."""
    if not ORIGINAL_PATH.is_file():
        pytest.skip("requires licensed SLES-50282 original ELF")
    pinned = (PROJECT_ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == pinned


def compile_iop_init(output_directory):
    """Compile current C++ source with the registered compiler, rejecting failures."""
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")
    output_path = output_directory / "kt_iop_init_220dd0.o"
    subprocess.run(
        [str(WRAPPER_PATH), str(COMPILER_PATH), "-O3", "-inline", "on",
         "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
         "-lang=c++", "-c", "src/kcet/kt_iop_init_220dd0.cpp", "-o", str(output_path)],
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
    if r_type == 4:  # R_MIPS_26
        target = CALLEES[symbol_name]
        w = struct.unpack_from("<I", data, offset)[0]
        relocated = (w & 0xFC000000) | ((target >> 2) & 0x03FFFFFF)
        struct.pack_into("<I", data, offset, relocated)
    elif r_type == 5:  # R_MIPS_HI16
        target = SYMBOLS[symbol_name]
        in_situ = struct.unpack_from("<h", data, offset)[0]
        hi = (target + in_situ + 0x8000) >> 16
        struct.pack_into("<H", data, offset, hi & 0xFFFF)
    elif r_type == 6:  # R_MIPS_LO16
        target = SYMBOLS[symbol_name]
        in_situ = struct.unpack_from("<h", data, offset)[0]
        lo = (target + in_situ) & 0xFFFF
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
