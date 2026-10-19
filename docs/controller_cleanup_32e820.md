# Combat subsystem controller slot cleanup at 0x32E820

`func_0032E820` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_cleanup.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces an exact **160/160 instruction bytes match (100.00%)**
and 1 relocation resolved (`R_MIPS_26` to `sub_260ED0` at offset `+0x068`).
Classified as NonMatching pending independent reviewer confirmation.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol Extent: VRAM `[0x32E820, 0x32E8C0)` (160 bytes, `0xA0`, 40 instructions).
  `config/SLES-50282/symbols.txt` terminates at `func_0032E640`; boundary derived
  directly from the ELF binary between padding end at `0x32E820` and successor `func_0032E8C0`.
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022EA00, 0x0022EAA0)`.
- Predecessor continuity: directly preceded by `func_0032E6B0` ending at `0x32E810` with
  two alignment NOPs at `0x32E810`–`0x32E81C`. Immediate successor at `0x32E820`.
- Successor continuity: directly followed by `func_0032E8C0` starting at `0x32E8C0`
  (immediate successor, 0 bytes padding).
- Stack frame: 64 bytes (`addiu $sp, $sp, -64` = `0x27BDFFC0` at `0x32E820`), saving
  `$ra` (+0x30), `$s2` (+0x20), `$s1` (+0x10), `$s0` (+0x0) via quadword stores `sq`.
  Epilogue: `jr $ra` at `0x32E8B8` (+0x98) with delay slot `addiu $sp, $sp, 64` = `0x27BD0040`.

## Relocation manifest

### Compiled candidate relocations (1 relocation)

1. `+0x068`: `R_MIPS_26` to `sub_260ED0` (addend 0)

### Full ELF function relocations (1 relocation)

1. `+0x068`: `R_MIPS_26` to `sub_260ED0`

Exact match on relocation offset, type, and callee.

## Observable behavior

1. Loop over `i` in `[0, 10)`:
   - Load `entry = m_slots[i]`.
   - Skip if `entry == 0`.
   - Skip if `(entry->flag & 4) != 4`.
   - Load `sub = entry->m_sub`.
   - Skip if `sub == 0`.
   - Skip if `(int)sub->action_id != m_slot_action_ids[i]` (signed 16→32 comparison).
   - Unconditionally dispatch `sub_260ED0(m_sub12c->m_sub_target)` (delay slot loads `120($v0)`).
   - Clear `m_slots[i] = 0` after callback returns.
2. Reset slot count: set `m_slot_count = 0`.

Note: Null inputs are undefined behavior in the original binary (no-guard design) and
are not claimed as supported API contracts. Subprocess tests verify UBSan death upon
null dereference to confirm absence of synthetic guards.

## TDD Chronology and Verification Evidence

1. **Red/Green Incremental Cycle:**
   - Step 1: stub failed `MUTATION_ASSERTION_FAILED: matching active slot must call sub_260ED0` (exit 1).
   - Step 1 Green: slot[0] single-check. All three fixtures: slot[0] callback, signed id, and slot[9] ran.
   - Step 2 Red: `MUTATION_ASSERTION_FAILED: slot 9 must be traversed and cleared on match` (exit 1). `aoe-advisor` authorized loop expansion.
   - Step 2 Green: replaced single slot[0] check with `for (int i = 0; i < 10; i++)` loop.
   - Step 3: Added `test_null_sub_skips_callback` fixture.
   - Step 4 Red: prospective Red `MUTATION_ASSERTION_FAILED: m_slot_count must be reset to 0 after cleanup` (exit 1). `aoe-advisor` authorized `self->m_slot_count = 0`.
   - Step 4 Green: added `self->m_slot_count = 0;` after loop.
   - Step 5 ELF Audit & Red: disassembled `AOK.ELF` `func_0032E820`. Verified zero instructions test `self == 0` or `self->m_sub12c == 0` (delay slot loads `120($v0)` unconditionally). Added behavioral Red death tests `test_null_self_behavioral_red` and `test_matched_null_sub12c_behavioral_red`; observed both fail on defensive source (exited 0 instead of UBSan death).
   - Step 5 Green: removed synthetic `self == 0` and `self->m_sub12c != 0` guards. Both behavioral Red death tests turned green.
   - Verified 10 production-source mutations killed by named assertion, confirmed by
     `tests/test_tactical_ai_combat_subsystem_controller_cleanup.py` (10/10 killed).
2. **Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate 160 bytes (exact 160-byte target extent).
   - Exactly **160/160 bytes match (100.00%)** bit-for-bit against pinned ELF.
   - Verified by `tests/test_tactical_ai_combat_subsystem_controller_cleanup_matching.py`.
   - Retained as **NonMatching** per reviewer directive until formal peer review clearance.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python3 -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_cleanup.py \
  tests/test_tactical_ai_combat_subsystem_controller_cleanup_matching.py
```

The focused test run comprises **14 total tests** (13 in behavioral suite + 1 exact matching test):
- One 32-bit native contract test under UBSan: 10-slot traversal, signed action-id sign-extension,
  callback receiver, slot intact during callback, slot cleared after, and m_slot_count reset to 0.
- Ten production-source mutations killed by named assertion: corrupt_loop_start, flag_bit_wrong,
  action_id_compare_bad, omit_sub260ed0_call, omit_slot_clear, loop_limit_1, loop_limit_9,
  signed_compare_wrong, clear_before_callback, omit_slot_count_reset.
- Two behavioral death tests confirming absence of synthetic guards via UBSan termination.
- One 100.00% exact bit-for-bit matching test (160/160 bytes) with Ninja/MWCC.

The WIP/BIN boundary and registered object list remain unchanged (NonMatching).
