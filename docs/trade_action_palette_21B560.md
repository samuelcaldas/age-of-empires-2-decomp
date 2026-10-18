# Palette upload dimensions at `0x21B560`

The palette uploader in `src/trade_action_helper_21B440.cpp` must dispatch a
**16 by 16** palette. It previously passed `width=0,height=16` to the correctly
reconstructed [packet dispatcher](trade_action_helper_21DE90.md). The zero width
would produce a zero block count in [DF50](trade_action_helper_21DF50.md).
Only the wrong width is changed here; this is not a full matching claim for
the palette module or its other argument calculations.

## Raw original evidence

The PAL ELF SHA-1 is `f478e19f2059d52899b691483ef5c7522e30e17c`.
Its file-backed `PT_LOAD` maps `p_offset=0x1E0` to `p_vaddr=0x100000`, giving
`file_offset = VRAM - 0xFFE20` for these instructions.

| VRAM | Raw word | R5900 instruction |
| --- | --- | --- |
| `0x21B5F0` | `0x240A0010` | `addiu t2,zero,0x10` |
| `0x21B634` | `0x080877A4` | `j 0x21DE90` |
| `0x21B638` | `0x71405E28` | `paddub t3,t2,zero` |

The final instruction executes in the jump delay slot. Therefore both `t2`
and `t3` are `16` at the dispatcher boundary. Their verified meanings are
`width` and `height`, respectively. The corrected call is:

```cpp
func_0021DE90(0x1F00, 0, 4, D_00C5DF00, t0, t1, 16, 16);
```

The raw words were checked before changing production code. A second session
independently confirmed the same instructions. No disputed arithmetic or return
expectation was changed as part of this repair.

## Regression evidence

The native palette harness now records the dispatcher's seventh argument,
`t2`. Both the set-and-upload case and direct swizzle-and-upload case assert
`last_21de90_t2 == 16`, while retaining all prior assertions.

Before changing the production call:

```sh
python -m pytest -q --tb=short tests/test_trade_action_helper_21B440.py
```

Result: two failed, one passed. Both failures were the behavioral assertion
`last_21de90_t2 == 16`; the harness compiled and executed. The separate log is
`build/abi-palette-width-red.log`.

The same cases run green after the one-argument correction:

```sh
python -m pytest -q -ra tests/test_trade_action_helper_21B440.py
```

Run commands inside the private `aoe4-verification-final:20261018` image using
`docker-dev`, a checkout mount at `/workspace`, and `TZ=America/Sao_Paulo`.
See [testing.md](testing.md). The existing palette fixture uses 32-bit native
C++; unlike the DE90/DF50 fixtures, it does not request C++98 or UBSan.
The palette harness observes the boundary argument. The existing two-helper
integration suite separately exercises the real DE90-to-DF50 chain.

The three palette cases pass after correction. The related focused gate passes
23 tests, including the permanent complete DE90 target comparison. The full
provisioned suite passes 2,614 tests with zero failures or skips:

```sh
python -m pytest tests -q -ra --tb=short --junitxml=build/abi-palette-current-full.xml
```

The complete trade-action subsystem also passes 1,303 tests with zero failures
or skips:

```sh
python -m pytest -q -ra tests/test_trade_action* tests/test_trade_packet_dispatch_matching.py
```

Its log is `build/abi-palette-subsystem.log`; the fresh objdiff report is
`build/abi-palette-report.json`. Report generation succeeds with the inherited
MIPS debug-line warning, `range exceeds .mdebug size`.

Default `ninja -j4` and explicit builds of the palette, DE90, and DF50 objects
succeed. The combined green/full/build log is `build/abi-palette-green-full.log`.

DE90 and DF50 remain registered **NonMatching** pending review. DE90's separate
192-byte relocated exact-match regression remains green. DF50's 304-byte
candidate still differs from its 308-byte original function.
