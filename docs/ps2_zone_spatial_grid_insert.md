# ZoneSpatialGrid entity insertion verification (`func_001F2730`)

## Overview

`func_001F2730` spans virtual address range `0x1F2730`–`0x1F2820` (file offsets
`0xF2910`–`0xF2A00`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
This function implements `ZoneSpatialGrid::insert`: it registers the entity,
checks for membership, allocates a 12-byte `ListNode` on the heap if needed,
splices the node into `self->field_14` (circular doubly-linked sentinel list),
increments `self->field_18++`, and dispatches spatial grid updates via `func_001F2EB0`.

Implemented in pure C++ in `src/zone_spatial_grid_insert.cpp` and declared in
`include/zone_spatial_grid_insert.h`.

## Function specification

| Property | Value |
|---|---|
| Function | `func_001F2730` |
| Virtual address range | `0x1F2730`–`0x1F2820` |
| Code extent | `0x1F2730`–`0x1F2814` (228 bytes, 57 instructions) |
| Delay slot | `0x1F2810` (`addiu $sp, $sp, 96`) |
| Alignment padding | `0x1F2814`–`0x1F2820` (12 bytes `nop` padding) |
| File offset range | `0xF2910`–`0xF2A00` |
| Relocations | 5 (`R_MIPS_26` function calls) |

## Relocation analysis

All 5 relocations match authentic ELF sites and targets exactly:

| Offset | Opcode Hex | Relocation Type | Target Symbol | Target Address |
|---|---|---|---|---|
| `+0x2C` | `0x0c07db34` | `R_MIPS_26` | `func_001F6CD0` | `0x1F6CD0` |
| `+0x38` | `0x0c07cb80` | `R_MIPS_26` | `func_001F2E00` | `0x1F2E00` |
| `+0x4C` | `0x0c0450fe` | `R_MIPS_26` | `func_001143F8` | `0x1143F8` |
| `+0x70` | `0x0c07db28` | `R_MIPS_26` | `func_001F6CA0` | `0x1F6CA0` |
| `+0xB8` | `0x0c07cbac` | `R_MIPS_26` | `func_001F2EB0` | `0x1F2EB0` |

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F2700`):** Lookup wrapper ends at `0x1F2730`
  (file offset `0xF2910`, 48 bytes, 0 padding).
  `0x1F2730 - 0x1F2730 = 0` gap/overlap.
- **Following boundary (`func_001F2820`):** Entity removal begins at `0x1F2820`
  (file offset `0xF2A00`) with prologue `addiu $sp, $sp, -32; sd $ra, 16($sp)`.
  `0x1F2820 - 0x1F2820 = 0` gap/overlap.

## Verification & TDD evidence

- **Red test:** `build/insert-red.log` captured observable assertion failure
  (`Assertion res == 1 failed`) with exit status `-6` (SIGABRT).
- **Green test:** `build/insert-green.log` confirmed native pass (2 passed in 0.31s)
  under C++98 `-m32`.
- **Provenance gate:** `tests/test_zone_spatial_grid_insert_provenance.py` (6 passed)
  verifies fresh compilation with `mwccps2.exe` v2.3.1.01 under `wibo`, literal byte
  matching against authentic `AOK.ELF`, 5-relocation manifest enforcement, corrupted
  instruction rejection, and CLI contract.
- **Configuration policy:** Registered as `NonMatching` pending review; `config.yml`
  and `symbols.txt` remain untouched.
