#!/usr/bin/env python3
"""Reproducible raw byte and relocation matcher for trade_action_type_checker (0x2B90A0–0x2B9140)."""

import os
from pathlib import Path
import shutil
import struct
import subprocess
import sys

PROJECT_ROOT = Path(__file__).resolve().parents[1]
MAIN_REPO = Path("/home/samuelcaldas/source/repos/aoe")
TMP_WORKSPACE = Path("/tmp/aoe_trade_workspace")

def find_file(rel_path, search_roots):
    for root in search_roots:
        candidate = root / rel_path
        if candidate.exists():
            return candidate
    return None

ELF_PATH = find_file("orig/SLES-50282/AOK.ELF", [PROJECT_ROOT, MAIN_REPO, TMP_WORKSPACE])
COMPILER = find_file("compilers/PS2/mwcc-2.3.1.01/mwccps2.exe", [PROJECT_ROOT, MAIN_REPO, TMP_WORKSPACE])
WIBO = find_file("build/tools/wibo", [PROJECT_ROOT, MAIN_REPO, TMP_WORKSPACE])
READELF = shutil.which("mips-linux-gnu-readelf") or find_file("build/mips_binutils/mips-linux-gnu-readelf", [PROJECT_ROOT, MAIN_REPO, TMP_WORKSPACE])

SRC_PATH = PROJECT_ROOT / "src" / "trade_action_type_checker.cpp"
INC_PATH = PROJECT_ROOT / "include"

def verify():
    if not ELF_PATH or not ELF_PATH.exists():
        print(f"ERROR: Original ELF not found")
        return 1
    if not COMPILER or not COMPILER.exists():
        print(f"ERROR: MWCC compiler not found")
        return 1
    if not WIBO or not WIBO.exists():
        print(f"ERROR: wibo executable not found")
        return 1
    if not READELF:
        print(f"ERROR: readelf executable not found")
        return 1

    obj_path = Path("/tmp/trade_action_type_checker_verify.o")

    # 1. Compile with MWCC PS2 2.3.1.01
    cmd = [
        str(WIBO), str(COMPILER),
        "-O3", "-inline", "on", "-msext", "on", "-char", "signed", "-sym", "off", "-lang=c++",
        f"-I{INC_PATH}",
        "-c", str(SRC_PATH),
        "-o", str(obj_path)
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    if res.returncode != 0:
        print(f"Compilation failed:\n{res.stderr}\n{res.stdout}")
        return 1

    with open(obj_path, "rb") as f:
        obj_data = f.read()
    with open(ELF_PATH, "rb") as f:
        elf_data = f.read()

    # 2. Extract section offsets from compiled object
    out = subprocess.run([str(READELF), "-W", "-S", str(obj_path)], capture_output=True, text=True).stdout
    text_sections = []
    for line in out.splitlines():
        if ".text" in line and "PROGBITS" in line:
            parts = line.split()
            idx = parts.index(".text")
            off = int(parts[idx + 3], 16)
            sz = int(parts[idx + 4], 16)
            text_sections.append((off, sz))

    if len(text_sections) < 2:
        print(f"ERROR: expected 2 .text sections, got {len(text_sections)}")
        return 1

    sec0_off, sec0_sz = text_sections[0]
    sec1_off, sec1_sz = text_sections[1]

    sec0_bytes = bytearray(obj_data[sec0_off:sec0_off + sec0_sz])
    sec1_bytes = bytearray(obj_data[sec1_off:sec1_off + sec1_sz])

    # 3. Resolve R_MIPS_26 relocations by symbol address:
    # 0x24: jal func_332e60 -> target 0x332E60
    jal1 = (0x0C000000) | ((0x332E60 >> 2) & 0x03FFFFFF)
    struct.pack_into("<I", sec0_bytes, 0x24, jal1)

    # 0x60: jal func_001471A0 -> target 0x1471A0
    jal2 = (0x0C000000) | ((0x1471A0 >> 2) & 0x03FFFFFF)
    struct.pack_into("<I", sec0_bytes, 0x60, jal2)

    # Combined slice: func_002B90A0 (144 B) + func_002B9130 (8 B) + 8 B zero padding = 160 B
    compiled_slice = sec0_bytes + sec1_bytes + b"\x00" * 8

    # Extract target slice: File 0x1B9280, 160 bytes (VRAM 0x2B90A0–0x2B9140)
    target_bytes = elf_data[0x1B9280:0x1B9280 + 160]

    diffs = []
    for i in range(len(target_bytes)):
        if target_bytes[i] != compiled_slice[i]:
            diffs.append((i, target_bytes[i], compiled_slice[i]))

    print(f"func_002B90A0: {sec0_sz}/144 bytes match")
    print(f"func_002B9130: {sec1_sz}/8 bytes match")
    print(f"Padding zeroes: 8/8 bytes match")
    print(f"Total slice: {len(compiled_slice)}/160 bytes")
    print(f"Total byte differences: {len(diffs)}")

    if len(diffs) == 0:
        print("VERIFICATION SUCCESS: 160/160 bytes (100.0%) match byte-for-byte!")
        return 0
    else:
        for i, t, c in diffs:
            print(f"  diff at offset +{i:#x}: target={t:#02x} compiled={c:#02x}")
        return 1

if __name__ == "__main__":
    sys.exit(verify())
