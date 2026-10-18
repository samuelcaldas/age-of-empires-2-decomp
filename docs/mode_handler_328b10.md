# Combat subsystem mode handler at 0x328B10

`func_00328B10` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_mode_handler.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces matching stack layout, argument
preservation, global pointer access to `D_004E3180`, calls to status checker
`func_185DC0`, reset routine `func_1F6510`, and action dispatcher `func_1A5200`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x328B10, 0x328C34)`, file `[0x228CF0, 0x228E14)`.
  The function spans 292 instruction bytes (0x124), followed by 12 bytes of
  alignment-padding nops up to `0x328C40`. Symbol size is `0x124`.
- Stack frame: 64 bytes (`addiu $sp, $sp, -0x40`), saving `$ra` (0x30),
  `$s2` (0x20), `$s1` (0x10), and `$s0` (0x00).

## Observable behavior

1. Call `func_185DC0(D_004E3180, 0)`. If non-zero, return 0.
2. Read system manager mode at `0x1C8(D_004E3180)`.
3. Validate mode in `{4, 5, 6, 7}`. If not matched, return 0.
4. Check sub-object state at `0xA0(0x28(D_004E3180))`:
   - If `m_state == 2`:
     * If mode is in `{4, 6, 7}`: invoke `func_1F6510(self)`.
     * Return 1.
   - Else:
     * Invoke `func_1A5200(self, a1, a2)`.
     * Return 1.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_mode_handler.py \
  tests/test_tactical_ai_combat_subsystem_mode_handler_matching.py
```

The focused test run comprises **7 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating status check failure,
  mode rejection, state 2 reset branch, and state not-2 action dispatch.
- Five production source mutations independently compiled and verified
  rejected (status check, mode validation, state comparison, reset call,
  action parameters).
- One matching test compiling fresh with Ninja/MWCC and verifying structural
  correspondence against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
