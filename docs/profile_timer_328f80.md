# Combat subsystem profiling timer wrapper at 0x328F80

`func_00328F80` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_profile_timer.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **80/80 instruction bytes (100.00%)**
against the original ELF binary after resolving four `R_MIPS_26` call
relocations (`func_2261C0` twice, `func_1A3640`, and `func_184B60`) and one
`R_MIPS_GPREL16` relocation to `D_004E3180`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x328F80, 0x328FD0)`, file `[0x229160, 0x2291B0)`.
  The function spans 80 instruction bytes (0x50). Symbol size is `0x50`.
- Stack frame: 48 bytes (`addiu $sp, $sp, -0x30`), saving `$ra` (0x20),
  `$s1` (0x10), and `$s0` (0x00).

## Observable behavior

1. Sample starting timestamp from hardware timer: `start_time = func_2261C0()`.
2. Invoke workload delegate: `func_1A3640(self)`.
3. Sample ending timestamp: `end_time = func_2261C0()`.
4. Emit elapsed duration metrics to profiling channel 7:
   `func_184B60(D_004E3180, 7, end_time - start_time)`.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_profile_timer.py \
  tests/test_tactical_ai_combat_subsystem_profile_timer_matching.py
```

The focused test run comprises **6 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating start/end timestamping,
  delegate execution with forwarded `self`, and elapsed delta calculation on
  profiling channel 7.
- Four production source mutations independently compiled and verified
  rejected (omitted delegate call, zero start timestamp, corrupted channel,
  inverted time delta).
- One matching test compiling fresh with Ninja/MWCC and verifying 100.00%
  byte-for-byte identity against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
