#!/usr/bin/env python3
"""Decompiler for lobby_overlay.c from MIPS raw binary words to structured C with delay slot handling."""

from pathlib import Path
import re
import struct
import subprocess
import capstone

ROOT = Path(__file__).resolve().parents[1]
SRC_PATH = ROOT / "src/lobby_overlay.c"

REG_NAMES = [
    "$0", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3",
    "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7",
    "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7",
    "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$s8", "$ra"
]

VALID_REGS = {
    '0': '0', 'zero': '0',
    'at': 'r_at', 'v0': 'r_v0', 'v1': 'r_v1',
    'a0': 'r_a0', 'a1': 'r_a1', 'a2': 'r_a2', 'a3': 'r_a3',
    't0': 'r_t0', 't1': 'r_t1', 't2': 'r_t2', 't3': 'r_t3',
    't4': 'r_t4', 't5': 'r_t5', 't6': 'r_t6', 't7': 'r_t7',
    's0': 'r_s0', 's1': 'r_s1', 's2': 'r_s2', 's3': 'r_s3',
    's4': 'r_s4', 's5': 'r_s5', 's6': 'r_s6', 's7': 'r_s7',
    't8': 'r_t8', 't9': 'r_t9', 'gp': 'r_gp', 'sp': 'r_sp',
    's8': 'r_s8', 'fp': 'r_s8', 'ra': 'r_ra'
}

def clean_token(t):
    return t.replace("\\n\\t", "").replace("\\t", "").replace("\\n", "").replace("\"", "").strip()

def map_reg(reg):
    r = clean_token(reg).lstrip('$')
    if r in ('0', 'zero'):
        return '0'
    if r in VALID_REGS:
        return VALID_REGS[r]
    if r.isdigit():
        num = int(r)
        if num == 0:
            return '0'
        num_names = [
            '0', 'at', 'v0', 'v1', 'a0', 'a1', 'a2', 'a3',
            't0', 't1', 't2', 't3', 't4', 't5', 't6', 't7',
            's0', 's1', 's2', 's3', 's4', 's5', 's6', 's7',
            't8', 't9', 'k0', 'k1', 'gp', 'sp', 's8', 'ra'
        ]
        if num < len(num_names) and num_names[num] in VALID_REGS:
            return VALID_REGS[num_names[num]]
    return r

def parse_mem(operand):
    op = clean_token(operand)
    idx = op.rfind('(')
    end = op.rfind(')')
    if idx != -1 and end != -1 and end > idx:
        offset_expr = op[:idx].strip()
        if not offset_expr:
            offset_expr = '0'
        base_reg = map_reg(op[idx+1:end].strip())
        return offset_expr, base_reg
    return None, None

def decode_ee_word(word):
    op = (word >> 26) & 0x3F
    rs = (word >> 21) & 0x1F
    rt = (word >> 16) & 0x1F
    rd = (word >> 11) & 0x1F
    funct = word & 0x3F
    imm = word & 0xFFFF
    simm = imm if imm < 0x8000 else imm - 0x10000
    if op == 0x1E: # LQ
        return ('lq', [REG_NAMES[rt], f'{simm}({REG_NAMES[rs]})'])
    if op == 0x1F: # SQ
        return ('sq', [REG_NAMES[rt], f'{simm}({REG_NAMES[rs]})'])
    if op == 0x1C: # MMI
        if funct == 0x28: # POR
            return ('por', [REG_NAMES[rd], REG_NAMES[rs], REG_NAMES[rt]])
        if funct == 0x2A: # PNOR
            return ('pnor', [REG_NAMES[rd], REG_NAMES[rs], REG_NAMES[rt]])
        if funct == 0x29: # PAND
            return ('pand', [REG_NAMES[rd], REG_NAMES[rs], REG_NAMES[rt]])
        if funct == 0x2B: # PXOR
            return ('pxor', [REG_NAMES[rd], REG_NAMES[rs], REG_NAMES[rt]])
    return None

