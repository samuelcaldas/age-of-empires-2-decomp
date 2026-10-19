# Combat subsystem controller context action dispatcher at 0x32BF70

`func_0032BF70` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_context.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces an 832-byte instruction sequence
(-108 bytes from 940-byte target code extent, 174 of 940 bytes matching, 766 byte differences),
matching stack frame (-0x90 = 144 bytes), callee-saved `$s0`–`$s4` and `$ra`, gate validation (`D_004E3180->m_mode` in `{4, 5, 6, 7}`),
`self->m_field_190` branch, state 20 target dispatch, busy manager rejection, state 21 routing, and manager notification fallback.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032BF70 = 0x32BF70; // type:func size:0x3B0 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32BF70, 0x32C31C)` (940 bytes, 235 instructions), excluding the 4-byte
  trailing alignment padding `nop` at `0x32C31C` to the 16-byte boundary of `func_0032C320`.
  Symbol extent spans `[0x32BF70, 0x32C320)` (944 bytes, `0x3B0`, 236 instructions).
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022C150, 0x0022C500)`.
- Predecessor continuity: directly preceded by `func_0032BE50` ending at `0x32BF6C` (`0x0022C150`).
  Contiguous, zero padding. Zero overlap.
- Successor continuity: directly followed by `func_0032C320` starting at `0x32C320` (`0x0022C500`).
  Contiguous, zero padding. Zero overlap.
- Stack frame: 144 bytes (`addiu $sp, $sp, -0x90` at `0x32BF70`), saving `$ra` (96),
  `$s4` (80), `$s3` (64), `$s2` (48), `$s1` (32), and `$s0` (16) via quadword stores `sq`.
  Epilogue: `jr $ra` at `0x32C314` (+0x3A4) and delay slot stack teardown `addiu $sp, $sp, 144` at `0x32C318` (+0x3A8).

## Relocation manifest (16 relocations)

1. `+0x020` (`0x32BF90`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
2. `+0x0B8` (`0x32C028`): `R_MIPS_26` to `func_1F65A0` (addend 0)
3. `+0x0EC` (`0x32C05C`): `R_MIPS_26` to `func_0032D400` (addend 0)
4. `+0x124` (`0x32C094`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
5. `+0x128` (`0x32C098`): `R_MIPS_26` to `func_185DC0` (addend 0)
6. `+0x144` (`0x32C0B4`): `R_MIPS_26` to `func_225590` (addend 0)
7. `+0x174` (`0x32C0E4`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
8. `+0x228` (`0x32C198`): `R_MIPS_GPREL16` to `D_004E2EA0` (addend -31,008)
9. `+0x250` (`0x32C1C0`): `R_MIPS_26` to `func_0032D400` (addend 0)
10. `+0x26C` (`0x32C1DC`): `R_MIPS_26` to `func_0032E580` (addend 0)
11. `+0x2B0` (`0x32C220`): `R_MIPS_26` to `func_0032E6B0` (addend 0)
12. `+0x2DC` (`0x32C24C`): `R_MIPS_26` to `func_31A720` (addend 0)
13. `+0x2F8` (`0x32C268`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
14. `+0x32C` (`0x32C29C`): `R_MIPS_26` to `func_0032E820` (addend 0)
15. `+0x334` (`0x32C2A4`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
16. `+0x360` (`0x32C2D0`): `R_MIPS_26` to `func_205EE0` (addend 0)

## Observable behavior

1. Check mode gate:
   - System manager mode `D_004E3180->m_mode` must be in `{4, 5, 6, 7}`.
   - If mode is unsupported, return 0 and suppress all downstream calls.
2. Check `self->m_field_190`:
   - If active (`!= 0`): dispatch `self->m_vtable->func_110(self)` and return 1.
3. Fallback notification: dispatch `func_1F65A0(self)`.
4. State 20 query (`D_004E3180->m_field_1CC == 20`):
   - Dispatch `func_0032D400(self, 41, 2, a1, a2, buf, sub_ca8, 1)`.
   - On return 52: dispatch view notification `view->func_8C(-1)`.
   - Return 1.
5. Query manager status via `func_185DC0(D_004E3180)`:
   - If busy (`func_185DC0 != 0`): return 0.
   - If idle (`func_185DC0 == 0`):
     - Dispatch `func_225590(18)`.
     - Route state 21 or fallback to `func_0032E820`, `func_205EE0`, view `func_28`, and manager `func_18`, returning 1.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_context_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_context.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_context.h"

     int func_0032BF70(CombatSubsystemControllerInstance *, int, int, int, int) {
         return -1;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_context.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_context_test.cpp -o build/test_context_red \
       && ./build/test_context_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: unsupported mode must return 0` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ context action dispatcher in `src/tactical_ai_combat_subsystem_controller_context.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_context.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_context_test.cpp -o build/test_context_green \
       && ./build/test_context_green
     ```
   - Result: All 11 fixtures passing cleanly (`gate_rejection`, `active_190`, `state_20_hit`, `state_20_miss`, `busy`, `idle_fallback`, `accepted_modes`, `state_21`, `t0_split`, `sub_a0`, `modes_5_7`), exit code 0 under UBSan.
   - Exact `func_0032D400` arguments verified: `self`, `a1 = 41` (state 20) or `40` (state 21), `a2 = 2` (state 20) or `0` (state 21), `a3 = a1`, `t0 = a2`, `buf = buffer` (asserted non-null and identically forwarded to `func_0032E580`, matching `$sp + 112` in ELF), `target_sub = sub_ca8` or `nullptr`, `flag = 1`.
   - Verified state 21 routing (`m_field_1CC == 21`) for both `m_field_108` in `{1, 2}` with exact 6-call sequence: `func_1F65A0` -> `func_185DC0` -> `func_225590` -> `func_31A720(-1, -1, -1, -1)` -> view `func_28(1)` -> manager `func_18(0, 0)`.
   - Verified `t0` split: `t0 == 0` with exact 4-call sequence `func_1F65A0` -> `func_185DC0` -> `func_225590` -> `func_12C(self, a1, a2, 1, -1)`; `t0 != 0` on hit 51 with exact 6-call sequence `func_1F65A0` -> `func_185DC0` -> `func_225590` -> `func_0032D400` -> `func_0032E580` -> `func_0032E6B0(self, 2962, 0, 0, 0)`.
   - Verified manager subfield gate `D_004E3180->m_sub_a0->m_val_a0 == 2` and mode bypass for `{5, 7}`.
   - Verified 13 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_context.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 832 bytes (-108 bytes from 940-byte target).
   - Relocations resolved: all 16 relocations (6 GPREL16, 10 JAL) resolved.
   - Classified strictly as **NonMatching** (174 matching bytes, 766 byte differences).
   - The matching test serves as a structural correspondence diagnostic asserting >=50 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_context.py \
  tests/test_tactical_ai_combat_subsystem_controller_context_matching.py
```

The focused test run comprises **15 total tests** (14 behavioral tests in `test_tactical_ai_combat_subsystem_controller_context.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_context_matching.py`):
- One 32-bit native contract test with UBSan validating mode gate rejection, accepted modes `{4, 5, 6, 7}`,
  active field_190 routing, state 20 dispatch with view notification, busy manager rejection, idle manager fallback,
  state 21 routing with `m_field_108` in `{1, 2}` and 6-call ordered callback sequencing, `t0` branch split with 4-call / 6-call ordered sequencing,
  non-null buffer pointer forwarding between func_0032D400 and func_0032E580, manager subfield gate, and mode bypass.
- Thirteen production source mutations independently compiled and verified
  rejected (gate return, active field_190 check, fallback func_1F65A0 call, state 20 check, view func_8C dispatch, busy manager check, busy return, func_225590 arguments, fallback view func_28 call, state 21 dispatch, t0 zero dispatch, t0 non-zero 32d400 call, sub_a0 gate check).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
