# Trade action helper `0x21C710` subsystem

`src/trade_action_helper_21C710.cpp` reconstructs the four functions in slice
`[0x21C710, 0x21C990)` in pure C++. All four functions achieve **100.00% exact
byte-for-byte matching** against the original PlayStation 2 PAL binary across all
632 code bytes. In accordance with coordinator directives, its `configure.py`
registration remains **NonMatching** pending formal promotion review.

## Architecture and function contracts

The unit implements Graphics Synthesizer (GS) register-write packets for display
and texture pipeline configuration:

- Fallback packet allocation: if the input packet pointer is null, `func_123908(0)`
  allocates and returns a new packet object.
- Packet header setup: invokes `func_104448(packet, 0, 0, 0)`.
- 128-bit tag setting: loads quadword `*(u128 *)D_00392B30` and passes it by
  value to `func_1045E8(packet, tag)` via `lq a1, 0(v0)`.
- Register-specific payload assembly:
  - `func_0021C710`: writes register `0x14` directly with `unsigned long a1`.
  - `func_0021C790`: writes register `0x16` directly with `unsigned long a1`.
  - `func_0021C810`: packs a 3-component bitfield for register `0x3B` using:
    `((unsigned long long)a1) | (((unsigned long long)a2) << 15) | (((unsigned long long)a3) << 32)`.
  - `func_0021C8D0`: packs a 3-component bitfield for register `0x4F` using:
    `((unsigned long long)a1) | (((unsigned long long)a2) << 24) | (((unsigned long long)a3) << 32)`.
- Packet finalization: invokes `func_104600(packet)` and returns the packet pointer.

Numeric register IDs (`0x14`, `0x16`, `0x3B`, `0x4F`) are used directly without
relying on unverified descriptive names.

| Function | VRAM range | Code size | Register | Matching |
|---|---|---|---|---|
| `func_0021C710` | `[0x21C710, 0x21C790)` | 128 B (`0x80`) | `0x14` | **100.00%** |
| `func_0021C790` | `[0x21C790, 0x21C810)` | 128 B (`0x80`) | `0x16` | **100.00%** |
| `func_0021C810` | `[0x21C810, 0x21C8CC)` | 188 B (`0xBC`) | `0x3B` | **100.00%** |
| `func_0021C8D0` | `[0x21C8D0, 0x21C98C)` | 188 B (`0xBC`) | `0x4F` | **100.00%** |

## Binary mapping and raw evidence

The PAL `SLES-50282` ELF SHA-1 is `f478e19f2059d52899b691483ef5c7522e30e17c`.
Its file-backed `PT_LOAD` segment maps `p_offset=0x1E0` to `p_vaddr=0x100000`,
yielding `file_offset = VRAM - 0xFFE20`.

- Prior slice `trade_action_helper_21C410` ends at `0x21C710` (zero gap, zero overlap).
- `func_0021C710`: original file offset `0x11C8F0`–`0x11C970` (code size 128 B, zero pad 0 B).
- `func_0021C790`: original file offset `0x11C970`–`0x11C9F0` (code size 128 B, zero pad 0 B).
- `func_0021C810`: original file offset `0x11C9F0`–`0x11CAAC` (code size 188 B, zero pad `[0x21C8CC, 0x21C8D0)` 4 B).
- `func_0021C8D0`: original file offset `0x11CAB0`–`0x11CB6C` (code size 188 B, zero pad `[0x21C98C, 0x21C990)` 4 B).
- Next slice `trade_action_helper_21C990` starts at `0x21C990` (file offset `0x11CB70`).
- Total slice: 632 B code + 8 B padding = 640 B (`0x280`).

## Relocations

The compiled relocatable object emits 28 code relocations in `.rel.text`:

- 20 call relocations (`R_MIPS_26`): `func_123908` (x4), `func_104448` (x4), `func_1045E8` (x4), `func_1046A8` (x4), `func_104600` (x4).
- 8 absolute data relocation records (`R_MIPS_HI16` / `R_MIPS_LO16`): four pairs for `D_00392B30`.
- 0 GP accesses.
- 4 `.rel.mwcats` metadata relocations (`R_MIPS_32`).

All decoded instruction-encoded `SHT_REL` addends are zero.

## Exact target comparison

The dedicated matching test is preserved in
`tests/test_trade_action_helper_21C710_matching.py`. It compiles the actual source
with MWCC PS2 2.3.1.01 using:
`-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++`.

It resolves calls to `func_123908` (`0x123908`), `func_104448` (`0x104448`),
`func_1045E8` (`0x1045E8`), `func_1046A8` (`0x1046A8`), and `func_104600` (`0x104600`),
and data references to `D_00392B30` (`0x392B30`). Each function's code bytes match
its original range exactly.

## Native tests and TDD evidence

Native regressions in `tests/test_trade_action_helper_21C710.py` and
`tests/native/trade_action_helper_21C710_test.cpp` verify:
1. `func_0021C710`: existing/null packet paths, tag value forwarding, and register `0x14` direct write.
2. `func_0021C790`: existing/null packet paths, tag value forwarding, and register `0x16` direct write.
3. `func_0021C810`: existing/null packet paths, 3-component bitfield packing, and register `0x3B` write.
4. `func_0021C8D0`: existing/null packet paths, 3-component bitfield packing, and register `0x4F` write.

### Red evidence
The Red baseline command:
```sh
pytest tests/test_trade_action_helper_21C710.py tests/test_trade_action_helper_21C710_matching.py -v
```
Failed against unchanged production source with 6 failures:
- 4 native tag assertion failures: `Assertion g_last_tag.words[0] == 0x00008000 failed` across all 4 functions.
- 1 matcher size failure: `func_0021C710 size mismatch: got 76, expected 128`.
- 1 matcher manifest failure: `expected 7 relocs in .rel.text, got 3`.
Logged at `build/abi-21c710-red.log`.

### Green evidence
After updating `src/trade_action_helper_21C710.cpp`, all 7 tests passed:
```sh
============================== 7 passed in 0.72s ===============================
```
Logged at `build/abi-21c710-green.log`.
