# Trade Action Helper `0x21DE20` (`trade_action_helper_21DE20.cpp`)

## 1. Overview and ELF Mapping
- **VRAM Address Range:** `0x21DE20` – `0x21DE84` (Size: `0x64` bytes / 100 bytes; padding to `0x21DE90`: `0x70` bytes / 112 bytes, end-exclusive)
- **File Offset Range:** `0x11E000` – `0x11E064` in `orig/SLES-50282/AOK.ELF` (padding to `0x11E070`)
- **Segment / Section:** `.text` (ELF load delta: `0xFFE20`)

## 2. Binary Analysis & Disassembly Trace
- **Prologue (`0x21DE20` – `0x21DE30`):**
  - `addiu sp, sp, -64` (Allocate stack frame of 64 bytes)
  - `sq ra, 48(sp)` (Save return address)
  - `sq s2, 32(sp)` (Save s2)
  - `sq s1, 16(sp)` (Save s1)
  - `sq s0, 0(sp)` (Save s0)
- **Register Setup & Forward Branch (`0x21DE34` – `0x21DE40`):**
  - `paddub s2, a0, zero` (Assign `s2` = `base` pointer)
  - `paddub s1, a1, zero` (Assign `s1` = `base_idx`)
  - `b 0x21DE68` (Branch forward to loop condition test)
  - Delay slot at `0x21DE40`: `paddub s0, a2, zero` (Assign `s0` = `count`)
- **Loop Body (`0x21DE44` – `0x21DE64`):**
  - `0x21DE44`: `paddub a0, s2, zero` (Set `a0` = current buffer pointer `s2`)
  - `0x21DE48`: `jal func_21DD10` (Target `0x21DD10`)
  - Delay slot at `0x21DE4C`: `paddub a1, s1, zero` (Set `a1` = current index `s1`)
  - `0x21DE50`: `addiu s1, s1, 1` (Increment index `s1++`)
  - `0x21DE54`: `andi v1, s1, 0xF` (Check if lower 4 bits are 0, i.e., 16-element wrap-around)
  - `0x21DE58`: `bnel v1, zero, 0x21DE68` (Branch Likely: if not wrapped, jump to loop test)
  - Delay slot at `0x21DE5C`: `addiu s0, s0, -1` (Executed only if branch taken)
  - On wrap-around (branch not taken):
    - `0x21DE60`: `addiu s2, s2, 0x400` (Advance buffer pointer by 1024 bytes)
    - `0x21DE64`: `addiu s0, s0, -1` (Decrement `count--`)
- **Loop Test (`0x21DE68` – `0x21DE6C`):**
  - `0x21DE68`: `bnez s0, 0x21DE44` (Loop back to 0x21DE44 while `s0 != 0`)
  - Delay slot at `0x21DE6C`: `paddub a0, s2, zero`
- **Epilogue (`0x21DE70` – `0x21DE84`):**
  - `lq ra, 48(sp)` (Restore ra)
  - `lq s2, 32(sp)` (Restore s2)
  - `lq s1, 16(sp)` (Restore s1)
  - `lq s0, 0(sp)` (Restore s0)
  - `jr ra` (Return at `0x21DE80`)
  - `addiu sp, sp, 64` (Delay slot at `0x21DE84`: deallocate stack frame)
- **Alignment Padding (`0x21DE88` – `0x21DE8C`):**
  - 2 `nop` instructions (8 bytes) aligning to 16-byte boundary for `0x21DE90`.

## 3. C++ Implementation & Verification
- Implemented in `src/trade_action_helper_21DE20.cpp` adhering strictly to C++98 standards, Object Calisthenics, and SOLID principles.
- Native 32-bit test harness in `src/trade_action_helper_21DE20_test.cpp` verifying iterative invocation, 16-element 0x400 pointer stride boundary crossings, and boundary conditions.
- Automated pytest regression in `tests/test_trade_action_helper_21DE20.py`.
- Registered as `NonMatching` in `configure.py`.
