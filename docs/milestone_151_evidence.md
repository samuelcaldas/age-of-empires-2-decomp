# Milestone 151 Verification & Behavioral Evidence: func_00280680

Durable record of behavioral derivation, TDD chronology, disassembly analysis, and exact byte verification for Milestone 151 (`func_00280680` / `func_280680`).

## 1. ELF Boundaries & Reference Artifacts

- **Target Binary**: PS2 PAL `SLES-50282` (`orig/SLES-50282/AOK.ELF`, SHA-1 `f478e19f2059d52899b691483ef5c7522e30e17c`)
- **Primary Symbol**: `func_00280680` (alias `func_280680`)
- **VRAM Extent**: `[0x280680, 0x28076C)` (236 code bytes, 59 instructions)
- **File Offset Extent**: `[0x180860, 0x18094C)`
- **Alignment Padding**: 4 bytes (`[0x18094C, 0x180950)` / `[0x28076C, 0x280770)`, 1 NOP word)
- **Total Segment Extent with Padding**: 240 bytes (`0xF0`)
- **Pinned 236-byte Code Slice SHA-1**: `3a5ed9046834ca80b63af322cfe1c479c8fdfb7a`
- **Pinned 240-byte Extent with Padding SHA-1**: `4285db247ac50ea429116e0c57f1d48d59653002`

### Neighboring Boundaries

- **Predecessor**: `func_00280670` (Milestone 150), ends at `0x280678` (`0x180858`) + 8B padding to `0x280680`.
- **Successor**: Function at `0x280770` (`0x180950`) with 0x30-byte stack frame (`addiu $sp, $sp, -0x30`).

---

## 2. ELF & Disassembly-Derived Behavior Derivation

`func_00280680` is an action manager list cleanup and update routine that iterates over an action linked list, checks the status of each action, destroys completed/terminated actions, and returns the number of active surviving actions.

### Disassembly Analysis

```assembly
0x280680: addiu $sp, $sp, -0x60        # Stack frame allocation (0x60 bytes)
0x280684: sq $ra, 0x50($sp)            # Callee-saved register preservation
0x280688: sq $s4, 0x40($sp)
0x28068c: sq $s3, 0x30($sp)
0x280690: sq $s2, 0x20($sp)
0x280694: sq $s1, 0x10($sp)
0x280698: sq $s0, 0x0($sp)
0x28069c: lw $s1, 0x8($a0)             # s1 = self->action_list_head (offset 8)
0x2806a0: paddub $s2, $a0, $zero       # s2 = self
0x2806a4: bnez $s1, .L002806B4          # If list is not empty, jump to loop setup
0x2806a8: paddub $s0, $zero, $zero     # Delay slot: s0 (active_count) = 0
0x2806ac: b .L0028074C                 # If list is empty, jump to epilogue
0x2806b0: paddub $v0, $zero, $zero     # Delay slot: return 0
.L002806B4:
0x2806b4: b .L00280740                 # Jump to loop test (while loop)
0x2806b8: paddub $s3, $zero, $zero     # Delay slot: s3 (prev) = NULL
.L002806BC: # Loop body
0x2806bc: lw $a0, 0x0($s1)             # a0 = node->item
0x2806c0: lw $t9, 0x0($a0)             # t9 = item->vtable
0x2806c4: lw $t9, 0x30($t9)            # t9 = vtable slot 10 (offset 0x30 = GetStatus)
0x2806c8: jalr $ra, $t9                # Call item->GetStatus()
0x2806cc: nop
0x2806d0: andi $v1, $v0, 0xff          # v1 = (unsigned char)status
0x2806d4: addiu $v0, $zero, 0x1
0x2806d8: beq $v1, $v0, 0x10           # If status == 1, jump to removal
0x2806dc: nop
0x2806e0: addiu $v0, $zero, 0x3
0x2806e4: bnel $v1, $v0, 0x50          # If status != 3, jump to keep (advances prev)
0x2806e8: paddub $s3, $s1, $zero       # Branch-likely delay slot: prev = curr

# Removal Branch (status == 1 or status == 3):
0x2806ec: bnez $s3, 0xc                # If prev != NULL, jump to relink
0x2806f0: lw $s4, 0x4($s1)             # Delay slot: s4 = curr->next
0x2806f4: b 0x8                        # Jump over head assignment
0x2806f8: sw $s4, 0x8($s2)             # Delay slot: self->action_list_head = next
0x2806fc: sw $s4, 0x4($s3)             # prev->next = next
0x280700: lw $a1, 0x0($s1)             # a1 = curr->item
0x280704: jal func_366af0              # Release factory resource
0x280708: addiu $a0, $gp, -0x71e4      # Delay slot: a0 = &D_4E35DC (GPREL16)
0x28070c: lw $a0, 0x0($s1)             # a0 = curr->item
0x280710: lw $t9, 0x0($a0)             # t9 = item->vtable
0x280714: lw $t9, 0x68($t9)            # t9 = vtable slot 24 (offset 0x68 = Cleanup)
0x280718: jalr $ra, $t9                # Call item->Cleanup()
0x28071c: nop
0x280720: paddub $a1, $s1, $zero       # a1 = curr (node)
0x280724: jal 0x138b50                 # BaseList::FreeNode(self, node)
0x280728: paddub $a0, $s2, $zero       # Delay slot: a0 = self
0x28072c: b 0x10                       # Jump to loop test
0x280730: paddub $s1, $s4, $zero       # Delay slot: curr = next

# Keep Branch (status != 1 and status != 3):
0x280734: paddub $s3, $s1, $zero       # prev = curr
0x280738: lw $s1, 0x4($s1)             # curr = curr->next
0x28073c: addiu $s0, $s0, 0x1          # active_count++
.L00280740: # Loop test
0x280740: bnez $s1, .L002806BC         # If curr != NULL, continue loop
0x280744: nop
0x280748: paddub $v0, $s0, $zero       # Return active_count
.L0028074C: # Epilogue
0x28074c: lq $ra, 0x50($sp)
0x280750: lq $s4, 0x40($sp)
0x280754: lq $s3, 0x30($sp)
0x280758: lq $s2, 0x20($sp)
0x28075c: lq $s1, 0x10($sp)
0x280760: lq $s0, 0x0($sp)
0x280764: jr $ra                       # Return
0x280768: addiu $sp, $sp, 0x60         # Delay slot: stack deallocation
```

