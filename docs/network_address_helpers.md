# Network address helpers

This slice contains the four endian-conversion helpers, IPv4 text formatting, and IPv4 text parsing in the PAL network layer.

| Function | Verified body | Alignment padding | Relocations |
| --- | ---: | ---: | ---: |
| `0x337520` | 60 bytes | 4 zero bytes | 0 |
| `0x337560` | 28 bytes | 4 zero bytes | 0 |
| `0x337590` | 60 bytes | 4 zero bytes | 0 |
| `0x3375D0` | 28 bytes | 4 zero bytes | 0 |
| `0x337600` | 92 bytes | 4 zero bytes | 5 |
| `0x337660` | 360 bytes | 8 zero bytes | 6 |

The formatter emits four unsigned address octets separated by periods into a shared buffer. The parser checks characters through a class table, accepts periods, scans four decimal fields, rejects out-of-range octets, and assembles the result in network byte order. The parser reads an input-provided string without a length bound, matching the original behavior; callers must provide a terminated string in readable memory.

The byte-swap helpers reverse all four bytes or the low two bytes. Native byte-swap coverage is in `tests/test_network_address_helpers_native.py`. Matching coverage invokes `tests/network_match_support.py` with each body's full extent and relocation count.

Matching and complete native validation remain pending until the regression suite and target compiler comparison pass.
