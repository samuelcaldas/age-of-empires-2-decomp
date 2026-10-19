# ZoneSpatialGrid field unbind/clear verification (`func_001F28A0`)

## Overview

`func_001F28A0` spans virtual address range `0x1F28A0`–`0x1F2900` (file offsets
`0xF2A80`–`0xF2AE0`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
This leaf function unbinds/clears five header fields (`field_10`, `field_04`,
`field_08`, `field_0C`, and `field_1C`) by checking if each field's current value
equals the input parameter `val`, resetting matching fields to 0.

Implemented in pure C++ in `src/zone_spatial_grid_clear.cpp` and declared in
`include/zone_spatial_grid_clear.h`.

## Function specification

| Property | Value |
|---|---|
| Function | `func_001F28A0` |
| Virtual address range | `0x1F28A0`–`0x1F2900` |
| Code extent | `0x1F28A0`–`0x1F28F8` (88 bytes, 22 instructions including delay slot `nop`) |
| Functional code | 84 bytes (21 instructions, `[0x1F28A0, 0x1F28F4)`) |
| Delay slot | `0x1F28F4` (`nop`) |
| Alignment padding | `0x1F28F8`–`0x1F2900` (8 bytes `nop` padding) |
| File offset range | `0xF2A80`–`0xF2AE0` |
| Relocations | 0 (leaf function) |

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F2820`):** Entity removal ends at `0x1F2894`
  followed by 12 bytes of `nop` padding to `0x1F28A0` (file offset `0xF2A80`).
  `0x1F28A0 - 0x1F28A0 = 0` gap/overlap.
- **Following boundary (`func_001F2900`):** Spatial update begins at `0x1F2900`
  (file offset `0xF2AE0`) with prologue `addiu $sp, $sp, -64`.
  `0x1F2900 - 0x1F2900 = 0` gap/overlap.

## Verification & TDD evidence

- **Red test:** `build/clear-red.log` captured observable assertion failure
  (`Assertion grid.field_10 == 0 failed`) with exit status `-6` (SIGABRT).
- **Green test:** `build/clear-green.log` confirmed native pass (2 passed in 0.26s)
  under C++98 `-m32`.
- **Provenance gate:** `tests/test_zone_spatial_grid_clear_provenance.py` (5 passed)
  verifies fresh compilation with `mwccps2.exe` v2.3.1.01 under `wibo`, literal byte
  matching against authentic `AOK.ELF`, 0 relocations, corrupted instruction
  rejection, and CLI contract.
- **Configuration policy:** Registered as `NonMatching` pending review; `config.yml`
  and `symbols.txt` remain untouched.
