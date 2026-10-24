"""Compilation and symbol verification tests for KCET Host/Dev Filesystem driver (kt_hd.c).

Verifies that kt_hd.c compiles with EE-GCC 2.9-991111 (-O2 -G0) into
valid object code containing all 27 filesystem functions.
"""

from pathlib import Path
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/kcet/kt_hd.c"
COMPILER = ROOT / "compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe"
WRAPPER = ROOT / "build/tools/wibo"

EXPECTED_FUNCS = [
    "func_00128BA8", "func_00128CF0", "func_00128D10", "func_00128D30",
    "func_00128D50", "func_00128D70", "func_00128D90", "func_00128DC0",
    "func_00128EC8", "func_00128F40", "func_00128F68", "func_00128F70",
    "func_00129108", "func_00129248", "func_00129348", "func_00129388",
    "func_001293A8", "func_001293E0", "func_00129428", "func_001294A0",
    "func_001294C0", "func_001294E0", "func_001294E8", "func_00129538",
    "func_00129548", "func_00129560", "func_00129588"
]


def require_inputs():
    missing = [str(path) for path in (COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires PS2 tools; missing: " + ", ".join(missing))


def compile_object(directory):
    output = directory / "kt_hd.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O2", "-G0", "-Iinclude", "-x", "c",
         "-c", str(SOURCE), "-o", str(output)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stdout + result.stderr
    return output


def test_kt_hd_compiles_and_matches_target(tmp_path):
    require_inputs()
    output = compile_object(tmp_path)

    with open(output, "rb") as stream:
        elf = ELFFile(stream)
        text = bytearray(elf.get_section_by_name(".text").data())
        assert len(text) > 0, "empty .text section"

        symtab = elf.get_section_by_name(".symtab")
        funcs = [s.name for s in symtab.iter_symbols() if s["st_info"]["type"] == "STT_FUNC"]

        for fn in EXPECTED_FUNCS:
            assert fn in funcs, f"missing function: {fn}"
        assert len(funcs) == 27, f"expected 27 functions, found {len(funcs)}"

        rel = elf.get_section_by_name(".rel.text")
        assert rel is not None, ".rel.text missing"
