# ZoneSpatialGrid field setters verification (`func_001F2AB0` & `func_001F2AC0`)

## Overview

`func_001F2AB0` and `func_001F2AC0` span virtual address range `0x1F2AB0`–`0x1F2AD0`
(file offsets `0xF2C90`–`0xF2CB0`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
These two leaf functions store an integer value into `self->field_04` and `self->field_08`
respectively, directly complementing accessors `func_001F26D0` and `func_001F26E0`.

Implemented in pure C++ in `src/zone_spatial_grid_setters.cpp` and declared in
`include/zone_spatial_grid_setters.h`.

## Function specifications

Each function is 8 bytes of code, aligned to 16 bytes by 8 bytes of trailing `nop` padding:

| Function | Virtual Address | File Offset | Size | Instructions & Delay Slot | Behavior |
|---|---|---|---|---|---|
| `func_001F2AB0` | `0x1F2AB0`–`0x1F2AB8` | `0xF2C90`–`0xF2C98` | 8 B | `jr $ra`<br>`sw $a1, 0x04($a0)` | `self->field_04 = val;` |
| `func_001F2AC0` | `0x1F2AC0`–`0x1F2AC8` | `0xF2CA0`–`0xF2CA8` | 8 B | `jr $ra`<br>`sw $a1, 0x08($a0)` | `self->field_08 = val;` |

Total code extent: 16 bytes (`0x10`). Total slice size with alignment: 32 bytes (`0x20`).
Both functions are leaf functions with zero relocations.

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F2980`):** Spatial re-link ends at `0x1F2AA4`
  followed by 12 bytes of `nop` padding to `0x1F2AB0` (file offset `0xF2C90`).
  `0x1F2AB0 - 0x1F2AB0 = 0` gap/overlap.
- **Following boundary (`func_001F2AD0`):** Bounding box routine begins at
  `0x1F2AD0` (file offset `0xF2CB0`) with prologue `addiu $sp, $sp, -64`.
  `0x1F2AD0 - 0x1F2AD0 = 0` gap/overlap.

## Verification & TDD evidence

- **Red test:** `build/setters-red.log` captured observable assertion failure
  (`Assertion grid.field_04 == 0x42 failed`) with exit status `-6` (SIGABRT).
- **Green test:** `build/setters-green.log` confirmed native pass (2 passed in 0.16s)
  under C++98 `-m32`.
- **Provenance gate:** `tests/test_zone_spatial_grid_setters_provenance.py` (5 passed)
  verifies fresh compilation with `mwccps2.exe` v2.3.1.01 under `wibo`, literal byte
  matching against authentic `AOK.ELF`, 0 relocations, corrupted instruction
  rejection, and CLI contract.
- **Configuration policy:** Registered as `NonMatching` pending review; `config.yml`
  and `symbols.txt` remain untouched.
