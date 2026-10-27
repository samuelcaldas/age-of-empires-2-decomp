# Decompilation of PS2 Mouse Subsystem & Absolute Positioning Support Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Decompile the PS2 Win32 mouse cursor accumulator and message generator subsystem (`func_00225580` GetCursorPos, `func_002255A0` SetCursorPos, `func_0036D700` Mouse_Update), and implement dual-mode operation supporting both vanilla relative delta integration and modern absolute cursor positioning for recompilations and touchscreens.

**Context:**
In vanilla PlayStation 2 *Age of Empires II*, the USB mouse driver (`kt_mouse.c` / `USBMOUSE.IRX`) emits relative motion packets $(dX, dY)$. The game's Win32 adaptation layer (`func_0036D700`) accumulates these deltas into global cursor coordinates $(X, Y)$ clamped to $640 \times 480$.
In modern PC recompilations, windowed environments, and touchscreen/tablet devices, relative integration introduces cursor desync, latency, and sensitivity drift relative to the host OS cursor. Decompiling this subsystem allows us to maintain 100% binary matching for vanilla relative mouse packets while introducing a first-class absolute positioning path (`Mouse_SetAbsolutePosition`) that feeds direct host coordinates seamlessly into the Win32 message pump (`WM_MOUSEMOVE`, `WM_LBUTTONDOWN`, etc.).

**Architecture:**
- `include/ps2_mouse.h` & `src/kcet/ps2_mouse.c`:
  - Global cursor coordinates `g_cursor_x` (`D_004E89C0`) and `g_cursor_y` (`D_004E89C4`).
  - `func_00225580` (`GetCursorPos`) and `func_002255A0` (`SetCursorPos` with $[0..639] \times [0..479]$ clamping).
  - `func_0036D700` (`Mouse_Update` / `PollMouse`): Drains `ktMouseReadPacket`, applies sensitivity scaling, handles 250 ms double-click timing, and posts Win32 messages (`WM_MOUSEMOVE`, `WM_LBUTTONDOWN`, `WM_LBUTTONUP`, `WM_LBUTTONDBLCLK`, `WM_RBUTTONDOWN`, `WM_RBUTTONUP`, `WM_MBUTTONDOWN`, `WM_MOUSEWHEEL`) via `func_2263F0` (`PostMessage`).
  - Absolute positioning extension: `Mouse_SetMode(int mode)` (`0 = RELATIVE`, `1 = ABSOLUTE`), `Mouse_SetAbsolutePosition(int x, int y, unsigned int buttons)`. In absolute mode, host coordinates directly update `(g_cursor_x, g_cursor_y)` and post standard Win32 mouse messages.
- `tests/native/ps2_mouse_test.cpp`:
  - 32-bit hermetic native test suite covering coordinate clamping, relative delta accumulation, double-click detection, button state transitions, and absolute coordinate injection.

**Tech Stack:** C/C++98 (PS2 EE GCC / MWCC compatibility), 32-bit native test harness (`gcc -m32 -O2 -Iinclude`).

**Spec:** `orig/SLES-50282/AOK.ELF` (SHA1: `f478e19f2059d52899b691483ef5c7522e30e17c`), VRAM `0x00225580`–`0x002255C8` and `0x0036D700`–`0x0036DF30`.

## Global Constraints

- Must match PlayStation 2 PAL `AOK.ELF` calling conventions ($a0-$a3, $v0 return register).
- C/C++ native code only; no empty `{}` stubs replacing assembly.
- Zero compiler warnings or errors under `gcc -m32 -O2 -Iinclude`.
- Exact memory address and offsets preserved:
  - `D_004E89C0`: Global cursor $X$ coordinate ($0 \le X \le 639$).
  - `D_004E89C4`: Global cursor $Y$ coordinate ($0 \le Y \le 479$).
  - Screen resolution bounds: Width 640 (`0x280`), Height 480 (`0x1E0`).
  - Double-click timeout threshold: 250 ms (`0xFA`).

## Review Focus

1. **Boundary Clamping:** `SetCursorPos` and relative accumulation must strictly clamp $X \in [0, 639]$ and $Y \in [0, 479]$, correctly handling negative inputs and overflow.
2. **Double-Click Timing:** A second left-click within 250 ms at the same position emits `WM_LBUTTONDBLCLK` (0x203) instead of `WM_LBUTTONDOWN` (0x201).
3. **lParam Packing Parity:** All mouse messages must pack coordinates as `lParam = (Y << 16) | (X & 0xFFFF)`.
4. **Wheel & Button Mask Independence:** Middle mouse button and wheel deltas are accurately processed without corrupting primary button state.
5. **Absolute Mode Non-Interference:** In absolute mode, relative deltas from hardware USB packets are ignored, and `Mouse_SetAbsolutePosition` updates cursor position with zero latency or jitter.