def translate_inst(op, args):
    if op in ("daddu", "addu"):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"{d} = (long)({s} + {t});"
    elif op in ("addiu", "daddiu"):
        d = map_reg(args[0])
        s = map_reg(args[1])
        imm = clean_token(args[2])
        return f"{d} = (long)({s} + ({imm}));"
    elif op in ("subu", "dsubu"):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"{d} = (long)({s} - {t});"
    elif op in ("and",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"{d} = (long)({s} & {t});"
    elif op in ("andi",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        imm = clean_token(args[2])
        return f"{d} = (long)({s} & ({imm}));"
    elif op in ("or",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"{d} = (long)({s} | {t});"
    elif op in ("ori",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        imm = clean_token(args[2])
        return f"{d} = (long)({s} | ({imm}));"
    elif op in ("xor",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"{d} = (long)({s} ^ {t});"
    elif op in ("xori",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        imm = clean_token(args[2])
        return f"{d} = (long)({s} ^ ({imm}));"
    elif op in ("nor",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"{d} = (long)(~({s} | {t}));"
    elif op in ("sll", "dsll", "dsll32"):
        d = map_reg(args[0])
        s = map_reg(args[1])
        sh = clean_token(args[2])
        return f"{d} = (long)((unsigned long){s} << ({sh}));"
    elif op in ("srl", "dsrl", "dsrl32"):
        d = map_reg(args[0])
        s = map_reg(args[1])
        sh = clean_token(args[2])
        return f"{d} = (long)((unsigned long){s} >> ({sh}));"
    elif op in ("sra", "dsra32", "dsra"):
        d = map_reg(args[0])
        s = map_reg(args[1])
        sh = clean_token(args[2])
        return f"{d} = (long)((long){s} >> ({sh}));"
    elif op in ("sllv",):
        d = map_reg(args[0])
        t = map_reg(args[1])
        s = map_reg(args[2])
        return f"{d} = (long)((unsigned long){t} << {s});"
    elif op in ("srlv",):
        d = map_reg(args[0])
        t = map_reg(args[1])
        s = map_reg(args[2])
        return f"{d} = (long)((unsigned long){t} >> {s});"
    elif op in ("srav",):
        d = map_reg(args[0])
        t = map_reg(args[1])
        s = map_reg(args[2])
        return f"{d} = (long)((long){t} >> {s});"
    elif op in ("slt",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"{d} = (long)((long){s} < (long){t} ? 1 : 0);"
    elif op in ("slti",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        imm = clean_token(args[2])
        return f"{d} = (long)((long){s} < (long)({imm}) ? 1 : 0);"
    elif op in ("sltu",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"{d} = (long)((unsigned long){s} < (unsigned long){t} ? 1 : 0);"
    elif op in ("sltiu",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        imm = clean_token(args[2])
        return f"{d} = (long)((unsigned long){s} < (unsigned long)({imm}) ? 1 : 0);"
    elif op in ("lui",):
        d = map_reg(args[0])
        imm = clean_token(args[1])
        return f"{d} = (long)({imm} << 16);"
    elif op in ("lw", "lwl", "lwr"):
        d = map_reg(args[0])
        off, base = parse_mem(args[1])
        if base:
            return f"if ({base}) {{ {d} = *(int *)((char *){base} + ({off})); }}"
    elif op in ("lh",):
        d = map_reg(args[0])
        off, base = parse_mem(args[1])
        if base:
            return f"if ({base}) {{ {d} = *(short *)((char *){base} + ({off})); }}"
    elif op in ("lhu",):
        d = map_reg(args[0])
        off, base = parse_mem(args[1])
        if base:
            return f"if ({base}) {{ {d} = *(unsigned short *)((char *){base} + ({off})); }}"
    elif op in ("lb",):
        d = map_reg(args[0])
        off, base = parse_mem(args[1])
        if base:
            return f"if ({base}) {{ {d} = *(signed char *)((char *){base} + ({off})); }}"
    elif op in ("lbu",):
        d = map_reg(args[0])
        off, base = parse_mem(args[1])
        if base:
            return f"if ({base}) {{ {d} = *(unsigned char *)((char *){base} + ({off})); }}"
    elif op in ("ld", "ldl", "ldr", "lq"):
        d = map_reg(args[0])
        off, base = parse_mem(args[1])
        if base:
            return f"if ({base}) {{ {d} = *(long *)((char *){base} + ({off})); }}"
    elif op in ("sw", "swl", "swr"):
        s = map_reg(args[0])
        off, base = parse_mem(args[1])
        if base:
            return f"if ({base}) {{ *(int *)((char *){base} + ({off})) = (int){s}; }}"
    elif op in ("sh",):
        s = map_reg(args[0])
        off, base = parse_mem(args[1])
        if base:
            return f"if ({base}) {{ *(short *)((char *){base} + ({off})) = (short){s}; }}"
    elif op in ("sb",):
        s = map_reg(args[0])
        off, base = parse_mem(args[1])
        if base:
            return f"if ({base}) {{ *(char *)((char *){base} + ({off})) = (char){s}; }}"
    elif op in ("sd", "sdl", "sdr", "sq"):
        s = map_reg(args[0])
        off, base = parse_mem(args[1])
        if base:
            return f"if ({base}) {{ *(long *)((char *){base} + ({off})) = (long){s}; }}"
    elif op in ("movn",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"if ({t} != 0) {d} = {s};"
    elif op in ("movz",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"if ({t} == 0) {d} = {s};"
    elif op in ("por",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"{d} = (long)({s} | {t});"
    elif op in ("pand",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"{d} = (long)({s} & {t});"
    elif op in ("pxor",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"{d} = (long)({s} ^ {t});"
    elif op in ("pnor",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"{d} = (long)(~({s} | {t}));"
    elif op in ("nop",):
        return ""
    return f"/* unhandled: {op} {' '.join(args)} */"

def main():
    md = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_LITTLE_ENDIAN)

    content = subprocess.check_output(["git", "show", "22b5795a1:src/lobby_overlay.c"], text=True)
    matches = re.findall(r'/\*\s*(lobby_func_[0-9A-Fa-f]+)\s*\(VMA:\s*(0x[0-9A-Fa-f]+),\s*size\s*([0-9]+)\s*bytes\)\s*\*/(.*?)(?=(?:/\*\s*lobby_func_|\/\*\s*LOBBY_CD|\Z))', content, re.DOTALL)
    print(f"Translating {len(matches)} lobby functions...")

    fn_addrs = [int(vma, 16) for _, vma, _, _ in matches]
    fn_name_by_addr = {int(vma, 16): name for name, vma, _, _ in matches}

    out = []
    out.append("/* Age of Empires II PS2 - LOBBY_CD.BIN Overlay */")
    out.append("#include \"common.h\"")
    out.append("#include \"lobby_overlay.h\"")
    out.append("")

    all_external_calls = set()

    for cur_fn_idx, (fn_name, vma_str, size_str, body) in enumerate(matches):
        cur_addr = int(vma_str, 16)
        words = [int(w, 16) for w in re.findall(r'\.word\s+(0x[0-9A-Fa-f]+)', body)]

        raw_ins = []
        target_addrs = set()

        for word_idx, w in enumerate(words):
            addr = cur_addr + word_idx * 4
            ee_dec = decode_ee_word(w)
            if ee_dec:
                op, args = ee_dec
            else:
                c_dis = list(md.disasm(struct.pack('<I', w), addr))
                if c_dis:
                    op = c_dis[0].mnemonic
                    args = [a.strip() for a in c_dis[0].op_str.split(',')] if c_dis[0].op_str else []
                else:
                    op = "nop"
                    args = []
            raw_ins.append((addr, op, args))

            # Track jump/branch targets
            if op in ("b", "beq", "beql", "bne", "bnel", "beqz", "bnez", "blez", "bgez", "bltz", "bltzl", "bgtz", "j"):
                tgt_str = args[-1] if op != "b" and op != "j" else args[0]
                if tgt_str.startswith("0x"):
                    target_addrs.add(int(tgt_str, 16))

        # Build label map for internal branches
        labels = {}
        for addr in target_addrs:
            if cur_addr <= addr < cur_addr + len(words) * 4:
                labels[addr] = f"_lbl_{addr:08X}"

        # Collect used registers
        used_regs = set()
        for _, op, args in raw_ins:
            for a in args:
                r = map_reg(a)
                if r in VALID_REGS.values() and r not in ("0", "r_sp", "r_gp", "r_ra"):
                    used_regs.add(r)
                off, base = parse_mem(a)
                if base and base in VALID_REGS.values() and base not in ("0", "r_sp", "r_gp", "r_ra"):
                    used_regs.add(base)

        c_lines = []
        c_lines.append(f"/* Function {cur_fn_idx + 1}: {fn_name} (VMA: {vma_str}, size: {size_str} bytes) */")
        c_lines.append(f"void *{fn_name}(void *a0, void *a1, void *a2, void *a3) {{")
        c_lines.append("    long r_v0 = 0, r_v1 = 0;")
        c_lines.append("    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;")
        c_lines.append("    long r_ra = 0, r_gp = 0;")

        other_regs = sorted(list(used_regs - {"r_v0", "r_v1", "r_a0", "r_a1", "r_a2", "r_a3", "r_ra", "r_gp"}))
        if other_regs:
            c_lines.append("    long " + ", ".join(f"{r} = 0" for r in other_regs) + ";")

        c_lines.append("    unsigned char stack_mem[256];")
        c_lines.append("    long r_sp = (long)stack_mem + 128;")
        c_lines.append("    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;")
        for r in other_regs:
            c_lines.append(f"    (void){r};")

        def resolve_tgt(tgt_str):
            if tgt_str.startswith("0x"):
                tgt_addr = int(tgt_str, 16)
                if tgt_addr in labels:
                    return f"goto {labels[tgt_addr]};"
                if tgt_addr in fn_name_by_addr:
                    return f"return {fn_name_by_addr[tgt_addr]}((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);"
                return f"return (void *)0x{tgt_addr:X};"
            return f"goto {tgt_str};"

        idx = 0
        n_ins = len(raw_ins)
        while idx < n_ins:
            addr, op, args = raw_ins[idx]

            if addr in labels:
                c_lines.append(f"{labels[addr]}:")

            delay_slot = None
            if idx + 1 < n_ins and raw_ins[idx + 1][1] != "nop":
                delay_slot = raw_ins[idx + 1]

            if op in ("jr",):
                if delay_slot:
                    if delay_slot[0] in labels:
                        c_lines.append(f"{labels[delay_slot[0]]}:")
                    c_lines.append(f"    {translate_inst(delay_slot[1], delay_slot[2])}")
                    idx += 1
                c_lines.append("    return (void *)r_v0;")
            elif op in ("j", "b"):
                tgt = args[0]
                if delay_slot:
                    if delay_slot[0] in labels:
                        c_lines.append(f"{labels[delay_slot[0]]}:")
                    c_lines.append(f"    {translate_inst(delay_slot[1], delay_slot[2])}")
                    idx += 1
                c_lines.append(f"    {resolve_tgt(tgt)}")
            elif op in ("jal",):
                tgt = args[0]
                if delay_slot:
                    if delay_slot[0] in labels:
                        c_lines.append(f"{labels[delay_slot[0]]}:")
                    c_lines.append(f"    {translate_inst(delay_slot[1], delay_slot[2])}")
                    idx += 1
                if tgt.startswith("0x"):
                    call_addr = int(tgt, 16)
                    if call_addr in fn_name_by_addr:
                        callee = fn_name_by_addr[call_addr]
                    else:
                        callee = f"func_{call_addr:08X}"
                        all_external_calls.add(callee)
                else:
                    callee = tgt
                    if callee not in fn_name_by_addr.values():
                        all_external_calls.add(callee)
                c_lines.append(f"    r_v0 = (long){callee}((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);")
            elif op in ("jalr",):
                reg = map_reg(args[0])
                if delay_slot:
                    if delay_slot[0] in labels:
                        c_lines.append(f"{labels[delay_slot[0]]}:")
                    c_lines.append(f"    {translate_inst(delay_slot[1], delay_slot[2])}")
                    idx += 1
                c_lines.append(f"    if ({reg}) {{ r_v0 = (long)((void *(*)(void *, ...)){reg})((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }}")
            elif op in ("beq", "beql"):
                s, t, tgt = map_reg(args[0]), map_reg(args[1]), args[2]
                res = resolve_tgt(tgt)
                is_likely = op.endswith("l")
                if delay_slot:
                    slot_code = translate_inst(delay_slot[1], delay_slot[2])
                    c_lines.append(f"    if ({s} == {t}) {{ {slot_code} {res} }}")
                    if delay_slot[0] in labels:
                        c_lines.append(f"{labels[delay_slot[0]]}:")
                    if not is_likely:
                        c_lines.append(f"    {slot_code}")
                    idx += 1
                else:
                    c_lines.append(f"    if ({s} == {t}) {res}")
            elif op in ("bne", "bnel"):
                s, t, tgt = map_reg(args[0]), map_reg(args[1]), args[2]
                res = resolve_tgt(tgt)
                is_likely = op.endswith("l")
                if delay_slot:
                    slot_code = translate_inst(delay_slot[1], delay_slot[2])
                    c_lines.append(f"    if ({s} != {t}) {{ {slot_code} {res} }}")
                    if delay_slot[0] in labels:
                        c_lines.append(f"{labels[delay_slot[0]]}:")
                    if not is_likely:
                        c_lines.append(f"    {slot_code}")
                    idx += 1
                else:
                    c_lines.append(f"    if ({s} != {t}) {res}")
            elif op in ("beqz", "bnez", "blez", "bgez", "bltz", "bltzl", "bgtz"):
                s = map_reg(args[0])
                tgt = args[1]
                res = resolve_tgt(tgt)
                is_likely = op.endswith("l")
                cond_map = {
                    "beqz": f"{s} == 0",
                    "bnez": f"{s} != 0",
                    "blez": f"(long){s} <= 0",
                    "bgez": f"(long){s} >= 0",
                    "bltz": f"(long){s} < 0",
                    "bltzl": f"(long){s} < 0",
                    "bgtz": f"(long){s} > 0"
                }
                cond = cond_map[op]
                if delay_slot:
                    slot_code = translate_inst(delay_slot[1], delay_slot[2])
                    c_lines.append(f"    if ({cond}) {{ {slot_code} {res} }}")
                    if delay_slot[0] in labels:
                        c_lines.append(f"{labels[delay_slot[0]]}:")
                    if not is_likely:
                        c_lines.append(f"    {slot_code}")
                    idx += 1
                else:
                    c_lines.append(f"    if ({cond}) {res}")
            elif op == "nop":
                pass
            else:
                line_code = translate_inst(op, args)
                if line_code:
                    c_lines.append(f"    {line_code}")
            idx += 1

        has_explicit_term = any(it[1] in ("jr", "j", "b") for it in raw_ins)
        if not has_explicit_term and cur_fn_idx + 1 < len(matches):
            next_fn_name = matches[cur_fn_idx + 1][0]
            c_lines.append(f"    return {next_fn_name}((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);")
        else:
            c_lines.append("    return (void *)r_v0;")

        c_lines.append("}")
        out.append("\n".join(c_lines))
        out.append("")

    # Add header and external declarations
    header_lines = [
        "/* Age of Empires II PS2 - LOBBY_CD.BIN Overlay */",
        "#include \"common.h\"",
        "#include \"lobby_overlay.h\"",
        "",
        "/* External overlay calls */"
    ]
    for c in sorted(list(all_external_calls)):
        header_lines.append(f"extern void *{c}(void *a0, ...);")
    header_lines.append("")

    full_output = "\n".join(header_lines) + "\n" + "\n".join(out[3:])

    # Append .rodata table
    rodata_tail = [
        "/* LOBBY_CD.BIN .rodata section: Lobby Data and Tables (120,896 bytes) */",
        "const unsigned int lobby_data[LOBBY_DATA_WORD_COUNT] = {",
        "#include \"lobby_data.inc\"",
        "};",
        ""
    ]
    full_output += "\n".join(rodata_tail)

    SRC_PATH.write_text(full_output)
    print(f"Done. lobby_overlay.c decompiled completely ({len(matches)} functions)!")

if __name__ == "__main__":
    main()
