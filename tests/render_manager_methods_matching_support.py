"""Fresh MWCC compilation and relocation-aware RenderManager methods comparison."""

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
    "func_00184A88": (0x184A88, 0x10),
    "func_00184A98": (0x184A98, 0x54),
    "func_00184AEC": (0x184AEC, 0x70),
    "func_00184B5C": (0x184B5C, 0x38),
    "func_00184B94": (0x184B94, 0x1C),
    "func_00184BB0": (0x184BB0, 0x10),
    "func_00184BC0": (0x184BC0, 0x10),
    "func_00184BD0": (0x184BD0, 0x10),
    "func_00184BE0": (0x184BE0, 0x10),
    "func_00184BF0": (0x184BF0, 0x10),
    "func_00184C00": (0x184C00, 0x08),
    "func_00184C08": (0x184C08, 0x10),
    "func_00184C18": (0x184C18, 0x10),
}
CALLEES = {
    "func_100670": 0x100670,
}


def require_original():
    """Skip absent licensed input, but reject a binary whose pinned hash differs."""
    if not ORIGINAL_PATH.is_file():
        pytest.skip("requires licensed SLES-50282 original ELF")
    pinned = (PROJECT_ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == pinned


def compile_methods(output_directory):
    """Compile current C++ source with the registered compiler, rejecting failures."""
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")
    output_path = output_directory / "render_manager_methods.o"
    subprocess.run(
        [str(WRAPPER_PATH), str(COMPILER_PATH), "-O3", "-inline", "on",
         "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
         "-lang=c++", "-c", "src/render/render_manager_methods.cpp", "-o", str(output_path)],
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


def relocate_jump(data, relocation, symbols):
    """Resolve an external call."""
    if relocation["r_info_type"] != 4:
        return
    offset = relocation["r_offset"]
    symbol = symbols.get_symbol(relocation["r_info_sym"]).name
    if symbol not in CALLEES:
        return
    instruction = struct.unpack_from("<I", data, offset)[0]
    target = CALLEES[symbol] + ((instruction & 0x03FFFFFF) << 2)
    assert target % 4 == 0
    relocated = (instruction & 0xFC000000) | ((target >> 2) & 0x03FFFFFF)
    struct.pack_into("<I", data, offset, relocated)


def relocate_section(elf, section_index, data):
    """Apply relocations only to the selected code section."""
    for section in elf.iter_sections():
        if section["sh_type"] != "SHT_REL" or section["sh_info"] != section_index:
            continue
        symbols = elf.get_section(section["sh_link"])
        for relocation in section.iter_relocations():
            relocate_jump(data, relocation, symbols)


def compiled_bytes(object_path, name):
    """Select the function by st_shndx, resolve calls, and return its sized bytes."""
    with object_path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab").get_symbol_by_name(name)
        assert symbols is not None and len(symbols) == 1, name
        symbol = symbols[0]
        section_index = symbol["st_shndx"]
        data = bytearray(elf.get_section(section_index).data())
        relocate_section(elf, section_index, data)
        start = symbol["st_value"]
        size = symbol["st_size"]
        return bytes(data[start:start + size])
