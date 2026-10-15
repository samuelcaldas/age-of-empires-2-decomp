# Plan: Slicing Trade Action Market Operations & Multi-Session Distribution

## Context
With the entire repository achieving zero assembly (`.s`) files across all 105 linked units and the `trade_action_evaluator` slice (up to VRAM `0x148FF0` / file offset `0x491E0`) successfully matched and merged, the next contiguous binary section in PlayStation 2 PAL `AOK.ELF` begins at file offset `0x491E0` (VRAM `0x149000`). This section covers `TradeAction` market evaluation, trade goods updating, and spatial search routines (3,120 bytes of code across 6 functions).

This plan slices this 3,120-byte block into 4 balanced, conflict-free units, configures the splat slicer and build toolchain, introduces initial pure C++ compilable stubs, and broadcasts task ownership across all four active Claude sessions (`aoe1`, `aoe2`, `aoe3`, `aoe4`).

## Slice Boundaries & Parallel Assignment

Each unit is completely disjoint in file offsets, VRAM addresses, and object files:

| Unit Name | Owner | File Offset Range | VRAM Address Range | Functions | Total Size |
|---|---|---|---|---|---|
| `trade_action_market_eval` | **aoe1** | `0x491E0`–`0x49640` | `0x149000`–`0x149460` | `func_00149000` (`0x460` / 1,120 B) | 1,120 B |
| `trade_action_market_ops` | **aoe3** | `0x49640`–`0x49850` | `0x149460`–`0x149670` | `func_00149460` (`0x1B0` / 432 B)<br>`func_00149610` (`0x60` / 96 B) | 528 B |
| `trade_action_market_strategy` | **aoe4** | `0x49850`–`0x49BE0` | `0x149670`–`0x149A00` | `func_00149670` (`0x390` / 912 B) | 912 B |
| `trade_action_market_items` | **aoe2** (this session) | `0x49BE0`–`0x49E10` | `0x149A00`–`0x149C30` | `func_00149A00` (`0xE0` / 224 B)<br>`func_00149AE0` (`0x150` / 336 B) | 560 B |

The remainder of the binary (`post_base`) advances to start at file offset `0x49E10` (VRAM `0x149C30`).

---

## Step-by-Step Implementation Steps

### 1. Update Slicer Configuration (`config/SLES-50282/config.yml`)
Replace the current `post_base` bin segment starting at `0x491E0` with the 4 code segments and move `post_base` to `0x49E10`:
```yaml
  - name: trade_action_market_eval
    type: code
    start: 0x491E0
    vram: 0x149000
    subsegments:
      - [0x491E0, asm, trade_action_market_eval]
  - name: trade_action_market_ops
    type: code
    start: 0x49640
    vram: 0x149460
    subsegments:
      - [0x49640, asm, trade_action_market_ops]
  - name: trade_action_market_strategy
    type: code
    start: 0x49850
    vram: 0x149670
    subsegments:
      - [0x49850, asm, trade_action_market_strategy]
  - name: trade_action_market_items
    type: code
    start: 0x49BE0
    vram: 0x149A00
    subsegments:
      - [0x49BE0, asm, trade_action_market_items]
  - name: post_base
    type: bin
    start: 0x49E10
  - [0x3e31c0]
```

### 2. Update Symbol Addresses (`config/SLES-50282/symbols.txt`)
Append the 6 functions with exact addresses and sizes:
```
func_00149000 = 0x149000; // type:func size:0x460 absolute:True
func_00149460 = 0x149460; // type:func size:0x1B0 absolute:True
func_00149610 = 0x149610; // type:func size:0x60 absolute:True
func_00149670 = 0x149670; // type:func size:0x390 absolute:True
func_00149A00 = 0x149A00; // type:func size:0xE0 absolute:True
func_00149AE0 = 0x149AE0; // type:func size:0x150 absolute:True
```

### 3. Update Object Registration (`configure.py`)
Add the four new matching objects to the PS2 object list in `configure.py`:
```python
                Object(
                    Matching,
                    "trade_action_market_eval",
                    source="trade_action_market_eval.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_market_ops",
                    source="trade_action_market_ops.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_market_strategy",
                    source="trade_action_market_strategy.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_market_items",
                    source="trade_action_market_items.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
```

### 4. Create Initial Pure C++ Scaffolding
Create initial `.cpp` source files under `src/` with `#pragma exceptions off`, `#include "sub_list.h"`, and minimal valid pure C++ stubs matching function signatures:
- `src/trade_action_market_eval.cpp`: defines `func_00149000`
- `src/trade_action_market_ops.cpp`: defines `func_00149460`, `func_00149610`
- `src/trade_action_market_strategy.cpp`: defines `func_00149670`
- `src/trade_action_market_items.cpp`: defines `func_00149A00`, `func_00149AE0`

### 5. Build, Validate & Commit
- Run `.venv/bin/python configure.py --version SLES-50282 --compilers compilers && ninja`.
- Verify report generation (`build/SLES-50282/report.json`), progress calculation, and 100.00% link without errors.
- Ensure working tree is clean. Commit and push to `origin/main` following the multi-developer synchronization policy.

### 6. Broadcast Assignments to Peer Sessions
Send cross-session directives via `SendMessage`:
- To `aoe1`: assign `trade_action_market_eval` (`0x149000`–`0x149460`, 1,120 B, worktree `.worktrees/trade-market-eval`).
- To `aoe3`: assign `trade_action_market_ops` (`0x149460`–`0x149670`, 528 B, worktree `.worktrees/trade-market-ops`).
- To `aoe4`: assign `trade_action_market_strategy` (`0x149670`–`0x149A00`, 912 B, worktree `.worktrees/trade-market-strategy`).
- Begin work in `aoe2` on `trade_action_market_items` (`0x149A00`–`0x149C30`, 560 B, worktree `.worktrees/trade-market-items`).

---

## Verification
- Run `ninja` to confirm all 109 units compile, link, and report cleanly.
- Verify with `git status` that no untracked or dirty files exist.
- Inspect `build/SLES-50282/report.json` to verify the 6 new symbols appear in the report.
