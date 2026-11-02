"""Link each C-built unit alone at its VRAM and compare .text with AOK.ELF.

Usage: .venv/bin/python scripts/verify_units_against_elf.py [unit ...]
Prints MATCH / DIFF / SKIP per unit. Does not modify the build.
"""
import re
import subprocess
import sys
import tempfile
from pathlib import Path

import yaml
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[1]
BIN = ROOT / "build/mips_binutils"
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
CONFIG = ROOT / "config/SLES-50282/config.yml"
SYMBOLS = ROOT / "config/SLES-50282/symbols.txt"
GLOBAL_POINTER = 0x4EA7C0  # gp = 0x4E35DC + 0x71E4, see docs/ps2_binary_analysis.md
HEX_NAME = re.compile(r"^(?:func|D|lbl|jtbl)_(?:0x)?([0-9A-Fa-f]{5,8})$")


def known_symbols():
    """Parse `name = 0xADDR;` lines from symbols.txt."""
    table = {}
    for line in SYMBOLS.read_text().splitlines():
        match = re.match(r"^(\S+)\s*=\s*(0x[0-9A-Fa-f]+);", line)
        if match:
            table[match.group(1)] = int(match.group(2), 16)
    return table


def undefined_symbols(object_path):
    output = subprocess.run([str(BIN / "mips-linux-gnu-nm"), str(object_path)],
                            capture_output=True, text=True, check=True).stdout
    return [line.split()[-1] for line in output.splitlines() if line.startswith(" ") and "U " in line]


def text_size(object_path):
    elf = ELFFile(object_path.open("rb"))
    return elf.get_section_by_name(".text")["sh_size"]


def gp_relative_symbols(object_path):
    output = subprocess.run([str(BIN / "mips-linux-gnu-objdump"), "-r", str(object_path)],
                            capture_output=True, text=True, check=True).stdout
    return {line.split()[-1] for line in output.splitlines() if "R_MIPS_GPREL16" in line}


def signed_gp_address(name):
    """Alternative naming: the low 16 bits of the name are the gp offset."""
    low = int(HEX_NAME.match(name).group(1), 16) & 0xFFFF
    return GLOBAL_POINTER + (low - 0x10000 if low >= 0x8000 else low)


def verify(unit, offset, vram, symbols):
    result = attempt(unit, offset, vram, symbols, False)
    if not result.startswith("DIFF"):
        return result
    alternative = attempt(unit, offset, vram, symbols, True)
    return alternative if alternative == "MATCH" else result


def attempt(unit, offset, vram, symbols, gp_alias):
    ours = ROOT / f"build/SLES-50282/src/{unit}.o"
    target = ROOT / f"build/SLES-50282/obj/{unit}.o"
    if not ours.is_file() or not target.is_file():
        return "SKIP (no object)"
    size = text_size(target)
    gp_names = gp_relative_symbols(ours)
    defs = [f"_gp = {GLOBAL_POINTER:#x};"]
    for name in undefined_symbols(ours):
        address = symbols.get(name)
        if gp_alias and name in gp_names and HEX_NAME.match(name):
            address = signed_gp_address(name)
        if address is None:
            match = HEX_NAME.match(name)
            address = int(match.group(1), 16) if match else None
        if address is None:
            return f"SKIP (unresolved {name})"
        defs.append(f"{name} = {address:#x};")
    with tempfile.TemporaryDirectory() as tmp:
        script = Path(tmp) / "unit.ld"
        script.write_text("SECTIONS { .text %#x : { *(.text) } .lit4 0x4E2808 : { *(.lit4) } .lit8 0x4E2820 : { *(.lit8) } /DISCARD/ : { *(*) } }\n%s\n"
                          % (vram, "\n".join(defs)))
        linked = Path(tmp) / "unit.elf"
        result = subprocess.run([str(BIN / "mips-linux-gnu-ld"), "-EL", "-m", "elf32ltsmip", "-T", str(script),
                                 "-o", str(linked), str(ours)], capture_output=True, text=True)
        if result.returncode != 0:
            return "SKIP (link: " + result.stderr.strip().splitlines()[-1][:60] + ")"
        code = ELFFile(linked.open("rb")).get_section_by_name(".text").data()
        size = min(size, len(code))
        code = code[:size]
    with ORIGINAL.open("rb") as stream:
        stream.seek(offset)
        expected = stream.read(size)
    if code == expected:
        return "MATCH"
    offsets = [i for i in range(0, size, 4) if code[i:i+4] != expected[i:i+4]]
    detail = " ".join(f"+{i:#x}:{expected[i:i+4][::-1].hex()}/{code[i:i+4][::-1].hex()}" for i in offsets[:4])
    return f"DIFF words={len(offsets)}/{size // 4} (orig/ours {detail})"


def main():
    config = yaml.safe_load(CONFIG.read_text())
    symbols = known_symbols()
    wanted = set(sys.argv[1:])
    for segment in config["segments"]:
        unit = segment.get("name") if isinstance(segment, dict) else None
        if not isinstance(segment, dict) or not unit or segment.get("type") != "code" or (wanted and unit not in wanted):
            continue
        print(unit, verify(unit, segment["start"], segment["vram"], symbols))


if __name__ == "__main__":
    main()
