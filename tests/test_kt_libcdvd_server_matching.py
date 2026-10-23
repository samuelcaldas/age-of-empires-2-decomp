"""Target matching and symbol regression tests for KCET CD/DVD Server subsystem (kt_libcdvd_server.c).

Verifies that kt_libcdvd_server.c compiles with EE-GCC 2.9-991111 (-O2 -G0) into
valid object code containing all 150 functions and that no inline assembly remains.
"""

from pathlib import Path
import subprocess

from elftools.elf.elffile import ELFFile
import pytest

import sys
sys.path.insert(0, str(Path(__file__).resolve().parent))
from kt_libcdvd_server_expected_funcs import EXPECTED_FUNCS


ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/kt_libcdvd_server.c"
COMPILER = ROOT / "compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe"
WRAPPER = ROOT / "build/tools/wibo"


def require_inputs():
    missing = [str(path) for path in (COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires PS2 tools; missing: " + ", ".join(missing))


def compile_object(directory):
    output = directory / "kt_libcdvd_server.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O2", "-G0", "-Iinclude", "-x", "c",
         "-c", str(SOURCE), "-o", str(output)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stdout + result.stderr
    return output


def test_kt_libcdvd_server_compiles_and_matches_target(tmp_path):
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
        assert len(funcs) == 150, f"expected 150 functions, found {len(funcs)}"

        rel = elf.get_section_by_name(".rel.text")
        assert rel is not None, ".rel.text missing"

        # Verify no inline assembly remains in C source
        source_text = SOURCE.read_text()
        assert "__asm__" not in source_text, "Found __asm__ in src/kt_libcdvd_server.c; must be pure C"
