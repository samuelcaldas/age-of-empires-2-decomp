# ActionBuild & CombatManager Subsystem (Milestones 104–135)

The ActionBuild and CombatManager subsystem spans VRAM `[0x2777A0, 0x27B700)` (file offset `[0x177980, 0x17B8E0)` in PS2 PAL `SLES-50282`).
It consists of **43 contiguous functions** totaling **16,224 bytes** implemented in 100% pure C++ across 32 compilation units with zero assembly.

## Reference Boundaries & Layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1 `f478e19f2059d52899b691483ef5c7522e30e17c`.
- VRAM Range: `0x2777A0`–`0x27B700` (16,224 bytes, 4,056 R5900 instructions).
- File Range: `0x177980`–`0x17B8E0`.
- All 43 functions form a strictly contiguous block with zero byte gaps when mapped to true MIPS function entry points (`addiu $sp, $sp, -imm`).

### True Function Entry Points & Size Table

| VRAM Start | VRAM End | Size (Bytes) | ELF Calls | Primary Symbol | Milestone File |
|---|---|---|---|---|---|
| `0x2777A0` | `0x277D50` | 1,456 | 12 | `func_2777A0` | `unit_action_build_77a0` |
| `0x277D50` | `0x277E50` | 256 | 3 | `func_00277D50` | `unit_action_build_77d50` |
| `0x277E50` | `0x277F50` | 256 | 3 | `func_00277E50` | `unit_action_build_77e50` |
| `0x277F50` | `0x277FC0` | 112 | 1 | `func_00277F50` | `unit_action_build_77f50` |
| `0x277FC0` | `0x278270` | 688 | 12 | `func_00277FC0` | `unit_action_build_77fc0` |
| `0x278270` | `0x2784D0` | 608 | 13 | `func_00278270` | `unit_action_build_78270` |
| `0x2784D0` | `0x278530` | 96 | 0 | `func_002784D0` | `unit_action_build_784d0` |
| `0x278530` | `0x278590` | 96 | 0 | `func_00278530` | `unit_action_build_784d0` |
| `0x278590` | `0x278650` | 192 | 4 | `func_278590` | `unit_action_build_78590` |
| `0x278650` | `0x2786F0` | 160 | 0 | `func_00278650` | `unit_action_build_78660` |
| `0x2786F0` | `0x278870` | 384 | 0 | `func_002786F0` | `unit_action_build_78700` |
| `0x278870` | `0x278900` | 144 | 1 | `func_00278870` | `unit_action_build_78870` |
| `0x278900` | `0x278990` | 144 | 1 | `func_00278900` | `unit_action_build_78870` |
| `0x278990` | `0x278D50` | 960 | 6 | `func_00278990` | `unit_action_build_789a0` |
| `0x278D50` | `0x278E20` | 208 | 7 | `func_278D50` | `unit_action_build_78d60` |
| `0x278E20` | `0x278EE0` | 192 | 7 | `func_278E20` | `unit_action_build_78d60` |
| `0x278EE0` | `0x278FA0` | 192 | 3 | `func_00278EE0` | `unit_action_build_78ef0` |
| `0x278FA0` | `0x279060` | 192 | 3 | `func_00278FA0` | `unit_action_build_78ef0` |
| `0x279060` | `0x2790F0` | 144 | 4 | `func_00279060` | `unit_action_build_79080` |
| `0x2790F0` | `0x279430` | 832 | 19 | `func_002790F0` | `unit_action_build_79110` |
| `0x279430` | `0x2794A0` | 112 | 2 | `func_00279430` | `unit_action_build_79440` |
| `0x2794A0` | `0x2795D0` | 304 | 6 | `func_002794A0` | `unit_action_build_79440` |
| `0x2795D0` | `0x279650` | 128 | 4 | `func_002795D0` | `unit_action_build_795e0` |
| `0x279650` | `0x279670` | 32 | 0 | `func_00279650` | `unit_action_build_795e0` |
| `0x279670` | `0x2796A0` | 48 | 0 | `func_00279670` | `unit_action_build_795e0` |
| `0x2796A0` | `0x2796E0` | 64 | 1 | `func_002796A0` | `unit_action_build_795e0` |
| `0x2796E0` | `0x279740` | 96 | 1 | `func_002796E0` | `unit_action_build_79700` |
| `0x279740` | `0x279910` | 464 | 16 | `func_00279740` | `unit_action_build_79700` |
| `0x279910` | `0x279B80` | 624 | 13 | `func_00279910` | `unit_action_build_79930` |
| `0x279B80` | `0x279C80` | 256 | 7 | `func_00279B80` | `unit_action_build_79ba0` |
| `0x279C80` | `0x279D60` | 224 | 5 | `func_00279C80` | `unit_action_build_79ca0` |
| `0x279D60` | `0x279F70` | 528 | 12 | `func_00279D60` | `unit_action_build_79d80` |
| `0x279F70` | `0x27A070` | 256 | 5 | `func_00279F70` | `unit_action_build_79f90` |
| `0x27A070` | `0x27A1B0` | 320 | 5 | `func_0027A070` | `unit_action_build_7a090` |
| `0x27A1B0` | `0x27A370` | 448 | 10 | `func_0027A1B0` | `unit_action_build_7a1d0` |
| `0x27A370` | `0x27A400` | 144 | 3 | `func_0027A370` | `unit_action_build_7a390` |
| `0x27A400` | `0x27A810` | 1,040 | 42 | `func_0027A400` | `unit_action_build_7a440` |
| `0x27A810` | `0x27AC90` | 1,152 | 44 | `func_0027A810` | `unit_action_build_7a830` |
| `0x27AC90` | `0x27B4B0` | 2,080 | 59 | `func_0027AC90` | `unit_action_build_7acb0` |
| `0x27B4B0` | `0x27B620` | 368 | 3 | `func_0027B4B0` | `unit_action_build_7b4d0` |
| `0x27B620` | `0x27B630` | 16 | 0 | `func_0027B620` | `unit_action_build_7b640` |
| `0x27B630` | `0x27B6B0` | 128 | 0 | `func_0027B630` | `unit_action_build_7b640` |
| `0x27B6B0` | `0x27B700` | 80 | 0 | `func_0027B6B0` | `unit_action_build_7b640` |

