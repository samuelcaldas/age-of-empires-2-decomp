# Combat subsystem mode dispatch at 0x328820

`func_00328820` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_mode_dispatch.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces matching stack layout, argument
preservation, global pointer access to `D_004E3180`, and exact calls to
status checker `func_185DC0`, disable handler `func_1A5390`, reset routine
`func_1F65A0`, and action dispatcher `func_1A52D0`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x328820, 0x328930)`, file `[0x228A00, 0x228B10)`.
  The function spans 272 instruction bytes (0x110). Symbol size is `0x110`.
- Stack frame: 64 bytes (`addiu $sp, $sp, -0x40`), saving `$ra` (0x30),
  `$s2` (0x20), `$s1` (0x10), and `$s0` (0x00).

## Observable behavior

1. Read system manager mode at `0x1C8(D_004E3180)`.
2. Validate mode in `{4, 5, 6, 7}`. If not matched, return 0.
3. Call `func_185DC0(D_004E3180, 0)`:
   - If non-zero:
     * If `self->m_active != 0` (at `0x17C`): invoke `func_1A5390(self)`.
     * Else: invoke `func_1F65A0(self)`.
     * Return 0.
   - If zero:
     * If `self->m_active != 0`: invoke `func_1A52D0(self, a1, a2)` and return 1.
     * Else: return 0.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_mode_dispatch.py \
  tests/test_tactical_ai_combat_subsystem_mode_dispatch_matching.py
```

The focused test run comprises **7 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating mode rejection,
  status non-zero branches (disable vs reset), and status zero action dispatch.
- Five production source mutations independently compiled and verified
  rejected (mode check, status check inversion, active flag branch inversion,
  argument forwarding, return value).
- One matching test compiling fresh with Ninja/MWCC and verifying structural
  correspondence against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
