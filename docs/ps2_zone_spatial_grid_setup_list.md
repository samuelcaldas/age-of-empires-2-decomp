# ZoneSpatialGrid sentinel list setup verification (`func_001F2DA0`)

## Overview

`func_001F2DA0` spans virtual address range `0x1F2DA0`–`0x1F2E00` (file offsets
`0xF2F80`–`0xF2FE0`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
This routine allocates and initializes the circular doubly-linked sentinel node
for the spatial grid: it allocates a 12-byte `ListNode` record via `func_001143F8(1, 12)`
(`calloc`), guards against allocation failure, initializes `sentinel->elem = NULL`,
establishes self-referential circular list pointers `sentinel->next = sentinel` and
`sentinel->prev = sentinel`, sets the active status flag `self->field_AB0 = 1`, and
returns 1 (or 0 on allocation failure).

Implemented in pure C++ in `src/zone_spatial_grid_setup_list.cpp` and declared in
`include/zone_spatial_grid_setup_list.h`.

## Function specification

| Property | Value |
|---|---|
| Function | `func_001F2DA0` |
| Virtual address range | `0x1F2DA0`–`0x1F2E00` |
| Code extent | `0x1F2DA0`–`0x1F2DFC` (96 bytes, 24 instructions) |
| Delay slot | `0x1F2DFC` (`addiu $sp, $sp, 32`) |
| Alignment padding | `0x1F2E00` (0 bytes padding; contiguous to `func_001F2E00`) |
| File offset range | `0xF2F80`–`0xF2FE0` |
| Relocations | 1 (`R_MIPS_26` function call) |

## Relocation analysis

The single relocation matches authentic ELF sites and targets exactly:

| Offset | Opcode Hex | Relocation Type | Target Symbol | Target Address |
|---|---|---|---|---|
| `+0x14` | `0x0c0450fe` | `R_MIPS_26` | `func_001143F8` | `0x1143F8` |

Implicit addend at the relocation site is verified to be zero (`0x0C000000`).

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F2D50`):** Occupant contains ends at `0x1F2D9C`
  followed by 4 bytes of `nop` padding to `0x1F2DA0` (file offset `0xF2F80`).
  `0x1F2DA0 - 0x1F2DA0 = 0` gap/overlap.
- **Following boundary (`func_001F2E00`):** Sentinel list lookup begins at `0x1F2E00`
  (file offset `0xF2FE0`).
  `0x1F2E00 - 0x1F2E00 = 0` gap/overlap.

## Verification & TDD evidence

### Step-by-Step TDD Progression (Granular Red/Green Cycles)

The implementation followed mandatory test-driven development through two isolated cycles executed in `docker-dev`:

1. **Step 1 — Allocation failure guard (`alloc == NULL`):**
   - **Red command:** `docker --context docker-dev run --rm --network host -v $(pwd):/workspace -w /workspace aoe-tests:verification pytest -p no:cacheprovider -q -ra -k "test_native_setup_list_behavior" tests/test_zone_spatial_grid_setup_list.py`
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): setup_list_test: /workspace/tests/native/zone_spatial_grid_setup_list_test.cpp:63: int main(): Assertion 'res1 == 0' failed.` on stub returning `-1`.
   - **Green change:** Implemented `self->field_14 = (ListNode *)func_001143F8(1, 12); if (self->field_14 == 0) return 0;`.
   - **Green result:** Case 1 passed; Case 2 failed as expected on `Assertion 'res2 == 1' failed`.

2. **Step 2 — Allocation success & circular sentinel initialization (`alloc != NULL`):**
   - **Red command:** `docker --context docker-dev run --rm --network host -v $(pwd):/workspace -w /workspace aoe-tests:verification pytest -p no:cacheprovider -q -ra -k "test_native_setup_list_behavior" tests/test_zone_spatial_grid_setup_list.py`
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): setup_list_test: /workspace/tests/native/zone_spatial_grid_setup_list_test.cpp:84: int main(): Assertion 'res2 == 1' failed.`.
   - **Green change:** Added `self->field_14->elem = 0; self->field_14->next = self->field_14; self->field_14->prev = self->field_14; self->field_AB0 = 1; return 1;`.
   - **Green result:** 1 native behavioral runner covering 2 test cases (allocation failure and success initialization) + 6 mutation checks passed (total 7 pytest items passed in 1.48s).

- **Mutation sensitivity:** 6 distinct mutations confirmed sensitive across allocation checks,
  element zeroing, next/prev self-referential initialization, status flag `field_AB0`, and return values.
- **Provenance gate:** `tests/test_zone_spatial_grid_setup_list_provenance.py` (17 passed in 0.57s)
  verifies fresh compilation under `wibo` using `compilers/PS2/mwcc-2.3.1.01/mwccps2.exe`,
  followed by exact literal instruction matching across all 96 bytes (`literal_match: true`),
  0 bytes trailing padding (`original_padding_verified: true`),
  1 direct `R_MIPS_26` function relocation, matching resolved SHA-256 hash
  (`0e2371bf8e9fa56935959154921b4d2a64b1f11e1b66884a49f7407d1ac6b50e`),
  corrupted instruction rejection against a passing baseline, unpinned ELF rejection,
  rejection of 7 relocation manifest mutations, rejection of non-zero implicit addends,
  rejection of non-executable sections, rejection of defined relocation symbols,
  rejection of non-MIPS ELF machine headers, rejection of oversized symbols,
  and CLI zero-exit contract.
- **Configuration policy:** Registered as `NonMatching` in `configure.py` per standing
  policy pending peer review; `config.yml` and `symbols.txt` remain untouched.
