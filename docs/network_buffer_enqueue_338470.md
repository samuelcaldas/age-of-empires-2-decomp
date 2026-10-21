# Network buffer enqueue at `0x338470`

`func_00338470` appends one payload to the DirectPlay-compatible receive/send buffer. The original routine spans `0x338470`–`0x3385B7`, including the `jr ra` delay slot. Two zero words at `0x3385B8` and `0x3385BC` align the next function at `0x3385C0`. The extent is 328 bytes.

## Behavior

| Condition | State and calls | Result |
|---|---|---|
| Packet count is nonpositive | Reset count, largest size, used bytes, and previous offset; wait on semaphore | Continue |
| `used + size < 2048` | Copy payload at `buffer + used`; increment count; save old used offset; advance used by `(size + 3) & -4`; signal semaphore | Destination pointer |
| `used + size >= 2048`, stored size is at least `size` | Mark prior slot flags with `0x80000000`; clear the stored size when it equals used bytes; clear used bytes; append packet; signal | Destination pointer |
| `used + size >= 2048`, stored largest size is less than `size` | Mark prior slot flags; log `dplay:`, the size, and `cur/sav/prev`; signal semaphore without copying | Null pointer |

The state fields are at offsets `3372` (count), `3376` (stored size), `3380` (used bytes), and `3384` (previous offset). The buffer begins at offset `1324`. The semaphore load uses the word at `D_004E3560 + 4`; these are disassembly-backed offsets, while higher-level field names remain unknown.

## Evidence

The original ELF disassembly at `0x338470` establishes the state transitions, semaphore boundaries, copy order, four-byte size alignment, 2048-byte threshold, and return values. Its call sites identify `0x104D60` and `0x104D40` as WaitSema and SignalSema, `0x117AF8` as the copy routine, and `0x118DE0` as the variadic logger. The log formats resolve to `0x4D2128`, `0x4D2130`, and `0x4D2150`.

The adjacent `0x3383B0` packet builder calls this function with its composed packet and size, then passes the return value to `0x337840` (`docs/network_send_checked_337840.md`). This establishes a local buffer-to-send path, not end-to-end delivery semantics.

## Tests and matching

- `tests/test_network_buffer_enqueue_338470_native.py` runs the real C++ implementation under 32-bit host compilation. It checks append state, rounded offsets, rollover flagging, size-rejection logging, and semaphore/copy call order.
- `tests/test_network_buffer_enqueue_338470_matching.py` compiles with MWCC 2.3.1.01, resolves all 16 relocations, checks the strings and alignment boundary, and compares all 328 function bytes without masks. The compiled function has the exact 328-byte extent and matches every byte.

## Contract notes and open questions

- The routine protects its local buffer mutation with a semaphore. The evidence does not identify a session lifecycle or peer identity contract.
- It creates no network connection and performs no send itself. The neighboring packet builder sends after a nonnegative result; `0x337840` sends a fixed 492-byte datagram.
- No acknowledgment, ordering, duplicate suppression, or loss recovery is visible here. Network delivery behavior remains unknown.
- The routine uses a 2048-byte threshold and four-byte alignment. It returns null when an incoming packet would cross the threshold and exceeds the stored size value. The exact meaning of the stored size field is unknown.
- No timeout or protocol error code appears in this routine. The rejection result is null, with diagnostic logs rather than a numeric network error.
