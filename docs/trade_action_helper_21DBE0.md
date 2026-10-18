# Trade Action Helper `0x21DBE0` (`trade_action_helper_21DBE0.cpp`)

## 1. Overview and ELF Mapping
- **VRAM Address Range:** `0x21DBE0` – `0x21DC48` (Size: `0x68` bytes / 104 bytes, end-exclusive)
- **File Offset Range:** `0x11DDC0` – `0x11DE28` in `orig/SLES-50282/AOK.ELF`
- **Segment / Section:** `.text` (ELF load delta: `0xFFE20`)

## 2. Binary Analysis & Disassembly Trace
- **Prologue (`0x21DBE0` – `0x21DBE8`):**
  - `addiu sp, sp, -48` (Allocate stack frame)
  - `sd ra, 32(sp)` (Save return address)
  - `sd s0, 16(sp)` (Save saved register s0)
- **Local Stack & Argument Setup (`0x21DBEC` – `0x21DC24`):**
  - Initializes local work variables on stack (`0(sp)`, `8(sp)`).
  - Prepares argument registers (`a1 = 0x1F00`, values derived from `a2`).
- **Function Calls (`0x21DC28` & `0x21DC30`):**
  - `jal 0x1046D0` (at `0x21DC28`, machine word `0x0C0411B4`): Invokes register write helper with target register `0x1F00` and data `a2`.
  - `jal 0x21C050` (at `0x21DC30`, machine word `0x0C087014`): Invokes mode update helper with mode `a3`.
- **Epilogue (`0x21DC38` – `0x21DC44`):**
  - `ld ra, 32(sp)` (Restore return address)
  - `ld s0, 16(sp)` (Restore s0)
  - `jr ra` (Return at `0x21DC40`)
  - `addiu sp, sp, 48` (Delay slot at `0x21DC44`: deallocate stack frame)

## 3. C++ Implementation & Verification
- Implemented in `src/trade_action_helper_21DBE0.cpp` following strict C++98 purity, Object Calisthenics, SOLID, and fail-fast principles.
- Tested via native 32-bit test harness (`src/trade_action_helper_21DBE0_test.cpp`) covering multiple distinct invocation scenarios (standard arguments, variant argument forwarding, and null-pointer safety with strict side-effect isolation).
- Validated via automated pytest suite (`tests/test_trade_action_helper_21DBE0.py`).
- Registered as `NonMatching` in `configure.py` pending licensed Metrowerks compiler availability for exact byte-matching verification (`objdiff`).
