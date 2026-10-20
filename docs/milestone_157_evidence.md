# Milestone 157 Verification & Behavioral Evidence: func_00281A90

Durable record of behavioral derivation, TDD chronology, disassembly analysis, and relocation manifest for Milestone 157 (`func_00281A90` / `func_281A90`).

## 1. ELF Boundaries & Reference Artifacts

- **Target Binary**: PS2 PAL `SLES-50282` (`orig/SLES-50282/AOK.ELF`, SHA-1 `f478e19f2059d52899b691483ef5c7522e30e17c`)
- **Primary Symbol**: `func_00281A90` (alias `func_281A90`)
- **Role**: Action handler for command `"build"`, registered in `TacticalAI2` initialization (`func_001422F0`) at VRAM `0x2831DC` / `0x2831E0` with command string `"build"` at `.rodata` `0x4CBA78`.
- **VRAM Extent**: `[0x281A90, 0x281BBC)` (300 code bytes, 75 instructions)
- **File Offset Extent**: `[0x181C70, 0x181D9C)`
- **Alignment Padding**: 4 bytes NOP (`0x00000000`) at `[0x181D9C, 0x181DA0)` / `[0x281BBC, 0x281BC0)`
- **Total Segment Extent**: 304 bytes (`0x130`)
- **Pinned 300-byte Code Slice SHA-1**: `fd444479d808a5d951357b3bbe6947eeb69825a4`
- **Pinned 304-byte Total Slice SHA-1**: `2a919b852f4b3c0d2b81f1688ee114d0781240c3`

### Neighboring Boundaries

- **Predecessor**: `func_00281A80` (Milestone 156), extent `[0x281A80, 0x281A88)` + 8B NOP padding to `0x281A90`. Zero gap.
- **Successor**: `func_00281BC0` (action handler for `"build-forward"`), extent `[0x281BC0, ...)`. Zero gap.

---

## 2. ELF & Disassembly-Derived Behavior Derivation

`func_00281A90` is the primary action handler for the `"build"` command:
- **Action Registry**: Registered at VRAM `0x2831DC` (`lui $v0, 0x28; addiu $a3, $v0, 0x1A90; lui $v0, 0x4D; addiu $a1, $v0, -0x4588; addiu $a2, $zero, 0x1; jal func_1422F0`).
- **One-time Initialization Flag (`D_4E3414`)**:
  - Global variable `D_4E3414` (address `0x4E3414`, GP offset `-0x73AC`).
  - When `D_4E3414 == 0`: Sets `D_4E3414 = 1` and runs pre-validation.
  - When `D_4E3414 != 0`: Branches directly to resolution call at `0x281B74` (offset `0x0E4`).
- **Filtered Building IDs**:
  - IDs `72, 117, 155, 487, -399` are rejected on first-time initialization; early return suppresses all downstream calls.
- **Building Mapping Range**:
  - Preceding equality filter handles `building_id == -399` directly with early return; the subsequent boolean range check `[-399, -397)` exclusively maps `building_id == -398` using MWCC boolean idiom `slti; beql; andi; slti; xori; andi; beqz`.
  - Calls `func_00298880(D_4E3428, building_id)`. If returns `-1`, early return.
  - If valid ID returned, skips `func_00203010` and proceeds to `func_002E01E0`.
- **Prerequisite Validation**:
  - Unmapped IDs call `func_00203010(D_4E3420, building_id)`. If returns 0, early return.
  - All valid IDs then call `func_002E01E0(D_4E3420, (short)building_id, 0, 1, 1, 1, 1.0f)`. If returns 0, early return.
