# Milestone 158 Verification & Behavioral Evidence: func_00281BC0

Durable record of behavioral derivation, TDD chronology, disassembly analysis, and relocation manifest for Milestone 158 (`func_00281BC0` / `func_281BC0`).

## 1. ELF Boundaries & Reference Artifacts

- **Target Binary**: PS2 PAL `SLES-50282` (`orig/SLES-50282/AOK.ELF`, SHA-1 `f478e19f2059d52899b691483ef5c7522e30e17c`)
- **Primary Symbol**: `func_00281BC0` (alias `func_281BC0`)
- **Role**: Action handler for command `"build-forward"`, registered in `TacticalAI2` initialization (`func_001422F0`) at VRAM `0x283210` with command string `"build-forward"` at `.rodata` `0x4CBA80`.
- **VRAM Extent**: `[0x281BC0, 0x281CE4)` (300 code bytes, 75 instructions)
- **File Offset Extent**: `[0x181DA0, 0x181ECC)`
- **Alignment Padding**: 4 bytes NOP (`0x00000000`) at `[0x181ECC, 0x181ED0)` / `[0x281CE4, 0x281CE8)`
- **Total Segment Extent**: 304 bytes (`0x130`)
- **Pinned 300-byte Code Slice SHA-1**: `36a46bc0abe93c2c25e0722807ebff41198a6225`
- **Pinned 304-byte Total Slice SHA-1**: `ef05c1bc1a4e92e3825465f18278a0ab77a7f481`

### Neighboring Boundaries

- **Predecessor**: `func_00281A90` (Milestone 157, `"build"`), extent `[0x281A90, 0x281BBC)` + 4B NOP padding to `0x281BC0`. Zero gap.
- **Successor**: `func_00281CF0` (Milestone 159, `"build-gate"`), extent `[0x281CF0, ...)`. Zero gap.

---

## 2. ELF & Disassembly-Derived Behavior Derivation

`func_00281BC0` is the primary action handler for the `"build-forward"` command:
- **Action Registry**: Registered at VRAM `0x283210` (`lui $v0, 0x28; addiu $a3, $v0, 0x1BC0; lui $v0, 0x4D; addiu $a1, $v0, -0x4580; addiu $a2, $zero, 0x1; jal func_1422F0`).
- **One-time Initialization Flag (`D_4E3414`)**:
  - Global variable `D_4E3414` (address `0x4E3414`, GP offset `-0x73AC`).
  - When `D_4E3414 == 0`: Sets `D_4E3414 = 1` and runs pre-validation filters (`72, 117, 155, 487, -399`).
  - Preceding equality filter handles `building_id == -399` directly with early return; the subsequent boolean range check `[-399, -397)` therefore exclusively maps `building_id == -398`.
  - When `D_4E3414 != 0`: Branches directly past pre-validation filters.
- **Distinct Dispatch Argument**:
  - Dispatches to `func_00284720(D_4E3424, building_id, 1)` with mode parameter `1` (distinct from `0` in Milestone 157).

---

## 3. Contemporaneous Behavioral TDD Chronology

*Chronology Statement*: Every step below was executed and logged in contemporaneous turns in Docker before proceeding to the next step.

### Step 0: Missing-Source Prerequisite Recorded

- **Exact Docker Command**:
  ```sh
  docker --context docker-dev run --rm \
    -v /home/samuelcaldas/source/repos/aoe/.worktrees/unit-action-targets:/workspace \
    -v /home/samuelcaldas/source/repos/aoe:/home/samuelcaldas/source/repos/aoe:ro \
    -w /workspace aoe-tests:verification \
    pytest tests/test_unit_action_build_81bc0.py
  ```
- **Observed Missing-Source Output**:
  ```text
  AssertionError: Compilation failed: cc1plus: fatal error: /workspace/src/unit_action_build_81bc0.cpp: No such file or directory
  compilation terminated.
  ```

### Step 1: Red on Minimal Stub for Distinct Dispatch Argument (Mode == 1)

