# IP address parser at `0x337660`

`func_00337660` validates a dotted-decimal address, parses four decimal
components, rejects values above 255, and packs octets in little-endian order.
The ELF extent is `0x170` bytes from `0x337660` through alignment; the next
function starts at `0x3377D0`.

## Behavior

| Input | Calls | Result |
|---|---|---|
| Four dotted decimal octets, each `0..255` | `func_11A510(input, D_004D1EA0, &octets[0..3])` | `a | (b << 8) | (c << 16) | (d << 24)` |
| Invalid character, four or more periods, fewer than four conversions, or octet above 255 | Parser only when lexical validation passes | `-1` |

The format string at `0x004D1EA0` is `%8d.%8d.%8d.%8d`. The lexical pass allows
only decimal digits and periods. A parsed octet must be less than 256. For
example, `192.168.0.255` returns `0xFF00A8C0`.

## Evidence and validation

Disassembly at `0x337684`–`0x3376E4` checks periods and the target character
classification table. The period count is limited to three at `0x3376E8`.
`0x337724` calls `0x11A510` using the format at `0x004D1EA0`; `0x33772C` requires
four conversions. The loop at `0x337750` rejects each value `>= 256`. The final
packing at `0x337784`–`0x3377A8` puts the first component in the low byte.
The return delay slot is `0x3377C4`; zero padding runs to `0x3377CC`.

- Native test: `tests/test_network_ip_format_parse_native.py` covers valid
  packing, out-of-range octets, missing components, invalid suffixes, repeated
  separators, and parser call count.
- Red attempt: `.venv/bin/python -m pytest -q -ra tests/test_network_ip_format_parse_native.py`
  failed before implementation because both source files and headers were
  absent. This was a missing-symbol/build blocker, not a behavioral red assertion.
- Green: the same command passed after implementation.
- MWCC compile succeeds. It emits `0x140` bytes, below the ELF extent `0x170`.
  Exact matching is not established. The original uses a character-class table;
  current C++ uses an ASCII range check. No byte-equality claim is made.

## Symbols needed

`func_11A510` (`0x11A510`) and `D_004D1EA0`.
