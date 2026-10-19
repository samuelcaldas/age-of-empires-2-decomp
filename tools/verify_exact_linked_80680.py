#!/usr/bin/env python3
"""
Stand-alone verification script for Milestone 151 (func_00280680).
Uses ONLY standard library (struct, hashlib). No pyelftools or external deps required.
"""
import hashlib
import struct
import sys
from pathlib import Path

EXPECTED_GPREL_COUNT = 1
EXPECTED_JAL_COUNT = 2
EXPECTED_SLICE_SHA1 = "3a5ed9046834ca80b63af322cfe1c479c8fdfb7a"
TARGET_SYMBOL = "func_00280680"
EXPECTED_SYMBOL_OFFSET = 0
EXPECTED_SYMBOL_SIZE = 236

GP_VAL = 0x4EA7C0


def load_symbols_map(symbols_path="config/SLES-50282/symbols.txt"):
    """
    Parse symbol addresses from symbols.txt into a dictionary.
    Does NOT infer addresses from symbol names.
    """
    sym_map = {
        "func_366AF0": 0x366AF0,
        "func_366af0": 0x366AF0,
        "func_138B50": 0x138B50,
        "func_00138B50": 0x138B50,
        "D_4E35DC": 0x4E35DC,
    }
    path = Path(symbols_path)
    if path.is_file():
        with open(path, "r", encoding="latin1") as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith("//"):
                    continue
                code_part = line.split("//")[0].strip()
                if "=" in code_part:
                    name_part, val_part = code_part.split("=", 1)
                    name = name_part.strip()
                    val_str = val_part.strip().rstrip(";")
                    try:
                        sym_map[name] = int(val_str, 0)
                    except ValueError:
                        pass
    return sym_map


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


def assert_function_symbol(sym_name, st_value, st_size, st_shndx, text_sec_idx):
    """Enforce that function symbol starts at offset 0 of .text and has size 236."""
    if sym_name != TARGET_SYMBOL:
        raise ValueError(
            f"Symbol name mismatch: got {sym_name}, expected {TARGET_SYMBOL}"
        )
    if st_value != EXPECTED_SYMBOL_OFFSET:
        raise ValueError(
            f"Symbol {sym_name} offset mismatch: got {st_value}, expected {EXPECTED_SYMBOL_OFFSET}"
        )
    if st_size != EXPECTED_SYMBOL_SIZE:
        raise ValueError(
            f"Symbol {sym_name} size mismatch: got {st_size}, expected {EXPECTED_SYMBOL_SIZE}"
        )
    if st_shndx != text_sec_idx:
        raise ValueError(
            f"Symbol {sym_name} section mismatch: got {st_shndx}, expected {text_sec_idx}"
        )


def validate_table_entry_divisibility(symtab_size, sym_entsize, reloc_size, reloc_entsize):
    """
    Validate that symbol and relocation table sizes are cleanly divisible by entry size.
    Raises ValueError on non-positive entry size or trailing/partial bytes.
    """
    if sym_entsize <= 0:
        raise ValueError(f"Invalid symbol entry size: {sym_entsize}")
    if symtab_size % sym_entsize != 0:
        raise ValueError(
            f"Symbol table size ({symtab_size}) not cleanly divisible by entry size ({sym_entsize}): {symtab_size % sym_entsize} trailing bytes"
        )
    if reloc_entsize <= 0:
        raise ValueError(f"Invalid relocation entry size: {reloc_entsize}")
    if reloc_size % reloc_entsize != 0:
        raise ValueError(
            f"Relocation table size ({reloc_size}) not cleanly divisible by entry size ({reloc_entsize}): {reloc_size % reloc_entsize} trailing bytes"
        )


