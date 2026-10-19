# Milestone 155 Verification & Behavioral Evidence: func_002818D0

Durable record of behavioral derivation, TDD chronology, disassembly analysis, and exact byte verification for Milestone 155 (`func_002818D0` / `func_2818D0`).

## 1. ELF Boundaries & Reference Artifacts

- **Target Binary**: PS2 PAL `SLES-50282` (`orig/SLES-50282/AOK.ELF`, SHA-1 `f478e19f2059d52899b691483ef5c7522e30e17c`)
- **Primary Symbol**: `func_002818D0` (alias `func_2818D0`)
- **Role**: Re-entrant dual-role query dispatcher and callback bitmask updater
- **VRAM Extent**: `[0x2818D0, 0x281A80)` (432 code bytes, 108 instructions)
- **File Offset Extent**: `[0x181AB0, 0x181C60)`
- **Alignment Padding**: 0 bytes (the function ends at `0x281A80`, which is 16-byte aligned; the successor function begins immediately)
- **Total Segment Extent**: 432 bytes (`0x1B0`)
- **Pinned 432-byte Code Slice SHA-1**: `c22ee798b95b114d8ba50e6b1c47c257248e5c87`

### Neighboring Boundaries

- **Predecessor**: `func_00281030` (Milestone 154), code extent `[0x281030, 0x2818D0)` (2208 bytes). Zero gap.
- **Successor**: Function at VRAM `0x281A80` (file offset `0x181C60`), beginning with `addiu $sp, $sp, -0x30`. Zero gap.

---

## 2. ELF & Disassembly-Derived Behavior Derivation

`func_002818D0` implements a dual-role action dispatcher and callback receiver:
- `$a0`: `int code_or_id`
- `$a1`: `void *param`

It allocates a `0x40`-byte stack frame (`addiu $sp, $sp, -64`), preserving 4 callee-saved registers (`$ra` at 48($sp), `$s2` at 32($sp), `$s1` at 16($sp), `$s0` at 0($sp)).

### Dual-Role Architecture

1. **Dispatcher Role (Negative Query Codes in `[-205, -100]`)**:
   - Condition: `code_or_id < -100 && code_or_id >= -205`.
   - Action: Delegates to `func_002807D0(code_or_id, (void (*)(int, void *))func_002818D0, param)`.
   - Returns immediately after delegation.

2. **Callback Receiver / Action ID Mapper Role (Codes 101 to 111)**:
   - Condition: `code_or_id >= 101 && code_or_id < 112`.
   - Dispatches via 11-entry jump table located in `.rodata` at `0x4CB960` (`@38`).
   - Maps `code_or_id` to index `v1 = code_or_id - 101` (`0 .. 10`).
   - Reads `D_00D90160[v1].field_4`.
   - Validates:
     - `field_4 != -1`
     - `field_4 == func_00141470(D_4E341C)`
   - If validation fails, sets `code_or_id = -1` and returns immediately.
   - If validation passes, reads `code_or_id = D_00D90160[v1].field_0`.
   - If mapped `code_or_id == -1`, returns immediately.

3. **Bitmask Clear Role (Direct or Mapped Action IDs)**:
   - Evaluates `param` (`$s1`).
   - Condition: `param > 0 && param <= 256`.
   - Reads active table ID: `active_id = ((Table2 *)D_4E3420)->active_id` (at offset `+2976` / `0xBA0`).
   - Calculates byte offset into spatial bitmask array: `offset = (active_id << 8) + param`.
   - Clears bit `(code_or_id - 1)`:
     ```cpp
     int mask = ~(1 << (code_or_id - 1));
     D_00D8F45F[(active_id << 8) + p] &= mask;
     ```

