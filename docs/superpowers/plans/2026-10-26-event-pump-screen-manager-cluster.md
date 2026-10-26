# Event Loop Pump (`func_00185230`) and Screen Manager Cluster Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Decompile the genuine Win32 event loop pump (`func_00185230`), `multimcd.bin` loader (`func_00300C60`), and the screen transition cluster (`func_002FD5A0`, `func_002FD5C0`, `func_002FC350`, `func_002FC510`, `func_002F8EA0`), eliminating the hardcoded `func_00300C90` jump and restoring binary-accurate screen transitions.

**Architecture:**
- `include/overlay_loader.h` & `src/kcet/overlay_loader.c`: Declares and implements `func_00300C60` (`multimcd.bin` streaming).
- `include/tribe_app.h` & `src/app/tribe_app.cpp`: Updates `func_00185230` to run the real Win32 message loop (`TranslateMessage`, `DispatchMessage`, virtual idle/dispatch methods) without calling `func_00300C90`.
- `include/screen_manager.h` & `src/app/screen_manager.cpp`: Implements the screen transition cluster that manages screen arrays, panel allocation, and routes to `func_00300C90` (`smenu_cd.bin` loader).
- `tests/native/`: Comprehensive unit and regression suites verifying message loop termination, virtual method dispatch, and overlay loading triggers.

**Tech Stack:** C/C++98 (PS2 EE GCC / MWCC compatibility), 32-bit native test harness (`gcc -m32 -O2`).

**Spec:** `docs/superpowers/specs/2026-10-26-event-pump-screen-manager-cluster-design.md`, `orig/SLES-50282/AOK.ELF` (SHA1: `f478e19f2059d52899b691483ef5c7522e30e17c`).

## Global Constraints

- Must match PlayStation 2 PAL `AOK.ELF` calling conventions ($a0-$a3, $v0 return register).
- C/C++ native code only; no empty `{}` stubs replacing assembly.
- Zero compiler warnings or errors under `gcc -m32 -O2 -Iinclude`.
- Exact memory addresses and symbols preserved:
  - `OVERLAY_LOAD_ADDR = 0x01D98000`.
  - `smenu_cd.bin` and `multimcd.bin` file strings at `0x004D1868` and `0x004D1858`.
  - Screen state array offsets `0x191C` and `0x1924`.

## Review Focus

1. `func_00185230` with `self->field_1C == 1`: terminates pump loop immediately and returns 0.
2. `func_00185230` during idle loop: dispatches virtual methods `0xA8` and `0xAC` without calling `func_00300C90`.
3. `func_00300C60` disc read retry: polls `func_002240B0` until return is non-zero, loading `"multimcd.bin"` into `0x01D98000`.
4. `func_002FD5C0`: clears arrays at `0x191C` and `0x1924`, releases previous panel at `0x1468`, streams `"smenu_cd.bin"`, and registers screen.
5. `func_002FC350` & `func_002FC510`: properly delegate to `func_002FD5C0`.

---

### Task 1: Decompile `func_00300C60` (`multimcd.bin` Streamer)

**Files:**
- Modify: `include/overlay_loader.h`
- Modify: `src/kcet/overlay_loader.c`
- Modify: `tests/native/smenu_loader_test.c`

**Interfaces:**
- Consumes: `func_002240B0(filename, dest)` from `include/game_thread.h`.
- Produces: `func_00300C60(void) -> int`.

- [ ] **Step 1: Write the failing test**

