# ZoneSpatialGrid occupant rebind verification (`func_001F2EB0`)

## Overview

`func_001F2EB0` spans virtual address range `0x1F2EB0`–`0x1F2F80` (file offsets
`0xF3090`–`0xF3160`) in PlayStation 2 PAL `AOK.ELF` (`SLES-50282`).
This routine performs occupant rebinding and notification for the spatial grid:
it binds the new occupant via `func_001F6CA0(item1, self->field_10)`, notifies the
previous occupant via `method_DC(0)` if non-null, updates `self->field_10 = item1`,
notifies the new occupant via `method_DC(1)` and `method_28(2)`, notifies the global
manager singleton `D_004D89C0` via `method_C8(D_004D8940, 0, 0, 0)` while setting
tracking flag `D_004D8E18 = 1`, and conditionally invokes occupant reset `func_001F2BD0(self)`
when `item2 != 0`.

Implemented in pure C++ in `src/zone_spatial_grid_rebind.cpp` and declared in
`include/zone_spatial_grid_rebind.h`.

## Function specification

| Property | Value |
|---|---|
| Function | `func_001F2EB0` |
| Virtual address range | `0x1F2EB0`–`0x1F2F80` |
| Code extent | `0x1F2EB0`–`0x1F2F7C` (204 bytes, 51 instructions) |
| Delay slot | `0x1F2F78` (`addiu $sp, $sp, 64`) |
| Alignment padding | `0x1F2F7C`–`0x1F2F80` (4 bytes `nop` padding) |
| File offset range | `0xF3090`–`0xF3160` |
| Relocations | 5 (2 `R_MIPS_26` function calls + 3 `R_MIPS_GPREL16` data loads) |

## Relocation analysis

All 5 relocations match authentic ELF sites and targets exactly:

| Offset | Opcode Hex | Relocation Type | Target Symbol | Target Address |
|---|---|---|---|---|
| `+0x24` | `0x0c07db28` | `R_MIPS_26` | `func_001F6CA0` | `0x1F6CA0` |
| `+0x74` | `0x8f8489c0` | `R_MIPS_GPREL16` | `D_004D89C0` | `0x4D89C0` (`$gp - 30272`) |
| `+0x84` | `0x8f858940` | `R_MIPS_GPREL16` | `D_004D8940` | `0x4D8940` (`$gp - 30400`) |
| `+0x88` | `0xaf828e18` | `R_MIPS_GPREL16` | `D_004D8E18` | `0x4D8E18` (`$gp - 29160`) |
| `+0xAC` | `0x0c07caf4` | `R_MIPS_26` | `func_001F2BD0` | `0x1F2BD0` |

Implicit addends at both `R_MIPS_26` relocation sites are verified to be zero (`0x0C000000`).

## Virtual call dispatches (no ELF relocation entry)

- `+0x3C` (`0x1F2EEC`): `vtable[55]` (`0xDC`) invoked on old `self->field_10` as `method_DC(0)`.
- `+0x54` (`0x1F2F04`): `vtable[55]` (`0xDC`) invoked on new `self->field_10` as `method_DC(1)`.
- `+0x68` (`0x1F2F18`): `vtable[10]` (`0x28`) invoked on new `self->field_10` as `method_28(2)`.
- `+0x98` (`0x1F2F48`): `vtable[50]` (`0xC8`) invoked on `D_004D89C0` as `method_C8(D_004D8940, 0, 0, 0)`.

## Contiguity & boundary proofs

- **Preceding boundary (`func_001F2E00`):** Sentinel lookup ends at `0x1F2EAC`
  with 0 bytes padding to `0x1F2EB0` (file offset `0xF3090`).
  `0x1F2EB0 - 0x1F2EB0 = 0` gap/overlap.
- **Following boundary (`func_001F2F80`):** Surface palette routine begins at `0x1F2F80`
  (file offset `0xF3160`, `27bdfa60 addiu $sp, $sp, -1440`).
  `0x1F2F80 - 0x1F2F80 = 0` gap/overlap.

## Verification & TDD evidence

### Chronology Note

In accordance with peer review guidelines, chronology is recorded with full transparency:
target contracts, relocations, and calling conventions were initially explored via retrospective
MWCC trial compilation to establish exact instruction structure. Prospective, isolated behavioral
Red/Green iterations were subsequently executed on the native harness in `docker-dev` to prove
each logical contract step-by-step before integration.

### Step-by-Step TDD Progression (Granular Red/Green Cycles)

The implementation followed mandatory test-driven development through eight isolated cycles executed in `docker-dev`:

