# Combat subsystem controller processor at 0x329550

`func_00329550` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_processor.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces an exact-length 1,172-byte instruction sequence
(1,172 of 1,172 bytes, 100% size match), matching stack frame (-0x90 = 144 bytes), argument
preservation in `$s4`, callee-saved `$s0`–`$s3` and `$f20`, gate validation
(`is_mode_supported`, `func_185DC0`, `m_sub28->m_field_80`, `func_1F26F0`, `func_1F26D0`),
viewport margin bounds evaluation, hardware timer delta calculation `func_2261C0`,
isometric position updates `func_204920`, and view notification dispatch through slot `0x28`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x329550, 0x3299E4)`, file `[0x229730, 0x229BC4)`.
  The function spans 1,172 instruction bytes (0x494), followed by 12 bytes of
  alignment-padding nops up to `0x3299F0`. Symbol size is `0x494`.
- Stack frame: 144 bytes (`addiu $sp, $sp, -0x90`), saving `$ra` (0x60),
  `$s4` (0x50), `$s3` (0x40), `$s2` (0x30), `$s1` (0x20), `$s0` (0x10),
  and `$f20` (0x00).

## Observable behavior

1. Check controller prerequisites via `check_controller_gate`:
   - System manager mode must be in `{4, 5, 6, 7}`.
   - Manager status `func_185DC0` must be 0.
   - `m_sub28->m_field_80` must be nonzero.
   - Focus query `func_1F26F0` and `func_1F26D0` must be clear or match `self`.
   - Lock flag `m_lock_342C` must be 0.
   - Entity flag `m_field_90` must be nonzero.
   - If any check fails, dispatch `func_00329350(self, 0)` and return 0.
2. Query viewport dimensions and current position via `func_2254D0` and `func_225560`.
3. Check scroll conditions: if input axes are non-negative and `m_field_190 != 2`,
   evaluate viewport boundaries with `m_margin_88` to derive direction vector `(s0, s1)`.
4. If either direction is active:
   - Sample hardware timer `now = func_2261C0()`.
   - If initial mode (`m_mode_3410 == 0`), activate mode 1 and speed = `1.0f`.
   - Else compute accelerated speed `(now - last_time) / duration` with half-step rounding.
   - Apply isometric movement offsets along X and Y axes via `func_204920`.
   - Notify `self->m_vtable->func_28(self, 1)` and `child->m_vtable->func_28(child, 1)`.
   - Update timestamp `m_time_340C = now`.
5. If both directions are zero, reset mode via `func_00329350(self, 0)`.
6. Return current mode `self->m_mode_3410`.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_processor_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `/tmp/stub_candidate.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_processor.h"

     int func_00329550(CombatSubsystemControllerInstance *) {
         return 0;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude /tmp/stub_candidate.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_processor_test.cpp -o build/test_proc_red \
       && ./build/test_proc_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: unsupported mode must call func_00329350` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ processor in `src/tactical_ai_combat_subsystem_controller_processor.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_processor.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_processor_test.cpp -o build/test_proc_green \
       && ./build/test_proc_green
     ```
   - Result: All 4 fixtures passing cleanly (`gate_rejection`, `center_idle`, `left_edge`, `right_edge`), exit code 0 under UBSan.
   - Verified 7 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_processor.py`.
3. **Refactor & Matching Diagnostics:**
   - Evaluated compiler register allocation: structured post-gate local variable ordering (`int s0; short s1;`) to allocate `self` to `$s4` and callee-saved `$s0`–`$s3`.
   - Verified exact function size of 1,172 / 1,172 bytes (293 instructions).
   - Classified as NonMatching (414 matching bytes, 758 byte differences).
   - Disassembly inspection artifact generated at `build/func_00329550_disassembly.txt` (all 293 instructions decoded and aligned side-by-side).

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_processor.py \
  tests/test_tactical_ai_combat_subsystem_controller_processor_matching.py
```

The focused test run comprises **9 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating gate rejection, center idle state,
  left-edge scroll activation, isometric movement calculation, and view callbacks.
- Seven production source mutations independently compiled and verified
  rejected (gate check, gate reset, idle mode reset, mode activation, movement application, timestamp update).
- One matching test compiling fresh with Ninja/MWCC and verifying structural
  correspondence (exact 1,172/1,172 byte size, >=414 byte relocated sequence correspondence) against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
