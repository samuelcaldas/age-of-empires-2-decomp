# Milestone 152 Verification & Behavioral Evidence: func_00280770

Durable record of behavioral derivation, TDD chronology, disassembly analysis, and exact byte verification for Milestone 152 (`func_00280770` / `func_280770`).

## 1. ELF Boundaries & Reference Artifacts

- **Target Binary**: PS2 PAL `SLES-50282` (`orig/SLES-50282/AOK.ELF`, SHA-1 `f478e19f2059d52899b691483ef5c7522e30e17c`)
- **Primary Symbol**: `func_00280770` (alias `func_280770`)
- **Role**: ActionManager/ActionBuild constructor (vtable slot 2 of `0x4DC9F0`)
- **VRAM Extent**: `[0x280770, 0x2807D0)` (96 code bytes, 24 instructions)
- **File Offset Extent**: `[0x180950, 0x1809B0)`
- **Alignment Padding**: 0 bytes (the function ends at `0x2807D0`, which is 16-byte aligned; the successor function begins immediately)
- **Total Segment Extent**: 96 bytes (`0x60`)
- **Pinned 96-byte Code Slice SHA-1**: `a292c068edfe12a397e37ed5840d3f6a8aa4b47f`

### Neighboring Boundaries

- **Predecessor**: `func_00280680` (Milestone 151), code extent `[0x280680, 0x28076C)` + 4B NOP padding to `0x280770`. Zero gap.
- **Successor**: Function at VRAM `0x2807D0` (file offset `0x1809B0`) with 0x60-byte stack frame (`addiu $sp, $sp, -0x60`). Zero gap.

---

## 2. ELF & Disassembly-Derived Behavior Derivation

`func_00280770` is a C++ constructor for the `ActionManager` / `ActionBuild` class that initializes the vtable pointer, invokes the base constructor `BaseList::BaseList(0)`, and conditionally invokes `__vec_ctor(this)` when `(short)count > 0`.

### Disassembly Analysis

```assembly
0x280770: addiu $sp, $sp, -0x30        # Stack frame allocation (0x30 bytes)
0x280774: sq $ra, 0x20($sp)            # Callee-saved register preservation
0x280778: sq $s1, 0x10($sp)
0x28077c: sq $s0, 0x0($sp)
0x280780: paddub $s1, $a0, $zero       # s1 = self (this pointer)
0x280784: beq $s1, $zero, 0x30         # If self == NULL, branch to epilogue (returns NULL)
0x280788: paddub $s0, $a1, $zero       # Delay slot: s0 = count
0x28078c: lui $v0, 0x004e              # R_MIPS_HI16: vtable at 0x4DC9F0 (0x4E0000)
0x280790: addiu $v0, $v0, -0x3610      # R_MIPS_LO16: 0x4E0000 - 0x3610 = 0x4DC9F0
0x280794: sw $v0, 0x0($s1)             # this->vtable = 0x4DC9F0
0x280798: jal 0x138a50                 # Call BaseList::BaseList(this, 0)
0x28079c: paddub $a1, $zero, $zero     # Delay slot: a1 = 0 (int argument)
0x2807a0: dsll32 $v0, $s0, 16          # Sign-extend low 16 bits of count
0x2807a4: dsra32 $v0, $v0, 16          # v0 = (short)count
0x2807a8: blez $v0, 0x10               # If (short)count <= 0, branch over __vec_ctor
0x2807ac: paddub $v0, $s1, $zero       # Branch-likely delay slot: v0 = self
0x2807b0: jal 0x100670                 # Call __vec_ctor(this)
0x2807b4: paddub $a0, $s1, $zero       # Delay slot: a0 = this
0x2807b8: paddub $v0, $s1, $zero       # v0 = this (return value)
0x2807bc: lq $ra, 0x20($sp)            # Epilogue: register restoration
0x2807c0: lq $s1, 0x10($sp)
0x2807c4: lq $s0, 0x0($sp)
0x2807c8: jr $ra                       # Return
0x2807cc: addiu $sp, $sp, 0x30         # Delay slot: stack frame deallocation
```

### Relocations Table

| Offset | Relocation Type | Target Symbol | Resolved Value | Notes |
|---|---|---|---|---|
| `0x1C` (`0x28078C`) | `R_MIPS_HI16` | `__vt__004DC9F0` | `0x004E` | `%hi(0x4DC9F0) = (0x4DC9F0 + 0x8000) >> 16` |
| `0x20` (`0x280790`) | `R_MIPS_LO16` | `__vt__004DC9F0` | `0xC9F0` (`-0x3610`) | `%lo(0x4DC9F0)` |
| `0x28` (`0x280798`) | `R_MIPS_26` | `func_138A50` | `0x138A50` | `BaseList::BaseList(int)` |
| `0x40` (`0x2807B0`) | `R_MIPS_26` | `func_100670` | `0x100670` | `__vec_ctor` (MSL vector constructor) |

