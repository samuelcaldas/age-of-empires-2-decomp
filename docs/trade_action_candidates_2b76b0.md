# `trade_action_candidates` (`func_002B76B0`, `func_002B7BB0`, `func_002B8560`, `func_002B8980`, `func_002B90A0`)

## Verification warning

The current reconstruction is incomplete. Native fixture results do not establish
original-game semantics or target binary matching. Signature order, callback
pointer dereferences and repeated calls, bounded-list edges, selector passes,
and symbol boundaries require verification against the original binary.
Descriptions below are provisional, not a verified behavioral specification.

The unfinished source split places selector and type-checker definitions in
`src/trade_action_candidates_extra.cpp`, which is fully registered in `configure.py`.
The new `func_002B9140` implementation and notify source remain experimental;
their behavior and return contracts are not verified. Do not mark them matched
or semantically complete.

The native compilation repair shares the existing exclusion helper through
`include/trade_action_candidates_exclusion.h`, adds missing callback declarations,
and exposes the experimental function declaration to fixtures. The rate mutation
checks the actual state assertion at offset `3240`; it does not expect return `25`.

## Overview

- **Symbols**:
  - `func_002B76B0` (VRAM `0x2B76B0`–`0x2B7BB0`, File `0x1B7890`–`0x1B7D90`, 1,276 B code, 4 B padding, 1,280 B slice)
  - `func_002B7BB0` (VRAM `0x2B7BB0`–`0x2B8560`, File `0x1B7D90`–`0x1B8740`, 2,468 B code, 12 B padding, 2,480 B slice)
  - `func_002B8560` (VRAM `0x2B8560`–`0x2B8978`, File `0x1B8740`–`0x1B8B60`, 1,044 B code, 4 B padding, 1,048 B slice)
  - `func_002B8980` (VRAM `0x2B8980`–`0x2B8E2C`, File `0x1B8B60`–`0x1B9020`, 1,196 B code, 4 B padding, 1,200 B slice)
  - `func_002B90A0` (VRAM `0x2B90A0`–`0x2B9134`, File `0x1B9280`–`0x1B9340`, 148 B code, 44 B padding, 192 B slice)
- **Source Files**:
  - `include/trade_action_candidates.h`
  - `include/trade_action_candidates_access.h`
  - `include/trade_action_candidates_dual.h`
  - `include/trade_action_candidates_selector.h`
  - `include/trade_action_candidates_distance.h`
  - `include/trade_action_candidates_exclusion.h`
  - `include/trade_action_candidates_extra.h`
  - `src/trade_action_candidates.cpp`
  - `src/trade_action_candidates_extra.cpp`
  - `include/trade_action_notify.h`
  - `src/trade_action_notify.cpp`
- **Status**: Implemented in pure C++ and verified with 37 native tests (25 core candidate behavior cases, 2 experimental func_002B9140 / plan cases, 1 trade notification suite, and 9 source mutation checks).

## Signatures

```cpp
int func_002B76B0(void *self, int a1, int a2, int a3, int t0);
int func_002B7BB0(void *self, int a1, int a2, int a3);
int func_002B8560(void *self, int mode);
int func_002B8980(void *self, int *coords, int mode, int flag);
int func_002B90A0(void *self, int target_type, int item_id);
```

## Behavior and Architecture

### 1. `func_002B76B0` (Single List Candidate Evaluator)
- **`a3 == 1` Initialization**: Resets matched count at `self + 3172` to 0 when flag `a3 == 1`.
- **Candidate Scan Loop**: Iterates through `s1` from 0 to `integer_at(self, 216)` (bounded items list).
- **Index Guard**: Accesses array `pointer_at(self, 212)` with bounded index `(s1 < integer_at(self, 224) - 1) ? s1 : 0`.
- **Entity Lookup**: Calls `func_00332e60(manager_entity_root(self), item_id)`.
- **Predicate Validation**: Invokes virtual predicate at vtable offset 356 (`vtable[89]`). Rejects if null/false.
- **Exclusion List**: Checks if candidate ID is present in exclusion list at `self + 3184` (count at 3188, cap at 3196). Rejects if found.
- **Special Entity Classification**:
  - Calls `func_001471a0(pred_result)`. If returns -1, marks special flag `s3 = 1`.
  - If `t0 != 0` and `func_001471a0` returns 600:
    - Resolves linked entity via `func_001471c0` and looks up in `manager_group_root`.
    - If linked entity is null or entity type at `field4 + 14` is 27, marks special flag `s3 = 1`.
- **Score Threshold Matching**:
  - If `s3 == 0`, evaluates `func_00147190(pred_result)` against threshold `a1`:
    - `a2 < 0`: matches if `score < a1`.
    - `a2 > 0`: matches if `score > a1`.
    - `a2 == 0`: matches if `score == a1`.
- **Candidate Buffer Storage**:
  - If matched, appends candidate ID to buffer at `self + 3168` (count at 3172, capacity at 3180) if not already present.
  - Increments return match counter `s0`.

