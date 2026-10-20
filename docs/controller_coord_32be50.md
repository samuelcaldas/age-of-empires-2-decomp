# Combat subsystem controller coordinate dispatcher at 0x32BE50

`func_0032BE50` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_coord.cpp`.
A fresh MWCC PS2 2.3.1.01 build produces a 260-byte instruction sequence
(-28 bytes from 288-byte target, 73 of 288 bytes matching, 215 byte differences), matching stack frame (-0x40 = 64 bytes),
callee-saved `$s0`–`$s2` and `$ra`, gate validation (`D_004E3180->m_mode` in `{4, 5, 6, 7}`),
manager status query `func_185DC0`, `self->m_field_190` routing, view notifications through slots `0x110` and `0x10C`,
and fallback notification `func_1F65A0`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Canonical Symbol: `func_0032BE50 = 0x32BE50; // type:func size:0x120 absolute:True`
  in `config/SLES-50282/symbols.txt`.
- Function Code Extent: VRAM `[0x32BE50, 0x32BF70)`, file `[0x0022C030, 0x0022C150)`.
  The function body spans 288 instruction bytes (`0x120`, 72 instructions). Symbol size is `0x120`.
  Code ends at `0x32BF6C` (`addiu $sp, $sp, 64` in delay slot of `jr $ra` at `0x32BF68`).
- Predecessor continuity: directly preceded by `func_0032BCE0` ending at `0x32BE48` with
  8 bytes alignment padding `nop` (`0x00000000 0x00000000` at `0x32BE48` and `0x32BE4C`). Zero overlap.
- Successor continuity: directly followed by `func_0032BF70` starting at `0x32BF70` (file offset `0x0022C150`),
  size `0x3B0`. Contiguous, zero padding. Zero overlap.
- Stack frame: 64 bytes (`addiu $sp, $sp, -0x40`), saving `$ra` (0x30),
  `$s2` (0x20), `$s1` (0x10), and `$s0` (0x00) via quadword stores `sq`.

## Observable behavior

1. Check mode gate:
   - System manager mode `D_004E3180->m_mode` must be in `{4, 5, 6, 7}`.
   - If mode is unsupported, return 0 and suppress all downstream calls.
2. Query manager status via `func_185DC0(D_004E3180)`:
   - If busy (`func_185DC0 != 0`):
     - If `self->m_field_190 != 0`: dispatch `self->m_vtable->func_110(self)`.
     - Else: dispatch `func_1F65A0(self)`.
     - Return 0.
   - If idle (`func_185DC0 == 0`):
     - If `self->m_field_190 != 0`: dispatch `self->m_vtable->func_10C(self, a1, a2)` and return 1.
     - Else: return 0.

## Original ELF instruction breakdown and semantic provenance

Disassembly of all 72 original instructions from `orig/SLES-50282/AOK.ELF` (`[0x0022C030, 0x0022C150)`):

