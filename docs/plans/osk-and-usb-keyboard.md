# On-Screen Keyboard (OSK) and USB Keyboard Subsystem Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Decompile the PS2 Win32 keyboard emulation bridge (`0x0036DF30`–`0x0036E76F`), the unified gamepad/keyboard input multiplexer (`0x0036D5F0`), and specify the architectural relationship between the On-Screen Keyboard (OSK) and the physical USB Keyboard in PlayStation 2 PAL `AOK.ELF`.

**Architecture:**
- `include/ps2_keyboard.h` & `src/kcet/ps2_keyboard.c`:
  - Scancode-to-VirtualKey translator using table `0x0048A470`.
  - `func_0036DF30` (`GetAsyncKeyState` for keyboard modifiers Shift/Ctrl/Alt).
  - `func_0036DFB0` (USB HID modifier byte evaluator).
  - `func_0036E010` (Keyboard layout resolver: US 104 vs JP 106/109).
  - `func_0036E0A8` & `func_0036E1F0` (Key-down and key-up event processors generating `WM_KEYDOWN` and `WM_KEYUP`).
  - `func_0036E160` (Typematic key repeat generator via `GetTickCount`).
  - `func_0036E350` (Caps/Num/Scroll Lock LED state synchronization).
  - `func_0036E510` & `func_0036E5E0` (Hardware packet polling loop via `ktKeybdReadPacket` and status monitoring via `ktKeybdGetStatus`).
- `include/ps2_input_multiplexer.h` & `src/kcet/ps2_input_multiplexer.c`:
  - `func_0036D5F0` (Consolidated input status evaluator merging Mouse, Gamepad buttons from `ktPadGetButtons`, and Keyboard modifiers from `func_0036DF30`).
- `include/ps2_osk.h` & `src/app/ps2_osk.cpp`:
  - OSK virtual keyboard state manager: Grid cursor navigation, character selection, and synthetic `WM_CHAR` / `WM_KEYDOWN` event emission into target `TEdit` controls when no physical keyboard is connected (`ktKeybdGetStatus() == 0`).
  - Seamless hot-plug bypass: When a USB keyboard is connected, keystrokes bypass OSK grid navigation and inject directly into the Win32 message pump (`func_00185230` -> `g_wndproc`).

**Tech Stack:** C/C++98 (PS2 EE GCC / MWCC 2.3.1.01 compatibility), 32-bit native test harness (`gcc -m32 -O2 -Iinclude`).

**Spec:** `orig/SLES-50282/AOK.ELF` (SHA1: `f478e19f2059d52899b691483ef5c7522e30e17c`), VRAM `0x0036D5F0`–`0x0036E76F`.

---

## Subsystem Architectural Relationship

