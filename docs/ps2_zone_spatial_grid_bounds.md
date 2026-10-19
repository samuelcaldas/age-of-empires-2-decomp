# ZoneSpatialGrid bounding volume update verification (`func_001F2AD0`)

## Overview

`func_001F2AD0` spans virtual address range `0x1F2AD0`–`0x1F2BD0` (file offsets
`0xF2CB0`–`0xF2DB0`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
This function updates entity bounding volumes and adjusts quadrant occupancy:
it updates `self->field_0C`, probes spatial handles via `func_001F6CC0`, clears
prior occupancy via `func_001F6750`, rebinds quadrant handles via `self->field_1C`,
and triggers entity `vtable[55]` (`method_DC(1)`).

Implemented in pure C++ in `src/zone_spatial_grid_bounds.cpp` and declared in
`include/zone_spatial_grid_bounds.h`.

## Function specification

| Property | Value |
|---|---|
| Function | `func_001F2AD0` |
| Virtual address range | `0x1F2AD0`–`0x1F2BD0` |
| Code extent | `0x1F2AD0`–`0x1F2BC4` (244 bytes, 61 instructions) |
| Delay slot | `0x1F2BC0` (`addiu $sp, $sp, 48`) |
| Alignment padding | `0x1F2BC4`–`0x1F2BD0` (12 bytes `nop` padding) |
| File offset range | `0xF2CB0`–`0xF2DB0` |
| Relocations | 4 (`R_MIPS_26` function calls) |

## Relocation analysis

All 4 direct function call relocations match authentic ELF sites:

| Offset | Opcode Hex | Relocation Type | Target Symbol | Target Address |
|---|---|---|---|---|
| `+0x28` | `0x0c07db30` | `R_MIPS_26` | `func_001F6CC0` | `0x1F6CC0` |
| `+0x54` | `0x0c07d9d4` | `R_MIPS_26` | `func_001F6750` | `0x1F6750` |
| `+0x7C` | `0x0c07d9d4` | `R_MIPS_26` | `func_001F6750` | `0x1F6750` |
| `+0xB8` | `0x0c07d9d4` | `R_MIPS_26` | `func_001F6750` | `0x1F6750` |

Virtual method dispatch at `+0xD8`: `vtable[55]` (`0xDC`) invoked as `method_DC(1)`.

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F2AC0`):** Field setter ends at `0x1F2AC8`
  followed by 8 bytes of `nop` padding to `0x1F2AD0` (file offset `0xF2CB0`).
  `0x1F2AD0 - 0x1F2AD0 = 0` gap/overlap.
- **Following boundary (`func_001F2BD0`):** Next routine begins at `0x1F2BD0`
  (file offset `0xF2DB0`).
  `0x1F2BD0 - 0x1F2BD0 = 0` gap/overlap.

## Verification & TDD evidence

- **Red test:** `build/bounds-red.log` captured observable assertion failure
  (`Assertion grid.field_0C == &item1 failed`) with exit status `-6` (SIGABRT).
- **Green test:** `build/bounds-green.log` confirmed native pass (2 passed in 0.24s)
  under C++98 `-m32`.
- **Provenance gate:** `tests/test_zone_spatial_grid_bounds_provenance.py` (6 passed)
  verifies fresh compilation with `mwccps2.exe` v2.3.1.01 under `wibo`, 4 relocations,
  corrupted instruction rejection, and CLI contract.
- **Configuration policy:** Registered as `NonMatching` pending exact instruction
  scheduling resolution; `config.yml` and `symbols.txt` remain untouched.