```text
0x32BE50: 27BDFFC0 addiu $sp, $sp, -64           ; stack frame allocation
0x32BE54: 7FBF0030 sq $ra, 48($sp)               ; callee-saved register preservation
0x32BE58: 7FB20020 sq $s2, 32($sp)
0x32BE5C: 7FB10010 sq $s1, 16($sp)
0x32BE60: 7FB00000 sq $s0, 0($sp)
0x32BE64: 70809628 por $s2, $a0, $zero           ; $s2 = self
0x32BE68: 8F8489C0 lw $a0, -30272($gp)           ; $a0 = D_004E3180 (R_MIPS_GPREL16)
0x32BE6C: 70C08628 por $s0, $a2, $zero           ; $s0 = a2
0x32BE70: 70A08E28 por $s1, $a1, $zero           ; $s1 = a1
0x32BE74: 64050001 daddiu $a1, $zero, 1
0x32BE78: 24020004 addiu $v0, $zero, 4
0x32BE7C: 8C8601C8 lw $a2, 456($a0)              ; $a2 = D_004E3180->m_mode
0x32BE80: 10C20005 beq $a2, $v0, 0x32BE98        ; mode == 4 -> pass
0x32BE84: 70A01E28 por $v1, $a1, $zero
0x32BE88: 24020006 addiu $v0, $zero, 6
0x32BE8C: 10C20002 beq $a2, $v0, 0x32BE98        ; mode == 6 -> pass
0x32BE90: 00000000 nop
0x32BE94: 70001E28 por $v1, $zero, $zero
0x32BE98: 14600007 bne $v1, $zero, 0x32BEB8
0x32BE9C: 30A200FF andi $v0, $a1, 0x00FF
0x32BEA0: 8C8301C8 lw $v1, 456($a0)              ; D_004E3180->m_mode
0x32BEA4: 24020007 addiu $v0, $zero, 7
0x32BEA8: 10620002 beq $v1, $v0, 0x32BEB4        ; mode == 7 -> pass
0x32BEAC: 00000000 nop
0x32BEB0: 70002E28 por $a1, $zero, $zero
0x32BEB4: 30A200FF andi $v0, $a1, 0x00FF
0x32BEB8: 14400008 bne $v0, $zero, 0x32BEDC
0x32BEBC: 70002E28 por $a1, $zero, $zero
0x32BEC0: 38C20005 xori $v0, $a2, 0x0005
0x32BEC4: 2C420001 sltiu $v0, $v0, 1             ; mode == 5 -> pass
0x32BEC8: 14400003 bne $v0, $zero, 0x32BED8
0x32BECC: 00000000 nop
0x32BED0: 10000021 beq $zero, $zero, 0x32BF58    ; mode rejected -> branch to epilogue
0x32BED4: 70001628 por $v0, $zero, $zero         ; return 0 in delay slot
0x32BED8: 70002E28 por $a1, $zero, $zero
0x32BEDC: 0C061770 jal 0x185DC0                  ; func_185DC0(D_004E3180) (R_MIPS_26)
0x32BEE0: 00000000 nop
0x32BEE4: 10400010 beq $v0, $zero, 0x32BF28      ; if (mgr_status == 0) -> goto idle branch
0x32BEE8: 00000000 nop
0x32BEEC: 92420190 lbu $v0, 400($s2)             ; busy branch: $v0 = self->m_field_190
0x32BEF0: 10400008 beq $v0, $zero, 0x32BF14      ; if (m_field_190 == 0) -> fallback
0x32BEF4: 72402628 por $a0, $s2, $zero           ; $a0 = self
0x32BEF8: 8E590000 lw $t9, 0($s2)                ; vtable lookup
0x32BEFC: 8F390110 lw $t9, 272($t9)              ; vtable->func_110 (slot 0x110)
0x32BF00: 0320F809 jalr $ra, $t9                 ; self->m_vtable->func_110(self)
0x32BF04: 72402628 por $a0, $s2, $zero
0x32BF08: 10000005 beq $zero, $zero, 0x32BF20    ; branch to epilogue
0x32BF0C: 70001628 por $v0, $zero, $zero         ; return 0
0x32BF10: 72402628 por $a0, $s2, $zero           ; $a0 = self
0x32BF14: 0C07D968 jal 0x1F65A0                  ; func_1F65A0(self) (R_MIPS_26)
0x32BF18: 00000000 nop
0x32BF1C: 70001628 por $v0, $zero, $zero         ; return 0
0x32BF20: 1000000E beq $zero, $zero, 0x32BF5C    ; branch to epilogue
0x32BF24: 7BBF0030 lq $ra, 48($sp)
0x32BF28: 92420190 lbu $v0, 400($s2)             ; idle branch: $v0 = self->m_field_190
0x32BF2C: 1040000A beq $v0, $zero, 0x32BF58      ; if (m_field_190 == 0) -> return 0
0x32BF30: 70001628 por $v0, $zero, $zero         ; return 0
0x32BF34: 8E590000 lw $t9, 0($s2)                ; vtable lookup
0x32BF38: 72202E28 por $a1, $s1, $zero           ; $a1 = a1
0x32BF3C: 72003628 por $a2, $s0, $zero           ; $a2 = a2
0x32BF40: 8F39010C lw $t9, 268($t9)              ; vtable->func_10C (slot 0x10C)
0x32BF44: 0320F809 jalr $ra, $t9                 ; self->m_vtable->func_10C(self, a1, a2)
0x32BF48: 72402628 por $a0, $s2, $zero           ; $a0 = self in delay slot
0x32BF4C: 10000002 beq $zero, $zero, 0x32BF58    ; branch to epilogue
0x32BF50: 24020001 addiu $v0, $zero, 1           ; return 1 in delay slot
0x32BF54: 70001628 por $v0, $zero, $zero
0x32BF58: 7BBF0030 lq $ra, 48($sp)               ; epilogue register restoration
0x32BF5C: 7BB20020 lq $s2, 32($sp)
0x32BF60: 7BB10010 lq $s1, 16($sp)
0x32BF64: 7BB00000 lq $s0, 0($sp)
0x32BF68: 03E00008 jr $ra
0x32BF6C: 27BD0040 addiu $sp, $sp, 64            ; stack frame teardown
```

