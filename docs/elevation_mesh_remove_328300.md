# Elevation mesh vertex remove at 0x328300

`func_00328300` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_elevation_mesh_remove.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **188/188 instruction bytes (100.00%)**
against the original ELF binary. It is a leaf function without stack frame
implementing unordered vertex removal via swap-with-last.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x328300, 0x3283BC)`, file `[0x2284E0, 0x22859C)`.
  The function spans 188 instruction bytes (0xBC), followed by 4 bytes of
  alignment-padding nops up to `0x3283C0`. Symbol size is `0xBC`.
- Leaf function: no stack frame allocation or register preservation.
  Operates entirely within temporary registers (`$v0`, `$v1`, `$a0`–`$a3`,
  `$t0`–`$t2`, `$at`, `$f0`, `$f1`).

## Observable behavior

1. If `self->m_count == 0`, return -1.
2. Read current vertex count for tag: `count = self->m_table_8[tag]`. If
   `count == 0`, return 0.
3. Access per-tag vertex buffer: `vertices = (MeshVertex *)self->m_table_0[tag]`.
4. Iterate `i` from 0 to `count - 1`:
   - If `vertices[i].m_id == id`:
     * If `i < count - 1`, copy the last vertex record `vertices[count - 1]`
       into slot `i` using two 32-bit floating-point registers (`lwc1`/`swc1`).
     * Decrement vertex count: `self->m_table_8[tag]--`.
     * Return index `i` of the removed item.
5. If loop completes without finding `id`, return -1.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_elevation_mesh_remove.py \
  tests/test_tactical_ai_combat_subsystem_elevation_mesh_remove_matching.py
```

The focused test run comprises **9 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating early exits (-1 and 0),
  not-found condition (-1), single-element removal without swap, and
  middle-element removal with last-element swap.
- Seven production source mutations independently compiled and verified
  rejected (count guard, tag count guard, omitted swap, omitted decrement,
  inverted ID comparison, wrong return value, wrong not-found code).
- One matching test compiling fresh with Ninja/MWCC and verifying 100.00%
  byte-for-byte identity against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
