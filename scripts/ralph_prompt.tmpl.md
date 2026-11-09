# Task: matching decompilation of one PS2 function (AoE2 SLES-50282)

Policy: inter-agent style. Terse, outcome first. Keep code, paths, hex exact.
Read first: CLAUDE.md, docs/recomp_ready_decomp_guidelines.md, docs/decomp_pipeline.md.

## Target
- Function: {{FUNC}}
- VRAM: {{VRAM}}  Size: {{SIZE}} bytes
- Write ONLY: {{STAGING_FILE}} (C++ for MWCC 2.3.1.01, flags: -O3 -inline on -msext on -char signed -sym off -lang=c++)
- Function symbol in the file must be named exactly `{{FUNC}}` (extern "C" if needed so the symbol is not mangled).

## Hard rules
- C/C++ only. No inline asm, no `.word` tricks, no empty stubs. Real logic.
- Use fixed-width types (u8/u16/u32/s32), typed structs instead of raw offsets.
- Goal: byte-exact match. Try #pragma options from memory notes (exceptions off for tail calls, inline_intrinsics, divbyzerocheck) when the diff shows them.
- Do not touch configure.py, config/, src/, symbols.txt. The loop promotes after measuring.
- Check yourself: `.venv/bin/python scripts/decomp_pipeline.py compile --source {{STAGING_FILE}}` then
  `.venv/bin/python scripts/ralph_slice.py measure --func {{FUNC}} --vram {{VRAM}} --size {{SIZE}} --obj {{STAGING_FILE_OBJ}}`
- Final reply: one line, outcome only.
- Only if the function cannot be written in C/C++ (syscall, COP0, hand-written asm, not compiler output): make the last
  line of your reply exactly `UNMATCHABLE: <reason>`. Do not use it for hard-to-match C.
{{HINTS_LINE}}

## Original bytes (little-endian words)
```
{{HEXDUMP}}
```

## Disassembly (capstone MIPS64; R5900 MMI/128-bit ops show as `.word`)
```
{{DISASM}}
```

## Known neighbouring symbols
```
{{NEIGHBOURS}}
```
{{FEEDBACK}}
