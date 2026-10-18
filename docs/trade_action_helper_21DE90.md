# Trade Action Helper `0x21DE90` (`trade_action_helper_21DE90.cpp`)

## 1. Overview and ELF Mapping
- **VRAM Address Range:** `0x21DE90` – `0x21DF48` (Size: `0xC0` bytes / 192 bytes, end-exclusive to `0x21DF50`)
- **File Offset Range:** `0x11E070` – `0x11E130` in `orig/SLES-50282/AOK.ELF`
- **Segment / Section:** `.text` (ELF load delta: `0xFFE20`)

## 2. Binary Analysis & Disassembly Trace
- **Prologue (`0x21DE90` – `0x21DEB0`):**
  - `addiu sp, sp, -160` (Allocate stack frame of 160 bytes)
  - `sq ra, 144(sp)`, `sq s7, 128(sp)`, `sq s6, 112(sp)`, `sq s5, 96(sp)`
  - `sq s4, 80(sp)`, `sq s3, 64(sp)`, `sq s2, 48(sp)`, `sq s1, 32(sp)`, `sq s0, 16(sp)`
- **Argument Preservation (`0x21DEB4` – `0x21DED4`):**
  - Preserves incoming arguments `a0..t3` into callee-saved registers `s6..s0, s7`:
    - `s6 = a0`, `s5 = a1`, `s4 = a2`, `s3 = a3`
    - `s2 = t0`, `s1 = t1`, `s0 = t2`, `s7 = t3`
- **First Call: Buffer Allocation (`0x21DED8` – `0x21DEDC`):**
  - Delay slot at `0x21DEBC`: `addiu a0, zero, 0xC` (Argument `0xC = 12`)
  - `jal func_221B60` (Target `0x221B60`): Unconditionally allocates buffer.
  - Return value `v0` holds allocated buffer pointer.
- **Sign-Extension and Second Call (`0x21DEE0` – `0x21DF10`):**
  - Sign-extends 16-bit short arguments via `dsll32 reg, in, 16` followed by `dsra32 reg, reg, 16`:
    - `a1 = (short)s6` (`(short)a0`)
    - `a2 = (short)s5` (`(short)a1`)
    - `a3 = (short)s4` (`(short)a2`)
  - Delay slot at `0x21DEF8`: `paddub a0, v0, zero` (Pass buffer pointer from Call 1 in `a0`)
  - Forwards `t0 = s3`, `t1 = s2`, `t2 = s1`, `t3 = s0`, and stores `s7` at `0(sp)`.
  - `jal func_0021DF50` at `0x21DF0C`.
- **Third Call: Resource Reconfiguration (`0x21DF14` – `0x21DF18`):**
  - Delay slot at `0x21DF18`: `addiu a0, zero, 0x100` (Argument `0x100 = 256`)
  - `jal func_221B60` at `0x21DF14`.
- **Fourth Call: Cleanup / Finalization (`0x21DF1C` – `0x21DF20`):**
  - `jal func_221AC0` at `0x21DF1C` with `nop` in delay slot.
- **Epilogue (`0x21DF24` – `0x21DF4C`):**
  - Restores `s0` through `s7` and `ra`.
  - `jr ra` at `0x21DF48`.
  - Delay slot at `0x21DF4C`: `addiu sp, sp, 160`.

## 3. C++ Implementation & Verification
- Implemented in `src/trade_action_helper_21DE90.cpp` adhering strictly to C++98 standards, Object Calisthenics, and SOLID principles.
- Removed invented `if (obj == 0) return 0;` null guard, ensuring 100% fidelity to the unconditional binary execution trace.
- Native 32-bit test harness in `src/trade_action_helper_21DE90_test.cpp` verifying unconditional execution, exact call sequence (`B60(0xC)` -> `DF50` -> `B60(0x100)` -> `AC0`), and short sign-extension semantics.
- Automated pytest regression in `tests/test_trade_action_helper_21DE90.py`.
- Registered as `NonMatching` in `configure.py`.
