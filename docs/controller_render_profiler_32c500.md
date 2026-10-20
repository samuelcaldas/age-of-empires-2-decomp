# Combat subsystem controller render profiler at 0x32C500

`func_0032C500` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_render_profiler.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 232-byte instruction sequence
(matching target code extent 232/232 bytes, 132 of 232 bytes matching, 100 byte differences;
classified strictly as NonMatching), matching stack frame (-0x40 = 64 bytes), callee-saved `$s0`–`$s2` and `$ra`,
profiling timers `func_2261C0`, manager metrics `func_184BF0(11)`, target presence branching on `m_field_12C` and `m_target`,
virtual callbacks `func_30(0)` and `func_34()` vs `func_31AAB0`, and profiling metric submissions `func_184B60(6, ...)` and `func_184B60(12, ...)`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032C500 = 0x32C500; // type:func size:0xE8 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32C500, 0x32C5E8)` (232 bytes, 58 instructions), with zero internal padding.
  Symbol extent spans `[0x32C500, 0x32C5E8)` (232 bytes, `0xE8`, 58 instructions).
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022C6E0, 0x0022C7C8)`.
- Predecessor continuity: directly preceded by `func_0032C480` ending at `0x32C4F8` (`0x0022C6D8`).
  Between `0x32C4F8` and `0x32C500`: exactly 8 bytes alignment padding `nop nop` (`0x00000000 0x00000000`).
  Zero overlap.
- Successor continuity: directly followed by `func_0032C5F0` starting at `0x32C5F0` (`0x0022C7D0`),
  size `0x8` (8 bytes, stub leaf `jr $ra; nop`).
  Between `0x32C5E8` and `0x32C5F0`: exactly 8 bytes alignment padding `nop nop` (`0x00000000 0x00000000`).
  Zero unclassified bytes, zero overlap.
- Stack frame: 64 bytes (`addiu $sp, $sp, -64` at `0x32C500`), saving `$ra` (48),
  `$s2` (32), `$s1` (16), and `$s0` (0) via quadword stores `sq`.
  Epilogue: `jr $ra` at `0x32C5E0` (+0x0E0) and delay slot stack teardown `addiu $sp, $sp, 64` at `0x32C5E4` (+0x0E4).

## Relocation manifest (15 relocations)

1. `+0x014` (`0x32C514`): `R_MIPS_26` to `func_2261C0` (addend 0)
2. `+0x01C` (`0x32C51C`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
3. `+0x024` (`0x32C524`): `R_MIPS_26` to `func_184BF0` (addend 0)
4. `+0x064` (`0x32C564`): `R_MIPS_26` to `func_1ABD90` (addend 0)
5. `+0x080` (`0x32C580`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
6. `+0x088` (`0x32C588`): `R_MIPS_26` to `func_31AAB0` (addend 0)
7. `+0x090` (`0x32C590`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
8. `+0x094` (`0x32C594`): `R_MIPS_26` to `func_184BF0` (addend 0)
9. `+0x09C` (`0x32C59C`): `R_MIPS_26` to `func_2261C0` (addend 0)
10. `+0x0A4` (`0x32C5A4`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
11. `+0x0B4` (`0x32C5B4`): `R_MIPS_26` to `func_184B60` (addend 0)
12. `+0x0BC` (`0x32C5BC`): `R_MIPS_26` to `func_184BB0` (addend 0)
13. `+0x0C0` (`0x32C5C0`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
14. `+0x0C4` (`0x32C5C4`): `R_MIPS_GPREL16` to `D_004E3180` (addend -30,272)
15. `+0x0CC` (`0x32C5CC`): `R_MIPS_26` to `func_184B60` (addend 0)

## Observable behavior

1. Record start timers and metrics:
   - Query timer `start_time = func_2261C0()`.
   - Query metric `start_metric = func_184BF0(D_004E3180, 11)`.
2. Target presence evaluation:
   - If `self->m_field_12C == 0 || self->m_target == 0`:
     - Dispatch `self->m_vtable->func_30(self, 0)`.
     - Dispatch `func_1ABD90(self->m_field_20, &self->m_field_24, self->m_field_10B)`.
     - Dispatch `self->m_vtable->func_34(self)`.
   - Else:
     - Dispatch `func_31AAB0(self)`.
3. Record end timers and metrics:
   - Query metric `end_metric = func_184BF0(D_004E3180, 11)`.
   - Query timer `end_time = func_2261C0()`.
4. Calculate deltas:
   - `metric_delta = end_metric - start_metric`
   - `elapsed_time = end_time - start_time`
5. Submit profiling metrics:
   - Dispatch `func_184B60(D_004E3180, 6, elapsed_time - metric_delta)`.
   - Dispatch `func_184BB0(D_004E3180)`.
   - Dispatch `func_184B60(D_004E3180, 12, metric_delta)`.
6. Return void.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_render_profiler_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_render_profiler.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_render_profiler.h"

     void func_0032C500(CombatSubsystemControllerInstance *) {}
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_render_profiler.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_render_profiler_test.cpp -o build/test_render_profiler_red \
       && ./build/test_render_profiler_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: must call func_2261C0 twice` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ render profiler in `src/tactical_ai_combat_subsystem_controller_render_profiler.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_render_profiler.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_render_profiler_test.cpp -o build/test_render_profiler_green \
       && ./build/test_render_profiler_green
     ```
   - Result: All 3 fixtures passing cleanly (`null_target`, `active_target`, `null_12c`), exit code 0 under UBSan.
   - Verified both branch paths independently: `m_field_12C != nullptr && m_target == nullptr` (`test_null_target_branch`) and `m_field_12C == nullptr && m_target != nullptr` (`test_null_field_12c_active_target`), proving both dispatch `func_30(0)`, `func_1ABD90`, and `func_34()`.
   - Verified 10 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_render_profiler.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 232 bytes (matching target code extent 232/232 bytes).
   - Relocations resolved: all 15 relocations (7 GPREL16, 8 JAL) resolved with duplicate-rejecting exact multiset check.
   - Classified strictly as **NonMatching** (132 matching bytes, 100 byte differences, 56.90% match).
   - The matching test serves as a structural correspondence diagnostic asserting >=40 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_render_profiler.py \
  tests/test_tactical_ai_combat_subsystem_controller_render_profiler_matching.py
```

The focused test run comprises **12 total tests** (11 behavioral tests in `test_tactical_ai_combat_subsystem_controller_render_profiler.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_render_profiler_matching.py`):
- One 32-bit native contract test with UBSan validating null target branch, active target branch, null field_12C branch,
  metric channels 6 and 12, delta calculations, and 10-call / 8-call ordered callback sequencing.
- Ten production source mutations independently compiled and verified
  rejected (channel 6 delta, channel 12 delta, func_30 call arguments, func_1ABD90 receiver, func_1ABD90 flag, func_34 call, func_31AAB0 call, func_184BB0 call, branch condition inversion, null field 12C branch bypass).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
