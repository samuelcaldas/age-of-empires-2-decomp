#!/usr/bin/env python3
"""
Stand-alone verification script for Milestone 150 (func_00280670).
Uses ONLY standard library (struct, hashlib). No pyelftools or external deps required.
"""
import hashlib
import struct
import sys

EXPECTED_RELOC_COUNT = 0
EXPECTED_SLICE_SHA1 = "dc1d3b01ab39f0712b323222c1b4832039664e82"


def assert_relocation_counts(reloc_count):
    """Enforce exact relocation counts (0 relocations for leaf function)."""
    if reloc_count != EXPECTED_RELOC_COUNT:
        raise ValueError(
            f"Relocation count mismatch: got {reloc_count}, expected exact {EXPECTED_RELOC_COUNT}"
        )


def assert_slice_hashes(orig_sha1, resolved_sha1):
    """Enforce that both original binary slice and resolved slice match pinned SHA1."""
    if orig_sha1 != EXPECTED_SLICE_SHA1:
        raise ValueError(
            f"Original slice SHA1 mismatch: got {orig_sha1}, expected {EXPECTED_SLICE_SHA1}"
        )
    if resolved_sha1 != EXPECTED_SLICE_SHA1:
        raise ValueError(
            f"Resolved slice SHA1 mismatch: got {resolved_sha1}, expected {EXPECTED_SLICE_SHA1}"
        )


def validate_elf_bytes(data):
    """Validate ELF32 structure, magic, section entry size, and header bounds."""
    if len(data) < 52:
        raise ValueError(f"Invalid ELF: file size ({len(data)} bytes) smaller than ELF32 header (52 bytes)")
    if data[:4] != b'\x7fELF':
        raise ValueError(f"Invalid ELF magic: {data[:4]!r}")
    if data[4] != 1:  # ELFCLASS32
        raise ValueError(f"Invalid ELF class: {data[4]}, expected ELFCLASS32 (1)")
    if data[5] != 1:  # ELFDATA2LSB (little-endian)
        raise ValueError(f"Invalid ELF endianness: {data[5]}, expected 2LSB (1)")

    e_shoff = struct.unpack_from('<I', data, 0x20)[0]
    e_shentsize = struct.unpack_from('<H', data, 0x2e)[0]
    e_shnum = struct.unpack_from('<H', data, 0x30)[0]
    e_shstrndx = struct.unpack_from('<H', data, 0x32)[0]

    if e_shentsize < 40:
        raise ValueError(f"Invalid section header entry size: {e_shentsize}, expected at least 40")
    if e_shnum == 0:
        raise ValueError("Invalid ELF: zero section headers")
    if e_shoff + e_shnum * e_shentsize > len(data):
        raise ValueError(
            f"Section header table extends beyond file: offset={e_shoff}, size={e_shnum * e_shentsize}, file_size={len(data)}"
        )
    if e_shstrndx >= e_shnum:
        raise ValueError(
            f"Invalid section name string table index: {e_shstrndx} >= {e_shnum}"
        )


def parse_elf_sections_from_bytes(data):
    """Parse sections from in-memory ELF bytearray."""
    validate_elf_bytes(data)

    e_shoff = struct.unpack_from('<I', data, 0x20)[0]
    e_shentsize = struct.unpack_from('<H', data, 0x2e)[0]
    e_shnum = struct.unpack_from('<H', data, 0x30)[0]
    e_shstrndx = struct.unpack_from('<H', data, 0x32)[0]

    sections = []
    for i in range(e_shnum):
        off = e_shoff + i * e_shentsize
        sh_name, sh_type, sh_flags, sh_addr, sh_offset, sh_size, sh_link, sh_info, sh_addralign, sh_entsize = \
            struct.unpack_from('<10I', data, off)

        if sh_type != 0 and sh_offset + sh_size > len(data):
            raise ValueError(
                f"Section {i} extends beyond file bounds: offset={sh_offset}, size={sh_size}, file_size={len(data)}"
            )

        sections.append({
            'name_idx': sh_name,
            'type': sh_type,
            'offset': sh_offset,
            'size': sh_size,
            'link': sh_link,
            'info': sh_info,
            'entsize': sh_entsize,
        })

    shstr = sections[e_shstrndx]
    shstr_off = shstr['offset']
    shstr_size = shstr['size']

    def get_str(strtab_off, strtab_size, idx):
        start = strtab_off + idx
        if start >= strtab_off + strtab_size:
            raise ValueError(f"String index {idx} out of string table bounds (size {strtab_size})")
        end = data.find(b'\x00', start, strtab_off + strtab_size)
        if end == -1:
            raise ValueError(f"Unterminated string in string table at offset {start}")
        return data[start:end].decode('latin1')

    sec_by_name = {}
    for i, s in enumerate(sections):
        s['name'] = get_str(shstr_off, shstr_size, s['name_idx'])
        sec_by_name[s['name']] = s

    if '.text' not in sec_by_name:
        raise ValueError("Missing required section .text in ELF")

    return data, sec_by_name


