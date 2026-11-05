---
name: ps2-decomp
description: Programmatic and idempotent pipeline for PS2 MIPS decompilation. Covers staging C/C++ drafts, compiling with PS2 MWCC, diffing against original ELF bytes (relocation-aware), and promoting 100% bit-matched functions into the codebase.
---

# ps2-decomp

Automated, idempotent decompilation workflow for PlayStation 2 (`SLES-50282`).
Read [docs/decomp_pipeline.md](../../../docs/decomp_pipeline.md) and
[docs/recomp_ready_decomp_guidelines.md](../../../docs/recomp_ready_decomp_guidelines.md).

## Operational Rules

1. **Staging Isolation:** Draft files must reside in `staging/` (`staging/<func_name>.cpp`).
   Never register unverified or non-matching code directly into `configure.py`.
2. **Deterministic Matching Gate:** A function is only considered complete when it attains
   **100% bit-match** against the original ELF range, with relocations resolved.
3. **Recomp-Ready Structuring:**
   - Use fixed-width types (`u8`, `u16`, `u32`, `s32`, `u64`).
   - Replace raw pointer offsets (`*(int *)(p + 0x14)`) with structured, named `struct` layouts.
   - Maintain bit-match at 100% during all refactoring.

## Workflow Commands

Always execute through `.venv/bin/python scripts/decomp_pipeline.py`.

### 1. Stage draft
Creates an initial scaffolding in `staging/<func_name>.cpp`. Idempotent: existing edits are preserved.
```sh
.venv/bin/python scripts/decomp_pipeline.py stage \
  --func <func_name> \
  --vram <vram_hex> \
  --size <size_hex>
```

### 2. Compile draft
Compiles staging file with PS2 MWCC (`mwccps2.exe`) via `wibo`:
```sh
.venv/bin/python scripts/decomp_pipeline.py compile \
  --source staging/<func_name>.cpp
```

### 3. Diff and verify match
Calculates instruction match percentage and outputs mismatch offsets:
```sh
.venv/bin/python scripts/decomp_pipeline.py diff \
  --func <func_name> \
  --vram <vram_hex> \
  --size <size_hex> \
  --obj staging/<func_name>.o
```

### 4. Promote to official codebase
Once 100% match is reached, promotes source into `src/<module>/`, declares segment in `config/SLES-50282/config.yml`, adds symbol to `config/SLES-50282/symbols.txt`, and registers object in `configure.py`:
```sh
.venv/bin/python scripts/decomp_pipeline.py promote \
  --func <func_name> \
  --module <module> \
  --source staging/<func_name>.cpp \
  --header <header_name> \
  --vram <vram_hex> \
  --offset <file_offset_hex> \
  --size <size_hex>
```

### 5. Regression Gate
Always verify regression and matching tests before committing:
```sh
.venv/bin/pytest tests/test_decomp_pipeline.py
```