Following creation of `include/unit_action_build_81bc0.h` and an empty stub in `src/unit_action_build_81bc0.cpp`:
- **Exact Docker Command**:
  ```sh
  docker --context docker-dev run --rm \
    -v /home/samuelcaldas/source/repos/aoe/.worktrees/unit-action-targets:/workspace \
    -v /home/samuelcaldas/source/repos/aoe:/home/samuelcaldas/source/repos/aoe:ro \
    -w /workspace aoe-tests:verification \
    pytest tests/test_unit_action_build_81bc0.py
  ```
- **Observed Failing Assertion**:
  ```text
  AssertionError: Test failed: unit_action_build_81bc0_test: /workspace/tests/native/unit_action_build_81bc0_test.cpp:34: int main(): Assertion `g_func_00284720_calls == 1' failed.
  FAILED tests/test_unit_action_build_81bc0.py::test_build_81bc0_dispatch_argument (1 failed in 0.25s)
  ```

### Step 2: Green on Minimal Dispatch (`func_00284720(..., 1)`)

- Implemented minimal dispatch: `func_00284720(D_4E3424, building_id, 1);`
- **Observed Green Result**: `1 passed in 0.15s`.

### Step 3: Red on Guarded Flag Initialization (`D_4E3414 == 1`)

- Added assertion `assert(D_4E3414 == 1);` when `D_4E3414 == 0` on entry.
- **Observed Failing Assertion**:
  ```text
  AssertionError: Test failed: unit_action_build_81bc0_test: /workspace/tests/native/unit_action_build_81bc0_test.cpp:56: int main(): Assertion `D_4E3414 == 1' failed.
  FAILED tests/test_unit_action_build_81bc0.py::test_build_81bc0_dispatch_argument (1 failed in 0.25s)
  ```

### Step 4: Green on Guarded Flag Initialization

- Implemented `if (!D_4E3414) { D_4E3414 = 1; }`
- **Observed Green Result**: `1 passed in 0.15s`.

### Step 5: Red on Filter ID 72

- Added Test 3: `func_00281BC0(72)` with `D_4E3414 == 0` asserts `assert(g_func_00284720_calls == 0);`.
- **Observed Failing Assertion**:
  ```text
  AssertionError: Test failed: unit_action_build_81bc0_test: /workspace/tests/native/unit_action_build_81bc0_test.cpp:64: int main(): Assertion `g_func_00284720_calls == 0' failed.
  FAILED tests/test_unit_action_build_81bc0.py::test_build_81bc0_dispatch_argument (1 failed in 0.25s)
  ```

### Step 6: Green on Filter ID 72

- Implemented `if (building_id == 72) return;`
- **Observed Green Result**: `1 passed in 0.15s`.

### Step 7: Red on Filter ID 117

- Added Test 4: `func_00281BC0(117)` with `D_4E3414 == 0` asserts `assert(g_func_00284720_calls == 0);`.
- **Observed Failing Assertion**:
  ```text
  AssertionError: Test failed: unit_action_build_81bc0_test: /workspace/tests/native/unit_action_build_81bc0_test.cpp:76: int main(): Assertion `g_func_00284720_calls == 0' failed.
  FAILED tests/test_unit_action_build_81bc0.py::test_build_81bc0_dispatch_argument (1 failed in 0.25s)
  ```

### Step 8: Green on Filter ID 117

- Implemented `if (building_id == 117) return;`
- **Observed Green Result**: `1 passed in 0.17s`.

### Step 9: Red on Filter ID 155