4. **Alias Symbol `func_2818D0` Evidence**:
   - **Original Binary Identification**:
     In `config/SLES-50282/symbols.txt`:
     ```text
     func_002818D0 = 0x2818D0; // type:func size:0x1B0 absolute:True
     func_2818D0 = 0x2818D0; // type:func absolute:True
     ```
     Both symbols map to the identical entry address `0x2818D0`.
   - **Compiled Object Verification**:
     In `build/SLES-50282/src/unit_action_build_818d0.o`:
     - Section 11 is a homonymous `.text` section of 8 bytes containing symbol `func_2818D0` (symbol 11, size 8, `st_shndx = 11`, `st_value = 0`).
     - Unlinked instruction words:
       `0x00: 0x08000000` (MIPS `j` opcode 2)
       `0x04: 0x00000000` (`nop`)
     - Section 12 is `.rel.text` linked to Section 11 (`sh_info = 11`), with 1 relocation:
       `offset = 0`, `type = 4 (R_MIPS_26)`, `symbol = func_002818D0`.
     - Resolved linked instructions with target `func_002818D0` at `0x2818D0`:
       `target = (0x2818D0 >> 2) & 0x03FFFFFF = 0x0A0634`
       `0x00: 0x080A0634` (`j 0x2818D0`)
       `0x04: 0x00000000` (`nop`)
     - Emits pure leaf tail-call forwarding without stack frame allocation (`#pragma exceptions off`).

---

## 3. Durable Behavioral TDD Chronology

### Step 1: Red (Observed Assertion Failure on Test Double)

- **Exact Red Command**:
  ```sh
  .venv/bin/pytest tests/test_unit_action_build_818d0.py
  ```
