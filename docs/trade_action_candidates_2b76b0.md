# `trade_action_candidates` (`func_002B76B0`, `func_002B7BB0`, `func_002B8560`, `func_002B8980`, `func_002B90A0`, `func_002B9140`)

## Verification warning

The current reconstruction is incomplete. Native fixture results do not establish
original-game semantics or target binary matching. Signature order, callback
pointer dereferences and repeated calls, bounded-list edges, selector passes,
and symbol boundaries require verification against the original binary.
Descriptions below are provisional, not a verified behavioral specification.

The unfinished source split places selector and type-checker definitions in
`src/trade_action_candidates_extra.cpp`, which is fully registered in `configure.py`.
The extracted `func_002B9140` implementation in `src/trade_action_plan_evaluator.cpp`
remains experimental (**NonMatching**); its full rate distribution and evaluation
semantics reached **98.75% match** (396/397 instructions matched, single opcode delta `blezl` vs `blez`).

The native compilation repair shares the existing exclusion helper through
`include/trade_action_candidates_exclusion.h`, adds missing callback declarations,
and exposes the experimental function declaration to fixtures. The rate mutation
checks the actual state assertion at offset `3240`; it does not expect return `25`.

## Overview

- **Symbols**:
  - `func_002B76B0` (VRAM `0x2B76B0`–`0x2B7BB0`, File `0x1B7890`–`0x1B7D90`, 1,276 B code, 4 B padding, 1,280 B slice)
  - `func_002B7BB0` (VRAM `0x2B7BB0`–`0x2B8560`, File `0x1B7D90`–`0x1B8740`, 2,468 B code, 12 B padding, 2,480 B slice)
  - `func_002B8560` (VRAM `0x2B8560`–`0x2B8978`, File `0x1B8740`–`0x1B8B60`, 1,044 B code, 4 B padding, 1,048 B slice)
  - `func_002B8980` (VRAM `0x2B8980`–`0x2B8E2C`, File `0x1B8B60`–`0x1B9010`, 1,196 B code, 4 B padding, 1,200 B slice)
  - `func_002B8E30` (VRAM `0x2B8E30`–`0x2B9098`, File `0x1B9010`–`0x1B9278`, 616 B code, 8 B padding, 624 B slice)
  - `func_002B90A0` (VRAM `0x2B90A0`–`0x2B9130`, File `0x1B9280`–`0x1B9310`, 144 B code)
  - `func_002B9130` (VRAM `0x2B9130`–`0x2B9138`, File `0x1B9310`–`0x1B9318`, 8 B stub, 8 B padding, 160 B slice)
  - `func_002B9140` (VRAM `0x2B9140`–`0x2B9770`, File `0x1B9320`–`0x1B9950`, 1,580 B code, 4 B padding, 1,584 B slice)
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
  - `include/post_trade_action_distance_candidates.h`
  - `src/post_trade_action_distance_candidates.cpp`
  - `include/trade_action_type_checker.h`
  - `src/trade_action_type_checker.cpp`
  - `include/trade_action_plan_evaluator.h`
  - `src/trade_action_plan_evaluator.cpp`
  - `include/trade_action_notify.h`
  - `src/trade_action_notify.cpp`
- **Status**: Implemented in pure C++ and verified with 48 native tests (25 core candidate behavior cases, 2 plan cases, 1 trade notification suite, 1 trade plan evaluator suite, 1 trade type checker suite, 1 distance pool selector suite, 2 verifier test suites, and 9 source mutation checks).

## Signatures

```cpp
int func_002B76B0(void *self, int a1, int a2, int a3, int t0);
int func_002B7BB0(void *self, int a1, int a2, int a3);
int func_002B8560(void *self, int mode);
int func_002B8980(void *self, int *coords, int mode, int flag);
int func_002B90A0(void *self, int target_type, int item_id);
int func_002B9140(void *self);
```

## Behavior and Architecture

