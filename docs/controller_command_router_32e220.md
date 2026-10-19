# Combat subsystem controller command router at 0x32E220

`func_0032E220` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_command_router.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 640-byte candidate sequence
(+72 bytes from 568-byte target code extent, 95 matching bytes, 8 relocations resolved with duplicate-rejecting multiset check;
classified strictly as NonMatching), scoping cleanup `func_0032E820`, entry gate `D_004E2EA0`, target query method 168,
entity lookup via self method 316 (0x13C, slot 79), audio cue dispatch `sub_31A160(self, 1500, a3)`, raycast fallback `func_0032D400(self, 40, 0, a1, a2, buf, 0, 1)`,
buffer forwarding `func_0032E580`, target query method 184, order dispatch `func_0032E6B0(self, 2961, 0, -1, 1)`, self state reset via method 40,
and manager notification via method at offset 0x18 (24 bytes, slot 6) on `D_004E3180`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032E220 = 0x32E220; // type:func size:0x238 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32E220, 0x32E458)` (568 bytes, `0x238`, 142 instructions), with zero internal padding.
  Symbol extent spans `[0x32E220, 0x32E458)` (568 bytes, `0x238`, 142 instructions).
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022E400, 0x0022E638)`.
- Predecessor continuity: directly preceded by `func_0032E0E0` ending at `0x32E21C` (`0x0022E3FC`).
  Between `0x32E21C` and `0x32E220`: exactly 4 bytes alignment padding `nop` (`0x00000000`).
  Zero overlap.
- Successor continuity: directly followed by `func_0032E460` starting at `0x32E460` (`0x0022E640`),
  size `0x4C` (76 bytes).
  Between `0x32E458` and `0x32E460`: exactly 8 bytes alignment padding `nop nop` (`0x00000000 0x00000000`).
  Zero unclassified bytes, zero overlap.
- Stack frame: 128 bytes (`addiu $sp, $sp, -128` = `0x27BDFF80` at `0x32E220`), saving `$ra` (80), `$s3` (64),
  `$s2` (48), `$s1` (32), `$s0` (16) via quadword stores `sq`.
  Epilogue: `jr $ra` at `0x32E450` (+0x230) and delay slot stack teardown `addiu $sp, $sp, 128` at `0x32E454` (+0x234).

## Relocation manifest

### Compiled candidate relocations (8 relocations)
The 640-byte candidate object resolves exactly 8 relocations with a duplicate-rejecting multiset check:
1. `+0x02C`: `R_MIPS_26` to `func_0032E820`
2. `+0x034`: `R_MIPS_GPREL16` to `D_004E2EA0` (addend -31,008 / 0x86E0)
3. `+0x13C`: `R_MIPS_26` to `sub_31A160`
4. `+0x144`: `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272 / 0x89C0)
5. `+0x19C`: `R_MIPS_26` to `func_0032D400`
6. `+0x1B8`: `R_MIPS_26` to `func_0032E580`
7. `+0x1FC`: `R_MIPS_26` to `func_0032E6B0`
8. `+0x228`: `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272 / 0x89C0)

### Full ELF function relocations (9 relocations)
The full 568-byte original binary function contains 9 relocations:
1. `+0x024`: `R_MIPS_26` to `func_0032E820`
2. `+0x02C`: `R_MIPS_GPREL16` to `D_004E2EA0` (addend -31,008)
3. `+0x118`: `R_MIPS_26` to `sub_31A160`
4. `+0x120`: `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
5. `+0x15C`: `R_MIPS_26` to `func_0032D400`
6. `+0x178`: `R_MIPS_26` to `func_0032E580`
7. `+0x1C4`: `R_MIPS_26` to `func_0032E6B0`
8. `+0x1E0`: `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
9. `+0x200`: `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)

## Observable behavior (Implemented Scope)

1. Subsystem cleanup: dispatch `func_0032E820(self)`.
2. Entry gate: query `D_004E2EA0`; if 0, return 0 immediately.
3. Target query: query target vtable method at offset 168 (`target->m_sub6960->m_vtable->func_168(target, sp120, sp126, -1, -1, -1, -1, 0)`).
   - If return value is 0, return 0 immediately.
4. Entity lookup: query self vtable method 316 (0x13C, slot 79) with `self->m_vtable->func_13C(self, a1, a2, sp116, -1, 0, 0, 0)`.
5. Entity branch (`entity != 0`):
   - Query target vtable method 184 (`target->m_sub6960->m_vtable->func_184(target, entity)`).
   - If result != 0, dispatch audio cue `sub_31A160(self, 1500, a3)`.
   - Dispatch manager notification via method at offset 0x18 (24 bytes, slot 6) on `D_004E3180` (`(D_004E3180, 0, 0)`).
   - Return status `s2`.
6. Raycast fallback (`entity == 0`):
   - Dispatch pick query `func_0032D400(self, 40, 0, a1, a2, buf, 0, 1)`.
   - If return code != 51: dispatch manager notification via method at offset 0x18 on `D_004E3180` and return 0.
   - If return code == 51:
     - Forward buffer via `func_0032E580(self, buf)`.
     - Query target vtable method 184 (`target->m_sub6960->m_vtable->func_184(target, 0)`).
     - If result != 0, dispatch order `func_0032E6B0(self, 2961, 0, -1, 1)`.
     - Dispatch self vtable method 40 (`self->m_vtable->func_28(self, 1)`).
     - Dispatch manager notification via method at offset 0x18 on `D_004E3180`.
     - Return status `s2`.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_command_router_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_command_router.cpp` returning -1.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_command_router.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_command_router_test.cpp -o build/test_cmd_router_red \
       && ./build/test_cmd_router_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: D_004E2EA0==0 must return 0` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ command router coordinator in `src/tactical_ai_combat_subsystem_controller_command_router.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_command_router.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_command_router_test.cpp -o build/test_cmd_router_green \
       && ./build/test_cmd_router_green
     ```
   - Result: All 5 fixtures passing cleanly (`gate_zero`, `target_zero`, `entity_hit`, `raycast_miss`, `raycast_hit`), exit code 0 under UBSan.
   - Verified 12 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_command_router.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 640 bytes (+72 bytes from 568-byte target).
   - Relocations resolved: all 8 compiled relocations mapped and resolved with exact multiset check.
   - Classified strictly as **NonMatching** (95 matching bytes).
   - The matching test serves as a structural correspondence diagnostic asserting >=60 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_command_router.py \
  tests/test_tactical_ai_combat_subsystem_controller_command_router_matching.py
```

The focused test run comprises **14 total tests** (13 behavioral tests in `test_tactical_ai_combat_subsystem_controller_command_router.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_command_router_matching.py`):
- One 32-bit native contract test with UBSan validating cleanup dispatch, D_004E2EA0 gate, target method 168, entity branch,
  audio cue 1500, raycast miss/hit, buffer forwarding, order 2961, self method 40, and manager method at offset 0x18.
- Twelve production source mutations independently compiled and verified
  rejected (cleanup call, D_004E2EA0 gate, target method 168 check, entity audio sound ID, audio param a3, pick query check, order 2961 action, self method 40, manager slot 5 rejection, manager receiver check, manager a1 arg, manager a2 arg).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
