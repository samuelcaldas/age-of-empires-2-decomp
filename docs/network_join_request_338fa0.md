# DirectPlay player join setup at `0x338FA0`

`func_00338FA0` spans 300 bytes (`0x338FA0`–`0x3390CB`), including the
`jr ra` delay slot. Four zero alignment bytes follow at `0x3390CC`; the next
function starts at `0x3390D0`.

## Behavior verified from the original

The routine obtains a player ID, stores it in the supplied DirectPlay state,
creates a player record, and copies 16-byte and 32-byte session strings into
that record. It derives one identity value and writes it to the first two record
fields. Host state controls announcement delivery: hosts skip the announcement.
Non-hosts increment the player count and call the announcement sender with a
local record pointer and fifth argument `100`. The fifth argument's meaning is
not established here.

The original does not parse four 112-byte records or clear player slots 4–7.
Its disassembly instead shows the single-record setup and conditional
announcement described above. The task hint does not match this address.

| State | Calls, in order | State and result |
|---|---|---|
| Host | allocate ID, create record, copy both strings, derive identity | Store ID and record; skip count increment and announcement; return `0` |
| Non-host | host-path calls, increment count, copy announcement fields, send | Store ID and record; increment count once; send with fifth argument `100`; return `0` |

## Tests and matching

- `tests/test_network_join_request_338fa0.py` builds and runs the C++ function
  with 32-bit host stubs. It checks call order, both state paths, record fields,
  string lengths, count changes, and announcement arguments.
- `tests/test_network_join_request_338fa0_matching.py` uses
  `tests/network_match_support.py`, asserts nine relocations and the 300-byte
  extent, compares all relocated bytes, and checks the four zero padding bytes.
- The best implementation remains nonmatching after 25 source-shape attempts.
  Its current mismatch is reported by the exact-match test; this is not a binary
  match claim.

## Memory-safety notes

The original copies fixed 16-byte and 32-byte ranges from the supplied session
record without validating source lengths. The stack announcement contains
bytes that the original does not initialize before sending the full 100-byte
record. These behaviors are preserved for matching and remain unsafe for
untrusted inputs.
