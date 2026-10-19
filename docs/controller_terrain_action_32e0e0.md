# Combat subsystem controller terrain action at 0x32E0E0

`func_0032E0E0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_terrain_action.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 392-byte candidate sequence
(+76 bytes from 316-byte target code extent, 56 matching bytes, 6 relocations resolved with duplicate-rejecting multiset check;
classified strictly as NonMatching), scoping cleanup `func_0032E820`, entry gate `D_004E2EA0`, target query method 168,
pick query `func_0032D400`, buffer forwarding `func_0032E580`, target query method 180, order dispatch `func_0032E6B0(self, 2961, 0, -1, 1)`,
and manager notification via method at offset 0x18 (24 bytes, slot 6) on `D_004E3180`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032E0E0 = 0x32E0E0; // type:func size:0x138 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent:
  - Canonical `symbols.txt` records `size: 0x138` (312 bytes), ending at `0x32E218` (after `jr $ra` at `0x32E214`).
  - True executable code boundary spans VRAM `[0x32E0E0, 0x32E21C)` (316 bytes, `0x13C`, 79 instructions),
    enclosing the return delay slot instruction `addiu $sp, $sp, 112` (`0x27BD0070`) at `0x32E218`.
  - File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022E2C0, 0x0022E3FC)`.
- Predecessor continuity: directly preceded by `func_0032DA90` ending at `0x32E0D4` (`0x0022E2B4`).
  Between `0x32E0D4` and `0x32E0E0`: exactly 12 bytes alignment padding `nop nop nop` (`0x00000000 0x00000000 0x00000000`).
  Zero overlap.
- Successor continuity: directly followed by `func_0032E220` starting at `0x32E220` (`0x0022E400`),
  size `0x238` (568 bytes).
  Between `0x32E21C` and `0x32E220`: exactly 4 bytes alignment padding `nop` (`0x00000000`).
  Zero unclassified bytes, zero overlap.
- Stack frame: 112 bytes (`addiu $sp, $sp, -112` = `0x27BDFF90` at `0x32E0E0`), saving `$ra` (64), `$s2` (48), `$s1` (32),
  `$s0` (16) via quadword stores `sq`.
  Epilogue: `jr $ra` at `0x32E214` (+0x134) and delay slot stack teardown `addiu $sp, $sp, 112` at `0x32E218` (+0x138).

## Relocation manifest

### Compiled candidate relocations (6 relocations)
The 392-byte candidate object resolves exactly 6 relocations with a duplicate-rejecting multiset check:
1. `+0x020`: `R_MIPS_26` to `func_0032E820`
2. `+0x028`: `R_MIPS_GPREL16` to `D_004E2EA0` (addend -31,008 / 0x86E0)
3. `+0x0D0`: `R_MIPS_26` to `func_0032D400`
4. `+0x0EC`: `R_MIPS_26` to `func_0032E580`
5. `+0x130`: `R_MIPS_26` to `func_0032E6B0`
6. `+0x138`: `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272 / 0x89C0)

### Full ELF function relocations (6 relocations)
The full 316-byte original binary function contains 6 relocations:
1. `+0x01C`: `R_MIPS_26` to `func_0032E820`
2. `+0x024`: `R_MIPS_GPREL16` to `D_004E2EA0` (addend -31,008)
3. `+0x098`: `R_MIPS_26` to `func_0032D400`
4. `+0x0B4`: `R_MIPS_26` to `func_0032E580`
5. `+0x100`: `R_MIPS_26` to `func_0032E6B0`
6. `+0x108`: `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)

## Observable behavior (Implemented Scope)

1. Subsystem cleanup: dispatch `func_0032E820(self)`.
2. Entry gate: load `D_004E2EA0`; if 0, return 0 immediately.
3. Target query: call target vtable method at offset 168 (`target->m_sub6960->m_vtable->func_168(target, sp104, sp110, -1, -1, -1, -1, 0)`).
   - If return value is 0, return 0 immediately.
4. Pick query evaluator: dispatch `func_0032D400(self, 42, 1, a1, a2, buf, 0, 1)`.
   - If return code is 50, skip buffer forwarding and order dispatch, proceeding directly to manager notification.
5. Buffer processing & Order dispatch:
   - Dispatch `func_0032E580(self, buf)`.
   - Call target vtable method at offset 180 (`target->m_sub6960->m_vtable->func_180(target, 0)`).
   - If result != 0, dispatch combat order `func_0032E6B0(self, 2961, 0, -1, 1)`.
6. Manager notification: dispatch virtual method at offset 0x18 (24 bytes, slot 6) on `D_004E3180` (`D_004E3180->m_vtable->func_18(D_004E3180, 0, 0)`).
7. Return `s1` (status code 0 or 1).

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_terrain_action_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_terrain_action.cpp` returning -1.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_terrain_action.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_terrain_action_test.cpp -o build/test_terrain_action_red \
       && ./build/test_terrain_action_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: D_004E2EA0==0 must return 0` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ terrain action coordinator in `src/tactical_ai_combat_subsystem_controller_terrain_action.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_terrain_action.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_terrain_action_test.cpp -o build/test_terrain_action_green \
       && ./build/test_terrain_action_green
     ```
   - Result: All 4 fixtures passing cleanly (`gate_zero`, `target_zero`, `pick_50`, `success`), exit code 0 under UBSan.
   - Verified 9 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_terrain_action.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 392 bytes (+76 bytes from 316-byte target).
   - Relocations resolved: all 6 compiled relocations mapped and resolved with exact multiset check.
   - Classified strictly as **NonMatching** (56 matching bytes).
   - The matching test serves as a structural correspondence diagnostic asserting >=40 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_terrain_action.py \
  tests/test_tactical_ai_combat_subsystem_controller_terrain_action_matching.py
```

The focused test run comprises **11 total tests** (10 behavioral tests in `test_tactical_ai_combat_subsystem_controller_terrain_action.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_terrain_action_matching.py`):
- One 32-bit native contract test with UBSan validating cleanup dispatch, D_004E2EA0 gate, target method 168, pick query 50,
  buffer forwarding, target method 180, order 2961, and manager method at offset 0x18.
- Nine production source mutations independently compiled and verified
  rejected (cleanup call, D_004E2EA0 gate, target method 168 check, pick query mode 42, pick query flag 1, pick 50 check, buffer forwarding, order 2961 action, manager notification call).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
