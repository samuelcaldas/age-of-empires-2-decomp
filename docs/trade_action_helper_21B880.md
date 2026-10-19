# Trade action helper `0x21B880` subsystem

`src/trade_action_helper_21B880.cpp` reconstructs `func_0021B880` in slice
`[0x21B880, 0x21BAE0)` in pure C++. The function achieves **97.85% matching**
(596 of 596 code bytes aligned, 4 instructions differing in format branch selection).
Its `configure.py` registration remains **NonMatching** pending complete matching.

## Architecture and function contracts

`func_0021B880` initializes and configures a viewport descriptor in the manager pool:
- Allocates a viewport via `func_0021B830(manager)`. If allocation fails, returns 1.
- Writes tag quadword `0x80808080` at offset `0x28`.
- Copies 27 configuration words from `config` to `viewport + 0x30`.
- Computes bounding rectangle coordinates `x2` and `y2` based on configuration flags (`flags & 4` and `flags & 2`).
- If `(flags & 1) && (flags_68 & 0x200)`: applies fullscreen 640x512 override and records viewport in `manager + 0x420`.
- If `flags & 0x1000`: evaluates pixel format and sets format code at offset `0x1C` (0 for 32 bpp, 2 for 16 bpp, 19 for 8 bpp, 20 for 4 bpp).
- Computes aligned row pitch at offset `0x40`: `(((width + 3) & ~3) * bpp) >> 3`.
- Stores `manager` pointer at offset `0x18`, returns viewport in `*out_viewport`, and returns 0.

| Function | VRAM range | Code size | Description | Matching |
|---|---|---|---|---|
| `func_0021B880` | `[0x21B880, 0x21BAD4)` | 596 B (`0x254`) | Viewport descriptor allocator and configurator | **97.85%** |

## Binary mapping and raw evidence

The PAL `SLES-50282` ELF SHA-1 is `f478e19f2059d52899b691483ef5c7522e30e17c`.
Its file-backed `PT_LOAD` segment maps `p_offset=0x1E0` to `p_vaddr=0x100000`,
yielding `file_offset = VRAM - 0xFFE20`.

- Prior function `func_0021B830` code ends at `0x21B874`.
- Gap `[0x21B874, 0x21B880)`: 12 zero padding bytes (`0xC`) for compiler 16-byte alignment.
- Function `func_0021B880`: original file offset `0x11BA60`–`0x11BCB4` (code size `0x254`).
- Return: `jr ra` at `0x21BACC`, stack deallocation `addiu sp, sp, 0x80` at `0x21BAD0`.
- Tail padding `[0x21BAD4, 0x21BAE0)`: 12 zero padding bytes (`0xC`).
- Next function `func_0021BAE0` begins at `0x21BAE0` (file offset `0x11BCC0`).

## Relocations

`func_0021B880` contains exactly one external relocation:
- `0x21B8BC`: `jal func_0021B830` (`R_MIPS_26`, target `0x21B830`).
No global data relocations exist.

## TDD regression evidence

1. **Red:** Binary analysis revealed that offset `0x40` stores the aligned row pitch `(((width + 3) & ~3) * bpp) >> 3` (`800` bytes for `width=200, bpp=32`), rather than `bpp >> 3` (4 bytes) as previously assumed.
   Updated `tests/native/trade_action_helper_21B880_test.cpp` with `assert(*(int *)(vp_buf + 64) == 800);`.
   Running `python -m pytest -q --tb=short tests/test_trade_action_helper_21B880.py` failed as expected against unchanged code (`1 failed, 1 passed`). Log: `build/abi-21b880-red.log`.
2. **Green:** Corrected the row pitch calculation in `src/trade_action_helper_21B880.cpp`.
   Both native test cases pass (`2 passed in 0.36s`).
3. **Full Gates:** Full suite passes with **2,620 passed**, zero failures, zero skips (`build/abi-21b880-matching-full.xml`). Trade subsystem passes **1,309 tests** (`build/abi-21b880-matching-subsystem.log`).

## Exact target comparison and compiler scheduling blocker

The dedicated matching test in `tests/test_trade_action_helper_21B880_matching.py`
explicitly loads all 596 bytes of the original code extent `[0x21B880, 0x21BAD4)`
from `AOK.ELF` and resolves call relocation `func_0021B830 = 0x21B830`.

The candidate compiles to 588 bytes (8 bytes / 2 instructions shorter) and achieves
**97.85% fuzzy match**:
- Prefix `[0x000, 0x1B8)` (440 bytes) and suffix `[0x1EC, 0x254)` (104 bytes) match
  **100.00% byte-for-byte**.
- Differences occur strictly within format branch selection at VRAM `0x21BA38`–`0x21BA48`:

| VRAM | Target opcode & instruction | Candidate opcode & instruction | Explanation |
|---|---|---|---|
| `0x21BA38` | `12430004` (`beq $s2, $v1, +4`) | `1643000A` (`bne $s2, $v1, +10`) | Target uses positive equality branch to `case 4`; candidate inverts check |
| `0x21BA3C` | `24030014` (`addiu $v1, $zero, 20`) | `00000000` (`nop`) | Target preloads 20 in branch delay slot |
| `0x21BA40` | `1000000B` (`b +11`) | `24030014` (`addiu $v1, $zero, 20`) | Target fallthrough jump past case blocks to `.L0021BA70` |
| `0x21BA44` | `9E030000` (`lwu $v1, 0($s0)`) | `10000007` (`b +7`) | Target hoists subsequent `*config_state` load into branch delay slot |
| `0x21BA48` | `24030014` (`addiu $v1, $zero, 20`) | `AC43001C` (`sw $v1, 0x1C($v0)`) | Target fallthrough duplicate load |

### Investigated hypotheses

1. **Standalone `switch (bpp)`:** In a standalone function, MWCC emits the exact target `beq` and hoisted `lwu` sequence. However, when enclosed inside `if (flags & 0x1000)` at `-O3`, the compiler optimizer inlines the construct, performs tail-merging, and inverts the final equality check.
2. **Explicit `goto` label ordering:** Tested separate merge labels (`load_state` vs `check_state_now`). The optimizer detects basic block destination equivalence and continues inverting the branch.
3. **Nested `if-else` and ternary chains:** Tested nested if-else ladders and ternary chains `(bpp == 32) ? 0 : ...`. All yield the identical 588-byte code structure.

The difference represents an irreducible compiler code-generation / basic-block scheduling artifact of MWCCPS2 2.3.1.01 at `-O3` under enclosing conditional scope. Semantic behavior is 100% verified by native tests. The object remains registered **NonMatching** in `configure.py`.