## Subsystems Covered

1. **Area of Effect Damage & Construction Repair (`0x2777A0`–`0x2784D0`):**
   - Tile grid traversal and damage falloff computation (`func_2777A0`).
   - Time-based and HP-based repair deduction (`func_00277D50`, `func_00277E50`).
   - Stance mode to action type conversions.
2. **Worker Actions, Formations & Garrisons (`0x2784D0`–`0x279D60`):**
   - Allied foundation validation and garrison threat recomputation.
   - Farm exhaustion, villager auto-drop search, and siege command dispatch.
3. **CombatManager Lifecycle & Serialization (`0x27A1B0`–`0x27B700`):**
   - CombatManager constructor, property setup, and destructor.
   - Stream deserialization (`0x27A400`, 1,040B) and serialization (`0x27A810`, 1,152B).
   - Periodic tactical zone evaluation and 8-sector threat analysis (`0x27AC90`, 2,080B).
   - Event buffer compaction (`0x27B4B0`, 368B).
   - Event count getter (`0x27B620`), coordinate query with flag guard (`0x27B630`), and 36-slot pool zero-marker allocator (`0x27B6B0`).

## Verification

All 32 compilation units build without assembly and execute cleanly under both 32-bit (`g++ -m32`) and 64-bit host environments.
The full test suite can be run via pytest:
```sh
.venv/bin/pytest tests/test_unit_action_build_7*.py
```
And verified with ninja dry-run:
```sh
ninja -n
```
