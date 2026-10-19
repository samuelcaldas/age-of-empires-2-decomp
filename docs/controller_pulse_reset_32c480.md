# Combat subsystem controller pulse reset at 0x32C480

`func_0032C480` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_pulse_reset.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces an exact 120-byte instruction sequence
(matching target code extent 120/120 bytes, **100.00% exact match**, 0 byte differences),
matching stack frame (-0x20 = 32 bytes), callee-saved `$s0` and `$ra`, pulse reset gate validation,
manager deactivation notification `func_185F00(0, 0)`, and unconditional final helper dispatch `func_00324470`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032C480 = 0x32C480; // type:func size:0x78 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32C480, 0x32C4F8)` (120 bytes, 30 instructions), with zero internal padding.
  Symbol extent spans `[0x32C480, 0x32C4F8)` (120 bytes, `0x78`, 30 instructions).
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022C660, 0x0022C6D8)`.
- Predecessor continuity: directly preceded by `func_0032C420` ending at `0x32C478` (`0x0022C658`).
  Between `0x32C478` and `0x32C480`: exactly 8 bytes alignment padding `nop nop` (`0x00000000 0x00000000`).
  Zero overlap.
- Successor continuity: directly followed by `func_0032C500` starting at `0x32C500` (`0x0022C6E0`).
  Between `0x32C4F8` and `0x32C500`: exactly 8 bytes alignment padding `nop nop` (`0x00000000 0x00000000`).
  Zero unclassified bytes, zero overlap.
- Stack frame: 32 bytes (`addiu $sp, $sp, -32` at `0x32C480`), saving `$ra` (16) and `$s0` (0) via quadword stores `sq`.
  Epilogue: `jr $ra` at `0x32C4F0` (+0x070) and delay slot stack teardown `addiu $sp, $sp, 32` at `0x32C4F4` (+0x074).

## Relocation manifest (5 relocations)

1. `+0x018` (`0x32C498`): `R_MIPS_26` to `func_1880D0` (target `0x1880D0`, raw word `0x0C062034`, addend 0)
2. `+0x01C` (`0x32C49C`): `R_MIPS_GPREL16` to `D_004E3180` (raw word `0x8F8489C0`, addend -30,272)
3. `+0x048` (`0x32C4C8`): `R_MIPS_GPREL16` to `D_004E3180` (raw word `0x8F8489C0`, addend -30,272)
4. `+0x050` (`0x32C4D0`): `R_MIPS_26` to `func_185F00` (target `0x185F00`, raw word `0x0C0617C0`, addend 0)
5. `+0x060` (`0x32C4E0`): `R_MIPS_26` to `func_00324470` (target `0x324470`, raw word `0x0C0C911C`, addend 0)

## Observable behavior

1. Check compound reset condition:
   - `self->m_field_341C != 0`
   - Manager query `func_1880D0(D_004E3180) != 0`
   - Mode flag `self->m_field_190 == 2`
2. If all three conditions hold:
   - Clear `self->m_field_3424 = 0`.
   - Check `self->m_field_3420`:
     - If non-zero: dispatch manager deactivation `func_185F00(D_004E3180, 0, 0)` and clear `self->m_field_3420 = 0`.
3. Unconditionally dispatch `func_00324470(self)` across all execution paths.
4. Return void.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_pulse_reset_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_pulse_reset.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_pulse_reset.h"

     void func_0032C480(CombatSubsystemControllerInstance *) {}
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_pulse_reset.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_pulse_reset_test.cpp -o build/test_pulse_reset_red \
       && ./build/test_pulse_reset_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: m_field_3424 must be reset to 0` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ pulse reset coordinator in `src/tactical_ai_combat_subsystem_controller_pulse_reset.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_pulse_reset.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_pulse_reset_test.cpp -o build/test_pulse_reset_green \
       && ./build/test_pulse_reset_green
     ```
   - Result: All 3 fixtures passing cleanly (`full_reset`, `inactive_3420`, `gates`), exit code 0 under UBSan.
   - Verified 9 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_pulse_reset.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 120 bytes (**100.00% exact byte-for-byte match**, 120/120 matching bytes, 0 differences).
   - Relocations resolved: all 5 relocations (2 GPREL16, 3 JAL) resolved with duplicate-rejecting exact multiset check.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_pulse_reset.py \
  tests/test_tactical_ai_combat_subsystem_controller_pulse_reset_matching.py
```

The focused test run comprises **11 total tests** (10 behavioral tests in `test_tactical_ai_combat_subsystem_controller_pulse_reset.py` and 1 exact matching test in `test_tactical_ai_combat_subsystem_controller_pulse_reset_matching.py`):
- One 32-bit native contract test with UBSan validating full reset with active field 3420, inactive field 3420 path,
  gate suppression, and unconditional final dispatch with 3-call ordered callback sequencing.
- Nine production source mutations independently compiled and verified
  rejected (gate 341C inversion, gate 1880D0 inversion, gate 190 inversion, field 3424 clearing, field 3420 check, manager 185F00 dispatch, manager argument validation, field 3420 clearing, unconditional 324470 dispatch).
- One exact matching test compiling fresh with Ninja/MWCC and verifying
  **100.00% byte-for-byte identity** against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
