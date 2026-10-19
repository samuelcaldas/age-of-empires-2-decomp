# ZoneSpatialGrid entity removal verification (`func_001F2820`)

## Overview

`func_001F2820` spans virtual address range `0x1F2820`–`0x1F28A0` (file offsets
`0xF2A00`–`0xF2A80`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
This function implements `ZoneSpatialGrid::remove`: if the input element pointer
is non-null, it queries `func_001F2E00(self, elem)`. If found, it decrements the
active entity counter `self->field_18--`, unlinks the node from the circular
doubly-linked sentinel list (`self->field_14`), and releases node memory via
`func_00116F68(node)`.

Implemented in pure C++ in `src/zone_spatial_grid_remove.cpp` and declared in
`include/zone_spatial_grid_remove.h`.

## Function specification

| Property | Value |
|---|---|
| Function | `func_001F2820` |
| Virtual address range | `0x1F2820`–`0x1F28A0` |
| Code extent | `0x1F2820`–`0x1F2894` (116 bytes, 29 instructions) |
| Delay slot | `0x1F2890` (`addiu $sp, $sp, 32`) |
| Alignment padding | `0x1F2894`–`0x1F28A0` (12 bytes `nop` padding) |
| File offset range | `0xF2A00`–`0xF2A80` |
| Relocations | 2 (`R_MIPS_26` function calls) |

## Relocation analysis

All 2 relocations match authentic ELF sites and targets exactly:

| Offset | Opcode Hex | Relocation Type | Target Symbol | Target Address |
|---|---|---|---|---|
| `+0x1C` | `0x0c07cb80` | `R_MIPS_26` | `func_001F2E00` | `0x1F2E00` |
| `+0x58` | `0x0c045bda` | `R_MIPS_26` | `func_00116F68` | `0x116F68` |

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F2730`):** Entity insertion ends at `0x1F2814`
  followed by 12 bytes of `nop` padding to `0x1F2820` (file offset `0xF2A00`).
  `0x1F2820 - 0x1F2820 = 0` gap/overlap.
- **Following boundary (`func_001F28A0`):** Field unbind begins at `0x1F28A0`
  (file offset `0xF2A80`).
  `0x1F28A0 - 0x1F28A0 = 0` gap/overlap.

## Verification & TDD evidence

- **Red test:** `build/remove-red.log` captured observable assertion failure
  (`Assertion call_log.size() == 1 failed`) with exit status `-6` (SIGABRT).
- **Green test:** `build/remove-green.log` confirmed native pass (2 passed in 0.37s)
  under C++98 `-m32`.
- **Provenance gate:** `tests/test_zone_spatial_grid_remove_provenance.py` (6 passed)
  verifies fresh compilation with `mwccps2.exe` v2.3.1.01 under `wibo`, literal byte
  matching against authentic `AOK.ELF`, 2-relocation manifest enforcement, corrupted
  instruction rejection, and CLI contract.
- **Configuration policy:** Registered as `NonMatching` pending review; `config.yml`
  and `symbols.txt` remain untouched.
