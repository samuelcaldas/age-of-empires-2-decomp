#!/usr/bin/env python3
"""Decompiler for thelp_overlay.c from MIPS raw binary words to structured C with delay slot handling."""

from pathlib import Path
import re
import struct
import capstone

ROOT = Path(__file__).resolve().parents[1]
SRC_PATH = ROOT / "src/thelp_overlay.c"

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
        if num < len(num_names):
            name = num_names[num]
            return VALID_REGS.get(name, f'r_{name}')
    return f'r_{r}'

def decode_mem_arg(arg):
    m = re.match(r'^(-?0x[0-9a-fA-F]+|-?[0-9]+)\((.*)\)$', arg)
    if m:
        offset = int(m.group(1), 0)
        base = map_reg(m.group(2))
        return offset, base
    m2 = re.match(r'^\((.*)\)$', arg)
    if m2:
        return 0, map_reg(m2.group(1))
    return 0, map_reg(arg)

def decode_ee_word(w):
    op = (w >> 26) & 0x3F
    rs = (w >> 21) & 0x1F
    rt = (w >> 16) & 0x1F
    rd = (w >> 11) & 0x1F
    funct = w & 0x3F
    if op == 0x1F:
        if funct == 0x12:
            return "sq", [REG_NAMES[rt], f"{w & 0xFFFF}({REG_NAMES[rs]})"]
    elif op == 0x1E:
        if funct == 0x12:
            return "lq", [REG_NAMES[rt], f"{w & 0xFFFF}({REG_NAMES[rs]})"]
    elif op == 0x1C:
        if funct == 0x28:
            return "por", [REG_NAMES[rd], REG_NAMES[rs], REG_NAMES[rt]]
        elif funct == 0x29:
            return "pnor", [REG_NAMES[rd], REG_NAMES[rs], REG_NAMES[rt]]
        elif funct == 0x2A:
            return "pand", [REG_NAMES[rd], REG_NAMES[rs], REG_NAMES[rt]]
        elif funct == 0x2B:
            return "pxor", [REG_NAMES[rd], REG_NAMES[rs], REG_NAMES[rt]]
    return None

