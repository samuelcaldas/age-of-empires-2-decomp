# Milestone 153 Verification & Behavioral Evidence: func_002807D0

Durable record of behavioral derivation, TDD chronology, disassembly analysis, and exact byte verification for Milestone 153 (`func_002807D0` / `func_2807D0`).

## 1. ELF Boundaries & Reference Artifacts

- **Target Binary**: PS2 PAL `SLES-50282` (`orig/SLES-50282/AOK.ELF`, SHA-1 `f478e19f2059d52899b691483ef5c7522e30e17c`)
- **Primary Symbol**: `func_002807D0` (alias `func_2807D0`)
- **Role**: Action/Message query dispatcher and callback iterator
- **VRAM Extent**: `[0x2807D0, 0x281024)` (2132 code bytes, 533 instructions)
- **File Offset Extent**: `[0x1809B0, 0x181204)`
- **Alignment Padding**: 12 bytes of NOP (`0x00000000 0x00000000 0x00000000`) at `[0x281024, 0x281030)` to reach 16-byte alignment (`0x281030`)
- **Total Segment Extent**: 2144 bytes (`0x860`)
- **Pinned 2132-byte Code Slice SHA-1**: `420dcf16176fa46ccf90d1d7fcd7b16eb807254f`

### Neighboring Boundaries

- **Predecessor**: `func_00280770` (Milestone 152), code extent `[0x280770, 0x2807D0)`. Zero gap.
- **Successor**: Function at VRAM `0x281030` (file offset `0x181210`) with stack frame `addiu $sp, $sp, -0x70` (`0x27BDFF90`). Zero gap.

---

## 2. ELF & Disassembly-Derived Behavior Derivation

`func_002807D0` is a C++ query dispatcher that takes a message/action code in `$a0`, a callback function pointer in `$a1`, and a context pointer in `$a2`. It evaluates 16 action codes across two table structures loaded from BSS (`D_4E3418` and `D_4E3420`):

1. **Table1 (`D_4E3418`)**: contains item count at offset `0x50` (short) and pointer array at offset `0x54` (`items[i]`).
2. **Table2 (`D_4E3420`)**: contains `active_id` at offset `0xBA0` (int) and byte status table at offset `0xBD8` queried via `func_205920(table2, i)`.

### Action Code Dispatch Modes

- **Single-Match Codes (-101 to -111)**: Iterates `i = 1 .. count-1`. On first matching element, invokes `callback(i, param)` via indirect call `jalr $ra, $s1`, and immediately breaks out of the loop and returns to the epilogue.
- **Multi-Match / Broadcast Codes (-201 to -205)**: Iterates `i = 1 .. count-1`. For every matching element, invokes `callback(i, param)` and continues the loop until all elements are inspected.
- **Default Path**: For any unhandled action code, branches directly to the epilogue and returns without making any helper or callback calls.

### Summary of Action Codes

| Code | Type | Condition | Helper Calls | Break Mode |
|---|---|---|---|---|
| -101 (`0xFF9B`) | Find First | `table2->active_id != i && !func_205920(table2, i)` | `func_205920` | Early break |
| -102 (`0xFF9A`) | Find First | `func_202B10(table1->items[i]) != 0` | `func_202B10` | Early break |
| -103 (`0xFF99`) | Find First | `table2->active_id != i && func_202B10(items[i]) && !func_205920(table2, i)` | `func_202B10`, `func_205920` | Early break |
| -104 (`0xFF98`) | Find First | `func_202B10(items[i]) && func_205920(table2, i) == 3` | `func_202B10`, `func_205920` | Early break |
| -105 (`0xFF97`) | Find First | `func_202B10(items[i]) && func_205920(table2, i) == 1` | `func_202B10`, `func_205920` | Early break |
| -106 (`0xFF96`) | Find First | `func_205920(table2, i) == 3` | `func_205920` | Early break |
| -107 (`0xFF95`) | Find First | `func_202B10(items[i]) == 0` | `func_202B10` | Early break |
| -108 (`0xFF94`) | Find First | `table2->active_id != i && !func_202B10(items[i]) && !func_205920(table2, i)` | `func_202B10`, `func_205920` | Early break |
| -109 (`0xFF93`) | Find First | `!func_202B10(items[i]) && func_205920(table2, i) == 3` | `func_202B10`, `func_205920` | Early break |
| -110 (`0xFF92`) | Find First | `!func_202B10(items[i]) && func_205920(table2, i) == 1` | `func_202B10`, `func_205920` | Early break |
| -111 (`0xFF91`) | Find First | `func_205920(table2, i) == 1` | `func_205920` | Early break |
| -201 (`0xFF37`) | Broadcast | `table2->active_id != i && !func_205920(table2, i)` | `func_205920` | Full iteration |
| -202 (`0xFF36`) | Broadcast | `func_202B10(table1->items[i]) != 0` | `func_202B10` | Full iteration |
| -203 (`0xFF35`) | Broadcast | `func_205920(table2, i) == 3` | `func_205920` | Full iteration |
| -204 (`0xFF34`) | Broadcast | `func_202B10(table1->items[i]) == 0` | `func_202B10` | Full iteration |
| -205 (`0xFF33`) | Broadcast | `func_205920(table2, i) == 1` | `func_205920` | Full iteration |
| Default | No-op | Unrecognized action code | None | Immediate return |