```
+-----------------------------------------------------------------------------------+
|                            KCET Hardware Drivers (IOP)                            |
|        USBKEYBD.IRX (HID Driver)               LIBPAD.IRX (DualShock 2)           |
+---------------------------------+---------------------------------+---------------+
                                  |                                 |
                                  v                                 v
+---------------------------------+---------------------------------+---------------+
|                      KCET EE Peripheral Layer (100% Matched)                      |
|   kt_usbkeybd_drv.c (0x137208)                    kt_libpad.c (0x125A70)          |
|   kt_keybd.c (0x135EC0: Ring Buffer,              ktPadGetButtons (0x126410)      |
|               Packets, Status, LEDs)              ktPadGetButtonsPressed          |
+---------------------------------+---------------------------------+---------------+
                                  |                                 |
                                  v                                 v
+-----------------------------------------------------------------------------------+
|               Unified Input Multiplexer & Emulator (0x0036D5F0)                   |
|   - Reads Mouse Work (0x138C110)                                                  |
|   - Reads DualShock 2 Buttons (ktPadGetButtons) -> Emulates Shift/Ctrl on Shoulders|
|   - Queries USB Keyboard Modifiers (func_0036DF30)                                |
|   - Merges Gamepad + Mouse + Keyboard into unified button/modifier mask           |
+-----------------------------------------------------------------------------------+
                                  |
                                  v
+-----------------------------------------------------------------------------------+
|               Win32 Keyboard Event Translation Bridge (0x0036E010)                |
|   - Polled every frame in func_0036E5E0                                           |
|   - Checks connection status: ktKeybdGetStatus(0)                                 |
|   - If Connected (n_keybd > 0):                                                   |
|       * Reads raw HID packets: ktKeybdReadPacket(0, &packet)                      |
|       * Translates HID scancodes via table 0x0048A470 (US 104 vs JP 106/109)      |
|       * Tracks pressed keys in state array 0x0048A270                             |
|       * Generates typematic repeats in func_0036E160                              |
|       * Posts WM_KEYDOWN (0x100), WM_KEYUP (0x101), WM_CHAR (0x102) to Win32 queue|
|   - If Disconnected (n_keybd == 0):                                               |
|       * Disables hardware hotkeys ("Hotkeys cannot be used unless USB keyboard")  |
+-----------------------------------------------------------------------------------+
                                  |
                                  v
+-----------------------------------------------------------------------------------+
|           DualShock 2 On-Screen Keyboard (OSK) / Virtual Character Grid           |
|   - Active when text editing requested without physical keyboard (n_keybd == 0)   |
|   - Navigated via D-Pad / Left Stick (KT_PAD_UP, DOWN, LEFT, RIGHT)               |
|   - Cross (KT_PAD_CROSS): Injects selected char as WM_CHAR into focused edit box  |
|   - Square (KT_PAD_SQUARE): Injects VK_BACK (0x08) backspace                      |
|   - Triangle (KT_PAD_TRIANGLE): Toggles Shift / Caps / Symbols                    |
|   - Start / Circle: Confirms entry and closes OSK dialog                          |
|   - Seamless USB Hot-Plugging: Physical keyboard typing automatically routes to   |
|     the same edit box, bypassing OSK navigation                                   |
+-----------------------------------------------------------------------------------+
                                  |
                                  v
+-----------------------------------------------------------------------------------+
|                     Win32 Event Pump & Message Dispatcher                         |
|   - func_00185230: Pumps messages via PeekMessage / Translate / DispatchMessage   |
|   - func_00186a30 (RenderManager::KeyDispatch):                                   |
|       * Updates global records D_004E89CC (wParam), D_004E89D0 (lParam)           |
|       * Queries modifier states via GetAsyncKeyState (D_004E89D4..D_004E89DC)     |
|       * Intercepts VK_ESCAPE (27) for modal screen cancel                         |
|       * Forwards to target window / edit panel via MethodF4                       |
+-----------------------------------------------------------------------------------+
```

---

## Global Constraints

- Must maintain strict PS2 PAL `AOK.ELF` calling conventions ($a0-$a3, $v0 return register).
- C/C++ native code only; no empty `{}` stubs replacing assembly.
- Zero compiler warnings or errors under `gcc -m32 -O2 -Iinclude`.
- Exact memory address and offsets preserved:
  - `0x0048A470`: USB HID Usage-to-VirtualKey lookup table (256 halfwords).
  - `0x0048A270`: Active pressed keys state array (32 bytes).
  - `0x004954A0`: String `"Hotkeys cannot be used unless a USB keyboard is connected"`.
  - `0x004B6700`: String `"Select Keyboard Type"`.

## Review Focus

1. **HID Scancode Mapping Parity:** Verification that HID usages `0x04`–`0x1D` accurately map to ASCII `'A'`–`'Z'` (`0x41`–`0x5A`) and numbers map to `'1'`–`'0'`.
2. **Keyboard Modifier Independence:** `func_0036DF30` correctly returns `-1` (`0xFFFFFFFF`) when Shift, Ctrl, or Alt are pressed and `0` when released.
3. **Typematic Repeat Cadence:** `func_0036E160` enforces accurate initial delay and repeat intervals using `GetTickCount`.
4. **Unified Input Multiplexer:** `func_0036D5F0` blends gamepad shoulder buttons and USB keyboard modifiers into identical bitmask outputs.
5. **OSK Synthetic Message Parity:** The OSK character injection emits `WM_CHAR` messages indistinguishable from physical USB keyboard messages to the Win32 window procedure.

