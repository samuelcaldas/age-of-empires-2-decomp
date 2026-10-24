"""Fresh MWCC compilation and relocation-aware RenderManager config comparison."""

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
    "func_00187ca0": (0x187CA0, 0x5C),
    "func_00187d00": (0x187D00, 0x19C),
    "func_00187ea0": (0x187EA0, 0x178),
}
CALLEES = {
    "func_192BF0": 0x192BF0,
    "func_00187d00": 0x187D00,
    "func_188250": 0x188250,
    "func_188240": 0x188240,
    "func_188260": 0x188260,
    "func_1882B0": 0x1882B0,
    "func_1882D0": 0x1882D0,
    "func_1882F0": 0x1882F0,
    "func_188300": 0x188300,
    "func_188310": 0x188310,
    "func_188320": 0x188320,
    "func_188330": 0x188330,
    "func_188340": 0x188340,
    "func_188350": 0x188350,
    "func_188360": 0x188360,
    "func_1883C0": 0x1883C0,
    "func_1883F0": 0x1883F0,
    "func_188020": 0x188020,
    "func_188490": 0x188490,
    "func_1884B0": 0x1884B0,
    "func_1884F0": 0x1884F0,
    "func_1884C0": 0x1884C0,
    "func_188500": 0x188500,
    "func_1883B0": 0x1883B0,
    "func_1883D0": 0x1883D0,
    "func_188060": 0x188060,
    "func_188070": 0x188070,
    "func_1880C0": 0x1880C0,
    "func_11ABBC": 0x11ABBC,
    "func_1880D0": 0x1880D0,
    "func_1880E0": 0x1880E0,
    "func_1880F0": 0x1880F0,
    "func_188100": 0x188100,
    "func_188110": 0x188110,
    "func_188120": 0x188120,
    "func_188130": 0x188130,
    "func_188140": 0x188140,
    "func_188150": 0x188150,
    "func_188160": 0x188160,
    "func_1881D0": 0x1881D0,
    "func_188170": 0x188170,
    "func_1881C0": 0x1881C0,
    "func_188220": 0x188220,
    "func_188050": 0x188050,
    "func_1884E0": 0x1884E0,
    "func_188510": 0x188510,
    "func_188520": 0x188520,
    "func_1881B0": 0x1881B0,
    "func_1881E0": 0x1881E0,
}


def require_original():
    """Skip absent licensed input, but reject a binary whose pinned hash differs."""
    if not ORIGINAL_PATH.is_file():
        pytest.skip("requires licensed SLES-50282 original ELF")
    pinned = (PROJECT_ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == pinned


def compile_config(output_directory):
    """Compile current C++ source with the registered compiler, rejecting failures."""
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")
    output_path = output_directory / "render_manager_config.o"
    subprocess.run(
        [str(WRAPPER_PATH), str(COMPILER_PATH), "-O3", "-inline", "on",
         "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
         "-lang=c++", "-c", "src/render/render_manager_config.cpp", "-o", str(output_path)],
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
