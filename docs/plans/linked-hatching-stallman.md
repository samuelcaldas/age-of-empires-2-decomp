# Implementation Plan: PS2 Memory Card Screen and Dialog Decompilation

## Context
During reverse engineering and cross-session verification with `aoe-recomp`, routines historically classified under "Tactical AI" (`0x340370`–`0x3429E0`) were identified as the PlayStation 2 **Memory Card Screen and Dialog** subsystem (`scr_sl`). The parent screen (`0x33DAF0`–`0x340370`) is currently trapped inside an opaque binary blob (`bin_3394e0_340370`). The child dialog is partially decompiled (`0x342170` and `0x340C30` match 100%, while `0x341040` is partially implemented and `0x340490` is missing).

This plan outlines the end-to-end process to split, decompile, and match all functions across both the Memory Card Screen (`0x33DAF0`–`0x340370`) and Dialog (`0x340490`–`0x3429E0`) under authentic Metrowerks CodeWarrior PS2 toolchain settings, supported by behavioral tests and bit-for-bit byte matching.

---

## Architecture & Subsystem Boundaries

The subsystem consists of two cooperating C++ classes:
1. **`MemoryCardScreen` (`0x33DAF0`–`0x340370`)**:
   - Vtable at `0x4DEF10` (resource `"scr_sl"`).
   - Manages top-level screen widgets:
     - `field_818`: Card status label (displays string `0xC3BD` + `0xC3E3` / `0xC3E2`).
     - `field_820`: Base UI panel container.
     - `field_824`: Save slots list table (`0x340090`).
     - `field_82C`: Cancel / Back button (`0xFA2`, hotkey `0x1B` / Triangle / ESC).
     - `field_830`: Load / Save action button (`0x23FE` / `0x240F`).
     - `field_8A0`: Pointer to owned child dialog (`MemoryCardDialog`).
   - Drives per-frame tick dispatcher `0x33ECE0` using 13-entry jump table at `0x4D5390`.
2. **`MemoryCardDialog` (`0x340490`–`0x3429E0`)**:
   - Vtable `0x4DF3F0`.
   - Manages modal confirmation/error prompts:
     - `field_830`: OK button (`0xFA1`).
     - `field_834`: Cancel button (`0xFA2`, hotkey `0x1B`).
     - `field_838`: Text input field (for save file naming).
     - `field_844`: Pointer back to parent `MemoryCardScreen`.
     - `field_84C`: Active modal step/mode (modes 0–29).
   - Drives UI layout/text updates in `0x341040` (jump table `0x4D5570`, 30 entries).
   - Drives event and button routing in `0x342170` (jump table `0x4D55F0`, 30 entries).

---

## Critical Files

### Configuration & Toolchain
- `config/SLES-50282/config.yml`: Splat split boundaries replacing `bin_3394e0_340370` and `bin_340490_3409c0`.
- `config/SLES-50282/symbols.txt`: Extents, sizes, and symbols for all screen and dialog functions and jump tables (`0x4D5390`, `0x4D5570`, `0x4D55F0`).
- `configure.py`: Object registrations and matching status tracking.

### Headers & Types
- `include/memory_card_screen.h`: MemoryCardScreen layout, vtable entries, and subobject members.
- `include/memory_card_dialog.h`: MemoryCardDialog layout, step definitions, and child widget members (transitioning from `include/tactical_ai_layout_341040.h`).

### Implementations
- `src/ui/memory_card_screen.cpp` (or `src/mc/memory_card_screen.cpp`): Screen constructor `0x33DAF0`, input handler `0x33E590`, tick loop `0x33ECE0`, card evaluation `0x33F280`, teardown `0x33F660`, and helpers (`0x33E7B0`, `0x33EA30`, `0x33F480`, `0x33F540`).
- `src/ui/memory_card_dialog.cpp`: Dialog constructor `0x340490`, layout/text updater `0x341040`, event router `0x342170` (integrating `src/ai/tactical_ai_func_342170.cpp` and `src/ai/tactical_ai_handler_340c30.cpp`).

### Tests
- `tests/test_memory_card_screen_matching.py`: Resolved byte-equality gate for screen code and jump table `0x4D5390`.
- `tests/test_memory_card_dialog_matching.py`: Resolved byte-equality gate for dialog code and jump tables `0x4D5570` / `0x4D55F0`.
- `tests/native/memory_card_screen_test.cpp`: Native behavioral test checking states, button actions, and card detection logic.
- `tests/native/memory_card_dialog_test.cpp`: Native behavioral test checking modal steps 0–29, event fallbacks, and dialog/screen acknowledgment.

---

## Phased Execution Strategy

### Phase 1: Splat Segmentation & Symbol Reconciliation
1. Replace opaque segment `bin_3394e0_340370` in `config/SLES-50282/config.yml` with:
   - `bin_3394e0_33daf0` (offset `0x2396C0`–`0x23DCD0`).
   - Code segments for screen functions starting at `0x23DCD0` (`0x33DAF0`):
     - `0x33DAF0` (Constructor, size ~`0x480`)
     - `0x33E590` (Input Handler, size ~`0x220`)
     - `0x33E7B0` (Panel/Widget Setup Helper)
     - `0x33EA30` (Button Setup Helper)
     - `0x33ECE0` (Per-frame Tick Dispatcher, size ~`0x5A0`)
     - `0x33F280` (Card Status Evaluator, size ~`0x200`)
     - `0x33F480` (Slot Table Populator)
     - `0x33F540` (Selection Helper)
     - `0x33F660` (Teardown/Exit Routine)
