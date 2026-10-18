# Combat subsystem mode processor at 0x328D50

`func_00328D50` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_mode_processor.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces matching stack layout (-0x60), argument
preservation, global pointer access to `D_004E3180`, calls to disable handler
`func_1A5390`, reset routine `func_1F65A0`, status checker `func_185DC0`, gate
validator `func_1A5010`, coordinate placement on `m_obj_120->m_vtable` slot
`0xDC`, cleanup function `func_205EE0`, and manager virtual method `func_18`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x328D50, 0x328F7C)`, file `[0x228F30, 0x22915C)`.
  The function spans 556 instruction bytes (0x22C), followed by 4 bytes of
  alignment-padding nops up to `0x328F80`. Symbol size is `0x22C`.
- Stack frame: 96 bytes (`addiu $sp, $sp, -0x60`), saving `$ra` (0x40),
  `$s3` (0x30), `$s2` (0x20), `$s1` (0x10), and `$s0` (0x00).
- Local output slots: `short s_5C` at `0x5C($sp)`, `short s_5E` at `0x5E($sp)`,
  and `int s_58` at `0x58($sp)`.

## Observable behavior

1. Validate mode at `0x1C8(D_004E3180)` in `{4, 5, 6, 7}`. If not matched, return 0.
2. If `self->m_active != 0` (at `0x17C`): invoke `func_1A5390(self)` and return 1.
3. Else: invoke `func_1F65A0(self)`.
4. Call `func_185DC0(D_004E3180, 0)`. If zero, return 0.
5. Validate `self->m_type_108` in `{1, 2}`. If not matched, return 0.
6. Check sub-object state at `0xA0(0x28(D_004E3180))`:
   - If `m_state == 2`:
     * If `subtype != 0` or `mode == 5`: return 0.
     * If `flag == 0`: call `self->m_vtable->func_118(self, a1, a2)`.
     * If `flag != 0`: call `func_1A5010(self, a1, a2, &s_5C, &s_5E, &s_58)`.
       If true, invoke `m_obj_120->m_vtable->func_DC(m_obj_120, s_5C + 0.5f, s_5E + 0.5f, 1.0f)`.
       Return 1.
   - Else (`m_state != 2`):
     * If `mode == 7`: return 0.
     * If `subtype != 0`: invoke `mgr->m_vtable->func_18(mgr, 0, 0)`.
     * Invoke cleanup `func_205EE0(self->m_obj_120)`.
     * Return 0.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_mode_processor.py \
  tests/test_tactical_ai_combat_subsystem_mode_processor_matching.py
```

The focused test run comprises **7 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating active instance disable,
  type rejection, state 2 branch with coordinate placement, and fallback cleanup.
- Five production source mutations independently compiled and verified
  rejected (mode check, active branch inversion, type validation, coordinate bias,
  cleanup invocation).
- One matching test compiling fresh with Ninja/MWCC and verifying structural
  correspondence against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
