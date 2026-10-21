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

## Validation

`tests/test_network_receiver_337B30_native.py` builds the C++ implementation
with `g++ -m32` inside the `docker-dev` verification image. The fixture covers
zero, one, and many complete receives, ring wraparound, callback order, incomplete
and failed receives, local-peer rejection, high-bit address swapping, connection
success/failure, the global connection buffer, unchanged address words, and log
arguments. The global-address test derives each address from the original
GP-relative load; the previous external map was incorrectly displaced by `0x40`.

The exact-match gate remains unchanged: 528 bytes and 46 relocations. The original
linked ELF has no symbol or relocation sections, so it cannot establish an original
relocation count. The count 46 first appeared with the baseline candidate's test;
that 372-byte candidate also emitted 46 relocations. Treat 46 as a candidate-shape
expectation, not verified original relocation evidence. After the behavioral
corrections and explicit inline helpers, the retained candidate emits 524 bytes and
54 relocations. Twenty-five source shapes were examined, including the baseline
and intermediate candidates.
The final native fixture passes for all 21 final-shape variants. Variants using a
different byte-swap expression emitted 528 bytes, but first differed at `0x337C86`.

A diagnostic comparison resolves all 54 relocations, including 11 HI16/LO16 pairs,
by matching the HI16 destination register to the LO16 base register. Every emitted
byte of the retained candidate agrees with `0x337B30`–`0x337D3B`. The first missing
byte is at `0x337D3C`; the original has four trailing zero bytes. This diagnostic
is not the matching gate and does not establish an exact 528-byte match.

Reproduce the required gate with:

```sh
.venv/bin/python -m pytest -q -ra tests/test_network_receiver_337B30_matching.py
```

It fails with `NOT RESOLVED: emitted size 524 != 528`, before relocation resolution
or full byte comparison. The candidate also exceeds the fixed relocation count
by eight. No padding, instruction masks, assembly, or registration as `Matching`
was added. The shared resolver now pairs HI16 destinations with LO16 base registers. It
rejects reused, unconsumed, or overwritten pairs while supporting overlapping
same-symbol pairs in distinct registers. Source reconstruction or independently
justified linker/relocation handling remains necessary; the
required matching expectations have not been relaxed.

## Contract notes

Delivery uses fixed 492-byte datagrams and a 16-slot ring. Discovery filters the
configured local peer and attempts one connection to a new peer. No timeout or
retry interval appears in this function. The thread does not return.
