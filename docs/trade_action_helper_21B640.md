# Trade action helper `0x21B640` subsystem

`src/trade_action_helper_21B640.cpp` reconstructs the four functions in slice
`[0x21B640, 0x21B7B0)` in pure C++. All four functions achieve **100.00% exact
byte-for-byte matching** against the original PlayStation 2 PAL binary. In
accordance with project policy, its `configure.py` registration remains
**NonMatching** pending review.

## Architecture and function contracts

The unit implements a 6-slot viewport/palette allocation pool of total size `0x420` (1056 bytes):
- Base array at offset `0x000`: 6 elements of size `0xA8` (168 bytes), total `0x3F0` (1008 bytes).
- Slot array at offset `0x3F0`: 6 slot descriptors of size 8 bytes, total `0x30` (48 bytes).
- Global manager instance: `D_00C5C2D0` in `.bss` (size `0x420`).

| Function | VRAM range | Code size | Description | Matching |
|---|---|---|---|---|
| `func_0021B640` | `[0x21B640, 0x21B6A0)` | 96 B (`0x60`) | Pool constructor; initializes 6 main elements via `func_1003B0`, 6 slots via `func_1003B0`, and resets both arrays | **100.00%** |
| `func_0021B6A0` | `[0x21B6A0, 0x21B724)` | 132 B (`0x84`) | Reset helper; loops 6 times resetting slots via `func_0021B420`, then 6 times resetting viewports via `func_0021A550` | **100.00%** |
| `func_0021B730` | `[0x21B730, 0x21B760)` | 48 B (`0x30`) | Global manager setup; assigns `*out_ptr = &D_00C5C2D0`, resets it, and returns 0 | **100.00%** |
| `func_0021B760` | `[0x21B760, 0x21B7A4)` | 68 B (`0x44`) | Sequential slot allocator; scans 6 slot halfwords, claims first free (`0`), marks it 1, and returns its pointer | **100.00%** |

## Binary mapping and raw evidence

The PAL `SLES-50282` ELF SHA-1 is `f478e19f2059d52899b691483ef5c7522e30e17c`.
Its file-backed `PT_LOAD` segment maps `p_offset=0x1E0` to `p_vaddr=0x100000`,
yielding `file_offset = VRAM - 0xFFE20`.

- Function `func_0021B640`: original file offset `0x11B820`–`0x11B880`
- Function `func_0021B6A0`: original file offset `0x11B880`–`0x11B904` (zero padding `0x11B904`–`0x11B910`)
- Function `func_0021B730`: original file offset `0x11B910`–`0x11B940`
- Function `func_0021B760`: original file offset `0x11B940`–`0x11B984` (zero padding `0x11B984`–`0x11B990`)

## Exact target comparison

The dedicated exact matching test is preserved in:
`tests/test_trade_action_helper_21B640_matching.py`.

It compiles `src/trade_action_helper_21B640.cpp` with MWCC PS2 2.3.1.01 using:
`-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++`.

It resolves call and data relocations:
- `func_0021A520 = 0x21A520`
- `func_1003B0 = 0x1003B0`
- `func_0021B3E0 = 0x21B3E0`
- `func_0021B420 = 0x21B420`
- `func_0021A550 = 0x21A550`
- `D_00C5C2D0 = 0xC5C2D0`

All 344 code bytes across all four functions match byte-for-byte with zero diffs.
Objdiff reports **100.0%** matching for the entire unit.

## Native tests

Native regression tests in `tests/test_trade_action_helper_21B640.py` and
`tests/native/trade_action_helper_21B640_test.cpp` verify:
1. `test_case_constructor_and_reset`: Constructor call counts and global manager pointer resolution.
2. `test_case_alloc_slot`: Sequential slot allocation, saturation return of `nullptr`.
3. `test_case_skip_occupied_slot`: Skips non-zero slots and handles unsigned status values.
