# ZoneSpatialGrid spatial re-link verification (`func_001F2980`)

## Overview

`func_001F2980` spans virtual address range `0x1F2980`–`0x1F2AB0` (file offsets
`0xF2B60`–`0xF2C90`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
This function coordinates entity re-linking across spatial quadrants: it checks
`self->field_10`, queries `func_001F6C90`, unlinks and rebinds spatial handles
via `func_001F6CA0` and `func_001F2CB0`, invokes two entity virtual methods
(`vtable[55]` at offset `0xDC` and `vtable[10]` at offset `0x28`), and notifies
the global manager singleton `D_004D89C0` via `vtable[50]` at offset `0xC8`.

Implemented in pure C++ in `src/zone_spatial_grid_relink.cpp` and declared in
`include/zone_spatial_grid_relink.h`.

## Function specification

| Property | Value |
|---|---|
| Function | `func_001F2980` |
| Virtual address range | `0x1F2980`–`0x1F2AB0` |
| Code extent | `0x1F2980`–`0x1F2AA4` (292 bytes, 73 instructions) |
| Delay slot | `0x1F2AA0` (`addiu $sp, $sp, 80`) |
| Alignment padding | `0x1F2AA4`–`0x1F2AB0` (12 bytes `nop` padding) |
| File offset range | `0xF2B60`–`0xF2C90` |
| Relocations | 8 (6 `R_MIPS_26` calls + 2 `R_MIPS_GPREL16` data loads) |

## Relocation analysis

All 8 relocations match authentic ELF sites and targets exactly:

| Offset | Opcode Hex | Relocation Type | Target Symbol | Target Address |
|---|---|---|---|---|
| `+0x30` | `0x0c07db24` | `R_MIPS_26` | `func_001F6C90` | `0x1F6C90` |
| `+0x68` | `0x0c07db28` | `R_MIPS_26` | `func_001F6CA0` | `0x1F6CA0` |
| `+0x7C` | `0x0c07db24` | `R_MIPS_26` | `func_001F6C90` | `0x1F6C90` |
| `+0x90` | `0x0c07db28` | `R_MIPS_26` | `func_001F6CA0` | `0x1F6CA0` |
| `+0x9C` | `0x0c07db34` | `R_MIPS_26` | `func_001F6CD0` | `0x1F6CD0` |
| `+0xA8` | `0x0c07cb2c` | `R_MIPS_26` | `func_001F2CB0` | `0x1F2CB0` |
| `+0xDC` | `0x8f8489c0` | `R_MIPS_GPREL16` | `D_004D89C0` | `0x4D89C0` (`$gp - 30272`) |
| `+0xEC` | `0x8f858940` | `R_MIPS_GPREL16` | `D_004D8940` | `0x4D8940` (`$gp - 30400`) |

## Virtual call dispatches (no ELF relocation entry)

- `+0xC0`: `vtable[55]` (`0xDC`) invoked as `method_DC(1)`.
- `+0xD4`: `vtable[10]` (`0x28`) invoked as `method_28(2)`.
- `+0xFC`: `vtable[50]` (`0xC8`) invoked on `D_004D89C0` as `method_C8(D_004D8940, 0, 0, 0)`.

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F2900`):** Spatial update ends at `0x1F297C`
  followed by 4 bytes of `nop` padding to `0x1F2980` (file offset `0xF2B60`).
  `0x1F2980 - 0x1F2980 = 0` gap/overlap.
- **Following boundary (`func_001F2AB0`):** Leaf setter begins at `0x1F2AB0`
  (file offset `0xF2C90`).
  `0x1F2AB0 - 0x1F2AB0 = 0` gap/overlap.

## Verification & TDD evidence

- **Red test:** `build/relink-red.log` captured observable assertion failure
  (`Assertion call_log.size() == 1 failed`) with exit status `-6` (SIGABRT).
- **Green test:** `build/relink-green.log` confirmed native pass (2 passed in 0.26s)
  under C++98 `-m32`.
- **Provenance gate:** `tests/test_zone_spatial_grid_relink_provenance.py` (6 passed)
  verifies fresh compilation with `mwccps2.exe` v2.3.1.01 under `wibo`, literal byte
  matching against authentic `AOK.ELF`, 8-relocation manifest enforcement, corrupted
  instruction rejection, and CLI contract.
- **Configuration policy:** Registered as `Matching`; `config.yml`
  and `symbols.txt` remain untouched.
- **Test coverage note:** The conditional unbind branch `if (func_001F6C90(newItem) == elem) func_001F6CA0(newItem, 0);`
  is verified via exact instruction matching (all 292 bytes and 8 relocations proven identical);
  noted as a minor non-blocking behavioral test omission.
