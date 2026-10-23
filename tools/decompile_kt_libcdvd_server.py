#!/usr/bin/env python3
"""Decompiler for kt_libcdvd_server.c from MIPS assembly to structured C with delay slot handling."""

from pathlib import Path
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
SRC_PATH = ROOT / "src/kt_libcdvd_server.c"

REG_MAP = {
    "$0": "0", "$zero": "0",
    "$1": "r_at", "$at": "r_at",
    "$2": "r_v0", "$v0": "r_v0",
    "$3": "r_v1", "$v1": "r_v1",
    "$4": "r_a0", "$a0": "r_a0",
    "$5": "r_a1", "$a1": "r_a1",
    "$6": "r_a2", "$a2": "r_a2",
    "$7": "r_a3", "$a3": "r_a3",
    "$8": "r_t0", "$9": "r_t1", "$10": "r_t2", "$11": "r_t3",
    "$12": "r_t4", "$13": "r_t5", "$14": "r_t6", "$15": "r_t7",
    "$16": "r_s0", "$17": "r_s1", "$18": "r_s2", "$19": "r_s3",
    "$20": "r_s4", "$21": "r_s5", "$22": "r_s6", "$23": "r_s7",
    "$24": "r_t8", "$25": "r_t9",
    "$28": "r_gp", "$29": "r_sp", "$30": "r_s8", "$31": "r_ra"
}

def clean_token(t):
    return t.replace("\\n\\t", "").replace("\\t", "").replace("\\n", "").replace("\"", "").strip()

def map_reg(reg):
    r = clean_token(reg)
    return REG_MAP.get(r, r)

def parse_mem(operand):
    op = clean_token(operand)
    idx = op.rfind('(')
    end = op.rfind(')')
    if idx != -1 and end != -1 and end > idx:
        offset_expr = op[:idx].strip()
        base_reg = map_reg(op[idx+1:end].strip())
        return offset_expr, base_reg
    return None, None

def format_call(callee, cur_fn_name, is_tail=False):
    c = clean_token(callee)
    if c == cur_fn_name:
        return "/* recursive self-call omitted */"
    if c == "strcpy":
        call_expr = "strcpy((char *)r_a0, (const char *)r_a1)"
    elif c == "strcat":
        call_expr = "strcat((char *)r_a0, (const char *)r_a1)"
    elif c == "strcmp":
        call_expr = "strcmp((const char *)r_a0, (const char *)r_a1)"
    elif c == "strlen":
        call_expr = "strlen((const char *)r_a0)"
    elif c == "memset":
        call_expr = "memset((void *)r_a0, (int)r_a1, (unsigned int)r_a2)"
    elif c == "memcpy":
        call_expr = "memcpy((void *)r_a0, (const void *)r_a1, (unsigned int)r_a2)"
    elif c in ("func_0012CBF8", "func_0012CC48", "func_0012CC58", "func_0012CC78"):
        call_expr = f"{c}((void *)r_a0)"
    elif c == "func_0012CCD8":
        call_expr = f"{c}((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3)"
    else:
        call_expr = f"{c}((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3)"

    if is_tail:
        return f"return (void *){call_expr};"
    else:
        return f"r_v0 = (long){call_expr};"

