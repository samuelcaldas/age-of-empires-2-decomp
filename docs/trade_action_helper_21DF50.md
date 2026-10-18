# Packet construction at `0x21DF50`

`src/trade_action_helper_21DF50.cpp` reconstructs the packet helper in pure
C++98. Thirteen native cases and two real-dispatch integration cases pass with
undefined-behavior sanitization. The function remains **NonMatching**:
the current MWCC entry is 304 bytes, versus 308 original bytes.

## Original mapping and boundaries

The PAL `SLES-50282` ELF has SHA-1
`f478e19f2059d52899b691483ef5c7522e30e17c`. The file-backed `PT_LOAD` maps
`p_offset=0x1E0` to `p_vaddr=0x100000`, with `p_filesz=0x3E2FE0`.
For this range, `file_offset = VRAM - 0xFFE20`.

- Function: `[0x21DF50, 0x21E084)`, size `0x134` / 308 bytes.
- Original file: `[0x11E130, 0x11E264)`.
- Return: `jr ra` at `0x21E07C`; frame restoration at `0x21E080` is its delay slot.
- Padding: `[0x21E084, 0x21E090)`, twelve bytes, excluded from function matching.

Original payload section names are blank. The mapping is segment-derived,
not proof of an original section named `.text`. Existing slice metadata spans
`0x140` bytes, including padding; that is not the function-code length.

## Nine inputs and allocation

The shared prototype in [trade_packet.h](../include/trade_packet.h) is:

```cpp
void *func_0021DF50(void *packet, int destination, int format, int pitch,
                    void *pixels, int x, int y, int width, int height);
```

The first eight inputs occupy `a0..a3,t0..t3`, in declaration order. The ninth
occupies incoming stack slot `0(sp)`. After allocating a `0xB0`-byte frame,
`lh fp,0xB0(sp)` at `0x21DF7C` consumes its signed low 16 bits. The observed
slot width and `sd` at callers do not prove the original source-level type.
The reconstructed `int height` preserves the consumed bits and argument slot.
Likewise, `void *pixels` preserves the observed palette-pointer bits; the
original typedef remains unknown.

A null packet calls `func_123908(0)` at `0x21DFA4`. A non-null packet skips
allocation. There is no allocator-result null guard in the binary. Both paths
then perform one writer call and one finalizer call.

## Divisor and wrapped arithmetic

The selector uses **signed low 16 bits** of `format`, not its low byte:

| Selector | Divisor |
| --- | --- |
| `20` | `512` |
| `19` | `256` |
| `2` | `128` |
| Anything else | `64` |

Let `w=sign16(width)` and `h=sign16(height)`. Their product fits in signed
32 bits. The numerator is the low 32 bits of `(w*h << 4) + divisor - 1`, then
interpreted as signed 32-bit. Signed division truncates toward zero.
The three-operand R5900 `mult v0,v1,v0` at `0x21E004` writes its explicit
`v0` destination. Its product feeds the shift; it is not discarded merely
because a later division updates LO.

The C++ performs the shift and addition as unsigned 32-bit operations, avoiding
signed-shift and signed-addition overflow. Conversion back to `int` uses the
verified native and MWCC two's-complement conversion behavior. The divisor is
always positive, so division by zero and `INT_MIN / -1` cannot occur.
`#pragma divbyzerocheck on` retains the original target's division trap sequence.

## Ten writer arguments and finalization

The call at `0x21E044` targets `func_1046D0`:

| Writer location | Observed value |
| --- | --- |
| `a0` | Selected packet. |
| `a1` | `destination & 0xFFFF`. |
| `a2` | `format & 0xFF`. |
| `a3` | `pitch & 0xFFFF`. |
| `t0` | Original `pixels` bits. |
| `t1` | Signed quotient. |
| `t2` | `sign16(x)`. |
| `t3` | `sign16(y)`. |
| Outgoing `0(sp)` | `sign16(width)`, stored with `sd` at `0x21DFF8`. |
| Outgoing `8(sp)` | `sign16(height)`, stored with `sd` at `0x21E000`. |

