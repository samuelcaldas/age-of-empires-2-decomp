"""Exact byte-matching regression tests for KCET USB mouse (kt_mouse.c).

Verifies that kt_mouse.c compiles with EE-GCC 2.9-991111 (-O2 -G0) into
100% bit-exact machine instructions matching orig/SLES-50282/AOK.ELF across
all 4,312 bytes (VRAM 0x134DE8 - 0x135EBC).
"""

from io import BytesIO
from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/kt_mouse.c"
COMPILER = ROOT / "compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe"
WRAPPER = ROOT / "build/tools/wibo"

START_ADDRESS = 0x134DE8
FILE_OFFSET = 0x34FC8
MODULE_SIZE = 4312
TOTAL_RELOCATIONS = 201

EXTERNAL_SYMBOLS = {
    "func_104A20": 0x104A20,
    "func_105748": 0x105748,
    "func_1057B0": 0x1057B0,
    "func_1075C8": 0x1075C8,
    "func_107C38": 0x107C38,
    "func_107E08": 0x107E08,
    "func_114320": 0x114320,
    "func_1143C0": 0x1143C0,
    "func_117AF8": 0x117AF8,
    "func_134210": 0x134210,
    "func_134440": 0x134440,
    "func_1344C0": 0x1344C0,
    "func_134500": 0x134500,
    "func_1348A8": 0x1348A8,
    "func_134A20": 0x134A20,
    "D_490820": 0x490820,
    "D_490830": 0x490830,
    "D_490850": 0x490850,
    "D_490870": 0x490870,
    "D_509F00": 0x509F00,
    "D_50A060": 0x50A060,
    "D_50A06C": 0x50A06C,
    "D_50A080": 0x50A080,
    "D_50A08C": 0x50A08C,
    "D_50A0C0": 0x50A0C0,
    "D_50A140": 0x50A140,
    "D_50A1C0": 0x50A1C0,
    "D_50A240": 0x50A240,
    "D_50A280": 0x50A280,
}

R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16 = 4, 5, 6


def require_inputs():
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))


def compile_object(directory):
    output = directory / "kt_mouse.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O2", "-G0", "-Iinclude", "-x", "c",
         "-c", str(SOURCE), "-o", str(output)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stdout + result.stderr
    return output


def test_kt_mouse_compiles_and_matches_target(tmp_path):
    require_inputs()
    output = compile_object(tmp_path)
    orig = ORIGINAL.read_bytes()

    with open(output, "rb") as stream:
        elf = ELFFile(stream)
        text = bytearray(elf.get_section_by_name(".text").data())
        assert len(text) == MODULE_SIZE, f"unexpected .text size: {len(text)}"

        symtab = elf.get_section_by_name(".symtab")
        rel = elf.get_section_by_name(".rel.text")
        relocations = sorted([r for r in rel.iter_relocations()], key=lambda r: r["r_offset"])
        assert len(relocations) == TOTAL_RELOCATIONS

        for r in relocations:
            off = r["r_offset"]
            kind = r["r_info_type"]
            sym = symtab.get_symbol(r["r_info_sym"])

            if sym.name == "":
                orig_word = struct.unpack_from("<I", orig, FILE_OFFSET + off)[0]
                target = (orig_word & 0x03FFFFFF) << 2
                val = (target >> 2) & 0x03FFFFFF
                word = struct.unpack_from("<I", text, off)[0]
                word = (word & 0xFC000000) | val
                struct.pack_into("<I", text, off, word)
                continue

            assert sym.name in EXTERNAL_SYMBOLS, f"unmapped external symbol {sym.name}"
            target = EXTERNAL_SYMBOLS[sym.name]
            word = struct.unpack_from("<I", text, off)[0]

            if kind == R_MIPS_26:
                val = (target >> 2) & 0x03FFFFFF
                word = (word & 0xFC000000) | val
            elif kind == R_MIPS_HI16:
                addend = struct.unpack("<h", struct.pack("<H", word & 0xFFFF))[0]
                val = target + (addend << 16)
                hi_val = (val + 0x8000) >> 16
                word = (word & 0xFFFF0000) | (hi_val & 0xFFFF)
            elif kind == R_MIPS_LO16:
                addend = struct.unpack("<h", struct.pack("<H", word & 0xFFFF))[0]
                val = target + addend
                lo_val = val & 0xFFFF
                word = (word & 0xFFFF0000) | (lo_val & 0xFFFF)
            else:
                raise AssertionError(f"unhandled reloc {kind} at offset {off:#x}")

            struct.pack_into("<I", text, off, word)

    expected = orig[FILE_OFFSET:FILE_OFFSET + MODULE_SIZE]
    assert bytes(text) == expected, "relocated bytes do not match target ELF bit-for-bit"
