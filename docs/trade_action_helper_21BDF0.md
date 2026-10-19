# Trade action helper `0x21BDF0` subsystem

`src/trade_action_helper_21BDF0.cpp` reconstructs the two functions in slice
`[0x21BDF0, 0x21BFD0)` in pure C++. Both functions achieve **100.00% exact
byte-for-byte matching** against the original PlayStation 2 PAL binary across all
468 code bytes (448 bytes for `func_0021BDF0` and 20 bytes for `func_0021BFB0`).
In accordance with standing repository instructions and coordinator policy, its
`configure.py` registration remains **NonMatching** pending formal promotion
review.

## Architecture and function contracts

The unit initializes global engine and display configurations (`D_00C5E300`),
instantiates the primary graphics/display manager object via `func_100850` (size `0x1948`),
initializes it via `func_2F61F0`, stores the object pointer in `D_004E32E4`, and
resets stream channels via `func_00219F60`. The successor function `func_0021BFB0`
dispatches virtual method slot 1 (`func1`, offset `+4`) on `D_004E32E4`.

| Function | VRAM range | Code size | Description | Matching |
|---|---|---|---|---|
| `func_0021BDF0` | `[0x21BDF0, 0x21BFB0)` | 448 B (`0x1C0`) | Engine/display setup and primary manager allocator | **100.00%** |
| `func_0021BFB0` | `[0x21BFB0, 0x21BFC4)` | 20 B (`0x14`) | Primary manager virtual method 1 tail dispatch | **100.00%** |

## Binary mapping and raw evidence

The PAL `SLES-50282` ELF SHA-1 is `f478e19f2059d52899b691483ef5c7522e30e17c`.
Its file-backed `PT_LOAD` segment maps `p_offset=0x1E0` to `p_vaddr=0x100000`,
yielding `file_offset = VRAM - 0xFFE20`.

- Prior slice `trade_action_helper_21BC30` ends at `0x21BDF0` (zero gap, zero overlap).
- `func_0021BDF0`: original file offset `0x11BFD0`–`0x11C190` (code size `0x1C0`, zero padding 0 B).
- `func_0021BFB0`: original file offset `0x11C190`–`0x11C1A4` (code size `0x14`), zero padding `[0x21BFC4, 0x21BFD0)` (12 B).
- Next slice starts at `0x21BFD0` (file offset `0x11C1B0`).

## Relocations

The compiled relocatable object emits:
- `func_0021BDF0`: 89 `.rel.text` relocations:
  - 5 `R_MIPS_26` call relocations (`strcpy` x2 at `0x18` and `0x2C`, `func_100850` at `0x184`, `func_2F61F0` at `0x1A0`, `func_00219F60` at `0x1A8`).
  - %hi/%lo pairs (`R_MIPS_HI16` / `R_MIPS_LO16`) for absolute buffers `D_00C5E300`, `D_492C70` (`"palette"`), and `D_492C78` (`"mcursors"`).
  - 1 `R_MIPS_GPREL16` literal float reference `@11` (`0.05f`) in `.lit4` at `0x40`.
  - 1 `R_MIPS_GPREL16` global pointer reference to `D_004E32E4` at `0x1AC`.
- `func_0021BFB0`: 1 `R_MIPS_GPREL16` global pointer reference to `D_004E32E4` at `0x0`.

## Exact target comparison

The dedicated matching test is preserved in:
`tests/test_trade_action_helper_21BDF0_matching.py`.

It compiles `src/trade_action_helper_21BDF0.cpp` with MWCC PS2 2.3.1.01 using:
`-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++`.

It resolves call relocations to `strcpy` (`0x11ABBC`), `func_100850` (`0x100850`),
`func_2F61F0` (`0x2F61F0`), `func_00219F60` (`0x219F60`), GP-relative `D_004E32E4` (`0x4E32E4`),
`D_00C5E300` (`0xC5E300`), `D_492C70` (`0x492C70`), `D_492C78` (`0x492C78`), and `.lit4` (`0x4E2804`):
- All 448 bytes of `func_0021BDF0` match 100.00% byte-for-byte with zero diffs.
- All 20 bytes of `func_0021BFB0` match 100.00% byte-for-byte with zero diffs.
- The 12 zero padding bytes after `func_0021BFB0` `[0x21BFC4, 0x21BFD0)` are verified in the original ELF.

## Native tests

Native regression tests in `tests/test_trade_action_helper_21BDF0.py` and
`tests/native/trade_action_helper_21BDF0_test.cpp` verify:
1. `test_func_0021BDF0_success`:
   - Allocation size is `0x1948`.
   - Constructor `func_2F61F0` receives allocated object, configuration `D_00C5E300`, and flag `1`.
   - `func_00219F60` is invoked.
   - `D_004E32E4` is published before stream reset.
   - Configuration fields are properly initialized (`palette`, `mcursors`, display parameters, 640x448 resolution settings).
   - Virtual method dispatch via `func_0021BFB0` targets vtable slot 1 (`func1`).
2. `test_func_0021BDF0_alloc_failure`:
   - Allocation failure skips constructor.
   - Stream reset `func_00219F60` is still executed.
   - `D_004E32E4` is set to null.

Durable Red evidence is recorded in `build/abi-21bdf0-red.log`.
All native and matching cases pass in green testing.