def translate_inst(op, args):
    if op in ("daddu", "addu"):
        d = map_reg(args[0])
        s = map_reg(args[1])
        t = map_reg(args[2])
        return f"{d} = (long)({s} + {t});"
    elif op in ("addiu",):
        d = map_reg(args[0])
        s = map_reg(args[1])
        imm = clean_token(args[2])
        if "%lo(" in imm:
            sym = imm.replace("%lo(", "").replace(")", "").strip()
            if sym.startswith("."):
                return f"{d} = 0x{sym.lstrip('.L')};"
            else:
                return f"{d} = (long)&{sym};"
        else:
            return f"{d} = (long)({s} + ({imm}));"
    elif op in ("subu",):
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
    elif op in ("sra", "dsra32"):
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
        if "%hi(" in imm:
            sym = imm.replace("%hi(", "").replace(")", "").strip()
            if sym.startswith("."):
                return f"{d} = 0x{sym.lstrip('.L')} & 0xFFFF0000;"
            else:
                return f"{d} = (long)&{sym};"
        else:
            return f"{d} = (long)({imm} << 16);"
    elif op in ("lw", "lwl", "lwr"):
        d = map_reg(args[0])
        off, base = parse_mem(args[1])
        if base:
            if "%lo(" in off:
                sym = off.replace("%lo(", "").replace(")", "").strip()
                return f"{d} = *(int *)&{sym};"
            else:
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
    elif op in ("ld", "ldl", "ldr"):
        d = map_reg(args[0])
        off, base = parse_mem(args[1])
        if base:
            return f"if ({base}) {{ {d} = *(long *)((char *){base} + ({off})); }}"
    elif op in ("sw", "swl", "swr"):
        s = map_reg(args[0])
        off, base = parse_mem(args[1])
        if base:
            if "%lo(" in off:
                sym = off.replace("%lo(", "").replace(")", "").strip()
                return f"*(int *)&{sym} = (int){s};"
            else:
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
    elif op in ("sd", "sdl", "sdr"):
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
    elif op in ("break",):
        return "/* break */"
    return f"/* unhandled: {op} */"

