# Trade Action Helper `0x21DBE0` (`trade_action_helper_21DBE0.cpp`)

## 1. Overview and ELF Mapping
- **VRAM Address Range:** `0x21DBE0` – `0x21DC44` (Size: `0x64` bytes / 100 bytes)
- **File Offset Range:** `0x11DDC0` – `0x11DE24` in `orig/SLES-50282/AOK.ELF`
- **Segment / Section:** `.text` (ELF load delta: `0xFFE20`)

## 2. Binary Analysis & Disassembly Trace
- **Prologue (`0x21DBE0`):**
  - `addiu sp, sp, -48` (Allocate stack frame)
  - `sd ra, 32(sp)` (Save return address)
  - `sd s0, 16(sp)` (Save saved register s0)
- **Local Stack & Argument Setup:**
  - Initializes local work variables on stack (`0(sp)`, `8(sp)`).
  - Prepares argument registers (`a1 = 0x1F00`, values derived from `a2`).
- **Function Calls:**
  - `jal 0x1046D0` (at `0x21DC28`): Invokes register write helper with target register `0x1F00` and data `a2`.
  - `jal 0x21C050` (at `0x21DC30`): Invokes mode update helper with mode `a3`.
- **Epilogue (`0x21DC38` – `0x21DC44`):**
  - `ld ra, 32(sp)` (Restore return address)
  - `ld s0, 16(sp)` (Restore s0)
  - `jr ra` (Return)
  - `addiu sp, sp, 48` (Delay slot: deallocate stack frame)

## 3. C++ Implementation & Verification
- Implemented in `src/trade_action_helper_21DBE0.cpp` following strict C++98 purity, Object Calisthenics, SOLID, and fail-fast principles.
- Tested via native 32-bit test harness (`src/trade_action_helper_21DBE0_test.cpp`) asserting non-null object return, exact call order (`func_1046D0` then `func_21C050`), exact register `0x1F00` passing, argument forwarding, and null-pointer safety with strict side-effect verification (ensuring zero calls when `obj == 0`).
- Validated via automated pytest suite (`tests/test_trade_action_helper_21DBE0.py`).
