#!/usr/bin/env python3
"""Standalone exact byte equality verifier for Milestone 156 (func_00281A80).

Verifies bit-for-bit byte equality of compiled unit_action_build_81a80.o
against orig/SLES-50282/AOK.ELF at VRAM 0x281A80 (file offset 0x181C60).
Enforces exact per-site relocation manifest, per-symbol counts, opcodes, addends,
and validates the 8-byte func_281A80 leaf tail-call alias.
Uses strictly Python 3 standard library (struct, hashlib, sys, pathlib).
"""

import hashlib
import struct
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
ORIG_ELF_PATH = REPO_ROOT / "orig" / "SLES-50282" / "AOK.ELF"
COMPILED_OBJ_PATH = REPO_ROOT / "build" / "SLES-50282" / "src" / "unit_action_build_81a80.o"
SYMBOLS_PATH = REPO_ROOT / "config" / "SLES-50282" / "symbols.txt"

FUNC_VRAM = 0x281A80
FUNC_FILE_OFFSET = 0x181C60
FUNC_BYTE_LEN = 8  # 2 instructions
GP_VALUE = 0x4EA7C0

EXPECTED_GPREL_COUNT = 1
EXPECTED_JAL_COUNT = 1
EXPECTED_TOTAL_RELOCS = 2
EXPECTED_SLICE_SHA1 = "84c86b068b5a6fda1b90c6f75d9fc307afeaecde"

EXPECTED_PER_SYMBOL_COUNTS = {
    "D_4E342C": 1,
    "func_002BFA60": 1,
}

EXPECTED_RELOCATIONS = {
    0x00: (4, "func_002BFA60", 0),
    0x04: (7, "D_4E342C", 0),
}


def load_symbols_map():
    if not SYMBOLS_PATH.exists():
        raise FileNotFoundError(f"Missing symbols file: {SYMBOLS_PATH}")
    sym_map = {
        "D_4E342C": 0x4E342C,
        "D_004E342C": 0x4E342C,
        "func_002BFA60": 0x2BFA60,
        "func_2BFA60": 0x2BFA60,
        "func_00281A80": 0x281A80,
        "func_281A80": 0x281A80,
    }
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


def assert_relocation_counts(gprel_count, jal_count):
    if gprel_count != EXPECTED_GPREL_COUNT:
        raise ValueError(
            f"GPREL16 count mismatch: got {gprel_count}, expected {EXPECTED_GPREL_COUNT}"
        )
    if jal_count != EXPECTED_JAL_COUNT:
        raise ValueError(
            f"JAL/J count mismatch: got {jal_count}, expected {EXPECTED_JAL_COUNT}"
        )


def assert_per_symbol_counts(counts_dict):
    for sym, expected_count in EXPECTED_PER_SYMBOL_COUNTS.items():
        actual_count = counts_dict.get(sym, 0)
        if actual_count != expected_count:
            raise ValueError(
                f"Per-symbol count mismatch for {sym}: expected {expected_count}, got {actual_count}"
            )


def assert_relocation_site(r_offset, r_type, target_name):
    if r_offset not in EXPECTED_RELOCATIONS:
        raise ValueError(f"Unexpected relocation at offset 0x{r_offset:03X} (symbol {target_name})")
    expected_type, expected_name, _ = EXPECTED_RELOCATIONS[r_offset]
    if r_type != expected_type:
        raise ValueError(
            f"Relocation type mismatch at 0x{r_offset:03X}: expected {expected_type}, got {r_type}"
        )
    if target_name != expected_name:
        raise ValueError(
            f"Relocation symbol mismatch at 0x{r_offset:03X}: expected {expected_name}, got {target_name}"
        )


def assert_relocation_addend(r_type, sym_vram, expected_addend, unlinked_word, resolved_word):
    if r_type == 7:  # R_MIPS_GPREL16
        unlinked_addend = unlinked_word & 0xFFFF
        if unlinked_addend != expected_addend:
            raise ValueError(f"Unexpected unlinked GPREL16 addend: 0x{unlinked_addend:04X} != 0x{expected_addend:04X}")
        expected_imm = (sym_vram + expected_addend - GP_VALUE) & 0xFFFF
        resolved_imm = resolved_word & 0xFFFF
        if resolved_imm != expected_imm:
            raise ValueError(
                f"Resolved GPREL16 addend mismatch: expected 0x{expected_imm:04X}, got 0x{resolved_imm:04X}"
            )
    elif r_type == 4:  # R_MIPS_26
        unlinked_target = unlinked_word & 0x03FFFFFF
        if unlinked_target != 0:
            raise ValueError(f"Non-zero unlinked J target field: 0x{unlinked_target:07X}")
        expected_target = (sym_vram >> 2) & 0x03FFFFFF
        resolved_target = resolved_word & 0x03FFFFFF
        if resolved_target != expected_target:
            raise ValueError(
                f"Resolved J target mismatch: expected 0x{expected_target:07X}, got 0x{resolved_target:07X}"
            )


