# AoE2 Decompilation Rules & Guidelines

These operational rules apply to all decompilation, refactoring, and test activities in this repository.

## 1. Matching Priority & Verification
- **Dual-Gate Quality:** Every function must satisfy two distinct gates:
  1. **Binary Matching:** Target compiler output comparison via `ninja` and `objdiff`.
  2. **Behavioral Correctness:** Native behavioral tests via `pytest` (compiled with `g++ -m32`).
- Matching C/C++ output is the ultimate source of truth. Never accept changes that improve cosmetic readability if they regress binary matching.
- Do not use raw inline assembly hacks (`asm`, `__asm__`) or compiler-specific pragmas to force matching, unless strictly guarded by `#if defined(__mips__)`.
- Maintain exact comments and memory address markers (`/* 0x00125A70 */`). Downstream tools rely on them.

## 2. Mandatory Test-Driven Development (TDD)
- **Red:** Write the smallest behavioral regression test in `tests/` before modifying or implementing a function. Observe the expected assertion failure.
- **Green:** Implement the minimal clean C/C++ code required to pass the test.
- **Refactor:** Improve types, structure layout, and documentation while keeping all tests passing.
- **Full Suite Gate:** Run affected tests and the relevant subsystem suite before submitting any change.

## 3. Recomp-Ready & Shim Standards
When decompiling or refining modules (especially KCET PS2 HAL layers in `src/kcet/`):
- **Fixed-Layout Structs:** Replace raw pointer arithmetic (`*(int *)(ptr + 0x6C)`) with named fields in `struct`, guarded by `_Static_assert(sizeof(...) == ...)` and `offsetof` assertions.
- **Fixed-Width Types:** Always use `u8`, `u16`, `u32`, `s32`, `u64`. Use `GuestAddr` (typedef `u32`) for 32-bit guest addresses to prevent 64-bit host pointer discrepancies.
- **Symbolic References:** Replace magic hardcoded memory addresses with typed `extern` declarations (`D_XXXXXX`).
- **YAML Sidecars:** Document function roles, purity, blocking behavior, arguments, and memory effects in `docs/recomp/<module>.yaml`.

## 4. Code Style & Environment
- Target standard: C++03, 150-column limit, formatted via `.clang-format`.
- Test execution environment:
  - Local virtualenv: `pytest -q -ra tests/<test_file>.py`
  - Docker dev environment: `docker --context docker-dev run --rm -e TZ=America/Sao_Paulo --mount "type=bind,source=$(pwd),target=/workspace" aoe-tests:verification python -m pytest -q -ra`