---

### Task 1: Decompile `GetCursorPos` (`func_00225580`) and `SetCursorPos` (`func_002255A0`)

**Files:**
- Create: `include/ps2_mouse.h`
- Create: `src/kcet/ps2_mouse.c`
- Create: `tests/native/ps2_mouse_test.cpp`

**Interfaces:**
- Produces:
  - `g_cursor_x`, `g_cursor_y`: Global coordinates at `D_004E89C0` and `D_004E89C4`.
  - `func_00225580(POINT *pt) -> int`: Win32 `GetCursorPos`.
  - `func_002255A0(int x, int y) -> int`: Win32 `SetCursorPos` with bounds clamping $[0..639] \times [0..479]$.

- [ ] **Step 1: Write the failing tests**

```cpp
// tests/native/ps2_mouse_test.cpp
void test_cursor_pos_get_set() {
    POINT pt = {0, 0};
    func_002255A0(100, 200);
    func_00225580(&pt);
    assert(pt.x == 100);
    assert(pt.y == 200);

    // Clamping: negative values clamp to 0
    func_002255A0(-50, -100);
    func_00225580(&pt);
    assert(pt.x == 0);
    assert(pt.y == 0);

    // Clamping: overflow clamps to 639 and 479
    func_002255A0(1000, 800);
    func_00225580(&pt);
    assert(pt.x == 639);
    assert(pt.y == 479);

    printf("PASS: test_cursor_pos_get_set\n");
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_mouse_test.cpp src/kcet/ps2_mouse.c -o /tmp/ps2_mouse_test`
Expected: Compilation failure (missing `ps2_mouse.h`, `ps2_mouse.c`).

- [ ] **Step 3: Implement `include/ps2_mouse.h` and `src/kcet/ps2_mouse.c`**

In `include/ps2_mouse.h`:
```c
typedef struct {
    int x;
    int y;
} POINT;

extern int g_cursor_x;
extern int g_cursor_y;

int func_00225580(POINT *pt);
int func_002255A0(int x, int y);

#define GetCursorPos func_00225580
#define SetCursorPos func_002255A0
```

In `src/kcet/ps2_mouse.c`:
```c
int g_cursor_x = 0;
int g_cursor_y = 0;

int func_00225580(POINT *pt) {
    if (!pt) return 0;
    pt->x = g_cursor_x;
    pt->y = g_cursor_y;
    return 1;
}

int func_002255A0(int x, int y) {
    if (x < 0) x = 0;
    if (x > 639) x = 639;
    if (y < 0) y = 0;
    if (y > 479) y = 479;
    g_cursor_x = x;
    g_cursor_y = y;
    return 1;
}
```

- [ ] **Step 4: Run test to verify it passes**

Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_mouse_test.cpp src/kcet/ps2_mouse.c -o /tmp/ps2_mouse_test && /tmp/ps2_mouse_test`
Expected: PASS: `test_cursor_pos_get_set`.

- [ ] **Step 5: Commit**

```bash
git add include/ps2_mouse.h src/kcet/ps2_mouse.c tests/native/ps2_mouse_test.cpp
git commit -m "feat(mouse): decompile GetCursorPos (0x225580) and SetCursorPos (0x2255A0)"
```

---

### Task 2: Decompile Mouse Event & Double-Click Dispatcher (`func_0036D700` Button Logic)

**Files:**
- Modify: `include/ps2_mouse.h`
- Modify: `src/kcet/ps2_mouse.c`
- Modify: `tests/native/ps2_mouse_test.cpp`

**Interfaces:**
- Produces:
  - `func_0036D700_dispatch_buttons(unsigned int new_buttons, unsigned int prev_buttons, unsigned int now_tick) -> void`
  - Win32 Message Dispatch: `WM_LBUTTONDOWN` (0x201), `WM_LBUTTONUP` (0x202), `WM_LBUTTONDBLCLK` (0x203), `WM_RBUTTONDOWN` (0x204), `WM_RBUTTONUP` (0x205), `WM_MBUTTONDOWN` (0x207), `WM_MBUTTONUP` (0x208).

- [ ] **Step 1: Write the failing tests**

Write tests asserting:
1. Pressing LMB posts `WM_LBUTTONDOWN` with packed coordinates in `lParam`.
2. Releasing LMB posts `WM_LBUTTONUP`.
3. Pressing LMB twice within 250 ms (`0xFA`) posts `WM_LBUTTONDBLCLK`.
4. Pressing LMB after > 250 ms posts a second `WM_LBUTTONDOWN` (not a double-click).
5. RMB and MMB transitions post matching messages.

- [ ] **Step 2: Run test to verify it fails**

Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_mouse_test.cpp src/kcet/ps2_mouse.c -o /tmp/ps2_mouse_test`
Expected: FAIL with undefined reference.

