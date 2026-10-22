# UTF-16 length helper at `0x3394B0`

`func_003394B0` counts nonzero 16-bit code units in a zero-terminated string.
The original extent is 40 bytes (`0x3394B0`–`0x3394D4`, including the `jr ra`
delay slot). Eight zero alignment bytes follow before `0x3394E0`.

## Behavior

| Input | Result |
|---|---:|
| First code unit is zero | `0` |
| One nonzero code unit then zero | `1` |
| `SESSION` followed by zero | `7` |

The function accepts a pointer in `$a0`, reads 16-bit values, and returns the
count in `$v0`. It has no calls, global accesses, or relocations. The target loop
uses a branch-likely delay slot to increment the result.

## Evidence and tests

- Original ELF disassembly at `0x3394B0`–`0x3394D4` confirms the loop and return.
- Red harness command: `.venv/bin/python -m pytest -q tests/test_network_utf16_length_3394b0_native.py`.
  The initial run was blocked by absent implementation/header and a C++98 test
  include issue; after replacing `<cstdint>`, only missing implementation files
  remained. This was harness setup, not a reproduced assertion failure.
- Green native command: `.venv/bin/python -m pytest -q tests/test_network_utf16_length_3394b0_native.py` — 1 passed.
- Target compile succeeded with MWCC 2.3.1.01 and the documented PS2 flags.
  The object emits 36 bytes, while the verified target extent is 40 bytes.
  The emitted loop uses a different branch layout. Exact byte comparison remains
  nonmatching; no bytes are masked and there are no relocations to resolve.
- Matching command: `MWCIncludes="" .venv/bin/python -m pytest -q tests/test_network_utf16_length_3394b0_matching.py`.
  It currently fails on the verified extent assertion (`36 != 40`).

## Open questions

- The precise source construct that produced the target's additional branch
  sequence is unresolved.