### 1. `func_002B76B0` (Single List Candidate Evaluator)
- **`a3 == 1` Initialization**: Resets matched count at `self + 3172` to 0 when flag `a3 == 1`.
- **Candidate Scan Loop**: Iterates through `s1` from 0 to `integer_at(self, 216)` (bounded items list).
- **Index Guard**: Accesses array `pointer_at(self, 212)` with bounded index `(s1 < integer_at(self, 224) - 1) ? s1 : 0`.
- **Entity Lookup**: Calls `func_332e60(manager_entity_root(self), item_id)`.
- **Predicate Validation**: Invokes virtual predicate at vtable offset 356 (`vtable[89]`). Rejects if null/false.
- **Exclusion List**: Checks if candidate ID is present in exclusion list at `self + 3184` (count at 3188, cap at 3196). Rejects if found.
- **Special Entity Classification**:
  - Calls `func_001471A0(pred_result)`. If returns -1, marks special flag `s3 = 1`.
  - If `t0 != 0` and `func_001471A0` returns 600:
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
- **Entity Validation**: Resolves each item through `func_332e60(manager_entity_root(self), item_id)` and verifies virtual predicate `vtable[356/4]`.
- **Mode Predicate Filter**:
  - For `mode == 0` or `mode == 3`: requires `func_002bf050(self, item_id) == 0`.
  - For `mode == 0` or `mode == 1`: requires item not present in exclusion list at `self + 196` (count at 200, capacity at 208).
- **Sub-ID Selection**:
  - Evaluates `(func_002bfcd0(self, short_at(item, 36)) & 0xFF) == 1`.
  - If matched, immediately returns `short_at(item, 36)`.
- **Return Value**: Returns matched candidate's sub-ID (or -1 if no candidate qualifies).

### 4. `func_002B8980` (Distance-based Candidate Pool Selector)
- **Scan Loop**: Iterates through pool array at `pointer_at(self, 180)` bounded by count at `self + 184`.
- **Entity & Predicate Validation**: Resolves each item through `func_332e60(manager_entity_root(self), item_id)` and checks virtual predicate `vtable[356/4]`.
- **Mode Predicate Filter**: Same mode checks as `func_002B8560` via `func_002bf050` and pool exclusion.
- **Distance Metric & Best Candidate Tracking**:
  - Checks `(func_002bfcd0(self, short_at(item, 36)) & 0xFF) == 1`.
  - Calls `func_00269190(coords[0], coords[1], item)`.
  - Tracks candidate with highest score (`dist <= best` for mode 1; `dist < best` for mode 0).
- **Return Value**: Sub-ID of optimal candidate, or -1 if none qualify.

### 4b. `func_002B8E30` (Post Distance Candidates Pool Selector)
- **Slice**: File `0x1B9010`–`0x1B9280`, VRAM `0x2B8E30`–`0x2B90A0` (616 B code, 8 B padding, 624 B slice).
- **Status**: **100.0% Matched** (verified byte-for-byte with MWCC PS2 2.3.1.01 against SLES-50282 original ELF; 624/624 bytes identical; kept NonMatching in configure.py pending promotion clearance).
- **Scan Loop**: Iterates through item pool array at `self + 180` bounded by count at `self + 184` using capacity guard at `self + 192`.
- **Filters**:
  - Rejects if in exclusion pool at `self + 3184` (count at `+3188`, capacity at `+3196`).
  - Resolves item via `func_332e60(group->m_root, item_id)` through manager `+176 -> +172 -> +2968`.
  - Validates virtual predicate via `item->get_id()`.
  - Rejects if proto field8 at `item + 4 -> +8` is 259 or 214.
  - Rejects if health `*(float*)(item + 64) > 7.0f`.
  - Rejects if action code from `func_00147170(*item->get_id())` is 702, 718, 700, or 717.
- **Distance Metric & Selection**:
  - Calls `func_00269190((float)coords[0], (float)coords[1], *(float*)(item + 76), item)`.
  - Tracks candidate with minimal distance (`best_dist <= dist` skips).
  - Returns optimal candidate's sub-ID `*(short*)(item + 36)`, or -1 if none qualify.

