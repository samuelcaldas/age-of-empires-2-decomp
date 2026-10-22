"""Exact byte-matching regression tests for KCET keyboard interface (kt_keybd.c).

Verifies that kt_keybd.c compiles with EE-GCC 2.9-991111 (-O2 -G0) into
100% bit-exact machine instructions matching orig/SLES-50282/AOK.ELF across
all 4,936 bytes (VRAM 0x135EC0 - 0x137208).
"""

from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/kt_keybd.c"
COMPILER = ROOT / "compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe"
WRAPPER = ROOT / "build/tools/wibo"

START_ADDRESS = 0x135EC0
FILE_OFFSET = 0x360A0
MODULE_SIZE = 4936
TOTAL_RELOCATIONS = 260

EXTERNAL_SYMBOLS = {
    "D_490888": 0x490888,
    "D_4908A8": 0x4908A8,
    "D_4908B8": 0x4908B8,
    "D_4908C8": 0x4908C8,
    "D_4908E8": 0x4908E8,
    "D_490900": 0x490900,
    "D_490910": 0x490910,
    "D_490928": 0x490928,
    "D_490938": 0x490938,
    "D_490950": 0x490950,
    "D_490968": 0x490968,
    "D_490980": 0x490980,
    "D_490998": 0x490998,
    "D_4909B0": 0x4909B0,
    "D_4909D0": 0x4909D0,
    "D_4909F0": 0x4909F0,
    "D_490A08": 0x490A08,
    "D_490A20": 0x490A20,
    "D_490A40": 0x490A40,
    "D_50A2C0": 0x50A2C0,
    "D_50A338": 0x50A338,
    "D_50A380": 0x50A380,
    "D_50A38C": 0x50A38C,
    "D_50A3C0": 0x50A3C0,
    "D_50A440": 0x50A440,
    "D_50A4C0": 0x50A4C0,
    "func_00137208": 0x137208,
    "func_00137250": 0x137250,
    "func_001372C0": 0x1372C0,
    "func_00137340": 0x137340,
    "func_001373C0": 0x1373C0,
    "func_00137420": 0x137420,
    "func_1143C0": 0x1143C0,
    "func_117AF8": 0x117AF8,
    "func_117CAC": 0x117CAC,
    "func_123790": 0x123790,
    "func_134210": 0x134210,
    "func_134440": 0x134440,
    "func_1344C0": 0x1344C0,
    "func_134500": 0x134500,
    "func_1348A8": 0x1348A8,
    "func_134A20": 0x134A20,
}

R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16 = 4, 5, 6


def require_inputs():
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))


def compile_object(directory):
    output = directory / "kt_keybd.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O2", "-G0", "-Iinclude", "-x", "c",
         "-c", str(SOURCE), "-o", str(output)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stdout + result.stderr
    return output


def test_kt_keybd_compiles_and_matches_target(tmp_path):
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
                target = START_ADDRESS
            else:
                assert sym.name in EXTERNAL_SYMBOLS, f"unmapped external symbol {sym.name}"
                target = EXTERNAL_SYMBOLS[sym.name]

            word = struct.unpack_from("<I", text, off)[0]

            if kind == R_MIPS_26:
                if sym.name == "":
                    addend = ((word & 0x03FFFFFF) << 2)
                    target = START_ADDRESS + addend
                val = (target >> 2) & 0x03FFFFFF
                word = (word & 0xFC000000) | val
            elif kind == R_MIPS_HI16:
                lo_val = 0
                for r2 in relocations:
                    if r2["r_info_sym"] == r["r_info_sym"] and r2["r_info_type"] == R_MIPS_LO16 and r2["r_offset"] >= off:
                        lo_word = struct.unpack_from("<I", text, r2["r_offset"])[0]
                        lo_val = struct.unpack("<h", struct.pack("<H", lo_word & 0xFFFF))[0]
                        break
                full = target + lo_val
                hi = ((full + 0x8000) >> 16) & 0xFFFF
                word = (word & 0xFFFF0000) | hi
            elif kind == R_MIPS_LO16:
                lo_addend = struct.unpack("<h", struct.pack("<H", word & 0xFFFF))[0]
                full = target + lo_addend
                word = (word & 0xFFFF0000) | (full & 0xFFFF)
            else:
                raise AssertionError(f"unhandled reloc {kind} at offset {off:#x}")

            struct.pack_into("<I", text, off, word)

    expected = orig[FILE_OFFSET:FILE_OFFSET + MODULE_SIZE]
    assert bytes(text) == expected, "relocated bytes do not match target ELF bit-for-bit"
