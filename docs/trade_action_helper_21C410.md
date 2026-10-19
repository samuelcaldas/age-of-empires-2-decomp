# Trade action helper `0x21C410` subsystem

`src/trade_action_helper_21C410.cpp` reconstructs the five functions in slice
`[0x21C410, 0x21C710)` in pure C++. All five functions achieve **100.00% exact
byte-for-byte matching** against the original PlayStation 2 PAL binary across all
736 code bytes. The unit is registered as **Matching** in `configure.py` following
independent relocation-resolved review.

## Architecture and function contracts

The unit builds Graphics Synthesizer (GS) register-write packets:

- Fallback packet allocation: if the input packet pointer is null, `func_123908(0)`
  supplies the packet object.
- Packet header setup: calls `func_104448(packet, 0, 0, 0)`.
- 128-bit tag setting: loads quadword `*(u128 *)D_00392B30` and passes it by
  value to `func_1045E8(packet, tag)` via `lq a1, 0(v0)`.
- Register-specific payload assembly:
  - `func_0021C410`: writes register `0x4A` with zero-extended 32-bit `a1`.
  - `func_0021C4A0`: writes register `0x4B` with zero-extended 32-bit `a1`.
  - `func_0021C530`: packs four zero-extended 32-bit components for register `0x4D`,
    using shifts of 0, 16, 24, and 32 bits before combining them with bitwise OR.
  - `func_0021C610`: writes register `0x48` with the incoming `unsigned long` value.
  - `func_0021C690`: writes register `0x41` with the incoming `unsigned long` value.
- Packet finalization: invokes `func_104600(packet)` and returns the packet pointer.

The conversion sequences in `func_0021C410` and `func_0021C4A0` use `DSRL32`
(function code `0x3E`), a logical right shift. They do not sign-extend negative
32-bit inputs. Numeric GS register identifiers are preserved here without the
previously incorrect descriptive names.

| Function | VRAM range | Code size | Register | Matching |
|---|---|---|---|---|
| `func_0021C410` | `[0x21C410, 0x21C494)` | 132 B (`0x84`) | `0x4A` | **100.00%** |
| `func_0021C4A0` | `[0x21C4A0, 0x21C524)` | 132 B (`0x84`) | `0x4B` | **100.00%** |
| `func_0021C530` | `[0x21C530, 0x21C608)` | 216 B (`0xD8`) | `0x4D` | **100.00%** |
| `func_0021C610` | `[0x21C610, 0x21C690)` | 128 B (`0x80`) | `0x48` | **100.00%** |
| `func_0021C690` | `[0x21C690, 0x21C710)` | 128 B (`0x80`) | `0x41` | **100.00%** |

## Binary mapping and raw evidence

The PAL `SLES-50282` ELF SHA-1 is `f478e19f2059d52899b691483ef5c7522e30e17c`.
Its file-backed `PT_LOAD` segment maps `p_offset=0x1E0` to `p_vaddr=0x100000`,
yielding `file_offset = VRAM - 0xFFE20`.

- Prior slice `trade_action_helper_21BFD0` ends at `0x21C410` (zero gap, zero overlap).
- `func_0021C410`: original file offset `0x11C5F0`–`0x11C674` (code size 132 B, zero pad `[0x21C494, 0x21C4A0)` 12 B).
- `func_0021C4A0`: original file offset `0x11C680`–`0x11C704` (code size 132 B, zero pad `[0x21C524, 0x21C530)` 12 B).
- `func_0021C530`: original file offset `0x11C710`–`0x11C7E8` (code size 216 B, zero pad `[0x21C608, 0x21C610)` 8 B).
- `func_0021C610`: original file offset `0x11C7F0`–`0x11C870` (code size 128 B, zero pad 0 B).
- `func_0021C690`: original file offset `0x11C870`–`0x11C8F0` (code size 128 B, zero pad 0 B).
- Next slice `trade_action_helper_21C710` starts at `0x21C710` (file offset `0x11C8F0`).
- Total slice: 736 B code + 32 B padding = 768 B (`0x300`).

## Relocations

The compiled relocatable object emits 35 `.rel.text` relocations:

