# Decompilation of Win32 Window Procedure Management (`func_002264A0`, `func_002264B0`, `func_002264E0`) Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Decompile the three Win32 window procedure management functions (`func_002264A0`, `func_002264B0`, `func_002264E0`) matching PlayStation 2 PAL `AOK.ELF` assembly, establishing 100% binary parity for window procedure registration and `GWL_WNDPROC` index queries.

**Architecture:**
- `include/game_window.h`: Declares Win32 constants (`GWL_WNDPROC = -4`), aliases, and function prototypes (`func_002264A0`, `func_002264B0`, `func_002264E0`).
- `src/kcet/game_window.c`: Implements `func_002264A0` (`RegisterClassA` / `SetWndProc`), `func_002264B0` (`GetWindowLongA`), and `func_002264E0` (`SetWindowLongA`) accessing `g_wndproc` at `gp - 0x746C`.
- `tests/native/game_window_test.cpp`: Tests registration, retrieval, and replacement of `GWL_WNDPROC` as well as non-wndproc index fallbacks.

**Tech Stack:** C/C++98 (PS2 EE GCC / MWCC compatibility), 32-bit native test harness (`gcc -m32 -O2`).

**Spec:** `orig/SLES-50282/AOK.ELF` (SHA1: `f478e19f2059d52899b691483ef5c7522e30e17c`), VRAM `0x002264A0`–`0x00226508`.

## Global Constraints

- Must match PlayStation 2 PAL `AOK.ELF` calling conventions ($a0-$a3, $v0 return register).
- C/C++ native code only; no empty `{}` stubs replacing assembly.
- Zero compiler warnings or errors under `gcc -m32 -O2 -Iinclude`.
- Exact memory address and offsets preserved:
  - `g_wndproc` stored at `gp - 0x746C`.
  - `GWL_WNDPROC = -4` (`0xFFFFFFFC`).

## Review Focus

1. `func_002264A0` return value: always returns 1 in `$v0` after storing `$a0` to `gp - 0x746C`.
2. `func_002264B0` with `nIndex == -4`: returns `g_wndproc` pointer in `$v0`.
3. `func_002264B0` with `nIndex != -4`: returns default fallback value 1 in `$v0`.
4. `func_002264E0` with `nIndex == -4`: stores `$a2` into `g_wndproc` and returns the previous `g_wndproc` in `$v0`.
5. `func_002264E0` with `nIndex != -4`: does not mutate `g_wndproc`.

---

### Task 1: Decompile `func_002264A0`, `func_002264B0`, and `func_002264E0`

**Files:**
- Modify: `include/game_window.h`
- Modify: `src/kcet/game_window.c`
- Modify: `tests/native/game_window_test.cpp`

**Interfaces:**
- Consumes: `g_wndproc` at `gp - 0x746C`.
- Produces:
  - `func_002264A0(void *proc) -> int` (`RegisterClassA` / `SetWndProc`)
  - `func_002264B0(int hwnd, int nIndex) -> void*` (`GetWindowLongA`)
  - `func_002264E0(int hwnd, int nIndex, void *newVal) -> void*` (`SetWindowLongA`)

- [ ] **Step 1: Write the failing tests**

```cpp
// tests/native/game_window_test.cpp
void test_win32_window_long_management() {
    g_wndproc = NULL;

    // 1. func_002264A0 stores proc and returns 1
    int res = func_002264A0((void *)0x12345678);
    assert(res == 1);
    assert(g_wndproc == (void *)0x12345678);

    // 2. func_002264B0 queries GWL_WNDPROC (-4)
    void *proc = func_002264B0(1, GWL_WNDPROC);
    assert(proc == (void *)0x12345678);

    // 2b. func_002264B0 with other index returns 1
    void *non_wndproc = func_002264B0(1, 0);
    assert(non_wndproc == (void *)1);

    // 3. func_002264E0 replaces GWL_WNDPROC (-4) and returns old proc
    void *old = func_002264E0(1, GWL_WNDPROC, (void *)0x87654321);
    assert(old == (void *)0x12345678);
    assert(g_wndproc == (void *)0x87654321);

    // 3b. func_002264E0 with other index does not mutate g_wndproc
    func_002264E0(1, 0, (void *)0x99999999);
    assert(g_wndproc == (void *)0x87654321);

    printf("PASS: test_win32_window_long_management\n");
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `gcc -m32 -O2 -Iinclude tests/native/game_window_test.cpp src/kcet/game_window.c -o /tmp/game_window_test`
Expected: FAIL with undefined reference to `func_002264A0`, `func_002264B0`, `func_002264E0`.

- [ ] **Step 3: Implement functions in `include/game_window.h` and `src/kcet/game_window.c`**

In `include/game_window.h`:
```c
#define GWL_WNDPROC (-4)

