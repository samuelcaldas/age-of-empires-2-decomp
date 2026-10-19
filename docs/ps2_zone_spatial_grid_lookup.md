# ZoneSpatialGrid entity lookup wrapper verification (`func_001F2700`)

## Overview

`func_001F2700` spans virtual address range `0x1F2700`–`0x1F2730` (file offsets
`0xF28E0`–`0xF2910`, 48 instruction bytes) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
This function implements a query helper over the `ZoneSpatialGrid` sentinel list,
invoking `func_001F2E00(self, item)` and extracting the first pointer field (`node[0]`)
if non-null, or returning `NULL`.

Implemented in pure C++ in `src/zone_spatial_grid_lookup.cpp` and declared in
`include/zone_spatial_grid_lookup.h`.

## Function specification

| Property | Value |
|---|---|
| Function | `func_001F2700` |
| Virtual address range | `0x1F2700`–`0x1F2730` |
| File offset range | `0xF28E0`–`0xF2910` |
| Code size | 48 bytes (12 instructions) |
| Alignment padding | 0 bytes (aligned to 16 bytes) |
| Relocations | 1 (`0x08`, `R_MIPS_26`, `func_001F2E00` at `0x1F2E00`) |
| Semantics | Lookup wrapper returning `node[0]` if found, else `NULL` |

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F26F0`):** Getter ends at `0x1F26F8` with 8 bytes
  of `nop` padding to `0x1F2700` (file offset `0xF28E0`).
  `0x1F2700 - 0x1F2700 = 0` gap/overlap.
- **Following boundary (`func_001F2730`):** List insertion routine begins at
  `0x1F2730` (file offset `0xF2910`) with prologue `addiu $sp, $sp, -96`.
  `0x1F2730 - 0x1F2730 = 0` gap/overlap.

## Verification & TDD evidence

- **Red test:** `build/lookup-red.log` captured observable assertion failure
  (`Assertion call_count == 1 failed`) with exit status `-6` (SIGABRT).
- **Green test:** `build/lookup-green.log` confirmed native pass (2 passed in 0.17s)
  under C++98 `-m32`.
- **Provenance gate:** `tests/test_zone_spatial_grid_lookup_provenance.py` (6 passed)
  verifies fresh compilation with `mwccps2.exe` v2.3.1.01 under `wibo`, literal byte
  matching against authentic `AOK.ELF`, relocation resolution, corrupted instruction
  rejection, and CLI contract.
- **Relocation analysis:** Verified single `R_MIPS_26` relocation at offset `0x08`
  targeting `func_001F2E00` (`0x1F2E00`).
- **Configuration policy:** Registered as `NonMatching` pending review; `config.yml`
  and `symbols.txt` remain untouched.