### 2. `func_002B7BB0` (Dual List Candidate Evaluator)
- **Initialization**: Resets count at `self + 3172` to 0 unconditionally.
- **Phase 1 (Secondary Items List)**:
  - If `a3 == 1`, iterates through secondary items list at `pointer_at(self, 260)` (count at `self + 264`, capacity at `self + 272`).
  - Evaluates each candidate against threshold `a1` with mode `a2` and flag `t0 = 0`.
  - Appends valid candidate IDs to buffer at `self + 3168`.
- **Phase 2 (Primary Items List)**:
  - Iterates through primary items list at `pointer_at(self, 212)` (count at `self + 216`, capacity at `self + 224`).
  - Evaluates each candidate against threshold `a1` with mode `a2` and flag `t0 = 0`.
  - Appends valid candidate IDs to buffer at `self + 3168`.
- **Return Value**: Total number of matching candidate insertions across both phases.

### 3. `func_002B8560` (Candidate Pool Selector)
- **Scan Loop**: Iterates through item pool array at `pointer_at(self, 180)` bounded by count at `self + 184`.
- **Entity Validation**: Resolves each item through `func_00332e60(manager_entity_root(self), item_id)` and verifies virtual predicate `vtable[356/4]`.
- **Mode Predicate Filter**:
  - For `mode == 0` or `mode == 3`: requires `func_002bf050(self, item_id) == 0`.
  - For `mode == 0` or `mode == 1`: requires item not present in exclusion list at `self + 196` (count at 200, capacity at 208).
- **Sub-ID Selection**:
  - Evaluates `(func_002bfcd0(self, short_at(item, 36)) & 0xFF) == 1`.
  - If matched, immediately returns `short_at(item, 36)`.
- **Return Value**: Returns matched candidate's sub-ID (or -1 if no candidate qualifies).

### 4. `func_002B8980` (Distance-based Candidate Pool Selector)
- **Scan Loop**: Iterates through pool array at `pointer_at(self, 180)` bounded by count at `self + 184`.
- **Entity & Predicate Validation**: Resolves each item through `func_00332e60(manager_entity_root(self), item_id)` and checks virtual predicate `vtable[356/4]`.
- **Mode Predicate Filter**: Same mode checks as `func_002B8560` via `func_002bf050` and pool exclusion.
- **Distance Metric & Best Candidate Tracking**:
  - Checks `(func_002bfcd0(self, short_at(item, 36)) & 0xFF) == 1`.
  - Calls `func_00269190(coords[0], coords[1], item)`.
  - Tracks candidate with highest score (`dist <= best` for mode 1; `dist < best` for mode 0).
- **Return Value**: Sub-ID of optimal candidate, or -1 if none qualify.

### 5. `func_002B90A0` (Entity Type Matcher)
- Resolves entity `item` via `func_00332e60(manager_entity_root(self), item_id)`.
- Rejects if `!item` or `!pred(item)`.
- Returns 1 if `func_001471a0(pred(item)) == target_type`, else 0.

## Trade notification routines (`0x2B9770`–`0x2B9B30`)

- **Slice**: File `0x1B9950`–`0x1B9D10`, VRAM `0x2B9770`–`0x2B9B30` (960 B code and padding).
- **Status**: **NonMatching / Experimental**.

Disassembly of the original binary ELF (`AOK.ELF`) confirms the following structure:

- `func_002B9770` (0x5C B): resolves manager `+176`, group `+172`, and player ba0 `+2976`. Dispatches action manager order notification through vtable offset 56 (`+6960`) with action code 706 and float parameters `-1.0f`. Returns 1.
- `func_002B97D0` (0x58 B): dispatches order notification through vtable offset 56 with action code 710, passing third float parameter `1.0f` and fourth float parameter `param`. Returns 1.
- `func_002B9830` (0x4C B): dispatches order notification through vtable offset 56 with action code 724. Returns 1.
- `func_002B9880` (0x2A4 B, 676 B code):
  - Inlined candidate exclusion pool loop (`self + 3184`, count at `+3188`, capacity at `+3196`).
  - Resolves entity root through `self + 176 -> +172 -> +2968` and looks up entity via `func_00332e60`.
  - Virtual predicate check at `vtable[356/4]`.
  - Class acceptance check: calls `func_001471a0` against `{600, 613, 602, 618, 605}`. Returns 1 on match.
  - Health rejection check: `*(float*)(item + 64) > 0.0f` rejects (returns 0).
  - Qualification filters: `func_00147170 == 710` with status 100 rejects; `func_00147170 == 702` rejects; `func_0014c430 == 1` rejects.
  - Final dispatch: tail-calls `func_002bb100(self, item_id, action_type)` and normalizes return via `movn`.

MWCC PS2 compilation yields an 80-byte stack frame (`addiu sp, sp, -80`) with identical saved registers (`ra`, `s3`, `s2`, `s1`, `s0`). The subsystem remains strictly **NonMatching** until 100% bit-for-bit instruction parity and relocation equivalence are achieved.
