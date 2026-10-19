# Trade action helper `0x21BC30` subsystem

`src/trade_action_helper_21BC30.cpp` reconstructs the three functions in slice
`[0x21BC30, 0x21BDF0)` in pure C++. Two functions achieve **100.00% exact
byte-for-byte matching** against the original PlayStation 2 PAL binary, and the
third achieves **78.13% matching** (unit total 79.16% fuzzy match across 424
code bytes). In accordance with project policy, its `configure.py` registration
remains **NonMatching** pending complete matching of all functions.

## Architecture and function contracts

The unit implements a 2048-byte sector DRS/archive streamer with 1 MB staging buffer `D_01E98000`:

| Function | VRAM range | Code size | Description | Matching |
|---|---|---|---|---|
| `func_0021BC30` | `[0x21BC30, 0x21BDC4)` | 404 B (`0x194`) | Sector DRS/archive loader; reads disc sectors in chunks via `func_12C388` and copies staged data via `func_117AF8` | **78.13%** |
| `func_0021BDD0` | `[0x21BDD0, 0x21BDDC)` | 12 B (`0xC`) | Version/capacity constant getter; returns `0x175E9` (95,721) | **100.00%** |
| `func_0021BDE0` | `[0x21BDE0, 0x21BDE8)` | 8 B (`0x8`) | Debug bypass flag setter; stores `$a0` to `D_004E32E0` (`-0x74E0($gp)`) | **100.00%** |

## Binary mapping and raw evidence

The PAL `SLES-50282` ELF SHA-1 is `f478e19f2059d52899b691483ef5c7522e30e17c`.
Its file-backed `PT_LOAD` segment maps `p_offset=0x1E0` to `p_vaddr=0x100000`,
yielding `file_offset = VRAM - 0xFFE20`.

- Prior slice `trade_action_helper_21BAE0` ends at `0x21BC30` (zero gap, zero overlap).
- `func_0021BC30`: original file offset `0x11BE10`–`0x11BFA4` (code size `0x194`), zero padding `[0x21BDC4, 0x21BDD0)` (12 B).
- `func_0021BDD0`: original file offset `0x11BFB0`–`0x11BFBC` (code size `0xC`), zero padding `[0x21BDDC, 0x21BDE0)` (4 B).
- `func_0021BDE0`: original file offset `0x11BFC0`–`0x11BFC8` (code size `0x8`), zero padding `[0x21BDE8, 0x21BDF0)` (8 B).
- Next slice `trade_action_helper_21BDF0` begins at `0x21BDF0` (file offset `0x11BFD0`).

## Relocations

The slice contains:
- `0x21BD28`: `jal func_12C388` (`R_MIPS_26`, target `0x12C388`).
- `0x21BD70`: `jal func_117AF8` (`R_MIPS_26`, target `0x117AF8`).
- `0x21BD08` and `0x21BDE4`: GP-relative accesses to `D_004E32E0` (`R_MIPS_GPREL16`, `-0x74E0($gp)`).

## Exact target comparison

The dedicated matching test is preserved in:
`tests/test_trade_action_helper_21BC30_matching.py`.

It compiles `src/trade_action_helper_21BC30.cpp` with MWCC PS2 2.3.1.01 using:
`-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++`.

It resolves call relocations to `func_12C388`, `func_117AF8`, and GP-relative `D_004E32E0`:
- All 12 bytes of `func_0021BDD0` match 100.00% byte-for-byte with zero diffs directly.
- All 8 bytes of `func_0021BDE0` match 100.00% byte-for-byte with GP-relative relocation resolved.
- `func_0021BC30` compiles to 396 bytes (8 bytes / 2 instructions shorter than the 404-byte original).
  Objdiff sequence alignment reports **78.11% match** (direct unaligned word overlap is 11 words / 44 bytes).
- Padding boundaries are verified in the original ELF: 12 zero padding bytes after BC30, 4 zero padding bytes after BDD0, and 8 zero padding bytes after BDE0.

## Native tests

Native regression tests in `tests/test_trade_action_helper_21BC30.py` and
`tests/native/trade_action_helper_21BC30_test.cpp` verify:
1. `test_helpers`: Getter `func_0021BDD0` returns `0x175E9` and setter `func_0021BDE0` updates `D_004E32E0`.
2. `test_func_0021BC30_direct`: Direct read mode without staging (verifies all 4096 bytes).
3. `test_func_0021BC30_staging`: Staging mode with intra-sector offset (verifies all 500 payload bytes).
4. `test_func_0021BC30_skip_when_debug_flag`: Debug bypass flag skips hardware disc reads.
5. `test_func_0021BC30_count_zero_and_offset`: Default size loading from stream info and multi-sector offset calculation (verifies all 8192 bytes).
6. `test_func_0021BC30_just_over_sector`: Just-over sector size (2049 B) forces staging and verifies all 2049 bytes.
7. `test_func_0021BC30_exact_sector_with_offset`: Exact sector size with unaligned offset (2048 B + 512 B offset) verifies all 2048 bytes.
8. `test_func_0021BC30_multi_chunk_1mb`: Multi-chunk request crossing 1 MiB staging boundary (1.25 MiB across 2 chunks) verifies chunk sequencing and all 1,310,720 bytes.

Durable Red evidence for the 1 MiB multi-chunk boundary condition is recorded in `build/abi-21bc30-red.log`.
All 8 native cases pass in green testing.
