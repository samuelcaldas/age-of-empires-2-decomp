# Combat subsystem controller decrement by ID at 0x32E640

`func_0032E640` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_decrement_by_id.cpp`.
A fresh MWCC PS2 2.3.1.01 build achieves an **exact 100.00% bit-for-bit match (100 of 100 bytes)**,
traversing a contiguous 20-byte struct table at `self->m_table` with `m_count` entries,
testing `active == 1` and `id == target_id`, and subtracting `decrement` from `count`.
Promoted to **Matching** in `configure.py` following independent review clearance and 100.00% exact bit-for-bit compiler/link verification.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032E640 = 0x32E640; // type:func size:0x64 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32E640, 0x32E6A4)` (100 bytes, `0x64`, 25 instructions), with zero internal padding.
  Symbol extent spans `[0x32E640, 0x32E6A4)` (100 bytes, `0x64`, 25 instructions).
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022E820, 0x0022E884)`.
- Predecessor continuity: directly preceded by `func_0032E580` ending at `0x32E640` (`0x0022E820`).
  Between `0x32E640` and `0x32E640`: exactly 0 bytes padding (immediate successor).
  Zero overlap.
- Successor continuity: directly followed by `func_0032E6B0` starting at `0x32E6B0` (`0x0022E890`),
  size `0x170` (368 bytes).
  Between `0x32E6A4` and `0x32E6B0`: exactly 12 bytes alignment padding `nop nop nop` (`0x00000000 0x00000000 0x00000000`).
  Zero unclassified bytes, zero overlap.
- Leaf function without stack frame allocation (`$sp` unchanged).
  Epilogue: `jr $ra` at `0x32E69C` (+0x5C) and delay slot `nop` at `0x32E6A0` (+0x60).

## Relocation manifest

### Compiled candidate relocations (0 relocations)
The 100-byte candidate object resolves 0 relocations.

### Full ELF function relocations (0 relocations)
The full 100-byte original binary function contains 0 relocations (pure leaf table traversal routine).

## Observable behavior

1. Loop traversal: iterate `i` from 0 to `self->m_count - 1`.
2. Stride address calculation: compute entry address at `m_table + i * 20` bytes.
3. Matching check:
   - If `entry->active == 1` and `entry->id == target_id`:
     subtract `entry->decrement` from `entry->count`.
4. Inactive or mismatched entries: leave `count` unmodified.
5. Exit: return void.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_decrement_by_id_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_decrement_by_id.cpp` (no-op).
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_decrement_by_id.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_decrement_by_id_test.cpp -o build/test_dec_by_id_red \
       && ./build/test_dec_by_id_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: matching active entry count must be decremented by decrement value` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ table decrement helper in `src/tactical_ai_combat_subsystem_controller_decrement_by_id.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_decrement_by_id.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_decrement_by_id_test.cpp -o build/test_dec_by_id_green \
       && ./build/test_dec_by_id_green
     ```
   - Result: All 5 fixtures passing cleanly (`one_match`, `zero_count`, `inactive`, `mismatch`, `multiple`), exit code 0 under UBSan.
   - Verified 9 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_decrement_by_id.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size exactly 100 bytes (0 byte differences).
   - Relocations resolved: 0 relocations.
   - **100.00% exact bit-for-bit match (100 of 100 bytes)** achieved.
   - Verified with target compiler/wibo comparison against the pinned ELF binary in `tests/test_tactical_ai_combat_subsystem_controller_decrement_by_id_matching.py`.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_decrement_by_id.py \
  tests/test_tactical_ai_combat_subsystem_controller_decrement_by_id_matching.py
```

The focused test run comprises **11 total tests** (10 behavioral tests in `test_tactical_ai_combat_subsystem_controller_decrement_by_id.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_decrement_by_id_matching.py`):
- One 32-bit native contract test with UBSan validating single match decrement, zero-count table safety,
  inactive entry preservation, mismatched ID preservation, and multiple matches processing.
- Nine production source mutations independently compiled and verified
  rejected (active check, active val, id check, decrement op, decrement val, loop break, loop start, zero bound, count target).
- One 100.00% exact bit-for-bit match test compiling fresh with Ninja/MWCC and verifying
  bytecode parity against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged pending independent review.
