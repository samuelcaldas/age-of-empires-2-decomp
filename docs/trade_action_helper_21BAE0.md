# Trade action helper `0x21BAE0` subsystem

`src/trade_action_helper_21BAE0.cpp` reconstructs the three functions in slice
`[0x21BAE0, 0x21BC30)` in pure C++. All three functions achieve **100.00% exact
byte-for-byte matching** against the original PlayStation 2 PAL binary (316
code bytes). In accordance with project policy, its `configure.py` registration
remains **NonMatching** pending review.

## Architecture and function contracts

The unit implements palette copy, palette update, and nearest color matching:

| Function | VRAM range | Code size | Description | Matching |
|---|---|---|---|---|
| `func_0021BAE0` | `[0x21BAE0, 0x21BB18)` | 56 B (`0x38`) | Palette copy delegation to `func_0021B440(palette_obj, 0, start_idx, count, dst_buf)` | **100.00%** |
| `func_0021BB20` | `[0x21BB20, 0x21BB5C)` | 60 B (`0x3C`) | Palette set delegation to `func_0021B4C0(palette_obj, 0, start_idx, count, src_buf, 0xFF)` | **100.00%** |
| `func_0021BB60` | `[0x21BB60, 0x21BC28)` | 200 B (`0xC8`) | Nearest palette color search using 3D Euclidean distance squared minimization (`dr*dr + dg*dg + db*db`) | **100.00%** |

## Binary mapping and raw evidence

The PAL `SLES-50282` ELF SHA-1 is `f478e19f2059d52899b691483ef5c7522e30e17c`.
Its file-backed `PT_LOAD` segment maps `p_offset=0x1E0` to `p_vaddr=0x100000`,
yielding `file_offset = VRAM - 0xFFE20`.

- Prior slice `trade_action_helper_21B880` ends at `0x21BAE0` (zero gap, zero overlap).
- `func_0021BAE0`: original file offset `0x11BCC0`–`0x11BCF8` (code size `0x38`), zero padding `[0x21BB18, 0x21BB20)` (8 B).
- `func_0021BB20`: original file offset `0x11BD00`–`0x11BD3C` (code size `0x3C`), zero padding `[0x21BB5C, 0x21BB60)` (4 B).
- `func_0021BB60`: original file offset `0x11BD40`–`0x11BE08` (code size `0xC8`), zero padding `[0x21BC28, 0x21BC30)` (8 B).
- Next slice `trade_action_helper_21BC30` begins at `0x21BC30` (file offset `0x11BE10`).

## Relocations

The slice contains three external call relocations:
- `0x21BAFC`: `jal func_0021B440` (`R_MIPS_26`, target `0x21B440`).
- `0x21BB40`: `jal func_0021B4C0` (`R_MIPS_26`, target `0x21B4C0`).
- `0x21BB9C`: `jal func_0021B440` (`R_MIPS_26`, target `0x21B440`).
All three callees are matched in `trade_action_helper_21B440`. No data relocations exist.

## Exact target comparison

The dedicated matching test is preserved in:
`tests/test_trade_action_helper_21BAE0_matching.py`.

It compiles `src/trade_action_helper_21BAE0.cpp` with MWCC PS2 2.3.1.01 using:
`-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++`.

It resolves call relocations to `func_0021B440` and `func_0021B4C0`.
- All 56 bytes of `func_0021BAE0` match 100.00% byte-for-byte.
- All 60 bytes of `func_0021BB20` match 100.00% byte-for-byte.
- All 200 bytes of `func_0021BB60` match 100.00% byte-for-byte.
Total: all 316 code bytes match byte-for-byte with zero diffs. Objdiff reports **100.0%** matching for the entire unit.

## Native tests

Native regression tests in `tests/test_trade_action_helper_21BAE0.py` and
`tests/native/trade_action_helper_21BAE0_test.cpp` verify:
1. `test_func_0021BAE0`: Palette copy delegation and return count.
2. `test_func_0021BB20`: Palette set delegation with alpha `0xFF`.
3. `test_func_0021BB60`: Nearest color matching, boundary indices (0, 255), and tie-breaking behavior.
4. `test_func_0021BB60_alpha_mask`: Ignores high alpha byte in target color (RGB distance only).
