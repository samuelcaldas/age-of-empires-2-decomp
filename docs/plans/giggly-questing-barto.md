# Plan: Decompile `kt_libcdvd_server.c` to C/C++

## Context

`src/kt_libcdvd_server.c` preserves 150 KCET CD/DVD server routines as embedded MIPS assembly. The requested outcome is readable C/C++ implementations that retain verified behavior and target matching. The whole module is the proposed scope because no function subset was specified. The GPU source is not the target; `kt_gpu.c` and `kt_mouse.c` are references for native C conventions only.

The current matching test covers 14,104 bytes from `0x1295D0` through `0x12CCE8`, while `docs/asm_to_c_migration_map.md` lists 14,072 bytes. Resolve this discrepancy against the original ELF and verified symbol boundaries before using either extent as a gate.

## Approach

1. **Establish and document the baseline.** Read `docs/testing.md`, inspect the existing test and relevant binary evidence, and run `python -m pytest -q -ra tests/test_kt_libcdvd_server_matching.py` in the documented `docker-dev` test container. Record compiler, original ELF, and wrapper availability; do not treat skips as passing evidence.
2. **Map behavior and dependencies.** Inventory the 150 functions, exact boundaries, calls, data references, shared state, and calling-convention assumptions. Use the original ELF/disassembly as behavioral evidence. Group routines by subsystem and dependency so each conversion slice stays testable.
3. **Add tests before each behavior change.** For each independently observable slice, first add focused native tests derived from binary evidence. Exercise outputs, state changes, call order, boundary inputs, and failure paths. Run them against the unchanged assembly-backed baseline and record genuine expected assertion failures; missing tools or collection errors are blockers, not red evidence.
4. **Convert incrementally to C/C++.** Replace assembly for one coherent group at a time, retaining externally visible symbols, signatures, data layout, side effects, and target-specific integer semantics. Use `src/kt_mouse.c` and `src/kt_gpu.c` for project C style. Keep the original assembly comparison as an independent exact-matching gate; investigate compiler/code-generation differences instead of weakening checks.
5. **Update tracking and verify.** Update `docs/asm_to_c_migration_map.md` as verified groups move to C/C++, and correct the module extent only after ELF evidence confirms it. Retain behavior tests with the change. Run focused native and matching tests, affected subsystem tests, then the full suite. Report every failure, skip, unavailable prerequisite, and exact-match result.

## Critical files

- `src/kt_libcdvd_server.c` — assembly-backed routines to convert.
- `tests/test_kt_libcdvd_server_matching.py` — existing exact `.text` comparison and relocation patching; validate its extent and assumptions before relying on it.
- New focused native test(s) following existing `tests/native/` and pytest conventions, added slice by slice.
- `docs/asm_to_c_migration_map.md` — module status and verified extent.
- `docs/testing.md` — mandatory test and evidence requirements.
- `src/kt_mouse.c`, `src/kt_gpu.c` — native C style references.

## Verification and prerequisites

- Focused target comparison: `python -m pytest -q -ra tests/test_kt_libcdvd_server_matching.py`.
- Focused native tests: add the new module test node(s) to the command above.
- Follow `docs/testing.md` for execution inside the `docker-dev` test container, then run affected/subsystem tests and `python -m pytest -q -ra`.
- Exact matching requires `compilers/PS2/ee-gcc2.9-991111/bin/ee-gcc.exe`, `build/tools/wibo`, and `orig/SLES-50282/AOK.ELF`. Missing prerequisites must be reported as blockers or skips, never as successful matching.
- Confirm the 14,104-byte test range versus the 14,072-byte migration-map entry against the original ELF before conversion or test updates.
