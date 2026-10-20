# ZoneSpatialGrid field accessors verification (`func_001F26C0`–`func_001F26F0`)

## Overview

The `ZoneSpatialGrid` accessors span virtual address range `0x1F26C0`–`0x1F2700`
(file offsets `0xF28A0`–`0xF28E0`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
These four leaf functions return fundamental spatial grid dimensions and bounds
from the object's header.

Implemented in pure C++ in `src/zone_spatial_grid_getters.cpp` and declared in
`include/zone_spatial_grid_getters.h`.

## Function specifications

Each function is 8 bytes of code, aligned to 16 bytes by 8 bytes of trailing `nop` padding:

| Function | Virtual Address | File Offset | Size | Instructions & Delay Slot | Return Value |
|---|---|---|---|---|---|
| `func_001F26C0` | `0x1F26C0`–`0x1F26C8` | `0xF28A0`–`0xF28A8` | 8 B | `jr $ra`<br>`lw $v0, 0x10($a0)` | `self->field_10` |
| `func_001F26D0` | `0x1F26D0`–`0x1F26D8` | `0xF28B0`–`0xF28B8` | 8 B | `jr $ra`<br>`lw $v0, 0x04($a0)` | `self->field_04` |
| `func_001F26E0` | `0x1F26E0`–`0x1F26E8` | `0xF28C0`–`0xF28C8` | 8 B | `jr $ra`<br>`lw $v0, 0x08($a0)` | `self->field_08` |
| `func_001F26F0` | `0x1F26F0`–`0x1F26F8` | `0xF28D0`–`0xF28D8` | 8 B | `jr $ra`<br>`lw $v0, 0x0C($a0)` | `self->field_0C` |

Total code extent: 32 bytes (`0x20`). Total slice size with alignment: 64 bytes (`0x40`).
All four functions are leaf functions with zero relocations.

## Contiguity & boundary proofs

- **Preceding boundary (Block 63 Destructor):**
  - Code extent: `0x1F2590`–`0x1F26B4` (file offsets `0xF2770`–`0xF2894`, 292 instruction bytes).
  - Delay slot: `0x1F26B0` (`addiu $sp, $sp, 96`).
  - Alignment padding: `0x1F26B4`–`0x1F26C0` (file offsets `0xF2894`–`0xF28A0`, 12 bytes of `nop` padding).
  - Aligned slice boundary: ends at `0x1F26C0` (file offset `0xF28A0`).
  - Getter slice boundary: begins at `0x1F26C0` (file offset `0xF28A0`).
  - Contiguity: exactly 0 unmapped gap bytes and 0 overlapping bytes between the destructor slice and the getter slice.
- **Following boundary (`func_001F2700`):**
  - Getter slice extent: code ends at `0x1F26F8` with 8 bytes of `nop` padding to `0x1F2700` (file offset `0xF28E0`).
  - `func_001F2700` starts at `0x1F2700` (file offset `0xF28E0`) with prologue `addiu $sp, $sp, -16; sd $ra, 0($sp); jal 0x1F2E00`.
  - Contiguity: `0x1F2700 - 0x1F2700 = 0` gap/overlap.

## Verification & TDD evidence

- **Red test:** `build/getters-red.log` captured observable assertion failure on
  mock object field read mismatch (`Assertion func_001F26C0(ptr) == 0x456789AB failed`).
- **Green test:** `build/getters-green.log` confirmed native pass (2 passed in 0.18s)
  with C++98 `-m32`.
- **Provenance gate:** `tests/test_zone_spatial_grid_getters_provenance.py` (5 passed)
  verifies fresh compilation with `mwccps2.exe` v2.3.1.01 under `wibo`, literal byte
  matching against authentic `AOK.ELF`, corrupted instruction rejection, and CLI contract.
- **Relocation analysis:** Verified 0 relocations across all 4 functions.
- **Configuration policy:** Registered as `NonMatching` pending merge; `config.yml`
  and `symbols.txt` remain untouched.
- **Test suite count reconciliation:**
  - Initial baseline: 2,613 tests.
  - Post-Block 61/62: 2,620 tests (+7 tests).
  - Post-Block 63: 2,646 tests (+26 tests across 4 modules: block63, state, list, provenance).
  - Post-Getters: 2,653 tests (+7 tests: 2 native + 5 provenance).
  - Zero failures and zero skips across all 2,653 tests.
