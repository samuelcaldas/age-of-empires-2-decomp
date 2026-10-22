# PS2 network-layer contract and evidence

This document records the PAL network slice reviewed on 2026-10-21. Findings come
from static analysis of the original PAL image and native C++ tests. No live PS2
session, packet capture, or runtime trace was available. It is a partial contract,
not a completed multiplayer implementation.

## Evidence levels

- **Proven** means instructions, bytes, or tests directly establish the behavior.
- **Likely** means code paths support the behavior, but one condition remains open.
- **Unproven** means the available evidence does not settle the question.

## Transport framing

- **Proven:** The transport uses datagram sockets for receive, transmit, and
  broadcast. The broadcast endpoint targets all hosts.
- **Proven:** The low-level send wrapper always submits one fixed 492-byte frame.
  It accepts a caller size only as a gate; the wrapper rejects values above 492.
  Receive processing accepts only frames of exactly 492 bytes and ignores other
  lengths.
- **Proven:** A network message has a 16-byte header. The packet builder permits
  at most 476 logical payload bytes before the transport limit rejects it.
- **Important framing distinction:** Session information contains an 8-byte tag
  and a 216-byte description, or 224 logical bytes. A join reply contains an
  8-byte tag and four 112-byte player records, or 456 logical bytes. Both are
  carried in the fixed 492-byte frame. The remaining frame bytes are not proven
  to be zero padding.
- **Proven:** The original send buffer can hold 1024 bytes. The send path reuses
  that buffer, and the low-level wrapper transmits the whole fixed frame. Bytes
  beyond the current logical message may therefore be stale buffer contents.
  Host implementations must not transmit uninitialized or stale memory.
- **Proven:** The higher-level builder accepts lengths whose header-plus-payload
  size fits its buffer. A payload above the transport limit fails at the send
  wrapper. A very large payload above the builder's own limit can return without
  sending. Callers must validate lengths before queueing or sending.

## Sessions, peers, and player capacity

- **Proven:** Discovery ignores incomplete frames and the configured local peer.
  It records a new peer address and attempts a connection. The receiver updates
  connection state after a successful connection; failed connections clear the
  stored peer words.
- **Proven:** The runtime player table has eight entries. Send-to-all iterates
  those entries and skips the local player.
- **Proven:** The join reply serializes only four player records. The client
  initializes those four records and clears the remaining four slots.
- **Unproven:** The runtime table and user interface suggest eight players, but
  the four-record join handshake does not establish an effective end-to-end
  maximum. Do not treat eight as a proven multiplayer capacity.
- **Likely:** The host returns a session description on a session-information
  request and player records on a join request. Exact protocol meaning of every
  discovery and lifecycle message remains incomplete.
- **Unproven:** Host election, migration, complete leave behavior, and all peer
  identity rules are not fully traced.

## Message queues and memory safety

- **Proven:** The receiver dispatches a complete frame synchronously before it
  advances its 16-slot ring. That ring is scratch storage, not the consumer's
  durable receive queue.
- **Proven:** Each network object has a 2048-byte message queue. Messages use a
  16-byte header and four-byte-aligned storage. When the queue cannot accept a
  message, the enqueue path logs and drops it without notifying the remote peer.
- **Proven:** The original dispatcher copies 512 bytes from a 492-byte ring slot.
  This reads 20 bytes past that slot. The original queue path also trusts a length
  read from the frame and can copy beyond its input. These are original-binary
  memory-safety risks, not requirements for new host code.
- **Requirement for host ingress:** Validate sender, recipient, and length before
  writing to a guest queue. Never reproduce the 20-byte over-read. Never forward
  stale host memory. Do not assume zero-padding is safe until framing and checksum
  coverage are established.

## Reliable game messages

- **Proven:** Reliable game messages use serial numbers. The sender assigns a
  shared session sequence before fan-out and tracks acknowledgement state per
  recipient. It keeps pending messages for retransmission.
