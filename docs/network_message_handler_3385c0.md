# Received message handler at `0x3385C0`

`func_003385C0` consumes one received datagram for the DirectPlay-compatible
network layer. The original function occupies 940 bytes (`0x3385C0` through
`0x338968`, including the return delay slot). Four zero alignment bytes follow
before `0x338970`.

## Verified behavior

- A host recognizes control requests only when the three header words at offsets
  0, 8, and 12 are zero. `SESSION` sends the 216-byte session description with
  its tag; `JOINED` copies eight 112-byte player records and sends 456 bytes.
- Messages with a nonzero field at offset 4 are queued with a 16-byte header.
- System messages include player creation (3), destruction (5), and name update
  (259). Types 7, 33, 258, 260, 263, 264, and 265 are ignored. Types 49 and
  257 are queued.
- The handler returns 1 for handled/ignored messages and 0 when player lookup or
  player creation fails in the observed branches.

These contracts come from static disassembly and the host SESSION native test.
No runtime trace establishes peer identity, delivery guarantees, or timeouts.
The handler trusts message length and offsets. Hostile lengths can cause unsafe
reads or copies through the queue path; matching must preserve this original
behavior rather than add validation here.

## Tests and matching status

`tests/test_network_message_handler_3385c0_native.py` builds and runs native
SESSION-response and player-creation checks with stub callees.
`tests/test_network_message_handler_3385c0_matching.py` uses the shared
relocation-aware matcher, expects 31 relocations, checks the 940-byte function
extent, and checks four zero padding bytes.

Current candidate is nonmatching. MWCC emits 904 bytes instead of the original
940-byte extent. Across that candidate extent, 303/904 bytes match; the first
difference is at `0x3385E1`. The matching test fails at the emitted-size check.
