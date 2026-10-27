# Render Font Context Handlers Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Slice, decompile, natively test, and 100% bit-match the PS2 font/glyph context handlers in `render_font_context` (VRAM `0x21FEC0` - `0x21FF40`) from `orig/SLES-50282/AOK.ELF`.

**Architecture:** Decompile three functions into `src/render/render_font_context.cpp`: `func_0021FEC0` (active font context setter via GP-relative pointer store to `D_004E32FC`), `func_0021FED0` (active font context getter via GP-relative pointer load from `D_004E32FC`), and `func_0021FEE0` (glyph advance width/range lookup iterating a sentinel-terminated 8-byte-stride glyph range table).

**Tech Stack:** C++ (`-lang=c++`), Metrowerks CodeWarrior MIPS C/C++ Compiler for PS2 (`PS2/mwcc-2.3.1.01`, flags `-O3 -inline on -msext on -char signed -sym off -Iinclude`), Python 3 (`pytest`, `pyelftools`), Docker (`docker-dev` context, image `aoe-tests:verification`).

**Spec:** Task specification for slicing and decompiling font/glyph context handlers in `post_21E370` / `post_21CD20` (VRAM `0x21FEC0` - `0x21FF40`).

## Global Constraints

- Platform: PS2 PAL (`SLES-50282`), SHA-1 `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Compiler: MWCCPS2 2.3.1.01 with flags `-O3 -inline on -msext on -char signed -sym off -Iinclude`.
- Timezone: `TZ=America/Sao_Paulo` in docker container runs.
- C/C++ Only: Assembly (`.s` / `.word asm`) never counts for matching; real C/C++ is mandatory.
- No Empty Stubs: Empty stubs (`{}`) to remove ASM are strictly forbidden.
- Tail Calls & Leaf functions: `#pragma exceptions off` enables leaf function generation without stack frames.
- MWCC Homonymous `.text` sections: MWCC emits multiple separate `.text` sections per object in C++ mode; symbol matching must index via `st_shndx`.
- GP-Relative symbol: In `SLES-50282`, `ri_gp_value = 0x4EA7C0`, and `-0x74C4($gp)` resolves to address `0x4E32FC` (`0x8B3C` as unsigned 16-bit offset).

## Review Focus

1. **Character below minimum glyph range:** Input `c` is smaller than `table->first` -> Function correctly skips the bucket without underflow or false match.
2. **Character at range boundaries:** Input `c == table->first` and `c == table->last` -> Correctly returns exact range endpoints (`glyph_offset` and `glyph_offset + (last - first)`).
3. **Empty or sentinel-only table:** Table with immediate `first == 0xFFFF` -> Returns `-1` without inspecting subsequent bytes or memory access violation.
4. **Context pointer roundtrip:** Setting `NULL`, arbitrary heap pointers, or aligned structure pointers through `func_0021FEC0` and reading back through `func_0021FED0` preserves pointer identity exactly.
5. **Character between non-contiguous ranges:** Table with gaps (e.g., '0'-'9' and 'A'-'Z') looking up a character in the gap (e.g., ':') -> Scans past first range, fails second range, and returns `-1`.

---

### Task 1: Slicer configuration and symbol registration

**Files:**
- Modify: `config/SLES-50282/config.yml:4994-5005`
- Modify: `config/SLES-50282/symbols.txt:2080-2100`

**Interfaces:**
- Produces: Slicer slice `render_font_context` at offset `0x1200A0` (VRAM `0x21FEC0`) and symbols `func_0021FEC0`, `func_0021FED0`, `func_0021FEE0`, `D_004E32FC`.

- [ ] **Step 1: Write validation test for slice boundaries and symbols**

Verify that `config/SLES-50282/config.yml` contains `render_font_context` at file offset `0x1200A0` and `post_21FF40` at `0x120120`, and `symbols.txt` contains the four symbols.

- [ ] **Step 2: Run test to verify it fails**

Run:
```bash
python3 -c "
import yaml
cfg = yaml.safe_load(open('config/SLES-50282/config.yml'))
segs = {s['name']: s for s in cfg['segments'] if isinstance(s, dict)}
assert 'render_font_context' in segs
assert 'post_21FF40' in segs
"
```
Expected: FAIL (`AssertionError: 'render_font_context' not in segs`).

- [ ] **Step 3: Update `config/SLES-50282/config.yml` and `config/SLES-50282/symbols.txt`**

In `config/SLES-50282/config.yml`:
Replace the monolithic `post_21CD20` segment with:
```yaml
  - name: post_21CD20
    type: bin
    start: 0x11D190
  - name: render_font_context
    type: code
    start: 0x1200A0
    vram: 0x21FEC0
    subsegments:
      - [0x1200A0, asm, render/render_font_context]
  - name: post_21FF40
    type: bin
    start: 0x120120
```