---

### Task 1: Scancode Translation Table & Modifier Query (`func_0036DF30`, `func_0036DFB0`)

**Files:**
- Create: `include/ps2_keyboard.h`
- Create: `src/kcet/ps2_keyboard.c`
- Create: `tests/native/ps2_keyboard_test.cpp`

**Interfaces:**
- Produces:
  - `func_0036DF30(int vkey) -> int`: Win32 `GetAsyncKeyState` for `VK_SHIFT` (0x10), `VK_CONTROL` (0x11), and `VK_MENU` (0x12).
  - `func_0036DFB0(int mode) -> int`: Evaluates USB HID modifier bytes.
  - `g_usb_scancode_table[256]`: Halfword mapping table at `0x0048A470`.

- [ ] **Step 1: Write the failing tests**
Write tests in `tests/native/ps2_keyboard_test.cpp` verifying `func_0036DF30` modifier reporting for Shift, Ctrl, Alt, and scancode translation parity.

- [ ] **Step 2: Run test to verify it fails**
Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_keyboard_test.cpp src/kcet/ps2_keyboard.c -o /tmp/ps2_keyboard_test`
Expected: Compilation failure (missing symbols `func_0036DF30`, `func_0036DFB0`).

- [ ] **Step 3: Implement functions in `include/ps2_keyboard.h` and `src/kcet/ps2_keyboard.c`**
Implement the lookup table `0x0048A470` and functions `func_0036DF30` and `func_0036DFB0` matching `AOK.ELF`.

- [ ] **Step 4: Run test to verify it passes**
Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_keyboard_test.cpp src/kcet/ps2_keyboard.c -o /tmp/ps2_keyboard_test && /tmp/ps2_keyboard_test`
Expected: PASS.

- [ ] **Step 5: Commit**
```bash
git add include/ps2_keyboard.h src/kcet/ps2_keyboard.c tests/native/ps2_keyboard_test.cpp
git commit -m "feat(keyboard): implement scancode table and func_0036DF30 modifier query"
```

---

### Task 2: Win32 Message Generation Bridge (`func_0036E0A8`, `func_0036E160`, `func_0036E1F0`)

**Files:**
- Modify: `include/ps2_keyboard.h`
- Modify: `src/kcet/ps2_keyboard.c`
- Modify: `tests/native/ps2_keyboard_test.cpp`

**Interfaces:**
- Produces:
  - `func_0036E0A8(int scancode) -> void`: Posts `WM_KEYDOWN` via `func_2263F0` and updates state array.
  - `func_0036E160(int scancode) -> void`: Checks tick interval and posts typematic repeated `WM_KEYDOWN`.
  - `func_0036E1F0(void *prev_packet, void *curr_packet) -> void`: Detects released keys and posts `WM_KEYUP`.

- [ ] **Step 1: Write the failing tests**
Add test cases in `tests/native/ps2_keyboard_test.cpp` verifying message capture for key down, typematic repeat, and key up.

- [ ] **Step 2: Run test to verify it fails**
Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_keyboard_test.cpp src/kcet/ps2_keyboard.c -o /tmp/ps2_keyboard_test`
Expected: FAIL with undefined references to `func_0036E0A8`, `func_0036E160`, `func_0036E1F0`.

- [ ] **Step 3: Implement functions in `src/kcet/ps2_keyboard.c`**
Implement key-down tracking, repeat intervals, and key-up detection with `PostMessage`.

- [ ] **Step 4: Run test to verify it passes**
Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_keyboard_test.cpp src/kcet/ps2_keyboard.c -o /tmp/ps2_keyboard_test && /tmp/ps2_keyboard_test`
Expected: PASS.

