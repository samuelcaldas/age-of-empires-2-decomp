"""Exact byte-matching regression tests for KCET USB keyboard driver (kt_usbkeybd_drv.c).

Verifies that kt_usbkeybd_drv.c compiles with EE-GCC 2.9-991111 (-O2 -G0) into
100% bit-exact machine instructions matching orig/SLES-50282/AOK.ELF across
all 628 bytes (VRAM 0x137208 - 0x13747C).
"""

from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/kcet/kt_usbkeybd_drv.c"
COMPILER = ROOT / "compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe"
WRAPPER = ROOT / "build/tools/wibo"

START_ADDRESS = 0x137208
FILE_OFFSET = 0x373E8
MODULE_SIZE = 628

EXTERNAL_SYMBOLS = {
    "func_1075C8": 0x1075C8,
    "func_107C38": 0x107C38,
    "func_107E08": 0x107E08,
    "func_114320": 0x114320,
    "D_490A60": 0x490A60,
    "D_490A78": 0x490A78,
    "D_490A98": 0x490A98,
    "D_490AB8": 0x490AB8,
    "D_50A540": 0x50A540,
    "D_50A580": 0x50A580,
}

R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16 = 4, 5, 6


def require_inputs():
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))


def compile_object(directory):
    output = directory / "kt_usbkeybd_drv.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O2", "-G0", "-Iinclude", "-x", "c",
         "-c", str(SOURCE), "-o", str(output)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stdout + result.stderr
    return output


def test_kt_usbkeybd_drv_compiles_and_matches_target(tmp_path):
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

        for r in relocations:
            off = r["r_offset"]
            kind = r["r_info_type"]
            sym = symtab.get_symbol(r["r_info_sym"])
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
