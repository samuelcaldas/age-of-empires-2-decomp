# IP address formatter at `0x337600`

`func_00337600` formats four address bytes into the shared buffer at
`0x01087EB0`. The target function occupies `0x60` bytes through its zero
alignment word; the next function begins at `0x337660`.

## Behavior

| Input bytes | Calls | Result |
|---|---|---|
| `{a, b, c, d}` | `func_11A498(D_01087EB0, D_004D1E88, a, b, c, d)` | `D_01087EB0` containing `a.b.c.d` |

The format string at `0x004D1E88` is `%d.%d.%d.%d`. The formatter extracts
unsigned bytes in memory order. The output buffer is shared; later calls replace
the prior string.

## Evidence and validation

Disassembly at `0x337600`–`0x337658` loads the four bytes from the input,
passes them with the format string to `0x11A498`, then returns `0x01087EB0`.
The return delay slot ends at `0x337658`; the zero word at `0x33765C` aligns the
next function.

- Native test: `tests/test_network_ip_format_parse_native.py` checks byte order,
  formatted output, and formatter call count.
- Red attempt: `.venv/bin/python -m pytest -q -ra tests/test_network_ip_format_parse_native.py`
  failed before implementation because both source files and headers were
  absent. This was a missing-symbol/build blocker, not a behavioral red assertion.
- Green: the same command passed after implementation.
- MWCC compile succeeds. It emits `0x40` bytes for this function, while the ELF
  extent is `0x60`; exact matching is not established. The remaining mismatch
  requires source-shape investigation. No byte-equality claim is made.

## Symbols needed

`func_11A498` (`0x11A498`), `D_01087EB0`, and `D_004D1E88`.
