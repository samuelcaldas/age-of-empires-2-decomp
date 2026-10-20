# Combat subsystem controller mode setter at 0x329350

`func_00329350` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_mode.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **256/256 instruction bytes (100.00%)**
after resolving relocations for `D_004E3180` (R_MIPS_GPREL16), `func_1880D0` (R_MIPS_26),
`func_184C10` (R_MIPS_26), `func_184BD0` (R_MIPS_26), `func_185DC0` (R_MIPS_26),
and `func_185F00` (R_MIPS_26).

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_00329350 = 0x329350; // type:func size:0x100 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function: VRAM `[0x329350, 0x329450)`, file `[0x229530, 0x229630)`.
  The function spans 256 instruction bytes (`0x100`). Symbol size is `0x100`.
- Stack frame: 48 bytes (`addiu $sp, $sp, -0x30`), saving `$ra` (0x20),
  `$s1` (0x10), and `$s0` (0x00) with 128-bit store instructions (`sq`).

## Observable behavior

1. Same-mode guard: if `a1 == self->m_field_3410`, return immediately.
2. Update state: `self->m_field_3410 = a1`.
3. Feature flag gate check: if `self->m_field_341C == 0`, return immediately.
4. Manager active check: if `func_1880D0(D_004E3180) == 0`, return immediately.
5. If `self->m_field_3410 != 0` (enable mode):
   - Query manager divisor: `s1 = func_184C10(D_004E3180)` (if 0, clamp to 1).
   - Query manager dividend: `v0 = func_184BD0(D_004E3180, 1)`.
   - Hardware division-by-zero trap check (`#pragma divbyzerocheck on`).
   - Ratio threshold check: if `v0 / s1 > 40`:
     - `self->m_field_3424 = a1 = 1`.
     - Check manager busy state: `func_185DC0(D_004E3180)`. If busy != 0, return.
     - Notify manager: `func_185F00(D_004E3180, 1, 1)`.
     - `self->m_field_3420 = 1`.
6. Else (disable mode):
   - Lock guard: if `self->m_field_342C != 0`, return immediately.
   - Clear `self->m_field_3424 = 0`.
   - If active `self->m_field_3420 != 0`:
     - Notify manager: `func_185F00(D_004E3180, 0, 0)`.
     - Clear `self->m_field_3420 = 0`.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_mode_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_mode.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_mode.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_mode_test.cpp -o build/test_mode_red \
       && ./build/test_mode_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: field_3410 must be updated even if gate is zero` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ mode setter in `src/tactical_ai_combat_subsystem_controller_mode.cpp`.
   - Verified clean compilation with `g++ -std=c++98 -Wall -Wextra -Werror` (exit code 0, zero warnings).
   - Recompiled and executed native fixture: passed cleanly with exit code 0 across all isolated sub-tests.
3. **Refactor & Hardening Stage:**
   - Added `#pragma divbyzerocheck on` for hardware division trap sequence matching.
   - Structured condition `v0 / s1 > 40` and assignment `self->m_field_3424 = a1 = 1` for exact register allocation.
   - Constrained relocation table parsing to reject duplicate offsets and strictly verify exact expected
     multiset of 12 relocations with unpatched word verification.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
.venv/bin/python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_mode.py \
  tests/test_tactical_ai_combat_subsystem_controller_mode_matching.py
```

The focused test run comprises **9 passing tests, zero skips**:

- One 32-bit native contract process with UBSan and NDEBUG protection validating
  same-mode guard, feature flag gate, manager active check, ratio threshold, busy manager handling,
  lock guard, and disable state notification.
- Seven production source mutations independently compiled and verified
  rejected with exact expected assertion diagnostics (corrupted same-mode guard, corrupted flag gate,
  corrupted manager active check, corrupted ratio threshold, corrupted busy check, corrupted locked
  check, corrupted notification arguments).
- One exact matching test compiling fresh with Ninja/MWCC and verifying
  100.00% byte-for-byte identity against the pinned ELF binary with canonical symbol boundary
  and duplicate-rejecting multiset relocation checks.
