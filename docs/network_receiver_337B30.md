# Receiver thread at `0x337B30`

`func_00337B30` is an infinite network receive thread. The original extent is
528 bytes (`0x337B30`–`0x337D3F`), including the trailing `nop`; the next
function starts at `0x337D40`.

## Observed behavior

The thread logs its startup, then selects connected or peer-discovery receive
behavior from a global state flag. Connected mode receives 492-byte packets
into a 16-slot ring, dispatches each complete packet, then advances the ring
index modulo 16 and increments the receive count. In discovery mode it uses
`recvfrom`, ignores incomplete packets and the configured local address,
records a new peer, byte-swaps its address words, and calls `connect`. A
successful connection sets the state and advances the counters. A failed
connection clears the stored peer words.

The original trusts the returned peer address and packet length. No bounds
checks belong inside this function.

## Validation

`tests/test_network_receiver_337B30_native.py` builds the C++ implementation
with host `g++ -m32`; the focused native test passes. `tests/test_network_receiver_337B30_matching.py` uses the
shared `tests/network_match_support.py` exact-byte resolver with a 528-byte
extent and a fixed relocation count. The current candidate does not match: MWCC
emits 372 bytes. Matching remains blocked pending source-shape reconstruction.

## Contract notes

Delivery uses fixed 492-byte datagrams and a 16-slot ring. Discovery filters the
configured local peer and attempts one connection to a new peer. No timeout or
retry interval appears in this function. The thread does not return.
