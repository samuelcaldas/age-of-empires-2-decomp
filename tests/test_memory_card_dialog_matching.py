"""Verify memory card dialog decompilation against original SLES-50282 AOK.ELF and native unit tests."""

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


def test_memory_card_dialog_native_runner(tmp_path):
    """Compile and execute native unit tests for MemoryCardDialog layout and states."""
    test_bin = tmp_path / "dialog_native_test"
    subprocess.run(
        [
            "g++", "-m32", "-std=c++98", "-Iinclude",
            "tests/native/memory_card_dialog_test.cpp",
            "-o", str(test_bin),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    res = subprocess.run([str(test_bin)], capture_output=True, text=True, check=True)
    assert "ALL MEMORY CARD DIALOG TESTS PASSED" in res.stdout


def test_jump_tables_4d5570_and_4d55f0_entries():
    """Verify that jtbl_4D5570 and jtbl_4D55F0 in the original ELF have 30 valid destinations each."""
    require_toolchain()
    table_570 = struct.unpack("<30I", load_original_range(0x4D5570, 30 * 4))
    table_5f0 = struct.unpack("<30I", load_original_range(0x4D55F0, 30 * 4))

    # All targets in jtbl_4D5570 must reside within func_00341040 (0x341040 to 0x342170)
    for i, target in enumerate(table_570):
        assert 0x341040 <= target < 0x342170, f"jtbl_4D5570[{i}] out of bounds: {hex(target)}"

    # All targets in jtbl_4D55F0 must reside within func_00342170 (0x342170 to 0x3427A0)
    for i, target in enumerate(table_5f0):
        assert 0x342170 <= target < 0x3427A0, f"jtbl_4D55F0[{i}] out of bounds: {hex(target)}"
