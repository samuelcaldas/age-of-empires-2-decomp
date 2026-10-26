# Decompilation of Overlay Loaders (`func_00300C90`, `func_00300C60`, `func_003800F0`, `func_0036C350`, `func_00226DE0`, `func_00226FA0`, `func_0022F550`, `func_00258E40`) Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Decompile the 8 overlay loader functions linking the game state machine to disk overlay binaries (`smenu_cd.bin`, `multimcd.bin`, `thelp_cd.bin`, `mo_ov_cd.bin`, `dcomp_cd.bin`, `rmmmemcd.bin`, `hist_cd.bin`) into `src/kcet/overlay_loader.c`.

**Architecture:** 
- `include/overlay_loader.h`: Exposes signatures for all 8 overlay loading and dispatch routines, destination addresses, and global overlay state variables.
- `src/kcet/overlay_loader.c`: Implements the 8 functions matching PlayStation 2 PAL `AOK.ELF` assembly, routing disk stream reads through `func_002240B0`.
- `tests/native/overlay_loader_test.c`: Behavioral unit test suite exercising polling retry logic, target load addresses, entry point invocations, and state flag mutations.

**Tech Stack:** C/C++98 (PS2 EE GCC / MWCC compatibility), 32-bit native test harness (`gcc -m32 -O2`).

**Spec:** `orig/SLES-50282/AOK.ELF` (SHA1: `f478e19f2059d52899b691483ef5c7522e30e17c`), `docs/ps2_disc_architecture.md`.

## Global Constraints

- Must match PlayStation 2 PAL `AOK.ELF` calling conventions ($a0-$a3, $t0-$t3 for arguments).
- C/C++ native code only; no empty `{}` stubs replacing assembly.
- Zero compiler warnings or errors under `gcc -m32 -O2 -Iinclude`.
- Exact memory addresses preserved:
  - `OVERLAY_LOAD_ADDR = 0x01D98000` (used by `smenu_cd`, `multimcd`, `dcomp_cd`, `rmmmemcd`, `hist_cd`)
  - `THELP_OVERLAY_LOAD_ADDR = 0x01F68000` (used by `thelp_cd`)
  - `MO_OV_OVERLAY_LOAD_ADDR = 0x01ED7000` (used by `mo_ov_cd`)
  - `DCOMP_OVERLAY_PTR = 0x01E58000` (stored in `gp - 0x7928`)
  - Entry points: `0x01ED7080` (`mo_ov`), `0x01D98080` (`rmmmem`), `0x01D98820` (`hist`), `0x01D9BEF0` / `0x01D9BCE0` (`dcomp`).

## Review Focus

1. `func_003800F0` destination address: must use `0x01F68000`, not `0x01D98000`.
2. `func_0036C350` destination address and entry call: must load to `0x01ED7000`, invoke `0x01ED7080`, and store returned handle to `gp - 0x71a4`.
3. `func_00226FA0` caching check: must skip `func_002240B0` when flag `gp - 0x745C` is already `1`.
4. `func_0022F550` conditional branch: must check `field_13C` and bypass overlay loading when non-zero.
5. Polling loops: every loader must poll `func_002240B0` until return code is non-zero.

---

### Task 1: Standalone Overlay Streamers (`func_00300C90`, `func_00300C60`, `func_003800F0`)

**Files:**
- Create: `include/overlay_loader.h`
- Create: `src/kcet/overlay_loader.c`
- Test: `tests/native/overlay_loader_test.c`

**Interfaces:**
- Consumes: `func_002240B0(filename, dest)` from `game_thread.h`.
- Produces: 
  - `func_00300C90(void) -> int` (`smenu_cd.bin` -> `0x01D98000`)
  - `func_00300C60(void) -> int` (`multimcd.bin` -> `0x01D98000`)
  - `func_003800F0(void) -> int` (`thelp_cd.bin` -> `0x01F68000`)

- [ ] **Step 1: Write the failing test**

