"""Compare tactical AI handler function 0x340C30 with original PS2 instructions."""

import hashlib
import subprocess
from pathlib import Path

import pytest
from elftools.elf.elffile import ELFFile


PROJECT_ROOT = Path(__file__).resolve().parents[1]
SOURCE_PATH = PROJECT_ROOT / "src/tactical_ai_handler_340c30.cpp"
ORIGINAL_PATH = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER_PATH = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER_PATH = PROJECT_ROOT / "build/tools/wibo"
LINKER_PATH = PROJECT_ROOT / "build/mips_binutils/mips-linux-gnu-ld"
TEXT_ADDRESS = 0x340C30
TEXT_SIZE = 180
SLICE_SIZE = 192
FILE_OFFSET = 0x240E10
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
FUNCTIONS = {
    "func_00340C30": (0x340C30, 180),
}
EXTERNAL_SYMBOLS = {
    "D_00A80BB0": 0x00A80BB0,
    "aMemorycardScreen": 0x004D5510,
    "func_2261c0": 0x2261C0,
    "func_33A730": 0x33A730,
    "func_20BF20": 0x20BF20,
    "func_1F2900": 0x1F2900,
    "func_340360": 0x340360,
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
    return output_directory / "tactical_ai_handler_340c30.o"


def assert_function_symbols(elf_file, linked=False):
    """Verify function symbols, sizes, addresses, and their actual sections."""
    symbol_table = elf_file.get_section_by_name(".symtab")
    for name, (address, size) in FUNCTIONS.items():
        symbol_matches = symbol_table.get_symbol_by_name(name)
        assert symbol_matches and len(symbol_matches) == 1, name
        symbol = symbol_matches[0]
        assert symbol["st_info"]["type"] == "STT_FUNC"
        assert symbol["st_size"] == size
        section = elf_file.get_section(symbol["st_shndx"])
        start = symbol["st_value"]
        if linked:
            assert start == address
            start -= section["sh_addr"]
        assert len(section.data()[start:start + size]) == size


def link_handler(output_directory, object_path):
    """Resolve real external addresses and link the full text section."""
    linker_script = output_directory / "tactical_ai_handler_340c30.ld"
    definitions = "".join(
        f"{name} = {address:#x};\n" for name, address in EXTERNAL_SYMBOLS.items()
    )
    linker_script.write_text(
        definitions + "SECTIONS {\n"
        f"  .text {TEXT_ADDRESS:#x} : {{ *(.text) }}\n"
        "  /DISCARD/ : { *(*) }\n"
        "}\n",
        encoding="utf-8",
    )
    linked_path = output_directory / "tactical_ai_handler_340c30.elf"
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
        code = text_section.data()
        assert len(code) == TEXT_SIZE
        return code


def original_text_and_tail():
    """Read the exact PT_LOAD bytes and original-only trailing zero words."""
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
            and TEXT_ADDRESS + SLICE_SIZE <= segment["p_vaddr"] + segment["p_filesz"]
        ]
        assert len(matching_segments) == 1, len(matching_segments)
        segment = matching_segments[0]
        offset = TEXT_ADDRESS - segment["p_vaddr"]
        assert segment["p_offset"] + offset == FILE_OFFSET
        code_and_tail = segment.data()[offset:offset + SLICE_SIZE]
        assert len(code_and_tail) == SLICE_SIZE
        return code_and_tail[:TEXT_SIZE], code_and_tail[TEXT_SIZE:]


def test_tactical_ai_handler_340c30_match_original_after_resolving_externals(tmp_path):
    """Match all 180 linked text bytes and verify 12 bytes zero padding."""
    require_toolchain()
    expected_code, original_tail = original_text_and_tail()
    assert original_tail == b"\0" * 12
    object_path = compile_handler(tmp_path)
    with object_path.open("rb") as object_stream:
        assert_function_symbols(ELFFile(object_stream))
    actual_code = link_handler(tmp_path, object_path)
    assert actual_code == expected_code