int func_002264A0(void *proc);
void *func_002264B0(int hwnd, int nIndex);
void *func_002264E0(int hwnd, int nIndex, void *newVal);

#define RegisterWndProc func_002264A0
#define GetWindowLongA func_002264B0
#define SetWindowLongA func_002264E0
```

In `src/kcet/game_window.c`:
```c
int func_002264A0(void *proc) {
    g_wndproc = proc;
    return 1;
}

void *func_002264B0(int hwnd, int nIndex) {
    (void)hwnd;
    if (nIndex == GWL_WNDPROC) {
        return g_wndproc;
    }
    return (void *)1;
}

void *func_002264E0(int hwnd, int nIndex, void *newVal) {
    (void)hwnd;
    if (nIndex == GWL_WNDPROC) {
        void *old = g_wndproc;
        g_wndproc = newVal;
        return old;
    }
    return NULL;
}
```

- [ ] **Step 4: Run test to verify it passes**

Run: `gcc -m32 -O2 -Iinclude tests/native/game_window_test.cpp src/kcet/game_window.c -o /tmp/game_window_test && /tmp/game_window_test`
Expected: PASS: `test_wndproc_dispatch` and `test_win32_window_long_management`.

- [ ] **Step 5: Commit**

```bash
git add include/game_window.h src/kcet/game_window.c tests/native/game_window_test.cpp
git commit -m "feat(window): decompile func_002264A0, func_002264B0, and func_002264E0"
```

---

### Task 2: Subsystem Regression Verification Gate

**Files:**
- Verify all 8 test suites across the repository.

- [ ] **Step 1: Run all 8 test suites**

Run:
```sh
gcc -m32 -O2 -Iinclude tests/native/game_window_test.cpp src/kcet/game_window.c -o /tmp/game_window_test && /tmp/game_window_test && \
gcc -m32 -O2 -Iinclude tests/native/smenu_loader_test.c src/kcet/overlay_loader.c -o /tmp/smenu_loader_test && /tmp/smenu_loader_test && \
gcc -m32 -O2 -Iinclude tests/native/overlay_loader_test.c src/kcet/overlay_loader.c -o /tmp/overlay_loader_test && /tmp/overlay_loader_test && \
gcc -m32 -O2 -Iinclude tests/native/tribe_app_test.cpp src/app/tribe_app.cpp -o /tmp/tribe_app_test && /tmp/tribe_app_test && \
gcc -m32 -O2 -Iinclude tests/native/game_thread_test.c src/kcet/game_thread.c src/kcet/kt_libcdvd_server.c -Wl,--unresolved-symbols=ignore-in-object-files -o /tmp/game_thread_test && /tmp/game_thread_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_sound_test.c src/kcet/kt_sound.c -o /tmp/kt_sound_test && /tmp/kt_sound_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_libpad_test.c src/kcet/kt_libpad.c -o /tmp/kt_libpad_test && /tmp/kt_libpad_test && \
gcc -m32 -O2 -Iinclude tests/native/kt_mouse_test.c src/kcet/kt_mouse.c -o /tmp/kt_mouse_test && /tmp/kt_mouse_test
```
Expected: All 8 test suites pass with 100% and 0 warnings.
