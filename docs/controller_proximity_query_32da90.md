# Combat subsystem controller proximity query at 0x32DA90

`func_0032DA90` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_proximity_query.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 148-byte candidate prefix matching 28 of 148 candidate-prefix
bytes against the original binary prefix, with 1,456 bytes unimplemented remainder of the 1,604 target bytes
(classified strictly as NonMatching), scoping 8 ABI parameter registers, `out_status` zeroing on entry,
null-self / null-vtable / null-pointer safety guards, `func_120` virtual dispatch with `(10, 30, 15, 4, 1)`, and early exit gate routing.
Remaining complex inner proximity grid scans and entity slot traversals are unmodeled in this partial slice.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032DA90 = 0x32DA90; // type:func size:0x640 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent:
  - Canonical `symbols.txt` records `size: 0x640` (1,600 bytes), ending at `0x32E0D0` (after `jr $ra` at `0x32E0CC`).
  - True executable code boundary spans VRAM `[0x32DA90, 0x32E0D4)` (1,604 bytes, `0x644`, 401 instructions),
    enclosing the return delay slot instruction `addiu $sp, $sp, 1552` (`0x27BD0610`) at `0x32E0D0`.
  - File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022DC70, 0x0022E2B4)`.
- Predecessor continuity: directly preceded by `func_0032D400` ending at `0x32DA88` (`0x0022DC68`).
  Between `0x32DA88` and `0x32DA90`: exactly 8 bytes alignment padding `nop nop` (`0x00000000 0x00000000`).
  Zero overlap.
- Successor continuity: directly followed by `func_0032E0E0` starting at `0x32E0E0` (`0x0022E2C0`),
  size `0x138` (312 bytes).
  Between `0x32E0D4` and `0x32E0E0`: exactly 12 bytes alignment padding `nop nop nop` (`0x00000000 0x00000000 0x00000000`).
  Zero unclassified bytes, zero overlap.
- Stack frame: 1,552 bytes (`addiu $sp, $sp, -1552` = `0x27BDF9F0` at `0x32DA90`), saving `$ra` (160) and
  callee-saved registers `$s0`–`$s7`, `$fp` via quadword stores `sq`.
  Epilogue: `jr $ra` at `0x32E0CC` (+0x63C) and delay slot stack teardown `addiu $sp, $sp, 1552` at `0x32E0D0` (+0x640).

## Relocation manifest

### Compiled candidate relocations (0 relocations)
The 148-byte candidate object resolves 0 relocations (all calls are indirect virtual dispatches through `m_vtable->func_120`).

### Full ELF function relocations (2 relocations)
The full 1,604-byte original binary function contains 2 relocations (both `R_MIPS_26`, 0 `R_MIPS_GPREL16`):
1. `+0x138` (0x32DBC8): `R_MIPS_26` to `func_117AF8`
2. `+0x15C` (0x32DBEC): `R_MIPS_26` to `func_117AF8`

## Observable behavior (Implemented Partial Scope)

1. Argument unpacking:
   - Receives 8 ABI arguments in registers (`$a0`–`$a3`, `$t0`–`$t3`).
   - If `out_status` (`$a3`) is non-null, zeroes `*out_status = 0`.
2. Virtual method dispatch:
   - If `self == 0 || self->m_vtable == 0 || self->m_vtable->func_120 == 0`, returns 0.
   - Dispatches virtual method `self->m_vtable->func_120(self, x, y, 10, 30, 15, 4, 1)`.
3. Early exit gate:
   - If `func_120` returns 0, returns 0 immediately.
4. Success path:
   - If `out_status` is non-null, sets `*out_status = 1`.
   - Returns 1.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_proximity_query_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_proximity_query.cpp` returning -1.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_proximity_query.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_proximity_query_test.cpp -o build/test_prox_query_red \
       && ./build/test_prox_query_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: func_120 zero return must return 0` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ partial proximity query evaluator in `src/tactical_ai_combat_subsystem_controller_proximity_query.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_proximity_query.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_proximity_query_test.cpp -o build/test_prox_query_green \
       && ./build/test_prox_query_green
     ```
   - Result: All 7 fixtures passing cleanly (`zero_return`, `null_status`, `null_self`, `null_vtable`, `null_func120`, `trailing_args`, `hit_return`), exit code 0 under UBSan.
   - Defensive null guards are included for harness isolation and memory safety under native tests, not claimed as verified original binary behavior.
   - Verified 12 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_proximity_query.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 148 bytes (1,456 bytes unimplemented remainder of 1,604 target bytes).
   - Relocations resolved: 0 compiled relocations mapped and verified with multiset check.
   - Classified strictly as **NonMatching** (28 of 148 candidate-prefix matching bytes against original prefix).
   - The matching test serves as a structural correspondence diagnostic asserting >=25 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_proximity_query.py \
  tests/test_tactical_ai_combat_subsystem_controller_proximity_query_matching.py
```

The focused test run comprises **14 total tests** (13 behavioral tests in `test_tactical_ai_combat_subsystem_controller_proximity_query.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_proximity_query_matching.py`):
- One 32-bit native contract test with UBSan validating 8 ABI arguments, out_status zeroing, null guards, trailing argument safety, func_120 virtual dispatch,
  and hit return value.
- Twelve production source mutations independently compiled and verified
  rejected (out_status zero, null-self guard, null-vtable guard, null-func120 guard, func_120 gate, 5 virtual arguments, out_status hit update, hit return value).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