### ABI Call Register Note

At `0x32BE74`, register `$a1` is initially loaded with 1 (`daddiu $a1, $zero, 1`) during the short-circuit boolean evaluation of `m_mode`. The gate logic subsequently clears `$a1` to 0 (`por $a1, $zero, $zero` at `0x32BEB0`, `0x32BEBC`, `0x32BED8`) before the call at `0x32BEDC` (`jal 0x185DC0`). Thus, the hardware register state entering `func_185DC0` has `$a0 = D_004E3180` and `$a1 = 0`. The C/C++ function declaration `int func_185DC0(SystemManager *mgr)` declares a single parameter, matching `$a0`; register `$a1` is a compiler intermediate register artifact from the preceding boolean logic and is ignored by the callee.

## TDD Chronology and Verification Evidence

1. **Red Stage:**
   - Test harness established in `tests/native/tactical_ai_combat_subsystem_controller_coord_test.cpp`
     with fail-fast `TEST_ASSERT` macros and `#ifdef NDEBUG #error` compile-time guards.
   - Tested against empty candidate stub in `src/tactical_ai_combat_subsystem_controller_coord.cpp`:
     ```cpp
     #include "tactical_ai_combat_subsystem_controller_coord.h"

     int func_0032BE50(CombatSubsystemControllerInstance *, int, int) {
         return -1;
     }
     ```
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_coord.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_coord_test.cpp -o build/test_coord_red \
       && ./build/test_coord_red
     ```
   - Exact observed failing assertion:
     `MUTATION_ASSERTION_FAILED: unsupported mode must return 0` (exit code 1).
2. **Green Stage:**
   - Implemented pure C++ coordinate dispatcher in `src/tactical_ai_combat_subsystem_controller_coord.cpp`.
   - Command:
     ```sh
     g++ -std=c++11 -O2 -m32 -fno-builtin -Wall -Wextra -Werror -fsanitize=undefined \
       -fno-sanitize-recover=all -Iinclude src/tactical_ai_combat_subsystem_controller_coord.cpp \
       tests/native/tactical_ai_combat_subsystem_controller_coord_test.cpp -o build/test_coord_green \
       && ./build/test_coord_green
     ```
   - Result: All 6 fixtures passing cleanly (`gate_rejection`, `busy_active`, `busy_inactive`, `idle_inactive`, `idle_active`, `accepted_modes`), exit code 0 under UBSan.
   - Native test explicitly validates manager pointer identity: `TEST_ASSERT(s_last_185dc0_mgr == D_004E3180)`.
   - Verified 10 production-source mutations independently compiled and killed via diagnostic matching in `tests/test_tactical_ai_combat_subsystem_controller_coord.py`.
3. **Refactor & Matching Diagnostics:**
   - Built with verified MWCC PS2 flags: candidate size 260 bytes (-28 bytes from 288-byte target).
   - Relocations resolved: `D_004E3180` (offset +0x18, `R_MIPS_GPREL16`), `func_185DC0` (offset +0x8C, `R_MIPS_26`), `func_1F65A0` (offset +0xC4, `R_MIPS_26`).
   - Classified strictly as **NonMatching** (73 matching bytes, 215 byte differences).
   - The matching test serves as a structural correspondence diagnostic asserting >=50 matching bytes rather than an exact matching claim.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_coord.py \
  tests/test_tactical_ai_combat_subsystem_controller_coord_matching.py
```

The focused test run comprises **12 passing tests** (or 11 passing, 1 skipped when compiler/wibo are unprovisioned):
- One 32-bit native contract test with UBSan validating mode gate rejection, accepted modes `{4, 5, 6, 7}`,
  busy manager dispatch with active/inactive field, idle manager dispatch with active/inactive field, manager pointer identity `D_004E3180`, arguments, and return values.
- Ten production source mutations independently compiled and verified
  rejected (gate return, busy check, manager argument pointer, busy field check, busy vtable func_110 call, busy fallback func_1F65A0 call, idle field check, idle vtable func_10C call, idle func_10C arguments, idle return).
- One structural correspondence diagnostic test compiling fresh with Ninja/MWCC and verifying
  relocation-aware bytecode alignment against the pinned ELF binary (skipped when compiler/wibo are unprovisioned).

The WIP/BIN boundary and registered object list remain unchanged.
