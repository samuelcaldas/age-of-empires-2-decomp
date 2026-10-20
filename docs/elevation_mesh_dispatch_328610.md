# Gated elevation mesh dispatch at 0x328610

`func_00328610` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_elevation_mesh_dispatch.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **164/164 instruction bytes (100.00%)**
against the original ELF binary after resolving two `R_MIPS_26` call relocations
to validation routine `func_1A5010` and subsystem handler `func_1F5C80`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x328610, 0x3286B4)`, file `[0x2287F0, 0x228894)`.
  The function spans 164 instruction bytes (0xA4), followed by 12 bytes of
  alignment-padding nops up to `0x3286C0`. Symbol size is `0xA4`.
- Stack frame: 128 bytes (`addiu $sp, $sp, -0x80`), saving `$ra` (0x60),
  `$s5` (0x50), `$s4` (0x40), `$s3` (0x30), `$s2` (0x20), `$s1` (0x10),
  and `$s0` (0x00).
- Local output slots: `short s_7C` at `0x7C($sp)`, `short s_7E` at `0x7E($sp)`,
  and `int s_78` at `0x78($sp)`. Their addresses are passed to `func_1A5010`.

## Observable behavior

1. Preserve incoming 6 arguments: `self` (`$a0`), `a1` (`$a1`), `a2` (`$a2`),
   `a3` (`$a3`), `a4` (`$t0`), and `a5` (`$t1`) into `$s5`..`$s0`.
2. Invoke validation gate: `func_1A5010(self, a2, a3, &s_7C, &s_7E, &s_78)`.
3. If `func_1A5010` returns 0, abort and return 0.
4. If validation succeeds, forward all original parameters to `func_1F5C80(self, a1, a2, a3, a4, a5)`.
5. Return the result of `func_1F5C80`.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_elevation_mesh_dispatch.py \
  tests/test_tactical_ai_combat_subsystem_elevation_mesh_dispatch_matching.py
```

The focused test run comprises **6 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating rejection on gate
  failure, parameter forwarding, and result return on gate success.
- Four production source mutations independently compiled and verified
  rejected (inverted gate, wrong rejection return value, corrupted argument 1
  forwarding, corrupted argument 2 forwarding).
- One matching test compiling fresh with Ninja/MWCC and verifying 100.00%
  byte-for-byte identity against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
