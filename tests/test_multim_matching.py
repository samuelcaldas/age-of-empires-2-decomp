"""Target matching and symbol regression tests for PS2 MULTIMCD.BIN overlay (src/overlays/multim_overlay.c).

Verifies that src/overlays/multim_overlay.c compiles with EE-GCC 2.9-991111 (-O2 -G0) into
valid object code containing all 19 structured functions and matches the slideshow tables
(.rodata section, 75,712 bytes).
"""

from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest

import sys
sys.path.insert(0, str(Path(__file__).resolve().parent))
from multim_expected_funcs import EXPECTED_FUNCS


ROOT = Path(__file__).resolve().parents[1]
OVERLAY_BIN = ROOT / "orig/SLES-50282/MULTIMCD.BIN"
SOURCE = ROOT / "src/overlays/multim_overlay.c"
COMPILER = ROOT / "compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe"
WRAPPER = ROOT / "build/tools/wibo"

OVERLAY_HEADER_SIZE = 0x80
TEXT_SIZE = 7872
RODATA_SIZE = 75712
VRAM_BASE = 0x01D98000
RODATA_VRAM_BASE = 0x01D99EC0


def require_inputs():
    missing = [str(path) for path in (OVERLAY_BIN, COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires MULTIMCD.BIN and PS2 tools; missing: " + ", ".join(missing))


def compile_object(directory):
    output = directory / "multim_overlay.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O2", "-G0", "-Iinclude", "-x", "c",
         "-c", str(SOURCE), "-o", str(output)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, f"Compilation failed:\n{result.stderr}"
    return output


def test_multim_overlay_compiles_and_contains_all_functions(tmp_path):
    require_inputs()
    compiled_obj = compile_object(tmp_path)
    with compiled_obj.open("rb") as f:
        elf = ELFFile(f)
        text_section = elf.get_section_by_name(".text")
        assert text_section is not None, ".text section missing"
        assert len(text_section.data()) > 0, ".text section empty"

        symtab = elf.get_section_by_name(".symtab")
        funcs = [s.name for s in symtab.iter_symbols() if s["st_info"]["type"] == "STT_FUNC"]
        objects = [s.name for s in symtab.iter_symbols() if s["st_info"]["type"] == "STT_OBJECT"]
        for fn in EXPECTED_FUNCS:
            assert fn in funcs, f"Missing function {fn} in .symtab"
        assert len(funcs) == 19, f"Expected 19 functions, got {len(funcs)}"
        assert "multim_data" in objects, "Missing multim_data object symbol in .symtab"

        # Verify no inline assembly remains in C source
        source_text = SOURCE.read_text()
        assert "__asm__" not in source_text, "Found __asm__ in src/overlays/multim_overlay.c; must be pure C"


def test_multim_overlay_rodata_exact_match(tmp_path):
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

    assert not mismatches, f"{len(mismatches)} mismatches in MULTIM .rodata:\n" + "\n".join(mismatches[:20])
