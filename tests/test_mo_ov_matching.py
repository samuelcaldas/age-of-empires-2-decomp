"""Target matching regression tests for PS2 MO_OV_CD.BIN overlay (src/mo_ov_overlay.c).

Verifies that src/mo_ov_overlay.c compiles with EE-GCC 2.9-991111 (-O2 -G0) into
100% bit-exact machine instructions and data matching orig/SLES-50282/MO_OV_CD.BIN
across the entire payload (512 bytes: 192 bytes .text + 320 bytes .rodata,
2 structured functions for PSS video playback).
"""

from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
OVERLAY_BIN = ROOT / "orig/SLES-50282/MO_OV_CD.BIN"
SOURCE = ROOT / "src/mo_ov_overlay.c"
COMPILER = ROOT / "compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe"
WRAPPER = ROOT / "build/tools/wibo"

OVERLAY_HEADER_SIZE = 0x80
TEXT_SIZE = 192
RODATA_SIZE = 320
VRAM_BASE = 0x01ED7000
RODATA_VRAM_BASE = 0x01ED70C0


def require_inputs():
    missing = [str(path) for path in (OVERLAY_BIN, COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires MO_OV_CD.BIN and PS2 tools; missing: " + ", ".join(missing))


def compile_object(directory):
    output = directory / "mo_ov_overlay.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O2", "-G0", "-Iinclude", "-x", "c",
         "-c", str(SOURCE), "-o", str(output)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, f"Compilation failed:\n{result.stderr}"
    return output


def test_mo_ov_overlay_text_exact_match(tmp_path):
    require_inputs()
    with OVERLAY_BIN.open("rb") as f:
        f.seek(OVERLAY_HEADER_SIZE)
        expected_text = f.read(TEXT_SIZE)
        assert len(expected_text) == TEXT_SIZE

    compiled_obj = compile_object(tmp_path)
    with compiled_obj.open("rb") as f:
        elf = ELFFile(f)
        text_section = elf.get_section_by_name(".text")
        assert text_section is not None, ".text section missing"
        actual_text = text_section.data()

    assert len(actual_text) == len(expected_text), f"Length mismatch: {len(actual_text)} != {len(expected_text)}"

    mismatches = []
    for offset in range(0, len(expected_text), 4):
        exp_w, = struct.unpack_from("<I", expected_text, offset)
        act_w, = struct.unpack_from("<I", actual_text, offset)
        if exp_w != act_w:
            vma = VRAM_BASE + offset
            mismatches.append(f"0x{vma:08X} (offset +0x{offset:04X}): expected 0x{exp_w:08X}, got 0x{act_w:08X}")

    assert not mismatches, f"{len(mismatches)} mismatches in MO_OV .text:\n" + "\n".join(mismatches[:20])


def test_mo_ov_overlay_rodata_exact_match(tmp_path):
    require_inputs()
    with OVERLAY_BIN.open("rb") as f:
        f.seek(OVERLAY_HEADER_SIZE + TEXT_SIZE)
        expected_rodata = f.read(RODATA_SIZE)
        assert len(expected_rodata) == RODATA_SIZE

    compiled_obj = compile_object(tmp_path)
    with compiled_obj.open("rb") as f:
        elf = ELFFile(f)
        rodata_section = elf.get_section_by_name(".rodata")
        assert rodata_section is not None, ".rodata section missing"
        actual_rodata = rodata_section.data()

    assert len(actual_rodata) == len(expected_rodata), f"Length mismatch: {len(actual_rodata)} != {len(expected_rodata)}"

    mismatches = []
    for offset in range(0, len(expected_rodata), 4):
        exp_w, = struct.unpack_from("<I", expected_rodata, offset)
        act_w, = struct.unpack_from("<I", actual_rodata, offset)
        if exp_w != act_w:
            vma = RODATA_VRAM_BASE + offset
            mismatches.append(f"0x{vma:08X} (offset +0x{offset:04X}): expected 0x{exp_w:08X}, got 0x{act_w:08X}")

    assert not mismatches, f"{len(mismatches)} mismatches in MO_OV .rodata:\n" + "\n".join(mismatches[:20])
