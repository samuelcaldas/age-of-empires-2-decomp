#!/usr/bin/env python3
"""
Stand-alone verification script for Milestone 148 (func_0027F890).
Uses ONLY standard library (struct, hashlib). No pyelftools or external deps required.
"""
import hashlib
import struct
import sys

EXPECTED_GPREL_COUNT = 49
EXPECTED_JAL_COUNT = 51

GP_VAL = 0x4EA7C0
D_4E35DC_VAL = 0x4E35DC
GPREL_ADDEND = (D_4E35DC_VAL - GP_VAL) & 0xFFFF  # -0x71E4 = 0x8E1C


def assert_relocation_counts(gprel_count, jal_count):
    """Enforce exact relocation counts; raises ValueError if any count differs."""
    if gprel_count != EXPECTED_GPREL_COUNT:
        raise ValueError(
            f"GPREL16 relocation count mismatch: got {gprel_count}, expected exact {EXPECTED_GPREL_COUNT}"
        )
    if jal_count != EXPECTED_JAL_COUNT:
        raise ValueError(
            f"JAL relocation count mismatch: got {jal_count}, expected exact {EXPECTED_JAL_COUNT}"
        )


def validate_and_apply_relocation(r_offset, r_type, sym_name, compiled_bytes):
    """
    Validate relocation type, site opcode, registers, in-situ addend/target,
    and apply resolved value. Raises ValueError on any unexpected property.
    """
    if r_type == 7:  # R_MIPS_GPREL16
        if sym_name != "D_4E35DC":
            raise ValueError(
                f"Unexpected GPREL16 symbol at {r_offset:#06x}: got {sym_name}, expected D_4E35DC"
            )
        w = struct.unpack_from('<I', compiled_bytes, r_offset)[0]
        # Must be addiu $a0, $gp, 0 (0x27840000)
        if (w & 0xFFFF0000) != 0x27840000:
            raise ValueError(
                f"Invalid opcode/register at GPREL16 site {r_offset:#06x}: got {w:#010x}, expected addiu $a0, $gp, 0 (0x27840000)"
            )
        # In-situ addend must be zero
        in_situ_addend = w & 0xFFFF
        if in_situ_addend != 0:
            raise ValueError(
                f"Non-zero in-situ addend at GPREL16 site {r_offset:#06x}: got {in_situ_addend:#06x}, expected 0x0"
            )
        # Apply addend
        w_applied = (w & 0xFFFF0000) | GPREL_ADDEND
        struct.pack_into('<I', compiled_bytes, r_offset, w_applied)
        return "GPREL16"

    elif r_type == 4:  # R_MIPS_26
        if not sym_name.startswith("func_"):
            raise ValueError(
                f"Unexpected JAL symbol at {r_offset:#06x}: got {sym_name}, expected func_XXXXXX"
            )
        w = struct.unpack_from('<I', compiled_bytes, r_offset)[0]
        # Must be jal opcode (op=3, 0x0C000000)
        op = (w >> 26) & 0x3F
        if op != 3:
            raise ValueError(
                f"Invalid opcode at JAL site {r_offset:#06x}: got {w:#010x} (op={op}), expected jal (op=3)"
            )
        # In-situ target field must be zero
        in_situ_target = w & 0x03FFFFFF
        if in_situ_target != 0:
            raise ValueError(
                f"Non-zero in-situ target field at JAL site {r_offset:#06x}: got {in_situ_target:#010x}, expected 0x0"
            )
        # Apply target address derived from symbol name
        target_addr = int(sym_name.split('_')[1], 16)
        jal_target_field = (target_addr >> 2) & 0x03FFFFFF
        w_applied = 0x0C000000 | jal_target_field
        struct.pack_into('<I', compiled_bytes, r_offset, w_applied)
        return "JAL"

    else:
        raise ValueError(
            f"Unsupported in-range relocation type {r_type} at offset {r_offset:#06x}"
        )


def parse_elf_sections(path):
    with open(path, 'rb') as f:
        data = f.read()

    # ELF32 header
    magic = data[:4]
    assert magic == b'\x7fELF', f"Not an ELF file: {path}"
    e_shoff = struct.unpack_from('<I', data, 0x20)[0]
    e_shentsize = struct.unpack_from('<H', data, 0x2e)[0]
    e_shnum = struct.unpack_from('<H', data, 0x30)[0]
    e_shstrndx = struct.unpack_from('<H', data, 0x32)[0]

    # Section headers
    sections = []
    for i in range(e_shnum):
        off = e_shoff + i * e_shentsize
        sh_name, sh_type, sh_flags, sh_addr, sh_offset, sh_size, sh_link, sh_info, sh_addralign, sh_entsize = \
            struct.unpack_from('<10I', data, off)
        sections.append({
            'name_idx': sh_name,
            'type': sh_type,
            'offset': sh_offset,
            'size': sh_size,
            'link': sh_link,
            'info': sh_info,
            'entsize': sh_entsize,
        })

    # Section names
    shstr_off = sections[e_shstrndx]['offset']
    def get_str(strtab_off, idx):
        end = data.find(b'\x00', strtab_off + idx)
        return data[strtab_off + idx:end].decode('latin1')

    sec_by_name = {}
    for s in sections:
        s['name'] = get_str(shstr_off, s['name_idx'])
        sec_by_name[s['name']] = s

    return data, sec_by_name, lambda idx: get_str(sections[sec_by_name['.symtab']['link']]['offset'], idx)


