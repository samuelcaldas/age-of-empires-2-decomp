# Combat subsystem controller slot cleanup at 0x32E820

`func_0032E820` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_cleanup.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 168-byte candidate sequence
(+8 bytes from 160-byte target code extent, 39 matching prefix bytes,
1 relocation resolved; classified strictly as NonMatching),
iterating over all 10 slots, dispatching `sub_260ED0` for each active
matching slot, then clearing it.

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

1. `+0x074`: `R_MIPS_26` to `sub_260ED0` (addend 0)

### Full ELF function relocations (1 relocation)

1. `+0x068`: `R_MIPS_26` to `sub_260ED0`

Relocation type and callee match. Relocation offset differs by 12 bytes
(consistent with the +8 byte size difference plus 4-byte instruction order shift
in the null-check / register-save interleaving in the prologue).

## Observable behavior

1. Null guard: if `self == 0`, return immediately.
2. Loop over `i` in `[0, 10)`:
   - Load `entry = m_slots[i]`.
   - Skip if `entry == 0`.
   - Skip if `(entry->flag & 4) != 4`.
   - Load `sub = entry->m_sub`.
   - Skip if `sub == 0`.
   - Skip if `(int)sub->action_id != m_slot_action_ids[i]` (signed 16→32 comparison).
   - If `m_sub12c != 0`: dispatch `sub_260ED0(m_sub12c->m_sub_target)`.
   - Clear `m_slots[i] = 0` after callback returns.

## TDD Chronology and Verification Evidence

1. **Red/Green Incremental Cycle:**
   - Step 1: stub failed `MUTATION_ASSERTION_FAILED: matching active slot must call sub_260ED0` (exit 1).
   - Step 1 Green: slot[0] single-check. All three fixtures: slot[0] callback, signed id, and slot[9] ran.
   - Step 2 Red: `MUTATION_ASSERTION_FAILED: slot 9 must be traversed and cleared on match` (exit 1). `aoe-advisor` authorized loop expansion.
   - Step 2 Green: replaced single slot[0] check with `for (int i = 0; i < 10; i++)` loop.
   - Step 3: Added `test_null_sub_skips_callback` fixture. All 4 fixtures pass, exit 0 under UBSan.
   - Verified 9 production-source mutations via assertion string + 1 via UBSan crash (null-sub
     deref), for 10/10 total kills, confirmed by `tests/test_tactical_ai_combat_subsystem_controller_cleanup.py`.
2. **Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate 168 bytes (+8 from 160-byte target).
   - 39 matching prefix bytes; divergence at +0x10 due to null-check/sq-store scheduling.
   - Classified strictly as **NonMatching**.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python3 -m pytest -q tests/test_tactical_ai_combat_subsystem_controller_cleanup.py
```

The focused test run comprises **10 total tests** (1 behavioral reference contract +
9 production-source mutations verified by assertion + null-sub mutation killed by UBSan):
- One 32-bit native contract test under UBSan: null-self guard, 10-slot traversal,
  signed action-id sign-extension, callback receiver, slot intact during callback, slot cleared after.
- Nine production-source mutations killed by named assertion: null_guard_invert, flag_bit_wrong,
  action_id_compare_bad, omit_sub260ed0_call, omit_slot_clear, loop_limit_1, loop_limit_9,
  signed_compare_wrong, clear_before_callback.
- Sub-null-check mutation killed by UBSan null-pointer dereference (not named assertion).

The WIP/BIN boundary and registered object list remain unchanged (NonMatching).
