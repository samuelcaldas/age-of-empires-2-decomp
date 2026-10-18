# Nearest elevation mesh vertex search at 0x3283C0

`func_003283C0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_elevation_mesh_nearest.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **493/524 instruction bytes (94.08%)**
(120 of 131 instructions identical) against the original ELF binary after
resolving two `R_MIPS_26` call relocations to `func_123350` and four
`R_MIPS_LITERAL` relocations to `1.4f` and `0.61f`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x3283C0, 0x3285CC)`, file `[0x2285A0, 0x2287AC)`.
  The function spans 524 instruction bytes (0x20C), followed by 4 bytes of
  alignment-padding nops up to `0x3285D0`. Symbol size is `0x20C`.
- Stack frame: 192 bytes (`addiu $sp, $sp, -0xC0`), saving `$ra` (0x90),
  `$fp` (0x80), `$s7` (0x70), `$s6` (0x60), `$s5` (0x50), `$s4` (0x40),
  `$s3` (0x30), `$s2` (0x20), `$s1` (0x10), and `$s0` (0x00).

## Observable behavior

1. Boundary guards: if `tag < 0`, `self->m_count == 0`, or `tag >= self->m_count`,
   return NULL.
2. Read vertex count for tag: `count = self->m_table_8[tag]`. If `count == 0`,
   return NULL.
3. Access per-tag vertex buffer: `vertices = (MeshVertex *)self->m_table_0[tag]`.
4. Initialize search: `best_dist = 9999`, `best_vertex = 0`.
5. Iterate each vertex in the buffer:
   - Compute `dx = abs(target_x - vertex->m_x)` and `dy = abs(target_y - vertex->m_y)`.
   - Calculate diagonal/octagonal distance:
     If `dy < dx`: `dist = (dx - dy) + func_123350(0.61f + 1.4f * dy)`.
     Else: `dist = (dy - dx) + func_123350(0.61f + 1.4f * dx)`.
   - If `dist < best_dist`: check whether `vertex->m_id` is present in `exclude_list`.
     If not excluded, update `best_dist = dist` and `best_vertex = vertex`.
6. Clamping: if `best_dist >= 256`, clamp to 255.
7. If `best_vertex != 0`, store clamped distance into `best_vertex->m_flags_4`.
8. Return `best_vertex`.

## Matching analysis and compiler blocker

The candidate matches 493 of 524 instruction bytes (94.08%). 120 of 131 instructions
are byte-for-byte identical. The remaining 11 instructions involve minor compiler
register choices:
- Prologue register save sequence between `$a1`, `$a2`, `$t1`, and `$t2`.
- Loop temporary register for exclude-list index (`$a2` vs `$a3`).
- All loop structures, distance calculations, floating-point literals, and branch
  targets are functionally and structurally identical.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_elevation_mesh_nearest.py \
  tests/test_tactical_ai_combat_subsystem_elevation_mesh_nearest_matching.py
```

The focused test run comprises **9 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating early exits, nearest
  distance search, exclude list filtering, and distance clamping to 255.
- Seven production source mutations independently compiled and verified
  rejected (tag guard, upper bound guard, initial best distance, exclude match,
  clamp condition, clamp value, distance bias).
- One matching test compiling fresh with Ninja/MWCC and verifying >= 93.5%
  instruction byte match against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
