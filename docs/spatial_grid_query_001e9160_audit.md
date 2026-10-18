# Audit and Decompilation Analysis: Spatial Grid Query Engine (func_001E9160)

## Overview
- **Function Symbol**: `func_001E9160` (`zone_spatial_grid_execute_hierarchical_query`)
- **Binary Territory**: PlayStation 2 PAL `SLES-50282` (`AOK.ELF`)
- **VRAM Range**: `0x1E9160`–`0x1EA7F0` (5,760 bytes code + 16 bytes pad = 5,776 bytes slice)
- **File Offset**: `0xE9330`–`0xEA9C0`
- **Compiler**: Metrowerks C++ for PlayStation 2 (MWCC PS2 2.3.1.01)

## Audit Status & Defect Analysis
The initial implementation slice of `func_001E9160` in Block 33 used a reduced entry stub that checked bounds and returned early, omitting the full hierarchical query traversal, raycasting, and pathfinding calls. An independent audit performed against the disassembly revealed:
1. **Total Instructions**: 1,440 R5900 instructions.
2. **Branches**: 171 branch instructions.
3. **Stores**: 148 store instructions altering grid bounding extents, stack structures, and auxiliary tables.
4. **Function Calls**: 69 calls across 32 unique helper routines.

## Complete Control Flow & Architecture

### Phase 1: Boundary Initialization & Guard Clauses (0x1E9160 - 0x1E9258)
- Stack allocation of `0x280` bytes.
- When `t0 == 0`, clears bounding box indices at offsets `0xA4`, `0xA8`, `0xAC`, `0xB0` to `-1`.
- When `a3 == 0` (validation flag zero), returns status code `4` immediately (`0x1E920C`).
- Calls `func_1E7020(self, f14)` to set margin bounds.
- Validates source and target coordinates via `func_1E7070(self, x, y)`. If either point lies outside map margin bounds, returns `4` (`0x1E9238`, `0x1E9258`).

### Phase 2: Target Entity Lookup & Range Early Exit (0x1E925C - 0x1E92F4)
- When target entity ID (`a1`, at `0x20C($sp)`) is non-negative, retrieves entity pointer via `func_332E60(entity_mgr, id)`.
- If target entity is found, retrieves its position via `func_269220(target, &x, &y, 0.0f)`.
- Evaluates squared euclidean distance: `dx^2 + dy^2 <= (range + radius)^2`. If target is already within range, exits early returning `0`.

### Phase 3: Spatial Buffer Preparation & Raycast Shortcut (0x1E92F8 - 0x1E93E4)
- Expands tertiary embedded vector buffer via `func_1E6FC0(self, 0x100)`.
- Configures world collision radius via `func_1EE8F0(self->world, ...)` and `func_1EE070(self->world)`.
- Synchronizes entity obstacle masks via `func_1EE850(self->world, self->flag_88, self->array_94, self->count_8C)`.
- **Mode 1 Direct Raycast**: If `mode == 1`, executes direct ray traversal via `func_1E8CD0`. If direct line of sight is unobstructed, returns `1` immediately.

### Phase 4: Bounding Box Calculation & Threshold Area Branching (0x1E93E8 - 0x1E9500)
- Computes tile bounding rectangle:
  - `min_x = floorf(min(x0, x1)) - 2`
  - `max_x = floorf(max(x0, x1)) + 2`
  - `min_y = floorf(min(y0, y1)) - 2`
  - `max_y = floorf(max(y0, y1)) + 2`
- Clamps bounding rectangle to map grid dimensions `[0, map_width - 1]`, `[0, map_height - 1]`.
- Computes tile area: `area = (max_x - min_x + 1) * (max_y - min_y + 1)`.
- **Area Branching Decision**:
  - `area < 101`: Executes direct grid cell query across bounding tiles.
  - `area >= 101`: Executes hierarchical quadtree spatial pyramid search across levels 0–3, allocating path nodes via `func_1E82D0` (invoked up to 9 times).

### Phase 5: Pathfinding & Waypoint Smoothing (0x1E9500 - 0x1EA7E0)
- Executes core pathfinding search targeting `func_1EA7E0` (3 calls).
- If path is found, post-processes and prunes redundant waypoints via `func_1EB210` (`zone_spatial_grid_smooth_path_waypoints`).
- Restores stack frame and registers at `0x1EA7CC`–`0x1EA7DC` and executes epilogue `jr $ra; addiu $sp, $sp, 0x280`.