```c
// tests/native/overlay_loader_test.c
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "overlay_loader.h"

static int s_poll_counts[4] = {0};
static const char *s_last_files[4] = {NULL};
static void *s_last_dests[4] = {NULL};

int func_002240B0(const char *filename, void *dest) {
    if (strcmp(filename, "smenu_cd.bin") == 0) {
        s_poll_counts[0]++;
        s_last_files[0] = filename;
        s_last_dests[0] = dest;
        return (s_poll_counts[0] >= 2) ? 1 : 0;
    }
    if (strcmp(filename, "multimcd.bin") == 0) {
        s_poll_counts[1]++;
        s_last_files[1] = filename;
        s_last_dests[1] = dest;
        return (s_poll_counts[1] >= 2) ? 1 : 0;
    }
    if (strcmp(filename, "thelp_cd.bin") == 0) {
        s_poll_counts[2]++;
        s_last_files[2] = filename;
        s_last_dests[2] = dest;
        return (s_poll_counts[2] >= 2) ? 1 : 0;
    }
    return 1;
}

void test_standalone_streamers(void) {
    // 1. smenu_cd.bin -> 0x01D98000
    int res = func_00300C90();
    assert(res == 1);
    assert(s_poll_counts[0] == 2);
    assert(s_last_dests[0] == (void *)0x01D98000);

    // 2. multimcd.bin -> 0x01D98000
    res = func_00300C60();
    assert(res == 1);
    assert(s_poll_counts[1] == 2);
    assert(s_last_dests[1] == (void *)0x01D98000);

    // 3. thelp_cd.bin -> 0x01F68000
    res = func_003800F0();
    assert(res == 1);
    assert(s_poll_counts[2] == 2);
    assert(s_last_dests[2] == (void *)0x01F68000);

    printf("PASS: test_standalone_streamers\n");
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `gcc -m32 -O2 -Iinclude tests/native/overlay_loader_test.c -o /tmp/overlay_loader_test`
Expected: FAIL with undefined reference to `func_00300C90`, `func_00300C60`, `func_003800F0`.

- [ ] **Step 3: Implement `include/overlay_loader.h` and `src/kcet/overlay_loader.c`**

Implement `func_00300C90`, `func_00300C60`, and `func_003800F0` matching AOK.ELF assembly:
```c
int func_00300C90(void) {
    while (!func_002240B0("smenu_cd.bin", (void *)OVERLAY_LOAD_ADDR)) {
    }
    return 1;
}

int func_00300C60(void) {
    while (!func_002240B0("multimcd.bin", (void *)OVERLAY_LOAD_ADDR)) {
    }
    return 1;
}

int func_003800F0(void) {
    while (!func_002240B0("thelp_cd.bin", (void *)THELP_OVERLAY_LOAD_ADDR)) {
    }
    return 1;
}
```

- [ ] **Step 4: Run test to verify it passes**

Run: `gcc -m32 -O2 -Iinclude tests/native/overlay_loader_test.c src/kcet/overlay_loader.c -o /tmp/overlay_loader_test && /tmp/overlay_loader_test`
Expected: PASS: `test_standalone_streamers`.

- [ ] **Step 5: Commit**

```bash
git add include/overlay_loader.h src/kcet/overlay_loader.c tests/native/overlay_loader_test.c
git commit -m "feat(loader): decompile func_00300C90, func_00300C60, and func_003800F0"
```

---

### Task 2: Dynamic Overlay Invokers with Entry Points (`func_0036C350`, `func_0022F550`, `func_00258E40`)

**Files:**
- Modify: `include/overlay_loader.h`
- Modify: `src/kcet/overlay_loader.c`
- Modify: `tests/native/overlay_loader_test.c`

**Interfaces:**
- Consumes: `func_002240B0`, `func_0036CC40(handle)`, `func_100850`, `func_188680`, `func_257E40`, `func_2E7F90`.
- Produces:
  - `func_0036C350(void) -> void` (`mo_ov_cd.bin` -> `0x01ED7000`, entry `0x01ED7080`, sets `g_mo_ov_handle`)
  - `func_0022F550(void *screen_obj) -> int` (`rmmmemcd.bin` -> `0x01D98000`, entry `0x01D98080`)
  - `func_00258E40(void *context) -> int` (`hist_cd.bin` -> `0x01D98000`, entry `0x01D98820`)

- [ ] **Step 1: Write failing tests for entry point invocations**

Add unit tests to `tests/native/overlay_loader_test.c` verifying:
1. `func_0036C350` streams `"mo_ov_cd.bin"` to `0x01ED7000`, executes mock `0x01ED7080`, updates `g_mo_ov_handle`, and passes handle to `func_0036CC40`.
2. `func_0022F550` checks `field_13C`. If 0, streams `"rmmmemcd.bin"` to `0x01D98000` and executes `0x01D98080`. If `field_13C != 0`, skips streaming.
3. `func_00258E40` calls helper routines, streams `"hist_cd.bin"` to `0x01D98000`, and executes `0x01D98820`.

- [ ] **Step 2: Run test to verify it fails**

Run: `gcc -m32 -O2 -Iinclude tests/native/overlay_loader_test.c src/kcet/overlay_loader.c -o /tmp/overlay_loader_test`
Expected: FAIL with undefined reference to `func_0036C350`, `func_0022F550`, `func_00258E40`.

- [ ] **Step 3: Implement functions in `src/kcet/overlay_loader.c`**

Implement:
1. `func_0036C350`:
   ```c
   void func_0036C350(void) {
       while (!func_002240B0("mo_ov_cd.bin", (void *)MO_OV_OVERLAY_LOAD_ADDR)) {}
       g_mo_ov_handle = ((void *(*)(void))MO_OV_ENTRY_POINT)();
       func_0036CC40(g_mo_ov_handle);
   }
   ```
2. `func_0022F550`:
   ```c
   int func_0022F550(void *screen_obj) {
       if (screen_obj != NULL && *(int *)((char *)screen_obj + 0x13C) == 0) {
           while (!func_002240B0("rmmmemcd.bin", (void *)OVERLAY_LOAD_ADDR)) {}
           ((void (*)(void))RMMMEM_ENTRY_POINT)();
           return 1;
       }
       return 0;
   }
   ```
3. `func_00258E40`:
   ```c
   int func_00258E40(void *context) {
       func_257E40(g_game_context);
       while (!func_002240B0("hist_cd.bin", (void *)OVERLAY_LOAD_ADDR)) {}
       ((void (*)(void))HIST_ENTRY_POINT)();
       return 1;
   }
   ```

- [ ] **Step 4: Run test to verify it passes**

Run: `gcc -m32 -O2 -Iinclude tests/native/overlay_loader_test.c src/kcet/overlay_loader.c -o /tmp/overlay_loader_test && /tmp/overlay_loader_test`
Expected: PASS: `test_dynamic_invokers`.

- [ ] **Step 5: Commit**

```bash
git add include/overlay_loader.h src/kcet/overlay_loader.c tests/native/overlay_loader_test.c
git commit -m "feat(loader): decompile func_0036C350, func_0022F550, and func_00258E40"
```

---

### Task 3: DCOMP Overlay Loaders and State Dispatch (`func_00226DE0`, `func_00226FA0`)

**Files:**
- Modify: `include/overlay_loader.h`
- Modify: `src/kcet/overlay_loader.c`
- Modify: `tests/native/overlay_loader_test.c`

**Interfaces:**
- Consumes: `func_002240B0`, `g_dcomp_loaded` (`gp - 0x745C`), `g_dcomp_ptr` (`gp - 0x7928`).
- Produces:
  - `func_00226DE0(void) -> void` (unconditional load of `dcomp_cd.bin` and assignment of `g_dcomp_ptr = 0x01E58000`)
  - `func_00226FA0(void) -> void` (cached load of `dcomp_cd.bin`, sets `g_dcomp_loaded = 1`, dispatches entry points)

- [ ] **Step 1: Write failing tests for DCOMP loading and caching**

Add unit tests:
1. Call `func_00226DE0()`: verifies `dcomp_cd.bin` loaded into `0x01D98000` and `g_dcomp_ptr == (void *)0x01E58000`.
2. Call `func_00226FA0()` with `g_dcomp_loaded = 0`: loads `dcomp_cd.bin`, sets `g_dcomp_loaded = 1`, sets `g_dcomp_ptr = (void *)0x01E58000`, dispatches `0x01D9BEF0` and `0x01D9BCE0`.
3. Call `func_00226FA0()` second time with `g_dcomp_loaded = 1`: skips `func_002240B0` and immediately dispatches `0x01D9BCE0`.

- [ ] **Step 2: Run test to verify it fails**

Run: `gcc -m32 -O2 -Iinclude tests/native/overlay_loader_test.c src/kcet/overlay_loader.c -o /tmp/overlay_loader_test`
Expected: FAIL with undefined reference to `func_00226DE0`, `func_00226FA0`.

- [ ] **Step 3: Implement `func_00226DE0` and `func_00226FA0` in `src/kcet/overlay_loader.c`**

Implement:
```c
void func_00226DE0(void) {
    while (!func_002240B0("dcomp_cd.bin", (void *)OVERLAY_LOAD_ADDR)) {}
    g_dcomp_ptr = (void *)DCOMP_OVERLAY_PTR;
}

