"""Fresh MWCC compilation and relocation-aware RenderManager props comparison."""

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
    "func_00188020": (0x188020, 0x08),
    "func_00188030": (0x188030, 0x08),
    "func_00188040": (0x188040, 0x08),
    "func_00188050": (0x188050, 0x08),
    "func_00188060": (0x188060, 0x08),
    "func_00188070": (0x188070, 0x08),
    "func_00188080": (0x188080, 0x14),
    "func_001880a0": (0x1880A0, 0x08),
    "func_001880b0": (0x1880B0, 0x08),
    "func_001880c0": (0x1880C0, 0x08),
    "func_001880d0": (0x1880D0, 0x08),
    "func_001880e0": (0x1880E0, 0x08),
    "func_001880f0": (0x1880F0, 0x08),
    "func_00188100": (0x188100, 0x08),
    "func_00188110": (0x188110, 0x08),
    "func_00188120": (0x188120, 0x08),
    "func_00188130": (0x188130, 0x08),
    "func_00188140": (0x188140, 0x08),
    "func_00188150": (0x188150, 0x08),
    "func_00188160": (0x188160, 0x08),
    "func_00188170": (0x188170, 0x08),
    "func_00188180": (0x188180, 0x10),
    "func_00188190": (0x188190, 0x18),
    "func_001881b0": (0x1881B0, 0x0C),
    "func_001881c0": (0x1881C0, 0x08),
    "func_001881d0": (0x1881D0, 0x08),
    "func_001881e0": (0x1881E0, 0x28),
    "func_00188210": (0x188210, 0x08),
    "func_00188220": (0x188220, 0x08),
    "func_00188230": (0x188230, 0x08),
    "func_00188240": (0x188240, 0x08),
    "func_00188250": (0x188250, 0x08),
}
CALLEES = {
    "func_3444E0": 0x3444E0,
}


def require_original():
    """Skip absent licensed input, but reject a binary whose pinned hash differs."""
    if not ORIGINAL_PATH.is_file():
        pytest.skip("requires licensed SLES-50282 original ELF")
    pinned = (PROJECT_ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == pinned


def compile_props(output_directory):
    """Compile current C++ source with the registered compiler, rejecting failures."""
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")
    output_path = output_directory / "render_manager_props.o"
    subprocess.run(
        [str(WRAPPER_PATH), str(COMPILER_PATH), "-O3", "-inline", "on",
         "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
         "-lang=c++", "-c", "src/render_manager_props.cpp", "-o", str(output_path)],
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
