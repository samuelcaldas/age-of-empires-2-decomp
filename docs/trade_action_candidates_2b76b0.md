# `trade_action_candidates` (`func_002B76B0`, `func_002B7BB0`)

## Overview

- **Symbols**:
  - `func_002B76B0` (VRAM `0x2B76B0`–`0x2B7BB0`, File `0x1B7890`–`0x1B7D90`, 1,276 B code, 4 B padding, 1,280 B slice)
  - `func_002B7BB0` (VRAM `0x2B7BB0`–`0x2B8560`, File `0x1B7D90`–`0x1B8740`, 2,468 B code, 12 B padding, 2,480 B slice)
- **Source Files**:
  - `include/trade_action_candidates.h`
  - `include/trade_action_candidates_access.h`
  - `include/trade_action_candidates_dual.h`
  - `src/trade_action_candidates.cpp`
- **Status**: NonMatching (Pure C++, zero asm, Object Calisthenics compliant)

## Signatures

```cpp
int func_002B76B0(void *self, int a1, int a2, int a3, int t0);
int func_002B7BB0(void *self, int a1, int a2, int a3);
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
