# Combat subsystem controller selection engine at 0x32AAD0

`func_0032AAD0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_selection.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces an initial 188-byte instruction sequence
(-4,428 bytes from 4,616-byte target, 31 of 4,616 bytes matching), matching stack frame (-0xD0 = 208 bytes),
argument preservation in `$s4`, callee-saved `$s0`–`$s7` and `$fp`, gate validation (`D_004E3180->m_mode` in `{4, 5, 6, 7}`),
`m_field_190` branch routing, manager idle check `func_185DC0`, fallback notification `func_1F65A0`,
and status dispatch `func_225590`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032AAD0 = 0x32AAD0; // type:func size:0x1208 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32AAD0, 0x32BCD8)`, file `[0x0022ACB0, 0x0022BEB8)`.
  The function body spans 4,616 instruction bytes (`0x1208`, 1,154 instructions). Symbol size is `0x1208`.
  Code ends at `0x32BCD4` (`addiu $sp, $sp, 208` in delay slot of `jr $ra` at `0x32BCD0`).
- Predecessor continuity: directly preceded by `func_0032A8F0` terminating at `0x32AAC8` with
  8 bytes alignment padding `nop` (`0x00000000` at `0x32AAC8` and `0x32AACC`). Zero overlap.
- Successor continuity: directly followed by `func_0032BCE0` starting at `0x32BCE0`, with
  8 bytes alignment padding `nop` (`0x00000000` at `0x32BCD8` and `0x32BCDC`). Zero overlap.
- Stack frame: 208 bytes (`addiu $sp, $sp, -0xD0`), saving `$ra` (0xA0),
  `$fp` (0x90), and all 8 callee-saved `$s0`–`$s7` (0x10 to 0x80).

## Observable behavior

1. Check mode gate:
   - System manager mode must be in `{4, 5, 6, 7}`.
   - If not in set, return 0.
2. Check `self->m_field_190`:
   - If nonzero:
     - Dispatch `self->m_vtable->func_110(self)`.
     - Return 1.
3. Fallback notification:
   - Dispatch `func_1F65A0(self)`.
4. Check manager status via `func_185DC0(D_004E3180)`:
   - If busy (`!= 0`), return 0.
5. If idle (`== 0`):
   - Dispatch `func_225590(18)`.
   - Return 1.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_selection_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_selection.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_selection.h"

     int func_0032AAD0(CombatSubsystemControllerInstance *, int, int, int, int) {
         return 0;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_selection.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_selection_test.cpp -o build/test_sel_red \
       && ./build/test_sel_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: field_190 branch must return 1` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ selection engine in `src/tactical_ai_combat_subsystem_controller_selection.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_selection.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_selection_test.cpp -o build/test_sel_green \
       && ./build/test_sel_green
     ```
   - Result: All 5 fixtures passing cleanly (`gate_rejection` for modes 0/1/2, `supported_modes` for modes 4/5/6/7, `field_190_branch`, `busy_manager`, `idle_manager`), exit code 0 under UBSan.
   - Verified 7 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_selection.py`.
   - Verified strict call sequence and early-exit suppression: `field_190` branch dispatches `func_110` and suppresses all manager calls; busy manager suppresses `func_225590`; idle manager executes full sequence `func_1F65A0` -> `func_185DC0` -> `func_225590(18)`.
3. **Refactor & Matching Diagnostics:**
   - Evaluated compiler register allocation: `$s4` preserved as `self`.
   - Built with verified MWCC PS2 flags: initial candidate size 188 bytes (-4,428 bytes from 4,616-byte target).
   - Classified strictly as **NonMatching** (exact 31 matching bytes, 157 byte differences).
   - The matching test serves as a structural correspondence diagnostic asserting exactly 31 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_selection.py \
  tests/test_tactical_ai_combat_subsystem_controller_selection_matching.py
```

The focused test run comprises **9 passing tests** (or 8 passing, 1 skipped when compiler/wibo are unprovisioned):
- One 32-bit native contract test with UBSan validating mode gate rejection (modes 0, 1, 2), supported modes (4, 5, 6, 7), field_190 routing and suppression, manager busy rejection and suppression, and idle manager full sequence dispatch.
- Seven production source mutations independently compiled and verified
  rejected (gate return, field_190 return, field_190 func_110 call, busy return, idle return, func_1F65A0 call, func_225590 argument).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment (exactly 31 bytes) against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