2. Replace `bin_340490_3409c0` with:
   - `0x340490` (Dialog Constructor, size ~`0x344`)
   - Trailing code/helpers up to `0x3409C0`.
3. Add symbols to `config/SLES-50282/symbols.txt`:
   - Exact entry points and sizes for all new functions.
   - Jump tables: `jtbl_4D5390` (size `0x34`), `jtbl_4D5570` (size `0x78`), `jtbl_4D55F0` (size `0x78`).
4. Validate splat boundaries with `ninja -n` and verify no overlapping or dropped bytes.

### Phase 2: Class Layout Modeling & Native TDD Scaffolding
1. Define `MemoryCardScreen` and `MemoryCardDialog` classes with verified field offsets:
   - `MemoryCardScreen`: `field_804` (action code), `field_808` (mode), `field_818` (label), `field_820` (panel), `field_824` (slot list), `field_82C` (Cancel), `field_830` (Action), `field_8A0` (dialog).
   - `MemoryCardDialog`: `field_830` (OK), `field_834` (Cancel), `field_838` (Name), `field_840` (mode), `field_844` (screen), `field_84C` (step).
2. Write RED native characterization tests in `tests/native/`:
   - Verify layout alignment with compile-time assertions.
   - Verify action codes in `0x33ECE0` (states 1–12, especially state 12 for no card).
   - Verify synthetic click forwarding from dialog to screen `screen + 0x804 = 12`.

### Phase 3: Screen Decompilation & Matching (`0x33DAF0`–`0x340370`)
1. Implement `0x33F280` (Card Evaluation):
   - Logic: Handle `has_card == 0` (hides slot list `0x824`, sets strings `0xC3BD` + `0xC3E3`) vs `has_card != 0` (reads card count from `$gp[-0x71B4]`, formats free space, populates table).
   - Match exact MWCC codegen.
2. Implement `0x33E590` (Button Handler) & `0x33ECE0` (State Machine):
   - Match all 13 jump table cases in `0x33ECE0` and link to `.rodata` table `0x4D5390`.
   - Match button event routing in `0x33E590` (Cancel/Back triggers `0x33F660`, Action triggers save/load actions).
3. Implement `0x33DAF0` (Constructor) & Widget Helpers (`0x33E7B0`, `0x33EA30`, `0x33F660`):
   - Match object instantiation, vtable assignment (`0x4DEF10`), and child dialog creation.
4. Pass byte-matching verification gate for each function in `tests/test_memory_card_screen_matching.py`.

### Phase 4: Dialog Decompilation Completion (`0x340490`–`0x3429E0`)
1. Implement `0x340490` (Dialog Constructor):
   - Instantiate child controls (OK button `0xFA1`, Cancel button `0xFA2` with hotkey `0x1B`, name field `0x838`).
   - Match vtable `0x4DF3F0` assignment.
2. Complete `0x341040` (Layout / Text Updater):
   - Implement all 30 mode branches in `0x341040` using jump table `0x4D5570`.
   - Verify against MWCC compiler output and pass matching gate.
3. Consolidate and re-verify already-matching dialog units:
   - `0x340C30`, `0x340CF0`, `0x340D30`, `0x340D70`, `0x342170`, `0x342820`–`0x3429E0`.

### Phase 5: Domain Reorganization & Registration
1. Register all newly matched objects in `configure.py` as `Matching` under `PS2/mwcc-2.3.1.01`.
2. Transition files and symbols from `tactical_ai_*` to `memory_card_*` domain paths, preserving compatibility aliases.
3. Refresh `docs/badges/*.svg` with `.venv/bin/python -m scripts.observability badges`.

---

## Verification & Testing Gates

1. **Behavioral Gate (TDD)**:
   - Run inside Docker container:
     ```sh
     docker --context docker-dev run --rm -e TZ=America/Sao_Paulo \
       --mount "type=bind,source=$(pwd),target=/workspace" \
       aoe-tests:verification python -m pytest -q -ra tests/test_memory_card_*.py
     ```
   - Must verify:
     - "No card" path: `screen + 0x804 = 12` triggers `func_0033F280(screen, 0)`, slots hidden, Triangle/ESC exits via `0x33F660`.
     - "Card present" path: free blocks computed, slots populated, OK/Cancel actions routed correctly.
2. **Binary Matching Gate (Bit-for-Bit Equality)**:
   - Verified via MWCC PS2 2.3.1.01 (`-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++`).
   - Code and jump tables (`0x4D5390`, `0x4D5570`, `0x4D55F0`) compared 100% byte-for-byte against original `SLES-50282` `AOK.ELF`.
   - Run: `ninja` and `objdiff-cli` check.
