# Spatial grid constructor verification (Block 62)

## Current status

Block 62 (`zone_spatial_grid_constructor`, `func_001F24E0`) is implemented in
pure C++ in `src/zone_spatial_grid_constructor.cpp`.

The implementation matches all 172 instruction bytes (`0xAC`) of the original
PlayStation 2 PAL executable (`orig/SLES-50282/AOK.ELF`) after resolving three
relocations: two address relocations to vtable `D_004D9AD0` (`R_MIPS_HI16` and
`R_MIPS_LO16`), and one call relocation to `func_001F2DA0` (`R_MIPS_26`).
As directed by repository coordination, `config.yml` and `symbols.txt` remain
untouched pending integration review.

## Binary slice boundaries

The executable `PT_LOAD` mapping places file offset `0x1E0` at virtual address
`0x100000`, so `VA = file_offset + 0xFFE20`.

| Property | Value |
|---|---|
| Function | `func_001F24E0` |
| Virtual address | `0x1F24E0` |
| File offset start | `0xF26C0` |
| Code size | 172 bytes (`0xAC`, 43 instructions) |
| Delay slot instruction | `0x1F2588` (file offset `0xF2768`) |
| Slice end | `0xF2770` (virtual address `0x1F2590`) |
| Alignment padding | 4 bytes (`nop`) |

Note: `0x1F2590` marks the exact beginning of the next function's stack
prologue (`addiu $sp, $sp, -0x60`). The slice span is exactly `0xB0` (176 bytes).

## Preserved behavior

`func_001F24E0(ZoneSpatialGrid *self)` constructs a `ZoneSpatialGrid` object:

1. Installs the vtable pointer `D_004D9AD0` at offset `0x00`.
2. Clears basic members from offset `0x04` to `0x1C` (7 integer fields).
3. Sets configuration fields: `field_A98 = 0`, `field_A9C = 1`, `field_AA0 = 0`,
   `field_AA4 = 0`, `field_AA8 = 0`, `field_AAC = 1`, `field_AB0 = 0`.
4. Executes an initialization loop from `i = 0` to `9`:
   - Clears 10 pointers at offset `0x20 + i*4`.
   - Clears the first byte of 10 buckets at offset `0x48 + i*256`.
   - Clears 10 integers at offset `0xA48 + i*4`.
   - Clears 10 integers at offset `0xA70 + i*4`.
5. Invokes initialization helper `func_001F2DA0(self)`.
6. Returns `self` as the constructor result.

## Binary instruction matching

The compiled function produces exact original instruction bytes after resolving
the three explicit relocations:

```text
ea822e31cf90596ffa31dad21d1d7bf170dd240b126535587c7a292fb97a92be
```

Relocation table:

| Offset | Type | Symbol | Target Address |
|---|---|---|---|
| `0x04` | `R_MIPS_HI16` | `D_004D9AD0` | `0x4D9AD0` |
| `0x10` | `R_MIPS_LO16` | `D_004D9AD0` | `0x4D9AD0` |
| `0x90` | `R_MIPS_26` | `func_001F2DA0` | `0x1F2DA0` |

## Regression validation

- Native behavioral test: 8 assertion groups passed in C++98 `-m32`.
- Block 62 provenance suite (`test_zone_spatial_grid_constructor_provenance.py`):
  5 passed in 0.42s.
- Focused Block 62 module (`test_zone_spatial_grid_block62.py`): 2 passed in 0.19s.
- Full available repository test suite in `docker-dev`: 2,620 passed in 143.18s with zero failures and zero skips.
- Static checks: Clean under `flake8`, Markdown link validation, and `git diff --check`.
