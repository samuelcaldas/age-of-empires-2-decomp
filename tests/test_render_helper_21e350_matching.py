"""Exact binary matching test for render_helper_21e350."""

import hashlib
from pathlib import Path
import subprocess

import pytest
from elftools.elf.elffile import ELFFile


PROJECT_ROOT = Path(__file__).resolve().parents[1]
ORIGINAL_PATH = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER_PATH = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER_PATH = PROJECT_ROOT / "build/tools/wibo"
FUNCTION_OFFSET = 0x11E530
FUNCTION_SIZE = 0x18


def require_original():
    """Skip absent licensed input, but verify hash when present."""
    if not ORIGINAL_PATH.is_file():
        pytest.skip("requires licensed SLES-50282 original ELF")
    pinned = (PROJECT_ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == pinned


def test_render_helper_21e350_exact_match(tmp_path):
    """Verify bit-for-bit instruction match against original AOK.ELF."""
    require_original()
    if not COMPILER_PATH.is_file() or not WRAPPER_PATH.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")

    output_path = tmp_path / "render_helper_21e350.o"
    subprocess.run(
        [str(WRAPPER_PATH), str(COMPILER_PATH), "-O3", "-inline", "on",
         "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
         "-lang=c++", "-c", "src/render/render_helper_21e350.cpp", "-o", str(output_path)],
        cwd=PROJECT_ROOT, capture_output=True, text=True, check=True,
    )

    with open(output_path, "rb") as f:
        elf = ELFFile(f)
        text = elf.get_section_by_name(".text").data()

    with open(ORIGINAL_PATH, "rb") as f:
        f.seek(FUNCTION_OFFSET)
        expected = f.read(FUNCTION_SIZE)

    assert len(text) == FUNCTION_SIZE, f"size mismatch: {len(text)} != {FUNCTION_SIZE}"
    assert text == expected, "instruction bytes do not match original binary"
