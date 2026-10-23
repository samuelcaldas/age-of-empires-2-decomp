# Network address helpers

This slice contains the four endian-conversion helpers, IPv4 text formatting, and IPv4 text parsing in the PAL network layer.

| Function | Verified body | Alignment padding | Relocations | Status |
| --- | ---: | ---: | ---: | ---: |
| `0x337520` | 60 bytes | 4 zero bytes | 0 | **100.0% MATCH** |
| `0x337560` | 36 bytes | 12 zero bytes | 0 | **100.0% MATCH** |
| `0x337590` | 60 bytes | 4 zero bytes | 0 | **100.0% MATCH** |
| `0x3375D0` | 36 bytes | 12 zero bytes | 0 | **100.0% MATCH** |
| `0x337600` | 92 bytes | 4 zero bytes | 7 | **100.0% MATCH** |
| `0x337660` | 360 bytes | 8 zero bytes | 5 | **100.0% MATCH** |

The formatter emits four unsigned address octets separated by periods into a shared buffer. The parser checks characters through a class table, accepts periods, scans four decimal fields, rejects out-of-range octets, and assembles the result in network byte order. The parser reads an input-provided string without a length bound, matching the original behavior; callers must provide a terminated string in readable memory.

The byte-swap helpers reverse all four bytes or the low two bytes. Native byte-swap coverage is in `tests/test_network_address_helpers_native.py`. Matching coverage invokes `tests/network_match_support.py` with each body's full extent and relocation count.

All six units are registered as `Matching` in `configure.py` and sliced into individual code segments in `config/SLES-50282/config.yml`. Both native functional tests (`pytest tests/test_network_address_helpers_native.py`) and exact byte-matching verification (`pytest tests/test_network_address_helpers_matching.py` and `tests/test_network_registered_exact.py`) pass 100%.
