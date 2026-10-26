# Decompilation of App Constructor (func_2F61F0), WndProc Dispatcher (func_00226630), and SMENU Loader (func_00300C90) Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Decompile the three core functions linking the boot state machine to the main menu overlay: `func_2F61F0` (instantiates `TRIBE_App` and binds its vtable so `vtable[3]` dispatches cleanly), `func_00226630` (Win32 `DispatchMessage` port reading `GWL_WNDPROC`), and `func_00300C90` (streams `smenu_cd.bin` into `0x01D98000`), completely resolving the `pc=0` boot crash.

**Architecture:** 
- `src/kcet/game_window.c`: Implements `func_00226630` and `SetWindowLongA`/`GetWindowLongA` window procedure management at `gp - 0x746C`.
- `src/kcet/smenu_loader.c`: Implements `func_00300C90` bridging the application boot sequence to `func_002240B0("smenu_cd.bin", 0x01D98000)`.
- `src/app/tribe_app.cpp`: Implements `func_2F61F0` (`TRIBE_App` constructor), establishing `this->vtable = 0x004DE5E0` where `vtable[3]` points to `func_00185230` (event loop pump).
- `tests/native/`: Behavioral unit tests verifying execution paths, vtable integrity, WndProc delegation, and SMENU overlay loading.

**Tech Stack:** C/C++98 (PS2 EE GCC / MWCC compatibility), 32-bit native test harness (`gcc -m32 -O2`).

**Spec:** `docs/ps2_binary_analysis.md`, `orig/SLES-50282/AOK.ELF` (SHA1: `f478e19f2059d52899b691483ef5c7522e30e17c`).

## Global Constraints

- Must match PlayStation 2 PAL `AOK.ELF` calling conventions ($a0-$a3, $t0-$t3 for first 8 arguments).
- C/C++ native code only; no empty `{}` stubs replacing assembly.
- Zero compiler warnings or errors under `gcc -m32 -O2 -Iinclude`.
- Exact memory addresses preserved: `OVERLAY_LOAD_ADDR = 0x01D98000`, `TRIBE_APP_VTABLE = 0x004DE5E0`, `SMENU_ENTRY = 0x01D98080`.

## Review Focus

1. `func_00226630` with `wndproc == NULL`: must return 0 without invoking indirect call `$v0`.
2. `func_2F61F0` failure in base constructor: preserves `this` pointer in return register `$v0`.
3. `func_0021BFB0` virtual dispatch when `vtable[3] == func_00185230`: does not jump to `pc=0`.
4. `func_00300C90` overlay loading retry: polls `func_002240B0` until return code is non-zero.
5. Window procedure argument mapping in `func_00226630`: passes `hwnd=1`, `message=msg->message`, `wParam=msg->wParam`, `lParam=msg->lParam`.

---

### Task 1: Decompile `func_00226630` (WndProc Message Dispatcher)

**Files:**
- Create: `include/game_window.h`
- Create: `src/kcet/game_window.c`
- Test: `tests/native/game_window_test.cpp`

**Interfaces:**
- Consumes: `MSG` struct (`message`, `wParam`, `lParam`), `g_wndproc` at `gp - 0x746C`.
- Produces: `func_00226630(const MSG *msg) -> int`, `SetWindowProc(void *proc) -> void*`.

- [ ] **Step 1: Write the failing test**

