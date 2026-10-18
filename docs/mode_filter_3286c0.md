# Combat subsystem mode filter at 0x3286C0

`func_003286C0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_mode_filter.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces the matching stack frame, argument
preservation, global pointer loads from `D_004E3180`, and exact calls to
status checker `func_185DC0`, action handler `func_1A5200`, and reset routine
`func_1F6510`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x3286C0, 0x32881C)`, file `[0x2288A0, 0x2289FC)`.
  The function spans 348 instruction bytes (0x15C), followed by 4 bytes of
  alignment-padding nops up to `0x328820`. Symbol size is `0x15C`.
- Stack frame: 64 bytes (`addiu $sp, $sp, -0x40`), saving `$ra` (0x30),
  `$s2` (0x20), `$s1` (0x10), and `$s0` (0x00).

## Observable behavior

1. Call `func_185DC0(D_004E3180, 0)`. If non-zero, return 0.
2. Read system manager mode at `0x1C8(D_004E3180)`.
3. Validate mode in `{4, 5, 6, 7}`. If not matched, return 0.
4. Read subtype at `0x1CC(D_004E3180)`.
5. If subtype equals `0x6F` and sub-object state at `0xA0(0x28(D_004E3180))`
   equals `2`: invoke `func_1A5200(self, a1, a2)` and return 1.
6. Else if mode is in `{4, 6, 7}`: invoke `func_1F6510(self)` and return 1.
7. Otherwise return 0.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_mode_filter.py \
  tests/test_tactical_ai_combat_subsystem_mode_filter_matching.py
```

The focused test run comprises **7 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating status check failure,
  mode rejection, action dispatch with argument forwarding, and reset fallback.
- Five production source mutations independently compiled and verified
  rejected (omitted status check, omitted mode check, corrupted subtype anchor,
  corrupted state check, omitted fallback branch).
- One matching test compiling fresh with Ninja/MWCC and verifying structural
  correspondence against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
