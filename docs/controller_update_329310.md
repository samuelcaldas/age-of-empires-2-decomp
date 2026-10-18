# Combat subsystem controller update at 0x329310

`func_00329310` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_update.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **60/60 instruction bytes (100.00%)**
after resolving relocations `func_329550` (R_MIPS_26) and `func_1F4FA0` (R_MIPS_26).

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_00329310 = 0x329310; // type:func size:0x3C absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function: VRAM `[0x329310, 0x32934C)`, file `[0x2294F0, 0x22952C)`.
  The function spans 60 instruction bytes (`0x3C`), followed by 4 bytes of
  alignment-padding nop up to `0x329350`. Symbol size is `0x3C`.
- Stack frame: 32 bytes (`addiu $sp, $sp, -0x20`), saving `$ra` (0x10)
  and `$s0` (0x00) with 128-bit store instructions (`sq`).

## Observable behavior

1. Pre-hook call: invoke `func_329550(self)`.
2. Virtual method dispatch: invoke virtual function at vtable offset `0x140` (`self->func_138()`).
3. Post-hook call: invoke `func_1F4FA0(self)`.
4. Return (void).

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_update_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_update.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_update.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_update_test.cpp -o build/test_update_red \
       && ./build/test_update_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: expected exactly 3 update calls in trace` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ update sequence in `src/tactical_ai_combat_subsystem_controller_update.cpp`.
   - Recompiled and executed native fixture: passed cleanly with exit code 0 across all isolated sub-tests.
3. **Refactor & Hardening Stage:**
   - Constrained relocation table parsing to reject duplicate offsets and strictly verify exact expected
     multiset `[(0x0C, 4, "func_329550", 0x0C000000), (0x24, 4, "func_1F4FA0", 0x0C000000)]`.
   - Verified unpatched instruction words before relocation patching to prevent addend normalization.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
.venv/bin/python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_update.py \
  tests/test_tactical_ai_combat_subsystem_controller_update_matching.py
```

The focused test run comprises **9 passing tests, zero skips**:

- One 32-bit native contract process with UBSan and NDEBUG protection validating
  execution sequence, receiver pointer propagation, and call counts.
- Seven production source mutations independently compiled and verified
  rejected with exact expected assertion diagnostics (omitted pre-hook, omitted virtual call,
  omitted post-hook, swapped pre/virtual calls, swapped virtual/post calls, corrupted pre-hook
  receiver, corrupted post-hook receiver).
- One exact matching test compiling fresh with Ninja/MWCC and verifying
  100.00% byte-for-byte identity against the pinned ELF binary with canonical symbol boundary
  and duplicate-rejecting multiset relocation checks.