def validate_and_apply_relocation(r_offset, r_type, sym_name, compiled_bytes, func_size=None, symbols_map=None):
    """
    Validate relocation alignment, boundary, type, site opcode, registers,
    in-situ addend/target, look up symbol address from symbols_map,
    compute relocation addend, validate JAL 256MB region, and apply resolved value.
    Raises ValueError on any unexpected property or unmapped symbol.
    """
    if func_size is None:
        func_size = len(compiled_bytes)
    if symbols_map is None:
        symbols_map = load_symbols_map()

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

    # 3. Lookup symbol value in symbols map
    if sym_name not in symbols_map:
        raise ValueError(f"Symbol {sym_name} not defined in symbols map")
    sym_value = symbols_map[sym_name]

    # 4. Type-specific validation
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
        in_situ_addend = w & 0xFFFF
        if in_situ_addend != 0:
            raise ValueError(
                f"Non-zero in-situ addend at GPREL16 site {r_offset:#06x}: got {in_situ_addend:#06x}, expected 0x0"
            )
        computed_addend = (sym_value - GP_VAL) & 0xFFFF
        w_applied = (w & 0xFFFF0000) | computed_addend
        struct.pack_into('<I', compiled_bytes, r_offset, w_applied)
        return "GPREL16"

    elif r_type == 4:  # R_MIPS_26
        w = struct.unpack_from('<I', compiled_bytes, r_offset)[0]
        op = (w >> 26) & 0x3F
        if op != 3:
            raise ValueError(
                f"Invalid opcode at JAL site {r_offset:#06x}: got {w:#010x} (op={op}), expected jal (op=3)"
            )
        in_situ_target = w & 0x03FFFFFF
        if in_situ_target != 0:
            raise ValueError(
                f"Non-zero in-situ target field at JAL site {r_offset:#06x}: got {in_situ_target:#010x}, expected 0x0"
            )

        # Validate JAL 256MB region constraint (VRAM base is 0x280680)
        call_site_vram = 0x280680 + r_offset
        if (sym_value & 0xF0000000) != ((call_site_vram + 4) & 0xF0000000):
            raise ValueError(
                f"JAL target {sym_value:#010x} out of 256MB region for call site at {call_site_vram:#010x}"
            )

        jal_target_field = (sym_value >> 2) & 0x03FFFFFF
        w_applied = 0x0C000000 | jal_target_field
        struct.pack_into('<I', compiled_bytes, r_offset, w_applied)
        return "JAL"

    else:
        raise ValueError(
            f"Unsupported in-range relocation type {r_type} at offset {r_offset:#06x}"
        )


def validate_elf_bytes(data):
    """Validate ELF32 structure, magic, type, machine, section entry size, and header bounds."""
    if len(data) < 52:
        raise ValueError(f"Invalid ELF: file size ({len(data)} bytes) smaller than ELF32 header (52 bytes)")
    if data[:4] != b'\x7fELF':
        raise ValueError(f"Invalid ELF magic: {data[:4]!r}")
    if data[4] != 1:  # ELFCLASS32
        raise ValueError(f"Invalid ELF class: {data[4]}, expected ELFCLASS32 (1)")
    if data[5] != 1:  # ELFDATA2LSB (little-endian)
        raise ValueError(f"Invalid ELF endianness: {data[5]}, expected 2LSB (1)")

    e_type = struct.unpack_from('<H', data, 0x10)[0]
    e_machine = struct.unpack_from('<H', data, 0x12)[0]
    if e_type != 1:  # ET_REL
        raise ValueError(f"Invalid ELF type: {e_type}, expected ET_REL (1)")
    if e_machine != 8:  # EM_MIPS
        raise ValueError(f"Invalid ELF machine: {e_machine}, expected EM_MIPS (8)")

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
    """Parse sections, symbols, and string tables from in-memory ELF bytearray."""
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
            'index': i,
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

    for required in ['.text', '.symtab']:
        if required not in sec_by_name:
            raise ValueError(f"Missing required section {required} in ELF")

    symtab_sh_link = sec_by_name['.symtab']['link']
    if symtab_sh_link >= len(sections):
        raise ValueError(f"Invalid .symtab sh_link index: {symtab_sh_link} >= {len(sections)}")

    symtab_link = sections[symtab_sh_link]
    if symtab_link['type'] != 3:
        raise ValueError(f"Expected .symtab sh_link to point to SHT_STRTAB (type 3), got type {symtab_link['type']}")
    if symtab_link['offset'] + symtab_link['size'] > len(data):
        raise ValueError("Symbol string table extends beyond file bounds")

    return data, sec_by_name, lambda idx: get_str(symtab_link['offset'], symtab_link['size'], idx)


