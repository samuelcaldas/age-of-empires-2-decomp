"""Target matching regression tests for KCET GPU driver (kt_gpu.c).

Verifies that kt_gpu.c compiles with EE-GCC 2.9-991111 (-O2 -G0) into
100% bit-exact machine instructions matching orig/SLES-50282/AOK.ELF across
all 1,072 bytes (VRAM 0x125808 - 0x125C38).
"""

from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/kt_gpu.c"
COMPILER = ROOT / "compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe"
WRAPPER = ROOT / "build/tools/wibo"

START_ADDRESS = 0x125808
FILE_OFFSET = 0x259E8
MODULE_SIZE = 1072

EXTERNAL_SYMBOLS = {
    "func_1045E8": 0x1045E8,
    "func_1046A8": 0x1046A8,
    "func_123A70": 0x123A70,
    "func_114320": 0x114320,
    "func_104448": 0x104448,
    "func_104600": 0x104600,
    "func_134500": 0x134500,
    "func_134440": 0x134440,
    "func_10D8B0": 0x10D8B0,
    "func_10D0F8": 0x10D0F8,
    "func_10CE90": 0x10CE90,
    "func_116F68": 0x116F68,
    "func_1344C0": 0x1344C0,
    "D_38C730": 0x38C730,
    "D_38C740": 0x38C740,
    "D_48F1B8": 0x48F1B8,
    "D_48F1C8": 0x48F1C8,
    "D_4EA148": 0x4EA148,
}

R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16 = 4, 5, 6


def require_inputs():
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))


def compile_object(directory):
    output = directory / "kt_gpu.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O2", "-G0", "-Iinclude", "-x", "c",
         "-c", str(SOURCE), "-o", str(output)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stdout + result.stderr
    return output


def test_kt_gpu_compiles_and_matches_target(tmp_path):
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

        # Patch relocations in text to verify exact matching against original ELF
        for r in relocations:
            off = r["r_offset"]
            kind = r["r_info_type"]
            sym = symtab.get_symbol(r["r_info_sym"])

            inst = struct.unpack_from("<I", text, off)[0]

            if sym.name == "":
                # Local symbol / internal reference. The addend is in the low 26 bits of the JAL instruction.
                local_offset = (inst & 0x03FFFFFF) << 2
                target_val = START_ADDRESS + local_offset
            else:
                target_val = EXTERNAL_SYMBOLS.get(sym.name)
                assert target_val is not None, f"Unknown symbol {sym.name} at relocation offset 0x{off:x}"

            if kind == R_MIPS_26:
                patched = (inst & 0xFC000000) | ((target_val >> 2) & 0x03FFFFFF)
                struct.pack_into("<I", text, off, patched)
            elif kind == R_MIPS_HI16:
                addend = (inst & 0xFFFF) << 16
                for r2 in relocations:
                    if r2["r_offset"] > off and r2["r_info_type"] == R_MIPS_LO16 and r2["r_info_sym"] == r["r_info_sym"]:
                        lo_addend = struct.unpack_from("<h", text, r2["r_offset"])[0]
                        addend += lo_addend
                        break
                val = target_val + addend
                hi = (val + 0x8000) >> 16
                patched = (inst & 0xFFFF0000) | (hi & 0xFFFF)
                struct.pack_into("<I", text, off, patched)
            elif kind == R_MIPS_LO16:
                addend = struct.unpack_from("<h", text, off)[0]
                val = target_val + addend
                lo = val & 0xFFFF
                patched = (inst & 0xFFFF0000) | lo
                struct.pack_into("<I", text, off, patched)

        expected = orig[FILE_OFFSET : FILE_OFFSET + MODULE_SIZE]
        assert bytes(text) == expected
