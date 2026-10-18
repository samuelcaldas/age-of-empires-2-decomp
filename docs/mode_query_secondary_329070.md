# Combat subsystem secondary virtual query at 0x329070

`func_00329070` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_mode_query_secondary.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces matching stack layout (-0x40), argument
preservation, global pointer accesses to `D_004E2EA0` and `D_004E3180`, calls to
gate validator `func_1A5010`, coordinate bias calculation `(s_3C + 0.5f, s_3E + 0.5f)`,
virtual method call through `m_obj_120->m_vtable` slot `0xB4`, and manager
notification call through `D_004E3180->m_vtable` slot `0x18`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x329070, 0x329124)`, file `[0x229250, 0x229304)`.
  The function spans 180 instruction bytes (0xB4), followed by 12 bytes of
  alignment-padding nops up to `0x329130`. Symbol size is `0xB4`.
- Stack frame: 64 bytes (`addiu $sp, $sp, -0x40`), saving `$ra` (0x20),
  `$s1` (0x10), and `$s0` (0x00).
- Local output slots: `short s_3C` at `0x3C($sp)`, `short s_3E` at `0x3E($sp)`,
  and `int s_38` at `0x38($sp)`.

## Observable behavior

1. Check global feature flag `D_004E2EA0`. If zero, return 0.
2. Invoke gate validation: `func_1A5010(self, a1, a2, &s_3C, &s_3E, &s_38)`.
3. If validation succeeds:
   - Access target sub-object at `0x120(self)`.
   - Invoke virtual query `func_B4(obj, 0, (float)s_3C + 0.5f, (float)s_3E + 0.5f)`.
   - Invoke manager notification `D_004E3180->m_vtable->func_18(D_004E3180, 0, 0)`.
   - Truncate and return the 8-bit unsigned result.
4. Otherwise return 0.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_mode_query_secondary.py \
  tests/test_tactical_ai_combat_subsystem_mode_query_secondary_matching.py
```

The focused test run comprises **7 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating global flag guard,
  gate rejection, coordinate bias, virtual method query, and manager call.
- Five production source mutations independently compiled and verified
  rejected (global flag check, gate condition, coordinate bias, manager call,
  query method execution).
- One matching test compiling fresh with Ninja/MWCC and verifying structural
  correspondence against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
