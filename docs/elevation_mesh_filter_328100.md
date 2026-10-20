# Elevation mesh query filter at 0x328100

`func_00328100` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_elevation_mesh_filter.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **292/292 instruction bytes (100.00%)**
after resolving two `R_MIPS_26` call relocations (`func_208480` and `func_328230`).
This is an isolated function result, not a claim that the surrounding subsystem
or full linked executable matches. The descriptive file and structure names are
provisional; original class and member names remain unconfirmed.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x328100, 0x328224)`, file `[0x2282E0, 0x228404)`.
  The mapping is verified through the ELF `PT_LOAD` segment. The function
  spans 292 instruction bytes, followed by 12 alignment-padding nop bytes up
  to `0x328230`. Symbol size in `symbols.txt` is `0x124` (292 bytes).
- Stack frame: 112 bytes (`addiu $sp, $sp, -0x70`), saving `$ra` (0x50),
  `$s4` (0x40), `$s3` (0x30), `$s2` (0x20), `$s1` (0x10), and `$s0` (0x00).
- Local variables: `CellCoord *coords` at `0x68($sp)` and `int count` at
  `0x6C($sp)`. Their addresses are passed to `func_208480`.

## Observable behavior

1. Invoke `func_208480(region, &coords, &count)` to extract coordinate list
   and count.
2. Guard clauses: if `count <= 0`, return immediately. If `self->m_count == 0`,
   return immediately.
3. Traverse grid ownership: `self->m_world` (offset `0x0C`) -> `m_game_mgr`
   (offset `0xB98`) -> `m_map_zone` (offset `0x3C`) -> `m_cell_rows`
   (offset `0x8E8C`, resolved via signed offset `-0x7174` with `lui $at, 1`).
4. Outer loop iterates over each coordinate `(x, y)`:
   - Index cell row: `row = cell_rows[coords->y]`.
   - Index cell: `cell = &row[coords->x]` with cell stride 28 bytes (`0x1C`).
   - Inner loop iterates over `j < cell->m_entity_count` (unsigned byte at `0x0D`):
     * Fetch `entity = cell->m_entities[j]` (pointer array at `0x14`).
     * If `entity` is null, advance `j` and continue.
     * Fetch `desc = entity->m_desc` (offset `0x04`).
     * If `desc->m_active != 0` (unsigned byte at `0x03`), invoke
       `func_328230(self, entity->m_id, desc->m_tag)`, where `m_id` is a signed
       16-bit integer at `0x24` and `m_tag` is an unsigned 8-bit integer at `0x91`.

Declaring `ZoneCell *cell;` before `ZoneCell **cell_rows;` reproduces the
original compiler register allocation (`$s0 = cell`, `$s1 = cell_rows`,
`$s2 = i`, `$s3 = j`, `$s4 = self`) without assembly or manual register hints.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_elevation_mesh_filter.py \
  tests/test_tactical_ai_combat_subsystem_elevation_mesh_filter_matching.py
```

The focused test run comprises **9 passing tests, zero skips**:

- One 32-bit native contract process with UBSan checking early return on zero
  or negative coordinate count, early return on zero descriptor count, null
  entity safety, active entity filtering, and exact callback parameters.
- Seven production source mutations independently compiled and verified
  rejected (zero coord count guard, zero self count guard, inverted active
  check, omitted null check, corrupted entity ID, corrupted tag, frozen coord
  advancement).
- One exact matching test compiling fresh with Ninja/MWCC and checking all 292
  relocated instruction bytes against the pinned ELF binary.

## Wider validation and limits

In the full Docker pytest suite, the run completed with **429 passed, 939
skipped, zero failures**, including all 18 focused tests for `func_00328020` and
`func_00328100`. Of the 939 skipped cases across the broader repository, 894
explicitly require the external `build/mips_binutils/mips-linux-gnu-ld`, and 45
report private-original/tool prerequisites. Flake8 passes for `configure.py`
and both filter Python test files. File-size, Python function-length,
documentation-link, and focused-symbol checks also pass.

The WIP/BIN boundary and registered object list remain unchanged.
