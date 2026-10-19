# Combat subsystem controller coordinate clamp at 0x32E580

`func_0032E580` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_coord_clamp.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 168-byte candidate sequence
(-24 bytes from 192-byte target code extent, 73 matching bytes;
classified strictly as NonMatching), scoping 2D coordinate bounds clamping
against view limits `[0.0f, (float)m_bounds->max_x - 1.0f]` and `[0.0f, (float)m_bounds->max_y - 1.0f]`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032E580 = 0x32E580; // type:func size:0xC0 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32E580, 0x32E640)` (192 bytes, `0xC0`, 48 instructions), with zero internal padding.
  Symbol extent spans `[0x32E580, 0x32E640)` (192 bytes, `0xC0`, 48 instructions).
  File extent in `orig/SLES-50282/AOK.ELF`: `[0x0022E760, 0x0022E820)`.
- Predecessor continuity: directly preceded by `func_0032E4B0` ending at `0x32E580` (`0x0022E760`).
  Between `0x32E4B0` and `0x32E580`: exactly 0 bytes padding (immediate successor).
  Zero overlap.
- Successor continuity: directly followed by `func_0032E640` starting at `0x32E640` (`0x0022E820`),
  size `0x64` (100 bytes).
  Between `0x32E640` and `0x32E640`: exactly 0 bytes padding (immediate successor).
  Zero unclassified bytes, zero overlap.
- Leaf function without stack frame allocation (`$sp` unchanged).
  Epilogue: `jr $ra` at `0x32E638` (+0xB8) and delay slot `nop` at `0x32E63C` (+0xBC).

## Relocation manifest

### Compiled candidate relocations (0 relocations)
The 168-byte candidate object resolves 0 relocations.

### Full ELF function relocations (0 relocations)
The full 192-byte original binary function contains 0 relocations (pure leaf arithmetic routine).

## Observable behavior

1. Pointer validation: guard against null `self`, `m_bounds`, or `coords`.
2. X-coordinate clamping:
   - If `coords[0] < 0.0f`: clamp `coords[0] = 0.0f`.
   - Else if `coords[0] > (float)m_bounds->max_x - 1.0f`: clamp `coords[0] = (float)m_bounds->max_x - 1.0f`.
3. Y-coordinate clamping:
   - If `coords[1] < 0.0f`: clamp `coords[1] = 0.0f`.
   - Else if `coords[1] > (float)m_bounds->max_y - 1.0f`: clamp `coords[1] = (float)m_bounds->max_y - 1.0f`.
4. In-range preservation: leave values strictly within `[0.0f, max - 1.0f]` untouched.

## TDD Chronology and Verification Evidence

1. **Red/Green Incremental Cycle:**
   - Step 1: No-op stub failed fast with `MUTATION_ASSERTION_FAILED: negative x must clamp to zero` (exit code 1).
   - Step 1 Green: Implemented `x < 0` clamp. Re-run failed `MUTATION_ASSERTION_FAILED: negative y must clamp to zero` (exit code 1).
   - Step 2 Green: Implemented `y < 0` clamp. Re-run failed `MUTATION_ASSERTION_FAILED: upper x must clamp to max_x - 1.0f` (exit code 1).
   - Step 3 Green: Implemented `x` upper clamp. Re-run failed `MUTATION_ASSERTION_FAILED: upper y must clamp to max_y - 1.0f` (exit code 1).
   - Step 4 Green: Implemented `y` upper clamp.
   - Result: All 4 fixtures passing cleanly (`clamp_neg`, `clamp_upper`, `in_range`, `boundary`), exit code 0 under UBSan.
   - Verified 9 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_coord_clamp.py`.
2. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate code size 168 bytes (-24 bytes from 192-byte target).
   - Relocations resolved: 0 compiled relocations mapped and verified with multiset check.
   - Classified strictly as **NonMatching** (73 matching bytes).
   - The matching test serves as a structural correspondence diagnostic asserting >=60 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_coord_clamp.py \
  tests/test_tactical_ai_combat_subsystem_controller_coord_clamp_matching.py
```

The focused test run comprises **11 total tests** (10 behavioral tests in `test_tactical_ai_combat_subsystem_controller_coord_clamp.py` and 1 structural matching diagnostic test in `test_tactical_ai_combat_subsystem_controller_coord_clamp_matching.py`):
- One 32-bit native contract test with UBSan validating lower negative clamping, upper bound clamping,
  in-range value preservation, and boundary edge conditions for both coordinates.
- Nine production source mutations independently compiled and verified
  rejected (x neg check, x neg val, y neg check, y neg val, x upper val, y upper val, x upper check, y upper check, zero x boundary).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
