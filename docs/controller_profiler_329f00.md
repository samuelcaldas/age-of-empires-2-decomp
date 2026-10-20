# Combat subsystem controller profiler at 0x329F00

`func_00329F00` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_profiler.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **156/156 instruction bytes (100.00%)**
after resolving relocations for `func_2261C0` (R_MIPS_26), `func_1F60F0` (R_MIPS_26),
`D_004E3180` (R_MIPS_GPREL16), and `func_184B60` (R_MIPS_26).

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_00329F00 = 0x329F00; // type:func size:0x9C absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function: VRAM `[0x329F00, 0x329F9C)`, file `[0x0022A0E0, 0x0022A17C)`.
  The function spans 156 instruction bytes (`0x9C`, 39 instructions). Symbol size is `0x9C`.
- Predecessor padding: 4 bytes (`0x4`, 1 `nop` instruction `0x00000000` at `0x329EFC`)
  following `func_003299F0`. Zero overlap.
- Successor padding: 4 bytes (`0x4`, 1 `nop` instruction `0x00000000` at `0x329F9C`)
  preceding `func_00329FA0`. Zero overlap.
- Stack frame: 112 bytes (`addiu $sp, $sp, -0x70`), saving `$ra` (0x60),
  `$s5` (0x50), `$s4` (0x40), `$s3` (0x30), `$s2` (0x20), `$s1` (0x10),
  and `$s0` (0x00).

## Observable behavior

1. Query start timestamp: `start = func_2261C0()`.
2. Forward all 6 arguments to target processor: `ret = func_1F60F0(a0, a1, a2, a3, t0, t1)`.
3. Query completion timestamp: `end = func_2261C0()`.
4. Report profiling telemetry: `func_184B60(D_004E3180, 13, end - start)`.
5. Return processor outcome: `ret`.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_profiler_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_profiler.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_profiler.h"

     int func_00329F00(void *, void *, void *, void *, void *, void *) {
         return 0;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_profiler.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_profiler_test.cpp -o build/test_profiler_red \
       && ./build/test_profiler_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: profiler return value mismatch` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ profiler wrapper in `src/tactical_ai_combat_subsystem_controller_profiler.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_profiler.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_profiler_test.cpp -o build/test_profiler_green \
       && ./build/test_profiler_green
     ```
   - Result: All fixtures passing cleanly (`passthrough`, `zero_delta`), exit code 0 under UBSan.
   - Verified 5 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_profiler.py`.
3. **Refactor & Matching Verification:**
   - Built with verified MWCC PS2 flags: size 156 bytes (exact 156/156 byte match).
   - Relocations resolved: 5 relocations matching exact multiset with unpatched word verification.
   - Exact 100.00% byte-for-byte match (156/156 bytes, 0 differences) against original `SLES-50282` ELF.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_profiler.py \
  tests/test_tactical_ai_combat_subsystem_controller_profiler_matching.py
```

The focused test run comprises **7 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating argument forwarding, timer sampling,
  telemetry channel 13 dispatch, elapsed delta calculation, and return passthrough.
- Five production source mutations independently compiled and verified
  rejected (corrupted return value, corrupted channel, corrupted delta calculation, corrupted first argument, corrupted sixth argument).
- One exact matching test compiling fresh with Ninja/MWCC and verifying
  100.00% byte-for-byte identity against the pinned ELF binary with canonical symbol boundary
  and duplicate-rejecting multiset relocation checks.

The WIP/BIN boundary and registered object list remain unchanged.
