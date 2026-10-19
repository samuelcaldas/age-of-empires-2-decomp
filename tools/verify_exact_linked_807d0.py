#!/usr/bin/env python3
"""Standalone exact byte equality verifier for Milestone 153 (func_002807D0).

Verifies bit-for-bit byte equality of compiled unit_action_build_807d0.o
against orig/SLES-50282/AOK.ELF at VRAM 0x2807D0 (file offset 0x1809B0).
Resolves all 45 GPREL16 and 22 JAL relocations and validates 16 JALR call sites.
Uses strictly Python 3 standard library (struct, hashlib, sys, pathlib).
"""

import hashlib
import struct
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
ORIG_ELF_PATH = REPO_ROOT / "orig" / "SLES-50282" / "AOK.ELF"
COMPILED_OBJ_PATH = REPO_ROOT / "build" / "SLES-50282" / "src" / "unit_action_build_807d0.o"
SYMBOLS_PATH = REPO_ROOT / "config" / "SLES-50282" / "symbols.txt"

FUNC_VRAM = 0x2807D0
FUNC_FILE_OFFSET = 0x1809B0
FUNC_BYTE_LEN = 2132 # 533 instructions
GP_VALUE = 0x4EA7C0

EXPECTED_GPREL_COUNT = 45
EXPECTED_JAL_COUNT = 22
EXPECTED_JALR_COUNT = 16
EXPECTED_SLICE_SHA1 = "420dcf16176fa46ccf90d1d7fcd7b16eb807254f"

EXPECTED_JALR_OFFSETS = [
    0x12C, 0x188, 0x22C, 0x2B8, 0x344, 0x3A4, 0x40C, 0x4B8,
    0x54C, 0x5E0, 0x640, 0x6B4, 0x708, 0x760, 0x7C0, 0x814
]


