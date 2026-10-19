# Spatial grid destructor verification (Block 63)

## Current status

Block 63 (`zone_spatial_grid_destructor`, `func_001F2590`) is implemented in
pure C++ in `src/zone_spatial_grid_destructor.cpp` and achieves 100% exact
instruction matching against PlayStation 2 PAL `AOK.ELF`.

The implementation compiles to exactly 292 instruction bytes (`0x124`) matching
all 73 MIPS instructions of the original function. The compiled object
contains all eight genuine relocations (two for vtable `D_004D9AD0`, six function
call relocations) matching the original relocation sites and targets exactly.
Resolved instruction SHA-256 matches the original executable slice exactly:
`f4a44b5c924308fcb9f9a0fd3ba2b96625e8fd4c7da75aea01a5e38020f624db`.
In accordance with repository instructions, `config.yml` and `symbols.txt` remain
untouched pending review.

## Binary slice boundaries

The executable `PT_LOAD` mapping places file offset `0x1E0` at virtual address
`0x100000`, so `VA = file_offset + 0xFFE20`.

| Property | Value |
|---|---|
| Function | `func_001F2590` |
| Virtual address | `0x1F2590` |
| File offset start | `0xF2770` |
| Code size | 292 bytes (`0x124`, 73 instructions) |
| Delay slot instruction | `0x1F26B0` (file offset `0xF2890`) |
| Slice end | `0xF28A0` (virtual address `0x1F26C0`) |
| Alignment padding | 12 bytes (`nop`) |

## Preserved behavior

`func_001F2590(ZoneSpatialGrid *self, short flag)` destroys a `ZoneSpatialGrid`:

1. **Null guard:** If `self == NULL`, returns `self` immediately without
   side effects.
2. **Vtable reset:** Reinstalls vtable pointer `D_004D9AD0` at offset `0x00`.
3. **Subsystem cleanup:** Calls `func_001F34D0(self)`.
4. **Sentinel-headed list cleanup:** If `self->field_14 != NULL`, iterates
   over nodes starting from `self->field_14->next` until returning to sentinel;
   destroys each item via virtual destructor and frees each element wrapper via
   `func_00116F68`. Frees the sentinel node and resets `self->field_14 = NULL`.
5. **Table cleanup loop:** Loops `i = 0` to `9`: if `table_20[i] != NULL`,
   calls `func_0021B430(table_20[i])`, then zeroes `table_20[i]`,
   `buckets_48[i][0]`, `table_A48[i]`, and `table_A70[0]`. When `table_20[i] == NULL`,
   the entire cleanup sequence for that entry is skipped.
6. **Sub-destructor:** Invokes `func_001F32F0(self)`.
7. **Scalar deleting destructor:** If `flag > 0`, invokes `func_100670(self)`
   (`operator delete`).
8. Returns `self`.

## Relocation analysis

All eight relocations are present in the compiled object matching authentic ELF sites:

| Offset | Type | Symbol | Target Address |
|---|---|---|---|
| `0x28` | `R_MIPS_HI16` | `D_004D9AD0` | `0x4D9AD0` |
| `0x2C` | `R_MIPS_LO16` | `D_004D9AD0` | `0x4D9AD0` |
| `0x30` | `R_MIPS_26` | `func_001F34D0` | `0x1F34D0` |
| `0x70` | `R_MIPS_26` | `func_00116F68` | `0x116F68` |
| `0x84` | `R_MIPS_26` | `func_00116F68` | `0x116F68` |
| `0xB0` | `R_MIPS_26` | `func_0021B430` | `0x21B430` |
| `0xE0` | `R_MIPS_26` | `func_001F32F0` | `0x1F32F0` |
| `0xF8` | `R_MIPS_26` | `func_100670` | `0x100670` |

Note: The first wrapper free relocation is located at `0x70` with `node->elem`
evaluated into `$a0` in the delay slot at `0x74`.

## Regression validation

- Native behavioral suites: 19 test cases passed in C++98 `-m32` across three modules:
  - `test_zone_spatial_grid_block63.py`: 2 passed.
  - `test_zone_spatial_grid_block63_state.py`: 12 passed (covering null guards, state clearing, table entry preservation, `table_A70[0]` offset clearing, signed short flag evaluation).
  - `test_zone_spatial_grid_block63_list.py`: 5 passed (covering sentinel ring list traversal, head reload, and element pointer reload).
- Block 63 provenance suite (`test_zone_spatial_grid_destructor_provenance.py`):
  7 passed (fresh compilation verification, literal instruction matching, 8-relocation manifest enforcement, corrupted instruction rejection, unpinned ELF rejection, homonymous section owner preservation, and CLI contract).
- Full available repository test suite in `docker-dev`: 2,646 passed in 131.99s with zero failures and zero skips.
- Static checks: Clean under `flake8`, Markdown link validation, and `git diff --check`.

## TDD chronology & evidence limitation

Durable logs preserved under `build/`:
1. **Null-table skip (Red):** `build/block63-null-table-red.log` (failed assertion `grid->buckets_48[i][0] == ((i % 2 == 0) ? 0 : 0x77)`).
   **Green:** `build/block63-null-table-green.log` (2 passed in 0.20s).
2. **Single-word zeroing `table_A70[0]` (Red):** `build/block63-a70-red.log` (failed assertion `grid->table_A70[i] == ((i == 0) ? 0 : 200 + i)`).
   **Green:** `build/block63-a70-green.log` (2 passed in 0.21s).
3. **Literal instruction matching (Red):** `build/block63-literal-red.log` (assertion `assert False is True`).
4. **List pointer reloads (Red):** `build/block63-list-red.log` (assertions `test_head_reload` and `test_element_reload` failed).

*Evidence limitation:* Separate standalone log files for intermediate list and literal green runs were not retained during active development; the current focused list suite (`test_zone_spatial_grid_block63_list.py`, 5 passed) and provenance suite (`test_zone_spatial_grid_destructor_provenance.py`, 7 passed) constitute the verified green evidence without claiming unpreserved logs.
