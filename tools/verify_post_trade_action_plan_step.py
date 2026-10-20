#!/usr/bin/env python3
"""Robust ELF relocation and section parser for post_trade_action_plan_step (0x2B9B30–0x2BA160)."""

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

SRC_PATH = PROJECT_ROOT / "src" / "post_trade_action_plan_step.cpp"
INC_PATH = PROJECT_ROOT / "include"

SYMBOL_TARGETS = {
    "func_332e60": 0x332E60,
    "func_002261C0": 0x2261C0,
    "func_001471A0": 0x1471A0,
    "func_002C1920": 0x2C1920,
    "func_00147170": 0x147170,
    "func_00147190": 0x147190,
    "func_002BAA20": 0x2BAA20,
}

def verify(expected_slice_len=1584, elf_override_bytes=None, inject_extra_code=0):
    if (not elf_override_bytes) and (not ELF_PATH or not ELF_PATH.exists()):
        print(f"ERROR: Original ELF not found at {ELF_PATH}")
        return 1
    if not COMPILER or not COMPILER.exists():
        print(f"ERROR: MWCC compiler not found at {COMPILER}")
        return 1
    if not WIBO or not WIBO.exists():
        print(f"ERROR: wibo executable not found at {WIBO}")
        return 1

    obj_path = Path("/tmp/post_trade_action_plan_step_verify.o")

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

    if elf_override_bytes is not None:
        elf_data = elf_override_bytes
    else:
        with open(ELF_PATH, "rb") as f:
            elf_data = f.read()

    # 2. Parse ELF Header
    e_shoff = struct.unpack_from("<I", obj_data, 32)[0]
    e_shentsize = struct.unpack_from("<H", obj_data, 46)[0]
    e_shnum = struct.unpack_from("<H", obj_data, 48)[0]
    e_shstrndx = struct.unpack_from("<H", obj_data, 50)[0]

    sections = []
    for i in range(e_shnum):
        sh_offset = e_shoff + i * e_shentsize
        fields = struct.unpack_from("<10I", obj_data, sh_offset)
        sections.append({
            "idx": i,
            "sh_name": fields[0],
            "sh_type": fields[1],
            "sh_flags": fields[2],
            "sh_addr": fields[3],
            "sh_offset": fields[4],
            "sh_size": fields[5],
            "sh_link": fields[6],
            "sh_info": fields[7],
            "sh_addralign": fields[8],
            "sh_entsize": fields[9],
        })

    shstrtab = obj_data[sections[e_shstrndx]["sh_offset"]:sections[e_shstrndx]["sh_offset"] + sections[e_shstrndx]["sh_size"]]
    def get_str(strtab, offset):
        end = strtab.find(b"\x00", offset)
        return strtab[offset:end].decode("ascii", errors="ignore")

    for s in sections:
        s["name"] = get_str(shstrtab, s["sh_name"])

    # 3. Locate Symbol Table (.symtab) and String Table (.strtab)
    symtab_sec = next((s for s in sections if s["sh_type"] == 2), None)
    if not symtab_sec:
        print("ERROR: Symbol table not found")
        return 1
    strtab_sec = sections[symtab_sec["sh_link"]]
    strtab_data = obj_data[strtab_sec["sh_offset"]:strtab_sec["sh_offset"] + strtab_sec["sh_size"]]

    symbols = {}
    sym_count = symtab_sec["sh_size"] // 16
    for i in range(sym_count):
        sym_off = symtab_sec["sh_offset"] + i * 16
        st_name, st_value, st_size, st_info, st_other, st_shndx = struct.unpack_from("<IIIBBH", obj_data, sym_off)
        sym_name = get_str(strtab_data, st_name)
        symbols[i] = {
            "name": sym_name,
            "value": st_value,
            "size": st_size,
            "info": st_info,
            "shndx": st_shndx,
        }

    # 4. Locate symbol func_002B9B30
    sym_9b30 = next((s for s in symbols.values() if s["name"] == "func_002B9B30"), None)
    if not sym_9b30:
        print("ERROR: func_002B9B30 symbol not found in object")
        return 1

    print(f"Validated symbol func_002B9B30: section={sym_9b30['shndx']}, size={sym_9b30['size']} bytes (target code is 1576 bytes)")

    # 5. Extract and resolve .text section
    sec_9b30 = sections[sym_9b30["shndx"]]
    bytes_9b30 = bytearray(obj_data[sec_9b30["sh_offset"]:sec_9b30["sh_offset"] + sec_9b30["sh_size"]])

    rel_sec = next((s for s in sections if s["sh_type"] == 9 and s["sh_info"] == sec_9b30["idx"]), None)
    if rel_sec:
        rel_count = rel_sec["sh_size"] // 8
        print(f"Parsing {rel_count} relocations in section {rel_sec['name']}:")
        for i in range(rel_count):
            r_off = rel_sec["sh_offset"] + i * 8
            r_offset, r_info = struct.unpack_from("<II", obj_data, r_off)
            r_type = r_info & 0xFF
            r_sym = r_info >> 8
            sym_name = symbols[r_sym]["name"]

            if r_type == 4: # R_MIPS_26
                if sym_name in SYMBOL_TARGETS:
                    target_addr = SYMBOL_TARGETS[sym_name]
                    jal_opcode = 0x0C000000 | ((target_addr >> 2) & 0x03FFFFFF)
                    struct.pack_into("<I", bytes_9b30, r_offset, jal_opcode)
                    print(f"    -> resolved {sym_name} at 0x{target_addr:X}: opcode {jal_opcode:#010x}")

    # 6. Verify Slice Composition and Alignment
    code_bytes = len(bytes_9b30) + inject_extra_code
    padding_needed = expected_slice_len - code_bytes
    print(f"Code size: {code_bytes} bytes ({len(bytes_9b30)} + {inject_extra_code})")
    print(f"Padding to {expected_slice_len} bytes: {padding_needed} bytes")

    if padding_needed < 0:
        print(f"ERROR: code bytes ({code_bytes}) exceed slice length ({expected_slice_len}), negative padding {padding_needed}")
        return 1

    target_slice = elf_data[0x1B9D10:0x1B9D10 + expected_slice_len]
    if len(target_slice) != expected_slice_len:
        print(f"ERROR: target slice length {len(target_slice)} != {expected_slice_len}")
        return 1

    elf_padding = target_slice[1576:1584] if expected_slice_len == 1584 else b""
    if elf_padding and elf_padding != b"\x00" * len(elf_padding):
        print(f"ERROR: original ELF padding at 0x{0x1B9D10 + 1576:X} contains non-zero bytes: {elf_padding}")
        return 1

    compiled_slice = bytes_9b30 + b"\x00" * padding_needed

    # 7. Byte-for-byte comparison
    diffs = []
    compare_len = min(len(target_slice), len(compiled_slice))
    for i in range(compare_len):
        if target_slice[i] != compiled_slice[i]:
            diffs.append((i, target_slice[i], compiled_slice[i]))

    if diffs or code_bytes != 1576:
        pct = ((compare_len - len(diffs)) / float(expected_slice_len)) * 100.0
        print(f"DIAGNOSTIC: {len(diffs)} byte differences found ({pct:.2f}% byte match, code_size={code_bytes}/1576)")
        for i, t, c in diffs[:10]:
            print(f"  offset +{i:#x}: target={t:#02x} compiled={c:#02x}")
        if len(diffs) > 10:
            print(f"  ... ({len(diffs) - 10} more differences)")
        return 1

    print("SUCCESS: Exact 100.0% byte-for-byte match (1584/1584 bytes identical)!")
    return 0

if __name__ == "__main__":
    sys.exit(verify())
