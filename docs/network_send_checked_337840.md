# Checked datagram send at `0x337840`

`func_00337840` is the size-checked send wrapper of the PS2 network layer
(`mydplay.cpp`, the "DirectPlay Compatible Interface" over i.LINK sockets). It
is 136 bytes (`0x337840`–`0x3378C8`), including the return delay slot, and is
followed by eight zero alignment bytes before the next function at `0x3378D0`.

## Behavior

| Input | Calls, in order | Result |
|---|---|---|
| `size > 492` | log `"err! il_sendto()\n"` | `-1` |
| `size <= 492`, send returns 492 | WaitSema, send, SignalSema | `492` |
| `size <= 492`, send returns anything else | WaitSema, send, SignalSema, log `"err! sceILsockSend()\n"` | `-2` |

The send always transmits a fixed 492-byte buffer, whatever `size` is, with
flags `0`. The size argument only gates the call.

## Evidence for the callees and globals

All of the following comes from the original `SLES-50282` ELF:

- `0x104D20`, `0x104D40`, and `0x104D60` are single-syscall stubs for EE kernel
  calls 64, 66, and 68: `CreateSema`, `SignalSema`, and `WaitSema`.
- `D_004E3560` holds a semaphore created with an initial and maximum count of 1
  (a mutex). The wrapper holds it only around the send call.
- `0x388D60` is `sceILsockSend`. Its own error log uses the `socketee.c`
  string `"... sceILsockSend(sock=%d)\n"`. It rejects lengths of 493 and more
  with `-2007` before doing any RPC.
- The initialisation code opens three sockets with arguments `(60, 2, 0)` and
  stores them at `0x4E353C`, `0x4E3538`, and `0x4E3534`. Their bind error
  messages name them `sdRx`, `sdTx`, and `sdBc`. `D_004E3538` is therefore the
  transmit socket.
- `0x118DE0` is the variadic debug log. Both format strings are unique in the
  image, at `0x4D1EB0` and `0x4D1ED0`.

## Tests

- `tests/test_network_send_checked_337840.py` builds
  `tests/native/network_send_checked_337840_test.cpp` with the host compiler and
  checks the call order, the semaphore and socket globals, the fixed length and
  flags, the log strings, and all three return paths, including the 492/493
  boundary.
- `tests/test_network_send_checked_337840_matching.py` compiles the source with
  MWCC 2.3.1.01, resolves all 12 relocations (four `R_MIPS_26` calls, two
  `HI16`/`LO16` string pairs, and three `GPREL16` loads with `_gp = 0x4EA7C0`),
  and compares all 136 bytes with the original without masks. It also checks
  that the original holds both log strings at `0x4D1EB0` and `0x4D1ED0`.

## Registration

The unit is registered as `Matching`, with its own `config.yml` code segment
(file offset `0x237A20`, 0x90 bytes including the alignment) and the remainder
of the old `post_aoe4` range split off as `bin_3378d0_340370`. The callees use
the splitter's names (`func_104D60`, `func_104D40`, `func_388D60`, and
`func_118de0`). The strings and the two globals are `symbols.txt` entries, so
the reference assembly and the C++ object name them identically.

`objdiff-cli diff` reports 99.91% for the function. The only differences are
the three `$gp` loads: the split configuration does not set a `gp` value, so
the reference assembly keeps raw offsets where the C++ object has `GPREL16`
relocations. Other `Matching` units that read globals through `$gp` show the
same difference. The relocation-resolving byte test above is the exact check.

## Source shape

MWCC produces `slti at` only for `size > 492`; `size >= 493` produces
`slti v0`. The trailing `return sent;` after the error block produces the
unreachable `move v0,s0` at `0x3378B4`, which is present in the original.

## Open questions

- The meaning of socket arguments `(60, 2, 0)` is not yet mapped to i.LINK
  socket constants.
- Whether a caller or `sceILsockSend` itself retries or orders datagrams is not
  established. This function does neither.
