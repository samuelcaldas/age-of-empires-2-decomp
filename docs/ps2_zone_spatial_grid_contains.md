# ZoneSpatialGrid occupant contains verification (`func_001F2D50`)

## Overview

`func_001F2D50` spans virtual address range `0x1F2D50`–`0x1F2DA0` (file offsets
`0xF2F30`–`0xF2F80`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
This function verifies whether a spatial entity is currently tracked in the grid:
it guards against null item input, extracts the entity handle via `func_001F6CD0(item)`,
queries the circular doubly-linked sentinel list via `func_001F2E00(self, handle)`,
and returns 1 if present or 0 if missing/null.

Implemented in pure C++ in `src/zone_spatial_grid_contains.cpp` and declared in
`include/zone_spatial_grid_contains.h`.

## Function specification

| Property | Value |
|---|---|
| Function | `func_001F2D50` |
| Virtual address range | `0x1F2D50`–`0x1F2DA0` |
| Code extent | `0x1F2D50`–`0x1F2D9C` (76 bytes, 19 instructions) |
| Delay slot | `0x1F2D98` (`addiu $sp, $sp, 32`) |
| Alignment padding | `0x1F2D9C`–`0x1F2DA0` (4 bytes `nop` padding) |
| File offset range | `0xF2F30`–`0xF2F80` |
| Relocations | 2 (`R_MIPS_26` function calls) |

## Relocation analysis

All 2 relocations match authentic ELF sites and targets exactly:

| Offset | Opcode Hex | Relocation Type | Target Symbol | Target Address |
|---|---|---|---|---|
| `+0x14` | `0x0c07db34` | `R_MIPS_26` | `func_001F6CD0` | `0x1F6CD0` |
| `+0x20` | `0x0c07cb80` | `R_MIPS_26` | `func_001F2E00` | `0x1F2E00` |

Implicit addends at both relocation sites are verified to be zero (`0x0C000000`).

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F2CB0`):** Occupant unbind ends at `0x1F2D4C`
  with 0 bytes padding to `0x1F2D50` (file offset `0xF2F30`).
  `0x1F2D50 - 0x1F2D50 = 0` gap/overlap.
- **Following boundary (`func_001F2DA0`):** Sentinel list setup begins at `0x1F2DA0`
  (file offset `0xF2F80`, `27bdffe0 addiu $sp, $sp, -32`).
  `0x1F2DA0 - 0x1F2DA0 = 0` gap/overlap.

## Verification & TDD evidence

### Step-by-Step TDD Progression (Granular Red/Green Cycles)

The implementation followed mandatory test-driven development through three isolated cycles executed in `docker-dev`:

1. **Step 1 — Null item guard (`item == NULL`):**
   - **Red command:** `docker --context docker-dev run --rm --network host -v $(pwd):/workspace -w /workspace aoe-tests:verification pytest -p no:cacheprovider -q -ra -k "test_native_contains_behavior" tests/test_zone_spatial_grid_contains.py`
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): contains_test: /workspace/tests/native/zone_spatial_grid_contains_test.cpp:75: int main(): Assertion 'res1 == 0' failed.` on stub returning `-1`.
   - **Green change:** Implemented `if (item == 0) return 0;`.
   - **Green result:** Case 1 passed; Case 2 failed on `Assertion 'res2 == 0' failed`.

2. **Step 2 — Lookup failure guard (`node == NULL`):**
   - **Red command:** `docker --context docker-dev run --rm --network host -v $(pwd):/workspace -w /workspace aoe-tests:verification pytest -p no:cacheprovider -q -ra -k "test_native_contains_behavior" tests/test_zone_spatial_grid_contains.py`
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): contains_test: /workspace/tests/native/zone_spatial_grid_contains_test.cpp:89: int main(): Assertion 'res2 == 0' failed.`.
   - **Green change:** Added `void *handle = func_001F6CD0(item); ListNode *node = func_001F2E00(self, handle); if (node == 0) return 0;`.
   - **Green result:** Cases 1 and 2 passed with exact call order `[100, 200]` and argument forwarding verified; Case 3 failed on `Assertion 'res3 == 1' failed`.

3. **Step 3 — Present node return (`node != NULL`):**
   - **Red command:** `docker --context docker-dev run --rm --network host -v $(pwd):/workspace -w /workspace aoe-tests:verification pytest -p no:cacheprovider -q -ra -k "test_native_contains_behavior" tests/test_zone_spatial_grid_contains.py`
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): contains_test: /workspace/tests/native/zone_spatial_grid_contains_test.cpp:108: int main(): Assertion 'res3 == 1' failed.`.
   - **Green change:** Implemented `return 1;` when node is non-null (`if (item == 0 || func_001F2E00(self, func_001F6CD0(item)) == 0) return 0; return 1;`).
   - **Green result:** Native behavioral harness passed all 3 test cases, and all 5 mutation tests passed (6 passed in 1.31s).

- **Mutation sensitivity:** 5 distinct mutations confirmed sensitive across null guards,
  lookup checks, return values, always-true, and always-false mutants.
- **Provenance gate:** `tests/test_zone_spatial_grid_contains_provenance.py` (18 passed in 0.57s)
  verifies fresh compilation under `wibo` using `compilers/PS2/mwcc-2.3.1.01/mwccps2.exe`,
  followed by exact literal instruction matching across all 76 bytes (`literal_match: true`),
  4 bytes trailing NOP alignment padding (`original_padding_verified: true`),
  2 direct `R_MIPS_26` function relocations, matching resolved SHA-256 hash
  (`caa0c9b88379913f01010cb2dc407ed5278202c792d28e3bb6d9e77ee4a6f304`),
  corrupted instruction rejection against a passing baseline, unpinned ELF rejection,
  rejection of 7 relocation manifest mutations, rejection of non-zero implicit addends,
  rejection of non-executable sections, rejection of defined relocation symbols,
  rejection of non-MIPS ELF machine headers, rejection of oversized symbols,
  acceptance of permuted relocation records, and CLI zero-exit contract.
- **Configuration policy:** Promoted to `Matching` in `configure.py` following verification
  clearance; `config.yml` and `symbols.txt` remain untouched.
