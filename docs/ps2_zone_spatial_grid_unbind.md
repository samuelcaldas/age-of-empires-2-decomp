# ZoneSpatialGrid occupant unbind verification (`func_001F2CB0`)

## Overview

`func_001F2CB0` spans virtual address range `0x1F2CB0`–`0x1F2D50` (file offsets
`0xF2E90`–`0xF2F30`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
This routine performs element unbinding and removal from the spatial grid: it guards
against null input, queries the internal node via `func_001F2E00(self, elem)`, guards
against missing nodes, decrements the active occupant counter `self->field_18`, unlinks
the node from the circular doubly-linked sentinel list, invokes the element virtual
callback `node->elem->method_08(1)` via `vtable[2]` (slot 0 at offset `0x08`) if `node->elem`
is non-null, deallocates the node memory via `func_00116F68(node)`, and returns 1.

Implemented in pure C++ in `src/zone_spatial_grid_unbind.cpp` and declared in
`include/zone_spatial_grid_unbind.h`.

## Function specification

| Property | Value |
|---|---|
| Function | `func_001F2CB0` |
| Virtual address range | `0x1F2CB0`–`0x1F2D50` |
| Code extent | `0x1F2CB0`–`0x1F2D4C` (160 bytes, 40 instructions) |
| Delay slot | `0x1F2D4C` (`addiu $sp, $sp, 48`) |
| Alignment padding | `0x1F2D50` (0 bytes padding; contiguous to next function) |
| File offset range | `0xF2E90`–`0xF2F30` |
| Relocations | 2 (`R_MIPS_26` function calls) |

## Relocation analysis

All 2 relocations match authentic ELF sites and targets exactly:

| Offset | Opcode Hex | Relocation Type | Target Symbol | Target Address |
|---|---|---|---|---|
| `+0x20` | `0x0c07cb80` | `R_MIPS_26` | `func_001F2E00` | `0x1F2E00` |
| `+0x80` | `0x0c045bda` | `R_MIPS_26` | `func_00116F68` | `0x116F68` |

Implicit addends at both relocation sites are verified to be zero (`0x0C000000`).

## Virtual call dispatches (no ELF relocation entry)

- `+0x74` (`0x1F2D24`): `vtable[2]` (raw offset `0x08`, slot 0 in Metrowerks PS2 C++ ABI)
  invoked on `node->elem` as `method_08(1)`.

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F2C20`):** Occupant advance ends at `0x1F2CAC`
  followed by 4 bytes of `nop` padding to `0x1F2CB0` (file offset `0xF2E90`).
  `0x1F2CB0 - 0x1F2CB0 = 0` gap/overlap.
- **Following boundary (`0x1F2D50`):** Next routine begins at `0x1F2D50`
  (file offset `0xF2F30`).
  `0x1F2D50 - 0x1F2D50 = 0` gap/overlap.

## Verification & TDD evidence

### Step-by-Step TDD Progression (Granular Red/Green Cycles)

The implementation followed mandatory test-driven development through four isolated, observable cycles executed in `docker-dev`:

1. **Step 1 — Null element guard (`elem == NULL`):**
   - **Red command:** `docker --context docker-dev run --rm --network host -v $(pwd):/workspace -w /workspace aoe-tests:verification pytest -p no:cacheprovider -q -ra tests/test_zone_spatial_grid_unbind.py`
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): unbind_test: /workspace/tests/native/zone_spatial_grid_unbind_test.cpp:86: int main(): Assertion 'res1 == 0' failed.` on stub returning `-1`.
   - **Green change:** Implemented `if (elem == 0) return 0;`.
   - **Green result:** Case 1 passed; Case 2 failed as expected.

2. **Step 2 — Lookup failure guard (`node == NULL`):**
   - **Red command:** `docker --context docker-dev run --rm --network host -v $(pwd):/workspace -w /workspace aoe-tests:verification pytest -p no:cacheprovider -q -ra -k "test_native_unbind_behavior" tests/test_zone_spatial_grid_unbind.py`
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): unbind_test: /workspace/tests/native/zone_spatial_grid_unbind_test.cpp:96: int main(): Assertion 'res2 == 0' failed.`.
   - **Green change:** Added `ListNode *node = func_001F2E00(self, elem); if (node == 0) return 0;`.
   - **Green result:** Cases 1 and 2 passed; Case 3 failed as expected.

3. **Step 3 — Node unlinking and deallocation (`node->elem == NULL`):**
   - **Red command:** `docker --context docker-dev run --rm --network host -v $(pwd):/workspace -w /workspace aoe-tests:verification pytest -p no:cacheprovider -q -ra -k "test_native_unbind_behavior" tests/test_zone_spatial_grid_unbind.py`
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): unbind_test: /workspace/tests/native/zone_spatial_grid_unbind_test.cpp:128: int main(): Assertion 'res3 == 1' failed.`.
   - **Green change:** Implemented `self->field_18--; node->next->prev = node->prev; node->prev->next = node->next; func_00116F68(node); return 1;`.
   - **Green result:** Cases 1, 2, and 3 passed (interior unlinking with NULL elem); execution then proceeded to Case 4 and aborted on missing callback.

4. **Step 4 — Virtual callback dispatch (`node->elem != NULL`):**
   - **Red command:** `docker --context docker-dev run --rm --network host -v $(pwd):/workspace -w /workspace aoe-tests:verification pytest -p no:cacheprovider -q -ra -k "test_native_unbind_behavior" tests/test_zone_spatial_grid_unbind.py`
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): unbind_test: /workspace/tests/native/zone_spatial_grid_unbind_test.cpp:159: int main(): Assertion 'observed_method_self == &item' failed.`.
   - **Green change:** Added `if (node->elem != 0) { node->elem->method_08(1); }` before node deallocation.
   - **Green result:** Complete test binary passed all 7 test cases (including subsequent head, tail, and self-loop unlinking), and all 11 mutation tests passed (total 12 pytest items passed in 2.99s: 1 native runner covering 7 test cases + 11 mutation checks).

- **Mutation sensitivity:** 11 distinct mutations confirmed sensitive across null guards,
  counter decrement, pointer unlinking, method call presence, argument value, free call,
  and return value.
- **Provenance gate:** `tests/test_zone_spatial_grid_unbind_provenance.py` (18 passed in 0.54s)
  verifies fresh compilation under `wibo` using `compilers/PS2/mwcc-2.3.1.01/mwccps2.exe`,
  followed by exact literal instruction matching across all 160 bytes (`literal_match: true`),
  2 direct `R_MIPS_26` function relocations, matching resolved SHA-256 hash
  (`f3c4b868b0011e7cfab87bec4548d963487ce44f6222e30a897d39d76e7a7ea9`),
  corrupted instruction rejection against a passing baseline, unpinned ELF rejection,
  rejection of 7 relocation manifest mutations, rejection of non-zero implicit addends,
  rejection of non-executable sections, rejection of defined relocation symbols,
  rejection of non-MIPS ELF machine headers, rejection of oversized symbols,
  acceptance of permuted relocation records, and CLI zero-exit contract.
- **Configuration policy:** Promoted to `Matching` in `configure.py` following verification
  clearance; `config.yml` and `symbols.txt` remain untouched.
