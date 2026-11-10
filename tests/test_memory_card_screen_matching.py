"""Verify memory card screen decompilation against original SLES-50282 AOK.ELF and native unit tests."""

import hashlib
import struct
import subprocess
from pathlib import Path

import pytest
from elftools.elf.elffile import ELFFile

PROJECT_ROOT = Path(__file__).resolve().parents[1]
ORIGINAL_PATH = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
COMPILER_PATH = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER_PATH = PROJECT_ROOT / "build/tools/wibo"
LINKER_PATH = PROJECT_ROOT / "build/mips_binutils/mips-linux-gnu-ld"


def require_toolchain():
    """Skip only when the original binary or PS2 toolchain files are absent."""
    required_paths = (ORIGINAL_PATH, COMPILER_PATH, WRAPPER_PATH, LINKER_PATH)
    missing_paths = [str(p) for p in required_paths if not p.is_file()]
    if missing_paths:
        pytest.skip(f"missing toolchain components: {', '.join(missing_paths)}")


def load_original_range(address, size):
    """Load exact slice from the SHA-1 verified original ELF."""
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == ORIGINAL_SHA1
    with ORIGINAL_PATH.open("rb") as f:
        elf = ELFFile(f)
        for seg in elf.iter_segments():
            if seg["p_type"] == "PT_LOAD":
                vaddr = seg["p_vaddr"]
                filesz = seg["p_filesz"]
                if vaddr <= address and address + size <= vaddr + filesz:
                    start = address - vaddr
                    return seg.data()[start:start + size]
    raise AssertionError(f"Address {hex(address)} + {hex(size)} not found in PT_LOAD")


def test_memory_card_screen_native_runner(tmp_path):
    """Compile and execute native unit tests for MemoryCardScreen layout and states."""
    test_bin = tmp_path / "screen_native_test"
    subprocess.run(
        [
            "g++", "-m32", "-std=c++98", "-Iinclude",
            "tests/native/memory_card_screen_test.cpp",
            "-o", str(test_bin),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    res = subprocess.run([str(test_bin)], capture_output=True, text=True, check=True)
    assert "ALL MEMORY CARD SCREEN TESTS PASSED" in res.stdout


def test_jump_table_4d5390_entries():
    """Verify that jtbl_4D5390 in the original ELF matches all 13 expected destinations."""
    require_toolchain()
    table_data = load_original_range(0x4D5390, 13 * 4)
    entries = struct.unpack("<13I", table_data)
    expected = (
        0x33F250, 0x33ED38, 0x33F250, 0x33ED4C, 0x33ED70,
        0x33ED90, 0x33EE1C, 0x33EE70, 0x33F194, 0x33F1B0,
        0x33ED70, 0x33F200, 0x33F234,
    )
    assert entries == expected, f"Table entries mismatch: {entries}"


def test_func_0033F280_resolved_exact_match(tmp_path):
    """Verify compiled func_0033F280 byte-for-byte against the original binary."""
    require_toolchain()
    src = PROJECT_ROOT / "src/ui/memory_card_screen_33f280.cpp"
    obj = tmp_path / "screen_33f280.o"
    subprocess.run(
        [
            str(WRAPPER_PATH), str(COMPILER_PATH),
            "-c", "-O3", "-inline", "on", "-msext", "on", "-char", "signed", "-sym", "off",
            "-Iinclude", "-lang=c++", str(src), "-o", str(obj),
        ],
        cwd=PROJECT_ROOT, capture_output=True, text=True, check=True,
    )

    ld_script = tmp_path / "link.ld"
    ld_script.write_text("SECTIONS { .text 0x33F280 : { *(.text) } }")
    linked_elf = tmp_path / "linked.elf"

    subprocess.run(
        [
            str(LINKER_PATH), "-EL", "-T", str(ld_script), str(obj),
            "--defsym", "strcpy=0x11abbc",
            "--defsym", "strcat=0x11a7bc",
            "--defsym", "func_1F6EA0=0x1F6EA0",
            "--defsym", "func_11A498=0x11A498",
            "--defsym", "func_00219D20=0x219D20",
            "--defsym", "func_0033F540=0x33F540",
            "--defsym", "func_0033F480=0x33F480",
            "--defsym", "func_1F6750=0x1F6750",
            "--defsym", "func_2119B0=0x2119B0",
            "--defsym", "func_2257C0=0x2257C0",
            "--defsym", "func_1F88B0=0x1F88B0",
            "--defsym", "D_1292360=0x1292360",
            "--defsym", "D_004E360C=0x4E360C",
            "--defsym", "D_004E3610=0x4E3610",
            "--defsym", "_gp=0x4EA7C0",
            "-o", str(linked_elf),
        ],
        cwd=PROJECT_ROOT, capture_output=True, text=True, check=True,
    )

    with linked_elf.open("rb") as f:
        elf = ELFFile(f)
        sym = elf.get_section_by_name(".symtab").get_symbol_by_name("func_0033F280")[0]
        sec = elf.get_section(sym["st_shndx"])
        start = sym["st_value"] - sec["sh_addr"]
        compiled_bytes = sec.data()[start:start + sym["st_size"]]

    orig_bytes = load_original_range(0x33F280, len(compiled_bytes))
    assert compiled_bytes == orig_bytes, "Resolved bytes differ from original binary"
