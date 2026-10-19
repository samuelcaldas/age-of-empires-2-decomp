# Milestone 154 Verification & Behavioral Evidence: func_00281030

Durable record of behavioral derivation, TDD chronology, disassembly analysis, and exact byte verification for Milestone 154 (`func_00281030` / `func_281030`).

## 1. ELF Boundaries & Reference Artifacts

- **Target Binary**: PS2 PAL `SLES-50282` (`orig/SLES-50282/AOK.ELF`, SHA-1 `f478e19f2059d52899b691483ef5c7522e30e17c`)
- **Primary Symbol**: `func_00281030` (alias `func_281030`)
- **Role**: 4-parameter Action/Message query dispatcher and callback iterator
- **VRAM Extent**: `[0x281030, 0x2818D0)` (2208 code bytes, 552 instructions)
- **File Offset Extent**: `[0x181210, 0x181AB0)`
- **Alignment Padding**: 0 bytes (the function ends at `0x2818D0`, which is 16-byte aligned; the successor function begins immediately)
- **Total Segment Extent**: 2208 bytes (`0x8A0`)
- **Pinned 2208-byte Code Slice SHA-1**: `99b454230add025d664eea3b1e561b15206e8239`

### Neighboring Boundaries

- **Predecessor**: `func_002807D0` (Milestone 153), code extent `[0x2807D0, 0x281024)` + 12B NOP padding to `0x281030`. Zero gap.
- **Successor**: Function at VRAM `0x2818D0` (file offset `0x181AB0`) with stack frame `addiu $sp, $sp, -0x40` (`0x27BDFFC0`). Zero gap.

---

## 2. ELF & Disassembly-Derived Behavior Derivation

`func_00281030` is the companion 4-parameter query dispatcher to `func_002807D0`. It takes:
- `$a0`: `int code` (action code)
- `$a1`: `ActionCallback2 callback` (saved into `$s2` via `paddub $s2, $a1, $zero`)
- `$a2`: `void *param1` (saved into `$s1` via `paddub $s1, $a2, $zero`)
- `$a3`: `void *param2` (saved into `$s0` via `paddub $s0, $a3, $zero`)

It allocates a `0x70`-byte stack frame, preserving 7 callee-saved registers (`$ra`, `$s5`, `$s4`, `$s3`, `$s2`, `$s1`, `$s0`).

### Callback Invocation ABI

Indirect callback is invoked via `jalr $ra, $s2` with arguments:
- `$a0`: matching item index `id` (held in `$s3`, `$s4`, or `$s5`)
- `$a1`: `param1` (`$s1`)
- `$a2`: `param2` (`$s0`)

### Action Code Dispatch Modes

- **Single-Match Codes (-101 to -111)**: Iterates `i = 1 .. count-1`. On first matching element, invokes `callback(i, param1, param2)`, breaks out of the loop, and returns to the epilogue.
- **Multi-Match / Broadcast Codes (-201 to -205)**: Iterates `i = 1 .. count-1`. For every matching element, invokes `callback(i, param1, param2)` and continues the loop until all elements are inspected.
- **Default Path**: Unrecognized codes branch directly to the epilogue at `0x2818A8`, returning without helper or callback invocation.

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
  void func_00281030(int code, ActionCallback2 callback, void *param1, void *param2) {
      (void)code;
      (void)callback;
      (void)param1;
      (void)param2;
  }
  ```
- **Test Command**:
  ```sh
  g++ -m32 -O0 -g -std=c++98 -Iinclude src/unit_action_build_81030.cpp tests/native/unit_action_build_81030_test.cpp -o /tmp/test_81030 && /tmp/test_81030
  ```
- **Failure Log (Verbatim)**:
  ```
  test_81030: tests/native/unit_action_build_81030_test.cpp:178: void test_all_16_action_codes(): Assertion `g_callback_calls.size() >= 1' failed.
  /bin/bash: line 1: 1222460 Aborted (core dumped) /tmp/test_81030
  ```

### Step 2: Green (Passing Behavioral Test Doubles)

- **Implementation**: Pure C++ in `src/unit_action_build_81030.cpp` and `include/unit_action_build_81030.h`.
- **Test Command**:
  ```sh
  g++ -m32 -O0 -g -std=c++98 -Iinclude src/unit_action_build_81030.cpp tests/native/unit_action_build_81030_test.cpp -o /tmp/test_81030 && /tmp/test_81030
  ```
- **Output Log (Verbatim)**:
  ```
  PASS test_default_case_does_nothing
  PASS test_all_16_action_codes
  PASS test_single_match_vs_all_matches
  PASS test_alias
  All unit_action_build_81030 tests passed!
  ```

---

## 4. Standalone Verifier & Relocation Resolution Evidence

- **Script**: `tools/verify_exact_linked_81030.py`
- **Execution Command**:
  ```sh
  python3 tools/verify_exact_linked_81030.py
  ```
- **Execution Output**:
  ```
  === Milestone 154 (func_00281030) Relocation-Resolved Byte Equality Verification ===
  Target ELF:              orig/SLES-50282/AOK.ELF
  File Offset:             0x181210 (VRAM 0x281030)
  Length:                  2208 bytes (552 instructions)
  Symbol func_00281030:  validated at .text offset 0, size 2208
  Original ELF slice SHA1: 99b454230add025d664eea3b1e561b15206e8239 (enforced exact: 99b454230add025d664eea3b1e561b15206e8239)
  Resolved code slice SHA1:99b454230add025d664eea3b1e561b15206e8239 (enforced exact: 99b454230add025d664eea3b1e561b15206e8239)
  GPREL16 resolved sites:  45 (enforced exact: 45)
    - D_4E3418:            31 (enforced exact: 31)
    - D_4E3420:            14 (enforced exact: 14)
  JAL resolved sites:      22 (enforced exact: 22)
    - func_202B10:         10 (enforced exact: 10)
    - func_205920:         12 (enforced exact: 12)
  JALR call sites:         16 (enforced exact: 16)

  RESULT: EXACT MATCH! 2208 / 2208 bytes identical (100.00% byte equality).
  All 552 instructions match bit-for-bit against orig/SLES-50282/AOK.ELF.
  ```

### Verifier Hardening Controls

- **ELF32 Type & Machine**: strictly validates `e_type == ET_REL (1)` and `e_machine == EM_MIPS (8)`.
- **Per-Site Manifest**: validates all 67 relocation records against an exact offset-to-symbol-and-type table.
- **Per-Symbol Counts**: strictly enforces 31 D_4E3418, 14 D_4E3420, 10 func_202B10, 12 func_205920.
- **Addend Validation**: asserts unlinked low-16/low-26 bits are zero and resolved addends match expected offsets/targets.
- **Relocation Section Associations**: validates `.rel.text` `sh_info == .text` and `sh_link == .symtab`.
- **Out-of-Bounds Rejection**: rejects any relocation record with `r_offset >= 2208`.
- **Symbol Validation**: asserts `func_00281030` resides in `.text`, starts at offset 0, and has size 2208.
- **JAL 256MB Region**: asserts `(sym_vram & 0xF0000000) == ((call_site_vram + 4) & 0xF0000000)`.
- **Table Divisibility**: enforces `symtab_size % 16 == 0` and `reloc_size % 8 == 0`.
- **All 14 verifier enforcement tests** pass via `.venv/bin/pytest -v tests/test_verify_exact_linked_81030.py` (15 focused tests total).
