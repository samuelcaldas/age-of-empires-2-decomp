#!/usr/bin/env python3
"""Robust ELF relocation and section parser for post_trade_action_distance_candidates (0x2B8E30–0x2B90A0)."""

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

SRC_PATH = PROJECT_ROOT / "src" / "post_trade_action_distance_candidates.cpp"
INC_PATH = PROJECT_ROOT / "include"

SYMBOL_TARGETS = {
    "func_332e60": 0x332E60,
    "func_00147170": 0x147170,
    "func_00269190": 0x269190,
}

def verify(expected_slice_len=624, elf_override_bytes=None, inject_extra_code=0):
    if (not elf_override_bytes) and (not ELF_PATH or not ELF_PATH.exists()):
        print(f"ERROR: Original ELF not found at {ELF_PATH}")
        return 1
    if not COMPILER or not COMPILER.exists():
        print(f"ERROR: MWCC compiler not found at {COMPILER}")
        return 1
    if not WIBO or not WIBO.exists():
        print(f"ERROR: wibo executable not found at {WIBO}")
        return 1
    if not READELF:
        print(f"ERROR: readelf executable not found")
        return 1

    obj_path = Path("/tmp/post_trade_action_distance_candidates_verify.o")

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

    # 4. Validate symbol bounds for func_002B8E30
    sym_8e30 = next((s for s in symbols.values() if s["name"] == "func_002B8E30"), None)
    if not sym_8e30 or sym_8e30["size"] != 616:
        print(f"ERROR: func_002B8E30 size mismatch: {sym_8e30}")
        return 1

    print(f"Validated symbol func_002B8E30: section={sym_8e30['shndx']}, size={sym_8e30['size']} bytes")

    # 5. Extract and resolve .text section
    sec_8e30 = sections[sym_8e30["shndx"]]
    bytes_8e30 = bytearray(obj_data[sec_8e30["sh_offset"]:sec_8e30["sh_offset"] + sec_8e30["sh_size"]])

    rel_sec = next((s for s in sections if s["sh_type"] == 9 and s["sh_info"] == sec_8e30["idx"]), None)
    if not rel_sec:
        print("ERROR: Relocation section for func_002B8E30 not found")
        return 1

    rel_count = rel_sec["sh_size"] // 8
    print(f"Parsing {rel_count} relocations in section {rel_sec['name']}:")
    for i in range(rel_count):
        r_off = rel_sec["sh_offset"] + i * 8
        r_offset, r_info = struct.unpack_from("<II", obj_data, r_off)
        r_type = r_info & 0xFF
        r_sym = r_info >> 8
        sym_name = symbols[r_sym]["name"]
        print(f"  Relocation [{i}]: offset={r_offset:#x}, type={r_type} (R_MIPS_26), target={sym_name}")

        if r_type != 4:
            print(f"ERROR: unexpected relocation type {r_type}")
            return 1

        if sym_name not in SYMBOL_TARGETS:
            print(f"ERROR: target address for symbol {sym_name} unknown")
            return 1

        target_addr = SYMBOL_TARGETS[sym_name]
        jal_opcode = 0x0C000000 | ((target_addr >> 2) & 0x03FFFFFF)
        struct.pack_into("<I", bytes_8e30, r_offset, jal_opcode)
        print(f"    -> resolved {sym_name} at 0x{target_addr:X}: opcode {jal_opcode:#010x}")

    # 6. Verify Slice Composition and Alignment
    code_bytes = len(bytes_8e30) + inject_extra_code
    padding_needed = expected_slice_len - code_bytes
    print(f"Code size: {code_bytes} bytes ({len(bytes_8e30)} + {inject_extra_code})")
    print(f"Padding to {expected_slice_len} bytes: {padding_needed} bytes")

    if padding_needed < 0:
        print(f"ERROR: code bytes ({code_bytes}) exceed slice length ({expected_slice_len}), negative padding {padding_needed}")
        return 1

    target_slice = elf_data[0x1B9010:0x1B9010 + expected_slice_len]
    if len(target_slice) != expected_slice_len:
        print(f"ERROR: target slice length {len(target_slice)} != {expected_slice_len}")
        return 1

    elf_padding = target_slice[code_bytes:expected_slice_len]
    if elf_padding != b"\x00" * padding_needed:
        print(f"ERROR: original ELF padding at 0x{0x1B9010 + code_bytes:X} contains non-zero bytes: {elf_padding}")
        return 1

    compiled_slice = bytes_8e30 + b"\x00" * padding_needed

    if len(compiled_slice) != expected_slice_len:
        print(f"ERROR: compiled slice length {len(compiled_slice)} != {expected_slice_len}")
        return 1

    # 7. Byte-for-byte comparison
    diffs = []
    for i in range(expected_slice_len):
        if target_slice[i] != compiled_slice[i]:
            diffs.append((i, target_slice[i], compiled_slice[i]))

    if diffs:
        print(f"FAILED: {len(diffs)} byte differences found:")
        for i, t, c in diffs:
            print(f"  offset +{i:#x}: target={t:#02x} compiled={c:#02x}")
        return 1

    print("SUCCESS: Exact 100.0% byte-for-byte match (624/624 bytes identical)!")
    return 0

if __name__ == "__main__":
    sys.exit(verify())
