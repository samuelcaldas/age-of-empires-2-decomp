# Combat subsystem controller action engine at 0x32A060

`func_0032A060` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_action.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces an initial 400-byte instruction sequence
(-1,792 bytes from 2,192-byte target, 75 of 2,192 bytes matching), matching stack frame (-0x100 = 256 bytes),
argument preservation in `$s6`, callee-saved `$s0`–`$s7`, `$fp`, and `$f20`–`$f21`, gate validation
(`func_185DC0`, mode supported `{4, 5, 6, 7}`), state machine dispatcher on `D_004E3180->m_field_1CC`,
waypoint stepping `func_0032D400`, target resolution `func_205EE0` and `func_205CA0`,
and view notifications through slot `0x28`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032A060 = 0x32A060; // type:func size:0x890 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32A060, 0x32A8EC)`, file `[0x0022A240, 0x0022AACC)`.
  The function body comprises 2,188 instruction bytes (547 instructions).
  A 4-byte padding `nop` (`0x00000000`) sits at `0x32A8EC` to align to the 16-byte boundary `0x32A8F0`,
  bringing the total canonical symbol span to `0x890` (2,192 bytes, 548 words).
- Predecessor continuity: directly preceded by `func_00329FA0` ending at `0x32A060`. Zero padding, zero overlap.
- Successor continuity: directly followed by `func_0032A8F0` at `0x32A8F0`. Zero overlap.
- Stack frame: 256 bytes (`addiu $sp, $sp, -0x100`), saving `$ra` (0xA0),
  `$fp` (0x90), all 8 `$s0`–`$s7`, `$f21` (0x04), and `$f20` (0x00).

## Observable behavior

1. Check controller prerequisites via `check_action_gate`:
   - Manager status `func_185DC0` must be 0.
   - System manager mode must be in `{4, 5, 6, 7}`.
   - If any check fails, return 0.
2. Query action state `state = D_004E3180->m_field_1CC`.
3. Dispatch state machine:
   - State 18: invokes `func_0032D400(self, 41, 0, a1, a2, buf, sub_ca8)`. If result is 52 (0x34):
     - Dispatches `func_205EE0(self->m_target)`.
     - Extracts item pointer from buffer offset 12: `item = *(void**)(buf + 12)`.
     - Dispatches `func_205CA0(self->m_target, item, 1)`.
     - Dispatches view notification `self->m_vtable->func_28(self, 1)`.
     - Verified call sequence: `func_0032D400` -> `func_205EE0` -> `func_205CA0` -> `func_28`.
     - If result is not 52, bypasses entity dispatch and returns 1.
   - State 1: invokes `func_0032D400(self, 40, 0, a1, a2, buf, 0)`. If result is 51 (0x33):
     - Dispatches `func_0032E580(self, buf)`.
     - If result is not 51, bypasses `func_0032E580` and returns 1.
   - Default: returns 1.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_action_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_action.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_action.h"

     int func_0032A060(CombatSubsystemControllerInstance *, int, int, int, int) {
         return 0;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_action.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_action_test.cpp -o build/test_action_red \
       && ./build/test_action_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: default state must return 1` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ action engine in `src/tactical_ai_combat_subsystem_controller_action.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_action.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_action_test.cpp -o build/test_action_green \
       && ./build/test_action_green
     ```
   - Result: All 6 fixtures passing cleanly (`gate_rejection`, `default_state`, `state_18_success`, `state_18_non52`, `state_1_success`, `state_1_non51`), exit code 0 under UBSan.
   - Verified 10 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_action.py`.
3. **Refactor & Matching Diagnostics:**
   - Evaluated compiler register allocation: `$s6` preserved as `self`.
   - Built with verified MWCC PS2 flags: initial candidate size 400 bytes (-1,792 bytes from 2,188-byte code extent).
   - Classified strictly as **NonMatching** (75 matching bytes, 325 byte differences).
   - The matching test serves as a structural correspondence diagnostic rather than a matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_action.py \
  tests/test_tactical_ai_combat_subsystem_controller_action_matching.py
```

The focused test run comprises **12 passing tests** (or 11 passed, 1 skipped when compiler/wibo are unavailable in container environment):
- One 32-bit native contract test with UBSan validating gate rejection, default state return,
  state 18 success with call sequence and item forwarding, state 18 non-52 bypass, state 1 success with action 40 and buffer dispatch, and state 1 non-51 bypass.
- Ten production source mutations independently compiled and verified
  rejected (gate return, default return, state 18 check, result check, entity resolution, item setting, view notification, state 1 check, state 1 result check, state 1 buffer dispatch).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are not provisioned).

The WIP/BIN boundary and registered object list remain unchanged.

The WIP/BIN boundary and registered object list remain unchanged.
