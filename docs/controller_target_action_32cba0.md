# Combat subsystem controller target action coordinator at 0x32CBA0

`func_0032CBA0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_target_action.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 176-byte partial candidate sequence
(-1956 bytes from 2132-byte target code extent, 30 of 2132 bytes matching, 2102 byte differences;
classified strictly as NonMatching), scoping cleanup `func_0032E820`, primary entry gate `D_004E2EA0`,
raycast validation `func_0032D400`, buffer forwarding `func_0032E580`, and order dispatch `func_0032E6B0`.
Full target action coordinator sub-branches (including secondary raycasts, audio cues, and formation updates) are unmodeled in this partial slice.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032CBA0 = 0x32CBA0; // type:func size:0x854 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32CBA0, 0x32D3F4)` (2,132 bytes, 533 instructions), with zero internal padding.
  Symbol extent spans `[0x32CBA0, 0x32D3F4)` (2,132 bytes, `0x854`, 533 instructions).
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022CD80, 0x0022D5D4)`.
- Predecessor continuity: directly preceded by `func_0032C600` ending at `0x32CB94` (`0x0022CD74`).
  Between `0x32CB94` and `0x32CBA0`: exactly 12 bytes alignment padding `nop nop nop` (`0x00000000 0x00000000 0x00000000`).
  Zero overlap.
- Successor continuity: directly followed by `func_0032D400` starting at `0x32D400` (`0x0022D5E0`),
  size `0x688` (1,672 bytes).
  Between `0x32D3F4` and `0x32D400`: exactly 12 bytes alignment padding `nop nop nop` (`0x00000000 0x00000000 0x00000000`).
  Zero unclassified bytes, zero overlap.
- Stack frame: 256 bytes (`addiu $sp, $sp, -256` = `0x27BDFF00` at `0x32CBA0`), saving `$ra` (144) and
  callee-saved registers via quadword stores `sq`.
  Epilogue: `jr $ra` at `0x32D3EC` (+0x84C) and delay slot stack teardown `addiu $sp, $sp, 256` at `0x32D3F0` (+0x850).

## Relocation manifest

### Compiled candidate relocations (5 relocations)
The 176-byte candidate object resolves exactly 5 relocations with a duplicate-rejecting multiset check:
1. `+0x01C`: `R_MIPS_26` to `func_0032E820`
2. `+0x024`: `R_MIPS_GPREL16` to `D_004E2EA0`
3. `+0x054`: `R_MIPS_26` to `func_0032D400`
4. `+0x074`: `R_MIPS_26` to `func_0032E580`
5. `+0x08C`: `R_MIPS_26` to `func_0032E6B0`

### Full ELF function relocations (30 relocations)
The full 2,132-byte original binary function contains 30 relocations:
- 13 `R_MIPS_GPREL16` relocations:
  - `+0x048`: `D_004E2EA0` (addend -31,008)
  - `+0x0A0`, `+0x278`, `+0x3F4`, `+0x458`, `+0x484`, `+0x6E4`, `+0x7D8`: `D_004E3180` (addend -30,272)
  - `+0x0F0`, `+0x14C`: `D_4E2F20` (addend -30,880)
  - `+0x100`: `D_4E3500` (addend -29,376)
  - `+0x118`: `D_4E3504` (addend -29,372)
  - `+0x138`: `D_4E34FC` (addend -29,380)
- 17 `R_MIPS_26` JAL relocations (addend 0):
  - `+0x040`: `func_0032E820`
  - `+0x104`, `+0x11C`: `sub_114308` (2 calls)
  - `+0x130`: `func_2261C0`
  - `+0x150`: `func_332E60`
  - `+0x1EC`: `sub_2690D0`
  - `+0x390`, `+0x764`: `sub_2DEB80` (2 calls)
  - `+0x420`, `+0x804`: `sub_30A7F0` (2 calls)
  - `+0x434`, `+0x818`: `sub_116F68` (2 calls)
  - `+0x520`: `sub_2DFBB0`
  - `+0x5C0`: `sub_31A160`
  - `+0x660`: `func_0032D400`
  - `+0x67C`: `func_0032E580`
  - `+0x6C8`: `func_0032E6B0`

## Observable behavior (Implemented Partial Scope)

1. Cleanup: dispatch `func_0032E820(self)`.
2. Entry gate check: query `D_004E2EA0`. If 0, return 0 immediately.
3. Raycast query: dispatch `func_0032D400(self, 40, 0, x, y, buf, 0, 1)`.
   - If return value != 51, return 0.
4. Success path: dispatch `func_0032E580(self, buf)`.
5. Order dispatch: dispatch `func_0032E6B0(self, 2962, 0, 0, 0)`.
6. Return 1.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_target_action_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_target_action.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_target_action.h"

     int func_0032CBA0(CombatSubsystemControllerInstance *, int, int, int) {
         return -1;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_target_action.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_target_action_test.cpp -o build/test_target_action_red \
       && ./build/test_target_action_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: D_004E2EA0==0 must return 0` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ partial target action coordinator in `src/tactical_ai_combat_subsystem_controller_target_action.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_target_action.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_target_action_test.cpp -o build/test_target_action_green \
       && ./build/test_target_action_green
     ```
   - Result: All 3 fixtures passing cleanly (`gate_zero`, `d400_miss`, `success`), exit code 0 under UBSan.
   - Verified 9 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_target_action.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 176 bytes (-1956 bytes from 2132-byte target).
   - Relocations resolved: all 5 compiled relocations mapped and resolved with exact multiset check.
   - Classified strictly as **NonMatching** (30 matching bytes, 2102 byte differences).
   - The matching test serves as a structural correspondence diagnostic asserting >=25 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_target_action.py \
  tests/test_tactical_ai_combat_subsystem_controller_target_action_matching.py
```

The focused test run comprises **11 total tests** (10 behavioral tests in `test_tactical_ai_combat_subsystem_controller_target_action.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_target_action_matching.py`):
- One 32-bit native contract test with UBSan validating cleanup dispatch, D_004E2EA0 entry gate, func_0032D400 raycast gate,
  stack buffer forwarding identity, order dispatch, and success return value.
- Nine production source mutations independently compiled and verified
  rejected (cleanup call, entry gate inversion, entry gate return, raycast gate check, D400 a1 argument, D400 a2 argument, E580 dispatch, E6B0 dispatch, success return value).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