- **Action Resolution & Dispatch**:
  - Calls `func_00297C20(D_4E3428, building_id)`. If returns `-1`, early return.
  - Resolves final ID via `building_id = func_00298100(D_4E3428, mapped_id)`.
  - Dispatches via `func_00284720(D_4E3424, building_id, 0)`.

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
    pytest tests/test_unit_action_build_81a90.py
  ```

- **Observed Missing-Source Output**:
  ```text
  AssertionError: Compilation failed: cc1plus: fatal error: /workspace/src/unit_action_build_81a90.cpp: No such file or directory
  compilation terminated.
  ```

### Step 1: Red (Observed Assertion Failure on Stub in Docker)

Following creation of `include/unit_action_build_81a90.h` and an empty stub in `src/unit_action_build_81a90.cpp`:

- **Exact Docker Red Command**:
  ```sh
  docker --context docker-dev run --rm \
    -v /home/samuelcaldas/source/repos/aoe/.worktrees/unit-action-targets:/workspace \
    -v /home/samuelcaldas/source/repos/aoe:/home/samuelcaldas/source/repos/aoe:ro \
    -w /workspace aoe-tests:verification \
    pytest tests/test_unit_action_build_81a90.py
  ```

- **Observed Failing Assertion Output**:
  ```text
  AssertionError: Test failed: unit_action_build_81a90_test: /workspace/tests/native/unit_action_build_81a90_test.cpp:76: int main(): Assertion `D_4E3414 == 1' failed.
  FAILED tests/test_unit_action_build_81a90.py::test_build_81a90_behavior (1 failed in 0.25s)
  ```

### Step 2: Green on Minimal Flag Initialization & Filtered Return

Implementing `D_4E3414 = 1` and filtered ID early return:
- **Exact Docker Command**:
  ```sh
  docker --context docker-dev run --rm \
    -v /home/samuelcaldas/source/repos/aoe/.worktrees/unit-action-targets:/workspace \
    -v /home/samuelcaldas/source/repos/aoe:/home/samuelcaldas/source/repos/aoe:ro \
    -w /workspace aoe-tests:verification \
    pytest tests/test_unit_action_build_81a90.py
  ```
- **Observed Green Result**:
  ```text
  tests/test_unit_action_build_81a90.py .                                  [100%]
  1 passed in 0.15s
  ```

### Steps 3–7: Iterative Branch & Call TDD

Each subsequent call path was verified against native assertions:
- **Step 3 (func_00298880 mapping call on -398)**:
  - Red assertion: `AssertionError: Test failed: unit_action_build_81a90_test: /workspace/tests/native/unit_action_build_81a90_test.cpp:136: int main(): Assertion \`g_func_00298880_calls == 1\' failed.`
  - Green result: `1 passed in 0.16s`.
- **Step 4 (func_00203010 validation call)**:
  - Red assertion: `AssertionError: Test failed: unit_action_build_81a90_test: /workspace/tests/native/unit_action_build_81a90_test.cpp:151: int main(): Assertion \`g_func_00203010_calls == 1\' failed.`
  - Green result: `1 passed in 0.16s`.
- **Step 5 (func_002E01E0 validation call)**:
  - Red assertion: `AssertionError: Test failed: unit_action_build_81a90_test: /workspace/tests/native/unit_action_build_81a90_test.cpp:168: int main(): Assertion \`g_func_002E01E0_calls == 1\' failed.`
  - Green result: `1 passed in 0.16s`.
- **Step 6 (func_00297C20 resolution call)**:
  - Red assertion: `AssertionError: Test failed: unit_action_build_81a90_test: /workspace/tests/native/unit_action_build_81a90_test.cpp:190: int main(): Assertion \`g_func_00297C20_calls == 1\' failed.`
  - Green result: `1 passed in 0.16s`.
- **Step 7 (Full dispatch through func_00298100 and func_00284720)**:
  - Red assertion: `AssertionError: Test failed: unit_action_build_81a90_test: /workspace/tests/native/unit_action_build_81a90_test.cpp:214: int main(): Assertion \`g_func_00298100_calls == 1\' failed.`
  - Green result: `1 passed in 0.16s`.

### Retrospective Comprehensive Branch, Boundary, and Hardened Mutation Suite

*Chronology Disclosure*: Steps 0–2 were conducted under strict contemporaneous test-first execution before implementation. For subsequent branch additions (all 5 filtered IDs, adjacent bounds, flag-state branches, and mutation tests), the steps represent iterative native test expansion; where contemporaneous timestamp sequence cannot be independently verified, reproduction logs are explicitly designated retrospective.

