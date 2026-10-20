# Combat subsystem controller drag processor at 0x3299F0

`func_003299F0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_drag.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a high-fidelity 1,308-byte instruction sequence
(+16 bytes from 1,292-byte target, 221 of 1,292 bytes matching), matching stack frame (-0x180 = 384 bytes),
argument preservation in `$s0`, callee-saved `$s0`–`$s5` and `$vf20`, gate validation
(`func_185DC0`, mode supported `{4, 5, 6, 7}`, `m_field_90`), controller state query `sub_0036ddf0`,
sub-object callback dispatch `m_sub_ca8->m_vtable->func_44`, timer delta calculation `func_2261C0`,
isometric movement updates `func_204920`, lock state synchronization via `func_00329450`,
and view notifications through slot `0x28`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_003299F0 = 0x3299F0; // type:func size:0x50C absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function: VRAM `[0x3299F0, 0x329EFC)`, file `[0x00229BD0, 0x0022A0DC)`.
  The function spans 1,292 instruction bytes (`0x50C`, 323 instructions).
- Predecessor padding: 12 bytes (`0xC`, 3 `nop` instructions at `0x3299E4`, `0x3299E8`, `0x3299EC`)
  following `func_00329550`. Zero overlap.
- Successor padding: 4 bytes (`0x4`, 1 `nop` instruction at `0x329EFC`) preceding `func_00329F00`.
  Zero overlap.
- Stack frame: 384 bytes (`addiu $sp, $sp, -0x180`), saving `$ra` (0x70),
  `$s5` (0x60), `$s4` (0x50), `$s3` (0x40), `$s2` (0x30), `$s1` (0x20), `$s0` (0x10),
  and `$vf20` (0x00 via `sqc2 vf20, 0($sp)`).

## Observable behavior

1. Check controller prerequisites via `check_drag_gate`:
   - Manager status `func_185DC0` must be 0.
   - System manager mode must be in `{4, 5, 6, 7}`.
   - Entity flag `m_field_90` must be nonzero.
   - If any check fails, dispatch `func_00329450(self, 0)` and return 0.
2. Query controller buffer via `sub_0036ddf0(buf)`.
3. If `mgr->m_field_1CC == 18` and `self->m_target->m_sub_ca8` exists:
   - Evaluate directional buffer inputs:
     - Byte 166 (buf[38]) < 2: dispatch `sub_ca8->m_vtable->func_44(sub_ca8, tx + margin, ty - margin)` and mark scroll active (`s1 = 1`).
     - Byte 168 (buf[40]) < 2: dispatch `sub_ca8->m_vtable->func_44(sub_ca8, tx - margin, ty + margin)` and mark scroll active (`s1 = 1`).
     - Byte 165 (buf[37]) < 2: dispatch `sub_ca8->m_vtable->func_44(sub_ca8, tx - margin, ty - margin)` and mark scroll active (`s1 = 1`).
     - Byte 167 (buf[39]) < 2: dispatch `sub_ca8->m_vtable->func_44(sub_ca8, tx + margin, ty + margin)` and mark scroll active (`s1 = 1`).
   - Derive movement direction vector `(s2, s3)` from directional inputs.
4. If either movement axis is active (`s2 != 0 || s3 != 0`):
   - Sample timer `now = func_2261C0()`.
   - If initial lock (`self->m_lock_342C == 0`), activate lock via `func_00329450(self, 1)` and set `speed = 1.0f`.
   - Else compute accelerated speed `(now - last_time) / duration` with half-step rounding, clamped to `sub28->m_max_speed_98`.
   - Apply isometric movement offsets along X and Y axes via `func_204920`.
   - Update timestamp `self->m_time_3428 = now`.
   - Mark scroll active (`s1 = 1`).
5. If both direction axes are idle (`s2 == 0 && s3 == 0`), reset lock via `func_00329450(self, 0)`.
6. If scroll was active (`s1 != 0`), notify view objects through slot `0x28`.
7. Return scroll active status `s1`.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_drag_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_drag.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_drag.h"

     int func_003299F0(CombatSubsystemControllerInstance *) {
         return 0;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_drag.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_drag_test.cpp -o build/test_drag_red \
       && ./build/test_drag_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: busy manager must call func_00329450` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ drag processor in `src/tactical_ai_combat_subsystem_controller_drag.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_drag.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_drag_test.cpp -o build/test_drag_green \
       && ./build/test_drag_green
     ```
   - Result: All 5 fixtures passing cleanly (`gate_rejection`, `center_idle`, `drag_movement`, `acceleration`, `combined_inputs`), exit code 0 under UBSan.
   - Verified 9 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_drag.py`.
3. **Refactor & Matching Diagnostics:**
   - Evaluated compiler register allocation: `$s0` preserved as `self`, `$vf20` saved at stack offset 0.
   - Built with verified MWCC PS2 flags: size 1,308 bytes (+16 bytes from target 1,292).
   - Classified as NonMatching (221 matching bytes, 1,071 byte differences).

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_drag.py \
  tests/test_tactical_ai_combat_subsystem_controller_drag_matching.py
```

The focused test run comprises **11 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating gate rejection, center idle state,
  drag movement calculation, acceleration clamping, combined directional inputs, sub-object callback, and view notifications.
- Nine production source mutations independently compiled and verified
  rejected (gate check, gate lock reset, idle lock reset, drag enable, X/Y movement, timestamp update, speed clamping, secondary axis movement).
- One matching test compiling fresh with Ninja/MWCC and verifying structural
  correspondence (symbol boundary, relocation multiset, >=150 byte sequence correspondence) against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
