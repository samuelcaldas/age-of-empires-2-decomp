# Trade action helper `0x21B7B0` subsystem

`src/trade_action_helper_21B7B0.cpp` reconstructs the two functions in slice
`[0x21B7B0, 0x21B880)` in pure C++. Both functions achieve **100.00% exact
byte-for-byte matching** against the original PlayStation 2 PAL binary. In
accordance with project policy, its `configure.py` registration remains
**NonMatching** pending review.

## Architecture and function contracts

The unit implements palette slot allocation and viewport slot allocation on top of the
manager pool initialized in [trade_action_helper_21B640.md](trade_action_helper_21B640.md):

| Function | VRAM range | Code size | Description | Matching |
|---|---|---|---|---|
| `func_0021B7B0` | `[0x21B7B0, 0x21B830)` | 128 B (`0x80`) | Allocates palette slot via `func_0021B760`; uploads 256 palette entries via `func_0021B4C0` if `palette_src != 0`; stores `*out_slot = slot` | **100.00%** |
| `func_0021B830` | `[0x21B830, 0x21B874)` | 68 B (`0x44`) | Sequential viewport allocator; scans 6 viewport descriptors of size `0xA8` (168 B), claims first free (`*(int *)vp == 0`), marks it 1, and returns its pointer | **100.00%** |

## Binary mapping and raw evidence

The PAL `SLES-50282` ELF SHA-1 is `f478e19f2059d52899b691483ef5c7522e30e17c`.
Its file-backed `PT_LOAD` segment maps `p_offset=0x1E0` to `p_vaddr=0x100000`,
yielding `file_offset = VRAM - 0xFFE20`.

- Function `func_0021B7B0`: original file offset `0x11B990`–`0x11BA10`
- Function `func_0021B830`: original file offset `0x11BA10`–`0x11BA54` (zero padding `0x11BA54`–`0x11BA60`)

## Exact target comparison

The dedicated exact matching test is preserved in:
`tests/test_trade_action_helper_21B7B0_matching.py`.

It compiles `src/trade_action_helper_21B7B0.cpp` with MWCC PS2 2.3.1.01 using:
`-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++`.

It resolves call relocations:
- `func_0021B760 = 0x21B760`
- `func_0021B4C0 = 0x21B4C0`

All 196 code bytes across both functions match byte-for-byte with zero diffs.
Objdiff reports **100.0%** matching for the entire unit.

## Native tests

Native regression tests in `tests/test_trade_action_helper_21B7B0.py` and
`tests/native/trade_action_helper_21B7B0_test.cpp` verify:
1. `test_func_0021B7B0`: Allocation failure (returns 1), successful allocation with palette upload, null palette upload, and null output slot handling.
2. `test_func_0021B830`: Sequential viewport allocation, saturation return of `nullptr`, and reallocation of freed viewports.
3. `test_func_0021B830_skip_occupied`: Skips occupied viewports with arbitrary non-zero status values.