def parse_elf_sections(path):
    with open(path, 'rb') as f:
        data = f.read()
    return parse_elf_sections_from_bytes(data)


def verify_linked_bytes(src_obj_path='build/SLES-50282/src/unit_action_build_80680.o',
                        orig_elf_path='orig/SLES-50282/AOK.ELF',
                        orig_file_offset=0x180860,
                        func_size=236,
                        symbols_override=None):
    """
    Perform full relocation-aware byte equality verification for func_00280680.
    Asserts func_00280680 symbol starts at offset 0 of .text and has size 236.
    Validates preserved JALR slots at 0x48 and 0x98.
    Rejects any relocation outside [0, func_size).
    Returns (orig_sha1, resolved_sha1, gprel_count, jal_count).
    Raises ValueError on any discrepancy.
    """
    symbols_map = symbols_override if symbols_override is not None else load_symbols_map()

    # 1. Read original binary slice
    with open(orig_elf_path, 'rb') as f:
        f.seek(orig_file_offset)
        orig_bytes = f.read(func_size)
    if len(orig_bytes) != func_size:
        raise ValueError(f"Truncated read from {orig_elf_path}: got {len(orig_bytes)}, expected {func_size}")
    orig_sha1 = hashlib.sha1(orig_bytes).hexdigest()

    # 2. Parse compiled ET_REL object
    raw_obj, secs, get_sym_name = parse_elf_sections(src_obj_path)
    text_sec = secs['.text']
    text_sec_idx = text_sec['index']
    symtab_sec = secs['.symtab']
    symtab_sec_idx = symtab_sec['index']

    if text_sec['size'] < func_size:
        raise ValueError(f".text section size ({text_sec['size']}) smaller than function size ({func_size})")

    # 3. Assert function symbol starts at offset 0 and has size 236 in .text
    sym_entsize = symtab_sec['entsize'] if symtab_sec['entsize'] >= 16 else 16
    sym_count = symtab_sec['size'] // sym_entsize
    found_symbol = False

    for i in range(sym_count):
        off = symtab_sec['offset'] + i * sym_entsize
        st_name, st_value, st_size, st_info, st_other, st_shndx = struct.unpack_from('<IIIBBH', raw_obj, off)
        sym_name = get_sym_name(st_name)
        if sym_name == TARGET_SYMBOL:
            assert_function_symbol(sym_name, st_value, st_size, st_shndx, text_sec_idx)
            found_symbol = True
            break

    if not found_symbol:
        raise ValueError(f"Required function symbol {TARGET_SYMBOL} not found in .symtab")

    # Read .text bytes
    compiled_bytes = bytearray(raw_obj[text_sec['offset']:text_sec['offset'] + func_size])

    # 4. Validate preserved JALR slots (indirect vtable calls) at 0x48 and 0x98
    jalr_slots = [0x48, 0x98]
    for slot in jalr_slots:
        w = struct.unpack_from('<I', compiled_bytes, slot)[0]
        if w != 0x0320F809:  # jalr $ra, $t9
            raise ValueError(f"Preserved JALR slot at {slot:#04x} corrupted: got {w:#010x}, expected jalr $ra, $t9 (0x0320f809)")

    # 5. Parse and apply relocations from .rel.text
    gprel_count = 0
    jal_count = 0

    if '.rel.text' in secs:
        rel_text_sec = secs['.rel.text']
        rel_entsize = rel_text_sec['entsize'] if rel_text_sec['entsize'] >= 8 else 8

        # Validate section associations (sh_info must point to .text, sh_link to .symtab)
        if rel_text_sec['info'] != text_sec_idx:
            raise ValueError(f".rel.text sh_info ({rel_text_sec['info']}) does not target .text index ({text_sec_idx})")
        if rel_text_sec['link'] != symtab_sec_idx:
            raise ValueError(f".rel.text sh_link ({rel_text_sec['link']}) does not target .symtab index ({symtab_sec_idx})")

        validate_table_entry_divisibility(
            symtab_sec['size'], sym_entsize,
            rel_text_sec['size'], rel_entsize
        )

        symbols = []
        for i in range(sym_count):
            off = symtab_sec['offset'] + i * sym_entsize
            st_name, st_value, st_size, st_info, st_other, st_shndx = struct.unpack_from('<IIIBBH', raw_obj, off)
            sym_name = get_sym_name(st_name)
            symbols.append((sym_name, st_value))

        reloc_count = rel_text_sec['size'] // rel_entsize
        for i in range(reloc_count):
            off = rel_text_sec['offset'] + i * rel_entsize
            r_offset, r_info = struct.unpack_from('<II', raw_obj, off)
            r_type = r_info & 0xFF
            r_sym_idx = r_info >> 8

            if r_sym_idx >= len(symbols):
                raise ValueError(f"Symbol index {r_sym_idx} out of range ({len(symbols)})")

            sym_name, _ = symbols[r_sym_idx]

            # Reject out-of-bounds relocations rather than silently skipping
            if r_offset >= func_size:
                raise ValueError(f"Relocation offset {r_offset:#06x} extends beyond function size ({func_size})")

            rel_kind = validate_and_apply_relocation(
                r_offset, r_type, sym_name, compiled_bytes, func_size, symbols_map=symbols_map
            )
            if rel_kind == "GPREL16":
                gprel_count += 1
            elif rel_kind == "JAL":
                jal_count += 1

    # Enforce exact relocation counts
    assert_relocation_counts(gprel_count, jal_count)

    resolved_bytes = bytes(compiled_bytes)
    resolved_sha1 = hashlib.sha1(resolved_bytes).hexdigest()

    assert_slice_hashes(orig_sha1, resolved_sha1)

    mismatches = []
    for idx in range(func_size):
        if orig_bytes[idx] != resolved_bytes[idx]:
            mismatches.append(idx)

    if mismatches:
        raise ValueError(f"Byte mismatch at {len(mismatches)} positions! First at {mismatches[0]:#06x}")

    return orig_sha1, resolved_sha1, gprel_count, jal_count


