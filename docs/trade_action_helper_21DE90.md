# Packet dispatch at `0x21DE90`

`src/trade_action_helper_21DE90.cpp` reconstructs the eight-argument dispatcher
in pure C++98. A fresh MWCC PS2 compile and isolated link reproduce all **192
original function bytes**. Its `configure.py` registration remains
**NonMatching**, pending independent review. This result does not establish
matching for its callees or the entire palette module.

## Original mapping and boundaries

The PAL `SLES-50282` ELF has SHA-1
`f478e19f2059d52899b691483ef5c7522e30e17c`. Its file-backed `PT_LOAD` has
`p_offset=0x1E0`, `p_vaddr=0x100000`, and `p_filesz=0x3E2FE0`. Thus
`file_offset = VRAM - 0xFFE20` for this function.

- Function: `[0x21DE90, 0x21DF50)`, size `0xC0` / 192 bytes.
- Original file: `[0x11E070, 0x11E130)`.
- Return: `jr ra` at `0x21DF48`; frame restoration at `0x21DF4C` is its delay slot.
- The next function begins at `0x21DF50`; no padding is included in this comparison.

The original payload section names are blank. The mapping above comes from the
load segment, not an inferred original `.text` name.

## Register, stack, and call contract

The reconstructed names describe observed roles; they are not recovered source
identifiers. The function receives `destination`, `format`, `pitch`, and `pixels`
in `a0..a3`, then `x`, `y`, `width`, and `height` in `t0..t3`.

It unconditionally performs four calls:

| Call instruction | Target | Consumed argument or result |
| --- | --- | --- |
| `0x21DED8` | `0x221B60` | Request `0xC`; returned packet feeds DF50. |
| `0x21DF0C` | `0x21DF50` | Nine arguments, listed below. |
| `0x21DF14` | `0x221B60` | Request `0x100`; returned pointer is ignored. |
| `0x21DF1C` | `0x221AC0` | No meaningful input argument or semantic return established. |

The first request is set at `0x21DEBC`, not in a call delay slot. The actual
`0x21DEDC` delay slot preserves incoming `t3` in `s7`. The outgoing packet is
set at `0x21DEF8`, also not a delay slot. The DF50 delay slot at `0x21DF10`
stores `s7` with `sd` at outgoing `0(sp)`.

| DF50 location | Value |
| --- | --- |
| `a0` | First reservation result, including null. |
| `a1` | Sign-extended low 16 bits of `destination`. |
| `a2` | Sign-extended low 16 bits of `format`. |
| `a3` | Sign-extended low 16 bits of `pitch`. |
| `t0` | `pixels`, unchanged. |
| `t1` | `x`, unchanged. |
| `t2` | `y`, unchanged. |
| `t3` | `width`, unchanged. |
| Outgoing `0(sp)` | `height`; DF50 consumes its signed low halfword. |

There is no dispatcher null guard. DF50 handles a null reservation result.
The dispatcher discards DF50's result. Its epilogue physically preserves the
incidental `v0` left by `0x221AC0`; it does **not** return DF50's pointer or
promise zero. The C++ declaration is therefore semantically `void`. The exact
machine comparison also verifies preservation of the incidental register flow.
Known callers either discard or physically forward that value. No meaningful
consumer has been established; external or indirect use remains unresolved.

The shared declarations are in [trade_packet.h](../include/trade_packet.h).
The palette uploader uses that declaration and also has a semantic `void`
return. Its pre-existing copy and swizzle behavior has characterization coverage;
this is not a matching claim for the uploader or its callers. A separate
[palette-width regression](trade_action_palette_21B560.md) corrects its existing
zero-width upload to the original 16-by-16 dimensions.

## Native regression evidence

Tests execute the actual production C++ with `-m32 -std=c++98
-fsanitize=undefined -fno-sanitize-recover=undefined -fno-builtin`.

Before implementation, the four dispatcher cases failed on missing forwarding,
including `actual.input.x == input.x` and `actual.input.y == input.y`:

```sh
python -m pytest -q --tb=short tests/test_trade_action_helper_21DE90.py
```

The two-helper integration test was also run before repairing DE90, with DF50
already corrected. Both cases failed at the real writer assertion `blocks == 7`:

```sh
python -m pytest -q --tb=short tests/test_trade_action_helper_21DE90_chain.py
```

The green command runs four dispatcher cases, thirteen DF50 cases, and both
real-chain cases:

```sh
python -m pytest -q -ra tests/test_trade_action_helper_21DE90.py \
  tests/test_trade_action_helper_21DF50.py \
  tests/test_trade_action_helper_21DE90_chain.py
```

All 19 pass. They cover all arguments, first-three-only sign extension, null
reservation, zero inputs, pointer identity, reservation sizes, and call order.
Three existing palette characterization cases also pass before and after the
shared-declaration refactor.

These commands run in `docker-dev`, using the private
`aoe4-verification-final:20261018` image, with the checkout mounted at
`/workspace` and `TZ=America/Sao_Paulo`. See [testing.md](testing.md) for execution
requirements. Original binaries and licensed compilers are mounted privately,
read-only, at their symlink target paths when required.

## Exact target comparison

```sh
python -m pytest -q -ra tests/test_trade_packet_dispatch_matching.py
```

This permanent test compiles the current C++ with MWCC PS2 2.3.1.01 and
`-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++`.
It selects code through the function symbol's `st_shndx`, handles homonymous
`.text` sections, and rejects unexpected private executable sections.
The isolated GNU link uses `--no-undefined` and `_gp=0x4EA7C0`.

All four `R_MIPS_26` call relocations are resolved before comparison:

| Function-relative offset | Resolved target |
| --- | --- |
| `0x48` | `func_221B60 = 0x221B60` |
| `0x7C` | `func_0021DF50 = 0x21DF50` |
| `0x84` | `func_221B60 = 0x221B60` |
| `0x8C` | `func_221AC0 = 0x221AC0` |

The result is 192 equal bytes, zero different, missing, extra, or private-code
bytes, and zero unresolved symbols. Both original and linked function bytes
have SHA-256 `a776cee773a04ae2abca528c89a3b2c00a1fe27a15c8f7f77db0f1367e8665d6`.

The target regression was added after the behavioral implementation. Running it
against production sources from `4b56eef5dc65a69d28b38a8086713602f33a160f`
fails at `function["st_size"] == SIZE`, with `144 != 192`. This demonstrates
regression sensitivity, not test-first chronology for the implementation.

## Regression gate, 2026-10-18

The unchanged-production baseline at `4b56eef5d` ran with identical private
prerequisites: 2,595 passed, one intentional DF50 write-count failure, zero skips.
The repaired checkout passes all 2,614 tests, with zero failures or skips:

```sh
python -m pytest tests -q -ra --tb=short --junitxml=build/abi-current-full.xml
```

The expanded trade-action subsystem passes 1,303 tests:

```sh
python -m pytest -q -ra tests/test_trade_action* tests/test_trade_packet_dispatch_matching.py
```

Default `ninja -j4` and explicit builds of the B440, DE90, and DF50 objects
succeed. Python lint, `git diff --check`, and all 30 local links in the six
changed documents pass. Objdiff reports DE90 at 100%; its MIPS debug-line parser
still emits the inherited `range exceeds .mdebug size` warning.

The fresh raw project report records 194,676 / 863,568 matched code bytes and
1,305 / 3,085 matched functions across 889 registered units. These totals include
other source kinds and are **not** a verified pure-C++ completion measurement.