def translate_inst(op, args):
    if op == "nop":
        return ""
    if op == "por":
        d, s, t = map_reg(args[0]), map_reg(args[1]), map_reg(args[2])
        if d == "0":
            return ""
        return f"{d} = (long)({s} | {t});"
    if op in ("addu", "add", "addiu"):
        d = map_reg(args[0])
        s = map_reg(args[1])
        imm_or_t = clean_token(args[2])
        if d == "0":
            return ""
        if imm_or_t.startswith("$") or imm_or_t in VALID_REGS:
            t = map_reg(imm_or_t)
            return f"{d} = (long)({s} + {t});"
        else:
            val = int(imm_or_t, 0)
            return f"{d} = (long)({s} + ({hex(val) if abs(val) > 9 else str(val)}));"
    if op in ("subu", "sub"):
        d, s, t = map_reg(args[0]), map_reg(args[1]), map_reg(args[2])
        if d == "0":
            return ""
        return f"{d} = (long)({s} - {t});"
    if op == "lui":
        d = map_reg(args[0])
        imm = int(clean_token(args[1]), 0)
        if d == "0":
            return ""
        return f"{d} = (long)({hex(imm)} << 16);"
    if op in ("ori", "or"):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t_val = clean_token(args[2])
        if d == "0":
            return ""
        if t_val.startswith("$") or t_val in VALID_REGS:
            return f"{d} = (long)({s} | {map_reg(t_val)});"
        val = int(t_val, 0)
        return f"{d} = (long)({s} | ({hex(val) if abs(val) > 9 else str(val)}));"
    if op in ("andi", "and"):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t_val = clean_token(args[2])
        if d == "0":
            return ""
        if t_val.startswith("$") or t_val in VALID_REGS:
            return f"{d} = (long)({s} & {map_reg(t_val)});"
        val = int(t_val, 0)
        return f"{d} = (long)({s} & ({hex(val) if abs(val) > 9 else str(val)}));"
    if op in ("xori", "xor"):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t_val = clean_token(args[2])
        if d == "0":
            return ""
        if t_val.startswith("$") or t_val in VALID_REGS:
            return f"{d} = (long)({s} ^ {map_reg(t_val)});"
        val = int(t_val, 0)
        return f"{d} = (long)({s} ^ ({hex(val) if abs(val) > 9 else str(val)}));"
    if op == "nor":
        d, s, t = map_reg(args[0]), map_reg(args[1]), map_reg(args[2])
        if d == "0":
            return ""
        return f"{d} = (long)(~({s} | {t}));"
    if op == "sll":
        d, s = map_reg(args[0]), map_reg(args[1])
        sh = int(clean_token(args[2]), 0)
        if d == "0":
            return ""
        return f"{d} = (long)((unsigned long){s} << ({sh}));"
    if op == "srl":
        d, s = map_reg(args[0]), map_reg(args[1])
        sh = int(clean_token(args[2]), 0)
        if d == "0":
            return ""
        return f"{d} = (long)((unsigned long){s} >> ({sh}));"
    if op == "sra":
        d, s = map_reg(args[0]), map_reg(args[1])
        sh = int(clean_token(args[2]), 0)
        if d == "0":
            return ""
        return f"{d} = (long)((long){s} >> ({sh}));"
    if op == "sllv":
        d, t, s = map_reg(args[0]), map_reg(args[1]), map_reg(args[2])
        if d == "0":
            return ""
        return f"{d} = (long)((unsigned long){t} << ({s} & 0x1F));"
    if op == "srlv":
        d, t, s = map_reg(args[0]), map_reg(args[1]), map_reg(args[2])
        if d == "0":
            return ""
        return f"{d} = (long)((unsigned long){t} >> ({s} & 0x1F));"
    if op == "srav":
        d, t, s = map_reg(args[0]), map_reg(args[1]), map_reg(args[2])
        if d == "0":
            return ""
        return f"{d} = (long)((long){t} >> ({s} & 0x1F));"
    if op == "slt":
        d, s, t = map_reg(args[0]), map_reg(args[1]), map_reg(args[2])
        if d == "0":
            return ""
        return f"{d} = (long)((long){s} < (long){t} ? 1 : 0);"
    if op == "sltu":
        d, s, t = map_reg(args[0]), map_reg(args[1]), map_reg(args[2])
        if d == "0":
            return ""
        return f"{d} = (long)((unsigned long){s} < (unsigned long){t} ? 1 : 0);"
    if op == "slti":
        d, s = map_reg(args[0]), map_reg(args[1])
        imm = int(clean_token(args[2]), 0)
        if d == "0":
            return ""
        return f"{d} = (long)((long){s} < (long)({hex(imm) if abs(imm)>9 else str(imm)}) ? 1 : 0);"
    if op == "sltiu":
        d, s = map_reg(args[0]), map_reg(args[1])
        imm = int(clean_token(args[2]), 0)
        if d == "0":
            return ""
        return f"{d} = (long)((unsigned long){s} < (unsigned long)({hex(imm) if abs(imm)>9 else str(imm)}) ? 1 : 0);"
    if op in ("lw", "lhu", "lh", "lbu", "lb", "ld", "lwu", "lq"):
        d = map_reg(args[0])
        off, base = decode_mem_arg(args[1])
        type_map = {
            "lw": "int",
            "lhu": "unsigned short",
            "lh": "short",
            "lbu": "unsigned char",
            "lb": "char",
            "ld": "long",
            "lwu": "unsigned int",
            "lq": "long"
        }
        t = type_map[op]
        if d == "0":
            return ""
        return f"if ({base}) {{ {d} = *({t} *)((char *){base} + ({off})); }}"
    if op in ("sw", "sh", "sb", "sd", "sq"):
        s = map_reg(args[0])
        off, base = decode_mem_arg(args[1])
        type_map = {
            "sw": "int",
            "sh": "short",
            "sb": "char",
            "sd": "long",
            "sq": "long"
        }
        t = type_map[op]
        return f"if ({base}) {{ *({t} *)((char *){base} + ({off})) = ({t}){s}; }}"
    if op in ("movn",):
        d, s, t = map_reg(args[0]), map_reg(args[1]), map_reg(args[2])
        return f"if ({t} != 0) {d} = {s};"
    if op in ("movz",):
        d, s, t = map_reg(args[0]), map_reg(args[1]), map_reg(args[2])
        return f"if ({t} == 0) {d} = {s};"
    if op in ("sync", "pref"):
        return ""
    return f"/* unhandled: {op} {' '.join(args)} */"

