# Combat subsystem controller order dispatch at 0x32E6B0

`func_0032E6B0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_order_dispatch.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 360-byte candidate sequence
(-8 bytes from 368-byte target code extent, 94 matching bytes, 4 relocations resolved with duplicate-rejecting multiset check;
classified strictly as NonMatching), scoping conditional cleanup `func_0032E820` on `t0 != 0`,
slot state validation and cleanup `sub_260ED0`, unconditional table decrement `func_0032E640(self, 2)`,
order dispatch `sub_260E50`, and slot state recording with count increment.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol Extent: VRAM `[0x32E6B0, 0x32E820)` (368 bytes, `0x170`, 92 instructions).
  Note: `config/SLES-50282/symbols.txt` terminates at `func_0032E640`; the boundary for `func_0032E6B0` is derived directly
  from the original ELF binary between padding end at `0x32E6B0` and successor `func_0032E820` at `0x32E820`.
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022E890, 0x0022EA00)`.
- Predecessor continuity: directly preceded by `func_0032E640` ending at `0x32E6A4` (`0x0022E884`).
  Between `0x32E6A4` and `0x32E6B0`: exactly 12 bytes alignment padding `nop nop nop` (`0x00000000 0x00000000 0x00000000`).
  Zero overlap.
- Successor continuity: directly followed by `func_0032E820` starting at `0x32E820` (`0x0022EA00`),
  size `0x158` (344 bytes).
  Between `0x32E820` and `0x32E820`: exactly 0 bytes padding (immediate successor).
  Zero unclassified bytes, zero overlap.
- Stack frame: 112 bytes (`addiu $sp, $sp, -112` = `0x27BDFF90` at `0x32E6B0`), saving `$ra` (96), `$s4` (80),
  `$s3` (64), `$s2` (48), `$s1` (32), `$s0` (16), `$f21` (4), `$f20` (0) via quadword stores `sq` and `swc1`.
  Epilogue: `jr $ra` at `0x32E810` (+0x160) and delay slot stack teardown `addiu $sp, $sp, 112` at `0x32E814` (+0x164).
  Two internal alignment NOPs at `+0x168` and `+0x16C` round to 368 bytes.

## Relocation manifest

### Compiled candidate relocations (4 relocations)
The 360-byte candidate object resolves exactly 4 relocations with a duplicate-rejecting multiset check:
1. `+0x034`: `R_MIPS_26` to `func_0032E820` (addend 0)
2. `+0x0B8`: `R_MIPS_26` to `sub_260ED0` (addend 0)
3. `+0x0C8`: `R_MIPS_26` to `func_0032E640` (addend 0)
4. `+0x108`: `R_MIPS_26` to `sub_260E50` (addend 0)

### Full ELF function relocations (4 relocations)
The full 368-byte original binary function contains 4 relocations (all `R_MIPS_26`, 0 `R_MIPS_GPREL16`):
1. `+0x044`: `R_MIPS_26` to `func_0032E820`
2. `+0x0B4`: `R_MIPS_26` to `sub_260ED0`
3. `+0x0C4`: `R_MIPS_26` to `func_0032E640`
4. `+0x10C`: `R_MIPS_26` to `sub_260E50`

## Observable behavior

1. Conditional cleanup: if `t0 != 0`, dispatch `func_0032E820(self)`.
2. Ring buffer wrap: if `m_slot_count == 10`, reset `m_slot_count = 0`.
3. Valid slot teardown (`t0 == 0`):
   - Check slot entry at `m_slots[slot]`.
   - If entry flag has bit 4 and `action_id` matches `m_slot_action_ids[slot]`:
     dispatch `sub_260ED0(target_sub->m_sub_target)` and clear slot entry.
4. Table decrement: unconditionally dispatch `func_0032E640(self, 2)`.
5. Order dispatch:
   - Compute parameter bits (set bit 0 if `action_id == 2962`, OR with `a2`).
   - Dispatch `sub_260E50(target_sub->m_sub_target, action_id, 0, param & 0xFF, a3)`.
6. State update:
   - Record returned slot pointer into `m_slots[cur_slot]`.
   - Record `action_id` into `m_slot_action_ids[cur_slot]`.
   - Increment `m_slot_count`.

## TDD Chronology and Verification Evidence

1. **Red/Green Incremental Cycle:**
   - Step 1: No-op stub failed fast with `MUTATION_ASSERTION_FAILED: must unconditionally dispatch func_0032E640` (exit code 1).
   - Step 1 Green: Implemented unconditional `func_0032E640(self, 2)` call. Re-run failed `MUTATION_ASSERTION_FAILED: t0!=0 must dispatch cleanup func_0032E820` (exit code 1).
   - Step 2 Green: Implemented conditional cleanup `func_0032E820`. Re-run failed `MUTATION_ASSERTION_FAILED: valid slot on t0==0 must call sub_260ED0` (exit code 1).
   - Step 3 Green: Implemented `t0 == 0` slot validation and `sub_260ED0`. Re-run failed `MUTATION_ASSERTION_FAILED: must call sub_260E50 once` (exit code 1).
   - Step 4 Green: Implemented `sub_260E50` call. Re-run failed `MUTATION_ASSERTION_FAILED: slot count must be incremented` (exit code 1).
   - Step 5 Green: Implemented slot recording and `m_slot_count++`.
   - Result: All 4 fixtures passing cleanly (`cleanup_t0`, `suppress_t0`, `valid_slot`, `final_dispatch`), exit code 0 under UBSan.
   - Verified 9 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_order_dispatch.py`.
2. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 360 bytes (-8 bytes from 368-byte target).
   - Relocations resolved: all 4 compiled relocations mapped and verified with multiset check.
   - Classified strictly as **NonMatching** (94 matching bytes).
   - The matching test serves as a structural correspondence diagnostic asserting >=60 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_order_dispatch.py \
  tests/test_tactical_ai_combat_subsystem_controller_order_dispatch_matching.py
```

The focused test run comprises **11 total tests** (10 behavioral tests in `test_tactical_ai_combat_subsystem_controller_order_dispatch.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_order_dispatch_matching.py`):
- One 32-bit native contract test with UBSan validating t0!=0 cleanup, t0==0 cleanup suppression, valid slot sub_260ED0,
  unconditional func_0032E640(self, 2), final sub_260E50 arguments, and slot count increment.
- Nine production source mutations independently compiled and verified
  rejected (cleanup check, t0 zero check, sub_260ED0 call, func_0032E640 call, func_0032E640 id, sub_260E50 action arg, action id recording, slot increment, slot pointer recording).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