- [ ] **Step 5: Commit**
```bash
git add include/ps2_keyboard.h src/kcet/ps2_keyboard.c tests/native/ps2_keyboard_test.cpp
git commit -m "feat(keyboard): implement Win32 key event translation func_0036E0A8, func_0036E160, func_0036E1F0"
```

---

### Task 3: Packet Polling Loop & Update Entry (`func_0036E510`, `func_0036E5E0`)

**Files:**
- Modify: `include/ps2_keyboard.h`
- Modify: `src/kcet/ps2_keyboard.c`
- Modify: `tests/native/ps2_keyboard_test.cpp`

**Interfaces:**
- Produces:
  - `func_0036E510(void) -> int`: Consumes raw packets from `ktKeybdReadPacket` (`func_136190`).
  - `func_0036E5E0(void) -> int`: Main update loop checking `ktKeybdGetStatus` (`func_136230`) and triggering packet dispatch.

- [ ] **Step 1: Write the failing tests**
Add test cases in `tests/native/ps2_keyboard_test.cpp` verifying poll loop execution with mocked `ktKeybdReadPacket` and `ktKeybdGetStatus`.

- [ ] **Step 2: Run test to verify it fails**
Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_keyboard_test.cpp src/kcet/ps2_keyboard.c -o /tmp/ps2_keyboard_test`
Expected: FAIL with undefined references to `func_0036E510`, `func_0036E5E0`.

- [ ] **Step 3: Implement packet loop and update entry**
Implement `func_0036E510` and `func_0036E5E0` matching binary assembly.

- [ ] **Step 4: Run test to verify it passes**
Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_keyboard_test.cpp src/kcet/ps2_keyboard.c -o /tmp/ps2_keyboard_test && /tmp/ps2_keyboard_test`
Expected: PASS.

- [ ] **Step 5: Commit**
```bash
git add include/ps2_keyboard.h src/kcet/ps2_keyboard.c tests/native/ps2_keyboard_test.cpp
git commit -m "feat(keyboard): implement keyboard update and polling loop func_0036E510 and func_0036E5E0"
```

---

### Task 4: Unified Input Multiplexer (`func_0036D5F0`)

**Files:**
- Create: `include/ps2_input_multiplexer.h`
- Create: `src/kcet/ps2_input_multiplexer.c`
- Create: `tests/native/ps2_input_multiplexer_test.cpp`

**Interfaces:**
- Consumes:
  - `ktPadGetButtons` (`func_00126410`) from `kt_libpad.c`.
  - `func_0036DF30` from `ps2_keyboard.c`.
  - Mouse work struct at `0x0138C110`.
- Produces:
  - `func_0036D5F0(int *out_flags) -> void`: Combines gamepad, mouse, and keyboard modifiers into unified flags.

- [ ] **Step 1: Write the failing tests**
Write tests in `tests/native/ps2_input_multiplexer_test.cpp` asserting that gamepad L1/R1 and USB keyboard Shift/Ctrl set the corresponding output bits in `*out_flags`.

- [ ] **Step 2: Run test to verify it fails**
Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_input_multiplexer_test.cpp src/kcet/ps2_input_multiplexer.c -o /tmp/ps2_input_multiplexer_test`
Expected: FAIL with undefined reference to `func_0036D5F0`.

- [ ] **Step 3: Implement `func_0036D5F0` in `src/kcet/ps2_input_multiplexer.c`**
Implement input consolidation matching `AOK.ELF 0x0036D5F0`.

- [ ] **Step 4: Run test to verify it passes**
Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_input_multiplexer_test.cpp src/kcet/ps2_input_multiplexer.c -o /tmp/ps2_input_multiplexer_test && /tmp/ps2_input_multiplexer_test`
Expected: PASS.

