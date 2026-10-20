# Combat subsystem controller state notifier at 0x329FA0

`func_00329FA0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_state.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 136-byte instruction sequence
(-56 bytes from 192-byte target, 39 of 192 bytes matching), matching stack frame (-0x10 = 16 bytes),
argument preservation in `$a0`, gate validation (`D_004E3180->m_mode` in `{4, 5, 6, 7}`),
state query `D_004E3180->m_field_1CC`, and view notification dispatch through slot `0x28`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_00329FA0 = 0x329FA0; // type:func size:0xC0 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function: VRAM `[0x329FA0, 0x32A060)`, file `[0x0022A180, 0x0022A240)`.
  The function spans 192 instruction bytes (`0xC0`, 48 instructions). Symbol size is `0xC0`.
- Predecessor padding: 4 bytes (`0x4`, 1 `nop` instruction `0x00000000` at `0x329F9C`)
  following `func_00329F00`. Zero overlap.
- Successor boundary: directly followed by `func_0032A060` at `0x32A060`. Zero overlap.
- Stack frame: 16 bytes (`addiu $sp, $sp, -0x10`), saving only `$ra` at `0($sp)`.
  No callee-saved registers used.

## Observable behavior

1. Check mode gate:
   - System manager mode must be in `{4, 5, 6, 7}`.
   - If not in set, return 0.
2. Query state flag `D_004E3180->m_field_1CC`.
3. If `m_field_1CC` is in `{1, 7, 8}`:
   - Dispatch view notification `self->m_vtable->func_28(self, 1)`.
4. Return 1.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_state_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_state.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_state.h"

     int func_00329FA0(CombatSubsystemControllerInstance *) {
         return 0;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_state.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_state_test.cpp -o build/test_state_red \
       && ./build/test_state_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: field_1CC 1 must return 1` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ state notifier in `src/tactical_ai_combat_subsystem_controller_state.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_state.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_state_test.cpp -o build/test_state_green \
       && ./build/test_state_green
     ```
   - Result: All fixtures passing cleanly (`gate_rejection`, `cases_1_7_8`, `other_cases`), exit code 0 under UBSan.
   - Verified 6 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_state.py`.
3. **Refactor & Matching Diagnostics:**
   - Evaluated compiler register allocation: `$ra` saved at stack offset 0.
   - Built with verified MWCC PS2 flags: size 136 bytes (-56 bytes from target 192).
   - Classified as NonMatching (39 matching bytes, 153 byte differences). Single `R_MIPS_GPREL16` relocation resolved.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_state.py \
  tests/test_tactical_ai_combat_subsystem_controller_state_matching.py
```

The focused test run comprises **8 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating mode gate rejection, field_1CC cases {1, 7, 8},
  non-matching field_1CC cases, and slot 0x28 view callback arguments.
- Six production source mutations independently compiled and verified
  rejected (corrupted gate return, corrupted case 1, corrupted case 7, corrupted case 8, corrupted notification argument, corrupted success return).
- One matching test compiling fresh with Ninja/MWCC and verifying structural
  correspondence (symbol boundary, relocation multiset, >=35 byte sequence correspondence) against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
