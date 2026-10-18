# Palette upload dimensions and null-data flow at `0x21B560`

The palette uploader in `src/trade_action_helper_21B440.cpp` dispatches a
**16 by 16** palette. It previously passed `width=0,height=16` to the correctly
reconstructed [packet dispatcher](trade_action_helper_21DE90.md). Furthermore,
an early return on null `palette_data` incorrectly aborted the entire upload;
the original binary skips swizzling but continues to read `palette_obj + 2` and
dispatches the upload with the existing staging buffer contents.
These fixes do not constitute a full matching claim for the entire palette module
or its other argument calculations.

## Raw original evidence

The PAL ELF SHA-1 is `f478e19f2059d52899b691483ef5c7522e30e17c`.
Its file-backed `PT_LOAD` maps `p_offset=0x1E0` to `p_vaddr=0x100000`, giving
`file_offset = VRAM - 0xFFE20` for these instructions.

| VRAM | Raw word | R5900 instruction |
| --- | --- | --- |
| `0x21B560` | `0x10A00021` | `beq a1,zero,+33` (target `0x21B5E8`) |
| `0x21B564` | `0x00000000` | `nop` (branch delay slot) |
| `0x21B5E8` | `0x94830002` | `lhu v1,2(a0)` (read `clut_offset`) |
| `0x21B5F0` | `0x240A0010` | `addiu t2,zero,0x10` |
| `0x21B634` | `0x080877A4` | `j 0x21DE90` |
| `0x21B638` | `0x71405E28` | `paddub t3,t2,zero` |

The entry branch at `0x21B560` tests if `palette_data` (`$a1`) is null.
If null, it jumps to `0x21B5E8`, completely skipping the 256-iteration swizzle loop.
It then reads `palette_obj + 2`, calculates the CLUT arguments (`t0` and `t1`),
sets `a0=0x1F00`, `a1=0`, `a2=4`, `a3=D_00C5DF00`, `t2=16`, and tail-jumps to `0x21DE90`.
The delay slot at `0x21B638` sets `t3=16`.
Therefore:
1. `t2` and `t3` are both `16` at the dispatcher boundary (`width` and `height`).
2. Null `palette_data` still dispatches the upload without modifying `D_00C5DF00`.

The corrected call and control flow are:

```cpp
void func_0021B560(void *palette_obj, const char *palette_data) {
    if (palette_data != 0) {
        for (int i = 0; i < 256; i++) {
            int swizzled_idx = ((i >> 5) << 5) | (((i >> 4) & 1) << 3) | (((i >> 3) & 1) << 4) | (i & 7);
            const char *src = palette_data + i * 4;
            char *dst = D_00C5DF00 + swizzled_idx * 4;
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst[3] = src[3];
        }
    }

    unsigned short clut_offset = *(unsigned short *)((char *)palette_obj + 2);
    int clut_base = clut_offset >> 4;
    int v1 = ((clut_base >> 2) << 5) | ((clut_base & 1) << 4);
    int v0 = (clut_base & 2) << 3;

    int t0 = (short)v1;
    int t1 = (short)v0;

    func_0021DE90(0x1F00, 0, 4, D_00C5DF00, t0, t1, 16, 16);
}
```

The raw words were verified independently before changing production code. No disputed
arithmetic or return expectation was changed.

## Regression evidence

The native palette harness records dispatcher calls and arguments `a0`, `a1`, `a2`,
`clut_buf`, `t0`, `t1`, `t2`, and `t3`.

### 1. Width regression (committed in `d28eaa5f6`)
Asserted `last_21de90_t2 == 16` in existing palette test cases.
Before fix: 2 failed, 1 passed (`build/abi-palette-width-red.log`).
After fix: 3 passed.

### 2. Null palette data regression
Added `test_case_null_palette_data_upload` to verify that passing `palette_data == nullptr`
calls `func_0021DE90` once with `a0=0x1F00, a1=0, a2=4, t2=16, t3=16` and leaves `D_00C5DF00`
unmodified.
Before fix: 1 failed, 3 passed (`build/abi-palette-null-red.log`), failing at `c21de90_calls == 1`.
After fix: 4 passed (`build/abi-palette-null-green.log`).

Run commands inside the private `aoe4-verification-final:20261018` image using
`docker-dev`, a checkout mount at `/workspace`, and `TZ=America/Sao_Paulo`.
See [testing.md](testing.md). The existing palette fixture uses 32-bit native
C++; unlike the DE90/DF50 fixtures, it does not request C++98 or UBSan.
The palette harness observes boundary arguments; the integration suite
separately exercises the real DE90-to-DF50 chain.

The four palette cases pass after correction. The related focused gate passes
24 tests, including the permanent complete DE90 target comparison. The full
provisioned suite passes 2,615 tests with zero failures or skips:

```sh
python -m pytest tests -q -ra --tb=short --junitxml=build/abi-palette-null-full.xml
```

The complete trade-action subsystem also passes 1,304 tests with zero failures
or skips:

```sh
python -m pytest -q -ra tests/test_trade_action* tests/test_trade_packet_dispatch_matching.py
```

Its log is `build/abi-palette-null-subsystem.log`.

Default `ninja -j4` and explicit builds of the palette, DE90, and DF50 objects
succeed.

DE90 and DF50 remain registered **NonMatching** pending review. DE90's separate
192-byte relocated exact-match regression remains green. DF50's 304-byte
candidate still differs from its 308-byte original function.