### Relocations Table

| Offset | Relocation Type | Target Symbol | Notes |
|---|---|---|---|
| `0x88` (`0x280708`) | `R_MIPS_GPREL16` | `D_4E35DC` | `$gp - 0x71E4 = 0x4E35DC` |
| `0x84` (`0x280704`) | `R_MIPS_26` | `func_366AF0` | Factory cleanup `0x366AF0` |
| `0xA4` (`0x280724`) | `R_MIPS_26` | `func_138B50` | `BaseList::FreeNode(ListNode*)` |
| `0x48` (`0x2806C8`) | *(none — JALR)* | `item->vtable[10]` | `jalr $ra, $t9` (offset `0x30`) |
| `0x98` (`0x280718`) | *(none — JALR)* | `item->vtable[24]` | `jalr $ra, $t9` (offset `0x68`) |

---

## 3. Durable Behavioral TDD Chronology

### Step 1: Red (Observed Assertion Failure on Stub)

- **Stub Implementation**:
  ```cpp
  int func_00280680(void *self) {
      (void)self;
      return -1; // Stub
  }
  ```
- **Test Command**:
  ```sh
  g++ -m32 -O0 -g -std=c++98 -Iinclude /tmp/stub_80680.cpp tests/native/unit_action_build_80680_test.cpp -o /tmp/test_80680_red && /tmp/test_80680_red
  ```
