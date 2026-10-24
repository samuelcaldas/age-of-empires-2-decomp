"""Fresh MWCC compilation and relocation-aware RenderManager setters comparison."""

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
    "func_00188260": (0x188260, 0x30),
    "func_00188290": (0x188290, 0x08),
    "func_001882a0": (0x1882A0, 0x08),
    "func_001882b0": (0x1882B0, 0x14),
    "func_001882d0": (0x1882D0, 0x14),
    "func_001882f0": (0x1882F0, 0x10),
    "func_00188300": (0x188300, 0x08),
    "func_00188310": (0x188310, 0x08),
    "func_00188320": (0x188320, 0x08),
    "func_00188330": (0x188330, 0x08),
    "func_00188340": (0x188340, 0x08),
    "func_00188350": (0x188350, 0x08),
    "func_00188360": (0x188360, 0x08),
    "func_00188370": (0x188370, 0x18),
    "func_00188390": (0x188390, 0x1C),
    "func_001883b0": (0x1883B0, 0x0C),
    "func_001883c0": (0x1883C0, 0x08),
    "func_001883d0": (0x1883D0, 0x0C),
    "func_001883e0": (0x1883E0, 0x08),
    "func_001883f0": (0x1883F0, 0x08),
    "func_00188400": (0x188400, 0x28),
    "func_00188430": (0x188430, 0x28),
    "func_00188460": (0x188460, 0x14),
    "func_00188480": (0x188480, 0x08),
    "func_00188490": (0x188490, 0x08),
    "func_001884a0": (0x1884A0, 0x08),
    "func_001884b0": (0x1884B0, 0x0C),
    "func_001884c0": (0x1884C0, 0x0C),
    "func_001884d0": (0x1884D0, 0x08),
    "func_001884e0": (0x1884E0, 0x08),
    "func_001884f0": (0x1884F0, 0x08),
    "func_00188500": (0x188500, 0x08),
    "func_00188510": (0x188510, 0x08),
    "func_00188520": (0x188520, 0x08),
    "func_00188530": (0x188530, 0x30),
    "func_00188560": (0x188560, 0x30),
}
CALLEES = {
    "func_11B170": 0x11B170,
    "func_32F190": 0x32F190,
    "func_32F1C0": 0x32F1C0,
    "func_3449B0": 0x3449B0,
    "func_001884b0": 0x1884B0,
    "func_001884f0": 0x1884F0,
    "func_001884c0": 0x1884C0,
    "func_00188500": 0x188500,
}


def require_original():
    """Skip absent licensed input, but reject a binary whose pinned hash differs."""
    if not ORIGINAL_PATH.is_file():
        pytest.skip("requires licensed SLES-50282 original ELF")
    pinned = (PROJECT_ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == pinned


def compile_setters(output_directory):
    """Compile current C++ source with the registered compiler, rejecting failures."""
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")
    output_path = output_directory / "render_manager_setters.o"
    subprocess.run(
        [str(WRAPPER_PATH), str(COMPILER_PATH), "-O3", "-inline", "on",
         "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
         "-lang=c++", "-c", "src/render/render_manager_setters.cpp", "-o", str(output_path)],
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
