# Combat subsystem controller pulse evaluator at 0x32C320

`func_0032C320` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_pulse.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 252-byte instruction sequence
matching target code length (exact 252/252 code bytes, with 78 of 252 bytes matching and 174 byte differences;
classified strictly as NonMatching), matching stack frame (-0x40 = 64 bytes), callee-saved `$s0`–`$s2` and `$ra`, return value propagation from `func_00323860`,
optional view notification `view->func_28(1)`, early exit gate validation, denominator clamping with `#pragma divbyzerocheck on` hardware division trap,
quotient threshold evaluation, and manager notification `func_185F00`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032C320 = 0x32C320; // type:func size:0x100 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32C320, 0x32C41C)` (252 bytes, 63 instructions), excluding the 4-byte
  trailing alignment padding `nop` at `0x32C41C` inside the symbol extent to the 16-byte boundary of `func_0032C420`.
  Symbol extent spans `[0x32C320, 0x32C420)` (256 bytes, `0x100`, 64 instructions).
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022C500, 0x0022C600)`.
- Predecessor continuity: directly preceded by `func_0032BF70` ending at `0x32C31C` (`0x0022C500`).
  Contiguous, zero padding. Zero overlap.
- Successor continuity: directly followed by `func_0032C420` starting at `0x32C420` (`0x0022C600`).
  Contiguous, zero padding. Zero overlap.
- Stack frame: 64 bytes (`addiu $sp, $sp, -64` at `0x32C320`), saving `$ra` (48),
  `$s2` (32), `$s1` (16), and `$s0` (0) via quadword stores `sq`.
  Epilogue: `jr $ra` at `0x32C414` (+0x0F4) and delay slot stack teardown `addiu $sp, $sp, 64` at `0x32C418` (+0x0F8).
  Trailing padding: `nop` at `0x32C41C` (+0x0FC).

## Relocation manifest (11 relocations)

1. `+0x014` (`0x32C334`): `R_MIPS_26` to `func_00323860` (addend 0)
2. `+0x050` (`0x32C370`): `R_MIPS_26` to `func_1880D0` (addend 0)
3. `+0x054` (`0x32C374`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
4. `+0x070` (`0x32C390`): `R_MIPS_26` to `func_184C10` (addend 0)
5. `+0x074` (`0x32C394`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
6. `+0x088` (`0x32C3A8`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
7. `+0x08C` (`0x32C3AC`): `R_MIPS_26` to `func_184BD0` (addend 0)
8. `+0x0B8` (`0x32C3D8`): `R_MIPS_26` to `func_185DC0` (addend 0)
9. `+0x0BC` (`0x32C3DC`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
10. `+0x0C8` (`0x32C3E8`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
11. `+0x0D0` (`0x32C3F0`): `R_MIPS_26` to `func_185F00` (addend 0)

## Observable behavior

1. Primary evaluation: dispatch `func_00323860(self)` to obtain return value `ret`.
2. View notification: if `ret != 0` and `self->m_view != nullptr`, dispatch `self->m_view->func_28(1)` (vtable slot `0x28`).
3. Early exit checks: return `ret` if:
   - `self->m_field_341C == 0`
   - Manager status `func_1880D0(D_004E3180) == 0`
   - Mode flag `self->m_field_190 != 2`
4. Division threshold and signedness provenance:
   - Query denominator `den = func_184C10(D_004E3180)`. Clamped to 1 if zero.
   - Query numerator `num = func_184BD0(D_004E3180, 1)`.
   - At `0x32C3B4`–`0x32C3C0`, the original binary emits:
     ```text
     0x32C3B4: bne $s2, $zero, +2       ; branch if denominator non-zero
     0x32C3B8: divu $zero, $v0, $s2     ; unsigned hardware division
     0x32C3BC: break 0, 7               ; trap 7 on division by zero
     0x32C3C0: mflo $v0                 ; extract unsigned quotient
     0x32C3C4: sltiu $at, $v0, 81       ; unsigned comparison: quotient < 81
     0x32C3C8: bne $at, $zero, 0x32C400 ; early exit if quotient < 81
     ```
   - Hardware trap sequence (`#pragma divbyzerocheck on`): `quotient = (unsigned int)num / (unsigned int)den`.
   - The use of opcode `divu` (`0x0000001B`) and `sltiu` (`0x2C410051`) proves that both division and threshold evaluation are strictly unsigned.
   - If `quotient < 81`, return `ret`.
5. State update & manager notification:
   - Set `self->m_field_3424 = 1`.
   - Check `func_185DC0(D_004E3180)`: if busy (`!= 0`), return `ret`.
   - Dispatch `func_185F00(D_004E3180, 1, 1)`.
   - Set `self->m_field_3420 = 1`.
   - Return `ret`.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_pulse_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_pulse.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_pulse.h"

     int func_0032C320(CombatSubsystemControllerInstance *) {
         return -1;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_pulse.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_pulse_test.cpp -o build/test_pulse_red \
       && ./build/test_pulse_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: must propagate func_00323860 return value 42` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ pulse evaluator in `src/tactical_ai_combat_subsystem_controller_pulse.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_pulse.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_pulse_test.cpp -o build/test_pulse_green \
       && ./build/test_pulse_green
     ```
   - Result: All 5 fixtures passing cleanly (`return_prop`, `view_cb`, `gates`, `division`, `idle_success`), exit code 0 under UBSan.
   - Verified 11 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_pulse.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 252 bytes (exact 252/252 code byte length match).
   - Relocations resolved: all 11 relocations (5 GPREL16, 6 JAL) resolved.
   - Classified strictly as **NonMatching** (78 matching bytes, 174 byte differences).
   - The matching test serves as a structural correspondence diagnostic asserting >=50 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_pulse.py \
  tests/test_tactical_ai_combat_subsystem_controller_pulse_matching.py
```

The focused test run comprises **13 total tests** (12 behavioral tests in `test_tactical_ai_combat_subsystem_controller_pulse.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_pulse_matching.py`):
- One 32-bit native contract test with UBSan validating return propagation, view callback routing,
  early exit gates, denominator clamping, quotient threshold, and idle success updates with 7-call ordered callback sequencing.
- Eleven production source mutations independently compiled and verified
  rejected (return value propagation, view callback dispatch, gate 341C check, gate 1880D0 check, gate 190 check, denominator clamping zero trap, quotient threshold, field 3424 update, busy check, manager 185F00 arguments, field 3420 update).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