```c
// tests/native/smenu_loader_test.c
void test_multimcd_loader(void) {
    s_overlay_read_count = 0;
    int res = func_00300C60();
    assert(res == 1);
    assert(s_overlay_read_count == 2);
    assert(strcmp(s_last_filename, "multimcd.bin") == 0);
    assert(s_last_dest == (void *)0x01D98000);
    printf("PASS: test_multimcd_loader\n");
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `gcc -m32 -O2 -Iinclude tests/native/smenu_loader_test.c src/kcet/overlay_loader.c -o /tmp/smenu_loader_test`
Expected: FAIL with implicit declaration / undefined reference to `func_00300C60`.

- [ ] **Step 3: Implement `func_00300C60` in `include/overlay_loader.h` and `src/kcet/overlay_loader.c`**

In `include/overlay_loader.h`:
```c
int func_00300C60(void);
```

In `src/kcet/overlay_loader.c`:
```c
int func_00300C60(void) {
    while (!func_002240B0("multimcd.bin", (void *)0x01D98000)) {
        /* poll until disc read complete */
    }
    return 1;
}
```

- [ ] **Step 4: Run test to verify it passes**

Run: `gcc -m32 -O2 -Iinclude tests/native/smenu_loader_test.c src/kcet/overlay_loader.c -o /tmp/smenu_loader_test && /tmp/smenu_loader_test`
Expected: PASS: `test_smenu_loader` and `test_multimcd_loader`.

- [ ] **Step 5: Commit**

```bash
git add include/overlay_loader.h src/kcet/overlay_loader.c tests/native/smenu_loader_test.c
git commit -m "feat(loader): decompile func_00300C60 multimcd.bin overlay streamer"
```

---

### Task 2: Re-decompile `func_00185230` to Match True Win32 Event Loop Pump

**Files:**
- Modify: `include/tribe_app.h`
- Modify: `src/app/tribe_app.cpp`
- Modify: `tests/native/tribe_app_test.cpp`

**Interfaces:**
- Consumes:
  - `func_226620(const MSG *msg) -> int` (`TranslateMessage`)
  - `func_226630(const MSG *msg) -> int` (`DispatchMessage`)
  - `func_185160(MSG *msg, int *handled)`
  - `func_2265D0(MSG *msg, void *hwnd, int min, int max, int remove)`
  - `func_388010(void *app)`
- Produces:
  - `func_00185230(void *self) -> int`

- [ ] **Step 1: Write the failing test**

```cpp
// tests/native/tribe_app_test.cpp
void test_event_pump_no_unconditional_smenu() {
    unsigned char app_buf[0x1948];
    memset(app_buf, 0, sizeof(app_buf));
    func_2F61F0(app_buf, NULL, 1);

    // Set field 0x1C = 1 to signal immediate exit without looping
    *(int *)(app_buf + 0x1C) = 1;

    // Verify func_00185230 does not invoke func_00300C90
    s_smenu_stream_called = 0;
    int res = func_00185230(app_buf);
    assert(res == 0);
    assert(s_smenu_stream_called == 0);
    printf("PASS: test_event_pump_no_unconditional_smenu\n");
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `gcc -m32 -O2 -Iinclude tests/native/tribe_app_test.cpp src/app/tribe_app.cpp -o /tmp/tribe_app_test && /tmp/tribe_app_test`
Expected: FAIL because `s_smenu_stream_called` is incremented.

- [ ] **Step 3: Implement true `func_00185230` in `src/app/tribe_app.cpp`**

Remove the unconditional call to `func_00300C90()`. Implement loop checking `self->field_1C`, processing messages via `func_185160`, `func_226620`, and `func_226630`, and dispatching virtual method 0xA8 (`0x002FEDE0`) / 0xAC (`0x002FEFB0`).

- [ ] **Step 4: Run test to verify it passes**

Run: `gcc -m32 -O2 -Iinclude tests/native/tribe_app_test.cpp src/app/tribe_app.cpp -o /tmp/tribe_app_test && /tmp/tribe_app_test`
Expected: PASS with 0 warnings.

- [ ] **Step 5: Commit**

```bash
git add include/tribe_app.h src/app/tribe_app.cpp tests/native/tribe_app_test.cpp
git commit -m "fix(app): re-decompile func_00185230 event loop pump matching binary"
```

---

### Task 3: Decompile Screen Manager Transition Cluster (`func_002FD5A0`, `func_002FD5C0`, `func_002FC350`, `func_002FC510`, `func_002F8EA0`)

**Files:**
- Create: `include/screen_manager.h`
- Create: `src/app/screen_manager.cpp`
- Create: `tests/native/screen_manager_test.cpp`

**Interfaces:**
- Consumes: `func_00300C90` (`smenu_cd.bin` loader), `func_00300C60` (`multimcd.bin` loader), `func_100850` (malloc), `func_188140`.
- Produces:
  - `func_002FD5A0(void *app) -> int`
  - `func_002FD5C0(void *app) -> int`
  - `func_002FC350(void *app) -> int`
  - `func_002FC510(void *app) -> int`
  - `func_002F8EA0(void *app) -> int`

- [ ] **Step 1: Write the failing tests**

```cpp
// tests/native/screen_manager_test.cpp
void test_screen_manager_transitions() {
    unsigned char app_buf[0x1948];
    memset(app_buf, 0, sizeof(app_buf));

    // func_002FD5A0 calls func_188140 and returns 1
    int res = func_002FD5A0(app_buf);
    assert(res == 1);

    // func_002FD5C0 streams smenu_cd.bin and clears 0x191C/0x1924 arrays
    s_smenu_load_count = 0;
    res = func_002FD5C0(app_buf);
    assert(res == 1);
    assert(s_smenu_load_count == 1);
    for (int i = 0; i < 7; ++i) {
        assert(app_buf[0x191C + i] == 0);
        assert(*(int *)(app_buf + 0x1924 + i * 4) == 0);
    }

    // func_002F8EA0 triggers multimcd.bin load
    s_multimcd_load_count = 0;
    res = func_002F8EA0(app_buf);
    assert(res == 1);
    assert(s_multimcd_load_count == 1);

    printf("PASS: test_screen_manager_transitions\n");
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `gcc -m32 -O2 -Iinclude tests/native/screen_manager_test.cpp -o /tmp/screen_manager_test`
Expected: FAIL with undeclared identifiers.

- [ ] **Step 3: Implement `include/screen_manager.h` and `src/app/screen_manager.cpp`**

Implement:
- `func_002FD5A0`: invokes `func_188140(app)` and returns 1.
- `func_002FD5C0`: clears arrays at `0x191C` and `0x1924`, releases `0x1468`, calls `func_00300C90()`, constructs panel, calls `func_3000B0(app, 4)`.
- `func_002FC350`: invokes `func_002FD5C0(app)`.
- `func_002FC510`: invokes `func_002FD5A0(app)` then `func_002FD5C0(app)`.
- `func_002F8EA0`: invokes `func_00300C60()` and handles mode transition.

- [ ] **Step 4: Run test to verify it passes**

Run: `gcc -m32 -O2 -Iinclude tests/native/screen_manager_test.cpp src/app/screen_manager.cpp src/kcet/overlay_loader.c -o /tmp/screen_manager_test && /tmp/screen_manager_test`
Expected: PASS: `test_screen_manager_transitions`.

- [ ] **Step 5: Commit**

```bash
git add include/screen_manager.h src/app/screen_manager.cpp tests/native/screen_manager_test.cpp
git commit -m "feat(screen): decompile screen manager transition cluster and SMENU loader integration"
```

---

### Task 4: Subsystem Regression Verification Gate

**Files:**
- Verify all 9 test suites across the repository.

- [ ] **Step 1: Run all 9 test suites**

Run:
```sh
gcc -m32 -O2 -Iinclude tests/native/screen_manager_test.cpp src/app/screen_manager.cpp src/kcet/overlay_loader.c -o /tmp/screen_manager_test && /tmp/screen_manager_test && \
gcc -m32 -O2 -Iinclude tests/native/game_window_test.cpp src/kcet/game_window.c -o /tmp/game_window_test && /tmp/game_window_test && \
gcc -m32 -O2 -Iinclude tests/native/smenu_loader_test.c src/kcet/overlay_loader.c -o /tmp/smenu_loader_test && /tmp/smenu_loader_test && \
gcc -m32 -O2 -Iinclude tests/native/overlay_loader_test.c src/kcet/overlay_loader.c -o /tmp/overlay_loader_test && /tmp/overlay_loader_test && \
gcc -m32 -O2 -Iinclude tests/native/tribe_app_test.cpp src/app/tribe_app.cpp -o /tmp/tribe_app_test && /tmp/tribe_app_test && \
gcc -m32 -O2 -Iinclude tests/native/game_thread_test.c src/kcet/game_thread.c src/kcet/kt_libcdvd_server.c -Wl,--unresolved-symbols=ignore-in-object-files -o /tmp/game_thread_test && /tmp/game_thread_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_sound_test.c src/kcet/kt_sound.c -o /tmp/kt_sound_test && /tmp/kt_sound_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_libpad_test.c src/kcet/kt_libpad.c -o /tmp/kt_libpad_test && /tmp/kt_libpad_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_mouse_test.c src/kcet/kt_mouse.c -o /tmp/kt_mouse_test && /tmp/kt_mouse_test
```
Expected: All 9 test suites pass with 100% and 0 warnings.
