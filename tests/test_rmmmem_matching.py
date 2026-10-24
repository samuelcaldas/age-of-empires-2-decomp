"""Compilation and symbol verification tests for PS2 RMMMEMCD.BIN overlay (src/overlays/rmmmem_overlay.c).

Verifies that src/overlays/rmmmem_overlay.c compiles with EE-GCC 2.9-991111 (-O2 -G0) into
structured object code containing all 5 Random Map heap allocator functions.
"""

from pathlib import Path
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/overlays/rmmmem_overlay.c"
COMPILER = ROOT / "compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe"
WRAPPER = ROOT / "build/tools/wibo"


def require_inputs():
    missing = [str(path) for path in (COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires PS2 tools; missing: " + ", ".join(missing))


def compile_object(directory):
    output = directory / "rmmmem_overlay.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O2", "-G0", "-Iinclude", "-x", "c",
         "-c", str(SOURCE), "-o", str(output)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, f"Compilation failed:\n{result.stderr}"
    return output


def test_rmmmem_overlay_compiles_and_matches_target(tmp_path):
    require_inputs()
    output = compile_object(tmp_path)

    with open(output, "rb") as stream:
        elf = ELFFile(stream)
        text = bytearray(elf.get_section_by_name(".text").data())
        assert len(text) > 0, "empty .text section"

        symtab = elf.get_section_by_name(".symtab")
        funcs = [s.name for s in symtab.iter_symbols() if s["st_info"]["type"] == "STT_FUNC"]

        expected_funcs = [
            "rmmmem_func_01D98000",
            "rmmmem_func_01D98050",
            "rmmmem_func_01D980FC",
            "rmmmem_func_01D98150",
            "rmmmem_func_01D98284",
        ]
        for fn in expected_funcs:
            assert fn in funcs, f"missing function: {fn}"
        assert len(funcs) == 5, f"expected 5 functions, found {len(funcs)}"

        rel = elf.get_section_by_name(".rel.text")
        assert rel is not None, ".rel.text missing"