The expanded test harness (`tests/native/unit_action_build_81a90_test.cpp`) validates:
1. **Filtered IDs**: `72, 117, 155, 487, -399` individually assert `D_4E3414 == 1` and 0 downstream calls.
2. **Mapped Range**: `-398` with return `500` asserts `func_00203010` is skipped and `func_002E01E0` receives `500`.
3. **Adjacent Bounds**: `-400` (below) and `-397, -396` (above) assert `func_00298880` is not called and execution falls through to `func_00203010`.
4. **Already-Initialized Flag**: `D_4E3414 == 1` on entry with IDs `72` and `-398` asserts pre-validation is bypassed directly to `func_00297C20`.
5. **Hardened Mutation Suite**: `tests/test_unit_action_build_81a90.py` enforces `assert compile_res.returncode == 0` so compilation failure cannot produce a false pass. All 8 mutations compile cleanly and fail runtime assertions:
   - `no_flag_set`: `D_4E3414 = 1;` removed -> assertion `D_4E3414 == 1` fails.
   - `mutate_filter_72`: ID 72 check mutated to 73 -> filter fails, asserts downstream calls == 0.
   - `mutate_filter_117`: ID 117 check mutated to 118 -> filter fails.
   - `mutate_filter_neg399`: ID -399 check mutated to -400 -> filter fails.
   - `mutate_range_upper`: `< -397` mutated to `< -398` -> range boundary check fails.
   - `skip_validation_1`: `func_00203010` check bypassed (`if (0)`) -> early return check fails.
   - `mutate_ratio`: `1.0f` mutated to `0.5f` -> ratio argument assertion fails.
   - `skip_resolution_check`: `if (id == -1)` bypassed (`if (0)`) -> resolution return assertion fails.

---

## 4. Full Disassembly & Register Map