In `config/SLES-50282/symbols.txt`:
Add:
```text
func_0021FEC0 = 0x21FEC0; // type:func size:0x10 absolute:True
func_0021FED0 = 0x21FED0; // type:func size:0x10 absolute:True
func_0021FEE0 = 0x21FEE0; // type:func size:0x50 absolute:True
D_004E32FC = 0x4E32FC; // type:void* size:4 absolute:True
```

- [ ] **Step 4: Run validation test to verify it passes**

Run:
```bash
python3 -c "
import yaml
cfg = yaml.safe_load(open('config/SLES-50282/config.yml'))
segs = {s['name']: s for s in cfg['segments'] if isinstance(s, dict)}
assert segs['render_font_context']['start'] == 0x1200A0
assert segs['render_font_context']['vram'] == 0x21FEC0
assert segs['post_21FF40']['start'] == 0x120120
syms = open('config/SLES-50282/symbols.txt').read()
assert 'func_0021FEC0' in syms
assert 'func_0021FED0' in syms
assert 'func_0021FEE0' in syms
assert 'D_004E32FC' in syms
print('Config and symbols verified successfully.')
"
```
Expected: PASS (`Config and symbols verified successfully.`).

- [ ] **Step 5: Commit**

```bash
git add config/SLES-50282/config.yml config/SLES-50282/symbols.txt
git commit -m "config(sles): split render_font_context slice and register symbols"
```

---

### Task 2: Native behavioral test harness (Red phase)

**Files:**
- Create: `include/render_font_context.h`
- Create: `tests/native/render_font_context_test.cpp`
- Create: `tests/test_render_font_context.py`

**Interfaces:**
- Consumes: `func_0021FEC0(void*)`, `func_0021FED0()`, `func_0021FEE0(const GlyphRange*, int)`
- Produces: Native test executable exercising edge cases, bounds, and roundtrips in isolated processes.

- [ ] **Step 1: Create `include/render_font_context.h`**

Define the `GlyphRange` structure and C function declarations:
```cpp
#ifndef RENDER_FONT_CONTEXT_H
#define RENDER_FONT_CONTEXT_H

#ifdef __cplusplus
extern "C" {
#endif

struct GlyphRange {
    unsigned short first;
    unsigned short last;
    unsigned short glyph_offset;
    unsigned short pad;
};

void func_0021FEC0(void *ctx);
void *func_0021FED0(void);
int func_0021FEE0(const struct GlyphRange *table, int c);

#ifdef __cplusplus
}
#endif

#endif // RENDER_FONT_CONTEXT_H
```

- [ ] **Step 2: Create `tests/native/render_font_context_test.cpp`**

Implement standalone behavioral test suite with test cases:
- Case 0: Font context pointer setter and getter roundtrip (`NULL`, heap address, stack address).
- Case 1: Empty glyph table with immediate sentinel (`0xFFFF`) returns `-1`.
- Case 2: Single range table (`'A'`=65 to `'Z'`=90, `glyph_offset`=100) tests lower out-of-bounds ('@'), lower bound ('A'), middle ('B'), upper bound ('Z'), and upper out-of-bounds ('[').
- Case 3: Disjoint multi-range table (digits `'0'-'9'`, uppercase `'A'-'Z'`) tests gap rejection (':') and range resolution.

- [ ] **Step 3: Create `tests/test_render_font_context.py`**

Implement pytest wrapper compiling native 32-bit test binary with `g++ -m32` and invoking cases 0-3 with assertion checks.

- [ ] **Step 4: Run test in Docker to verify Red phase failure**

Run:
```bash
docker --context docker-dev run --rm -e TZ=America/Sao_Paulo --mount "type=bind,source=$(pwd),target=/workspace" -w /workspace aoe-tests:verification python -m pytest -q -ra tests/test_render_font_context.py
```
Expected: FAIL (compilation error due to missing `src/render/render_font_context.cpp`).

- [ ] **Step 5: Commit test harness**

```bash
git add include/render_font_context.h tests/native/render_font_context_test.cpp tests/test_render_font_context.py
git commit -m "test(render): add native behavioral tests for render_font_context"
```

---

### Task 3: Implementation and build registration (Green phase)

**Files:**
- Create: `src/render/render_font_context.cpp`
- Modify: `configure.py:2670-2700`

**Interfaces:**
- Consumes: `include/render_font_context.h`, `D_004E32FC`
- Produces: `render/render_font_context` object matching registration in build system.

- [ ] **Step 1: Implement `src/render/render_font_context.cpp`**

Write the exact C++ source:
```cpp
#pragma exceptions off
#include "render_font_context.h"

extern "C" {
extern void *D_004E32FC;

void func_0021FEC0(void *ctx) {
    D_004E32FC = ctx;
}

void *func_0021FED0(void) {
    return D_004E32FC;
}

int func_0021FEE0(const struct GlyphRange *table, int c) {
    int ret = -1;
    while (1) {
        if (table->first == 0xFFFF) {
            break;
        }
        if (c >= table->first && c <= table->last) {
            ret = table->glyph_offset + c - table->first;
            break;
        }
        table++;
    }
    return ret;
}
}
```

