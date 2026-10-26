# Decompilation of Win32 Event Pump (`func_00185230`) & Screen Manager Overlay Transition Cluster Design Spec

**Date:** 2026-10-26  
**Status:** Approved for Implementation Planning  
**Target:** PlayStation 2 PAL `AOK.ELF` (SHA1: `f478e19f2059d52899b691483ef5c7522e30e17c`)

---

## 1. Context & Motivation

In the initial bootstrap decompilation, `func_00185230` (the main event loop pump of `RGE_App` / `TRIBE_App`) was stubbed with a direct unconditional call to `func_00300C90()` (`smenu_cd.bin` loader).
Cross-session divergence analysis with `aoe-recomp` confirmed that in the original PS2 binary:
1. `func_00185230` never directly invokes `func_00300C90()`. It is a Win32 message pump port that calls `func_185160` (`PeekMessageA`), `func_226620` (`TranslateMessage`), and `func_226630` (`DispatchMessage`), plus indirect virtual dispatch to `vtable[0xA8 / 4]` (`func_002FEDE0`) and `vtable[0xAC / 4]` (`func_002FEFB0`).
2. `func_00300C90` (`smenu_cd.bin` streamer) is exclusively invoked through the screen-manager transition path `func_002FD5C0` (at `0x002FD950`), which is called by `func_002FC350` and `func_002FC510`.
3. `func_00300C60` (`multimcd.bin` streamer) is called by `func_002F8EA0`.

This design spec specifies the decompilation of:
- `func_00185230`: Genuine Win32 event loop pump matching assembly `0x00185230`–`0x001853D8`.
- Screen manager transition cluster:
  - `func_00300C60`: `multimcd.bin` overlay streamer.
  - `func_002FD5A0`: Screen transition prelude (`func_188140` helper).
  - `func_002FD5C0`: Main screen change driver linking into `func_00300C90` (`smenu_cd.bin` loader) and instantiating screen context `0x01D98080`.
  - `func_002FC350`: Menu screen transition caller.
  - `func_002FC510`: Scenario/game screen transition caller.
  - `func_002F8EA0`: Multi-menu transition caller.

---

## 2. Architecture & Data Structures

### 2.1 Event Loop Pump (`src/app/tribe_app.cpp`, `include/tribe_app.h`)
- Prototype: `int func_00185230(void *self)`
- Registers:
  - `$s1`: `this` pointer (`self`).
  - `$s0`: pointer to `msg.message` (`&msg.message`, at offset `+4` of `MSG` struct).
  - Virtual call `this->vtable[0xA8 / 4]`: invoked during idle/pump.
  - Virtual call `this->vtable[0xAC / 4]`: invoked when message queue is drained.
  - Calls `func_226620(&msg)` (`TranslateMessage`).
  - Calls `func_226630(&msg)` (`DispatchMessage`).
  - Calls `func_2265D0(&msg, NULL, 0, 0, 1)` (`PeekMessageA` port).

### 2.2 Overlay Streamers (`src/kcet/overlay_loader.c`, `include/overlay_loader.h`)
- `func_00300C60()`: Streams `"multimcd.bin"` to `0x01D98000` via `func_002240B0`.
- `func_00300C90()`: Streams `"smenu_cd.bin"` to `0x01D98000` via `func_002240B0` (already decompiled in `src/kcet/overlay_loader.c`).

### 2.3 Screen Manager Transition Cluster (`src/app/screen_manager.cpp`, `include/screen_manager.h`)
- `func_002FD5A0(void *app)`: Calls `func_188140(app)` and returns `1`.
- `func_002FD5C0(void *app)`:
  - Clears `app->field_191C` (bytes 0..6) and `app->field_1924` (words 0..6).
  - Allocates `0x17F8` bytes via `func_100850` and constructs panel via `func_23FF80`.
  - Releases old panel if present (`app->field_1468`).
  - Calls `func_00300C90()` to ensure `smenu_cd.bin` is streamed into `0x01D98000`.
  - Allocates `0x84C` bytes for menu panel and invokes `func_01D98080(panel, app->field_1468)`.
  - Registers screen via `func_3000B0(app, 4)`.
- `func_002FC350(void *app)`:
  - Evaluates screen mode predicate; invokes `func_002FD5C0(app)`.
- `func_002FC510(void *app)`:
  - Invokes `func_002FD5A0(app)` and `func_002FD5C0(app)`.
- `func_002F8EA0(void *app)`:
  - Transition handler invoking `func_00300C60()`.

---

## 3. Testing & Verification

1. **Native Unit Tests (`tests/native/tribe_app_test.cpp`)**:
   - Verify `func_00185230` does not jump to `func_00300C90`.
   - Verify `func_00185230` processes Win32 `MSG` flow (`TranslateMessage` and `DispatchMessage`).
   - Verify `func_00185230` exits loop when `self->field_1C` is set to 1.
2. **Native Unit Tests (`tests/native/screen_manager_test.cpp`)**:
   - Verify `func_002FD5A0` invokes `func_188140` and returns 1.
   - Verify `func_002FD5C0` calls `func_00300C90()` and initializes `0x191C`/`0x1924` arrays.
   - Verify `func_002FC350` and `func_002FC510` route into `func_002FD5C0`.
   - Verify `func_002F8EA0` triggers `func_00300C60()`.
3. **Regression Suite**:
   - All existing suites pass with 0 warnings.
