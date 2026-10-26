# Plan: Decompilation of Main Game Loop through Asset/Overlay Load

## Context
In PlayStation 2 *Age of Empires II* (`orig/SLES-50282/AOK.ELF`, SHA1: `f478e19f2059d52899b691483ef5c7522e30e17c`), the game thread (`Thread 2`, entry `0x002206A0`) initializes the platform hardware, enters an infinite per-frame message and state loop (`0x002206F0`–`0x002207A8`), and drives the boot state machine (`func_00221F40`).
When Phase 12 (`0x0C` in `func_002221A0`) is reached, the engine loads the initial language overlay (such as `EN\lobby_cd.bin`) into `0x01D98000` via `func_002240B0`, calling the CDVD file-read request service `func_0012C1D0` in `kt_libcdvd_server.c`. Control then transfers to the loaded overlay entry point (`0x01DE9900` / `0x01DE9B00`) which parses DRS records and mounts the game's consolidated asset archive (`ALL_DATA.BIN`).

Decompiling this execution chain connects the already-decompiled audio/pad drivers to the disc asset and UI loading subsystem, establishing full binary and behavioral parity for game boot.

---

## Scope & Target Functions

The pipeline will be decompiled across 5 key functions:

1. **`func_002206A0` (GameThread Entry)**:
   - Initial low-level driver calls (`func_00220940`, `func_00220BA0`, `func_00220C60`, `func_00221110`, `func_00221410`).
   - SIF sound initialization (`func_0012D648`).
   - Handoff into the infinite frame loop.

2. **`func_002206F0`–`0x002207A8` (GameThread Per-Frame Loop)**:
   - Frame object update (`func_002204D0`).
   - VSYNC semaphore synchronization (`0x00104D40` / `0x00104D60`).
   - Per-frame message queue polling (`func_002204E0`).
   - Viewport setup (`func_002207B0`) and peripheral input update (`func_00221790`).
   - State machine invocation (`func_00221F40`).

3. **`func_00221F40` (Boot & Menu State Machine)**:
   - Evaluates sub-phase index at `gp-0x74B4`.
   - Jump table at `0x00492EF0` with 10 branch cases (`0..9`).
   - Delegates sub-phases `0x08`–`0x11` to `func_002221A0`.

