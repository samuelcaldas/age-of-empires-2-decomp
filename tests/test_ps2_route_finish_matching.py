"""Check relocated MWCC function bytes against the original ELF load mapping."""

from pathlib import Path
import struct

import pytest
from elftools.elf.elffile import ELFFile


PROJECT_ROOT = Path(__file__).resolve().parents[1]
ORIGINAL_PATH = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
OBJECT_PATH = PROJECT_ROOT / "build/SLES-50282/src/trade/trade_action_route_finish.o"
FUNCTIONS = {
    "func_001508F0": (0x1508F0, 0x2C),
    "func_00150920": (0x150920, 0x3A0),
    "func_00150CC0": (0x150CC0, 0x20),
    "func_00150CE0": (0x150CE0, 0x264),
}
CALLEES = {
    "func_100730": 0x100730,
    "func_00100630": 0x100630,
    "memset": 0x117CAC,
    **{name: address for name, (address, _) in FUNCTIONS.items()},
}


def apply_jump_relocation(data, relocation, symbols):
    """Resolve an R_MIPS_26 relocation, rejecting unexpected relocation kinds."""
    assert relocation["r_info_type"] == 4
    offset = relocation["r_offset"]
    symbol_name = symbols.get_symbol(relocation["r_info_sym"]).name
    instruction = struct.unpack_from("<I", data, offset)[0]
    target = CALLEES[symbol_name] + ((instruction & 0x03FFFFFF) << 2)
    assert target % 4 == 0
    relocated = (instruction & 0xFC000000) | ((target >> 2) & 0x03FFFFFF)
    struct.pack_into("<I", data, offset, relocated)


def apply_relocation_table(section, symbols, data):
    """Resolve each relocation in a selected code relocation table."""
    for relocation in section.iter_relocations():
        apply_jump_relocation(data, relocation, symbols)


def apply_section_relocations(elf, section_index, data):
    """Apply only the code section's relocations, not Metrowerks metadata."""
    for section in elf.iter_sections():
        if section["sh_type"] != "SHT_REL":
            continue
        if section["sh_info"] != section_index:
            continue
        symbols = elf.get_section(section["sh_link"])
        apply_relocation_table(section, symbols, data)


def compiled_function_bytes(elf, name, size):
    """Read one MWCC function and resolve its external and local jump targets."""
    symbols = elf.get_section_by_name(".symtab")
    symbol = symbols.get_symbol_by_name(name)[0]
    assert symbol["st_size"] == size
    section_index = symbol["st_shndx"]
    section = elf.get_section(section_index)
    data = bytearray(section.data())
    apply_section_relocations(elf, section_index, data)
    start = symbol["st_value"]
    return bytes(data[start:start + size])


def original_function_bytes(elf, address, size):
    """Use the ELF's own load segments rather than the slicer's VRAM labels."""
    for segment in elf.iter_segments():
        if segment["p_type"] != "PT_LOAD":
            continue
        start = address - segment["p_vaddr"]
        if start < 0 or start + size > segment["p_filesz"]:
            continue
        return segment.data()[start:start + size]
    raise AssertionError(f"Function outside loadable ELF data: {address:#x}")


@pytest.mark.skipif(
    not ORIGINAL_PATH.is_file() or not OBJECT_PATH.is_file(),
    reason="requires licensed original ELF and a freshly built MWCC object",
)
@pytest.mark.parametrize("name", FUNCTIONS)
def test_route_function_matches_original_bytes(name):
    """Require literal instruction equality, including resolved call targets."""
    address, size = FUNCTIONS[name]
    with ORIGINAL_PATH.open("rb") as original, OBJECT_PATH.open("rb") as compiled:
        expected = original_function_bytes(ELFFile(original), address, size)
        actual = compiled_function_bytes(ELFFile(compiled), name, size)
    assert actual == expected
