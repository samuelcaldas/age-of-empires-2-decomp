"""Compare the compiled zone destructor with original PS2 instructions."""

import hashlib
import subprocess
from pathlib import Path

import pytest
from elftools.elf.elffile import ELFFile


PROJECT_ROOT = Path(__file__).resolve().parents[1]
SOURCE_PATH = PROJECT_ROOT / "src/zone/zone_destructor.cpp"
ORIGINAL_PATH = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER_PATH = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER_PATH = PROJECT_ROOT / "build/tools/wibo"
LINKER_PATH = PROJECT_ROOT / "build/mips_binutils/mips-linux-gnu-ld"
FUNCTION_NAME = "func_001C8FF0"
FUNCTION_ADDRESS = 0x1C8FF0
FUNCTION_SIZE = 976
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
EXTERNAL_SYMBOLS = {
    "func_335560": 0x335560,
    "func_00100670": 0x100670,
    "func_00100630": 0x100630,
    "func_1D16D0": 0x1D16D0,
    "func_25DE30": 0x25DE30,
    "memset": 0x117CAC,
    "func_001389F0": 0x1389F0,
    "func_327590": 0x327590,
    "func_1ED830": 0x1ED830,
    "func_1D06A0": 0x1D06A0,
    "D_4D9270": 0x4D9270,
    "D_004E2DF0": 0x4E2DF0,
    "D_004E2DE8": 0x4E2DE8,
    "D_004E2DEC": 0x4E2DEC,
    "D_938AC0": 0x938AC0,
    "D_938CC0": 0x938CC0,
    "D_81D120": 0x81D120,
    "D_92E820": 0x92E820,
    "D_938460": 0x938460,
    "D_938790": 0x938790,
    "_gp": 0x4EA7C0,
}


def require_toolchain():
    """Skip only when private binaries or PS2 toolchain files are absent."""
    required_paths = (ORIGINAL_PATH, COMPILER_PATH, WRAPPER_PATH, LINKER_PATH)
    missing_paths = [str(path) for path in required_paths if not path.is_file()]
    if missing_paths:
        pytest.skip("requires original ELF and PS2 toolchain; missing: " + ", ".join(missing_paths))


def compile_destructor(output_directory):
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
    return output_directory / "zone_destructor.o"


def destructor_symbol(object_path):
    """Confirm the compiler emitted the full destructor in its actual section."""
    with object_path.open("rb") as object_stream:
        object_elf = ELFFile(object_stream)
        symbol_table = object_elf.get_section_by_name(".symtab")
        symbol = symbol_table.get_symbol_by_name(FUNCTION_NAME)[0]
        assert symbol["st_info"]["type"] == "STT_FUNC"
        assert symbol["st_size"] == FUNCTION_SIZE
        section = object_elf.get_section(symbol["st_shndx"])
        start = symbol["st_value"]
        assert len(section.data()[start:start + FUNCTION_SIZE]) == FUNCTION_SIZE
        return symbol.name


def link_destructor(output_directory, object_path, symbol_name):
    """Resolve all external addresses and link the function at its original address."""
    linker_script = output_directory / "zone_destructor.ld"
    definitions = "".join(
        f"{name} = {address:#x};\n" for name, address in EXTERNAL_SYMBOLS.items()
    )
    linker_script.write_text(
        definitions + "SECTIONS {\n"
        f"  .text {FUNCTION_ADDRESS:#x} : {{ *(.text) }}\n"
        "  /DISCARD/ : { *(*) }\n"
        "}\n",
        encoding="utf-8",
    )
    linked_path = output_directory / "zone_destructor.elf"
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
        assert not unresolved, unresolved
        symbol = symbol_table.get_symbol_by_name(symbol_name)[0]
        assert symbol["st_value"] == FUNCTION_ADDRESS
        assert symbol["st_size"] == FUNCTION_SIZE
        section = linked_elf.get_section(symbol["st_shndx"])
        offset = symbol["st_value"] - section["sh_addr"]
        code = section.data()[offset:offset + symbol["st_size"]]
        assert len(code) == FUNCTION_SIZE
        return code


def original_destructor_bytes():
    """Read the exact original bytes from the ELF PT_LOAD file mapping."""
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == ORIGINAL_SHA1
    with ORIGINAL_PATH.open("rb") as original_stream:
        original_elf = ELFFile(original_stream)
        matching_segments = [
            segment for segment in original_elf.iter_segments()
            if segment["p_type"] == "PT_LOAD"
            and segment["p_vaddr"] <= FUNCTION_ADDRESS
            and FUNCTION_ADDRESS + FUNCTION_SIZE
            <= segment["p_vaddr"] + segment["p_filesz"]
        ]
        assert len(matching_segments) == 1, len(matching_segments)
        segment = matching_segments[0]
        offset = FUNCTION_ADDRESS - segment["p_vaddr"]
        assert segment["p_offset"] + offset == 0xC91D0
        code = segment.data()[offset:offset + FUNCTION_SIZE]
        assert len(code) == FUNCTION_SIZE
        return code


def test_zone_destructor_matches_original_after_resolving_externals(tmp_path):
    """Require all 976 emitted code bytes to match the original with no padding."""
    require_toolchain()
    expected_bytes = original_destructor_bytes()
    object_path = compile_destructor(tmp_path)
    symbol_name = destructor_symbol(object_path)
    actual_bytes = link_destructor(tmp_path, object_path, symbol_name)
    assert actual_bytes == expected_bytes
