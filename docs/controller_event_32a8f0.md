# Combat subsystem controller event dispatcher at 0x32A8F0

`func_0032A8F0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_event.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces an initial 436-byte instruction sequence
(-36 bytes from 472-byte target, 117 of 472 bytes matching), matching stack frame (-0x60 = 96 bytes),
argument preservation in `$s4`, callee-saved `$s0`–`$s4`, gate validation (`D_004E3180->m_mode` in `{4, 5, 6, 7}`),
manager status check `func_185DC0`, flag `m_field_190` routing, state query `D_004E3180->m_field_1CC`,
fallback notification `func_1F65A0`, and virtual method dispatches through slots `0x28`, `0x108`, `0x10C`, and `0x110`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032A8F0 = 0x32A8F0; // type:func size:0x1D8 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32A8F0, 0x32AAC8)`, file `[0x0022AAD0, 0x0022ACA8)`.
  The function body spans 472 instruction bytes (`0x1D8`, 118 instructions). Symbol size is `0x1D8`.
- Predecessor continuity: directly preceded by `func_0032A060` terminating at `0x32A8EC` with
  a 4-byte padding `nop` at `0x32A8EC`. Zero overlap.
- Successor continuity: directly followed by `func_0032AAD0` starting at `0x32AAD0`.
  8 bytes alignment padding `nop` (`0x00000000` at `0x32AAC8` and `0x32AACC`). Zero overlap.
- Stack frame: 96 bytes (`addiu $sp, $sp, -0x60`), saving `$ra` (0x50),
  `$s4` (0x40), `$s3` (0x30), `$s2` (0x20), `$s1` (0x10), and `$s0` (0x00).

## Observable behavior

1. Check mode gate:
   - System manager mode must be in `{4, 5, 6, 7}`.
   - If not in set, return 0.
2. Check manager status via `func_185DC0(D_004E3180)`:
   - If busy (`!= 0`):
     - If `self->m_field_190 != 0`, dispatch `self->m_vtable->func_110(self)`.
     - Else dispatch `func_1F65A0(self)`.
     - Return 0.
3. Manager idle path (`func_185DC0 == 0`):
   - If `self->m_field_190 != 0`:
     - Dispatch `self->m_vtable->func_10C(self, a1, a2)`.
     - Return 1.
   - Else query `state = D_004E3180->m_field_1CC`:
     - If `state` in `{1, 7, 8}`:
       - Dispatch `self->m_vtable->func_28(self, 1)`.
       - Return 1.
     - Else if `state == 0`:
       - Return 1.
     - Else:
       - Dispatch `func_1F65A0(self)`.
       - Dispatch `self->m_vtable->func_108(self, 2, self->m_field_E0, self->m_field_E4, a3, a4)`.
       - Dispatch `self->m_vtable->func_10C(self, a1, a2)`.
       - Verified call sequence: `func_1F65A0` -> `func_108` -> `func_10C` (matching original ELF instruction order at `+0x154`, `+0x178`, and `+0x190`).
       - Return 1.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_event_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_event.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_event.h"

     int func_0032A8F0(CombatSubsystemControllerInstance *, int, int, int, int) {
         return 0;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_event.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_event_test.cpp -o build/test_event_red \
       && ./build/test_event_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: busy with field_190 must call func_110` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ event dispatcher in `src/tactical_ai_combat_subsystem_controller_event.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_event.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_event_test.cpp -o build/test_event_green \
       && ./build/test_event_green
     ```
   - Result: All 6 fixtures passing cleanly (`gate_rejection`, `busy_branches`, `idle_field_190`, `idle_state_1_7_8`, `idle_state_0`, `idle_state_other`), exit code 0 under UBSan.
   - Verified 7 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_event.py`.
3. **Refactor & Matching Diagnostics:**
   - Evaluated compiler register allocation: `$s4` preserved as `self`.
   - Built with verified MWCC PS2 flags: initial candidate size 436 bytes (-36 bytes from 472-byte target).
   - Classified strictly as **NonMatching** (117 matching bytes, 319 byte differences).
   - The matching test serves as a structural correspondence diagnostic rather than a matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_event.py \
  tests/test_tactical_ai_combat_subsystem_controller_event_matching.py
```

The focused test run comprises **9 passing tests** (or 8 passing, 1 skipped when compiler/wibo are unprovisioned):
- One 32-bit native contract test with UBSan validating mode gate rejection, manager busy/idle routing,
  field_190 branching, field_1CC states {1, 7, 8}, 0, and other, and virtual callback arguments.
- Seven production source mutations independently compiled and verified
  rejected (gate return, busy return, busy field_190 routing, idle field_190 dispatch, state 1/7/8 view notification, state other func_108 call, state other func_10C call).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
