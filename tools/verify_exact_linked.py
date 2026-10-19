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
EXPECTED_SLICE_SHA1 = "48ed6848bd4752320b1203159ead512a0f1da64c"

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


def validate_and_apply_relocation(r_offset, r_type, sym_name, compiled_bytes, func_size=None):
    """
    Validate relocation alignment, boundary, type, site opcode, registers,
    in-situ addend/target, and apply resolved value.
    Raises ValueError on any unexpected property.
    """
    if func_size is None:
        func_size = len(compiled_bytes)

    # 1. Alignment check: MIPS instructions must be 4-byte aligned
    if r_offset % 4 != 0:
        raise ValueError(
            f"Unaligned relocation offset {r_offset:#06x}: must be 4-byte aligned"
        )

    # 2. Site boundary check: 4-byte instruction must not exceed code size
    if r_offset + 4 > func_size or r_offset + 4 > len(compiled_bytes):
        raise ValueError(
            f"Relocation site exceeds code boundary at {r_offset:#06x} (code size {func_size})"
        )

    # 3. Type-specific validation
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

    # In ELF32, section header entries must be at least 40 bytes (sizeof(Elf32_Shdr))
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
    """Parse sections, symbols, and string tables from in-memory ELF bytearray."""
    validate_elf_bytes(data)

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

    # Section names
    shstr = sections[e_shstrndx]
    shstr_off = shstr['offset']
    shstr_size = shstr['size']
    if shstr_off + shstr_size > len(data):
        raise ValueError(f"Section name string table extends beyond file bounds: {shstr_off + shstr_size} > {len(data)}")

    def get_str(strtab_off, strtab_size, idx):
        if strtab_off + strtab_size > len(data):
            raise ValueError(f"String table extends beyond file bounds: {strtab_off + strtab_size} > {len(data)}")
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

    for required in ['.text', '.rel.text', '.symtab']:
        if required not in sec_by_name:
            raise ValueError(f"Missing required section {required} in ELF")

    symtab_sh_link = sec_by_name['.symtab']['link']
    if symtab_sh_link >= len(sections):
        raise ValueError(f"Invalid .symtab sh_link index: {symtab_sh_link} >= {len(sections)}")

    symtab_link = sections[symtab_sh_link]
    if symtab_link['type'] != 3:  # SHT_STRTAB
        raise ValueError(f"Expected .symtab sh_link to point to SHT_STRTAB (type 3), got type {symtab_link['type']}")
    if symtab_link['offset'] + symtab_link['size'] > len(data):
        raise ValueError("Symbol string table extends beyond file bounds")

    return data, sec_by_name, lambda idx: get_str(symtab_link['offset'], symtab_link['size'], idx)


def parse_elf_sections(path):
    with open(path, 'rb') as f:
        data = f.read()
    return parse_elf_sections_from_bytes(data)


def main():
    src_obj_path = 'build/SLES-50282/src/unit_action_build_7f890.o'
    orig_elf_path = 'orig/SLES-50282/AOK.ELF'
    orig_file_offset = 0x17FA70
    func_size = 1672  # 0x688 bytes = 418 instructions

    # 1. Read original binary slice
    with open(orig_elf_path, 'rb') as f:
        f.seek(orig_file_offset)
        orig_bytes = f.read(func_size)
    if len(orig_bytes) != func_size:
        print(f"ERROR: Truncated read from {orig_elf_path}: got {len(orig_bytes)}, expected {func_size}", file=sys.stderr)
        sys.exit(1)
    orig_sha1 = hashlib.sha1(orig_bytes).hexdigest()

    # 2. Parse compiled ET_REL object
    try:
        raw_obj, secs, get_sym_name = parse_elf_sections(src_obj_path)
    except ValueError as err:
        print(f"ELF PARSER ERROR: {err}", file=sys.stderr)
        sys.exit(1)

    text_sec = secs['.text']
    rel_text_sec = secs['.rel.text']
    symtab_sec = secs['.symtab']

    if text_sec['size'] < func_size:
        print(f"ERROR: .text section size ({text_sec['size']}) smaller than function size ({func_size})", file=sys.stderr)
        sys.exit(1)

    # Read .text bytes
    compiled_bytes = bytearray(raw_obj[text_sec['offset']:text_sec['offset'] + func_size])

    # Parse symbols from .symtab
    symbols = []
    if symtab_sec['entsize'] != 0 and symtab_sec['entsize'] < 16:
        print(f"ERROR: Invalid symbol table entry size: {symtab_sec['entsize']}", file=sys.stderr)
        sys.exit(1)
    sym_entsize = symtab_sec['entsize'] if symtab_sec['entsize'] >= 16 else 16
    sym_count = symtab_sec['size'] // sym_entsize

    for i in range(sym_count):
        off = symtab_sec['offset'] + i * sym_entsize
        if off + 16 > len(raw_obj):
            print(f"ERROR: Symbol {i} extends beyond file bounds", file=sys.stderr)
            sys.exit(1)
        st_name, st_value, st_size, st_info, st_other, st_shndx = struct.unpack_from('<IIIBBH', raw_obj, off)
        try:
            sym_name = get_sym_name(st_name)
        except ValueError as err:
            print(f"SYMBOL TABLE ERROR at index {i}: {err}", file=sys.stderr)
            sys.exit(1)
        symbols.append((sym_name, st_value))

    # Parse relocations from .rel.text
    # Elf32_Rel: r_offset (4B), r_info (4B)
    if rel_text_sec['entsize'] != 0 and rel_text_sec['entsize'] < 8:
        print(f"ERROR: Invalid relocation table entry size: {rel_text_sec['entsize']}", file=sys.stderr)
        sys.exit(1)
    rel_entsize = rel_text_sec['entsize'] if rel_text_sec['entsize'] >= 8 else 8
    reloc_count = rel_text_sec['size'] // rel_entsize
    gprel_count = 0
    jal_count = 0

    for i in range(reloc_count):
        off = rel_text_sec['offset'] + i * rel_entsize
        if off + 8 > len(raw_obj):
            print(f"ERROR: Relocation {i} extends beyond file bounds", file=sys.stderr)
            sys.exit(1)
        r_offset, r_info = struct.unpack_from('<II', raw_obj, off)
        r_type = r_info & 0xFF
        r_sym_idx = r_info >> 8

        if r_sym_idx >= len(symbols):
            print(f"RELOCATION ERROR: symbol index {r_sym_idx} out of range ({len(symbols)})", file=sys.stderr)
            sys.exit(1)

        sym_name, _ = symbols[r_sym_idx]

        if r_offset >= func_size:
            continue

        try:
            rel_kind = validate_and_apply_relocation(r_offset, r_type, sym_name, compiled_bytes, func_size)
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

    # Enforce pinned hashes
    try:
        assert_slice_hashes(orig_sha1, resolved_sha1)
    except ValueError as err:
        print(f"HASH ENFORCEMENT ERROR: {err}", file=sys.stderr)
        sys.exit(1)

    print("=== Milestone 148 (func_0027F890) Relocation-Resolved Byte Equality Verification ===")
    print(f"Target ELF:              {orig_elf_path}")
    print(f"File Offset:             {orig_file_offset:#08x} (VRAM 0x27F890)")
    print(f"Length:                  {func_size} bytes ({func_size // 4} instructions)")
    print(f"Original ELF slice SHA1: {orig_sha1} (enforced exact: {EXPECTED_SLICE_SHA1})")
    print(f"Resolved code slice SHA1:{resolved_sha1} (enforced exact: {EXPECTED_SLICE_SHA1})")
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