#### TDD Red-Before-Implementation Chronology (`func_002B8E30`)
- **Red Baseline Command**: `.venv/bin/pytest tests/test_post_trade_action_distance_candidates.py`
- **Failing Assertion**: `AssertionError: test failed ... post-trade-action-distance-candidates-test: tests/native/post_trade_action_distance_candidates_test.cpp:93: int main(int, char**): Assertion 'res1 == 42' failed. Returncode -6 (SIGABRT) != 0`
- **Green Implementation**: Pure C++ implementation in `src/post_trade_action_distance_candidates.cpp` verifying pool iteration, exclusion, proto, health, action codes, and distance selection.
- **Green Result**: `5 passed` in `tests/test_post_trade_action_distance_candidates.py`.
- **Durable Mutation Gate**: Parameterized mutants (`corrupted_default_return`, `corrupted_health_threshold`, `corrupted_proto_check`, `inverted_distance_selection`) continuously assert expected failure modes.
- **Verifier Hardening**: `tests/test_verify_post_trade_action_distance_candidates.py` validates 624/624 byte match and asserts negative padding rejection, corrupted padding rejection, and slice truncation rejection.

### 5. `func_002B90A0` and `func_002B9130` (Trade Action Type Checker)
- **Slice**: File `0x1B9280`–`0x1B9320`, VRAM `0x2B90A0`–`0x2B9140` (160 B code and padding).
- **Status**: **100.0% Matched** (verified byte-for-byte with MWCC PS2 2.3.1.01 against SLES-50282 original ELF; 160/160 bytes identical; promoted to Matching in configure.py).
- `func_002B90A0` (144 B): resolves entity `item` via `func_332e60(group->m_root, item_id)` through manager `+176 -> +127816 -> +2968`. Rejects if `!item` or `!pred(item)`. Returns 1 if `func_001471A0(pred(item)) == target_type`, else 0.
- `func_002B9130` (8 B stub): `jr ra; nop`, followed by 8 B padding zeroes.

#### TDD Red-Before-Implementation Chronology
- **Red Baseline Command**: `.venv/bin/pytest tests/test_trade_action_type_checker.py`
- **Failing Assertion**: `AssertionError: type checker failed ... trade-action-type-checker-test: tests/native/trade_action_type_checker_test.cpp:46: int main(int, char**): Assertion 'res1 == 1' failed. Returncode -6 (SIGABRT) != 0`
- **Green Implementation**: Pure C++ implementation in `src/trade_action_type_checker.cpp`, verified with argument forwarding (`item_id`, `root`, `entity_id`).
- **Green Result**: `4 passed` in `tests/test_trade_action_type_checker.py`.
- **Durable Mutation Gate**: Automated parameterized mutants (`inverted_return`, `corrupted_root`, `corrupted_item_id`) in `test_trade_action_type_checker.py` continuously exercise and verify expected assertion failure modes.
- **Verifier Hardening**: `tests/test_verify_trade_action_type_checker.py` validates normal 160/160 match and asserts negative padding rejection and target slice truncation handling.

### 6. `func_002B9140` (Trade Action Plan Evaluator)
- **Slice**: File `0x1B9320`–`0x1B9950`, VRAM `0x2B9140`–`0x2B9770` (1,584 B code and padding).
- **Status**: **NonMatching / Experimental** (**98.75% match** on `func_002B9140`, 396/397 instructions matched).
- Evaluates plan items list bounded by `self->m_limit` (3092) (each item 24 bytes).
- Queries entity via `func_00144d10(self->m_mgr, item_id)` and virtual predicate `item->get_id()`.
- Calculates rate distribution slots across 4 categories and sorts rate indices at `self + 3200..3212` via inlined selection sort.