- **Observed Assertion Failure Log**:
  ```text
  ============================= test session starts ==============================
  platform linux -- Python 3.14.4, pytest-9.1.1, pluggy-1.6.0
  rootdir: /home/samuelcaldas/source/repos/aoe/.worktrees/unit-action-targets
  collected 1 item

  tests/test_unit_action_build_818d0.py F                                  [100%]

  =================================== FAILURES ===================================
  __________________________ test_build_818d0_behavior ___________________________

  native_binary = PosixPath('/tmp/pytest-of-samuelcaldas/pytest-698/bin0/unit_action_build_818d0_test')

      def test_build_818d0_behavior(native_binary):
          """Run native behavioral test suite for func_002818D0."""
          res = subprocess.run([str(native_binary)], capture_output=True, text=True)
  >       assert res.returncode == 0, f"Test failed: {res.stderr}\n{res.stdout}"
  E       AssertionError: Test failed: unit_action_build_818d0_test: /home/samuelcaldas/source/repos/aoe/.worktrees/unit-action-targets/tests/native/unit_action_build_818d0_test.cpp:67: void test_delegation_path(): Assertion `g_delegations.size() == 1' failed.
  E         
  E         
  E       assert -6 == 0
  E        +  where -6 = CompletedProcess(args=['/tmp/pytest-of-samuelcaldas/pytest-698/bin0/unit_action_build_818d0_test'], returncode=-6, stdout='', stderr='unit_action_build_818d0_test: /home/samuelcaldas/source/repos/aoe/.worktrees/unit-action-targets/tests/native/unit_action_build_818d0_test.cpp:67: void test_delegation_path(): Assertion `g_delegations.size() == 1\' failed.\n').returncode

  tests/test_unit_action_build_818d0.py:34: AssertionError
  =========================== short test summary info ============================
  FAILED tests/test_unit_action_build_818d0.py::test_build_818d0_behavior - AssertionError: Test failed
  ============================== 1 failed in 1.33s ===============================
  ```

### Step 2: Green (Implemented Pure C++ Behavior)

- **Exact Green Command**:
  ```sh
  .venv/bin/pytest tests/test_unit_action_build_818d0.py
  ```
- **Observed Green Result**:
  ```text
  ============================= test session starts ==============================
  platform linux -- Python 3.14.4, pytest-9.1.1, pluggy-1.6.0
  rootdir: /home/samuelcaldas/source/repos/aoe/.worktrees/unit-action-targets
  collected 1 item

  tests/test_unit_action_build_818d0.py .                                  [100%]

  ============================== 1 passed in 0.21s ===============================
  ```
- **Behavioral Coverage**:
  - Delegation of all boundary and intermediate negative query codes `[-205, -100]` with exact arguments `(code_or_id, func_002818D0, param)`.
  - Rejection of out-of-range negative codes (`-99`, `-206`).
  - Validation of all 11 jump table cases (101 to 111).
  - Validation of BSS structure field mismatch and match gating.
  - Validation of bitmask clearance for direct IDs (1 to 100) and mapped IDs.
  - Parameter boundaries: `p <= 0` (no op), `p == 1` (clears bit), `p == 256` (clears bit), `p > 256` (no op).
  - Active ID row stride: `(active_id << 8) + p`.
  - Full delegation, direct bitmask, and mapped bitmask coverage verified through alias `func_2818D0`.

---

## 4. Full Disassembly & Register Map

### Register Allocations

| Register | Role | Lifetime | Preservation |
|---|---|---|---|
| `$a0` | `code_or_id` / helper argument | Function start, switch index, mapped code | Caller-saved |
| `$a1` | `param` / callback arg 1 | Function start | Caller-saved |
| `$s0` | Scaled index (`v1 * 8`) | During BSS table lookup | `sq $s0, 0($sp)` / `lq $s0, 0($sp)` |
| `$s1` | Preserved `param` pointer | Across helper calls | `sq $s1, 16($sp)` / `lq $s1, 16($sp)` |
| `$s2` | `D_00D90160[v1].field_4` | Across `func_00141470` call | `sq $s2, 32($sp)` / `lq $s2, 32($sp)` |
| `$ra` | Return address | Across `jal` calls | `sq $ra, 48($sp)` / `lq $ra, 48($sp)` |
| `$v1` | Condition evaluations / switch index | Temporary | Ephemeral |
| `$at` | Assembler temporary (`slti $at, $s1, 257`) | Parameter upper bound check | Ephemeral |

---

## 5. Relocation Manifest & Resolution

14 relocation sites in Section 7 (`.text`), 11 relocation sites in Section 5 (`.rodata`), 1 relocation site in Section 12 for Section 11 (`.text` alias).

### Section 7 Relocation Manifest

| Section Offset | Type | Type Name | Target Symbol | Expected Addend | Expected Target VRAM |
|---|---|---|---|---|---|
| `0x034` | 5 | `R_MIPS_HI16` | `func_002818D0` | 0 | `0x2818D0` |
| `0x038` | 6 | `R_MIPS_LO16` | `func_002818D0` | 0 | `0x2818D0` |
| `0x03C` | 4 | `R_MIPS_26` | `func_002807D0` | 0 | `0x2807D0` |
| `0x074` | 5 | `R_MIPS_HI16` | `@38` (jumptable) | 0 | `0x4CB960` |
| `0x078` | 6 | `R_MIPS_LO16` | `@38` (jumptable) | 0 | `0x4CB960` |
| `0x0F8` | 5 | `R_MIPS_HI16` | `D_00D90160` | 0 | `0xD90160` |
| `0x0FC` | 6 | `R_MIPS_LO16` | `D_00D90160` | 4 | `0xD90164` |
| `0x114` | 4 | `R_MIPS_26` | `func_00141470` | 0 | `0x141470` |
| `0x118` | 7 | `R_MIPS_GPREL16` | `D_4E341C` | 0 | `0x4E341C` |
| `0x120` | 5 | `R_MIPS_HI16` | `D_00D90160` | 0 | `0xD90160` |
| `0x130` | 6 | `R_MIPS_LO16` | `D_00D90160` | 0 | `0xD90160` |
| `0x164` | 7 | `R_MIPS_GPREL16` | `D_4E3420` | 0 | `0x4E3420` |
| `0x174` | 5 | `R_MIPS_HI16` | `D_00D8F45F` | 0 | `0xD8F45F` |
| `0x17C` | 6 | `R_MIPS_LO16` | `D_00D8F45F` | 0 | `0xD8F45F` |

### Section 5 (.rodata) Jump Table Entries

11 entries of 4 bytes each (44 bytes total) pointing to switch target addresses:
- `JT[0]`: `func_002818D0 + 0x090` = `0x281960` (Case 101)
- `JT[1]`: `func_002818D0 + 0x098` = `0x281968` (Case 102)
- `JT[2]`: `func_002818D0 + 0x0A0` = `0x281970` (Case 103)
- `JT[3]`: `func_002818D0 + 0x0A8` = `0x281978` (Case 104)
- `JT[4]`: `func_002818D0 + 0x0B0` = `0x281980` (Case 105)
- `JT[5]`: `func_002818D0 + 0x0B8` = `0x281988` (Case 106)
- `JT[6]`: `func_002818D0 + 0x0C0` = `0x281990` (Case 107)
- `JT[7]`: `func_002818D0 + 0x0C8` = `0x281998` (Case 108)
- `JT[8]`: `func_002818D0 + 0x0D0` = `0x2819A0` (Case 109)
- `JT[9]`: `func_002818D0 + 0x0D8` = `0x2819A8` (Case 110)
- `JT[10]`: `func_002818D0 + 0x0E0` = `0x2819B0` (Case 111)

---

## 6. Standalone Relocation-Aware Verifier Evidence

Execution of `tools/verify_exact_linked_818d0.py`:
```text
=== Milestone 155 (func_002818D0) Relocation-Resolved Byte Equality Verification ===
Target ELF:              orig/SLES-50282/AOK.ELF
File Offset:             0x181AB0 (VRAM 0x2818D0)
Length:                  432 bytes (108 instructions)
Symbol func_002818D0:  validated at .text offset 0, size 432
Alias func_2818D0:       validated at homonymous .text section, size 8, j func_002818D0
Original ELF slice SHA1: c22ee798b95b114d8ba50e6b1c47c257248e5c87 (enforced exact: c22ee798b95b114d8ba50e6b1c47c257248e5c87)
Resolved code slice SHA1:c22ee798b95b114d8ba50e6b1c47c257248e5c87 (enforced exact: c22ee798b95b114d8ba50e6b1c47c257248e5c87)
GPREL16 resolved sites:  2 (enforced exact: 2)
  - D_4E341C:            1 (enforced exact: 1)
  - D_4E3420:            1 (enforced exact: 1)
