# Combat subsystem virtual query at 0x328FD0

`func_00328FD0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_mode_query.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces matching stack layout (-0x40), argument
preservation, global pointer access to `D_004E2EA0`, calls to gate validator
`func_1A5010`, coordinate bias calculation `(s_3C + 0.5f, s_3E + 0.5f)`, and
virtual method call through `m_obj_120->m_vtable` slot `0xBC`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x328FD0, 0x32906C)`, file `[0x2291B0, 0x22924C)`.
  The function spans 156 instruction bytes (0x9C), followed by 4 bytes of
  alignment-padding nops up to `0x329070`. Symbol size is `0x9C`.
- Stack frame: 64 bytes (`addiu $sp, $sp, -0x40`), saving `$ra` (0x20),
  `$s1` (0x10), and `$s0` (0x00).
- Local output slots: `short s_3C` at `0x3C($sp)`, `short s_3E` at `0x3E($sp)`,
  and `int s_38` at `0x38($sp)`.

## Observable behavior

1. Check global feature flag `D_004E2EA0`. If zero, return 0.
2. Invoke gate validation: `func_1A5010(self, a1, a2, &s_3C, &s_3E, &s_38)`.
3. If validation succeeds:
   - Access target sub-object at `0x120(self)`.
   - Invoke virtual query `func_BC(obj, 0, (float)s_3C + 0.5f, (float)s_3E + 0.5f)`.
   - Truncate and return the 8-bit unsigned result.
4. Otherwise return 0.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_mode_query.py \
  tests/test_tactical_ai_combat_subsystem_mode_query_matching.py
```

The focused test run comprises **7 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating global flag guard,
  gate rejection, coordinate bias, and virtual method return truncation.
- Five production source mutations independently compiled and verified
  rejected (global flag check, gate condition, coordinate bias, flag argument,
  method execution).
- One matching test compiling fresh with Ninja/MWCC and verifying structural
  correspondence against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
