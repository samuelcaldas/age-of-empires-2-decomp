# Combat subsystem controller camera dispatcher at 0x32BCE0

`func_0032BCE0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_camera.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 344-byte instruction sequence
(-16 bytes from 360-byte target, 122 of 360 bytes matching), matching stack frame (-0x60 = 96 bytes),
argument preservation in `$s4`, callee-saved `$s0`–`$s4`, gate validation (`func_185DC0`, `D_004E3180->m_mode` in `{4, 5, 6, 7}`),
state query `D_004E3180->m_field_1CC`, target entity focus `func_205EE0`, view notifications through slots `0x28` and `0x108`,
manager notification through slot `0x18`, and fallback notification `func_1F6510`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032BCE0 = 0x32BCE0; // type:func size:0x168 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32BCE0, 0x32BE48)`, file `[0x0022BEC0, 0x0022C028)`.
  The function body spans 360 instruction bytes (`0x168`, 90 instructions). Symbol size is `0x168`.
  Code ends at `0x32BE44` (`addiu $sp, $sp, 96` in delay slot of `jr $ra` at `0x32BE40`).
- Predecessor continuity: directly preceded by `func_0032AAD0` ending at `0x32BCD8` with
  8 bytes alignment padding `nop` (`0x00000000` at `0x32BCD8` and `0x32BCDC`). Zero overlap.
- Successor continuity: directly followed by `func_0032BE50` starting at `0x32BE50`, with
  8 bytes alignment padding `nop` (`0x00000000` at `0x32BE48` and `0x32BE4C`). Zero overlap.
- Stack frame: 96 bytes (`addiu $sp, $sp, -0x60`), saving `$ra` (0x50),
  `$s4` (0x40), `$s3` (0x30), `$s2` (0x20), `$s1` (0x10), and `$s0` (0x00).

## Observable behavior

1. Check controller prerequisites via `check_camera_gate`:
   - Manager status `func_185DC0` must be 0.
   - System manager mode must be in `{4, 5, 6, 7}`.
   - If any check fails, return 0.
2. Query state flag `D_004E3180->m_field_1CC`:
   - If `m_field_1CC == 19` and `self->m_target->m_sub_ca8 != 0`:
     - Dispatch `func_205EE0(target)`.
     - Dispatch `self->m_vtable->func_28(self, 1)`.
     - Dispatch `D_004E3180->m_vtable->func_18(D_004E3180, 19, 1)`.
     - Dispatch `self->m_vtable->func_108(self, 9, a1, a2, a3, a4)`.
     - Return 1.
3. Fallback path (state != 19 or sub_ca8 == 0):
   - Dispatch `func_1F6510(self)`.
   - Return 1.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_camera_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_camera.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_camera.h"

     int func_0032BCE0(CombatSubsystemControllerInstance *, int, int, int, int) {
         return 0;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_camera.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_camera_test.cpp -o build/test_cam_red \
       && ./build/test_cam_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: state 19 with sub_ca8 must return 1` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ camera dispatcher in `src/tactical_ai_combat_subsystem_controller_camera.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_camera.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_camera_test.cpp -o build/test_cam_green \
       && ./build/test_cam_green
     ```
   - Result: All 6 fixtures passing cleanly (`gate_rejection`, `accepted_modes`, `state_19_null_target`, `state_19_sub`, `state_19_nosub`, `state_not_19`), exit code 0 under UBSan.
   - Null-target fixture `test_state_19_null_target` asserts `self->m_target == nullptr` in state 19 falls back to `func_1F6510(self)` and returns 1 with sole-call sequencing, suppressing `func_205EE0`, `func_28`, manager `func_18`, and `func_108`.
   - Accepted modes fixture `test_accepted_modes` explicitly verifies system manager modes `{4, 5, 6, 7}` pass gate validation.
   - Verified 9 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_camera.py`.
3. **Refactor & Matching Diagnostics:**
   - Evaluated compiler register allocation: `$s4` preserved as `self`.
   - Built with verified MWCC PS2 flags: initial candidate size 344 bytes (-16 bytes from 360-byte target).
   - Classified strictly as **NonMatching** (122 matching bytes, 222 byte differences).
   - The matching test serves as a structural correspondence diagnostic asserting >=50 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_camera.py \
  tests/test_tactical_ai_combat_subsystem_controller_camera_matching.py
```

The focused test run comprises **11 passing tests** (or 10 passing, 1 skipped when compiler/wibo are unprovisioned):
- One 32-bit native contract test with UBSan validating mode gate rejection, accepted modes `{4, 5, 6, 7}`,
  state 19 null-target fallback, state 19 valid target routing, manager notification, and fallback routing.
- Nine production source mutations independently compiled and verified
  rejected (gate return, busy check, state 19 check, entity focus call, view func_28 call, manager func_18 call, view func_108 call, null target check, fallback func_1F6510 call).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