```cpp
// tests/native/game_window_test.cpp
#include <cassert>
#include <cstdio>
#include "game_window.h"

static int s_wndproc_called = 0;
static int s_last_hwnd = 0;
static unsigned int s_last_msg = 0;

static int mock_wndproc(int hwnd, unsigned int msg, unsigned int wp, long lp) {
    s_wndproc_called++;
    s_last_hwnd = hwnd;
    s_last_msg = msg;
    return 42;
}

void test_wndproc_dispatch() {
    SetWindowProc((void *)mock_wndproc);
    MSG msg = {0};
    msg.message = 0x100; // WM_KEYDOWN
    msg.wParam = 0x20;
    msg.lParam = 0;

    int res = func_00226630(&msg);
    assert(res == 42);
    assert(s_wndproc_called == 1);
    assert(s_last_hwnd == 1);
    assert(s_last_msg == 0x100);

    // Test null wndproc safe return (prevents pc=0)
    SetWindowProc(NULL);
    res = func_00226630(&msg);
    assert(res == 0);
    printf("PASS: test_wndproc_dispatch\n");
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `gcc -m32 -O2 -Iinclude tests/native/game_window_test.cpp -o /tmp/game_window_test`
Expected: FAIL with undefined reference to `func_00226630` and `SetWindowProc`.

- [ ] **Step 3: Implement `include/game_window.h` and `src/kcet/game_window.c`**

Implement `func_00226630` loading `g_wndproc` from `-0x746C($gp)`:
```c
int func_00226630(const MSG *msg) {
    typedef int (*WndProcFn)(int hwnd, unsigned int uMsg, unsigned int wParam, long lParam);
    WndProcFn proc = (WndProcFn)g_wndproc;
    if (proc != NULL) {
        return proc(1, msg->message, msg->wParam, msg->lParam);
    }
    return 0;
}
```

- [ ] **Step 4: Run test to verify it passes**

Run: `gcc -m32 -O2 -Iinclude tests/native/game_window_test.cpp src/kcet/game_window.c -o /tmp/game_window_test && /tmp/game_window_test`
Expected: PASS: `test_wndproc_dispatch`.

- [ ] **Step 5: Commit**

```bash
git add include/game_window.h src/kcet/game_window.c tests/native/game_window_test.cpp
git commit -m "feat(window): decompile func_00226630 WndProc dispatcher and safe fallback"
```

---

### Task 2: Decompile `func_00300C90` (SMENU Overlay Streamer)

**Files:**
- Create: `include/smenu_loader.h`
- Create: `src/kcet/smenu_loader.c`
- Test: `tests/native/smenu_loader_test.c`

**Interfaces:**
- Consumes: `func_002240B0(filename, dest)` from `game_thread.h`.
- Produces: `func_00300C90() -> int`.

- [ ] **Step 1: Write the failing test**

```c
// tests/native/smenu_loader_test.c
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "smenu_loader.h"

static int s_overlay_read_count = 0;
static const char *s_last_filename = NULL;
static void *s_last_dest = NULL;

int func_002240B0(const char *filename, void *dest) {
    s_overlay_read_count++;
    s_last_filename = filename;
    s_last_dest = dest;
    return (s_overlay_read_count >= 2) ? 1 : 0; // Succeed on second poll
}

