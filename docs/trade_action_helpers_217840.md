# Trade-action helpers at `0x217840`

`src/trade_action_helper_217840.cpp` implements eight independent entries at
`0x217840`, `0x217860`, `0x217880`, `0x2178A0`, `0x2178C0`, `0x2178E0`,
`0x217900`, and `0x217920`. Together, their original range contains 192
instruction bytes and 48 bytes of original padding, for a 240-byte slice.

The first seven entries store their arguments into the target object and invoke
the virtual function at vtable offset `0x28` with `(self, 1)`. The final entry
stores a word at `0x188` and the low byte of its second argument at `0x18C`, and
does not invoke a callback. They are intentionally separate functions rather
than one shared implementation.

The reconstruction remains **NonMatching**. A fresh MWCC build and real GNU
`--no-undefined` link placed all eight entries at their original addresses. Their
emitted symbol sizes are 28, 24, 24, 24, 24, 28, 28, and 12 bytes. The first seven
bodies each differ in five instruction bytes; the final body matches all 12.
These are unmasked comparisons, not fuzzy scores or exactness claims.

The linked `.text` contains 236 bytes: 192 instruction bytes and 44 emitted
internal-alignment bytes. The final four padding bytes belong only to the
original slice; this link does not emit them. Original bytes were read through
the file-backed ELF load after checking SHA-1
`f478e19f2059d52899b691483ef5c7522e30e17c`.

`tests/test_trade_action_helpers_217840.py` compiles the actual source as 32-bit
native code and checks object-wide write boundaries, callback-visible stores,
callback counts, integer edges, and byte truncation. A separate minimal compile
probes multilib availability; a production-source compile failure remains an
error, not a prerequisite skip. These behavioral tests do not establish exact
emitted instruction bytes or matching status.
