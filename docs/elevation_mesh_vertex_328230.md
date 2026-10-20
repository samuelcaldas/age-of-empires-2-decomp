# Elevation mesh vertex append at 0x328230

`func_00328230` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_elevation_mesh_vertex.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **190/196 instruction bytes (96.94%)**
(46 out of 49 instructions identical) after resolving two `R_MIPS_26` call
relocations to `func_123350` and one `R_MIPS_GPREL16` relocation to `D_004E350C`.
This function appends an 8-byte vertex record to the mesh descriptor's per-tag
buffer and increments the per-tag vertex counter.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x328230, 0x3282F4)`, file `[0x228410, 0x2284D4)`.
  The function spans 196 instruction bytes (0xC4), followed by 12 bytes of
  alignment-padding nops up to `0x328300` (`func_328300`). Symbol size is `0xC4`.
- Stack frame: 96 bytes (`addiu $sp, $sp, -0x60`), saving `$ra` (0x50),
  `$s4` (0x40), `$s3` (0x30), `$s2` (0x20), `$s1` (0x10), and `$s0` (0x00).
- Vertex record (8 bytes): `m_id` (4 bytes, offset `0x00`), two zero flag
  bytes at offsets `0x04` and `0x05`, followed by converted 8-bit coordinates
  `m_x` at `0x06` and `m_y` at `0x07`.

## Observable behavior

1. If `self->m_count == 0`, return immediately.
2. Index entity array `D_004E350C[id]`. If null, return immediately.
3. Compute buffer position: `buf = (char *)self->m_table_0[tag] + (self->m_table_8[tag] * 8)`.
4. Call `func_123350(entity->m_x)` and `func_123350(entity->m_y)` to convert
   floating-point world coordinates to integer tile coordinates.
5. Populate 8-byte vertex record at `buf`: store `id` as 32-bit int, clear
   flag bytes `0x04` and `0x05`, and store low bytes of x and y at `0x06`
   and `0x07`.
6. Increment vertex count: `self->m_table_8[tag]++`.

## Matching analysis and compiler blocker

The candidate matches 190 of 196 bytes (96.94%). All 46 operational instructions
are byte-for-byte identical. The only divergence is 3 instructions in the
prologue:
- Original copies `$a0` to `$s3` before the branch and `$a1` to `$s2` in the
  branch delay slot, choosing `$a3` as the temporary register for `id * 4`.
- Candidate copies `$a1` to `$s2` before the branch and `$a0` to `$s3` in the
  delay slot, choosing `$a0` as the temporary register for `id * 4`.
- Semantics, struct layout, and control flow are 100% equivalent.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_elevation_mesh_vertex.py \
  tests/test_tactical_ai_combat_subsystem_elevation_mesh_vertex_matching.py
```

The focused test run comprises **9 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating early exits and
  consecutive vertex serialization with exact field offsets.
- Seven production source mutations independently compiled and verified
  rejected (count guard, entity null guard, corrupted id, corrupted x,
  corrupted y, omitted count increment, corrupted stride).
- One matching test compiling fresh with Ninja/MWCC and verifying >= 96.9%
  instruction byte match against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
