"""Compilation and symbol verification tests for KCET Kernel/Threading subsystem (kt_kernel.c).

Verifies that kt_kernel.c compiles with EE-GCC 2.9-991111 (-O2 -G0) into
structured object code containing all 39 kernel, thread, semaphore, and V-Sync functions.
"""

from pathlib import Path
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/kt_kernel.c"
COMPILER = ROOT / "compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe"
WRAPPER = ROOT / "build/tools/wibo"


def require_inputs():
    missing = [str(path) for path in (COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires PS2 tools; missing: " + ", ".join(missing))


def compile_object(directory):
    output = directory / "kt_kernel.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O2", "-G0", "-Iinclude", "-x", "c",
         "-c", str(SOURCE), "-o", str(output)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stdout + result.stderr
    return output


def test_kt_kernel_compiles_and_matches_target(tmp_path):
    require_inputs()
    output = compile_object(tmp_path)

    with open(output, "rb") as stream:
        elf = ELFFile(stream)
        text = bytearray(elf.get_section_by_name(".text").data())
        assert len(text) > 0, "empty .text section"

        symtab = elf.get_section_by_name(".symtab")
        funcs = [s.name for s in symtab.iter_symbols() if s["st_info"]["type"] == "STT_FUNC"]

        expected_funcs = [
            "func_00134140", "func_00134168", "func_00134188", "func_001341B8",
            "func_00134210", "func_00134290", "func_00134330", "func_00134378",
            "func_001343A8", "func_001343F8", "func_00134440", "func_00134480",
            "func_001344C0", "func_00134500", "func_00134528", "func_00134538",
            "func_00134548", "func_00134558", "func_00134568", "func_001345D0",
            "func_00134638", "func_001346A8", "func_00134710", "func_001347A8",
            "func_00134828", "func_001348A8", "func_00134928", "func_00134970",
            "func_001349E8", "func_00134A20", "func_00134A58", "func_00134A78",
            "func_00134AF0", "func_00134BB0", "func_00134C60", "func_00134CB8",
            "func_00134CF0", "func_00134D48", "func_00134D80"
        ]

        for fn in expected_funcs:
            assert fn in funcs, f"missing function: {fn}"
        assert len(funcs) == 39, f"expected 39 functions, found {len(funcs)}"

        rel = elf.get_section_by_name(".rel.text")
        assert rel is not None, ".rel.text missing"