def main():
    md = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_LITTLE_ENDIAN)

    import subprocess
    content = subprocess.check_output(["git", "show", "HEAD~1:src/thelp_overlay.c"], text=True)

    matches = re.findall(r'/\*\s*(thelp_func_[0-9A-Fa-f]+)\s*\(VMA:\s*(0x[0-9A-Fa-f]+),\s*size\s*([0-9]+)\s*bytes.*?\*/(.*?)(?=(?:/\*\s*thelp_func_|\/\*\s*THELP_CD|\Z))', content, re.DOTALL)
    print(f"Translating {len(matches)} thelp functions...")

    fn_addrs = [int(vma, 16) for _, vma, _, _ in matches]
    fn_name_by_addr = {int(vma, 16): name for name, vma, _, _ in matches}

    out = []
    out.append("/* Age of Empires II PS2 - THELP_CD.BIN Overlay */")
    out.append("#include \"common.h\"")
    out.append("#include \"thelp_overlay.h\"")
    out.append("")
    out.append("/* External mock prototypes for external calls */")

    all_external_calls = set()

    fn_codes = []

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

        c_lines = []
        c_lines.append(f"/* Function {cur_fn_idx+1}: {fn_name} (VMA: {vma_str}, size: {len(words)*4} bytes) */")
        c_lines.append(f"void *{fn_name}(void *a0, void *a1, void *a2, void *a3) {{")
        c_lines.append("    long r_v0 = 0, r_v1 = 0;")
        c_lines.append("    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;")
        c_lines.append("    long r_ra = 0, r_gp = 0;")

        other_regs = sorted(list(used_regs - {"r_v0", "r_v1", "r_a0", "r_a1", "r_a2", "r_a3"}))
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

        # Check if function ends with return
        has_explicit_term = False
        for l in reversed(c_lines):
            l_strip = l.strip()
            if l_strip.startswith("return") or l_strip.startswith("goto"):
                has_explicit_term = True
                break
            elif l_strip and not l_strip.startswith("/*"):
                break

        if not has_explicit_term and cur_fn_idx + 1 < len(matches):
            next_fn_name = matches[cur_fn_idx + 1][0]
            c_lines.append(f"    return {next_fn_name}((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);")
        else:
            c_lines.append("    return (void *)r_v0;")

        c_lines.append("}")
        c_lines.append("")
        fn_codes.append("\n".join(c_lines))

    # Add external prototypes
    for ext in sorted(all_external_calls):
        out.append(f"extern void *{ext}(void *a0, void *a1, void *a2, void *a3);")
    out.append("")

    # Include .rodata table from thelp_data.inc
    out.append("/* Data and Read-Only Tables (.rodata: 320 bytes) */")
    out.append("const unsigned int thelp_data[THELP_DATA_WORD_COUNT] = {")
    out.append("#include \"thelp_data.inc\"")
    out.append("};")
    out.append("")

    out.extend(fn_codes)

    with open(SRC_PATH, "w") as f:
        f.write("\n".join(out) + "\n")

    # Generate header include/thelp_overlay.h
    header_path = ROOT / "include/thelp_overlay.h"
    hdr_lines = [
        "#ifndef THELP_OVERLAY_H",
        "#define THELP_OVERLAY_H",
        "",
        "#include \"common.h\"",
        "",
        "#define THELP_DATA_WORD_COUNT 80",
        "#define THELP_DATA_BYTE_SIZE  320",
        "",
        "extern const unsigned int thelp_data[THELP_DATA_WORD_COUNT];",
        "",
        "/* THELP_CD.BIN Overlay Function Prototypes */",
    ]
    for fn_name, _, _, _ in matches:
        hdr_lines.append(f"void *{fn_name}(void *a0, void *a1, void *a2, void *a3);")
    hdr_lines.append("")
    hdr_lines.append("#endif /* THELP_OVERLAY_H */\n")

    with open(header_path, "w") as f:
        f.write("\n".join(hdr_lines))

    print(f"Done. thelp_overlay.c decompiled completely ({len(matches)} functions)!")

if __name__ == "__main__":
    main()
