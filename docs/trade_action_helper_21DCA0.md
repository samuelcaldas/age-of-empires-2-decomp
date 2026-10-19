# Trade Action Helper `0x21DCA0` (`trade_action_helper_21DCA0.cpp`)

## 1. Overview and ELF Mapping
- **VRAM Address Range:** `0x21DCA0` – `0x21DD08` (Size: `0x68` bytes / 104 bytes; padding to `0x21DD10`: `0x70` bytes / 112 bytes, end-exclusive)
- **File Offset Range:** `0x11DE80` – `0x11DEE8` in `orig/SLES-50282/AOK.ELF` (padding to `0x11DEF0`)
- **Segment:** File-backed `PT_LOAD`; `file_offset = VRAM - 0xFFE20`. Original payload section names are blank.
- **Caller Site:** `0x224F38` passes `a0=s4`, `a1=s5`, and `a2=s6`; the delay slot sets `a1`. After return, the branch at `0x224F40` jumps to `0x22504C`, with `s3=2` in its delay slot. The `lui v0,0x49` at `0x224F48` is skipped, not an immediate return-value overwrite. The shared continuation advances `s0` and `s1`, checks loop state, and eventually restores the frame without using a semantic iterator result. This supports a semantic `void` declaration, not a promise that the helper clears `v0`.

## 2. Binary Analysis & Disassembly Trace
- **Prologue (`0x21DCA0` – `0x21DCB4`):**
  - `addiu sp, sp, -80` (Allocate stack frame of 80 bytes)
  - `sq ra, 64(sp)` (Save return address)
  - `sq s3, 48(sp)` (Save s3)
  - `sq s2, 32(sp)` (Save s2)
  - `sq s1, 16(sp)` (Save s1)
  - `sq s0, 0(sp)` (Save s0)
- **Register Assignment (`0x21DCB8` – `0x21DCC0`):**
  - `paddub s3, a0, zero` (Assign `s3` = `base` pointer)
  - `paddub s2, a1, zero` (Assign `s2` = `base_idx`)
  - `paddub s1, a2, zero` (Assign `s1` = `count`)
- **Loop Initialization & Forward Branch (`0x21DCC4` – `0x21DCC8`):**
  - `b 0x21DCE0` (Branch forward to loop condition check)
  - Delay slot at `0x21DCC8`: `paddub s0, zero, zero` (Initialize loop counter `s0 = 0`)
- **Loop Body (`0x21DCCC` – `0x21DCDC`):**
  - Callsite sets only `a0` and `a1`:
    - `0x21DCD0`: `jal func_21DC50` (Target `0x21DC50`)
    - Delay slot at `0x21DCD4`: `paddub a0, s3, zero` (Pass current pointer `s3` in `a0`)
  - Callee `func_0021DC50` consumes only two incoming arguments (`a0`, `a1`). The caller does not establish meaningful `a2/a3` inputs; caller-saved registers may still be clobbered.
  - `0x21DCD8`: `addiu s0, s0, 1` (Increment counter `s0++`)
  - `0x21DCDC`: `addiu s3, s3, 0x400` (Advance pointer by 1024 bytes / `0x400` per item)
- **Loop Condition & Backward Branch (`0x21DCE0` – `0x21DCE8`):**
  - `0x21DCE0`: `slt v1, s0, s1` (Check if `s0 < s1`)
  - `0x21DCE4`: `bnez v1, 0x21DCD0` (Branch back to `jal func_21DC50` if true)
  - Delay slot at `0x21DCE8`: `addu a1, s2, s0` (Compute `a1 = s2 + s0` for next iteration)
- **For count <= 0:**
  - Jumps directly to epilogue without writing `$v0`.
- **Epilogue (`0x21DCEC` – `0x21DD04`):**
  - `lq ra, 64(sp)` (Restore ra)
  - `lq s3, 48(sp)` (Restore s3)
  - `lq s2, 32(sp)` (Restore s2)
  - `lq s1, 16(sp)` (Restore s1)
  - `lq s0, 0(sp)` (Restore s0)
  - `jr ra` (Return at `0x21DD00`)
  - `addiu sp, sp, 80` (Delay slot at `0x21DD04`: deallocate stack frame)
- **Alignment Padding (`0x21DD08` – `0x21DD0C`):**
  - 2 `nop` instructions (8 bytes) aligning to 16-byte boundary for `0x21DD10`.

## 3. C++ Implementation & Verification
- Implemented in `src/trade_action_helper_21DCA0.cpp` as `void func_0021DCA0(void *base, int base_idx, int count)` adhering strictly to C++98 standards, Object Calisthenics, and SOLID principles.
- Models exact two-argument invocation `func_0021DC50(ptr, base_idx + i)` without uninitialized return variables or dummy trailing arguments.
- Native 32-bit test harness in `src/trade_action_helper_21DCA0_test.cpp` verifying sequential invocations, exact stride pointer arithmetic (`0x400` per step), index incrementing (`base_idx + i`), and zero/negative boundary termination.
- Automated pytest regression in `tests/test_trade_action_helper_21DCA0.py`.
- Registered as `NonMatching` in `configure.py`.