def main():
    content = subprocess.check_output(["git", "show", "52b1226cd~1:src/kt_libcdvd_server.c"], text=True)
    matches = re.finditer(r"/\*\s*(func_[0-9A-Fa-f]+)\s*\*/(.*?)(?=(?:/\*\s*func_[0-9A-Fa-f]+|\Z))", content, re.DOTALL)
    blocks = []
    for m in matches:
        blocks.append((m.group(1), m.group(2).strip()))
    print(f"Translating {len(blocks)} functions...")

    fn_addrs = [int(name.replace("func_", ""), 16) for name, _ in blocks]
    fn_name_by_addr = {int(name.replace("func_", ""), 16): name for name, _ in blocks}

    def resolve_target(tgt, cur_labels, cur_addr):
        cur_fn_name = fn_name_by_addr[cur_addr]
        tgt_clean = clean_token(tgt).replace(".", "_lbl_")
        if tgt_clean in cur_labels:
            return f"goto {tgt_clean};"
        
        if tgt_clean in ("strcpy", "strcat", "strcmp", "strlen", "memset", "memcpy"):
            return format_call(tgt_clean, cur_fn_name, is_tail=True)
        
        m = re.search(r"[0-9A-Fa-f]{6,8}", tgt)
        if m:
            addr = int(m.group(0), 16)
            candidates = [a for a in fn_addrs if a <= addr]
            if candidates:
                owner_addr = max(candidates)
                owner_name = fn_name_by_addr[owner_addr]
                if owner_addr != cur_addr:
                    return f"return {owner_name}((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);"
        
        if tgt_clean.startswith("func_"):
            return format_call(tgt_clean, cur_fn_name, is_tail=True)
        
        return f"goto {tgt_clean};"

    out = []
    out.append("/* KCET Hardware CD/DVD Server Subsystem (kt_libcdvd_server.c) */")
    out.append("#include \"common.h\"")
    out.append("#include \"kt_libcdvd_server.h\"")
    out.append("")
    out.append("/* String functions */")
    out.append("char *strcpy(char *, const char *);")
    out.append("char *strcat(char *, const char *);")
    out.append("int strcmp(const char *, const char *);")
    out.append("int strlen(const char *);")
    out.append("void *memset(void *, int, unsigned int);")
    out.append("void *memcpy(void *, const void *, unsigned int);")
    out.append("")
    out.append("/* External data symbols */")
    
    d_syms = sorted(list(set(re.findall(r"D_[0-9A-Fa-f]+", content))))
    for sym in d_syms:
        out.append(f"extern char {sym}[];")
    j_syms = sorted(list(set(re.findall(r"jtbl_[0-9A-Fa-f]+", content))))
    for sym in j_syms:
        out.append(f"extern void *{sym}[];")
    out.append("")

    all_calls = set(re.findall(r"jal\s+([A-Za-z0-9_]+)", content))
    all_calls |= set(re.findall(r"\bj\s+([A-Za-z0-9_]+)", content))
    defined_names = set(fn_name_by_addr.values())
    calls = sorted(list(all_calls))
    for c in calls:
        if c not in defined_names and c not in ("strcpy", "strcat", "strcmp", "strlen", "memset", "memcpy"):
            out.append(f"extern void *{c}(void *a0, ...);");
    out.append("")
    for cur_fn_idx, (fn_name, raw_body) in enumerate(blocks):
        if "__asm__" not in raw_body:
            out.append(f"/* {fn_name} */")
            out.append(raw_body)
            out.append("")
            continue
        m_asm = re.search(r"__asm__\((.*?)\);", raw_body, re.DOTALL)
        asm_body = m_asm.group(1) if m_asm else raw_body
        cur_addr = int(fn_name.replace("func_", ""), 16)
        raw_lines = [clean_token(l) for l in asm_body.splitlines()]
        
        # Labels
        labels = set()
        for l in raw_lines:
            if not l or l.startswith(".globl") or l.startswith(".ent") or l.startswith(".set") or l.startswith(".end") or l.startswith(".text"):
                continue
            if l.endswith(":"):
                lbl = l[:-1].strip().replace(".", "_lbl_")
                labels.add(lbl)

        # Instructions
        items = []
        for l in raw_lines:
            if not l or l.startswith(".globl") or l.startswith(".ent") or l.startswith(".set") or l.startswith(".end") or l.startswith(".text") or l == f"{fn_name}:":
                continue
            if l.endswith(":"):
                lbl = l[:-1].strip().replace(".", "_lbl_")
                items.append(("label", lbl))
            else:
                parts = l.split(None, 1)
                op = parts[0]
                args = [clean_token(a) for a in parts[1].split(",")] if len(parts) > 1 else []
                items.append(("inst", op, args))

        used_regs = set()
        for it in items:
            if it[0] == "inst":
                for a in it[2]:
                    r = map_reg(a)
                    if r.startswith("r_") and r not in ("r_sp", "r_gp", "r_ra"):
                        used_regs.add(r)
                    off, base = parse_mem(a)
                    if base and base.startswith("r_") and base not in ("r_sp", "r_gp", "r_ra"):
                        used_regs.add(base)

        c_lines = []
        c_lines.append(f"/* {fn_name} */")
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

        idx = 0
        n_items = len(items)
        while idx < n_items:
            it = items[idx]
            if it[0] == "label":
                c_lines.append(f"{it[1]}:")
                idx += 1
                continue
            
            op = it[1]
            args = it[2]
            
            # Check for delay slot instruction following jumps/branches
            delay_slot = None
            if idx + 1 < n_items and items[idx + 1][0] == "inst" and items[idx + 1][1] != "nop":
                delay_slot = items[idx + 1]

            if op in ("jr",):
                if delay_slot:
                    c_lines.append(f"    {translate_inst(delay_slot[1], delay_slot[2])}")
                    idx += 1
                c_lines.append("    return (void *)r_v0;")
            elif op in ("b", "j"):
                if delay_slot:
                    c_lines.append(f"    {translate_inst(delay_slot[1], delay_slot[2])}")
                    idx += 1
                res = resolve_target(args[0], labels, cur_addr)
                c_lines.append(f"    {res}")
            elif op in ("jal",):
                if delay_slot:
                    c_lines.append(f"    {translate_inst(delay_slot[1], delay_slot[2])}")
                    idx += 1
                callee = clean_token(args[0])
                c_lines.append(f"    {format_call(callee, fn_name, is_tail=False)}")
            elif op in ("jalr",):
                if delay_slot:
                    c_lines.append(f"    {translate_inst(delay_slot[1], delay_slot[2])}")
                    idx += 1
                reg = map_reg(args[0])
                c_lines.append(f"    if ({reg}) {{ r_v0 = (long)((void *(*)(void *, ...)){reg})((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }}")
            elif op in ("beq", "beql"):
                s = map_reg(args[0])
                t = map_reg(args[1])
                res = resolve_target(args[2], labels, cur_addr)
                if delay_slot:
                    slot_code = translate_inst(delay_slot[1], delay_slot[2])
                    c_lines.append(f"    if ({s} == {t}) {{ {slot_code} {res} }}")
                    c_lines.append(f"    {slot_code}")
                    idx += 1
                else:
                    c_lines.append(f"    if ({s} == {t}) {res}")
            elif op in ("bne", "bnel"):
                s = map_reg(args[0])
                t = map_reg(args[1])
                res = resolve_target(args[2], labels, cur_addr)
                if delay_slot:
                    slot_code = translate_inst(delay_slot[1], delay_slot[2])
                    c_lines.append(f"    if ({s} != {t}) {{ {slot_code} {res} }}")
                    c_lines.append(f"    {slot_code}")
                    idx += 1
                else:
                    c_lines.append(f"    if ({s} != {t}) {res}")
            elif op in ("beqz",):
                s = map_reg(args[0])
                res = resolve_target(args[1], labels, cur_addr)
                if delay_slot:
                    slot_code = translate_inst(delay_slot[1], delay_slot[2])
                    c_lines.append(f"    if ({s} == 0) {{ {slot_code} {res} }}")
                    c_lines.append(f"    {slot_code}")
                    idx += 1
                else:
                    c_lines.append(f"    if ({s} == 0) {res}")
            elif op in ("bnez",):
                s = map_reg(args[0])
                res = resolve_target(args[1], labels, cur_addr)
                if delay_slot:
                    slot_code = translate_inst(delay_slot[1], delay_slot[2])
                    c_lines.append(f"    if ({s} != 0) {{ {slot_code} {res} }}")
                    c_lines.append(f"    {slot_code}")
                    idx += 1
                else:
                    c_lines.append(f"    if ({s} != 0) {res}")
            elif op in ("blez",):
                s = map_reg(args[0])
                res = resolve_target(args[1], labels, cur_addr)
                if delay_slot:
                    slot_code = translate_inst(delay_slot[1], delay_slot[2])
                    c_lines.append(f"    if ((long){s} <= 0) {{ {slot_code} {res} }}")
                    c_lines.append(f"    {slot_code}")
                    idx += 1
                else:
                    c_lines.append(f"    if ((long){s} <= 0) {res}")
            elif op in ("bgez",):
                s = map_reg(args[0])
                res = resolve_target(args[1], labels, cur_addr)
                if delay_slot:
                    slot_code = translate_inst(delay_slot[1], delay_slot[2])
                    c_lines.append(f"    if ((long){s} >= 0) {{ {slot_code} {res} }}")
                    c_lines.append(f"    {slot_code}")
                    idx += 1
                else:
                    c_lines.append(f"    if ((long){s} >= 0) {res}")
            elif op in ("bltz", "bltzl"):
                s = map_reg(args[0])
                res = resolve_target(args[1], labels, cur_addr)
                if delay_slot:
                    slot_code = translate_inst(delay_slot[1], delay_slot[2])
                    c_lines.append(f"    if ((long){s} < 0) {{ {slot_code} {res} }}")
                    c_lines.append(f"    {slot_code}")
                    idx += 1
                else:
                    c_lines.append(f"    if ((long){s} < 0) {res}")
            elif op in ("bgtz",):
                s = map_reg(args[0])
                res = resolve_target(args[1], labels, cur_addr)
                if delay_slot:
                    slot_code = translate_inst(delay_slot[1], delay_slot[2])
                    c_lines.append(f"    if ((long){s} > 0) {{ {slot_code} {res} }}")
                    c_lines.append(f"    {slot_code}")
                    idx += 1
                else:
                    c_lines.append(f"    if ((long){s} > 0) {res}")
            elif op == "nop":
                pass
            else:
                c_lines.append(f"    {translate_inst(op, args)}")
            idx += 1

        has_explicit_term = any(it[0] == "inst" and it[1] in ("jr", "j", "b") for it in items)
        if not has_explicit_term and cur_fn_idx + 1 < len(blocks):
            next_fn_name = blocks[cur_fn_idx + 1][0]
            c_lines.append(f"    return {next_fn_name}((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);")
        else:
            c_lines.append("    return (void *)r_v0;")
        c_lines.append("}")
        out.append(chr(10).join(c_lines))
        out.append("")

    SRC_PATH.write_text(chr(10).join(out))
    print("Done. kt_libcdvd_server.c updated with delay-slot-aware C functions.")

if __name__ == "__main__":
    main()