- [ ] **Step 3: Implement button dispatcher in `src/kcet/ps2_mouse.c`**

Implement button delta comparison and double-click interval checking ($250\text{ ms}$).

- [ ] **Step 4: Run test to verify it passes**

Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_mouse_test.cpp src/kcet/ps2_mouse.c -o /tmp/ps2_mouse_test && /tmp/ps2_mouse_test`
Expected: PASS: `test_cursor_pos_get_set` and `test_mouse_button_dispatch`.

- [ ] **Step 5: Commit**

```bash
git add include/ps2_mouse.h src/kcet/ps2_mouse.c tests/native/ps2_mouse_test.cpp
git commit -m "feat(mouse): implement mouse button transition and double-click dispatcher"
```

---

### Task 3: Decompile Relative Motion Accumulator (`func_0036D700`)

**Files:**
- Modify: `include/ps2_mouse.h`
- Modify: `src/kcet/ps2_mouse.c`
- Modify: `tests/native/ps2_mouse_test.cpp`

**Interfaces:**
- Consumes:
  - `ktMouseReadPacket` (`func_00135118`) from `kt_mouse.h`.
  - `ktMouseGetStatus` (`func_00135258`).
- Produces:
  - `func_0036D700(void) -> int`: Full mouse update tick consuming hardware packets, integrating relative deltas, and posting `WM_MOUSEMOVE` and button messages.

- [ ] **Step 1: Write the failing tests**

Write tests in `tests/native/ps2_mouse_test.cpp` asserting that relative packets with $(dX, dY)$ update `(g_cursor_x, g_cursor_y)`, clamp at screen edges, and post `WM_MOUSEMOVE` (0x200).

- [ ] **Step 2: Run test to verify it fails**

Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_mouse_test.cpp src/kcet/ps2_mouse.c -o /tmp/ps2_mouse_test`
Expected: FAIL with undefined reference to `func_0036D700`.

- [ ] **Step 3: Implement `func_0036D700` in `src/kcet/ps2_mouse.c`**

Implement relative packet polling loop, sensitivity scaling, coordinate accumulation, and Win32 message dispatch matching `AOK.ELF 0x0036D700`.

