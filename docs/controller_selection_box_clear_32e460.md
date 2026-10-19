# Combat subsystem controller selection box clear at 0x32E460

`func_0032E460` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_selection_box_clear.cpp`.
A fresh MWCC PS2 2.3.1.01 build achieves an **exact 100.00% bit-for-bit match (76 of 76 bytes)**,
resolving the `sub_31A720` call and self virtual method dispatch `self->func_28(1)` (offset 40, 0x28).
Per standing repository policy, it remains registered as NonMatching pending independent review clearance and promotion.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032E460 = 0x32E460; // type:func size:0x4C absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32E460, 0x32E4AC)` (76 bytes, `0x4C`, 19 instructions), with zero internal padding.
  Symbol extent spans `[0x32E460, 0x32E4AC)` (76 bytes, `0x4C`, 19 instructions).
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022E640, 0x0022E68C)`.
- Predecessor continuity: directly preceded by `func_0032E220` ending at `0x32E458` (`0x0022E638`).
  Between `0x32E458` and `0x32E460`: exactly 8 bytes alignment padding `nop nop` (`0x00000000 0x00000000`).
  Zero overlap.
- Successor continuity: directly followed by `func_0032E4B0` starting at `0x32E4B0` (`0x0022E690`),
  size `0xD0` (208 bytes).
  Between `0x32E4AC` and `0x32E4B0`: exactly 4 bytes alignment padding `nop` (`0x00000000`).
  Zero unclassified bytes, zero overlap.
- Stack frame: 32 bytes (`addiu $sp, $sp, -32` = `0x27BDFFE0` at `0x32E460`), saving `$ra` (16) and
  callee-saved register `$s0` (0) via quadword stores `sq`.
  Epilogue: `jr $ra` at `0x32E4A4` (+0x44) and delay slot stack teardown `addiu $sp, $sp, 32` at `0x32E4A8` (+0x48).

## Relocation manifest

### Compiled candidate relocations (1 relocation)
The 76-byte candidate object resolves exactly 1 relocation with a duplicate-rejecting multiset check:
1. `+0x01C`: `R_MIPS_26` to `sub_31A720` (addend 0)

### Full ELF function relocations (1 relocation)
The full 76-byte original binary function contains 1 relocation:
1. `+0x01C`: `R_MIPS_26` to `sub_31A720` (addend 0)
0 `R_MIPS_GPREL16` relocations.

## Observable behavior

1. Reset box bounds: dispatch `sub_31A720(self, -1, -1, -1, -1)`.
2. Update controller state: dispatch virtual method 40 (`self->func_28(1)`).
3. Return 0.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_selection_box_clear_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_selection_box_clear.cpp` returning -1.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_selection_box_clear.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_selection_box_clear_test.cpp -o build/test_sel_box_clear_red \
       && ./build/test_sel_box_clear_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: func_0032E460 must return 0` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ selection box clear helper in `src/tactical_ai_combat_subsystem_controller_selection_box_clear.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_selection_box_clear.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_selection_box_clear_test.cpp -o build/test_sel_box_clear_green \
       && ./build/test_sel_box_clear_green
     ```
   - Result: Contract test passing cleanly (`clear_contracts`), exit code 0 under UBSan.
   - Verified 9 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_selection_box_clear.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size exactly 76 bytes (0 byte differences).
   - Relocations resolved: single `R_MIPS_26` relocation to `sub_31A720` matches.
   - **100.00% exact bit-for-bit match (76 of 76 bytes)** achieved.
   - Verified with target compiler/wibo comparison against the pinned ELF binary in `tests/test_tactical_ai_combat_subsystem_controller_selection_box_clear_matching.py`.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_selection_box_clear.py \
  tests/test_tactical_ai_combat_subsystem_controller_selection_box_clear_matching.py
```

The focused test run comprises **11 total tests** (10 behavioral tests in `test_tactical_ai_combat_subsystem_controller_selection_box_clear.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_selection_box_clear_matching.py`):
- One 32-bit native contract test with UBSan validating exact `sub_31A720(self, -1, -1, -1, -1)` parameters, `func_28(1)` call order,
  and return value 0.
- Nine production source mutations independently compiled and verified
  rejected (sub_31A720 call, 4 arguments to sub_31A720, func_28 call, func_28 a1 arg, call order inversion, return value).
- One 100.00% exact bit-for-bit match test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode parity against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged pending independent review.