---

## 3. Durable Behavioral TDD Chronology

### Step 1: Red (Observed Assertion Failure on Stub)

- **Stub Implementation**:
  ```cpp
  void func_002807D0(int code, ActionCallback callback, void *param) {
      (void)code;
      (void)callback;
      (void)param;
  }
  ```
- **Test Command**:
  ```sh
  g++ -m32 -O0 -g -std=c++98 -Iinclude src/unit_action_build_807d0.cpp tests/native/unit_action_build_807d0_test.cpp -o /tmp/test_807d0 && /tmp/test_807d0
  ```
- **Failure Log (Verbatim)**:
  ```
  test_807d0: tests/native/unit_action_build_807d0_test.cpp:161: void test_all_16_action_codes(): Assertion `g_callback_calls.size() >= 1' failed.
  /bin/bash: line 1: 920927 Aborted (core dumped) /tmp/test_807d0
  ```

### Step 2: Green (Passing Behavioral Test Doubles)

- **Implementation**: Pure C++ in `src/unit_action_build_807d0.cpp` and `include/unit_action_build_807d0.h`.
- **Test Command**:
  ```sh
  g++ -m32 -O0 -g -std=c++98 -Iinclude src/unit_action_build_807d0.cpp tests/native/unit_action_build_807d0_test.cpp -o /tmp/test_807d0 && /tmp/test_807d0
  ```
- **Output Log (Verbatim)**:
  ```
  PASS test_default_case_does_nothing
  PASS test_all_16_action_codes
  PASS test_single_match_vs_all_matches
  PASS test_alias
  All unit_action_build_807d0 tests passed!
  ```

---

## 4. Standalone Verifier & Relocation Resolution Evidence

- **Script**: `tools/verify_exact_linked_807d0.py`
- **Execution Command**:
  ```sh
  python3 tools/verify_exact_linked_807d0.py
  ```
- **Execution Output**:
  ```
  === Milestone 153 (func_002807D0) Relocation-Resolved Byte Equality Verification ===
  Target ELF:              orig/SLES-50282/AOK.ELF
  File Offset:             0x1809B0 (VRAM 0x2807D0)
  Length:                  2132 bytes (533 instructions)
  Symbol func_002807D0:  validated at .text offset 0, size 2132
  Original ELF slice SHA1: 420dcf16176fa46ccf90d1d7fcd7b16eb807254f (enforced exact: 420dcf16176fa46ccf90d1d7fcd7b16eb807254f)
  Resolved code slice SHA1:420dcf16176fa46ccf90d1d7fcd7b16eb807254f (enforced exact: 420dcf16176fa46ccf90d1d7fcd7b16eb807254f)
  GPREL16 resolved sites:  45 (enforced exact: 45)
    - D_4E3418:            31 (enforced exact: 31)
    - D_4E3420:            14 (enforced exact: 14)
  JAL resolved sites:      22 (enforced exact: 22)
    - func_202B10:         10 (enforced exact: 10)
    - func_205920:         12 (enforced exact: 12)
  JALR call sites:         16 (enforced exact: 16)

  RESULT: EXACT MATCH! 2132 / 2132 bytes identical (100.00% byte equality).
  All 533 instructions match bit-for-bit against orig/SLES-50282/AOK.ELF.
  ```

### Verifier Hardening Controls

- **ELF32 Type & Machine**: strictly validates `e_type == ET_REL (1)` and `e_machine == EM_MIPS (8)`.
- **Per-Site Manifest**: validates all 67 relocation records against an exact offset-to-symbol-and-type table.
- **Per-Symbol Counts**: strictly enforces 31 D_4E3418, 14 D_4E3420, 10 func_202B10, 12 func_205920.
- **Addend Validation**: asserts unlinked low-16/low-26 bits are zero and resolved addends match expected offsets/targets.
- **Relocation Section Associations**: validates `.rel.text` `sh_info == .text` and `sh_link == .symtab`.
- **Out-of-Bounds Rejection**: rejects any relocation record with `r_offset >= 2132`.
- **Symbol Validation**: asserts `func_002807D0` resides in `.text`, starts at offset 0, and has size 2132.
- **JAL 256MB Region**: asserts `(sym_vram & 0xF0000000) == ((call_site_vram + 4) & 0xF0000000)`.
- **Table Divisibility**: enforces `symtab_size % 16 == 0` and `reloc_size % 8 == 0`.
- **All 14 verifier enforcement tests** pass via `.venv/bin/pytest -v tests/test_verify_exact_linked_807d0.py` (15 focused tests total).
