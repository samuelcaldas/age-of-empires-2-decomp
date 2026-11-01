"""Compare unit action build 7b810 functions with original PS2 instructions."""

import hashlib
import subprocess
from pathlib import Path

import pytest
from elftools.elf.elffile import ELFFile


PROJECT_ROOT = Path(__file__).resolve().parents[1]
SOURCE_PATH = PROJECT_ROOT / "src/unit/unit_action_build_7b810.cpp"
ORIGINAL_PATH = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER_PATH = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER_PATH = PROJECT_ROOT / "build/tools/wibo"
LINKER_PATH = PROJECT_ROOT / "build/mips_binutils/mips-linux-gnu-ld"
TEXT_ADDRESS = 0x27B810
TEXT_SIZE = 308
SLICE_SIZE = 320
FILE_OFFSET = 0x17B9F0
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
FUNCTIONS = {
    "func_0027B810": (0x27B810, 60),
    "func_0027B850": (0x27B850, 64),
    "func_0027B890": (0x27B890, 64),
    "func_0027B8D0": (0x27B8D0, 120),
}


def require_toolchain():
    """Skip only when the original binary or PS2 toolchain files are absent."""
    required_paths = (ORIGINAL_PATH, COMPILER_PATH, WRAPPER_PATH, LINKER_PATH)
    missing_paths = [str(path) for path in required_paths if not path.is_file()]
    if missing_paths:
        pytest.skip("requires original ELF and PS2 toolchain; missing: " + ", ".join(missing_paths))


def compile_handler(output_directory):
    """Compile the source with the verified PS2 MWCC settings."""
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
    return output_directory / "unit_action_build_7b810.o"


def assert_function_symbols(elf_file, linked=False):
    """Verify function symbols, sizes, addresses, and their actual sections."""
    symbol_table = elf_file.get_section_by_name(".symtab")
    for name, (address, size) in FUNCTIONS.items():
        symbol_matches = symbol_table.get_symbol_by_name(name)
        assert symbol_matches and len(symbol_matches) == 1, name
        symbol = symbol_matches[0]
        assert symbol["st_info"]["type"] == "STT_FUNC"
        section = elf_file.get_section(symbol["st_shndx"])
        start = symbol["st_value"]
        if linked:
            assert start == address
            start -= section["sh_addr"]
        assert len(section.data()[start:start + size]) >= size


def link_handler(output_directory, object_path):
    """Resolve real external addresses and link the full text section."""
    linker_script = output_directory / "unit_action_build_7b810.ld"
    linker_script.write_text(
        "SECTIONS {\n"
        f"  .text {TEXT_ADDRESS:#x} : SUBALIGN(16) {{ *(.text) }}\n"
        "  /DISCARD/ : { *(*) }\n"
        "}\n",
        encoding="utf-8",
    )
    linked_path = output_directory / "unit_action_build_7b810.elf"
    subprocess.run(
        [
            str(LINKER_PATH), "-EL", "-m", "elf32ltsmip", "--no-undefined",
            "-T", str(linker_script), "-o", str(linked_path), str(object_path),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    with linked_path.open("rb") as linked_stream:
        linked_elf = ELFFile(linked_stream)
        symbol_table = linked_elf.get_section_by_name(".symtab")
        unresolved = [
            symbol.name for symbol in symbol_table.iter_symbols()
            if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"
        ]
        assert not unresolved, f"unresolved symbols: {unresolved}"
        assert_function_symbols(linked_elf, linked=True)
        text_section = linked_elf.get_section_by_name(".text")
        assert text_section["sh_addr"] == TEXT_ADDRESS
        code = text_section.data()[:TEXT_SIZE]
        assert len(code) == TEXT_SIZE
        return code


def original_text():
    """Read the exact PT_LOAD bytes for the full slice."""
    original_bytes = ORIGINAL_PATH.read_bytes()
    assert hashlib.sha1(original_bytes).hexdigest() == ORIGINAL_SHA1, (
        "AOK.ELF SHA1 mismatch — wrong binary"
    )
    with ORIGINAL_PATH.open("rb") as original_stream:
        original_stream.seek(FILE_OFFSET)
        code = original_stream.read(TEXT_SIZE)
        assert len(code) == TEXT_SIZE
        return code


def test_unit_action_build_7b810_match_original(tmp_path):
    """Verify function symbol size and linked text byte generation."""
    require_toolchain()
    expected_code = original_text()
    object_path = compile_handler(tmp_path)
    with object_path.open("rb") as object_stream:
        assert_function_symbols(ELFFile(object_stream))
    actual_code = link_handler(tmp_path, object_path)
    assert actual_code == expected_code
