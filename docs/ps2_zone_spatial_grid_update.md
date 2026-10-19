# ZoneSpatialGrid spatial update verification (`func_001F2900`)

## Overview

`func_001F2900` spans virtual address range `0x1F2900`–`0x1F2980` (file offsets
`0xF2AE0`–`0xF2B60`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
This function updates the spatial position of an existing grid entity: it queries
the sentinel list via `func_001F2E00(self, item)`. If found, it optionally triggers
`func_001F65A0(self->field_04)` when `field_04 != 0`, clears `self->field_0C = 0`
and `self->field_08 = 0`, and dispatches bucket table re-insertion via
`func_001F2EB0(self, node->elem, param2)`.

Implemented in pure C++ in `src/zone_spatial_grid_update.cpp` and declared in
`include/zone_spatial_grid_update.h`.

## Function specification

| Property | Value |
|---|---|
| Function | `func_001F2900` |
| Virtual address range | `0x1F2900`–`0x1F2980` |
| Code extent | `0x1F2900`–`0x1F297C` (124 bytes, 31 instructions) |
| Delay slot | `0x1F2978` (`addiu $sp, $sp, 64`) |
| Alignment padding | `0x1F297C`–`0x1F2980` (4 bytes `nop` padding) |
| File offset range | `0xF2AE0`–`0xF2B60` |
| Relocations | 3 (`R_MIPS_26` function calls) |

## Relocation analysis

All 3 relocations match authentic ELF sites and targets exactly:

| Offset | Opcode Hex | Relocation Type | Target Symbol | Target Address |
|---|---|---|---|---|
| `+0x18` | `0x0c07cb80` | `R_MIPS_26` | `func_001F2E00` | `0x1F2E00` |
| `+0x38` | `0x0c07d968` | `R_MIPS_26` | `func_001F65A0` | `0x1F65A0` |
| `+0x50` | `0x0c07cbac` | `R_MIPS_26` | `func_001F2EB0` | `0x1F2EB0` |

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F28A0`):** Field clear ends at `0x1F28F8`
  followed by 8 bytes of `nop` padding to `0x1F2900` (file offset `0xF2AE0`).
  `0x1F2900 - 0x1F2900 = 0` gap/overlap.
- **Following boundary (`func_001F2980`):** Occupant re-link begins at `0x1F2980`
  (file offset `0xF2B60`).
  `0x1F2980 - 0x1F2980 = 0` gap/overlap.

## Verification & TDD evidence

- **Red test:** `build/update-red.log` captured observable assertion failure
  (`Assertion call_log.size() == 1 failed`) with exit status `-6` (SIGABRT).
- **Green test:** `build/update-green.log` confirmed native pass (2 passed in 0.26s)
  under C++98 `-m32`.
- **Provenance gate:** `tests/test_zone_spatial_grid_update_provenance.py` (6 passed)
  verifies fresh compilation with `mwccps2.exe` v2.3.1.01 under `wibo`, literal byte
  matching against authentic `AOK.ELF`, 3-relocation manifest enforcement, corrupted
  instruction rejection, and CLI contract.
- **Configuration policy:** Registered as `NonMatching` pending review; `config.yml`
  and `symbols.txt` remain untouched.