- Added Test 5: `func_00281BC0(155)` with `D_4E3414 == 0` asserts `assert(g_func_00284720_calls == 0);`.
- **Observed Failing Assertion**:
  ```text
  AssertionError: Test failed: unit_action_build_81bc0_test: /workspace/tests/native/unit_action_build_81bc0_test.cpp:88: int main(): Assertion `g_func_00284720_calls == 0' failed.
  FAILED tests/test_unit_action_build_81bc0.py::test_build_81bc0_dispatch_argument (1 failed in 0.26s)
  ```

### Step 10: Green on Filter ID 155

- Implemented `if (building_id == 155) return;`
- **Observed Green Result**: `1 passed in 0.23s`.

### Step 11: Red on Filter ID 487

- Added Test 6: `func_00281BC0(487)` with `D_4E3414 == 0` asserts `assert(g_func_00284720_calls == 0);`.
- **Observed Failing Assertion**:
  ```text
  AssertionError: Test failed: unit_action_build_81bc0_test: /workspace/tests/native/unit_action_build_81bc0_test.cpp:100: int main(): Assertion `g_func_00284720_calls == 0' failed.
  FAILED tests/test_unit_action_build_81bc0.py::test_build_81bc0_dispatch_argument (1 failed in 0.29s)
  ```

### Step 12: Green on Filter ID 487

- Implemented `if (building_id == 487) return;`
- **Observed Green Result**: `1 passed in 0.19s`.

### Step 13: Red on Filter ID -399

- Added Test 7: `func_00281BC0(-399)` with `D_4E3414 == 0` asserts `assert(g_func_00284720_calls == 0);`.
- **Observed Failing Assertion**:
  ```text
  AssertionError: Test failed: unit_action_build_81bc0_test: /workspace/tests/native/unit_action_build_81bc0_test.cpp:112: int main(): Assertion `g_func_00284720_calls == 0' failed.
  FAILED tests/test_unit_action_build_81bc0.py::test_build_81bc0_dispatch_argument (1 failed in 0.28s)
  ```

### Step 14: Green on Filter ID -399

- Implemented `if (building_id == -399) return;`
- **Observed Green Result**: `1 passed in 0.25s`.

### Step 15: Characterization Test for Pre-Initialized Flag (`D_4E3414 == 1`)

- Added Test 8: `func_00281BC0(72)` with `D_4E3414 == 1` asserts that pre-validation filters are bypassed and `func_00284720(D_4E3424, 72, 1)` is called directly.
- **Observed Characterization Result**: `1 passed in 0.20s`.

### Step 16: Red on Mapped-Success Path with Full ABI Assertions

- Added Test 10: `func_00281BC0(-398)` with `func_00298880` returning `500` asserting `func_00203010` is skipped and `func_002E01E0` is called with full audited ABI arguments: `(D_4E3420, (short)500, 0, 1, 1, 1, 1.0f)`.
- **Observed Failing Assertion**:
  ```text
  AssertionError: Test failed: unit_action_build_81bc0_test: /workspace/tests/native/unit_action_build_81bc0_test.cpp:227: int main(): Assertion `g_func_002E01E0_calls == 1' failed.
  FAILED tests/test_unit_action_build_81bc0.py::test_build_81bc0_dispatch_argument (1 failed in 0.47s)
  ```

### Step 17: Green on Mapped-Success Path

- Implemented mapped-success branch: when `func_00298880` returns != -1, calls `func_002E01E0` with exact audited arguments and skips `func_00203010`.
- **Observed Green Result**: `1 passed in 0.37s`.

### Step 18: Red on func_00297C20 Resolution Call with -1 Return

- Added Test 11: on `func_002E01E0` returning 1, calls `func_00297C20(D_4E3428, building_id)` returning -1. Asserts exact arguments, call order (`2E01E0` before `297C20`), and that `func_00298100` and `func_00284720` are not called.
- **Observed Failing Assertion**:
  ```text
  AssertionError: Test failed: unit_action_build_81bc0_test: /workspace/tests/native/unit_action_build_81bc0_test.cpp:300: int main(): Assertion `g_func_00297C20_calls == 1' failed.
  FAILED tests/test_unit_action_build_81bc0.py::test_build_81bc0_dispatch_argument (1 failed in 0.47s)
  ```

### Step 19: Green on func_00297C20 Resolution & -1 Early Exit

- Implemented: `int id = func_00297C20(D_4E3428, building_id); if (id == -1) return;`
- **Observed Green Result**: `1 passed in 0.32s`.

### Step 20: Red on func_00298100 Resolution and Return Value Dispatch

- Added Test 12: when `func_00297C20` returns a valid id (42), `func_00298100(D_4E3428, 42)` must be called, and its return value (999, not `building_id` 100) must be passed as `$a1` to `func_00284720(D_4E3424, 999, 1)`. Asserts exact arguments and strict call order (`297C20 -> 298100 -> 284720`).
- **Observed Failing Assertion**:
  ```text
  AssertionError: Test failed: unit_action_build_81bc0_test: /workspace/tests/native/unit_action_build_81bc0_test.cpp:351: int main(): Assertion `g_func_00298100_calls == 1' failed.
  FAILED tests/test_unit_action_build_81bc0.py::test_build_81bc0_dispatch_argument (1 failed in 0.61s)
  ```