def main():
    src_obj_path = 'build/SLES-50282/src/unit_action_build_80680.o'
    orig_elf_path = 'orig/SLES-50282/AOK.ELF'
    orig_file_offset = 0x180860
    func_size = 236  # 59 instructions

    try:
        orig_sha1, resolved_sha1, gprel_count, jal_count = verify_linked_bytes(
            src_obj_path=src_obj_path,
            orig_elf_path=orig_elf_path,
            orig_file_offset=orig_file_offset,
            func_size=func_size
        )
    except ValueError as err:
        print(f"VERIFICATION FAILURE: {err}", file=sys.stderr)
        sys.exit(1)

    print("=== Milestone 151 (func_00280680) Relocation-Resolved Byte Equality Verification ===")
    print(f"Target ELF:              {orig_elf_path}")
    print(f"File Offset:             {orig_file_offset:#08x} (VRAM 0x280680)")
    print(f"Length:                  {func_size} bytes ({func_size // 4} instructions)")
    print(f"Symbol {TARGET_SYMBOL}:  validated at .text offset {EXPECTED_SYMBOL_OFFSET}, size {EXPECTED_SYMBOL_SIZE}")
    print(f"Original ELF slice SHA1: {orig_sha1} (enforced exact: {EXPECTED_SLICE_SHA1})")
    print(f"Resolved code slice SHA1:{resolved_sha1} (enforced exact: {EXPECTED_SLICE_SHA1})")
    print(f"GPREL16 resolved sites:  {gprel_count} (enforced exact: {EXPECTED_GPREL_COUNT}, addend = -0x71E4 / 0x8E1C)")
    print(f"JAL (R_MIPS_26) resolved:{jal_count} (enforced exact: {EXPECTED_JAL_COUNT})")
    print("Preserved JALR slots:    2 (slots at 0x48 and 0x98 verified as jalr $ra, $t9)")
    print()
    print("RESULT: EXACT MATCH! 236 / 236 bytes identical (100.00% byte equality).")
    print("All 59 instructions match bit-for-bit against orig/SLES-50282/AOK.ELF.")
    sys.exit(0)


if __name__ == '__main__':
    main()