def load_symbols_map():
    if not SYMBOLS_PATH.exists():
        raise FileNotFoundError(f"Missing symbols file: {SYMBOLS_PATH}")
    sym_map = {}
    with open(SYMBOLS_PATH, "r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("//"):
                continue
            if "=" in line and ";" in line:
                name_part, rest = line.split("=", 1)
                sym_name = name_part.strip()
                val_part = rest.split(";", 1)[0].strip()
                try:
                    val = int(val_part, 0)
                    sym_map[sym_name] = val
                except ValueError:
                    continue
    return sym_map


def validate_elf_bytes(data):
    if len(data) < 52:
        raise ValueError(f"ELF object header truncated: len={len(data)} < 52")
    if data[:4] != b"\x7fELF":
        raise ValueError("Invalid ELF magic: expected 0x7fELF")
    e_type, e_machine = struct.unpack("<HH", data[16:20])
    if e_type != 1:
        raise ValueError(f"Expected ET_REL (1), got {e_type}")
    if e_machine != 8:
        raise ValueError(f"Expected EM_MIPS (8), got {e_machine}")


def assert_slice_hashes(orig_sha1, resolved_sha1):
    if orig_sha1 != EXPECTED_SLICE_SHA1:
        raise ValueError(
            f"Original slice SHA1 mismatch: got {orig_sha1}, expected {EXPECTED_SLICE_SHA1}"
        )
    if resolved_sha1 != EXPECTED_SLICE_SHA1:
        raise ValueError(
            f"Resolved slice SHA1 mismatch: got {resolved_sha1}, expected {EXPECTED_SLICE_SHA1}"
        )


def assert_relocation_counts(gprel_count, jal_count, jalr_count):
    if gprel_count != EXPECTED_GPREL_COUNT:
        raise ValueError(
            f"GPREL16 count mismatch: got {gprel_count}, expected {EXPECTED_GPREL_COUNT}"
        )
    if jal_count != EXPECTED_JAL_COUNT:
        raise ValueError(
            f"JAL count mismatch: got {jal_count}, expected {EXPECTED_JAL_COUNT}"
        )
    if jalr_count != EXPECTED_JALR_COUNT:
        raise ValueError(
            f"JALR count mismatch: got {jalr_count}, expected {EXPECTED_JALR_COUNT}"
        )


def assert_function_symbol(sym_name, st_value, st_size, st_shndx, text_sec_idx):
    if sym_name not in ["func_002807D0", "func_2807D0"]:
        raise ValueError(f"Unexpected function symbol: {sym_name}")
    if st_value != 0:
        raise ValueError(
            f"Function {sym_name} offset mismatch: expected 0, got {st_value}"
        )
    if st_size != FUNC_BYTE_LEN:
        raise ValueError(
            f"Function {sym_name} size mismatch: expected {FUNC_BYTE_LEN}, got {st_size}"
        )
    if st_shndx != text_sec_idx:
        raise ValueError(
            f"Function {sym_name} section mismatch: expected {text_sec_idx}, got {st_shndx}"
        )


def verify_linked_bytes(symbols_override=None):
    if not ORIG_ELF_PATH.exists():
        raise FileNotFoundError(f"Missing original binary: {ORIG_ELF_PATH}")
    if not COMPILED_OBJ_PATH.exists():
        raise FileNotFoundError(f"Missing compiled object: {COMPILED_OBJ_PATH}")

    with open(ORIG_ELF_PATH, "rb") as f:
        f.seek(FUNC_FILE_OFFSET)
        orig_bytes = f.read(FUNC_BYTE_LEN)
    if len(orig_bytes) != FUNC_BYTE_LEN:
        raise ValueError(f"Could not read {FUNC_BYTE_LEN} bytes from {ORIG_ELF_PATH}")

    with open(COMPILED_OBJ_PATH, "rb") as f:
        obj_bytes = f.read()

    validate_elf_bytes(obj_bytes)

    e_shoff = struct.unpack("<I", obj_bytes[32:36])[0]
    e_shentsize, e_shnum, e_shstrndx = struct.unpack("<HHH", obj_bytes[46:52])
    if e_shentsize < 40:
        raise ValueError(f"Invalid section header entry size: {e_shentsize} < 40")
    if len(obj_bytes) < e_shoff + e_shnum * e_shentsize:
        raise ValueError("Section header table extends beyond file length")

    # Read shstrtab
    shstr_hdr = obj_bytes[e_shoff + e_shstrndx * e_shentsize : e_shoff + (e_shstrndx + 1) * e_shentsize]
    shstr_offset, shstr_size = struct.unpack("<II", shstr_hdr[16:24])
    shstrtab = obj_bytes[shstr_offset : shstr_offset + shstr_size]

    sections = []
    text_sec_idx = None
    rel_text_sec_idx = None
    symtab_sec_idx = None
    strtab_sec_idx = None

    for i in range(e_shnum):
        shdr = obj_bytes[e_shoff + i * e_shentsize : e_shoff + (i + 1) * e_shentsize]
        sh_name, sh_type, sh_flags, sh_addr, sh_offset, sh_size, sh_link, sh_info, sh_addralign, sh_entsize = struct.unpack(
            "<IIIIIIIIII", shdr[:40]
        )
        name = shstrtab[sh_name:].split(b"\x00")[0].decode("latin1")
        sec_info = {
            "idx": i,
            "name": name,
            "type": sh_type,
            "flags": sh_flags,
            "offset": sh_offset,
            "size": sh_size,
            "link": sh_link,
            "info": sh_info,
            "entsize": sh_entsize,
        }
        sections.append(sec_info)
        if name == ".text" and text_sec_idx is None:
            text_sec_idx = i
        elif name == ".rel.text" and rel_text_sec_idx is None:
            rel_text_sec_idx = i
        elif sh_type == 2:  # SHT_SYMTAB
            symtab_sec_idx = i
        elif name == ".strtab":
            strtab_sec_idx = i

    if text_sec_idx is None:
        raise ValueError("Could not find .text section")
    if rel_text_sec_idx is None:
        raise ValueError("Could not find .rel.text section")
    if symtab_sec_idx is None:
        raise ValueError("Could not find .symtab section")
    if strtab_sec_idx is None:
        raise ValueError("Could not find .strtab section")

    # Validate section associations
    rel_sec = sections[rel_text_sec_idx]
    if rel_sec["info"] != text_sec_idx:
        raise ValueError(
            f".rel.text sh_info mismatch: expected {text_sec_idx}, got {rel_sec['info']}"
        )
    if rel_sec["link"] != symtab_sec_idx:
        raise ValueError(
            f".rel.text sh_link mismatch: expected {symtab_sec_idx}, got {rel_sec['link']}"
        )

    # Validate divisibility
    symtab_sec = sections[symtab_sec_idx]
    strtab_sec = sections[strtab_sec_idx]
    if symtab_sec["size"] % 16 != 0:
        raise ValueError(f"Symbol table size not divisible by 16: {symtab_sec['size']}")
    if rel_sec["size"] % 8 != 0:
        raise ValueError(f"Relocation table size not divisible by 8: {rel_sec['size']}")

    # Parse symbols
    strtab = obj_bytes[strtab_sec["offset"] : strtab_sec["offset"] + strtab_sec["size"]]
    symbols = []
    num_symbols = symtab_sec["size"] // 16
    for i in range(num_symbols):
        sym_bytes = obj_bytes[symtab_sec["offset"] + i * 16 : symtab_sec["offset"] + (i + 1) * 16]
        st_name, st_value, st_size, st_info, st_other, st_shndx = struct.unpack("<IIIBBH", sym_bytes)
        sym_name = strtab[st_name:].split(b"\x00")[0].decode("latin1")
        symbols.append({
            "idx": i,
            "name": sym_name,
            "value": st_value,
            "size": st_size,
            "info": st_info,
            "shndx": st_shndx,
        })

    # Validate func_002807D0 symbol
    func_sym = next((s for s in symbols if s["name"] in ["func_002807D0", "func_2807D0"]), None)
    if func_sym is None:
        raise ValueError("func_002807D0 symbol not found in symbol table")
    assert_function_symbol(func_sym["name"], func_sym["value"], func_sym["size"], func_sym["shndx"], text_sec_idx)

    # Load symbols map
    sym_map = symbols_override if symbols_override is not None else load_symbols_map()

    # Read .text code slice
    text_sec = sections[text_sec_idx]
    if text_sec["size"] < FUNC_BYTE_LEN:
        raise ValueError(f".text section too short: {text_sec['size']} < {FUNC_BYTE_LEN}")
    code_slice = bytearray(obj_bytes[text_sec["offset"] : text_sec["offset"] + FUNC_BYTE_LEN])

    # Validate JALRs inside code slice
    jalr_count = 0
    for i in range(0, FUNC_BYTE_LEN, 4):
        w = struct.unpack("<I", code_slice[i : i + 4])[0]
        if w == 0x0220F809:  # jalr $ra, $s1
            if i not in EXPECTED_JALR_OFFSETS:
                raise ValueError(f"Unexpected JALR site at section offset 0x{i:03X}")
            jalr_count += 1

    # Read and resolve relocations
    gprel_count = 0
    jal_count = 0
    num_relocs = rel_sec["size"] // 8

    for i in range(num_relocs):
        rel_bytes = obj_bytes[rel_sec["offset"] + i * 8 : rel_sec["offset"] + (i + 1) * 8]
        r_offset, r_info = struct.unpack("<II", rel_bytes)
        r_sym = r_info >> 8
        r_type = r_info & 0xFF

        if r_offset >= FUNC_BYTE_LEN:
            raise ValueError(f"Out of bounds relocation offset: 0x{r_offset:X} >= 0x{FUNC_BYTE_LEN:X}")
        if r_offset % 4 != 0:
            raise ValueError(f"Unaligned relocation offset: 0x{r_offset:X}")
        if r_sym >= len(symbols):
            raise ValueError(f"Relocation references out-of-range symbol index: {r_sym}")

        target_sym = symbols[r_sym]
        target_name = target_sym["name"]
        call_site_vram = FUNC_VRAM + r_offset

        if r_type == 7:  # R_MIPS_GPREL16
            if target_name not in sym_map:
                raise ValueError(f"Unmapped GPREL16 symbol: {target_name}")
            sym_vram = sym_map[target_name]
            imm = (sym_vram - GP_VALUE) & 0xFFFF
            inst_word = struct.unpack("<I", code_slice[r_offset : r_offset + 4])[0]
            opcode = inst_word >> 26
            if opcode != 35:  # lw
                raise ValueError(f"Expected lw (35) opcode for GPREL16, got {opcode}")
            resolved_word = (inst_word & 0xFFFF0000) | imm
            code_slice[r_offset : r_offset + 4] = struct.pack("<I", resolved_word)
            gprel_count += 1

        elif r_type == 4:  # R_MIPS_26 (JAL)
            if target_name not in sym_map:
                raise ValueError(f"Unmapped JAL symbol: {target_name}")
            sym_vram = sym_map[target_name]
            inst_word = struct.unpack("<I", code_slice[r_offset : r_offset + 4])[0]
            opcode = inst_word >> 26
            if opcode != 3:  # jal
                raise ValueError(f"Expected jal (3) opcode for R_MIPS_26, got {opcode}")
            if (sym_vram & 0xF0000000) != ((call_site_vram + 4) & 0xF0000000):
                raise ValueError(f"JAL target 0x{sym_vram:X} outside 256MB region of site 0x{call_site_vram:X}")
            resolved_word = (3 << 26) | ((sym_vram >> 2) & 0x03FFFFFF)
            code_slice[r_offset : r_offset + 4] = struct.pack("<I", resolved_word)
            jal_count += 1

        else:
            raise ValueError(f"Unsupported relocation type {r_type} at offset 0x{r_offset:X}")

    assert_relocation_counts(gprel_count, jal_count, jalr_count)

    orig_sha1 = hashlib.sha1(orig_bytes).hexdigest()
    resolved_sha1 = hashlib.sha1(code_slice).hexdigest()
    assert_slice_hashes(orig_sha1, resolved_sha1)

    diffs = []
    for i in range(0, FUNC_BYTE_LEN, 4):
        wo = struct.unpack("<I", orig_bytes[i : i + 4])[0]
        wr = struct.unpack("<I", code_slice[i : i + 4])[0]
        if wo != wr:
            diffs.append((i, wo, wr))

    if diffs:
        msg = f"Byte mismatch: {len(diffs)} word differences after relocation resolution:\n"
        for off, wo, wr in diffs[:10]:
            msg += f"  Offset 0x{off:03X} (VRAM 0x{FUNC_VRAM+off:06X}): orig=0x{wo:08X}, resolved=0x{wr:08X}\n"
        raise ValueError(msg)

    print(f"=== Milestone 153 (func_002807D0) Relocation-Resolved Byte Equality Verification ===")
    print(f"Target ELF:              {ORIG_ELF_PATH.relative_to(REPO_ROOT)}")
    print(f"File Offset:             0x{FUNC_FILE_OFFSET:06X} (VRAM 0x{FUNC_VRAM:06X})")
    print(f"Length:                  {FUNC_BYTE_LEN} bytes ({FUNC_BYTE_LEN//4} instructions)")
    print(f"Symbol {func_sym['name']}:  validated at .text offset 0, size {FUNC_BYTE_LEN}")
    print(f"Original ELF slice SHA1: {orig_sha1} (enforced exact: {EXPECTED_SLICE_SHA1})")
    print(f"Resolved code slice SHA1:{resolved_sha1} (enforced exact: {EXPECTED_SLICE_SHA1})")
    print(f"GPREL16 resolved sites:  {gprel_count} (enforced exact: {EXPECTED_GPREL_COUNT})")
    print(f"JAL resolved sites:      {jal_count} (enforced exact: {EXPECTED_JAL_COUNT})")
    print(f"JALR call sites:         {jalr_count} (enforced exact: {EXPECTED_JALR_COUNT})")
    print(f"\nRESULT: EXACT MATCH! {FUNC_BYTE_LEN} / {FUNC_BYTE_LEN} bytes identical (100.00% byte equality).")
    print(f"All {FUNC_BYTE_LEN//4} instructions match bit-for-bit against {ORIG_ELF_PATH.relative_to(REPO_ROOT)}.")


if __name__ == "__main__":
    try:
        verify_linked_bytes()
    except Exception as e:
        print(f"Verification FAILED: {e}", file=sys.stderr)
        sys.exit(1)
