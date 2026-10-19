# Combat subsystem controller leaf stub at 0x32C5F0

`func_0032C5F0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_stub.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces an exact 8-byte instruction sequence
(matching target code extent 8/8 bytes, **100.00% exact match**, 0 byte differences),
0-byte stack frame (leaf function), no relocations, and pure leaf no-op behavior.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032C5F0 = 0x32C5F0; // type:func size:0x8 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32C5F0, 0x32C5F8)` (8 bytes, 2 instructions), with zero internal padding.
  Symbol extent spans `[0x32C5F0, 0x32C5F8)` (8 bytes, `0x8`, 2 instructions).
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022C7D0, 0x0022C7D8)`.
- Predecessor continuity: directly preceded by `func_0032C500` ending at `0x32C5E8` (`0x0022C7C8`).
  Between `0x32C5E8` and `0x32C5F0`: exactly 8 bytes alignment padding `nop nop` (`0x00000000 0x00000000`).
  Zero overlap.
- Successor continuity: directly followed by `func_0032C600` starting at `0x32C600` (`0x0022C7E0`),
  size `0x594` (1,428 bytes).
  Between `0x32C5F8` and `0x32C600`: exactly 8 bytes alignment padding `nop nop` (`0x00000000 0x00000000`).
  Zero unclassified bytes, zero overlap.
- Stack frame: 0 bytes (leaf function, no stack allocation).
  Instructions:
  `0x32C5F0: 0x03E00008 jr $ra`
  `0x32C5F4: 0x00000000 nop`

## Relocation manifest (0 relocations)

No relocations (pure leaf stub).

## Observable behavior

1. Leaf no-op stub: performs no state mutation, consumes no memory, and returns `void`.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_stub_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_stub.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_stub.h"

     void func_0032C5F0(CombatSubsystemControllerInstance *self) {
         if (self) *(int*)self = 0xDEADBEEF;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_stub.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_stub_test.cpp -o build/test_stub_red \
       && ./build/test_stub_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: func_0032C5F0 must not mutate instance memory (word 0)` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ stub in `src/tactical_ai_combat_subsystem_controller_stub.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_stub.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_stub_test.cpp -o build/test_stub_green \
       && ./build/test_stub_green
     ```
   - Result: All 2 fixtures passing cleanly (`noop`, `null`), exit code 0 under UBSan.
   - Verified 4 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_stub.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 8 bytes (**100.00% exact byte-for-byte match**, 8/8 matching bytes, 0 differences).
   - Relocations resolved: 0 relocations.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_stub.py \
  tests/test_tactical_ai_combat_subsystem_controller_stub_matching.py
```

The focused test run comprises **6 total tests** (5 behavioral tests in `test_tactical_ai_combat_subsystem_controller_stub.py` and 1 exact matching test in `test_tactical_ai_combat_subsystem_controller_stub_matching.py`):
- One 32-bit native contract test with UBSan validating noop memory preservation and null self safety.
- Four production source mutations independently compiled and verified
  rejected (mutating word 0, mutating word 1, mutating word 2, mutating word 3).
- One exact matching test compiling fresh with Ninja/MWCC and verifying
  **100.00% byte-for-byte identity** against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