void test_smenu_loader() {
    s_overlay_read_count = 0;
    int res = func_00300C90();
    assert(res == 1);
    assert(s_overlay_read_count == 2);
    assert(strcmp(s_last_filename, "smenu_cd.bin") == 0);
    assert(s_last_dest == (void *)0x01D98000);
    printf("PASS: test_smenu_loader\n");
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `gcc -m32 -O2 -Iinclude tests/native/smenu_loader_test.c -o /tmp/smenu_loader_test`
Expected: FAIL with undefined reference to `func_00300C90`.

- [ ] **Step 3: Implement `src/kcet/smenu_loader.c`**

```c
#include "game_thread.h"
#include "smenu_loader.h"

int func_00300C90(void) {
    while (!func_002240B0("smenu_cd.bin", (void *)OVERLAY_LOAD_ADDR)) {
        /* wait for disc read completion */
    }
    return 1;
}
```

- [ ] **Step 4: Run test to verify it passes**

Run: `gcc -m32 -O2 -Iinclude tests/native/smenu_loader_test.c src/kcet/smenu_loader.c -o /tmp/smenu_loader_test && /tmp/smenu_loader_test`
Expected: PASS: `test_smenu_loader`.

- [ ] **Step 5: Commit**

```bash
git add include/smenu_loader.h src/kcet/smenu_loader.c tests/native/smenu_loader_test.c
git commit -m "feat(loader): decompile func_00300C90 SMENU overlay streamer"
```

---

### Task 3: Decompile `func_2F61F0` (`TRIBE_App` Constructor & Vtable Binding)

**Files:**
- Create: `include/tribe_app.h`
- Create: `src/app/tribe_app.cpp`
- Test: `tests/native/tribe_app_test.cpp`

**Interfaces:**
- Consumes: `func_184340` (RGE_App base constructor), `func_00185230` (event loop pump).
- Produces: `func_2F61F0(void *obj, void *cfg, int arg) -> void*`, `g_tribe_app_vtable`.

- [ ] **Step 1: Write the failing test**

```cpp
// tests/native/tribe_app_test.cpp
#include <cassert>
#include <cstdio>
#include <cstring>
#include "tribe_app.h"

static int s_rge_app_init_called = 0;
extern "C" void func_184340(void *self, void *cfg, int arg) {
    s_rge_app_init_called++;
}

void test_tribe_app_constructor() {
    unsigned char app_buf[0x1948];
    memset(app_buf, 0xAA, sizeof(app_buf));

    void *res = func_2F61F0(app_buf, NULL, 1);
    assert(res == app_buf);
    assert(s_rge_app_init_called == 1);

    // Verify vtable assigned at offset 0
    void **vtable = *(void ***)app_buf;
    assert(vtable != NULL);
    // Method 3 (offset 0xC) MUST point to func_00185230 (not NULL, preventing pc=0)
    assert(vtable[3] == (void *)func_00185230);

    // Verify critical field initialization
    assert(*(int *)(app_buf + 0x142C) == 0);
    assert(*(int *)(app_buf + 0x1430) == -1);
    assert(*(void **)(app_buf + 0x1F0) == (void *)app_buf);

    printf("PASS: test_tribe_app_constructor\n");
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `gcc -m32 -O2 -Iinclude tests/native/tribe_app_test.cpp -o /tmp/tribe_app_test`
Expected: FAIL with undefined reference to `func_2F61F0` and `g_tribe_app_vtable`.

- [ ] **Step 3: Implement `include/tribe_app.h` and `src/app/tribe_app.cpp`**

Implement `func_2F61F0` matching assembly `0x002F61F0`:
1. Invoke base `func_184340(this, cfg, arg)`.
2. Assign `*(void ***)this = g_tribe_app_vtable` where `vtable[3] = (void *)func_00185230`.
3. Clear/initialize fields `0x142C`..`0x1468`, `0x190C`..`0x1944`, `0x1F0 = this`, `0x11A0 = 0xD`.
4. Register global pointer `g_pApp = this` (`gp - 0x7A04`).

- [ ] **Step 4: Run test to verify it passes**

Run: `gcc -m32 -O2 -Iinclude tests/native/tribe_app_test.cpp src/app/tribe_app.cpp -o /tmp/tribe_app_test && /tmp/tribe_app_test`
Expected: PASS: `test_tribe_app_constructor`.

- [ ] **Step 5: Commit**

```bash
git add include/tribe_app.h src/app/tribe_app.cpp tests/native/tribe_app_test.cpp
git commit -m "feat(app): decompile func_2F61F0 TRIBE_App constructor and vtable binding"
```

---

### Task 4: Full System Integration & Regression Verification Gate

**Files:**
- Modify: `tests/native/game_thread_test.c` (connect the full chain from boot through app vtable dispatch to SMENU loader)

- [ ] **Step 1: Write integration test exercising full chain**

Validate that:
1. `func_00221F40` advances to Phase `0x10`.
2. Phase `0x10` calls `func_0021BDF0`, allocating `0x1948` bytes and running `func_2F61F0`.
3. `func_0021BFB0` invokes `vtable[3]` which cleanly routes to `func_00185230` without jumping to `pc=0`.
4. `func_00185230` message pump dispatches messages safely through `func_00226630`.
5. `func_00300C90` loads `smenu_cd.bin` into `0x01D98000` via `func_002240B0`.

- [ ] **Step 2: Run all subsystem test suites**

Run:
```sh
gcc -m32 -O2 -Iinclude tests/native/game_window_test.cpp src/kcet/game_window.c -o /tmp/game_window_test && /tmp/game_window_test && \
gcc -m32 -O2 -Iinclude tests/native/smenu_loader_test.c src/kcet/smenu_loader.c -o /tmp/smenu_loader_test && /tmp/smenu_loader_test && \
gcc -m32 -O2 -Iinclude tests/native/tribe_app_test.cpp src/app/tribe_app.cpp -o /tmp/tribe_app_test && /tmp/tribe_app_test && \
gcc -m32 -O2 -Iinclude tests/native/game_thread_test.c src/kcet/game_thread.c src/kcet/kt_libcdvd_server.c -Wl,--unresolved-symbols=ignore-in-object-files -o /tmp/game_thread_test && /tmp/game_thread_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_sound_test.c src/kcet/kt_sound.c -o /tmp/kt_sound_test && /tmp/kt_sound_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_libpad_test.c src/kcet/kt_libpad.c -o /tmp/kt_libpad_test && /tmp/kt_libpad_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_mouse_test.c src/kcet/kt_mouse.c -o /tmp/kt_mouse_test && /tmp/kt_mouse_test
```
Expected: All 7 suites report 100% PASS with 0 warnings.

- [ ] **Step 3: Commit integration tests and clean merge**

```bash
git add tests/native/game_thread_test.c
git commit -m "test(integration): verify boot state machine to SMENU load execution chain"
```
