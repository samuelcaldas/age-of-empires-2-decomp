# Session message dispatcher at `0x3378D0`

`func_003378D0` dispatches a 512-byte i.LINK session message. The function spans
`0x3378D0` through the return delay slot at `0x3379E0` (`0x114` bytes). Twelve
zero bytes align the next function at `0x3379F0`.

## Behavior verified from the original

| Message prefix | State and calls | Result |
|---|---|---|
| `ilhost` (6 bytes) | Set `0x4E3530` to `2`. | `0` |
| `ilconnect` (9 bytes) or `ilbroadcast` (11 bytes) | If `0x4E3530 != 1`, clear `0x4E3530` and `0x4E352C`; otherwise preserve both. | `0` |
| `JOINED` (6 bytes) or `SESSION` (7 bytes) | Copy 512 bytes from the message to `0x108AFA0`. | `1` |
| Other prefixes | Call `0x3385C0(0x1087ED0, message, *(int *)(message + 12), 0)`. | `0` |

The comparisons use `strncmp`-like routine `0x117A64`. Prefixes need not be
null-terminated within their compared lengths. The native test checks `ilhost`,
`ilconnect`, `JOINED`, and fallback delegation, including call order and the
message field passed at offset 12.

## Binary and matching evidence

The original `SLES-50282` ELF contains the strings at these exact addresses:

- `0x4D1EE8`: `ilhost`
- `0x4D1EF0`: `ilconnect`
- `0x4D1F00`: `ilbroadcast`
- `0x4D1F10`: `JOINED`
- `0x4D1F18`: `SESSION`

The body contains five `0x117A64` calls, one `0x117AF8` copy call, and one
`0x3385C0` delegation call. Its relocation manifest has 25 entries: seven
`R_MIPS_26`, five string `HI16`/`LO16` pairs and two global pairs, and four
`GPREL16` accesses using
`_gp = 0x4EA7C0`. The matching test applies every relocation and compares all
276 bytes without masks. It also verifies the five strings and 12 zero padding
bytes.

Commands:

- Red: `.venv/bin/python -m pytest -q -ra tests/test_network_session_dispatch_3378d0_native.py` failed at link because the production source did not yet exist. The repository TDD policy treats this as a blocked red, not an assertion-level behavioral failure.
- Green: `.venv/bin/python -m pytest -q -ra tests/test_network_session_dispatch_3378d0_native.py tests/test_network_session_dispatch_3378d0_matching.py` passed: 8 tests.
- Network regression: `.venv/bin/python -m pytest -q -ra tests/test_network_send_checked_337840.py tests/test_network_send_checked_337840_matching.py tests/test_network_session_dispatch_3378d0_native.py tests/test_network_session_dispatch_3378d0_matching.py` passed: 13 tests.
- Full suite: `.venv/bin/python -m pytest -q -ra` reported 4424 passed, 10 skipped, 1 failed, and 7 errors. The failure was `tests/test_tactical_ai_node_item.py::test_tactical_ai_node_item_behavior[tactical_ai_node_item ctor]`. Errors were six item-creator cases in `tests/test_item_creator.py` and `tests/test_visible_map.py::test_visible_map_lifecycle`; the 32-bit compile/link subprocesses failed. These are unrelated to this slice.

## Contract limits and open questions

This function proves local message dispatch and two integer state updates only.
It does not prove peer identity, acknowledgements, delivery ordering, duplicate
suppression, packet-loss handling, or timeout behavior. Those contracts remain
open in this slice. The fallback callee's behavior is outside this function.