1. **Step 1 — Unconditional bind helper dispatch (`func_001F6CA0`):**
   - **Red command:** `docker --context docker-dev run --rm --network host -v $(pwd):/workspace -w /workspace aoe-tests:verification pytest -p no:cacheprovider -q -ra tests/test_zone_spatial_grid_rebind.py`
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): rebind_test: /workspace/tests/native/zone_spatial_grid_rebind_test.cpp:125: int main(): Assertion 'observed_bind_new == item1_ptr' failed.` on empty stub.
   - **Green change:** Implemented `func_001F6CA0(item1, self->field_10);`.
   - **Green result:** Step 1 passed; Step 2 failed on `Assertion 'grid.field_10 == &item1' failed`.

2. **Step 2 — Occupant field assignment (`self->field_10 = item1`):**
   - **Red command:** Same targeted pytest command.
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): rebind_test: /workspace/tests/native/zone_spatial_grid_rebind_test.cpp:134: int main(): Assertion 'grid.field_10 == &item1' failed.`.
   - **Green change:** Added `self->field_10 = item1;`.
   - **Green result:** Field assignment passed; Step 3 failed on `Assertion 'D_004D8E18 == 1' failed`.

3. **Step 3 — Global manager tracking flag write (`D_004D8E18 = 1`):**
   - **Red command:** Same targeted pytest command.
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): rebind_test: /workspace/tests/native/zone_spatial_grid_rebind_test.cpp:136: int main(): Assertion 'D_004D8E18 == 1' failed.`.
   - **Green change:** Added `if (D_004D89C0 != 0) { D_004D8E18 = 1; }`.
   - **Green result:** Flag write passed; Step 4 failed on `Assertion 'observed_mgr_self == &mgr' failed`.

4. **Step 4 — Global manager method_C8 dispatch:**
   - **Red command:** Same targeted pytest command.
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): rebind_test: /workspace/tests/native/zone_spatial_grid_rebind_test.cpp:138: int main(): Assertion 'observed_mgr_self == &mgr' failed.`.
   - **Green change:** Added `D_004D89C0->method_C8(D_004D8940, 0, 0, 0);`.
   - **Green result:** Manager dispatch passed; Step 5 failed on `Assertion 'observed_method_dc_calls.size() == 1' failed`.

5. **Step 5 — Old occupant notification (`method_DC(0)`):**
   - **Red command:** Same targeted pytest command.
   - **Observable failure:** Observed missing old occupant notification before field update.
   - **Green change:** Added `if (self->field_10 != 0) { self->field_10->method_DC(0); }` before assignment.
   - **Green result:** Old occupant callback passed; Step 6 failed on new occupant `method_DC(1)`.

6. **Step 6 — New occupant primary callback (`method_DC(1)`):**
   - **Red command:** Same targeted pytest command.
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): rebind_test: /workspace/tests/native/zone_spatial_grid_rebind_test.cpp:143: int main(): Assertion 'observed_method_dc_calls.size() == 1' failed.`.
   - **Green change:** Added `self->field_10->method_DC(1);`.
   - **Green result:** New occupant `method_DC(1)` passed; Step 7 failed on `Assertion 'observed_method_28_calls.size() == 1' failed`.

7. **Step 7 — New occupant secondary callback (`method_28(2)`):**
   - **Red command:** Same targeted pytest command.
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): rebind_test: /workspace/tests/native/zone_spatial_grid_rebind_test.cpp:145: int main(): Assertion 'observed_method_28_calls.size() == 1' failed.`.
   - **Green change:** Added `self->field_10->method_28(2);`.
   - **Green result:** Both new occupant callbacks passed; Step 8 failed on `Assertion 'observed_reset_self == grid_ptr' failed`.

8. **Step 8 — Conditional occupant reset (`item2 != 0`):**
   - **Red command:** Same targeted pytest command.
   - **Observable failure:** `AssertionError: Native test failed with code -6 (SIGABRT): rebind_test: /workspace/tests/native/zone_spatial_grid_rebind_test.cpp:171: int main(): Assertion 'observed_reset_self == grid_ptr' failed.`.
   - **Green change:** Implemented `if (item2 != 0) { func_001F2BD0(self); }`.
   - **Green result:** Complete native test binary passed all 4 test cases, and all 11 mutation checks passed (12 passed in 3.18s: 1 native runner covering 4 test cases + 11 mutation tests).

- **Mutation sensitivity:** 11 distinct mutations confirmed sensitive across old occupant guard,
  old callback presence, field assignment, new DC callback, new 28 callback, argument corruptions,
  manager flag write, manager call, and item2 reset guard/call.
- **Provenance gate:** `tests/test_zone_spatial_grid_rebind_provenance.py` (18 passed in 0.78s)
  verifies fresh compilation under `wibo` using `compilers/PS2/mwcc-2.3.1.01/mwccps2.exe`,
  followed by exact literal instruction matching across all 204 bytes (`literal_match: true`),
  4 bytes trailing NOP padding (`original_padding_verified: true`),
  5 direct function/data relocations, matching resolved SHA-256 hash
  (`f7b7fabeb1e0b47cf705de26695a8881956633838bc0496fadc16c774c854a75`),
  corrupted instruction rejection against a passing baseline, unpinned ELF rejection,
  rejection of 7 relocation manifest mutations, rejection of non-zero implicit addends,
  rejection of non-executable sections, rejection of defined relocation symbols,
  rejection of non-MIPS ELF machine headers, rejection of oversized symbols,
  acceptance of permuted relocation records, and CLI zero-exit contract.
- **Configuration policy:** Registered as `NonMatching` in `configure.py` per standing
  policy pending peer review; `config.yml` and `symbols.txt` remain untouched.
