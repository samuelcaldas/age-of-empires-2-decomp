"""Target matching regression tests for KCET Gamepad/Libpad driver (kt_libpad.c).

Verifies that kt_libpad.c compiles with EE-GCC 2.9-991111 (-O2 -G0) into
100% bit-exact machine instructions matching orig/SLES-50282/AOK.ELF across
all 12,144 bytes (VRAM 0x125C38 - 0x128BA8, 100 functions).
"""

from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/kt_libpad.c"
COMPILER = ROOT / "compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe"
WRAPPER = ROOT / "build/tools/wibo"

START_ADDRESS = 0x125C38
FILE_OFFSET = 0x25E18
MODULE_SIZE = 12144

EXTERNAL_SYMBOLS = {
    "D_10DC08": 0x10DC08,
    "D_10DC60": 0x10DC60,
    "D_38C7B8": 0x38C7B8,
    "D_38C7C8": 0x38C7C8,
    "D_48F1F0": 0x48F1F0,
    "D_48F200": 0x48F200,
    "D_48F210": 0x48F210,
    "D_48F220": 0x48F220,
    "D_48F240": 0x48F240,
    "D_48F268": 0x48F268,
    "D_48F298": 0x48F298,
    "D_48F2C0": 0x48F2C0,
    "D_48F2E8": 0x48F2E8,
    "D_48F2F8": 0x48F2F8,
    "D_48F318": 0x48F318,
    "D_48F350": 0x48F350,
    "D_48F378": 0x48F378,
    "D_48F3B0": 0x48F3B0,
    "D_48F3D0": 0x48F3D0,
    "D_48F3E0": 0x48F3E0,
    "D_48F3F0": 0x48F3F0,
    "D_48F430": 0x48F430,
    "D_4E2BC8": 0x4E2BC8,
    "D_4E2BD0": 0x4E2BD0,
    "D_4EA148": 0x4EA148,
    "D_4EA158": 0x4EA158,
    "func_001143C0": 0x1143C0,
    "func_00125A70": 0x125A70,
    "func_00125AA8": 0x125AA8,
    "func_00125AC8": 0x125AC8,
    "func_00125AE8": 0x125AE8,
    "func_103358": 0x103358,
    "func_104B60": 0x104B60,
    "func_10CCB0": 0x10CCB0,
    "func_10CF10": 0x10CF10,
    "func_10D0F8": 0x10D0F8,
    "func_10D260": 0x10D260,
    "func_10D2E0": 0x10D2E0,
    "func_10D3F8": 0x10D3F8,
    "func_10D480": 0x10D480,
    "func_10D6C0": 0x10D6C0,
    "func_10D7F8": 0x10D7F8,
    "func_10D8B0": 0x10D8B0,
    "func_10D968": 0x10D968,
    "func_10DBA8": 0x10DBA8,
    "func_10DDF0": 0x10DDF0,
    "func_10DEC0": 0x10DEC0,
    "func_114320": 0x114320,
    "func_116D40": 0x116D40,
    "func_116F68": 0x116F68,
    "func_128D30": 0x128D30,
    "func_134210": 0x134210,
    "jtbl_48F280": 0x48F280,
    "jtbl_48F410": 0x48F410,
}

R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16 = 4, 5, 6


def require_inputs():
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))


def compile_object(directory):
    output = directory / "kt_libpad.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O2", "-G0", "-Iinclude", "-x", "c",
         "-c", str(SOURCE), "-o", str(output)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stdout + result.stderr
    return output


def test_kt_libpad_compiles_and_matches_target(tmp_path):
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
                target_val = START_ADDRESS
            elif sym.name.startswith("func_0012") or sym.name.startswith("func_0011"):
                try:
                    target_val = int(sym.name.replace("func_", ""), 16)
                except ValueError:
                    target_val = EXTERNAL_SYMBOLS[sym.name]
            else:
                target_val = EXTERNAL_SYMBOLS.get(sym.name)
                if target_val is None:
                    target_val = int(sym.name.replace("func_", "").replace("D_", "").replace("jtbl_", ""), 16)

            if kind == R_MIPS_26:
                local_offset = (inst & 0x03FFFFFF) << 2
                target_val += local_offset
                patched = (inst & 0xFC000000) | ((target_val >> 2) & 0x03FFFFFF)
                struct.pack_into("<I", text, off, patched)
            elif kind == R_MIPS_HI16:
                lo_addend = 0
                for r2 in relocations:
                    if r2["r_offset"] > off and r2["r_info_type"] == R_MIPS_LO16 and r2["r_info_sym"] == r["r_info_sym"]:
                        lo_addend = struct.unpack_from("<h", text, r2["r_offset"])[0]
                        break
                val = target_val + lo_addend
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
