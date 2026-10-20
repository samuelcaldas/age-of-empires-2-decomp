# Combat subsystem controller instance constructor at 0x3291F0

`func_003291F0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_instance.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **164/164 instruction bytes (100.00%)**
after resolving relocations `func_318340` (R_MIPS_26) and `D_004DED20` (R_MIPS_HI16/LO16).

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_003291F0 = 0x3291F0; // type:func size:0xA4 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function: VRAM `[0x3291F0, 0x329294)`, file `[0x2293D0, 0x229474)`.
  The function spans 164 instruction bytes (`0xA4`), followed by 12 bytes of
  alignment-padding nops up to `0x3292A0`. Symbol size is `0xA4`.
- Stack frame: 32 bytes (`addiu $sp, $sp, -0x20`), saving `$ra` (0x10)
  and `$s0` (0x00) with 128-bit store instructions (`sq`).

## Observable behavior

1. Invoke base class constructor: `func_318340(self)`.
2. Install virtual method table: `self->m_vtable = D_004DED20`.
3. Initialize scalar instance fields:
   - `m_field_DC = 10`
   - `m_field_3408 = 0`, `m_field_340C = 0`, `m_field_3410 = 0`
   - `m_field_3414 = -1`, `m_field_3418 = -1`
   - `m_field_341C = 1`
   - `m_field_3420 = 0`, `m_field_3424 = 0`, `m_field_3428 = 0`, `m_field_342C = 0`, `m_field_3430 = 0`
4. Reset 10-slot tracking tables:
   - For `i = 0..9`: `m_field_3434[i] = 0`, `m_field_345C[i] = -1`
5. Initialize trailing attributes:
   - `m_field_3484 = 0`
   - `m_field_2398 = 41` (0x29)
6. Return `self` pointer.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_instance_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_instance.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_instance.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_instance_test.cpp -o build/test_controller_red \
       && ./build/test_controller_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: base constructor must be called exactly once` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ constructor in `src/tactical_ai_combat_subsystem_controller_instance.cpp`.
   - Recompiled and executed native fixture: passed cleanly with exit code 0 across all isolated sub-tests.
3. **Refactor & Hardening Stage:**
   - Added receiver pointer verification and call-order contract ensuring base constructor runs before
     vtable installation and field assignments.
   - Constrained relocation table parsing to reject duplicate offsets and strictly verify exact expected
     multiset `[(0x0C, 4, "func_318340"), (0x14, 5, "D_004DED20"), (0x18, 6, "D_004DED20")]`.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
.venv/bin/python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_instance.py \
  tests/test_tactical_ai_combat_subsystem_controller_instance_matching.py
```

The focused test run comprises **10 passing tests, zero skips**:

- One 32-bit native contract process with UBSan and NDEBUG protection validating
  receiver identity, base-before-vtable call order, vtable installation, scalar fields,
  slot table reset, and return value.
- Eight production source mutations independently compiled and verified
  rejected with exact expected assertion diagnostics (omitted base call, corrupted
  call order, corrupted vtable pointer, corrupted field DC, corrupted field 2398,
  corrupted scalar flag field 341C, corrupted zero table entry, corrupted negative table entry).
- One exact matching test compiling fresh with Ninja/MWCC and verifying
  100.00% byte-for-byte identity against the pinned ELF binary with canonical symbol boundary
  and duplicate-rejecting multiset relocation checks.