def assert_alias_symbol_and_code(symbols, sections, obj_bytes, sym_map):
    alias_sym = next((s for s in symbols if s["name"] == "func_281A80"), None)
    if alias_sym is None:
        raise ValueError("func_281A80 alias symbol not found in symbol table")
    if alias_sym["value"] != 0:
        raise ValueError(f"func_281A80 alias value mismatch: expected 0, got {alias_sym['value']}")
    if alias_sym["size"] != 8:
        raise ValueError(f"func_281A80 alias size mismatch: expected 8, got {alias_sym['size']}")

    alias_shndx = alias_sym["shndx"]
    alias_sec = sections[alias_shndx]
    if alias_sec["name"] != ".text":
        raise ValueError(f"func_281A80 alias section name mismatch: expected .text, got {alias_sec['name']}")
    if alias_sec["size"] != 8:
        raise ValueError(f"func_281A80 alias section size mismatch: expected 8, got {alias_sec['size']}")

    rel_alias_sec = next((s for s in sections if s and s.get("name") == ".rel.text" and s.get("info") == alias_shndx), None)
    if rel_alias_sec is None:
        raise ValueError(f"Missing .rel.text section for alias section {alias_shndx}")
    if rel_alias_sec["size"] != 8:
        raise ValueError(f"Alias relocation table size mismatch: expected 8, got {rel_alias_sec['size']}")

    rel_bytes = obj_bytes[rel_alias_sec["offset"] : rel_alias_sec["offset"] + 8]
    r_offset, r_info = struct.unpack("<II", rel_bytes)
    r_sym = r_info >> 8
    r_type = r_info & 0xFF
    if r_offset != 0:
        raise ValueError(f"Alias relocation offset mismatch: expected 0, got {r_offset}")
    if r_type != 4:
        raise ValueError(f"Alias relocation type mismatch: expected 4 (R_MIPS_26), got {r_type}")

    target_sym = symbols[r_sym]
    if target_sym["name"] != "func_00281A80":
        raise ValueError(f"Alias relocation target mismatch: expected func_00281A80, got {target_sym['name']}")

    alias_code = bytearray(obj_bytes[alias_sec["offset"] : alias_sec["offset"] + 8])
    w0_unlinked = struct.unpack("<I", alias_code[0:4])[0]
    w1_unlinked = struct.unpack("<I", alias_code[4:8])[0]
    if w0_unlinked != 0x08000000:
        raise ValueError(f"Alias unlinked word 0 mismatch: expected 0x08000000 (j), got 0x{w0_unlinked:08X}")
    if w1_unlinked != 0x00000000:
        raise ValueError(f"Alias unlinked word 1 mismatch: expected 0x00000000 (nop), got 0x{w1_unlinked:08X}")

    target_vram = sym_map["func_00281A80"]
    expected_w0_resolved = (2 << 26) | ((target_vram >> 2) & 0x03FFFFFF)
    if expected_w0_resolved != 0x080A06A0:
        raise ValueError(f"Unexpected resolved alias target: expected 0x080A06A0, got 0x{expected_w0_resolved:08X}")


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

    rel_sec = sections[rel_text_sec_idx]
    if rel_sec["info"] != text_sec_idx:
        raise ValueError(
            f".rel.text sh_info mismatch: expected {text_sec_idx}, got {rel_sec['info']}"
        )
    if rel_sec["link"] != symtab_sec_idx:
        raise ValueError(
            f".rel.text sh_link mismatch: expected {symtab_sec_idx}, got {rel_sec['link']}"
        )

    symtab_sec = sections[symtab_sec_idx]
    strtab_sec = sections[strtab_sec_idx]
    if symtab_sec["size"] % 16 != 0:
        raise ValueError(f"Symbol table size not divisible by 16: {symtab_sec['size']}")
    if rel_sec["size"] % 8 != 0:
        raise ValueError(f"Relocation table size not divisible by 8: {rel_sec['size']}")

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

    func_sym = next((s for s in symbols if s["name"] == "func_00281A80"), None)
    if func_sym is None:
        raise ValueError("func_00281A80 symbol not found in symbol table")
    if func_sym["value"] != 0:
        raise ValueError(f"Function {func_sym['name']} offset mismatch: expected 0, got {func_sym['value']}")
    if func_sym["size"] != FUNC_BYTE_LEN:
        raise ValueError(f"Function {func_sym['name']} size mismatch: expected {FUNC_BYTE_LEN}, got {func_sym['size']}")
    if func_sym["shndx"] != text_sec_idx:
        raise ValueError(f"Function {func_sym['name']} section mismatch: expected {text_sec_idx}, got {func_sym['shndx']}")

    sym_map = symbols_override if symbols_override is not None else load_symbols_map()

    assert_alias_symbol_and_code(symbols, sections, obj_bytes, sym_map)

    text_sec = sections[text_sec_idx]
    if text_sec["size"] < FUNC_BYTE_LEN:
        raise ValueError(f".text section too short: {text_sec['size']} < {FUNC_BYTE_LEN}")
    code_slice = bytearray(obj_bytes[text_sec["offset"] : text_sec["offset"] + FUNC_BYTE_LEN])

    gprel_count = 0
    jal_count = 0
    per_sym_counts = {}
    visited_offsets = set()
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

        assert_relocation_site(r_offset, r_type, target_name)
        visited_offsets.add(r_offset)

        if target_name not in per_sym_counts:
            per_sym_counts[target_name] = 0
        per_sym_counts[target_name] += 1

        unlinked_word = struct.unpack("<I", code_slice[r_offset : r_offset + 4])[0]
        _, _, expected_addend = EXPECTED_RELOCATIONS[r_offset]

        if target_name not in sym_map:
            raise ValueError(f"Unmapped relocation symbol: {target_name}")
        sym_vram = sym_map[target_name]

        if r_type == 7:  # R_MIPS_GPREL16
            imm = (sym_vram + expected_addend - GP_VALUE) & 0xFFFF
            opcode = unlinked_word >> 26
            if opcode != 35:  # lw
                raise ValueError(f"Expected lw (35) opcode for GPREL16, got {opcode}")
            resolved_word = (unlinked_word & 0xFFFF0000) | imm
            assert_relocation_addend(r_type, sym_vram, expected_addend, unlinked_word, resolved_word)
            code_slice[r_offset : r_offset + 4] = struct.pack("<I", resolved_word)
            gprel_count += 1

        elif r_type == 4:  # R_MIPS_26 (J)
            opcode = unlinked_word >> 26
            if opcode != 2:  # j
                raise ValueError(f"Expected j (2) opcode for R_MIPS_26, got {opcode}")
            if (sym_vram & 0xF0000000) != ((call_site_vram + 4) & 0xF0000000):
                raise ValueError(f"J target 0x{sym_vram:X} outside 256MB region of site 0x{call_site_vram:X}")
            resolved_word = (2 << 26) | ((sym_vram >> 2) & 0x03FFFFFF)
            assert_relocation_addend(r_type, sym_vram, expected_addend, unlinked_word, resolved_word)
            code_slice[r_offset : r_offset + 4] = struct.pack("<I", resolved_word)
            jal_count += 1

        else:
            raise ValueError(f"Unsupported relocation type {r_type} at offset 0x{r_offset:X}")

    assert_relocation_counts(gprel_count, jal_count)
    assert_per_symbol_counts(per_sym_counts)

    if visited_offsets != set(EXPECTED_RELOCATIONS.keys()):
        missing = set(EXPECTED_RELOCATIONS.keys()) - visited_offsets
        raise ValueError(f"Missing expected relocation sites: {[hex(x) for x in missing]}")

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

    print(f"=== Milestone 156 (func_00281A80) Relocation-Resolved Byte Equality Verification ===")
    print(f"Target ELF:              {ORIG_ELF_PATH.relative_to(REPO_ROOT)}")
    print(f"File Offset:             0x{FUNC_FILE_OFFSET:06X} (VRAM 0x{FUNC_VRAM:06X})")
    print(f"Length:                  {FUNC_BYTE_LEN} bytes ({FUNC_BYTE_LEN//4} instructions)")
    print(f"Symbol {func_sym['name']}:  validated at .text offset 0, size {FUNC_BYTE_LEN}")
    print(f"Alias func_281A80:       validated at homonymous .text section, size 8, j func_00281A80")
    print(f"Original ELF slice SHA1: {orig_sha1} (enforced exact: {EXPECTED_SLICE_SHA1})")
    print(f"Resolved code slice SHA1:{resolved_sha1} (enforced exact: {EXPECTED_SLICE_SHA1})")
    print(f"GPREL16 resolved sites:  {gprel_count} (enforced exact: {EXPECTED_GPREL_COUNT})")
    print(f"  - D_4E342C:            {per_sym_counts['D_4E342C']} (enforced exact: 1)")
    print(f"J resolved sites:        {jal_count} (enforced exact: {EXPECTED_JAL_COUNT})")
    print(f"  - func_002BFA60:       {per_sym_counts['func_002BFA60']} (enforced exact: 1)")
    print(f"\nRESULT: EXACT MATCH! {FUNC_BYTE_LEN} / {FUNC_BYTE_LEN} bytes identical (100.00% byte equality).")
    print(f"All {FUNC_BYTE_LEN//4} instructions match bit-for-bit against {ORIG_ELF_PATH.relative_to(REPO_ROOT)}.")


if __name__ == "__main__":
    try:
        verify_linked_bytes()
    except Exception as e:
        print(f"Verification FAILED: {e}", file=sys.stderr)
        sys.exit(1)
