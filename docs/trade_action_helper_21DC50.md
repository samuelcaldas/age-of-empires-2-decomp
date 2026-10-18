# Trade Action Helper `0x21DC50` (`trade_action_helper_21DC50.cpp`)

## 1. Overview and ELF Mapping
- **VRAM Address Range:** `0x21DC50` – `0x21DC94` (Size: `0x44` bytes / 68 bytes; padding to `0x21DCA0`: `0x50` bytes / 80 bytes, end-exclusive)
- **File Offset Range:** `0x11DE30` – `0x11DE74` in `orig/SLES-50282/AOK.ELF` (padding to `0x11DE80`)
- **Segment / Section:** `.text` (ELF load delta: `0xFFE20`)

## 2. Binary Analysis & Disassembly Trace
- **Prologue (`0x21DC50` – `0x21DC5C`):**
  - `addiu sp, sp, -48` (Allocate stack frame of 48 bytes)
  - `sq ra, 32(sp)` (Save return address)
  - `sq s1, 16(sp)` (Save callee-saved register s1)
  - `sq s0, 0(sp)` (Save callee-saved register s0)
- **Argument Preservation (`0x21DC60` – `0x21DC64`):**
  - `paddub s1, a0, zero` (Preserve input argument `a0` into `s1`)
  - `paddub s0, a1, zero` (Preserve input argument `a1` into `s0`)
- **First Call: Allocation Helper (`0x21DC68` – `0x21DC6C`):**
  - `jal 0x123908` (machine word `0x0C048E42`): Invokes allocation/setup helper `func_123908` unconditionally.
  - Delay slot at `0x21DC6C`: `paddub a0, zero, zero` (machine word `0x70002628`), zeroing argument `a0` (`func_123908(0)`).
- **Argument Forwarding (`0x21DC70` – `0x21DC74`):**
  - `paddub a1, s1, zero` (Forward preserved input `a0` as second parameter `a1` to `func_0021DBE0`).
  - `paddub a2, s0, zero` (Forward preserved input `a1` as third parameter `a2` to `func_0021DBE0`).
- **Second Call: Trade Action Helper (`0x21DC78` – `0x21DC7C`):**
  - `jal 0x21DBE0` (machine word `0x0C0876F8`): Invokes `func_0021DBE0`.
  - Delay slot at `0x21DC7C`: `paddub a0, v0, zero` (machine word `0x70402628`), forwarding `v0` (the object returned from `func_123908`) as the first parameter `obj` to `func_0021DBE0`.
- **Epilogue (`0x21DC80` – `0x21DC90`):**
  - `lq ra, 32(sp)` (Restore return address)
  - `lq s1, 16(sp)` (Restore s1)
  - `lq s0, 0(sp)` (Restore s0)
  - `jr ra` (Return at `0x21DC8C`)
  - `addiu sp, sp, 48` (Delay slot at `0x21DC90`: deallocate stack frame)
- **Alignment Padding (`0x21DC94` – `0x21DC9C`):**
  - 3 `nop` instructions (12 bytes) aligning to 16-byte boundary for `0x21DCA0`.

## 3. C++ Implementation & Verification
- Implemented in `src/trade_action_helper_21DC50.cpp` adhering strictly to C++98 standards, Object Calisthenics, SOLID, and unconditional execution without invented null guards.
- Tested via native 32-bit test harness (`src/trade_action_helper_21DC50_test.cpp`) asserting call order (`STEP_ALLOC` precedes `STEP_DBE0`), object forwarding, argument routing (`a0 -> a1`, `a1 -> a2`), and null-pointer unconditional execution.
- Validated via automated pytest suite (`tests/test_trade_action_helper_21DC50.py`).
- Registered as `NonMatching` in `configure.py` pending licensed Metrowerks compiler availability for exact byte-matching verification (`objdiff`).