JAL resolved sites:      2 (enforced exact: 2)
  - func_002807D0:       1 (enforced exact: 1)
  - func_00141470:       1 (enforced exact: 1)
HI16 resolved sites:     5 (enforced exact: 5)
LO16 resolved sites:     5 (enforced exact: 5)
  - func_002818D0:       2 (enforced exact: 2)
  - @38 (jumptable):     2 (enforced exact: 2)
  - D_00D90160:          4 (enforced exact: 4)
  - D_00D8F45F:          2 (enforced exact: 2)
.rodata jumptable:       11 entries validated at 0x4CB960

RESULT: EXACT MATCH! 432 / 432 bytes identical (100.00% byte equality).
All 108 instructions match bit-for-bit against orig/SLES-50282/AOK.ELF.
```

---

## 7. Dual-Mount Container Verification & Regression Gate

Ran in container `aoe-tests:verification` with dual mounts:
```text
=== Milestone 153 (func_002807D0) Relocation-Resolved Byte Equality Verification ===
RESULT: EXACT MATCH! 2132 / 2132 bytes identical (100.00% byte equality).
=== Milestone 154 (func_00281030) Relocation-Resolved Byte Equality Verification ===
RESULT: EXACT MATCH! 2208 / 2208 bytes identical (100.00% byte equality).
=== Milestone 155 (func_002818D0) Relocation-Resolved Byte Equality Verification ===
RESULT: EXACT MATCH! 432 / 432 bytes identical (100.00% byte equality).

collected 45 items
tests/test_unit_action_build_807d0.py .                                  [  2%]
tests/test_verify_exact_linked_807d0.py ..............                   [ 33%]
tests/test_unit_action_build_81030.py .                                  [ 35%]
tests/test_verify_exact_linked_81030.py ..............                   [ 66%]
tests/test_unit_action_build_818d0.py .                                  [ 68%]
tests/test_verify_exact_linked_818d0.py ..............                   [100%]

45 passed in 2.18s
```
Status in `configure.py`: strictly maintained as `NonMatching` pending `aoe-advisor` review and clearance.
Branch `feat/unit-action-build-7c390` remains unmerged.