- [ ] **Step 4: Run test to verify it passes**

Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_mouse_test.cpp src/kcet/ps2_mouse.c -o /tmp/ps2_mouse_test && /tmp/ps2_mouse_test`
Expected: PASS.

- [ ] **Step 5: Commit**

```bash
git add include/ps2_mouse.h src/kcet/ps2_mouse.c tests/native/ps2_mouse_test.cpp
git commit -m "feat(mouse): decompile relative motion accumulator func_0036D700"
```

---

### Task 4: Implement Absolute Mouse Positioning Extension

**Files:**
- Modify: `include/ps2_mouse.h`
- Modify: `src/kcet/ps2_mouse.c`
- Modify: `tests/native/ps2_mouse_test.cpp`

**Interfaces:**
- Produces:
  - `Mouse_SetMode(int mode) -> void`: `MOUSE_MODE_RELATIVE = 0`, `MOUSE_MODE_ABSOLUTE = 1`.
  - `Mouse_GetMode(void) -> int`.
  - `Mouse_SetAbsolutePosition(int x, int y, unsigned int buttons) -> void`: Injects direct host coordinates and button states without relative drift.

- [ ] **Step 1: Write the failing tests**

```cpp
void test_absolute_mouse_mode() {
    Mouse_SetMode(MOUSE_MODE_ABSOLUTE);
    assert(Mouse_GetMode() == MOUSE_MODE_ABSOLUTE);

    s_post_count = 0;
    Mouse_SetAbsolutePosition(320, 240, 0x01); // LMB at center screen
    assert(g_cursor_x == 320);
    assert(g_cursor_y == 240);
    assert(s_posted_msg == 0x201); // WM_LBUTTONDOWN
    assert(s_posted_lparam == ((240 << 16) | 320));

    // When in absolute mode, func_0036D700 ignores relative dX, dY packets
    s_mock_dx = 50;
    s_mock_dy = 50;
    func_0036D700();
    assert(g_cursor_x == 320); // Position unchanged by relative packet
    assert(g_cursor_y == 240);

    // Return to relative mode
    Mouse_SetMode(MOUSE_MODE_RELATIVE);
    func_0036D700();
    assert(g_cursor_x == 370); // Accumulated

    printf("PASS: test_absolute_mouse_mode\n");
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_mouse_test.cpp src/kcet/ps2_mouse.c -o /tmp/ps2_mouse_test`
Expected: FAIL with undefined reference to `Mouse_SetMode`, `Mouse_SetAbsolutePosition`.

- [ ] **Step 3: Implement absolute positioning in `src/kcet/ps2_mouse.c`**

Implement mode switch, coordinate override, and synthetic event posting.

- [ ] **Step 4: Run test to verify it passes**

Run: `gcc -m32 -O2 -Iinclude tests/native/ps2_mouse_test.cpp src/kcet/ps2_mouse.c -o /tmp/ps2_mouse_test && /tmp/ps2_mouse_test`
Expected: PASS: all mouse unit tests pass.

- [ ] **Step 5: Commit**

```bash
git add include/ps2_mouse.h src/kcet/ps2_mouse.c tests/native/ps2_mouse_test.cpp
git commit -m "feat(mouse): implement absolute positioning mode extension"
```

---

### Task 5: Subsystem Regression Verification Gate

**Files:**
- Verify all 13 test suites across the repository.

- [ ] **Step 1: Run all 13 test suites**

Run:
```sh
gcc -m32 -O2 -Iinclude tests/native/ps2_mouse_test.cpp src/kcet/ps2_mouse.c -o /tmp/ps2_mouse_test && /tmp/ps2_mouse_test && \
gcc -m32 -O2 -Iinclude tests/native/ps2_keyboard_test.cpp src/kcet/ps2_keyboard.c -o /tmp/ps2_keyboard_test && /tmp/ps2_keyboard_test && \
gcc -m32 -O2 -Iinclude tests/native/ps2_input_multiplexer_test.cpp src/kcet/ps2_input_multiplexer.c src/kcet/ps2_keyboard.c -o /tmp/ps2_input_multiplexer_test && /tmp/ps2_input_multiplexer_test && \
gcc -m32 -O2 -Iinclude tests/native/ps2_osk_test.cpp src/app/ps2_osk.cpp -o /tmp/ps2_osk_test && /tmp/ps2_osk_test && \
gcc -m32 -O2 -Iinclude tests/native/screen_manager_test.cpp src/app/screen_manager.cpp src/kcet/overlay_loader.c -o /tmp/screen_manager_test && /tmp/screen_manager_test && \
gcc -m32 -O2 -Iinclude tests/native/game_window_test.cpp src/kcet/game_window.c -o /tmp/game_window_test && /tmp/game_window_test && \
gcc -m32 -O2 -Iinclude tests/native/smenu_loader_test.c src/kcet/overlay_loader.c -o /tmp/smenu_loader_test && /tmp/smenu_loader_test && \
gcc -m32 -O2 -Iinclude tests/native/overlay_loader_test.c src/kcet/overlay_loader.c -o /tmp/overlay_loader_test && /tmp/overlay_loader_test && \
gcc -m32 -O2 -Iinclude tests/native/tribe_app_test.cpp src/app/tribe_app.cpp src/kcet/game_window.c -o /tmp/tribe_app_test && /tmp/tribe_app_test && \
gcc -m32 -O2 -Iinclude tests/native/game_thread_test.c src/kcet/game_thread.c src/kcet/kt_libcdvd_server.c -Wl,--unresolved-symbols=ignore-in-object-files -o /tmp/game_thread_test && /tmp/game_thread_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_sound_test.c src/kcet/kt_sound.c -o /tmp/kt_sound_test && /tmp/kt_sound_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_libpad_test.c src/kcet/kt_libpad.c -o /tmp/kt_libpad_test && /tmp/kt_libpad_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_mouse_test.c src/kcet/kt_mouse.c -o /tmp/kt_mouse_test && /tmp/kt_mouse_test
```
Expected: All 13 test suites pass with 100% and 0 warnings.
