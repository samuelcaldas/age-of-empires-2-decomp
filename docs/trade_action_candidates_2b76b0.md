# func_002B76B0 (`trade_action_candidates`)

## Overview

- **Symbol**: `func_002B76B0`
- **File Offset**: `0x1B7890`–`0x1B7D90` (Size: 0x500 bytes = 1,280 bytes; Code: 0x4FC = 1,276 bytes; Padding: 4 bytes zero at `0x2B7BAC`–`0x2B7BB0`)
- **VRAM**: `0x2B76B0`–`0x2B7BB0`
- **Source**: `src/trade_action_candidates.cpp`
- **Status**: NonMatching (Pure C++, 0 asm, Object Calisthenics compliant)

## Signature

```cpp
int func_002B76B0(void *self, int a1, int a2, int a3, int t0);
```

## Behavior and Architecture

- **`a3 == 1` Initialization**: If `a3 == 1`, resets the matched candidate count at `self + 3172` to 0.
- **Candidate Scan Loop**: Iterates through `s1` from 0 to `integer_at(self, 216)` (bounded items list).
- **Index Guard**: Accesses `pointer_at(self, 212)` with bounded index `(s1 < integer_at(self, 224) - 1) ? s1 : 0`.
- **Entity Lookup**: Calls `func_00332e60(pointer_at(pointer_at(pointer_at(self, 176), 0x1f348), 2968), item_id)`.
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
- **Return**: Returns total matching candidate count.