- [ ] **Step 5: Commit**
```bash
git add include/ps2_input_multiplexer.h src/kcet/ps2_input_multiplexer.c tests/native/ps2_input_multiplexer_test.cpp
git commit -m "feat(input): implement unified input multiplexer func_0036D5F0"
```

---

### Task 5: On-Screen Keyboard (OSK) Character Injection & Interplay Subsystem

**Files:**
- Create: `include/ps2_osk.h`
- Create: `src/app/ps2_osk.cpp`
- Create: `tests/native/ps2_osk_test.cpp`

**Interfaces:**
- Consumes:
  - DualShock 2 buttons (`KT_PAD_UP`, `KT_PAD_DOWN`, `KT_PAD_LEFT`, `KT_PAD_RIGHT`, `KT_PAD_CROSS`, `KT_PAD_SQUARE`).
  - `ktKeybdGetStatus` from `kt_keybd.h`.
- Produces:
  - `OSK_Init(OSKState *state, int max_len)`
  - `OSK_ProcessInput(OSKState *state, u16 pad_buttons, u16 pad_pressed) -> int`
  - `OSK_InjectCharacter(void *target_edit_panel, char c) -> void`
  - `OSK_IsKeyboardActive() -> int`

- [ ] **Step 1: Write the failing tests**
Write tests in `tests/native/ps2_osk_test.cpp` validating:
1. Navigation across the virtual character grid via D-Pad events.
2. Selection with Cross emits synthetic `WM_CHAR` with matching ASCII character into target control.
3. Square emits Backspace (`VK_BACK` / 0x08).
4. Physical USB keyboard presence (`ktKeybdGetStatus() > 0`) bypasses OSK navigation, delivering direct keystrokes.

- [ ] **Step 2: Run test to verify it fails**
Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_osk_test.cpp src/app/ps2_osk.cpp -o /tmp/ps2_osk_test`
Expected: FAIL with undefined references.

- [ ] **Step 3: Implement OSK logic in `src/app/ps2_osk.cpp`**
Implement the virtual keyboard grid navigation, character map, synthetic message injection, and USB hot-plug switching logic.

- [ ] **Step 4: Run test to verify it passes**
Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_osk_test.cpp src/app/ps2_osk.cpp -o /tmp/ps2_osk_test && /tmp/ps2_osk_test`
Expected: PASS.

- [ ] **Step 5: Commit**
```bash
git add include/ps2_osk.h src/app/ps2_osk.cpp tests/native/ps2_osk_test.cpp
git commit -m "feat(osk): implement on-screen keyboard grid and USB keyboard interplay"
```

---

### Task 6: Full Subsystem Regression Verification Gate

**Files:**
- Verify all native test suites across the repository.

- [ ] **Step 1: Run all test suites**
Run:
```sh
gcc -m32 -O2 -Iinclude tests/native/ps2_keyboard_test.cpp src/kcet/ps2_keyboard.c -o /tmp/ps2_keyboard_test && /tmp/ps2_keyboard_test && \
gcc -m32 -O2 -Iinclude tests/native/ps2_input_multiplexer_test.cpp src/kcet/ps2_input_multiplexer.c -o /tmp/ps2_input_multiplexer_test && /tmp/ps2_input_multiplexer_test && \
gcc -m32 -O2 -Iinclude tests/native/ps2_osk_test.cpp src/app/ps2_osk.cpp -o /tmp/ps2_osk_test && /tmp/ps2_osk_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_keybd_test.c src/kcet/kt_keybd.c -o /tmp/kt_keybd_test && /tmp/kt_keybd_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_libpad_test.c src/kcet/kt_libpad.c -o /tmp/kt_libpad_test && /tmp/kt_libpad_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_mouse_test.c src/kcet/kt_mouse.c -o /tmp/kt_mouse_test && /tmp/kt_mouse_test && \
gcc -m32 -O2 -Iinclude tests/native/tribe_app_test.cpp src/app/tribe_app.cpp -o /tmp/tribe_app_test && /tmp/tribe_app_test
```
Expected: All suites pass 100% with 0 warnings.
