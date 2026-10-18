"""Fresh MWCC compilation and relocation-aware RenderManager chat methods comparison."""

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
    "func_001890a0": (0x1890A0, 0x38),
    "func_001890e0": (0x1890E0, 0x6C),
    "func_00189150": (0x189150, 0x08),
    "func_00189160": (0x189160, 0x28),
    "func_00189190": (0x189190, 0x38),
    "func_001891d0": (0x1891D0, 0x38),
    "func_00189210": (0x189210, 0x08),
    "func_00189220": (0x189220, 0x08),
    "func_00189230": (0x189230, 0x08),
    "func_00189240": (0x189240, 0x08),
    "func_00189250": (0x189250, 0x08),
}
CALLEES = {
    "func_116F68": 0x116F68,
}


def require_original():
    """Skip absent licensed input, but reject a binary whose pinned hash differs."""
    if not ORIGINAL_PATH.is_file():
        pytest.skip("requires licensed SLES-50282 original ELF")
    pinned = (PROJECT_ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == pinned


def compile_chat_methods(output_directory):
    """Compile current C++ source with the registered compiler, rejecting failures."""
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")
    output_path = output_directory / "render_manager_chat_methods.o"
    subprocess.run(
        [str(WRAPPER_PATH), str(COMPILER_PATH), "-O3", "-inline", "on",
         "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
         "-lang=c++", "-c", "src/render_manager_chat_methods.cpp", "-o", str(output_path)],
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
    """Resolve R_MIPS_26 relocations."""
    r_type = relocation["r_info_type"]
    offset = relocation["r_offset"]
    symbol_name = symbols.get_symbol(relocation["r_info_sym"]).name
    if r_type == 4:
        target = CALLEES[symbol_name]
        w = struct.unpack_from("<I", data, offset)[0]
        relocated = (w & 0xFC000000) | ((target >> 2) & 0x03FFFFFF)
        struct.pack_into("<I", data, offset, relocated)
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
