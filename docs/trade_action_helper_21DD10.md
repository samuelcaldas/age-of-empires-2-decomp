# Trade Action Helper `0x21DD10` (`trade_action_helper_21DD10.cpp`)

## 1. Overview and ELF Mapping
- **VRAM Address Range:** `[0x21DD10, 0x21DE14)` (size `0x104` / 260 bytes, including the return delay slot); padding continues to `0x21DE20`.
- **File Offset Range:** `[0x11DEF0, 0x11DFF4)` in `orig/SLES-50282/AOK.ELF`; padding continues to `0x11E000`.
- **Segment:** File-backed `PT_LOAD`; `file_offset = VRAM - 0xFFE20`. Original payload section names are blank.

## 2. Binary Analysis & Disassembly Trace
- **Prologue (`0x21DD10` – `0x21DD24`):**
  - `addiu sp, sp, -96` (Allocate stack frame of 96 bytes)
  - `sq ra, 80(sp)` (Save return address)
  - `sq s3, 64(sp)` (Save s3)
  - `sq s2, 48(sp)` (Save s2)
  - `sq s1, 32(sp)` (Save s1)
  - `paddub s1, a0, zero` (Preserve input argument `a0` into `s1`)
  - `paddub s3, a1, zero` (Preserve input argument `a1` into `s3`)
- **First Call: Allocation Helper (`0x21DD2C` – `0x21DD34`):**
  - `paddub a0, zero, zero` (Clear `a0 = 0`)
  - `jal 0x123908` (machine word `0x0C048E42`): Unconditionally invokes allocation helper `func_123908(0)`.
  - Delay slot at `0x21DD34`: `sq s0, 16(sp)` (Save s0 to stack).
  - `paddub s0, v0, zero` at `0x21DD38`: Save allocated packet pointer into `s0`.
- **Bitwise Coordinates Computation (`0x21DD3C` – `0x21DD84`):**
  - Strictly follows MIPS R5900 instruction semantics:
    - Logical shift right (`srl`) for `s3 >> 6` (machine word `0x00131982`), `s3 >> 1` (machine word `0x00131042`), and `v0 >> 4` (machine word `0x00021102`).
    - Arithmetic shift right (`sra`) only at `0x21DD44` (`0x00021043`).
    - `u_a1 = (unsigned int)a1`
    - `a1_masked = u_a1 & 0x0E`
    - `bit0 = u_a1 & 0x01`
    - `s1_val = s1 + (((bit0 << 5) + (a1_masked << 6)) & ~0x0F)`
    - `s2_val = ((u_a1 >> 6) << 5) + (u_a1 & 0x10) + (bit0 << 3)`
    - `s3_val = ((u_a1 >> 1) & 0x10) + a1_masked`
- **Second Call: Packet Write 1 (`0x21DD88` – `0x21DDB8`):**
  - Sets parameters on stack and registers:
    - `0(sp) = 8`, `8(sp) = 1`
    - `a1 = 0x1F00`, `a2 = 0`, `a3 = 4`
    - `t0 = s1_val`, `t1 = 2`, `t2 = s2_val`, `t3 = s3_val`
  - `jal 0x1046D0` at `0x21DDB4` with `a0 = s0`.
- **Third Call: Packet Write 2 (`0x21DDBC` – `0x21DDEC`):**
  - Prepares offset parameters:
    - `0(sp) = 8`, `8(sp) = 1`
    - `a1 = 0x1F00`, `a2 = 0`, `a3 = 4`
    - `t0 = s1_val + 0x80`, `t1 = 2`, `t2 = s2_val`, `t3 = s3_val + 1`
  - `jal 0x1046D0` at `0x21DDE8` with `a0 = s0`.
- **Fourth Call: Packet Finalizer (`0x21DDF0` – `0x21DDF4`):**
  - `jal 0x21C050` with `a0 = s0` in its delay slot. The finalizer consumes only `a0` and explicitly returns the packet. A retained `a1 = 0x1F00` is not guaranteed: the preceding writer can clobber caller-saved registers.
  - Existing C++ declarations and stubs still model an extra mode argument and omit both writer stack dimensions. Those repairs remain separate work; existing native coverage does not establish the complete real-call ABI.
- **Epilogue (`0x21DDF8` – `0x21DE10`):**
  - Restores `ra, s3, s2, s1, s0` from stack frame.
  - `jr ra` at `0x21DE0C`.
  - Delay slot at `0x21DE10`: `addiu sp, sp, 96`.
- **Alignment Padding (`0x21DE14` – `0x21DE1C`):**
  - 3 `nop` instructions (12 bytes) aligning to 16-byte boundary for `0x21DE20`.

## 3. C++ Implementation & Verification
- Implemented in `src/trade_action_helper_21DD10.cpp` adhering strictly to C++98 standards, Object Calisthenics, and SOLID principles.
- Native 32-bit test harness in `src/trade_action_helper_21DD10_test.cpp` verifying unconditional allocation, dual packet writes with exact bitwise calculations, logical right shift (`srl`) semantics for negative inputs (e.g. `a1 = -1`), and offset relationships.
- Automated pytest regression in `tests/test_trade_action_helper_21DD10.py`.
- Registered as `NonMatching` in `configure.py`.
