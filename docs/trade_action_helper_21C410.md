# Trade action helper `0x21C410` subsystem

`src/trade_action_helper_21C410.cpp` reconstructs the five functions in slice
`[0x21C410, 0x21C710)` in pure C++. All five functions achieve **100.00% exact
byte-for-byte matching** against the original PlayStation 2 PAL binary across all
736 code bytes. In accordance with standing coordinator directives, its
`configure.py` registration remains **NonMatching** pending formal promotion
review.

## Architecture and function contracts

The unit implements Graphics Synthesizer (GS) texture mapping and format register
dispatch routines for display control:
- Fallback packet allocation: if the input packet pointer is null, `func_123908(0)`
  allocates a packet object.
- Packet header setup: calls `func_104448(packet, 0, 0, 0)`.
- 128-bit tag setting: loads quadword `*(u128 *)D_00392B30` and passes it by
  value to `func_1045E8(packet, tag)` via `lq a1, 0(v0)`.
- Register-specific payload assembly:
  - `func_0021C410`: writes GS register `0x4A` (`MIPTBP1_1`) with sign-extended `a1`.
  - `func_0021C4A0`: writes GS register `0x4B` (`MIPTBP2_1`) with sign-extended `a1`.
  - `func_0021C530`: packs 4-component bitfield for GS register `0x4D` (`TEXA`).
  - `func_0021C610`: writes GS register `0x48` (`TEX0_1`) directly with `a1`.
  - `func_0021C690`: writes GS register `0x41` (`TEX1_1`) directly with `a1`.
- Packet finalization: invokes `func_104600(packet)` and returns the packet pointer.

| Function | VRAM range | Code size | Description | Matching |
|---|---|---|---|---|
| `func_0021C410` | `[0x21C410, 0x21C494)` | 132 B (`0x84`) | GS register `0x4A` (`MIPTBP1`) packet dispatcher | **100.00%** |
| `func_0021C4A0` | `[0x21C4A0, 0x21C524)` | 132 B (`0x84`) | GS register `0x4B` (`MIPTBP2`) packet dispatcher | **100.00%** |
| `func_0021C530` | `[0x21C530, 0x21C608)` | 216 B (`0xD8`) | GS register `0x4D` (`TEXA`) bitfield dispatcher | **100.00%** |
| `func_0021C610` | `[0x21C610, 0x21C690)` | 128 B (`0x80`) | GS register `0x48` (`TEX0`) packet dispatcher | **100.00%** |
| `func_0021C690` | `[0x21C690, 0x21C710)` | 128 B (`0x80`) | GS register `0x41` (`TEX1`) packet dispatcher | **100.00%** |

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
- 10 absolute data references (`R_MIPS_HI16` / `R_MIPS_LO16`): `%hi` and `%lo` for `D_00392B30` across all five functions.
- 0 GP accesses.

## Exact target comparison

The dedicated matching test is preserved in:
`tests/test_trade_action_helper_21C410_matching.py`.

It compiles `src/trade_action_helper_21C410.cpp` with MWCC PS2 2.3.1.01 using:
`-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++`.

It resolves call relocations to `func_123908` (`0x123908`), `func_104448` (`0x104448`),
`func_1045E8` (`0x1045E8`), `func_1046A8` (`0x1046A8`), `func_104600` (`0x104600`), and
`D_00392B30` (`0x392B30`):
- All 132 bytes of `func_0021C410` match 100.00% byte-for-byte with zero diffs.
- All 132 bytes of `func_0021C4A0` match 100.00% byte-for-byte with zero diffs.
- All 216 bytes of `func_0021C530` match 100.00% byte-for-byte with zero diffs.
- All 128 bytes of `func_0021C610` match 100.00% byte-for-byte with zero diffs.
- All 128 bytes of `func_0021C690` match 100.00% byte-for-byte with zero diffs.
- All 3 zero padding gaps (12 B, 12 B, 8 B) are verified in the original ELF.

## Native tests

Native regression tests in `tests/test_trade_action_helper_21C410.py` and
`tests/native/trade_action_helper_21C410_test.cpp` verify:
1. `func_0021C410`: existing/null packet allocation, header initialization, 128-bit tag value forwarding, and register `0x4A` write.
2. `func_0021C4A0`: register `0x4B` write with data `a1`.
3. `func_0021C530`: register `0x4D` 4-component bitfield pack and write.
4. `func_0021C610`: register `0x48` write directly with `a1`.
5. `func_0021C690`: register `0x41` write directly with `a1`.

Durable Red evidence is recorded in `build/abi-21c410-red.log`.
All native and matching cases pass in green testing.
