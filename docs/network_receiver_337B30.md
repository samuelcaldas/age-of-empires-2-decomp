# Receiver thread at `0x337B30`

`func_00337B30` is an infinite network receive thread. Its executable instructions
span 524 bytes (`0x337B30`–`0x337D3B`), ending with the delay slot at `0x337D38`.
The `nop` at `0x337D3C` is four bytes of alignment before the next function at
`0x337D40`; it is not part of the receiver's instruction stream.

## Observed behavior

The thread logs its startup, then selects connected or peer-discovery receive
behavior from a global state flag. Connected mode receives 492-byte packets
into a 16-slot ring, dispatches each complete packet, then advances the ring
index modulo 16 and increments the receive count. In discovery mode it uses
`recvfrom`, ignores incomplete packets and the configured local address,
copies words at address offsets 4 and 8 into the global socket address at
`0x010890C0`, stores their byte-swapped values in the peer globals, and calls
`connect` with the global socket address. Its words at offsets 0 and 12 remain
unchanged. A
successful connection sets the state and advances the counters before logging
the two swapped peer words. A failed
connection clears the stored peer words. Address-byte swapping uses unsigned
shifts; signed right shifts corrupt peer words with the high bit set.

The original trusts the returned peer address and packet length. No bounds
checks belong inside this function.

## Matching evidence

The receiver's executable instruction stream spans 524 bytes, from `0x337B30`
through the delay-slot instruction at `0x337D3B`. The zero word at `0x337D3C`
is alignment; the following initializer starts at `0x337D40` with a verified
stack-frame prologue. The PAL ELF is linked and stripped, so it has no original
symbol or relocation sections. Its bytes establish the instruction extent, not
an original relocation-count manifest.

MWCC emits the receiver as a 524-byte C++ function with 54 relocations. The
matching test asserts the candidate relocation count and type manifest: seven
`R_MIPS_26`, eleven `R_MIPS_HI16`, eleven `R_MIPS_LO16`, and twenty-five
`R_MIPS_GPREL16`. All undefined names resolve to explicitly supplied targets.
The strict resolver pairs each `HI16` destination register with the matching
`LO16` base register, rejects overlaps or missing pairs, and confirms every one
of the candidate's 524 bytes against the original ELF without masks. The four
original alignment bytes remain a separate zero-padding assertion.

The previous 528-byte/46-relocation expectation came from an earlier candidate,
not from original ELF metadata. One earlier 528-byte source variant differed at
`0x337C86`; it was not an exact match. Do not infer that the stripped original
had 54 linker relocations. The evidence proves resolved-byte equality for this
compiled C++ function, plus separate alignment, but cannot compare against absent
original relocation records.

`tests/test_network_receiver_337B30_native.py` builds the implementation with
host `g++ -m32`. It exercises connected receive, ring wraparound, peer discovery,
incomplete packets, local-peer rejection, high-bit address swapping, successful
and failed connect, buffer contents, state changes, call order, and logs. The
byte-swap helper uses unsigned host shifts to reproduce R5900 logical shifts.

Run the focused gates with:

```sh
.venv/bin/python -m pytest -q -ra \
  tests/test_network_receiver_337B30_native.py \
  tests/test_network_receiver_337B30_matching.py \
  tests/test_network_match_support.py
```

The matcher reports `EXACT 524 bytes`; the native and relocation-helper tests
pass. The original function and its alignment remain registered separately in
the network branch, with the receiver code segment spanning `0x337B30` through
the alignment word before the next function.

## Contract notes

Delivery uses fixed 492-byte datagrams and a 16-slot ring. Discovery filters the
configured local peer and attempts one connection to a new peer. No timeout or
retry interval appears in this function. The thread does not return.
