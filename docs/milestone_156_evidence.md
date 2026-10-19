# Milestone 156 Verification & Behavioral Evidence: func_00281A80

Durable record of behavioral derivation, TDD chronology, disassembly analysis, and exact byte verification for Milestone 156 (`func_00281A80` / `func_281A80`).

## 1. ELF Boundaries & Reference Artifacts

- **Target Binary**: PS2 PAL `SLES-50282` (`orig/SLES-50282/AOK.ELF`, SHA-1 `f478e19f2059d52899b691483ef5c7522e30e17c`)
- **Primary Symbol**: `func_00281A80` (alias `func_281A80`)
- **Role**: Action handler for command `"attack-now"`, tail-calling `func_002BFA60(D_4E342C)`
- **VRAM Extent**: `[0x281A80, 0x281A88)` (8 code bytes, 2 instructions)
- **File Offset Extent**: `[0x181C60, 0x181C68)`
- **Alignment Padding**: 8 bytes NOP padding (`0x00000000`, `0x00000000`) at `[0x181C68, 0x181C70)` / `[0x281A88, 0x281A90)`
- **Total Segment Extent**: 16 bytes (`0x10`)
- **Pinned 8-byte Code Slice SHA-1**: `84c86b068b5a6fda1b90c6f75d9fc307afeaecde`
- **Pinned 16-byte Total Slice SHA-1**: `10ebc3c261da80ef92719faefeb8aad768ba0f5d`

### Neighboring Boundaries

- **Predecessor**: `func_002818D0` (Milestone 155), code extent `[0x2818D0, 0x281A80)` (432 bytes). Zero gap.
- **Successor**: Function at VRAM `0x281A90`, extent `[0x281A90, 0x281BBC)` (300 bytes) + 4B NOP padding to `0x281BC0`. Zero gap.

---

## 2. ELF & Disassembly-Derived Behavior Derivation

`func_00281A80` is an 8-byte leaf tail-call forwarder:
- Action Registry: Registered as a function pointer in register `$a3` at VRAM `0x2831C8` / `0x2831CC` inside `TacticalAI2` table initialization (`func_001422F0`), associated with command string `"attack-now"` at `.rodata` address `0x4DBA68`.
- Target Function: Calls `func_002BFA60` at VRAM `0x2BFA60`.
- Target ABI: `void func_002BFA60(void *mgr);` accepts a single pointer argument in `$a0` (preserved into `$s6` via `paddub $s6, $a0, $zero` at `0x2BFA8C`), performs internal processing, and returns `void` without setting `$v0` before `jr $ra` at `0x2BFCC4`.
- Forwarder Behavior: Loads global pointer `D_4E342C` via GP-relative load into `$a0` in the branch delay slot of an unconditional jump `j func_002BFA60`.
- Calling Convention: Does not allocate a stack frame (`#pragma exceptions off` produces leaf tail call optimization `j` instead of `jal`).
- Alias Symbol: `func_281A80` is emitted into a separate homonymous `.text` section of 8 bytes containing `j func_00281A80; nop`.

---

## 3. Durable Behavioral TDD Chronology

### Step 0: Missing-Source Prerequisite Recorded

Before creating the implementation file, running the native test suite resulted in the expected missing-source collection failure:

- **Exact Docker Command**:
  ```sh
  docker --context docker-dev run --rm \
    -v /home/samuelcaldas/source/repos/aoe/.worktrees/unit-action-targets:/workspace \
    -v /home/samuelcaldas/source/repos/aoe:/home/samuelcaldas/source/repos/aoe:ro \
    -w /workspace aoe-tests:verification \
    pytest tests/test_unit_action_build_81a80.py
  ```

- **Observed Missing-Source Output**:
  ```text
  AssertionError: Compilation failed: cc1plus: fatal error: /workspace/src/unit_action_build_81a80.cpp: No such file or directory
  compilation terminated.
  ```

### Step 1: Red (Observed Assertion Failure on Stub in Docker)

Following creation of `include/unit_action_build_81a80.h` and an empty no-op stub in `src/unit_action_build_81a80.cpp`, the native behavioral test failed as expected on the forwarded-call assertion:

- **Exact Docker Red Command**:
  ```sh
  docker --context docker-dev run --rm \
    -v /home/samuelcaldas/source/repos/aoe/.worktrees/unit-action-targets:/workspace \
    -v /home/samuelcaldas/source/repos/aoe:/home/samuelcaldas/source/repos/aoe:ro \
    -w /workspace aoe-tests:verification \
    pytest tests/test_unit_action_build_81a80.py
  ```