def main():
    src_obj_path = 'build/SLES-50282/src/unit_action_build_7f890.o'
    orig_elf_path = 'orig/SLES-50282/AOK.ELF'
    orig_file_offset = 0x17FA70
    func_size = 1672  # 0x688 bytes = 418 instructions

    # 1. Read original binary slice
    with open(orig_elf_path, 'rb') as f:
        f.seek(orig_file_offset)
        orig_bytes = f.read(func_size)
    orig_sha1 = hashlib.sha1(orig_bytes).hexdigest()

    # 2. Parse compiled ET_REL object
    raw_obj, secs, get_sym_name = parse_elf_sections(src_obj_path)
    text_sec = secs['.text']
    rel_text_sec = secs['.rel.text']
    symtab_sec = secs['.symtab']

    # Read .text bytes
    compiled_bytes = bytearray(raw_obj[text_sec['offset']:text_sec['offset'] + func_size])

    # Parse symbols from .symtab
    symbols = []
    sym_count = symtab_sec['size'] // symtab_sec['entsize']
    for i in range(sym_count):
        off = symtab_sec['offset'] + i * symtab_sec['entsize']
        st_name, st_value, st_size, st_info, st_other, st_shndx = struct.unpack_from('<IIIBBH', raw_obj, off)
        sym_name = get_sym_name(st_name)
        symbols.append((sym_name, st_value))

    # Parse relocations from .rel.text
    # Elf32_Rel: r_offset (4B), r_info (4B)
    reloc_count = rel_text_sec['size'] // rel_text_sec['entsize']
    gprel_count = 0
    jal_count = 0

    for i in range(reloc_count):
        off = rel_text_sec['offset'] + i * rel_text_sec['entsize']
        r_offset, r_info = struct.unpack_from('<II', raw_obj, off)
        r_type = r_info & 0xFF
        r_sym_idx = r_info >> 8
        sym_name, _ = symbols[r_sym_idx]

        if r_offset >= func_size:
            continue

        try:
            rel_kind = validate_and_apply_relocation(r_offset, r_type, sym_name, compiled_bytes)
            if rel_kind == "GPREL16":
                gprel_count += 1
            elif rel_kind == "JAL":
                jal_count += 1
        except ValueError as err:
            print(f"RELOCATION VALIDATION ERROR: {err}", file=sys.stderr)
            sys.exit(1)

    # Enforce exact relocation counts
    try:
        assert_relocation_counts(gprel_count, jal_count)
    except ValueError as err:
        print(f"RELOCATION COUNT ENFORCEMENT ERROR: {err}", file=sys.stderr)
        sys.exit(1)

    resolved_bytes = bytes(compiled_bytes)
    resolved_sha1 = hashlib.sha1(resolved_bytes).hexdigest()

    print("=== Milestone 148 (func_0027F890) Relocation-Resolved Byte Equality Verification ===")
    print(f"Target ELF:              {orig_elf_path}")
    print(f"File Offset:             {orig_file_offset:#08x} (VRAM 0x27F890)")
    print(f"Length:                  {func_size} bytes ({func_size // 4} instructions)")
    print(f"Original ELF slice SHA1: {orig_sha1}")
    print(f"Resolved code slice SHA1:{resolved_sha1}")
    print(f"GPREL16 resolved sites:  {gprel_count} (enforced exact: {EXPECTED_GPREL_COUNT}, addend = -0x71E4 / 0x8E1C)")
    print(f"JAL (R_MIPS_26) resolved:{jal_count} (enforced exact: {EXPECTED_JAL_COUNT})")
    print()

    # Byte by byte comparison
    mismatches = []
    for idx in range(func_size):
        if orig_bytes[idx] != resolved_bytes[idx]:
            mismatches.append(idx)

    if mismatches:
        print(f"FAILED: {len(mismatches)} mismatched bytes!")
        for m in mismatches[:10]:
            print(f"  Byte offset {m:#06x}: orig={orig_bytes[m]:#04x} resolved={resolved_bytes[m]:#04x}")
        sys.exit(1)
    else:
        print("RESULT: EXACT MATCH! 1672 / 1672 bytes identical (100.00% byte equality).")
        print("All 418 instructions match bit-for-bit against orig/SLES-50282/AOK.ELF.")
        sys.exit(0)


if __name__ == '__main__':
    main()
