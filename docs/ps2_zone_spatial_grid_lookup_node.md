# ZoneSpatialGrid sentinel lookup node verification (`func_001F2E00`)

## Overview

`func_001F2E00` spans virtual address range `0x1F2E00`–`0x1F2EB0` (file offsets
`0xF2FE0`–`0xF3090`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
This routine performs internal circular doubly-linked sentinel list traversal to locate
a node matching a given entity handle / string key: it guards against null handle input,
traverses backward starting from `self->field_14->prev` (tail), extracts each node's handle via
`func_001F6CD0(curr->elem)`, evaluates equality via `func_0011AA78` (`strcmp`), and returns
the matching `ListNode *` pointer, or `NULL` if exhausted without a match.

Implemented in pure C++ in `src/zone_spatial_grid_lookup_node.cpp` and declared in
`include/zone_spatial_grid_lookup_node.h`.

## Function specification

| Property | Value |
|---|---|
| Function | `func_001F2E00` |
| Virtual address range | `0x1F2E00`–`0x1F2EB0` |
| Code extent | `0x1F2E00`–`0x1F2EAC` (176 bytes, 44 instructions) |
| Delay slot | `0x1F2EAC` (`addiu $sp, $sp, 64`) |
| Alignment padding | `0x1F2EB0` (0 bytes padding; contiguous to `func_001F2EB0`) |
| File offset range | `0xF2FE0`–`0xF3090` |
| Relocations | 4 (`R_MIPS_26` function calls) |

## Relocation analysis

All 4 relocations match authentic ELF sites and targets exactly:

| Offset | Opcode Hex | Relocation Type | Target Symbol | Target Address |
|---|---|---|---|---|
| `+0x48` | `0x0c07db34` | `R_MIPS_26` | `func_001F6CD0` | `0x1F6CD0` |
| `+0x54` | `0x0c046a9e` | `R_MIPS_26` | `func_0011AA78` | `0x11AA78` (`strcmp`) |
| `+0x70` | `0x0c07db34` | `R_MIPS_26` | `func_001F6CD0` | `0x1F6CD0` |
| `+0x7C` | `0x0c046a9e` | `R_MIPS_26` | `func_0011AA78` | `0x11AA78` (`strcmp`) |

Implicit addends at all relocation sites are verified to be zero (`0x0C000000`).

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F2DA0`):** Sentinel setup ends at `0x1F2DFC`
  with 0 bytes padding to `0x1F2E00` (file offset `0xF2FE0`).
  `0x1F2E00 - 0x1F2E00 = 0` gap/overlap.
- **Following boundary (`func_001F2EB0`):** Next routine begins at `0x1F2EB0`
  (file offset `0xF3090`, `27bdffc0 addiu $sp, $sp, -64`).
  `0x1F2EB0 - 0x1F2EB0 = 0` gap/overlap.

## Verification & TDD evidence

### Step-by-Step TDD Progression (Granular Red/Green Cycles)

The implementation followed mandatory test-driven development through four isolated cycles executed in `docker-dev`:

1. **Step 1 — Null handle guard (`handle == NULL`):**
   - **Red command:** `docker --context docker-dev run --rm --network host -v $(pwd):/workspace -w /workspace aoe-tests:verification pytest -p no:cacheprovider -q -ra -k "test_native_lookup_node_behavior" tests/test_zone_spatial_grid_lookup_node.py`
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): lookup_node_test: /workspace/tests/native/zone_spatial_grid_lookup_node_test.cpp:67: int main(): Assertion 'res1 == NULL' failed.` on stub returning `0xDEADBEEF`.
   - **Green change:** Implemented `if (handle == 0) return 0;`.
   - **Green result:** Case 1 passed; Case 2 failed on `Assertion 'res2 == NULL' failed`.

2. **Step 2 — Empty list check (`sentinel->prev == sentinel`):**
   - **Red command:** `docker --context docker-dev run --rm --network host -v $(pwd):/workspace -w /workspace aoe-tests:verification pytest -p no:cacheprovider -q -ra -k "test_native_lookup_node_behavior" tests/test_zone_spatial_grid_lookup_node.py`
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): lookup_node_test: /workspace/tests/native/zone_spatial_grid_lookup_node_test.cpp:75: int main(): Assertion 'res2 == NULL' failed.`.
   - **Green change:** Implemented early empty-list termination check.
   - **Green result:** Cases 1 and 2 passed with 0 external calls; Case 3 failed on `Assertion 'res3 == NULL' failed`.

3. **Step 3 — Backward traversal & not-found return (`curr == sentinel`):**
   - **Red command:** `docker --context docker-dev run --rm --network host -v $(pwd):/workspace -w /workspace aoe-tests:verification pytest -p no:cacheprovider -q -ra -k "test_native_lookup_node_behavior" tests/test_zone_spatial_grid_lookup_node.py`
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): lookup_node_test: /workspace/tests/native/zone_spatial_grid_lookup_node_test.cpp:108: int main(): Assertion 'res3 == NULL' failed.`.
   - **Green change:** Implemented backward traversal loop (`curr = self->field_14->prev; while (curr != self->field_14 && func_0011AA78(...) != 0) curr = curr->prev;`) returning NULL on exhaustion.
   - **Green result:** Cases 1, 2, and 3 passed with backward traversal order and arguments verified; Case 4 failed on `Assertion 'res4 == &node1' failed`.

4. **Step 4 — Matching node pointer return (`curr != sentinel`):**
   - **Red command:** `docker --context docker-dev run --rm --network host -v $(pwd):/workspace -w /workspace aoe-tests:verification pytest -p no:cacheprovider -q -ra -k "test_native_lookup_node_behavior" tests/test_zone_spatial_grid_lookup_node.py`
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): lookup_node_test: /workspace/tests/native/zone_spatial_grid_lookup_node_test.cpp:130: int main(): Assertion 'res4 == reinterpret_cast<ListNode *>(&node1)' failed.`.
   - **Green change:** Implemented `if (curr != self->field_14 && func_0011AA78(...) == 0) return curr;`.
   - **Green result:** Native behavioral harness passed all 5 test cases (including duplicate-node backward tail-first order), and all 5 mutation checks passed (6 passed in 1.63s: 1 native runner covering 5 test cases + 5 mutation tests).

- **Mutation sensitivity:** 5 distinct mutations confirmed sensitive across null checks,
  forward vs backward traversal direction, advance step direction, strcmp condition, and found node return.
- **Provenance gate:** `tests/test_zone_spatial_grid_lookup_node_provenance.py` (18 passed in 0.57s)
  verifies fresh compilation under `wibo` using `compilers/PS2/mwcc-2.3.1.01/mwccps2.exe`,
  followed by exact literal instruction matching across all 176 bytes (`literal_match: true`),
  0 bytes trailing padding (`original_padding_verified: true`),
  4 direct `R_MIPS_26` function relocations, matching resolved SHA-256 hash
  (`2d1ce2034f92dfe27adf2ea9ec4acc9a8bd6e18475ba9537498d567daeedc6b6`),
  corrupted instruction rejection against a passing baseline, unpinned ELF rejection,
  rejection of 7 relocation manifest mutations, rejection of non-zero implicit addends,
  rejection of non-executable sections, rejection of defined relocation symbols,
  rejection of non-MIPS ELF machine headers, rejection of oversized symbols,
  acceptance of permuted relocation records, and CLI zero-exit contract.
- **Configuration policy:** Registered as `NonMatching` in `configure.py` per standing
  policy pending peer review; `config.yml` and `symbols.txt` remain untouched.