- 25 call relocations (`R_MIPS_26`): `func_123908` (x5), `func_104448` (x5), `func_1045E8` (x5), `func_1046A8` (x5), `func_104600` (x5).
- 10 absolute data relocation records (`R_MIPS_HI16` / `R_MIPS_LO16`): five pairs for `D_00392B30`.
- 0 GP accesses.

These records belong to the compiled `ET_REL` object, not the original `ET_EXEC`
ELF. The test's manifest records zero in its addend field; it does not decode
instruction-encoded `SHT_REL` addends. The separate linked-byte comparison resolves
call and data relocations before comparing the resulting instructions.

## Exact target comparison

The dedicated matching test is preserved in
`tests/test_trade_action_helper_21C410_matching.py`. It compiles the actual source
with MWCC PS2 2.3.1.01 using:
`-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++`.

It resolves calls to `func_123908` (`0x123908`), `func_104448` (`0x104448`),
`func_1045E8` (`0x1045E8`), `func_1046A8` (`0x1046A8`), and `func_104600` (`0x104600`),
and data references to `D_00392B30` (`0x392B30`). Each function's code bytes match
its original range exactly. The test also checks the executable-section inventory,
undefined symbols, the relocation manifest, and the three original zero-padding
gaps.

The matcher allows each compiled symbol's size to equal the expected code size
or that size plus 12 bytes. Its byte comparison covers only the expected code
prefix. Padding checks read the original ELF, not emitted candidate padding.
Consequently, these checks do not establish strict candidate symbol extents or a
complete candidate code-and-padding image. Exact code-byte matching and those
additional extent/padding guarantees are different claims.

## Native tests

Native regressions in `tests/test_trade_action_helper_21C410.py` and
`tests/native/trade_action_helper_21C410_test.cpp` execute the actual C++ source:

1. `func_0021C410`: existing/null packet paths, zero header arguments, four tag
   words, register `0x4A`, and zero-extension of high-bit input `0x80001234`.
2. `func_0021C4A0`: existing packet, header/tag values, register `0x4B`, and
   zero-extension of high-bit input `0xFFEEDDCC`.
3. `func_0021C530`: existing/null packet paths and four-component packing for
   register `0x4D` with the positive inputs `0x12`, `0x34`, `0x56`, and `0x78`.
4. `func_0021C610`: existing packet and register `0x48` payload `0x99`.
5. `func_0021C690`: existing packet and register `0x41` payload `0x42`.
6. An additional existing-packet `func_0021C410` call-order assertion.

All five existing-packet cases assert header, tag, write, and close order.
Allocation-before-header order is checked for `func_0021C410` and `func_0021C530`;
there is no null-path test for every entry function. Native `g++ -m32` uses a
16-byte aggregate fallback for the tag and a 32-bit `unsigned long`. It does not
reproduce MWCC's quadword argument ABI or 64-bit `unsigned long`; target matching
provides separate compiler-specific evidence.

## Rejection-test scope and caveats

The tests named mutation rejection have narrower scope than compiled-object or
runtime mutation testing:

- Relocation checks compile an unchanged valid object, then alter the **expected
  manifest** passed to `verify_relocation_manifest`. Offset, symbol, and type
  mismatches raise assertions. No relocation record in the object is mutated.
- Padding checks alter a copy of the **original ELF bytes**, or the expected gap
  interval, before calling `verify_padding_gaps`. They do not mutate or compare
  emitted candidate padding.
- The additional native case executes unchanged `func_0021C410`, then compares its
  recorded trace with the correct order and four constant alternatives. It does
  not compile or execute reordered production code or exercise every permutation.

These are verifier-input rejection checks and ordinary call-order assertions,
not evidence that compiled-object or runtime mutants were executed and rejected.
The independently confirmed exact code-byte comparison does not depend on them.
The added call-order and rejection checks also do not establish Red-before-source
chronology for the earlier production change.

The original behavioral Red run failed the tag-word assertion against unchanged
production. Its local log is `build/abi-21c410-red.log`; `build/` is ignored, so that
log is not committed evidence. Current gate commands and results must be reported
separately from that historical Red run.
