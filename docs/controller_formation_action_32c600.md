# Combat subsystem controller formation action coordinator at 0x32C600

`func_0032C600` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_formation.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 204-byte partial candidate sequence
(-1224 bytes from 1428-byte target code extent, 30 of 1428 bytes matching, 1398 byte differences;
classified strictly as NonMatching), scoping the primary entry gate `D_004E2EA0`, raycast validation `func_0032D400`,
buffer forwarding `func_0032E580`, manager mode query `func_186010`, and target event dispatching.
Full formation coordinator sub-branches (including view callbacks and secondary formation queries) are unmodeled in this partial slice.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032C600 = 0x32C600; // type:func size:0x594 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32C600, 0x32CB94)` (1,428 bytes, 357 instructions), with zero internal padding.
  Symbol extent spans `[0x32C600, 0x32CB94)` (1,428 bytes, `0x594`, 357 instructions).
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022C7E0, 0x0022CD74)`.
- Predecessor continuity: directly preceded by `func_0032C5F0` ending at `0x32C5F8` (`0x0022C7D8`).
  Between `0x32C5F8` and `0x32C600`: exactly 8 bytes alignment padding `nop nop` (`0x00000000 0x00000000`).
  Zero overlap.
- Successor continuity: directly followed by `func_0032CBA0` starting at `0x32CBA0` (`0x0022CD80`),
  size `0x854` (2,132 bytes).
  Between `0x32CB94` and `0x32CBA0`: exactly 12 bytes alignment padding `nop nop nop` (`0x00000000 0x00000000 0x00000000`).
  Zero unclassified bytes, zero overlap.
- Stack frame: 176 bytes (`addiu $sp, $sp, -176` = `0x27BDFF50` at `0x32C600`), saving `$ra` (128) and
  callee-saved registers `$s0`–`$s5` via quadword stores `sq`.
  Epilogue: `jr $ra` at `0x32CB8C` (+0x58C) and delay slot stack teardown `addiu $sp, $sp, 176` at `0x32CB90` (+0x590).

## Relocation manifest

### Compiled candidate relocations (10 relocations)
The 204-byte candidate object resolves exactly 10 relocations with a duplicate-rejecting multiset check:
1. `+0x010`: `R_MIPS_GPREL16` to `D_004E2EA0`
2. `+0x040`: `R_MIPS_26` to `func_0032D400`
3. `+0x060`: `R_MIPS_26` to `func_0032E580`
4. `+0x068`: `R_MIPS_GPREL16` to `D_004E3180`
5. `+0x074`: `R_MIPS_26` to `func_186010`
6. `+0x088`: `R_MIPS_26` to `func_1AAB30`
7. `+0x090`: `R_MIPS_26` to `func_26A680`
8. `+0x09C`: `R_MIPS_26` to `func_1830E0`
9. `+0x0A4`: `R_MIPS_26` to `func_262FA0`
10. `+0x0AC`: `R_MIPS_26` to `func_332E60`

### Full ELF function relocations (25 relocations)
The full 1,428-byte original binary function contains 25 relocations:
- 11 `R_MIPS_GPREL16` relocations:
  - `+0x020`: `D_004E2EA0` (addend -31,008)
  - `+0x080`, `+0x0B8`, `+0x0C0`, `+0x104`, `+0x174`, `+0x1C4`, `+0x2EC`, `+0x3D8`, `+0x484`, `+0x4BC`: `D_004E3180` (addend -30,272)
- 14 `R_MIPS_26` JAL relocations (addend 0):
  - `+0x05C`: `func_0032D400`
  - `+0x078`: `func_0032E580`
  - `+0x094`, `+0x0B4`, `+0x11C`, `+0x188`, `+0x290`, `+0x4B8`: `func_186010` (6 calls)
  - `+0x33C`, `+0x394`: `func_1AAB30` (2 calls)
  - `+0x388`: `func_26A680`
  - `+0x400`: `func_1830E0`
  - `+0x41C`: `func_262FA0`
  - `+0x49C`: `func_332E60`

## Observable behavior (Implemented Partial Scope)

1. Entry gate check: query `D_004E2EA0`. If 0, return 0 immediately.
2. Raycast query: dispatch `func_0032D400(self, 40, 0, x, y, buf, 0, 1)`.
   - If return value != 51, return 0.
3. Success path: dispatch `func_0032E580(self, buf)`.
4. Target event dispatch (when `m_target != nullptr`):
   - Dispatch `func_186010(D_004E3180, a3)`.
   - Dispatch `func_1AAB30(self->m_target, a3)`.
   - Dispatch `func_26A680(self->m_target)`.
   - Dispatch `func_1830E0(self->m_target, a3)`.
   - Dispatch `func_262FA0(self->m_target)`.
   - Dispatch `func_332E60(self->m_target)`.
5. Return 1.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_formation_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_formation.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_formation.h"

     int func_0032C600(CombatSubsystemControllerInstance *, int, int, int) {
         return -1;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_formation.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_formation_test.cpp -o build/test_formation_red \
       && ./build/test_formation_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: D_004E2EA0==0 must return 0` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ partial formation coordinator in `src/tactical_ai_combat_subsystem_controller_formation.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_formation.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_formation_test.cpp -o build/test_formation_green \
       && ./build/test_formation_green
     ```
   - Result: All 4 fixtures passing cleanly (`gate_zero`, `d400_miss`, `success`, `target_events`), exit code 0 under UBSan.
   - Active target fixture asserts exact 8-call ordered sequencing: `func_0032D400` -> `func_0032E580` -> `func_186010` -> `func_1AAB30` -> `func_26A680` -> `func_1830E0` -> `func_262FA0` -> `func_332E60`.
   - Verified 13 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_formation.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 204 bytes (-1224 bytes from 1428-byte target).
   - Relocations resolved: all 10 compiled relocations mapped and resolved with exact multiset check.
   - Classified strictly as **NonMatching** (30 matching bytes, 1398 byte differences).
   - The matching test serves as a structural correspondence diagnostic asserting >=25 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_formation.py \
  tests/test_tactical_ai_combat_subsystem_controller_formation_matching.py
```

The focused test run comprises **15 total tests** (14 behavioral tests in `test_tactical_ai_combat_subsystem_controller_formation.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_formation_matching.py`):
- One 32-bit native contract test with UBSan validating D_004E2EA0 entry gate, func_0032D400 raycast gate,
  stack buffer forwarding identity, success return value, and 8-call ordered callback sequencing on active target.
- Thirteen production source mutations independently compiled and verified
  rejected (entry gate inversion, entry gate return, raycast gate check, D400 a1 argument, D400 a2 argument, E580 dispatch, success return value, func_186010 call, func_1AAB30 call, func_26A680 call, func_1830E0 call, func_262FA0 call, func_332E60 call).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