### Step 21: Green on func_00298100 Resolution and Return Value Dispatch

- Implemented: `building_id = func_00298100(D_4E3428, id); func_00284720(D_4E3424, building_id, 1);`
- **Observed Green Result**: `1 passed in 0.47s`.
- Subsystem verification: all 333 tests in `pytest tests/test_unit_action_build_*.py tests/test_verify_exact_linked_*.py` passed in 29.81s.

### Step 22: Red on Unmapped Validation Path (func_00203010 Calling and Early Return on 0)

- Added Test 13: for unmapped building ID (`50`) with `D_4E3414 == 0`, when not in range `[-399, -397)`, `func_00203010(D_4E3420, 50)` must be called. When `func_00203010` returns `0`, execution must early return without downstream validation (`func_002E01E0`), resolution, or dispatch.
- **Observed Failing Assertion**:
  ```text
  AssertionError: Test failed: unit_action_build_81bc0_test: /workspace/tests/native/unit_action_build_81bc0_test.cpp:403: int main(): Assertion `g_func_00203010_calls == 1' failed.
  FAILED tests/test_unit_action_build_81bc0.py::test_build_81bc0_dispatch_argument (1 failed in 1.46s)
  ```

---

## 4. Full Disassembly & Register Map

```asm
0x000 (0x281BC0): 0x27BDFFE0  addiu       $sp, $sp, -0x20
0x004 (0x281BC4): 0x7FBF0010  sq          $ra, 0x10($sp)
0x008 (0x281BC8): 0x7FB00000  sq          $s0, 0x0($sp)
0x00C (0x281BCC): 0x8F838C54  lw          $v1, -0x73AC($gp)
0x010 (0x281BD0): 0x14600042  bnez        $v1, . + 4 + (0x42 << 2)
0x014 (0x281BD4): 0x70808628  paddub      $s0, $a0, $zero
0x018 (0x281BD8): 0x24030001  addiu       $v1, $zero, 0x1
0x01C (0x281BDC): 0xAF838C54  sw          $v1, -0x73AC($gp)
0x020 (0x281BE0): 0x24030048  addiu       $v1, $zero, 0x48
0x024 (0x281BE4): 0x1203003D  beq         $s0, $v1, . + 4 + (0x3D << 2)
0x028 (0x281BE8): 0x00000000  nop
0x02C (0x281BEC): 0x24030075  addiu       $v1, $zero, 0x75
0x030 (0x281BF0): 0x1203003A  beq         $s0, $v1, . + 4 + (0x3A << 2)
0x034 (0x281BF4): 0x00000000  nop
0x038 (0x281BF8): 0x2403009B  addiu       $v1, $zero, 0x9B
0x03C (0x281BFC): 0x12030037  beq         $s0, $v1, . + 4 + (0x37 << 2)
0x040 (0x281C00): 0x00000000  nop
0x044 (0x281C04): 0x240301E7  addiu       $v1, $zero, 0x1E7
0x048 (0x281C08): 0x12030034  beq         $s0, $v1, . + 4 + (0x34 << 2)
0x04C (0x281C0C): 0x00000000  nop
0x050 (0x281C10): 0x2403FE71  addiu       $v1, $zero, -0x18F
0x054 (0x281C14): 0x12030031  beq         $s0, $v1, . + 4 + (0x31 << 2)
0x058 (0x281C18): 0x00000000  nop
0x05C (0x281C1C): 0x2A02FE73  slti        $v0, $s0, -0x18D
0x060 (0x281C20): 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
0x064 (0x281C24): 0x304200FF  andi        $v0, $v0, 0xFF
0x068 (0x281C28): 0x2A02FE71  slti        $v0, $s0, -0x18F
0x06C (0x281C2C): 0x38420001  xori        $v0, $v0, 0x1
0x070 (0x281C30): 0x304200FF  andi        $v0, $v0, 0xFF
0x074 (0x281C34): 0x1040000A  beqz        $v0, . + 4 + (0xA << 2)
0x078 (0x281C38): 0x00000000  nop
0x07C (0x281C3C): 0x8F848C68  lw          $a0, -0x7398($gp)
0x080 (0x281C40): 0x0C0A6220  jal         func_298880
0x084 (0x281C44): 0x72002E28  paddub      $a1, $s0, $zero
0x088 (0x281C48): 0x2403FFFF  addiu       $v1, $zero, -0x1
0x08C (0x281C4C): 0x70408628  paddub      $s0, $v0, $zero
0x090 (0x281C50): 0x16030008  bne         $s0, $v1, . + 4 + (0x8 << 2)
0x094 (0x281C54): 0x00000000  nop
0x098 (0x281C58): 0x10000021  b           . + 4 + (0x21 << 2)
0x09C (0x281C5C): 0x7BBF0010  lq          $ra, 0x10($sp)
0x0A0 (0x281C60): 0x8F848C60  lw          $a0, -0x73A0($gp)
0x0A4 (0x281C64): 0x0C080C04  jal         func_203010
0x0A8 (0x281C68): 0x72002E28  paddub      $a1, $s0, $zero
0x0AC (0x281C6C): 0x1040001B  beqz        $v0, . + 4 + (0x1B << 2)
0x0B0 (0x281C70): 0x00000000  nop
0x0B4 (0x281C74): 0x8F848C60  lw          $a0, -0x73A0($gp)
0x0B8 (0x281C78): 0x24070001  addiu       $a3, $zero, 0x1
0x0BC (0x281C7C): 0x3C023F80  lui         $v0, 0x3F80
0x0C0 (0x281C80): 0x00102C3C  dsll32      $a1, $s0, 16
0x0C4 (0x281C84): 0x44826000  mtc1        $v0, $f12
0x0C8 (0x281C88): 0x00052C3F  dsra32      $a1, $a1, 16
0x0CC (0x281C8C): 0x70003628  paddub      $a2, $zero, $zero
0x0D0 (0x281C90): 0x70E04628  paddub      $t0, $a3, $zero
0x0D4 (0x281C94): 0x0C0B8078  jal         func_2E01E0
0x0D8 (0x281C98): 0x70E04E28  paddub      $t1, $a3, $zero
0x0DC (0x281C9C): 0x1040000F  beqz        $v0, . + 4 + (0xF << 2)
0x0E0 (0x281CA0): 0x00000000  nop
0x0E4 (0x281CA4): 0x8F848C68  lw          $a0, -0x7398($gp)
0x0E8 (0x281CA8): 0x0C0A5F08  jal         func_297C20
0x0EC (0x281CAC): 0x72002E28  paddub      $a1, $s0, $zero
0x0F0 (0x281CB0): 0x2403FFFF  addiu       $v1, $zero, -0x1
0x0F4 (0x281CB4): 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
0x0F8 (0x281CB8): 0x00000000  nop
0x0FC (0x281CBC): 0x8F848C68  lw          $a0, -0x7398($gp)
0x100 (0x281CC0): 0x0C0A6040  jal         func_298100
0x104 (0x281CC4): 0x70402E28  paddub      $a1, $v0, $zero
0x108 (0x281CC8): 0x70408628  paddub      $s0, $v0, $zero
0x10C (0x281CCC): 0x8F848C64  lw          $a0, -0x739C($gp)
0x110 (0x281CD0): 0x24060001  addiu       $a2, $zero, 0x1
0x114 (0x281CD4): 0x0C0A11C8  jal         func_284720
0x118 (0x281CD8): 0x72002E28  paddub      $a1, $s0, $zero
0x11C (0x281CDC): 0x7BBF0010  lq          $ra, 0x10($sp)
0x120 (0x281CE0): 0x7BB00000  lq          $s0, 0x0($sp)
0x124 (0x281CE4): 0x03E00008  jr          $ra
0x128 (0x281CE8): 0x27BD0020  addiu       $sp, $sp, 0x20
```

---

## 5. Relocation Manifest & Resolution

| Section Offset | Type | Type Name | Target Symbol | Addend | Resolved Value |
|---|---|---|---|---|---|
| `0x00C` | 7 | `R_MIPS_GPREL16` | `D_4E3414` | 0 | `0x8F838C54` (`lw $v1, -29612($gp)`) |
| `0x01C` | 7 | `R_MIPS_GPREL16` | `D_4E3414` | 0 | `0xAF838C54` (`sw $v1, -29612($gp)`) |
| `0x07C` | 7 | `R_MIPS_GPREL16` | `D_4E3428` | 0 | `0x8F848C68` (`lw $a0, -29592($gp)`) |
| `0x080` | 4 | `R_MIPS_26` | `func_00298880` | 0 | `0x0C0A6220` (`jal func_298880`) |
| `0x0A0` | 7 | `R_MIPS_GPREL16` | `D_4E3420` | 0 | `0x8F848C60` (`lw $a0, -29600($gp)`) |
| `0x0A4` | 4 | `R_MIPS_26` | `func_00203010` | 0 | `0x0C080C04` (`jal func_203010`) |
| `0x0B4` | 7 | `R_MIPS_GPREL16` | `D_4E3420` | 0 | `0x8F848C60` (`lw $a0, -29600($gp)`) |
| `0x0D4` | 4 | `R_MIPS_26` | `func_002E01E0` | 0 | `0x0C0B8078` (`jal func_2E01E0`) |
| `0x0E4` | 7 | `R_MIPS_GPREL16` | `D_4E3428` | 0 | `0x8F848C68` (`lw $a0, -29592($gp)`) |
| `0x0E8` | 4 | `R_MIPS_26` | `func_00297C20` | 0 | `0x0C0A5F08` (`jal func_297C20`) |
| `0x0FC` | 7 | `R_MIPS_GPREL16` | `D_4E3428` | 0 | `0x8F848C68` (`lw $a0, -29592($gp)`) |
| `0x100` | 4 | `R_MIPS_26` | `func_00298100` | 0 | `0x0C0A6040` (`jal func_298100`) |
| `0x10C` | 7 | `R_MIPS_GPREL16` | `D_4E3424` | 0 | `0x8F848C64` (`lw $a0, -29596($gp)`) |
| `0x114` | 4 | `R_MIPS_26` | `func_00284720` | 0 | `0x0C0A11C8` (`jal func_284720`) |

---

## 6. Dual-Mount Container Verification & Regression Gate

Ran in container `aoe-tests:verification` with dual mounts:

```text
============================= test session starts ==============================
platform linux -- Python 3.14.7, pytest-9.1.1, pluggy-1.7.0
rootdir: /workspace
collected 333 items

tests/test_unit_action_build_77a0.py .                                   [  0%]
...
tests/test_unit_action_build_81a90.py .........                          [ 30%]
tests/test_unit_action_build_81bc0.py .                                  [ 30%]
...
tests/test_verify_exact_linked_81a80.py ..............                   [100%]

============================= 333 passed in 31.51s =============================
```

Status: Maintained strictly as `NonMatching`.
Configuration and symbols files remain untouched.
Branch `feat/unit-action-build-7c390` remains unmerged.