- **Proven:** An expected serial advances that sender's expected counter and is
  dispatched. An older serial is acknowledged and returns without dispatch.
  A future serial is stored in a pending table, acknowledged, and causes a request
  for the missing serial. The receive pump later dispatches a stored message only
  when it becomes the sender's next expected serial.
- **Important limitation:** The receiver ignores the pending-store result, then
  acknowledges the message. If storage fails, the sender may believe a message
  was accepted although its payload was not retained. Therefore this mechanism is
  not an unconditional delivery guarantee.
- **Proven:** Acknowledgements clear the matching recipient's pending count.
  A fully acknowledged table entry can be released. Retransmission requests use
  the requested serial and retransmit a retained matching message.
- **Unproven:** Wraparound, table-exhaustion recovery, duplicate pending entries,
  concurrent send behavior, and delivery under real packet loss have not been
  tested dynamically. The allocator can report a full table, and one observed
  caller does not check that result.

## Checksums and timeouts

- **Unproven:** The transport header includes a byte-sum of the logical payload.
  No verification of that sum was found in the receive chain examined. This does
  not prove that no other layer checks it.
- **Proven:** A separate game-level synchronization message carries 36 logical
  bytes. The receiver compares eight words, or 32 bytes, and ignores the final
  word. A mismatch emits diagnostics and updates local state. The decoder ignores
  the comparator's return value.
- **Unproven:** The downstream effect of the mismatch event is not traced. No
  evidence here supports claims that it stops the game, drops a player, or
  resynchronizes the session.
- **Proven:** Session and join paths wait using a hardware timer and a threshold
  expressed in timer units. The binary does not express that threshold in
  milliseconds. No conversion to real time is claimed.

## Error and failure behavior

- **Proven:** Transport send rejects oversized frames and reports short-send
  failure through the wrapper's error path. Socket initialization logs bind,
  connect, and thread-creation failures; several initialization stages continue
  after resource errors.
- **Proven:** The session/join paths have a timeout failure, and queue exhaustion
  returns failure after logging.
- **Unproven:** Numeric API-style results are not mapped here to public header
  names. Error meanings beyond the observed branches require more evidence.

## Matching status

The isolated PAL branch registers eight exact C++ functions: the state reset loop,
two state accessors, the send wrapper, session-message dispatcher, queue enqueue,
transport initializer, and receiver thread. Strict byte tests resolve every
candidate relocation and compare every executable byte without masks. The PAL
initializer matches 920 bytes with 107 candidate relocations. The receiver
matches 524 executable bytes with 54 candidate relocations, followed by a
separately checked four-byte alignment word. The original stripped ELF has no
relocation manifest; candidate relocation counts are not presented as original
relocation counts.

The receiver, initializer, and registered-function object builds pass in the
isolated worktree. The network-only suite passes 70 tests. The paired full-suite
runs remain red:

| Worktree | Passed | Failed | Skipped | Errors |
|---|---:|---:|---:|---:|
| Clean main baseline, with nine verifier objects prepared | 4,355 | 36 | 31 | 7 |
| Network branch after receiver registration | 4,447 | 35 | 10 | 7 |

The runs share all failure and error identifiers. The baseline has one additional
unrelated tactical-AI compilation failure. The network branch adds tests, so the
skip counts differ. Full regression is not green.

Unmatched session replies, join lifecycle, and other control handlers remain
outside the exact-match set. NTSC-J is unverified because its original image is
unavailable. The overall network-layer gate remains blocked.

## Function-level evidence

Byte and relocation details remain in the individual function records:

- [Checked send](network_send_checked_337840.md)
- [Session dispatch](network_session_dispatch_3378d0.md)
- [Receive queue enqueue](network_buffer_enqueue_338470.md)
- [PAL transport initialization](network_transport_init_337d40.md)
- [Receiver thread](network_receiver_337B30.md)
