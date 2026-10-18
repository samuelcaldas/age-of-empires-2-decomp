# Combat subsystem mode update at 0x328930

`func_00328930` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_mode_update.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces matching stack layout, argument
preservation, global pointer access to `D_004E3180`, calls to disable handler
`func_1A5390`, reset routine `func_1F65A0`, status checker `func_185DC0`, gate
validator `func_1A5010`, and virtual method calls through `m_vtable` slots
`0x118`, `0x11C`, and `0x120`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x328930, 0x328B10)`, file `[0x228B10, 0x228CF0)`.
  The function spans 480 instruction bytes (0x1E0). Symbol size is `0x1E0`.
- Stack frame: 80 bytes (`addiu $sp, $sp, -0x50`), saving `$ra` (0x30),
  `$s2` (0x20), `$s1` (0x10), and `$s0` (0x00).
- Local output slots: `short s_4C` at `0x4C($sp)`, `short s_4E` at `0x4E($sp)`,
  and `int s_48` at `0x48($sp)`.

## Observable behavior

1. Validate mode at `0x1C8(D_004E3180)` in `{4, 5, 6, 7}`. If not matched, return 0.
2. If `self->m_active != 0` (at `0x17C`): invoke `func_1A5390(self)` and return 1.
3. Else: invoke `func_1F65A0(self)`.
4. Call `func_185DC0(D_004E3180, 0)`. If zero, return 0.
5. If mode equals 5, return 0.
6. Invoke gate validation: `func_1A5010(self, a1, a2, &s_4C, &s_4E, &s_48)`.
   If zero, return 0.
7. Dispatch by `m_subtype` at `0x1CC(D_004E3180)`:
   - Subtype 4: call `m_vtable->func_11C(self, a1, a2)` and return 1.
   - Subtype 5: call `m_vtable->func_120(self, a1, a2)` and return 1.
   - Subtype 0 (if `m_sub28->m_state == 2`): call `m_vtable->func_118(self, a1, a2)`
     and return its result if non-zero.
   - Otherwise return 0.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_mode_update.py \
  tests/test_tactical_ai_combat_subsystem_mode_update_matching.py
```

The focused test run comprises **7 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating active instance disable,
  status rejection, gate rejection, and virtual method subtype dispatch.
- Five production source mutations independently compiled and verified
  rejected (mode check, active branch inversion, status inversion, subtype 4
  dispatch, subtype 0 state check).
- One matching test compiling fresh with Ninja/MWCC and verifying structural
  correspondence against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
