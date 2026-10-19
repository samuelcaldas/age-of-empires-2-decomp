# Combat subsystem controller child sync at 0x32C420

`func_0032C420` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_child_sync.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces an 84-byte instruction sequence
(-4 bytes from 88-byte target code extent, 32 of 88 bytes matching, 56 byte differences;
classified strictly as NonMatching), matching stack frame (-0x20 = 32 bytes), callee-saved `$s0` and `$ra`,
child gate validation `func_00323B50`, optional child view notification `view->func_28(1)`, and return values.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032C420 = 0x32C420; // type:func size:0x58 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32C420, 0x32C478)` (88 bytes, 22 instructions), with zero internal padding.
  Symbol extent spans `[0x32C420, 0x32C478)` (88 bytes, `0x58`, 22 instructions).
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022C600, 0x0022C658)`.
- Predecessor continuity: directly preceded by `func_0032C320` ending at `0x32C420` (`0x0022C600`).
  Contiguous, zero padding. Zero overlap.
- Successor continuity: directly followed by `func_0032C480` starting at `0x32C480` (`0x0022C660`).
  Between `0x32C478` and `0x32C480`: exactly 8 bytes alignment padding `nop nop` (`0x00000000 0x00000000` at `0x32C478` and `0x32C47C`).
  Zero unclassified bytes, zero overlap.
- Stack frame: 32 bytes (`addiu $sp, $sp, -32` at `0x32C420`), saving `$ra` (16) and `$s0` (0) via quadword stores `sq`.
  Epilogue: `jr $ra` at `0x32C470` (+0x050) and delay slot stack teardown `addiu $sp, $sp, 32` at `0x32C474` (+0x054).

## Relocation manifest (1 relocation)

1. `+0x00C` (`0x32C42C`): `R_MIPS_26` to `func_00323B50` (target `0x323B50`, raw word `0x0C0C8ED4`, addend 0)

## Observable behavior

1. Child gate check: dispatch `func_00323B50(self)`.
   - If return value is 0, return 0 immediately and suppress view notification.
2. View notification:
   - Query `self->m_view` (offset `0x3408`).
   - If non-null, dispatch `self->m_view->func_28(1)` via vtable slot `0x28`.
3. Return 1.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_child_sync_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_child_sync.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_child_sync.h"

     int func_0032C420(CombatSubsystemControllerInstance *) {
         return -1;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_child_sync.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_child_sync_test.cpp -o build/test_child_sync_red \
       && ./build/test_child_sync_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: failed child gate must return 0` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ child sync dispatcher in `src/tactical_ai_combat_subsystem_controller_child_sync.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_child_sync.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_child_sync_test.cpp -o build/test_child_sync_green \
       && ./build/test_child_sync_green
     ```
   - Result: All 3 fixtures passing cleanly (`gate_fail`, `with_view`, `without_view`), exit code 0 under UBSan.
   - Verified 8 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_child_sync.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 84 bytes (-4 bytes from 88-byte target).
   - Relocations resolved: single relocation `func_00323B50` (+0x00C, `R_MIPS_26`) resolved with duplicate-rejecting multiset check.
   - Classified strictly as **NonMatching** (32 matching bytes, 56 byte differences).
   - The matching test serves as a structural correspondence diagnostic asserting >=30 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_child_sync.py \
  tests/test_tactical_ai_combat_subsystem_controller_child_sync_matching.py
```

The focused test run comprises **10 total tests** (9 behavioral tests in `test_tactical_ai_combat_subsystem_controller_child_sync.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_child_sync_matching.py`):
- One 32-bit native contract test with UBSan validating child gate failure, child sync with view, and child sync without view.
- Eight production source mutations independently compiled and verified
  rejected (gate check inversion, gate return inversion, self argument identity, view null check inversion, view func_28 dispatch, view argument identity, final return value, without-view return value).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
