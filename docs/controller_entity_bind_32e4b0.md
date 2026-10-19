# Combat subsystem controller entity bind at 0x32E4B0

`func_0032E4B0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_entity_bind.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 256-byte candidate sequence
(+48 bytes from 208-byte target code extent, 52 matching bytes, 6 relocations resolved with duplicate-rejecting multiset check;
classified strictly as NonMatching), scoping pick raycast `func_0032D400(self, 41, 2, x, y, buf, 0, 1)`,
entity handle acquisition `sub_1C8C00`, string lookup `sub_1F6EA0`, string copy `strcpy`, handle release `sub_1C8C10`,
and fallback delegation `sub_1F6EF0(self, x, y, out_name, a4)`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032E4B0 = 0x32E4B0; // type:func size:0xD0 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32E4B0, 0x32E580)` (208 bytes, `0xD0`, 52 instructions), with zero internal padding.
  Symbol extent spans `[0x32E4B0, 0x32E580)` (208 bytes, `0xD0`, 52 instructions).
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022E690, 0x0022E760)`.
- Predecessor continuity: directly preceded by `func_0032E460` ending at `0x32E4AC` (`0x0022E68C`).
  Between `0x32E4AC` and `0x32E4B0`: exactly 4 bytes alignment padding `nop` (`0x00000000`).
  Zero overlap.
- Successor continuity: directly followed by canonical 192-byte coordinate clamp function `func_0032E580` starting at `0x32E580` (`0x0022E760`),
  spanning `[0x32E580, 0x32E640)` (with interior address `0x32E5E0`) and ending at sole epilogue `jr $ra` at `0x32E638`.
  Between `0x32E580` and `0x32E580`: exactly 0 bytes padding (immediate successor).
  Zero unclassified bytes, zero overlap.
- Stack frame: 128 bytes (`addiu $sp, $sp, -128` = `0x27BDFF80` at `0x32E4B0`), saving `$ra` (80), `$s4` (64),
  `$s3` (48), `$s2` (32), `$s1` (16), `$s0` (0) via quadword stores `sq`.
  Epilogue: `jr $ra` at `0x32E578` (+0xC8) and delay slot stack teardown `addiu $sp, $sp, 128` at `0x32E57C` (+0xCC).

## Relocation manifest

### Compiled candidate relocations (6 relocations)
The 256-byte candidate object resolves exactly 6 relocations with a duplicate-rejecting multiset check:
1. `+0x048`: `R_MIPS_26` to `func_0032D400`
2. `+0x084`: `R_MIPS_26` to `sub_1C8C00`
3. `+0x090`: `R_MIPS_26` to `sub_1F6EA0`
4. `+0x0AC`: `R_MIPS_26` to `strcpy`
5. `+0x0B8`: `R_MIPS_26` to `sub_1C8C10`
6. `+0x0D8`: `R_MIPS_26` to `sub_1F6EF0`

### Full ELF function relocations (6 relocations)
The full 208-byte original binary function contains 6 relocations (all `R_MIPS_26`, 0 `R_MIPS_GPREL16`):
1. `+0x040`: `R_MIPS_26` to `func_0032D400`
2. `+0x060`: `R_MIPS_26` to `sub_1C8C00`
3. `+0x06C`: `R_MIPS_26` to `sub_1F6EA0`
4. `+0x078`: `R_MIPS_26` to `strcpy`
5. `+0x084`: `R_MIPS_26` to `sub_1C8C10`
6. `+0x0A8`: `R_MIPS_26` to `sub_1F6EF0`

## Observable behavior (Implemented Scope)

1. Pick raycast query: dispatch `func_0032D400(self, 41, 2, x, y, buf, 0, 1)`.
2. Entity resolution branch (`pick_res == 52`):
   - Extract entity handle from buffer.
   - Dispatch `sub_1C8C00(entity)`.
   - Dispatch `sub_1F6EA0(self, handle)`.
   - Copy resolved string into `out_name` via `strcpy`.
   - Dispatch `sub_1C8C10(entity)`.
   - Return 1.
3. Fallback delegation (`pick_res != 52`):
   - Dispatch `sub_1F6EF0(self, x, y, out_name, a4)`.
   - Return result of `sub_1F6EF0`.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_entity_bind_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_entity_bind.cpp` returning -1.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_entity_bind.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_entity_bind_test.cpp -o build/test_entity_bind_red \
       && ./build/test_entity_bind_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: pick 52 hit must return 1` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ entity bind coordinator in `src/tactical_ai_combat_subsystem_controller_entity_bind.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_entity_bind.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_entity_bind_test.cpp -o build/test_entity_bind_green \
       && ./build/test_entity_bind_green
     ```
   - Result: All fixtures passing cleanly (`pick_52`, `fallback`), exit code 0 under UBSan.
   - Verified 9 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_entity_bind.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 256 bytes (+48 bytes from 208-byte target).
   - Relocations resolved: all 6 compiled relocations mapped and resolved with exact multiset check.
   - Classified strictly as **NonMatching** (52 matching bytes).
   - The matching test serves as a structural correspondence diagnostic asserting >=40 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_entity_bind.py \
  tests/test_tactical_ai_combat_subsystem_controller_entity_bind_matching.py
```

The focused test run comprises **11 total tests** (10 behavioral tests in `test_tactical_ai_combat_subsystem_controller_entity_bind.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_entity_bind_matching.py`):
- One 32-bit native contract test with UBSan validating D400 mode 41 arguments, return-52 binding sequence,
  strcpy destination buffer, and fallback delegation return propagation.
- Nine production source mutations independently compiled and verified
  rejected (D400 mode, D400 flag, pick 52 gate, sub_1C8C00 call, sub_1F6EA0 res, sub_1C8C10 call, strcpy call, return hit, fallback return propagation).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
