# Trade action helper `0x21C990` subsystem

`src/trade_action_helper_21C990.cpp` reconstructs the two functions in slice
`[0x21C990, 0x21CD20)` in pure C++. `func_0021CC90` achieves **100.00% exact
byte-for-byte matching** against the original PlayStation 2 PAL binary across all
132 code bytes. `func_0021C990` achieves **77.89% matching** (148 / 190 words matching,
42 instruction differences remaining) with all 21 relocation sites aligned to the exact
target offsets. In accordance with coordinator directives, `configure.py` registration
remains **NonMatching** pending complete matching across both functions.

## Architecture and function contracts

The unit implements Graphics Synthesizer (GS) textured quad packet rasterization:

- Fallback packet allocation: if the input packet pointer is null, `func_123908(0)`
  allocates and returns a new packet object.
- Packet header setup: calls `func_104448(packet, 0, 0, 0)`.
- 128-bit tag setting: loads quadword `D_00392B40`, sets low 64 bits to
  `0x8000 | (0x10004000ULL << 32) | (v0 << 47)`, and passes it by value to
  `func_1045E8(packet, tag)` via `lq a1, 0(v0)`.
- Coordinate transformation: loads screen center `(D_00CA158C, D_00CA158E)`, computes
  base position `(0x800 - (center >> 1)) << 4`, applies depth offset `(-z) << 3`,
  and transforms 4 quad vertices with an 8-byte (4-short) stride.
- Register emission:
  - Writes sprite mode register (`0x06` or `0x07` based on `t3`) with `a1`.
  - Writes prim register `0x01` with `a3`.
  - Writes 4 interleaved pairs of UV (`0x03`: `u | v << 16`) and XYZ
    (`0x04`: `(t2 & 0xFFFF) << 32 | x | y << 16`).
- Packet finalization: invokes `func_104600(packet)`.
- Wrapper delegation: `func_0021CC90` expands bounding rectangle `[x, y, w, h]` into
  the 4 quad points `(x, y)`, `(x+w, y)`, `(x, y+h)`, `(x+w, y+h)` with an 8-byte stride
  and delegates to `func_0021C990`.

| Function | VRAM range | Code size | Description | Matching |
|---|---|---|---|---|
| `func_0021C990` | `[0x21C990, 0x21CC88)` | 760 B (`0x2F8`) | Textured quad GS packet rasterizer | **77.89%** (148/190 words) |
| `func_0021CC90` | `[0x21CC90, 0x21CD14)` | 132 B (`0x84`) | Bounding rect expansion quad wrapper | **100.00%** (132/132 bytes) |

## Binary mapping and raw evidence

The PAL `SLES-50282` ELF SHA-1 is `f478e19f2059d52899b691483ef5c7522e30e17c`.
Its file-backed `PT_LOAD` segment maps `p_offset=0x1E0` to `p_vaddr=0x100000`,
yielding `file_offset = VRAM - 0xFFE20`.

- Prior slice `trade_action_helper_21C710` ends at `0x21C990` (zero gap, zero overlap).
- `func_0021C990`: original file offset `0x11CB70`–`0x11CE68` (code size 760 B, zero pad `[0x21CC88, 0x21CC90)` 8 B).
- `func_0021CC90`: original file offset `0x11CE70`–`0x11CEF4` (code size 132 B, zero pad `[0x21CD14, 0x21CD20)` 12 B).
- Next slice `trade_action_helper_21CD20` starts at `0x21CD20` (file offset `0x11CF00`).
- Total slice: 892 B code + 20 B padding = 912 B (`0x390`).

## Relocations

The compiled relocatable object emits 22 code relocations in `.rel.text`:

- 16 call relocations (`R_MIPS_26`): 15 in `func_0021C990` (`func_123908` x1, `func_104448` x1,
  `func_1045E8` x1, `func_1046A8` x11, `func_104600` x1) and 1 in `func_0021CC90` (`func_0021C990`).
- 6 absolute data relocation records (`R_MIPS_HI16` / `R_MIPS_LO16`): three pairs for
  `D_00392B40`, `D_00CA158C`, and `D_00CA158E`.
- 0 GP accesses.
- 2 metadata relocations in `.rel.mwcats` (`R_MIPS_32`).

All decoded instruction-encoded `SHT_REL` addends are zero.

## Native tests and TDD evidence

Native regressions in `tests/test_trade_action_helper_21C990.py` and
`tests/native/trade_action_helper_21C990_test.cpp` verify:
1. `func_0021C990`: existing packet path, tag computation, 10 register writes, UV/XYZ formulas.
2. `func_0021C990`: null object allocation path, reg `0x06` sprite mode, negative depth offset `z = -5`.
3. `func_0021CC90`: rect expansion into 4 vertices with 8-byte stride and delegation.

### Red evidence
The Red baseline command executed against unchanged production source:
```sh
pytest tests/test_trade_action_helper_21C990.py tests/test_trade_action_helper_21C990_matching.py -v
```
Failed with 3 failures and 3 passes:
- Native tag failure: `Assertion g_last_tag.words[0] == exp_word0 failed` at line 104 in `trade_action_helper_21C990_test.cpp`.
- Matcher size failure: `func_0021C990 size mismatch: got 244, expected 760`.
- Matcher relocation count: `expected 21 relocs in .rel.text, got 8`.
Logged at `build/abi-21c990-red.log`.

### Current matching status
- `func_0021CC90`: **100.00% exact match** across all 132 code bytes.
- `func_0021C990`: **77.89% match** (148/190 words matching, 42 word differences remaining).
- All 3 native tests pass.
- Relocation manifest rejection and padding rejection tests pass.
- Registration kept as **NonMatching** in `configure.py`.
