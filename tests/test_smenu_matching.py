"""Target matching regression tests for PS2 SMENU_CD.BIN overlay (src/smenu_overlay.c).

Verifies that src/smenu_overlay.c compiles with EE-GCC 2.9-991111 (-O2 -G0) into
100% bit-exact machine instructions matching orig/SLES-50282/SMENU_CD.BIN across
all 25,232 bytes in Batches 1..4 (VRAM 0x01D98000 - 0x01D9E290, 45 functions).
"""

from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
OVERLAY_BIN = ROOT / "orig/SLES-50282/SMENU_CD.BIN"
SOURCE = ROOT / "src/smenu_overlay.c"
COMPILER = ROOT / "compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe"
WRAPPER = ROOT / "build/tools/wibo"

OVERLAY_HEADER_SIZE = 0x80
CURRENT_SIZE = 25232
VRAM_BASE = 0x01D98000


def require_inputs():
    missing = [str(path) for path in (OVERLAY_BIN, COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires SMENU_CD.BIN and PS2 tools; missing: " + ", ".join(missing))


def compile_object(directory):
    output = directory / "smenu_overlay.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O2", "-G0", "-Iinclude", "-x", "c",
         "-c", str(SOURCE), "-o", str(output)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, f"Compilation failed:\n{result.stderr}"
    return output


def extract_compiled_text(object_path):
    with object_path.open("rb") as f:
        elf = ELFFile(f)
        text_section = elf.get_section_by_name(".text")
        assert text_section is not None, ".text section missing from compiled object"
        return text_section.data()


def read_original_bytes():
    with OVERLAY_BIN.open("rb") as f:
        f.seek(OVERLAY_HEADER_SIZE)
        data = f.read(CURRENT_SIZE)
        assert len(data) == CURRENT_SIZE, f"Short read from {OVERLAY_BIN}: {len(data)} != {CURRENT_SIZE}"
        return data


def test_smenu_overlay_exact_match(tmp_path):
    require_inputs()
    expected = read_original_bytes()
    compiled_obj = compile_object(tmp_path)
    actual = extract_compiled_text(compiled_obj)

    assert len(actual) == len(expected), f"Length mismatch: {len(actual)} != {len(expected)}"

    mismatches = []
    for offset in range(0, len(expected), 4):
        exp_w, = struct.unpack_from("<I", expected, offset)
        act_w, = struct.unpack_from("<I", actual, offset)
        if exp_w != act_w:
            vma = VRAM_BASE + offset
            mismatches.append(f"0x{vma:08X} (offset +0x{offset:04X}): expected 0x{exp_w:08X}, got 0x{act_w:08X}")

    assert not mismatches, f"{len(mismatches)} mismatches in SMENU decompilation:\n" + "\n".join(mismatches[:20])
