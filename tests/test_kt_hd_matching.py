"""Target matching regression tests for KCET Host/Dev Filesystem driver (kt_hd.c).

Verifies that kt_hd.c compiles with EE-GCC 2.9-991111 (-O2 -G0) into
100% bit-exact machine instructions matching orig/SLES-50282/AOK.ELF across
all 2,600 bytes (VRAM 0x128BA8 - 0x1295D0, 27 functions).
"""

from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/kt_hd.c"
COMPILER = ROOT / "compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe"
WRAPPER = ROOT / "build/tools/wibo"

START_ADDRESS = 0x128BA8
FILE_OFFSET = 0x28D88
MODULE_SIZE = 2600

EXTERNAL_SYMBOLS = {
    "D_48F448": 0x48F448,
    "D_48F458": 0x48F458,
    "D_48F468": 0x48F468,
    "D_48F478": 0x48F478,
    "D_48F4B0": 0x48F4B0,
    "D_4E2BF0": 0x4E2BF0,
    "D_4E2C08": 0x4E2C08,
    "D_4E2C10": 0x4E2C10,
    "D_4E2C18": 0x4E2C18,
    "D_4E2C20": 0x4E2C20,
    "D_4E2C28": 0x4E2C28,
    "D_4EA180": 0x4EA180,
    "D_4EA1C0": 0x4EA1C0,
    "D_4EA7C0": 0x4EA7C0,
    "D_4EC1C0": 0x4EC1C0,
    "D_4ED300": 0x4ED300,
    "func_0011ACD0": 0x11ACD0,
    "func_00128A20": 0x128A20,
    "func_00128B18": 0x128B18,
    "func_00128B68": 0x128B68,
    "func_103358": 0x103358,
    "func_104B20": 0x104B20,
    "func_104B40": 0x104B40,
    "func_104C10": 0x104C10,
    "func_104C20": 0x104C20,
    "func_108D38": 0x108D38,
    "func_108FC0": 0x108FC0,
    "func_109140": 0x109140,
    "func_109378": 0x109378,
    "func_1095E8": 0x1095E8,
    "func_114320": 0x114320,
    "func_11AFB8": 0x11AFB8,
    "func_12D988": 0x12D988,
    "func_12D990": 0x12D990,
    "func_134210": 0x134210,
    "func_134440": 0x134440,
    "func_1344C0": 0x1344C0,
    "strcat": 0x11A7BC,
    "strcpy": 0x11ABBC,
}

R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16 = 4, 5, 6


def require_inputs():
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))


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
            elif sym.name.startswith("func_00128") or sym.name.startswith("func_00129"):
                target_val = int(sym.name.replace("func_", ""), 16)
            else:
                target_val = EXTERNAL_SYMBOLS.get(sym.name)
                if target_val is None:
                    target_val = int(sym.name.replace("func_", "").replace("D_", ""), 16)

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
