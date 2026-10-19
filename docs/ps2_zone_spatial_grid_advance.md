# ZoneSpatialGrid occupant advance verification (`func_001F2C20`)

## Overview

`func_001F2C20` spans virtual address range `0x1F2C20`–`0x1F2CB0` (file offsets
`0xF2E00`–`0xF2E90`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
This routine advances the spatial occupant pointer: it checks `self->field_0C`,
invokes `func_001F6CB0(self->field_0C)`, verifies the returned `item` is non-null,
triggers `item->method_DC(1)` via vtable slot 55, updates grid fields via
`func_001F2AB0(self, item)` and `func_001F2AC0(self, item)`, updates `self->field_0C = item`,
and returns 1 (or 0 if any null guard fails).

Implemented in pure C++ in `src/zone_spatial_grid_advance.cpp` and declared in
`include/zone_spatial_grid_advance.h`.

## Function specification

| Property | Value |
|---|---|
| Function | `func_001F2C20` |
| Virtual address range | `0x1F2C20`–`0x1F2CB0` |
| Code extent | `0x1F2C20`–`0x1F2CAC` (140 bytes, 35 instructions) |
| Delay slot | `0x1F2CA8` (`addiu $sp, $sp, 48`) |
| Alignment padding | `0x1F2CAC`–`0x1F2CB0` (4 bytes `nop` padding) |
| File offset range | `0xF2E00`–`0xF2E90` |
| Relocations | 3 (`R_MIPS_26` function calls) |

## Relocation analysis

All 3 direct function call relocations match authentic ELF sites:

| Offset | Opcode Hex | Relocation Type | Target Symbol | Target Address |
|---|---|---|---|---|
| `+0x28` | `0x0c07db2c` | `R_MIPS_26` | `func_001F6CB0` | `0x1F6CB0` |
| `+0x5C` | `0x0c07caac` | `R_MIPS_26` | `func_001F2AB0` | `0x1F2AB0` |
| `+0x68` | `0x0c07cab0` | `R_MIPS_26` | `func_001F2AC0` | `0x1F2AC0` |

Virtual method dispatch at `+0x50`: `vtable[55]` (`0xDC`) invoked as `method_DC(1)`.

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F2BD0`):** Occupant reset ends at `0x1F2C14`
  followed by 12 bytes of `nop` padding to `0x1F2C20` (file offset `0xF2E00`).
  `0x1F2C20 - 0x1F2C20 = 0` gap/overlap.
- **Following boundary (`func_001F2CB0`):** Next routine begins at `0x1F2CB0`
  (file offset `0xF2E90`, `27bdffd0 addiu $sp, $sp, -48`).
  `0x1F2CB0 - 0x1F2CB0 = 0` gap/overlap.

## Verification & TDD evidence

- **Red test:** `build/advance-red.log` captured observable assertion failure
  (`Assertion res1 == 0 failed`) with exit status `-6` (SIGABRT) on stub returning `-1`.
- **Green test:** `build/advance-green.log` confirmed native pass (2 passed in 0.25s)
  under C++98 `-m32` verifying both null guards, vtable slot 55 invocation (arg=1),
  setters `func_001F2AB0`/`func_001F2AC0`, `field_0C` update, and return codes (0/1).
- **Provenance gate:** `tests/test_zone_spatial_grid_advance_provenance.py` (6 passed)
  verifies fresh compilation under `wibo` using `compilers/PS2/mwcc-2.3.1.01/mwccps2.exe`, followed by exact
  literal instruction matching across all 140 bytes (`literal_match: true`), 3 direct
  `R_MIPS_26` function relocations, matching resolved SHA-256 hash
  (`7334e37f68281872d4a6a87b951d09b2869cc348d41ce3057e95f081835a213e`),
  separate verification of original ELF 4-byte trailing NOP alignment padding
  (`original_padding_verified: true`, `0x1F2CAC`..`0x1F2CB0`) strictly outside the
  140-byte function matching gate, corrupted instruction rejection against a passing baseline,
  unpinned ELF rejection, and CLI zero-exit contract.
- **Configuration policy:** Registered as `NonMatching` in `configure.py` per standing
  policy pending peer review; `config.yml` and `symbols.txt` remain untouched.