def parse_elf_sections(path):
    with open(path, 'rb') as f:
        data = f.read()
    return parse_elf_sections_from_bytes(data)


def verify_linked_bytes(src_obj_path='build/SLES-50282/src/unit_action_build_80670.o',
                        orig_elf_path='orig/SLES-50282/AOK.ELF',
                        orig_file_offset=0x180850,
                        func_size=8):
    """
    Perform byte equality verification for func_00280670 (8 bytes, 0 relocations).
    Returns (orig_sha1, resolved_sha1, reloc_count).
    Raises ValueError on any discrepancy.
    """
    # 1. Read original binary slice
    with open(orig_elf_path, 'rb') as f:
        f.seek(orig_file_offset)
        orig_bytes = f.read(func_size)
    if len(orig_bytes) != func_size:
        raise ValueError(f"Truncated read from {orig_elf_path}: got {len(orig_bytes)}, expected {func_size}")
    orig_sha1 = hashlib.sha1(orig_bytes).hexdigest()

    # 2. Parse compiled ET_REL object
    raw_obj, secs = parse_elf_sections(src_obj_path)
    text_sec = secs['.text']

    if text_sec['size'] < func_size:
        raise ValueError(f".text section size ({text_sec['size']}) smaller than function size ({func_size})")

    # Read .text bytes
    compiled_bytes = bytearray(raw_obj[text_sec['offset']:text_sec['offset'] + func_size])

    # Check relocations
    reloc_count = 0
    if '.rel.text' in secs:
        rel_text_sec = secs['.rel.text']
        rel_entsize = rel_text_sec['entsize'] if rel_text_sec['entsize'] >= 8 else 8
        count = rel_text_sec['size'] // rel_entsize
        for i in range(count):
            off = rel_text_sec['offset'] + i * rel_entsize
            r_offset = struct.unpack_from('<I', raw_obj, off)[0]
            if r_offset < func_size:
                reloc_count += 1

    assert_relocation_counts(reloc_count)

    resolved_bytes = bytes(compiled_bytes)
    resolved_sha1 = hashlib.sha1(resolved_bytes).hexdigest()

    assert_slice_hashes(orig_sha1, resolved_sha1)

    mismatches = []
    for idx in range(func_size):
        if orig_bytes[idx] != resolved_bytes[idx]:
            mismatches.append(idx)

    if mismatches:
        raise ValueError(f"Byte mismatch at {len(mismatches)} positions! First at {mismatches[0]:#06x}")

    return orig_sha1, resolved_sha1, reloc_count


def main():
    src_obj_path = 'build/SLES-50282/src/unit_action_build_80670.o'
    orig_elf_path = 'orig/SLES-50282/AOK.ELF'
    orig_file_offset = 0x180850
    func_size = 8  # 2 instructions

    try:
        orig_sha1, resolved_sha1, reloc_count = verify_linked_bytes(
            src_obj_path=src_obj_path,
            orig_elf_path=orig_elf_path,
            orig_file_offset=orig_file_offset,
            func_size=func_size
        )
    except ValueError as err:
        print(f"VERIFICATION FAILURE: {err}", file=sys.stderr)
        sys.exit(1)

    print("=== Milestone 150 (func_00280670) Relocation-Resolved Byte Equality Verification ===")
    print(f"Target ELF:              {orig_elf_path}")
    print(f"File Offset:             {orig_file_offset:#08x} (VRAM 0x280670)")
    print(f"Length:                  {func_size} bytes ({func_size // 4} instructions)")
    print(f"Original ELF slice SHA1: {orig_sha1} (enforced exact: {EXPECTED_SLICE_SHA1})")
    print(f"Resolved code slice SHA1:{resolved_sha1} (enforced exact: {EXPECTED_SLICE_SHA1})")
    print(f"Relocations:             {reloc_count} (enforced exact: {EXPECTED_RELOC_COUNT})")
    print()
    print("RESULT: EXACT MATCH! 8 / 8 bytes identical (100.00% byte equality).")
    print("All 2 instructions match bit-for-bit against orig/SLES-50282/AOK.ELF.")
    sys.exit(0)


if __name__ == '__main__':
    main()