---

## 3. Durable Behavioral TDD Chronology

### Step 1: Red (Observed Assertion Failure on Stub)

- **Stub Implementation**:
  ```cpp
  void *func_00280770(void *self, short count) {
      (void)self;
      (void)count;
      return (void *)0;
  }
  ```
- **Test Command**:
  ```sh
  g++ -m32 -O0 -g -std=c++98 -Iinclude /tmp/stub_80770.cpp tests/native/unit_action_build_80770_test.cpp -o /tmp/test_80770_red && /tmp/test_80770_red
  ```
- **Failure Log (Verbatim)**:
  ```
  test_80770_red: tests/native/unit_action_build_80770_test.cpp:64: void test_non_null_positive_count(): Assertion `res == &mgr' failed.
  /bin/bash: line 1: 727395 Aborted (core dumped) /tmp/test_80770
  ```

### Step 2: Green (Passing Behavioral Test Doubles)

- **Implementation**: Pure C++ in `src/unit_action_build_80770.cpp` and `include/unit_action_build_80770.h`.
- **Test Command**:
  ```sh
  g++ -m32 -O0 -g -std=c++98 -Iinclude src/unit_action_build_80770.cpp tests/native/unit_action_build_80770_test.cpp -o /tmp/test_80770 && /tmp/test_80770
  ```
- **Output Log (Verbatim)**:
  ```
  PASS test_null_self_returns_null
  PASS test_non_null_positive_count
  PASS test_non_null_zero_and_negative_counts
  PASS test_alias
  All unit_action_build_80770 tests passed!
  ```

### Behaviors Verified:

1. **Null self**: when `self == NULL`, returns `NULL`; base constructor `BaseList` and `__vec_ctor` are NOT called.
2. **Positive count**: when `self != NULL` and `count > 0`, initializes `vtable` to `0x4DC9F0`, calls `BaseList::BaseList(this, 0)`, calls `__vec_ctor(this)`, and returns `this`.
3. **Zero and negative count boundary**: tests `count == 0`, `count == -1`, `count == -5`, `count == -32768`. Initializes `vtable` and calls `BaseList::BaseList(this, 0)`, but strictly skips `__vec_ctor`.
4. **Call order**: verifies `BaseList::BaseList` is invoked first, followed by `__vec_ctor`.
5. **Inlined alias**: `func_280770` behaves identically to `func_00280770`.

---

## 4. Standalone Verifier & Relocation Resolution Evidence

- **Script**: `tools/verify_exact_linked_80770.py`
- **Execution Command**:
  ```sh
  python3 tools/verify_exact_linked_80770.py
  ```
- **Execution Output**:
  ```
  === Milestone 152 (func_00280770) Relocation-Resolved Byte Equality Verification ===
  Target ELF:              orig/SLES-50282/AOK.ELF
  File Offset:             0x180950 (VRAM 0x280770)
  Length:                  96 bytes (24 instructions)
  Symbol func_00280770:  validated at .text offset 0, size 96
  Original ELF slice SHA1: a292c068edfe12a397e37ed5840d3f6a8aa4b47f (enforced exact: a292c068edfe12a397e37ed5840d3f6a8aa4b47f)
  Resolved code slice SHA1:a292c068edfe12a397e37ed5840d3f6a8aa4b47f (enforced exact: a292c068edfe12a397e37ed5840d3f6a8aa4b47f)
  HI16 resolved sites:     1 (enforced exact: 1)
  LO16 resolved sites:     1 (enforced exact: 1)
  JAL (R_MIPS_26) resolved:2 (enforced exact: 2)

  RESULT: EXACT MATCH! 96 / 96 bytes identical (100.00% byte equality).
  All 24 instructions match bit-for-bit against orig/SLES-50282/AOK.ELF.
  ```

### Verifier Hardening Controls:

- **ELF32 Type & Machine**: strictly validates `e_type == ET_REL (1)` and `e_machine == EM_MIPS (8)`.
- **Relocation Section Associations**: validates `.rel.text` `sh_info == .text` and `sh_link == .symtab`.
- **Out-of-Bounds Rejection**: rejects any relocation record with `r_offset >= 96`.
- **Symbol Validation**: asserts `func_00280770` resides in `.text`, starts at offset 0, and has size 96.
- **JAL 256MB Region**: asserts `(sym_value & 0xF0000000) == ((call_site_vram + 4) & 0xF0000000)`.
- **Table Divisibility**: enforces `symtab_size % 16 == 0` and `reloc_size % 8 == 0`.
- **All 7 verifier enforcement tests** pass via `/usr/bin/python3 tests/test_verify_exact_linked_80770.py`.