- **Observed Failing Assertion Output**:
  ```text
  ============================= test session starts ==============================
  platform linux -- Python 3.14.7, pytest-9.1.1, pluggy-1.7.0
  rootdir: /workspace
  collected 1 item

  tests/test_unit_action_build_81a80.py F                                  [100%]

  =================================== FAILURES ===================================
  __________________________ test_build_818d0_behavior ___________________________

  native_binary = PosixPath('/tmp/pytest-of-root/pytest-0/bin0/unit_action_build_81a80_test')

      def test_build_81a80_behavior(native_binary):
          """Run native behavioral test suite for func_00281A80."""
          res = subprocess.run([str(native_binary)], capture_output=True, text=True)
  >       assert res.returncode == 0, f"Test failed: {res.stderr}\n{res.stdout}"
  E       AssertionError: Test failed: unit_action_build_81a80_test: /workspace/tests/native/unit_action_build_81a80_test.cpp:28: int main(): Assertion `g_func_002BFA60_call_count == 1' failed.
  E
  E
  E       assert -6 == 0
  E        +  where -6 = CompletedProcess(args=['/tmp/pytest-of-root/pytest-0/bin0/unit_action_build_81a80_test'], returncode=-6, stdout='', stderr='unit_action_build_81a80_test: /workspace/tests/native/unit_action_build_81a80_test.cpp:28: int main(): Assertion `g_func_002BFA60_call_count == 1\' failed.\n').returncode

  tests/test_unit_action_build_81a80.py:34: AssertionError
  =========================== short test summary info ============================
  FAILED tests/test_unit_action_build_81a80.py::test_build_81a80_behavior - AssertionError: Test failed
  ============================== 1 failed in 0.29s ===============================
  ```

### Step 2: Green Execution in Docker

Implementing the forwarding call `func_002BFA60(D_4E342C)` in `src/unit_action_build_81a80.cpp` satisfies all assertions:

- **Exact Docker Green Command**:
  ```sh
  docker --context docker-dev run --rm \
    -v /home/samuelcaldas/source/repos/aoe/.worktrees/unit-action-targets:/workspace \
    -v /home/samuelcaldas/source/repos/aoe:/home/samuelcaldas/source/repos/aoe:ro \
    -w /workspace aoe-tests:verification \
    pytest tests/test_unit_action_build_81a80.py
  ```

- **Observed Green Result**:
  ```text
  ============================= test session starts ==============================
  platform linux -- Python 3.14.7, pytest-9.1.1, pluggy-1.7.0
  rootdir: /workspace
  collected 1 item

  tests/test_unit_action_build_81a80.py .                                  [100%]

  ============================== 1 passed in 0.20s ===============================
  ```

- **Behavioral Assertions Verified**:
  - Target function `func_002BFA60` invoked with initial pointer `&g_dummy_mgr`.
  - Mutation of global pointer `D_004E342C = &g_other_mgr` observed on subsequent call.
  - Forwarding behavior verified through alias `func_281A80`.

---

## 4. Full Disassembly & Register Map

### Section 5 (`func_00281A80`)

```asm
0x00 (0x281A80): 0x080AFE98  j 0x2BFA60
0x04 (0x281A84): 0x8F848C6C  lw $a0, -29588($gp)
```

### Section 9 (`func_281A80`)

```asm
0x00: 0x080A06A0  j func_00281A80
0x04: 0x00000000  nop
```

---

## 5. Relocation Manifest & Resolution

### Section 5 Relocations

| Section Offset | Type | Type Name | Target Symbol | Addend | Resolved Value |
|---|---|---|---|---|---|
| `0x00` | 4 | `R_MIPS_26` | `func_002BFA60` | 0 | `0x080AFE98` (`j 0x2BFA60`) |
| `0x04` | 7 | `R_MIPS_GPREL16` | `D_4E342C` | 0 | `0x8F848C6C` (`lw $a0, -29588($gp)`) |

### Section 9 Relocations (Alias)

| Section Offset | Type | Type Name | Target Symbol | Addend | Resolved Value |
|---|---|---|---|---|---|
| `0x00` | 4 | `R_MIPS_26` | `func_00281A80` | 0 | `0x080A06A0` (`j 0x281A80`) |

---

## 6. Standalone Relocation-Aware Verifier Evidence

Execution of `tools/verify_exact_linked_81a80.py`:
```text
=== Milestone 156 (func_00281A80) Relocation-Resolved Byte Equality Verification ===
Target ELF:              orig/SLES-50282/AOK.ELF
File Offset:             0x181C60 (VRAM 0x281A80)
Length:                  8 bytes (2 instructions)
Symbol func_00281A80:  validated at .text offset 0, size 8
Alias func_281A80:       validated at homonymous .text section, size 8, j func_00281A80
Original ELF slice SHA1: 84c86b068b5a6fda1b90c6f75d9fc307afeaecde (enforced exact: 84c86b068b5a6fda1b90c6f75d9fc307afeaecde)
Resolved code slice SHA1:84c86b068b5a6fda1b90c6f75d9fc307afeaecde (enforced exact: 84c86b068b5a6fda1b90c6f75d9fc307afeaecde)
GPREL16 resolved sites:  1 (enforced exact: 1)
  - D_4E342C:            1 (enforced exact: 1)
J resolved sites:        1 (enforced exact: 1)
  - func_002BFA60:       1 (enforced exact: 1)

RESULT: EXACT MATCH! 8 / 8 bytes identical (100.00% byte equality).
All 2 instructions match bit-for-bit against orig/SLES-50282/AOK.ELF.
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
=== Milestone 156 (func_00281A80) Relocation-Resolved Byte Equality Verification ===
RESULT: EXACT MATCH! 8 / 8 bytes identical (100.00% byte equality).

collected 60 items
tests/test_unit_action_build_807d0.py .                                  [  1%]
tests/test_verify_exact_linked_807d0.py ..............                   [ 25%]
tests/test_unit_action_build_81030.py .                                  [ 26%]
tests/test_verify_exact_linked_81030.py ..............                   [ 50%]
tests/test_unit_action_build_818d0.py .                                  [ 51%]
tests/test_verify_exact_linked_818d0.py ..............                   [ 75%]
tests/test_unit_action_build_81a80.py .                                  [ 76%]
tests/test_verify_exact_linked_81a80.py ..............                   [100%]

60 passed in 2.31s
```
Status in `configure.py`: strictly maintained as `NonMatching` pending `aoe-advisor` review and clearance.
Branch `feat/unit-action-build-7c390` remains unmerged.