- **Failure Log (Verbatim)**:
  ```
  test_80680_red: tests/native/unit_action_build_80680_test.cpp:75: void test_empty_list(): Assertion `count == 0' failed.
  /bin/bash: line 1: 110029 Aborted (core dumped) /tmp/test_80680
  ```

### Step 2: Green (Passing Behavioral Test Doubles)

- **Implementation**: Pure C++ in `src/unit_action_build_80680.cpp` and `include/unit_action_build_80680.h`.
- **Test Command**:
  ```sh
  g++ -m32 -O0 -g -std=c++98 -Iinclude src/unit_action_build_80680.cpp tests/native/unit_action_build_80680_test.cpp -o /tmp/test_80680 && /tmp/test_80680
  ```
- **Output Log (Verbatim)**:
  ```
  PASS test_empty_list
  PASS test_active_count_and_removal
  PASS test_remove_head_node
  PASS test_alias
  All unit_action_build_80680 tests passed!
  ```

### Behaviors Verified:

1. **Empty list**: returns 0, does not dereference `action_list_head`.
2. **Active count & status removal**: actions with `status == 1` or `status == 3` are unlinked, their factory cleanup called, their vtable cleanup called, and their node freed via `FreeNode`. Actions with other statuses are retained and increment `active_count`.
3. **Head node removal**: unlinking the first node correctly updates `self->action_list_head` to point to the second node.
4. **Cleanup invocation order**: verifies that for each removed action, `func_366AF0` is called first, then `vtable[Cleanup]`, then `FreeNode`.
5. **Inlined alias**: `func_280680` behaves identically to `func_00280680`.

---

## 4. Standalone Verifier & Relocation Resolution Evidence

- **Script**: `tools/verify_exact_linked_80680.py`
- **Execution Command**:
  ```sh
  python3 tools/verify_exact_linked_80680.py
  ```
- **Execution Output**:
  ```
  === Milestone 151 (func_00280680) Relocation-Resolved Byte Equality Verification ===
  Target ELF:              orig/SLES-50282/AOK.ELF
  File Offset:             0x180860 (VRAM 0x280680)
  Length:                  236 bytes (59 instructions)
  Symbol func_00280680:  validated at .text offset 0, size 236
  Original ELF slice SHA1: 3a5ed9046834ca80b63af322cfe1c479c8fdfb7a (enforced exact: 3a5ed9046834ca80b63af322cfe1c479c8fdfb7a)
  Resolved code slice SHA1:3a5ed9046834ca80b63af322cfe1c479c8fdfb7a (enforced exact: 3a5ed9046834ca80b63af322cfe1c479c8fdfb7a)
  GPREL16 resolved sites:  1 (enforced exact: 1, addend = -0x71E4 / 0x8E1C)
  JAL (R_MIPS_26) resolved:2 (enforced exact: 2)
  Preserved JALR slots:    2 (slots at 0x48 and 0x98 verified as jalr $ra, $t9)

  RESULT: EXACT MATCH! 236 / 236 bytes identical (100.00% byte equality).
  All 59 instructions match bit-for-bit against orig/SLES-50282/AOK.ELF.
  ```

### Verifier Hardening Controls:

- **ELF32 Type & Machine**: strictly validates `e_type == ET_REL (1)` and `e_machine == EM_MIPS (8)`.
- **Relocation Section Associations**: validates `.rel.text` `sh_info == .text` and `sh_link == .symtab`.
- **Out-of-Bounds Rejection**: rejects any relocation record with `r_offset >= 236`.
- **Symbol Validation**: asserts `func_00280680` resides in `.text`, starts at offset 0, and has size 236.
- **JAL 256MB Region**: asserts `(sym_value & 0xF0000000) == ((call_site_vram + 4) & 0xF0000000)`.
- **Table Divisibility**: enforces `symtab_size % 16 == 0` and `reloc_size % 8 == 0`.
- **Relocation Associations Test**: `test_verifier_rejects_wrong_rel_sh_info` and `test_verifier_rejects_wrong_rel_sh_link` specifically mutate `.rel.text` header fields and strictly require controlled exit code 42 rejection.
- **Verifier Enforcement Tests**: All 12 verifier enforcement test functions pass via `/usr/bin/python3 tests/test_verify_exact_linked_80680.py`.
- **Focused Test Suite (16 Total Tests)**: `python -m pytest -v tests/test_unit_action_build_80680.py tests/test_verify_exact_linked_80680.py` passes 16/16 tests in 0.72s in Docker with parent repo dual bind mount (4 behavioral + 12 verifier).
- **Subsystem Build Suite**: `tests/test_unit_action_build_*.py` passes 217/217 tests in 19.77s.
- **Broader unit_action Subsystem**: `tests/test_unit_action*.py` passes 297/297 tests in 23.19s with zero failures and zero skips.