- [ ] **Step 2: Register in `configure.py`**

In `configure.py` under the PS2 matching object list (around line 2675, right after `render/render_packet_builder_21cd20`):
```python
                Object(
                    Matching,
                    "render/render_font_context",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
```

- [ ] **Step 3: Run pytest in Docker to verify Green phase**

Run:
```bash
docker --context docker-dev run --rm -e TZ=America/Sao_Paulo --mount "type=bind,source=$(pwd),target=/workspace" -w /workspace aoe-tests:verification python -m pytest -q -ra tests/test_render_font_context.py
```
Expected: PASS (`4 passed in 0.xx s`).

- [ ] **Step 4: Commit**

```bash
git add src/render/render_font_context.cpp configure.py
git commit -m "feat(render): implement render_font_context slice"
```

---

### Task 4: Bit-for-bit target matching verification

**Files:**
- Create: `tests/render_font_context_matching_support.py`
- Create: `tests/test_render_font_context_matching.py`

**Interfaces:**
- Consumes: `orig/SLES-50282/AOK.ELF`, `compilers/PS2/mwcc-2.3.1.01/mwccps2.exe`, `build/tools/wibo`
- Produces: Exact bit-for-bit verification of compiled object against original ELF binary.

- [ ] **Step 1: Create `tests/render_font_context_matching_support.py`**

Implement relocation resolver and compiler runner:
- Target functions:
  - `func_0021FEC0`: VRAM `0x21FEC0`, size `0x08`
  - `func_0021FED0`: VRAM `0x21FED0`, size `0x08`
  - `func_0021FEE0`: VRAM `0x21FEE0`, size `0x54`
- Relocations:
  - `GPREL_SYMBOLS`: `{"D_004E32FC": 0x8B3C}` (matching `-0x74C4($gp)`)
- Section selection using `symbol["st_shndx"]` for homonymous `.text` sections.

- [ ] **Step 2: Create `tests/test_render_font_context_matching.py`**

Implement matching test functions:
- `test_render_font_context_matches_original`: checks instruction bytes of all 3 functions against `AOK.ELF`.
- `test_render_font_context_split_boundaries`: verifies segment boundaries and prologue/padding instructions in `AOK.ELF` at `0x21FEC0`, `0x21FED0`, `0x21FEE0`, and `0x21FF40`.

- [ ] **Step 3: Run matching test locally and in Docker**

Run:
```bash
docker --context docker-dev run --rm -e TZ=America/Sao_Paulo --mount "type=bind,source=$(pwd),target=/workspace" -w /workspace aoe-tests:verification python -m pytest -q -ra tests/test_render_font_context_matching.py
```
Expected: PASS (`4 passed in 0.xx s`).

- [ ] **Step 4: Commit**

```bash
git add tests/render_font_context_matching_support.py tests/test_render_font_context_matching.py
git commit -m "test(render): add 100% bit-for-bit matching tests for render_font_context"
```

---

### Task 5: Regression gate and clean tree verification

**Files:**
- Test: Full render subsystem test suite `tests/test_render_*.py`

- [ ] **Step 1: Run full render test suite in Docker**

Run:
```bash
docker --context docker-dev run --rm -e TZ=America/Sao_Paulo --mount "type=bind,source=$(pwd),target=/workspace" -w /workspace aoe-tests:verification python -m pytest -q -ra tests/test_render_*.py
```
Expected: All tests pass with 0 regressions.

- [ ] **Step 2: Run ninja dry-run or configure test**

Run:
```bash
.venv/bin/python configure.py --version SLES-50282 --compilers compilers/
ninja -n
```
Expected: Build configuration succeeds, ninja reports build targets valid.

- [ ] **Step 3: Check working directory cleanliness**

Run:
```bash
git status
```
Expected: Working tree clean, default branch sync clean.

---

## Verification Plan

### Automated Tests
1. **Behavioral unit tests:**
   `docker --context docker-dev run --rm -e TZ=America/Sao_Paulo --mount "type=bind,source=$(pwd),target=/workspace" -w /workspace aoe-tests:verification python -m pytest -q -ra tests/test_render_font_context.py`
2. **Matching tests:**
   `docker --context docker-dev run --rm -e TZ=America/Sao_Paulo --mount "type=bind,source=$(pwd),target=/workspace" -w /workspace aoe-tests:verification python -m pytest -q -ra tests/test_render_font_context_matching.py`
3. **Subsystem regression test suite:**
   `docker --context docker-dev run --rm -e TZ=America/Sao_Paulo --mount "type=bind,source=$(pwd),target=/workspace" -w /workspace aoe-tests:verification python -m pytest -q -ra tests/test_render_*.py`
4. **Ninja build plan:**
   `.venv/bin/python configure.py --version SLES-50282 --compilers compilers/ && ninja -n`
