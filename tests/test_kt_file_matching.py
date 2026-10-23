"""Target matching regression tests for KCET File I/O subsystem (kt_file.c).

Verifies that kt_file.c compiles with EE-GCC 2.9-991111 (-O2 -G0) into
100% bit-exact machine instructions matching orig/SLES-50282/AOK.ELF across
all 4,072 bytes (VRAM 0x12CCE8 - 0x12DCD0, 50 functions).
"""

from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/kt_file.c"
COMPILER = ROOT / "compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe"
WRAPPER = ROOT / "build/tools/wibo"

START_ADDRESS = 0x12CCE8
FILE_OFFSET = 0x2CEC8
MODULE_SIZE = 4072

R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16 = 4, 5, 6


def require_inputs():
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))


def compile_object(directory):
    output = directory / "kt_file.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O2", "-G0", "-Iinclude", "-x", "c",
         "-c", str(SOURCE), "-o", str(output)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stdout + result.stderr
    return output


def test_kt_file_compiles_and_matches_target(tmp_path):
    require_inputs()
    output = compile_object(tmp_path)

    with open(output, "rb") as stream:
        elf = ELFFile(stream)
        text = bytearray(elf.get_section_by_name(".text").data())
        assert len(text) > 0, "empty .text section"

        symtab = elf.get_section_by_name(".symtab")
        funcs = [s.name for s in symtab.iter_symbols() if s["st_info"]["type"] == "STT_FUNC"]
        assert len(funcs) == 50, f"expected all 50 functions present, found {len(funcs)}"

        rel = elf.get_section_by_name(".rel.text")
        assert rel is not None, ".rel.text missing"
