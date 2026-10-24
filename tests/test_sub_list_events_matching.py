"""Compare the compiled SubList caller with original PS2 instructions."""

import struct
import subprocess
from pathlib import Path

import pytest
from elftools.elf.elffile import ELFFile


PROJECT_ROOT = Path(__file__).resolve().parents[1]
SOURCE_PATH = PROJECT_ROOT / "src/core/sub_list_events.cpp"
ORIGINAL_PATH = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER_PATH = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER_PATH = PROJECT_ROOT / "build/tools/wibo"
LINKER_PATH = PROJECT_ROOT / "build/mips_binutils/mips-linux-gnu-ld"
CALLER_ADDRESS = 0x13AB90
CALLER_SIZE = 88
CALLEE_ADDRESS = 0x267530
CALLER_PREFIX = "func_0013AB90"


def require_toolchain():
    """Skip clearly when private game files or PS2 tools are unavailable."""
    required_paths = (
        SOURCE_PATH,
        ORIGINAL_PATH,
        COMPILER_PATH,
        WRAPPER_PATH,
        LINKER_PATH,
    )
    missing_paths = [
        str(path) for path in required_paths if not path.is_file()
    ]
    if missing_paths:
        reason = "requires original ELF and PS2 toolchain; missing: "
        pytest.skip(reason + ", ".join(missing_paths))


def compile_caller(output_directory):
    """Compile the current C++ caller with the verified PS2 MWCC settings."""
    subprocess.run(
        [
            str(WRAPPER_PATH), str(COMPILER_PATH), "-O3", "-inline", "on",
            "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
            "-lang=c++", "-c", str(SOURCE_PATH), "-o", str(output_directory),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    return output_directory / "sub_list_events.o"


def caller_symbol(object_path):
    """Find the caller and its actual MWCC code section."""
    with object_path.open("rb") as object_stream:
        object_elf = ELFFile(object_stream)
        symbol_table = object_elf.get_section_by_name(".symtab")
        matching_symbols = [
            symbol for symbol in symbol_table.iter_symbols()
            if symbol.name.startswith(CALLER_PREFIX)
            and symbol["st_info"]["type"] == "STT_FUNC"
        ]
        symbol_names = [symbol.name for symbol in matching_symbols]
        assert len(matching_symbols) == 1, symbol_names
        symbol = matching_symbols[0]
        assert symbol["st_size"] == CALLER_SIZE
        section = object_elf.get_section(symbol["st_shndx"])
        start = symbol["st_value"]
        assert len(section.data()[start:start + CALLER_SIZE]) == CALLER_SIZE
        return symbol.name


def link_caller(output_directory, object_path, symbol_name):
    """Resolve the canonical callee and retain only this caller."""
    linker_script = output_directory / "sub_list_events.ld"
    linker_script.write_text(
        f"func_00267530 = {CALLEE_ADDRESS:#x};\n"
        "SECTIONS {\n"
        f"  .text {CALLER_ADDRESS:#x} : {{ *(.text) }}\n"
        "  /DISCARD/ : { *(.comment) *(.mwcats.text) }\n"
        "}\n",
        encoding="utf-8",
    )
    linked_path = output_directory / "sub_list_events.elf"
    subprocess.run(
        [
            str(LINKER_PATH), "-EL", "-m", "elf32ltsmip", "--no-undefined",
            "--gc-sections", "-e", symbol_name, "-T", str(linker_script),
            "-o", str(linked_path), str(object_path),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    with linked_path.open("rb") as linked_stream:
        linked_elf = ELFFile(linked_stream)
        symbol_table = linked_elf.get_section_by_name(".symtab")
        symbol = symbol_table.get_symbol_by_name(symbol_name)[0]
        assert symbol["st_value"] == CALLER_ADDRESS
        assert symbol["st_size"] == CALLER_SIZE
        section = linked_elf.get_section(symbol["st_shndx"])
        section_offset = symbol["st_value"] - section["sh_addr"]
        code = section.data()[section_offset:section_offset + CALLER_SIZE]
    direct_jump_targets = {
        (struct.unpack_from("<I", code, offset)[0] & 0x03FFFFFF) << 2
        for offset in range(0, len(code), 4)
        if struct.unpack_from("<I", code, offset)[0] >> 26 == 3
    }
    assert CALLEE_ADDRESS in direct_jump_targets, direct_jump_targets
    return code


def original_caller_bytes():
    """Read exact caller bytes through the original ELF PT_LOAD mapping."""
    with ORIGINAL_PATH.open("rb") as original_stream:
        original_elf = ELFFile(original_stream)
        matching_segments = [
            segment for segment in original_elf.iter_segments()
            if segment["p_type"] == "PT_LOAD"
            and segment["p_vaddr"] <= CALLER_ADDRESS
            and CALLER_ADDRESS + CALLER_SIZE
            <= segment["p_vaddr"] + segment["p_filesz"]
        ]
        assert len(matching_segments) == 1, len(matching_segments)
        segment = matching_segments[0]
        start = CALLER_ADDRESS - segment["p_vaddr"]
        return segment.data()[start:start + CALLER_SIZE]


def test_sub_list_caller_matches_original_after_resolving_callee(tmp_path):
    """Require 88 exact bytes with func_00267530 resolved at 0x267530."""
    require_toolchain()
    object_path = compile_caller(tmp_path)
    symbol_name = caller_symbol(object_path)
    actual_bytes = link_caller(tmp_path, object_path, symbol_name)
    expected_bytes = original_caller_bytes()
    assert actual_bytes == expected_bytes
