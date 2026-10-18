| Function / Method | VRAM Address | Code Size (Orig) | Slice Size | Match Status | Description |
|---|---|---|---|---|---|
| `func_00340C30` | `0x340C30` | 180 B | 192 B | **Matching (100.00%)** | Tactical AI state handler and memorycard screen notification dispatcher. |

#### 6.193 `GIF/GS Packet Builder Helpers` Subsystem (`0x21BFD0`–`0x21C410`, `trade_action_helper_21BFD0.cpp`)

Located at VRAM `0x21BFD0`–`0x21C410` (file offset `0x11C1B0`–`0x11C5F0`, 1088 bytes total slice, 1072 bytes code + 16 bytes zero padding, Metrowerks C++ PS2 MWCC 2.3.1.01):
- `func_0021BFD0` (`0x21BFD0`, 128 bytes code): Constructs packet object, initializes with tag quadword `D_00392B30` (`0x00008000, 0x10000000, 0x0000000E, 0x00000000`), writes register `0x08`, and finalizes.
- `func_0021C050` (`0x21C050`, 128 bytes code): Constructs packet object, initializes with tag quadword `D_00392B30`, writes register `0x3F` with 0, and finalizes.
- `func_0021C0D0` (`0x21C0D0`, 256 bytes code): Constructs packet object, packs 5-component bitfield into 64-bit value `a1 | (a2<<2) | (a3<<4) | (t0<<6) | (t1<<32)`, writes to register `0x42`, and finalizes.
- `func_0021C1D0` (`0x21C1D0`, 256 bytes code): Constructs packet object, packs 5-component bitfield into 64-bit value `a1 | (a2<<2) | (a3<<4) | (t0<<6) | (t1<<32)`, writes to register `0x43`, and finalizes.
- `func_0021C2D0` (`0x21C2D0`, 304 bytes code): Constructs packet object, packs 8-component bitfield into 64-bit value `a1 | (a2<<1) | (a3<<4) | (t0<<12) | (t1<<14) | (t2<<15) | (t3<<16) | (sp90<<17)`, writes to register `0x48`, and finalizes.

Pure C++ following Object Calisthenics, SOLID, and fail-fast principles. Validated with native regression tests in `tests/native/trade_action_helper_21BFD0_test.cpp` and pytest runner in `tests/test_trade_action_helper_21BFD0.py`.

#### 6.194 `GIF/GS Packet Builder Register Setters` Subsystem (`0x21C410`–`0x21C710`, `trade_action_helper_21C410.cpp`)

Located at VRAM `0x21C410`–`0x21C710` (file offset `0x11C5F0`–`0x11C8F0`, 768 bytes total slice, Metrowerks C++ PS2 MWCC 2.3.1.01):
- `func_0021C410` (`0x21C410`, 144 bytes code): Constructs packet object, initializes with tag quadword `D_00392B30` (`0x00008000, 0x10000000, 0x0000000E, 0x00000000`), converts `a1` with zero-extension to 64-bit, writes to register `0x4A`, and finalizes.
- `func_0021C4A0` (`0x21C4A0`, 144 bytes code): Constructs packet object, initializes with tag quadword `D_00392B30`, converts `a1` with zero-extension to 64-bit, writes to register `0x4B`, and finalizes.
- `func_0021C530` (`0x21C530`, 224 bytes code): Constructs packet object, packs 4-component bitfield into 64-bit value `a1 | (a2<<16) | (a3<<24) | ((u64)t0<<32)`, writes to register `0x4D`, and finalizes.
- `func_0021C610` (`0x21C610`, 128 bytes code): Constructs packet object, initializes with tag quadword `D_00392B30`, writes register `0x48` directly with `a1`, and finalizes.
- `func_0021C690` (`0x21C690`, 128 bytes code): Constructs packet object, initializes with tag quadword `D_00392B30`, writes register `0x41` directly with `a1`, and finalizes.

Pure C++ following Object Calisthenics, SOLID, and fail-fast principles. Validated with native regression tests in `tests/native/trade_action_helper_21C410_test.cpp` and pytest runner in `tests/test_trade_action_helper_21C410.py`.

#### 6.195 `Tactical AI Action Message Handler` Subsystem (`0x340D70`–`0x341040`, `tactical_ai_action_handler_340d70.cpp`)

Located at VRAM `0x340D70`–`0x341040` (file offset `0x240F50`–`0x241220`, 720 bytes total slice, 712 bytes code + 8 bytes padding, Metrowerks C++ PS2 MWCC 2.3.1.01):
- `func_00340D70` (`0x340D70`, 712 bytes code, 720 bytes slice): Evaluates object active state in `field_840`. If -1, exits immediately with 0. Processes action message commands (255, 18, 17, 16, 14, 13, 10, 12, 11) using internal state machine transitions on `field_84C`, handles virtual notification dispatch at offset `0xD0` (`vfunc_d0`), timer refresh via `func_2261c0()`, and state-change notification to helper functions `func_21A1C0` and `func_341040`.

Implemented in pure C++ with native unit tests in `tests/native/tactical_ai_action_handler_340d70_test.cpp` and binary verification in `tests/test_tactical_ai_action_handler_340d70_matching.py`.

#### 6.195.1 Tactical AI Action Message Handler Results (Pure C++, 720 Bytes)

| Function / Method | VRAM Address | Code Size (Orig) | Slice Size | Match Status | Description |
|---|---|---|---|---|---|
| `func_00340D70` | `0x340D70` | 712 B | 720 B | **Decompiled (Pure C++)** | Tactical AI action state transition handler and virtual notification dispatcher. |