void func_00226FA0(void) {
    if (!g_dcomp_loaded) {
        while (!func_002240B0("dcomp_cd.bin", (void *)OVERLAY_LOAD_ADDR)) {}
        g_dcomp_loaded = 1;
        g_dcomp_ptr = (void *)DCOMP_OVERLAY_PTR;
        ((void (*)(void))DCOMP_ENTRY_INIT)();
    }
    ((void (*)(void))DCOMP_ENTRY_DISPATCH)();
}
```

- [ ] **Step 4: Run test to verify it passes**

Run: `gcc -m32 -O2 -Iinclude tests/native/overlay_loader_test.c src/kcet/overlay_loader.c -o /tmp/overlay_loader_test && /tmp/overlay_loader_test`
Expected: PASS: `test_dcomp_loaders`.

- [ ] **Step 5: Commit**

```bash
git add include/overlay_loader.h src/kcet/overlay_loader.c tests/native/overlay_loader_test.c
git commit -m "feat(loader): decompile func_00226DE0 and func_00226FA0 DCOMP loaders"
```

---

### Task 4: Full System Integration & Regression Verification Gate

**Files:**
- Modify: `tests/native/game_thread_test.c` (validate integration with game thread and existing boot sequence)

- [ ] **Step 1: Verify full suite with all 8 overlay loaders active**

Verify that:
1. `smenu_loader.h` delegates cleanly to `overlay_loader.h` (or is consolidated).
2. All 8 target loader functions are callable across C and C++ translation units.
3. Destination addresses and entry point conventions match `AOK.ELF` specifications.

- [ ] **Step 2: Run all subsystem test suites**

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
Expected: All 8 suites report 100% PASS with 0 warnings.

- [ ] **Step 3: Commit integration tests and clean merge**

```bash
git add tests/native/game_thread_test.c
git commit -m "test(integration): verify all 8 overlay loaders and boot state integration"
```
