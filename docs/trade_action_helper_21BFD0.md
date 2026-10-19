# Trade action helper `0x21BFD0` subsystem

`src/trade_action_helper_21BFD0.cpp` reconstructs the five functions in slice
`[0x21BFD0, 0x21C410)` in pure C++. All five functions achieve **100.00% exact
byte-for-byte matching** against the original PlayStation 2 PAL binary across all
1,048 code bytes. In accordance with standing coordinator directives, its
`configure.py` registration remains **NonMatching** pending formal promotion
review.

## Architecture and function contracts

The unit implements Graphics Synthesizer (GS) packet and privileged register
dispatch routines for display control:
- Fallback packet allocation: if the input packet pointer is null, `func_123908(0)`
  allocates a packet object.
- Packet header setup: calls `func_104448(packet, 0, 0, 0)`.
- 128-bit tag setting: loads quadword `*(u128 *)D_00392B30` and passes it by
  value to `func_1045E8(packet, tag)` via `lq a1, 0(v0)`.
- Register-specific payload assembly:
  - `func_0021BFD0`: writes GS register `0x08` (`FRAME_1`/`FRAME_2`) with `val`.
  - `func_0021C050`: writes GS register `0x3F` (`TEST_1`/`TEST_2`) with `0`.
  - `func_0021C0D0`: packs 5-component bitfield for GS register `0x42` (`CLAMP_1`).
  - `func_0021C1D0`: packs 5-component bitfield for GS register `0x43` (`CLAMP_2`).
  - `func_0021C2D0`: packs 8-component bitfield for GS register `0x48` (`TEX0_1`/`TEX0_2`).
- Packet finalization: invokes `func_104600(packet)` and returns the packet pointer.

| Function | VRAM range | Code size | Description | Matching |
|---|---|---|---|---|
| `func_0021BFD0` | `[0x21BFD0, 0x21C050)` | 128 B (`0x80`) | GS register `0x08` (`FRAME`) packet dispatcher | **100.00%** |
| `func_0021C050` | `[0x21C050, 0x21C0C8)` | 120 B (`0x78`) | GS register `0x3F` (`TEST`) packet dispatcher | **100.00%** |
| `func_0021C0D0` | `[0x21C0D0, 0x21C1C4)` | 244 B (`0xF4`) | GS register `0x42` (`CLAMP_1`) bitfield dispatcher | **100.00%** |
| `func_0021C1D0` | `[0x21C1D0, 0x21C2C4)` | 244 B (`0xF4`) | GS register `0x43` (`CLAMP_2`) bitfield dispatcher | **100.00%** |
| `func_0021C2D0` | `[0x21C2D0, 0x21C408)` | 312 B (`0x138`) | GS register `0x48` (`TEX0`) bitfield dispatcher | **100.00%** |

## Binary mapping and raw evidence

The PAL `SLES-50282` ELF SHA-1 is `f478e19f2059d52899b691483ef5c7522e30e17c`.
Its file-backed `PT_LOAD` segment maps `p_offset=0x1E0` to `p_vaddr=0x100000`,
yielding `file_offset = VRAM - 0xFFE20`.

- Prior slice `trade_action_helper_21BDF0` ends at `0x21BFD0` (zero gap, zero overlap).
- `func_0021BFD0`: original file offset `0x11C1B0`–`0x11C230` (code size 128 B, zero pad 0 B).
- `func_0021C050`: original file offset `0x11C230`–`0x11C2A8` (code size 120 B, zero pad `[0x21C0C8, 0x21C0D0)` 8 B).
- `func_0021C0D0`: original file offset `0x11C2B0`–`0x11C3A4` (code size 244 B, zero pad `[0x21C1C4, 0x21C1D0)` 12 B).
- `func_0021C1D0`: original file offset `0x11C3B0`–`0x11C4A4` (code size 244 B, zero pad `[0x21C2C4, 0x21C2D0)` 12 B).
- `func_0021C2D0`: original file offset `0x11C4B0`–`0x11C5E8` (code size 312 B, zero pad `[0x21C408, 0x21C410)` 8 B).
- Next slice `trade_action_helper_21C410` starts at `0x21C410` (file offset `0x11C5F0`).
- Total slice: 1,048 B code + 40 B padding = 1,088 B (`0x440`).

## Relocations

The compiled relocatable object emits 35 `.rel.text` relocations:
- 25 call relocations (`R_MIPS_26`): `func_123908` (x5), `func_104448` (x5), `func_1045E8` (x5), `func_1046A8` (x5), `func_104600` (x5).
- 10 absolute data references (`R_MIPS_HI16` / `R_MIPS_LO16`): `%hi` and `%lo` for `D_00392B30` across all five functions.
- 0 GP accesses.

## Exact target comparison

The dedicated matching test is preserved in:
`tests/test_trade_action_helper_21BFD0_matching.py`.

It compiles `src/trade_action_helper_21BFD0.cpp` with MWCC PS2 2.3.1.01 using:
`-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++`.

It resolves call relocations to `func_123908` (`0x123908`), `func_104448` (`0x104448`),
`func_1045E8` (`0x1045E8`), `func_1046A8` (`0x1046A8`), `func_104600` (`0x104600`), and
`D_00392B30` (`0x392B30`):
- All 128 bytes of `func_0021BFD0` match 100.00% byte-for-byte with zero diffs.
- All 120 bytes of `func_0021C050` match 100.00% byte-for-byte with zero diffs.
- All 244 bytes of `func_0021C0D0` match 100.00% byte-for-byte with zero diffs.
- All 244 bytes of `func_0021C1D0` match 100.00% byte-for-byte with zero diffs.
- All 312 bytes of `func_0021C2D0` match 100.00% byte-for-byte with zero diffs.
- All 4 zero padding gaps (8 B, 12 B, 12 B, 8 B) are verified in the original ELF.

## Native tests

Native regression tests in `tests/test_trade_action_helper_21BFD0.py` and
`tests/native/trade_action_helper_21BFD0_test.cpp` verify:
1. `func_0021BFD0`: existing/null packet allocation, header initialization, 128-bit tag value forwarding, and register `0x08` write.
2. `func_0021C050`: register `0x3F` write with data `0`.
3. `func_0021C0D0`: register `0x42` 5-component bitfield pack and write.
4. `func_0021C1D0`: register `0x43` 5-component bitfield pack and write.
5. `func_0021C2D0`: register `0x48` 8-component bitfield pack and write (including stack argument `sp90`).

Durable Red evidence is recorded in `build/abi-21bfd0-red.log`.
All native and matching cases pass in green testing.