```asm
0x000 (0x281A90): 0x27BDFFE0  addiu       $sp, $sp, -0x20
0x004 (0x281A94): 0x7FBF0010  sq          $ra, 0x10($sp)
0x008 (0x281A98): 0x7FB00000  sq          $s0, 0x0($sp)
0x00C (0x281A9C): 0x8F838C54  lw          $v1, -0x73AC($gp)
0x010 (0x281AA0): 0x14600042  bnez        $v1, . + 4 + (0x42 << 2)
0x014 (0x281AA4): 0x70808628  paddub      $s0, $a0, $zero
0x018 (0x281AA8): 0x24030001  addiu       $v1, $zero, 0x1
0x01C (0x281AAC): 0xAF838C54  sw          $v1, -0x73AC($gp)
0x020 (0x281AB0): 0x24030048  addiu       $v1, $zero, 0x48
0x024 (0x281AB4): 0x1203003D  beq         $s0, $v1, . + 4 + (0x3D << 2)
0x028 (0x281AB8): 0x00000000  nop
0x02C (0x281ABC): 0x24030075  addiu       $v1, $zero, 0x75
0x030 (0x281AC0): 0x1203003A  beq         $s0, $v1, . + 4 + (0x3A << 2)
0x034 (0x281AC4): 0x00000000  nop
0x038 (0x281AC8): 0x2403009B  addiu       $v1, $zero, 0x9B
0x03C (0x281ACC): 0x12030037  beq         $s0, $v1, . + 4 + (0x37 << 2)
0x040 (0x281AD0): 0x00000000  nop
0x044 (0x281AD4): 0x240301E7  addiu       $v1, $zero, 0x1E7
0x048 (0x281AD8): 0x12030034  beq         $s0, $v1, . + 4 + (0x34 << 2)
0x04C (0x281ADC): 0x00000000  nop
0x050 (0x281AE0): 0x2403FE71  addiu       $v1, $zero, -0x18F
0x054 (0x281AE4): 0x12030031  beq         $s0, $v1, . + 4 + (0x31 << 2)
0x058 (0x281AE8): 0x00000000  nop
0x05C (0x281AEC): 0x2A02FE73  slti        $v0, $s0, -0x18D
0x060 (0x281AF0): 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
0x064 (0x281AF4): 0x304200FF  andi        $v0, $v0, 0xFF
0x068 (0x281AF8): 0x2A02FE71  slti        $v0, $s0, -0x18F
0x06C (0x281AFC): 0x38420001  xori        $v0, $v0, 0x1
0x070 (0x281B00): 0x304200FF  andi        $v0, $v0, 0xFF
0x074 (0x281B04): 0x1040000A  beqz        $v0, . + 4 + (0xA << 2)
0x078 (0x281B08): 0x00000000  nop
0x07C (0x281B0C): 0x8F848C68  lw          $a0, -0x7398($gp)
0x080 (0x281B10): 0x0C0A6220  jal         func_298880
0x084 (0x281B14): 0x72002E28  paddub      $a1, $s0, $zero
0x088 (0x281B18): 0x2403FFFF  addiu       $v1, $zero, -0x1
0x08C (0x281B1C): 0x70408628  paddub      $s0, $v0, $zero
0x090 (0x281B20): 0x16030008  bne         $s0, $v1, . + 4 + (0x8 << 2)
0x094 (0x281B24): 0x00000000  nop
0x098 (0x281B28): 0x10000021  b           . + 4 + (0x21 << 2)
0x09C (0x281B2C): 0x7BBF0010  lq          $ra, 0x10($sp)
0x0A0 (0x281B30): 0x8F848C60  lw          $a0, -0x73A0($gp)
0x0A4 (0x281B34): 0x0C080C04  jal         func_203010
0x0A8 (0x281B38): 0x72002E28  paddub      $a1, $s0, $zero
0x0AC (0x281B3C): 0x1040001B  beqz        $v0, . + 4 + (0x1B << 2)
0x0B0 (0x281B40): 0x00000000  nop
0x0B4 (0x281B44): 0x8F848C60  lw          $a0, -0x73A0($gp)
0x0B8 (0x281B48): 0x24070001  addiu       $a3, $zero, 0x1
0x0BC (0x281B4C): 0x3C023F80  lui         $v0, 0x3F80
0x0C0 (0x281B50): 0x00102C3C  dsll32      $a1, $s0, 16
0x0C4 (0x281B54): 0x44826000  mtc1        $v0, $f12
0x0C8 (0x281B58): 0x00052C3F  dsra32      $a1, $a1, 16
0x0CC (0x281B5C): 0x70003628  paddub      $a2, $zero, $zero
0x0D0 (0x281B60): 0x70E04628  paddub      $t0, $a3, $zero
0x0D4 (0x281B64): 0x0C0B8078  jal         func_2E01E0
0x0D8 (0x281B68): 0x70E04E28  paddub      $t1, $a3, $zero
0x0DC (0x281B6C): 0x1040000F  beqz        $v0, . + 4 + (0xF << 2)
0x0E0 (0x281B70): 0x00000000  nop
0x0E4 (0x281B74): 0x8F848C68  lw          $a0, -0x7398($gp)
0x0E8 (0x281B78): 0x0C0A5F08  jal         func_297C20
0x0EC (0x281B7C): 0x72002E28  paddub      $a1, $s0, $zero
0x0F0 (0x281B80): 0x2403FFFF  addiu       $v1, $zero, -0x1
0x0F4 (0x281B84): 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
0x0F8 (0x281B88): 0x00000000  nop
0x0FC (0x281B8C): 0x8F848C68  lw          $a0, -0x7398($gp)
0x100 (0x281B90): 0x0C0A6040  jal         func_298100
0x104 (0x281B94): 0x70402E28  paddub      $a1, $v0, $zero
0x108 (0x281B98): 0x70408628  paddub      $s0, $v0, $zero
0x10C (0x281B9C): 0x8F848C64  lw          $a0, -0x739C($gp)
0x110 (0x281BA0): 0x72002E28  paddub      $a1, $s0, $zero
0x114 (0x281BA4): 0x0C0A11C8  jal         func_284720
0x118 (0x281BA8): 0x70003628  paddub      $a2, $zero, $zero
0x11C (0x281BAC): 0x7BBF0010  lq          $ra, 0x10($sp)
0x120 (0x281BB0): 0x7BB00000  lq          $s0, 0x0($sp)
0x124 (0x281BB4): 0x03E00008  jr          $ra
0x128 (0x281BB8): 0x27BD0020  addiu       $sp, $sp, 0x20
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
collected 332 items

tests/test_unit_action_build_77a0.py .                                   [  0%]
...
tests/test_unit_action_build_81a80.py .                                  [ 27%]
tests/test_unit_action_build_81a90.py .........                          [ 30%]
...
tests/test_verify_exact_linked_81a80.py ..............                   [100%]

============================= 332 passed in 23.41s =============================
```

Status: Maintained strictly as `NonMatching`.
Configuration and symbols files remain untouched.
Branch `feat/unit-action-build-7c390` remains unmerged.