4. **`func_002221A0` (Overlay Phase Sequencer & Phase 12 Handoff)**:
   - State branches for phases `0x08` through `0x11`.
   - **Phase 12 (`0x0C` at `0x0022226C`)**:
     - Prepares target VRAM destination `0x01D98000`.
     - Prepends `EN\` to the overlay filename (`lobby_cd.bin`).
     - Invokes `func_002240B0` to queue asynchronous CD sector reading.
     - Loops at `0x00222280` until loading completes (`v0 == 1`).
     - Dispatches to overlay entry `0x01DE9900` or `0x01DE9B00`.

5. **`func_002240B0` (Overlay CD Reader Bridge)**:
   - Formats file path buffer on the stack.
   - Calls `func_0012C1D0` (`kt_libcdvd_server` file read request) to submit sector I/O.
   - Queries completion status and returns readiness flag (`1 = loaded`, `0 = pending`).

6. **`func_0012C1D0` (CDVD File Read Request Bridge in `kt_libcdvd_server`)**:
   - Prepares request buffer (`func_00129F58`, `func_00129FD0`).
   - Submits CD sector read packet via `func_0012C128`.

---

## File Architecture

- **Public Headers**:
  - `include/game_thread.h`: Structs, phase constants, prototypes for `func_002206A0`, `func_002206F0`, `func_00221F40`, `func_002221A0`, `func_002240B0`.
  - `include/kt_libcdvd_server.h`: Updated with declaration for `func_0012C1D0`.
- **Implementations**:
  - `src/kcet/game_thread.c`: GameThread entry, per-frame loop, boot state machine (`func_00221F40`), phase sequencer (`func_002221A0`), and overlay loader (`func_002240B0`).
  - `src/kcet/kt_libcdvd_server.c`: Export and decompilation of `func_0012C1D0`.
- **Native Test Suite**:
  - `tests/native/game_thread_test.c`: TDD behavioral test exercising the loop, state machine cases 0..9, phase 12 overlay request formatting, and CDVD read completion polling.

---

## Step-by-Step Implementation Plan (TDD)

### Step 1: Worktree & Test Harness Setup
- Create worktree `.worktrees/game-thread-loop` on branch `game-thread-loop`.
- Define `include/game_thread.h` with phase constants (`BOOT_PHASE_AUDIO_POLL = 0x06`, `BOOT_PHASE_LOAD_OVERLAY = 0x0C`, `BOOT_PHASE_OVERLAY_ENTRY1 = 0x10`, `BOOT_PHASE_OVERLAY_ENTRY2 = 0x11`).
- Write initial Red test `tests/native/game_thread_test.c` verifying the presence and signatures of the functions.

### Step 2: Decompile `func_0012C1D0` in `kt_libcdvd_server.c`
- **Red**: Add test verifying `func_0012C1D0` packages file path and buffer requests.
- **Green**: Decompile `func_0012C1D0` matching `AOK.ELF` assembly (calls to `func_00129F58`, `func_00129FD0`, `func_0012C128`).
- **Refactor**: Ensure clean static typing and no warnings.

### Step 3: Decompile `func_002240B0` (Overlay Loader)
- **Red**: Add test verifying that passing `"lobby_cd.bin"` formats `"EN\\lobby_cd.bin"` and polls `func_0012C1D0` until completion.
- **Green**: Implement `func_002240B0` with exact stack buffer allocation, prefix formatting, and status evaluation.
- **Refactor**: Clean string operations and status checks.

### Step 4: Decompile `func_002221A0` & `func_00221F40` (State Machine & Phase 12)
- **Red**: Add tests exercising:
  - Jump table dispatch for cases 0..9 in `func_00221F40`.
  - Phase 12 execution in `func_002221A0` verifying it targets `0x01D98000`, loads the overlay via `func_002240B0`, and transitions to `0x01DE9900`.
- **Green**: Implement the exact control flow, branch labels, jump table indexing (`0x00492EF0`), and phase progression.
- **Refactor**: Map named constants to validated phases.

### Step 5: Decompile `func_002206A0` & Frame Loop (`0x002206F0`–`0x002207A8`)
- **Red**: Add test executing a single bounded cycle of the frame loop, validating call order:
  `func_002204D0` -> semaphore signals -> `func_002204E0` -> `func_002207B0` -> `func_00221790` -> `func_00221F40`.
- **Green**: Implement `func_002206A0` and the per-frame loop body matching original registers and syscall invocations.
- **Refactor**: Ensure seamless linkability with existing native stubs and mock layers.

### Step 6: Regression & Verification Gate
- Run full native test suite under `gcc -m32 -O2 -Iinclude`:
  1. `tests/native/game_thread_test.c`
  2. `tests/native/kt_sound_test.c`
  3. `tests/native/kt_libpad_test.c`
  4. `tests/native/kt_mouse_test.c`
- Verify clean git status in worktree, commit changes, rebase and merge with `--no-ff` into `main`.

---

## Verification & Acceptance Criteria
- `gcc -m32 -O2` compiles all native test suites with zero warnings or errors.
- All unit assertions in `game_thread_test` pass:
  - GameThread loop sequences calls in exact binary order.
  - State machine correctly routes through jump table at `0x00492EF0`.
  - Phase 12 loads `"EN\\lobby_cd.bin"` into `0x01D98000` via `func_002240B0` and calls `func_0012C1D0`.
  - Overlay entry point addresses `0x01DE9900` / `0x01DE9B00` are validated as the handoff target.
- Regression tests for `kt_sound`, `kt_libpad`, and `kt_mouse` remain 100% green.
