"""Compare tactical AI level check function 0x342AB0 with original PS2 instructions."""

import hashlib
import subprocess
from pathlib import Path

import pytest
from elftools.elf.elffile import ELFFile


PROJECT_ROOT = Path(__file__).resolve().parents[1]
SOURCE_PATH = PROJECT_ROOT / "src/tactical_ai_func_342ab0.cpp"
ORIGINAL_PATH = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER_PATH = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER_PATH = PROJECT_ROOT / "build/tools/wibo"
LINKER_PATH = PROJECT_ROOT / "build/mips_binutils/mips-linux-gnu-ld"
TEXT_ADDRESS = 0x342AB0
TEXT_SIZE = 128
FILE_OFFSET = 0x242C90
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
FUNCTIONS = {
    "func_00342AB0": (0x342AB0, 128),
}


def require_toolchain():
    """Skip only when the original binary or PS2 toolchain files are absent."""
    required_paths = (ORIGINAL_PATH, COMPILER_PATH, WRAPPER_PATH, LINKER_PATH)
    missing_paths = [str(path) for path in required_paths if not path.is_file()]
    if missing_paths:
        pytest.skip("requires original ELF and PS2 toolchain; missing: " + ", ".join(missing_paths))


def compile_function(output_directory):
    """Compile the source with the verified PS2 MWCC settings."""
    object_path = output_directory / "tactical_ai_func_342ab0.o"
    subprocess.run(
        [
            str(WRAPPER_PATH),
            str(COMPILER_PATH),
            "-c",
            "-O3",
            "-inline", "on",
            "-msext", "on",
            "-char", "signed",
            "-sym", "off",
            "-Iinclude",
            "-lang=c++",
            str(SOURCE_PATH),
            "-o",
            str(object_path),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    return object_path


def link_function(output_directory, object_path):
    """Link the self-contained text section at its verified address."""
    linker_script = output_directory / "tactical_ai_func_342ab0.ld"
    linker_script.write_text(
        "SECTIONS {\n"
        f"  .text {TEXT_ADDRESS:#x} : {{ *(.text) }}\n"
        "  /DISCARD/ : { *(*) }\n"
        "}\n",
        encoding="utf-8",
    )
    linked_path = output_directory / "tactical_ai_func_342ab0.elf"
    subprocess.run(
        [
            str(LINKER_PATH),
            "-EL",
            "-m", "elf32ltsmip",
            "--no-undefined",
            "-T", str(linker_script),
            "-o", str(linked_path),
            str(object_path),
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
        text_section = linked_elf.get_section_by_name(".text")
        assert text_section["sh_addr"] == TEXT_ADDRESS
        code = text_section.data()
        assert len(code) == TEXT_SIZE
        return code


def original_text():
    """Read the exact PT_LOAD bytes from the original ELF."""
    original_bytes = ORIGINAL_PATH.read_bytes()
    assert hashlib.sha1(original_bytes).hexdigest() == ORIGINAL_SHA1, (
        "AOK.ELF SHA1 mismatch — wrong binary"
    )
    with ORIGINAL_PATH.open("rb") as original_stream:
        original_elf = ELFFile(original_stream)
        matching_segments = [
            segment for segment in original_elf.iter_segments()
            if segment["p_type"] == "PT_LOAD"
            and segment["p_vaddr"] <= TEXT_ADDRESS
            and TEXT_ADDRESS + TEXT_SIZE <= segment["p_vaddr"] + segment["p_filesz"]
        ]
        assert len(matching_segments) == 1, len(matching_segments)
        segment = matching_segments[0]
        offset = TEXT_ADDRESS - segment["p_vaddr"]
        assert segment["p_offset"] + offset == FILE_OFFSET
        code = segment.data()[offset:offset + TEXT_SIZE]
        assert len(code) == TEXT_SIZE
        return code


def test_tactical_ai_func_342ab0_match_original_after_resolving_externals(tmp_path):
    """Match all 128 linked text bytes (100% bit-for-bit)."""
    require_toolchain()
    expected_code = original_text()
    object_path = compile_function(tmp_path)
    actual_code = link_function(tmp_path, object_path)
    assert actual_code == expected_code