The writer consumes both stack dimensions. Its result is ignored; this call
does not establish its original return type. The shared declaration uses `void`
because the repaired helpers require no result.

At `0x21E04C`, `func_21C050` receives only the packet in `a0`. It does not
consume a meaningful retained `a1` mode. That finalizer explicitly copies the
packet into `v0` at `0x21C0B4`, after its internal finalization call. DF50
returns this packet pointer. Internal tag results are not DF50's return contract.

## Native red and green evidence

Before changing the production helper, the following command compiled the
actual C++ harness and failed all thirteen cases at `writes.size() == 1`:

```sh
python -m pytest -q --tb=short tests/test_trade_action_helper_21DF50.py
```

After implementation, the same thirteen cases pass:

```sh
python -m pytest -q -ra tests/test_trade_action_helper_21DF50.py
```

Each case verifies all ten writer arguments, exactly one write, packet identity,
allocation behavior, return value, and allocation/write/finalization order.
All calls additionally check unsigned destination/pitch masks, pointer-bit
preservation, and signed coordinate truncation.

| Format | Width | Height | Blocks | Additional purpose |
| --- | --- | --- | --- | --- |
| `0x14` | `10` | `20` | `7` | Divisor 512. |
| `0x13` | `10` | `20` | `13` | Divisor 256. |
| `2` | `10` | `20` | `25` | Divisor 128. |
| `0` | `10` | `20` | `50` | Default divisor. |
| `0` | `10` | `20` | `50` | Null input triggers allocation. |
| `0x10014` | `0x1000A` | `0x20014` | `7` | Signed low-halfword inputs. |
| `0xFF14` | `10` | `20` | `50` | Selector differs from its low byte. |
| `0` | `-20` | `10` | `-49` | Negative division truncates toward zero. |
| `0` | `32767` | `32767` | `-16382` | Positive product wraps negative. |
| `0` | `-32768` | `-32768` | `0` | Shift wraps to zero. |
| `0x14` | `-32768` | `32767` | `1024` | Negative product wraps positive. |
| `0` | `0` | `20` | `0` | Zero dimension. |
| `-1` | `10` | `20` | `50` | Negative default selector. |

Run these commands inside `docker-dev`, using the private
`aoe4-verification-final:20261018` image, with the checkout at `/workspace` and
`TZ=America/Sao_Paulo`. Tests use `-m32 -std=c++98 -fsanitize=undefined
-fno-sanitize-recover=undefined -fno-builtin`. See [testing.md](testing.md).
Negative quotient tests mock the writer; they do not execute its real repeat
loop. Legal application-level dimension ranges remain unverified.

The [dispatcher tests](trade_action_helper_21DE90.md) additionally compile both
real helpers together and check both reservation/allocation paths.

## Target comparison and remaining work

MWCC PS2 2.3.1.01 uses
`-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++`.
An isolated link resolves all calls, selects the entry by symbol `st_shndx`,
and accounts for every executable section, including private helpers.

The current complete comparison reports 308 original bytes, 304 candidate
bytes, 118 equal bytes, 186 different overlapping bytes, four missing bytes,
zero extra or private-code bytes, and zero unresolved symbols. The raw equality
is `38.311688%`; it is not an objdiff fuzzy score or a matching claim.
The fresh objdiff function score is separately `6.3896103%` fuzzy.
The original saves `fp` and loads the stack halfword before allocation; the
candidate delays that load and uses a smaller frame. Selection and arithmetic
instruction scheduling also differ. Do not conceal these differences by
comparing only an overlapping prefix.

Other callers at `0x21ACD0` and `0x21E0D0` still need separate declaration and
argument-flow repairs. Their existing native tests do not establish the real
nine-argument chain. This change does not claim those callers are corrected.