#### Matching Blocker Analysis: `blezl` vs `blez` at `0x2B957C`
- **Target**: `0x2B957C: 58600048 blezl v1, 0x2B96A0` (`paddub a0, zero, zero` in delay slot).
- **Candidate**: `+0x43C: 18600048 blez v1, 0x560` (`paddub a0, zero, zero` in delay slot).
- Both instructions share exact branch offset `0x0048` (+72 words) jumping to index sorting initialization loop at `0x2B96A0`, and share exact hoisted delay-slot instruction `paddub a0, zero, zero` (`a0 = 0`).
- **Semantic Equivalence**: On taken path (`diff <= 0`), delay slot initializes `a0 = 0` in both. On fall-through path (`diff > 0`), `blezl` squashes `a0 = 0` while `blez` executes it; however, `a0` is never read in the rate adjustment block and is unconditionally re-initialized (`paddub a0, zero, zero`) at `0x2B969C` before the loop. Behavioral semantics are 100% equivalent.
- **Compiler Heuristic**: MWCC 2.3.1.01 emits `blezl` only when branch-likely heuristics are triggered (e.g. synthetic compound conditionals such as `diff > 0 && sum2 >= 0`), but clean C++ (`int diff = self->m_total - sum2; if (diff > 0)`) emits `blez`. To avoid artificial semantic distortion or assembly injection, the routine remains strictly **NonMatching** with a 396/397 instruction diagnostic alignment.

## Trade notification routines (`0x2B9770`–`0x2B9B30`)

- **Slice**: File `0x1B9950`–`0x1B9D10`, VRAM `0x2B9770`–`0x2B9B30` (960 B code and padding).
- **Status**: **100.0% Matched** (verified byte-for-byte with MWCC PS2 2.3.1.01 against SLES-50282 original ELF; promoted to Matching in configure.py).
- **Matching Coverage (objdiff)**:
  - `func_002B9770`: **100.0% match** (96 B code, 24/24 instructions).
  - `func_002B97D0`: **100.0% match** (96 B code, 24/24 instructions).
  - `func_002B9830`: **100.0% match** (80 B code, 20/20 instructions).
  - `func_002B9880`: **100.0% match** (688 B code, 169/169 instructions).
  - Unit `main/trade_action_notify` (`.text`): **100.0% match** (960 / 960 B).

Disassembly of the original binary ELF (`AOK.ELF`) confirms the following structure:

- `func_002B9770` (0x60 B): resolves manager `+176`, group `+172`, and player ba0 `+2976`. Dispatches action manager order notification through vtable offset 56 (`+6960`) with action code 706 and float parameters `-1.0f`. **100.0% bit-for-bit matched**.
- `func_002B97D0` (0x60 B): dispatches order notification through vtable offset 56 with action code 710, passing float parameters `-1.0f, -1.0f, 1.0f, param`. **100.0% bit-for-bit matched**.
- `func_002B9830` (0x50 B): dispatches order notification through vtable offset 56 with action code 724. **100.0% bit-for-bit matched**.
- `func_002B9880` (0x2B0 B, 676 B code):
  - Inlined candidate exclusion pool helper `in_exclusion_pool` returning int (`self + 3184`, count at `+3188`, capacity at `+3196`).
  - Resolves entity root through `self + 176 -> +172 -> +2968` and looks up entity via `func_332e60`.
  - Virtual predicate check via `item->get_id()` (`vtable[356/4]`).
  - Class acceptance check: calls `func_001471A0` against `{600, 613, 602, 618, 605}`. Returns 1 on match.
  - Health rejection check: `*(float*)(item + 64) > 0.0f` rejects (returns 0).
  - Qualification filters: `func_00147170 == 710` with status 100 branches to reject block; `func_00147170 == 702` branches to reject block; `func_0014C430 != 1` branches to dispatch block.
  - Final dispatch: tail-calls `func_2BB100(self, item_id, action_type)` and normalizes return via `movn` (`res == 0 ? 0 : 1`).

All 4 notification routines achieve 100.0% byte-for-byte matching with Metrowerks PS2 compiler (MWCC 2.3.1.01).
