# Combat subsystem controller pick query evaluator at 0x32D400

`func_0032D400` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_pick_query.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 412-byte partial candidate sequence
(-1260 bytes from 1672-byte target code extent, 67 of 1672 bytes matching, 1605 byte differences;
classified strictly as NonMatching), scoping 8 ABI parameter registers, mode-41 virtual dispatch,
mode-42 recursive self-dispatch, and `sub_31C7F0` fallback routing.
Remaining complex inner raycast traversal and grid-distance loops are unmodeled in this partial slice.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032D400 = 0x32D400; // type:func size:0x688 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32D400, 0x32DA88)` (1,672 bytes, 418 instructions), with zero internal padding.
  Symbol extent spans `[0x32D400, 0x32DA88)` (1,672 bytes, `0x688`, 418 instructions).
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022D5E0, 0x0022DC68)`.
- Predecessor continuity: directly preceded by `func_0032CBA0` ending at `0x32D3F4` (`0x0022D5D4`).
  Between `0x32D3F4` and `0x32D400`: exactly 12 bytes alignment padding `nop nop nop` (`0x00000000 0x00000000 0x00000000`).
  Zero overlap.
- Successor continuity: directly followed by `func_0032DA90` starting at `0x32DA90` (`0x0022DC70`),
  size `0x640` (1,600 bytes).
  Between `0x32DA88` and `0x32DA90`: exactly 8 bytes alignment padding `nop nop` (`0x00000000 0x00000000`).
  Zero unclassified bytes, zero overlap.
- Stack frame: 1024 bytes (`addiu $sp, $sp, -1024` = `0x27BDF800` at `0x32D400`), saving `$ra` (144) and
  callee-saved registers via quadword stores `sq`.
  Epilogue: `jr $ra` at `0x32DA80` (+0x680) and delay slot stack teardown `addiu $sp, $sp, 1024` at `0x32DA84` (+0x684).

## Relocation manifest

### Compiled candidate relocations (2 relocations)
The 412-byte candidate object resolves exactly 2 relocations with a duplicate-rejecting multiset check:
1. `+0x130`: `R_MIPS_26` to `func_0032D400`
2. `+0x168`: `R_MIPS_26` to `sub_31C7F0`

### Full ELF function relocations (4 relocations)
The full 1,672-byte original binary function contains 4 relocations (all `R_MIPS_26`, 0 `R_MIPS_GPREL16`):
1. `+0x218` (0x32D618): `R_MIPS_26` to `func_117AF8`
2. `+0x23C` (0x32D63C): `R_MIPS_26` to `func_117AF8`
3. `+0x614` (0x32DA14): `R_MIPS_26` to `func_0032D400` (recursive self-dispatch)
4. `+0x64C` (0x32DA4C): `R_MIPS_26` to `sub_31C7F0`

## Observable behavior (Implemented Partial Scope)

1. Argument unpacking:
   - Receives 8 ABI arguments in registers (`$a0`–`$a3`, `$t0`–`$t3`).
   - Extracts 8-bit `mode` (`$a1 & 0xFF`).
2. Mode 41 evaluation:
   - Zeroes the initial 20 bytes of `buf`.
   - If `(flag & 0xFF) == 0`: queries virtual method `vtable->func_120(self, x, y, 0, 40, 15, 4, 1)`.
   - If `(flag & 0xFF) != 0`: queries virtual method `vtable->func_120(self, x, y, 10, 30, 15, 4, 1)`.
   - If `func_120` returns 0: returns 50 immediately.
   - If `func_120` returns 1: returns 52.
3. Mode 42 evaluation:
   - Recursively invokes `func_0032D400(self, 41, flag, x, y, buf, target_sub, 1)`.
   - If the recursive call returns 52: returns 52 immediately.
   - If the recursive call returns != 52: falls through to fallback.
4. Fallback evaluation:
   - Dispatches to `sub_31C7F0(self, 40, flag, x, y, buf, target_sub, recurse_flag)`.
   - Returns masked 8-bit status (`ret & 0xFF`).

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_pick_query_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_pick_query.cpp` returning -1.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_pick_query.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_pick_query_test.cpp -o build/test_pick_query_red \
       && ./build/test_pick_query_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: mode 41 flag 0 zero return must return 50` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ partial pick query evaluator in `src/tactical_ai_combat_subsystem_controller_pick_query.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_pick_query.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_pick_query_test.cpp -o build/test_pick_query_green \
       && ./build/test_pick_query_green
     ```
   - Result: All 4 fixtures passing cleanly (`mode41_flag0`, `mode41_flag1`, `mode42_recurse`, `fallback`), exit code 0 under UBSan.
   - Verified 9 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_pick_query.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 412 bytes (-1260 bytes from 1672-byte target).
   - Relocations resolved: all 2 compiled relocations mapped and resolved with exact multiset check.
   - Classified strictly as **NonMatching** (67 matching bytes, 1605 byte differences).
   - The matching test serves as a structural correspondence diagnostic asserting >=30 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_pick_query.py \
  tests/test_tactical_ai_combat_subsystem_controller_pick_query_matching.py
```

The focused test run comprises **11 total tests** (10 behavioral tests in `test_tactical_ai_combat_subsystem_controller_pick_query.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_pick_query_matching.py`):
- One 32-bit native contract test with UBSan validating 8 ABI arguments, mode 41 virtual dispatch, mode 42 recursion,
  buffer zeroing, and fallback return value.
- Nine production source mutations independently compiled and verified
  rejected (mode 41 gate, mode 41 zero return, mode 41 flag 0 args, mode 41 flag 1 args, mode 41 buffer zero loop, mode 42 gate, mode 42 recurse mode, fallback mode, fallback 8-bit mask).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
