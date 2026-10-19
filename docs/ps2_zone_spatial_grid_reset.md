# ZoneSpatialGrid occupant reset verification (`func_001F2BD0`)

## Overview

`func_001F2BD0` spans virtual address range `0x1F2BD0`–`0x1F2C20` (file offsets
`0xF2DB0`–`0xF2E00`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
This routine resets the grid active occupant pointer: if `self->field_0C` is non-null
and differs from `self->field_10`, it notifies `func_001F6CC0(self->field_10, self->field_0C)`,
then synchronizes `self->field_0C = self->field_10`.

Implemented in pure C++ in `src/zone_spatial_grid_reset.cpp` and declared in
`include/zone_spatial_grid_reset.h`.

## Function specification

| Property | Value |
|---|---|
| Function | `func_001F2BD0` |
| Virtual address range | `0x1F2BD0`–`0x1F2C20` |
| Code extent | `0x1F2BD0`–`0x1F2C14` (68 bytes, 17 instructions) |
| Delay slot | `0x1F2C10` (`addiu $sp, $sp, 32`) |
| Alignment padding | `0x1F2C14`–`0x1F2C20` (12 bytes `nop` padding) |
| File offset range | `0xF2DB0`–`0xF2E00` |
| Relocations | 1 (`R_MIPS_26` function call) |

## Relocation analysis

The single direct function call relocation matches the authentic ELF site:

| Offset | Opcode Hex | Relocation Type | Target Symbol | Target Address |
|---|---|---|---|---|
| `+0x24` | `0x0c07db30` | `R_MIPS_26` | `func_001F6CC0` | `0x1F6CC0` |

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F2AD0`):** Bounding volume update ends at `0x1F2BC4`
  followed by 12 bytes of `nop` padding to `0x1F2BD0` (file offset `0xF2DB0`).
  `0x1F2BD0 - 0x1F2BD0 = 0` gap/overlap.
- **Following boundary (`func_001F2C20`):** Next routine begins at `0x1F2C20`
  (file offset `0xF2E00`, `27bdffd0 addiu $sp, $sp, -48`).
  `0x1F2C20 - 0x1F2C20 = 0` gap/overlap.

## Verification & TDD evidence

- **Red test:** `build/reset-arg2-red.log` captured observable assertion failure
  (`Assertion last_f6cc0_item2 == &item1 failed`) with exit status `-6` (SIGABRT)
  when mutating the second argument. `build/reset-order-red.log` captured observable
  assertion failure (`Assertion field_0c_at_call_time == &item1 failed`) with exit status `-6`
  when mutating call ordering to overwrite `field_0C` before the callback.
- **Green test:** `build/reset-order-green.log` confirmed native pass (2 passed in 0.29s)
  under C++98 `-m32` verifying exact typed `SpatialItem *` variadic argument retrieval,
  first argument (`field_10`), second argument (`field_0C`), call ordering (prior to `field_0C`
  update), and final reset state.
- **Provenance gate:** `tests/test_zone_spatial_grid_reset_provenance.py` (6 passed)
  verifies fresh compilation with `mwccps2.exe` v2.3.1.01 under `wibo`, 100% exact
  literal instruction matching across all 68 bytes (`literal_match: true`), 1 direct
  `R_MIPS_26` function relocation, matching resolved SHA-256 hash
  (`f28d39c41c74b96050a4fa27829784f9f074176c836c0ab442b942f59370b819`),
  separate verification of original ELF 12-byte trailing NOP alignment padding
  (`original_padding_verified: true`, `0x1F2C14`..`0x1F2C20`) strictly outside the
  68-byte function matching gate, corrupted instruction rejection against a passing baseline,
  unpinned ELF rejection, and CLI zero-exit contract.
- **Configuration policy:** Promoted to `Matching` in `configure.py` following
  independent review verification and coordinator approval; `config.yml` and `symbols.txt` remain untouched.
