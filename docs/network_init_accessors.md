# Network initialization and state accessors

## Behavior

| Function | Observed behavior |
|---|---|
| `func_003377D0` (`0x3377D0`) | If argument is zero, call `func_003379F0(0)` three times, then store argument in `D_004E3568`. Nonzero input skips calls and stores as-is. |
| `func_00337820` (`0x337820`) | Store argument in `D_004E3530`; return through `jr ra` delay slot. |
| `func_00337830` (`0x337830`) | Return `D_004E3530` through the `jr ra` delay slot. |

The functions span `0x50`, `0x10`, and `0x10` bytes respectively when alignment padding is included. The first extent ends with the return delay slot at `0x33781C`; setter and getter return delay slots are at `0x337824` and `0x337834`.

## Evidence and limits

Original PAL ELF disassembly at `0x3377D0` shows a zero-argument loop with three calls to `0x3379F0`, followed by the global store. `0x337820` and `0x337830` use a store and load of the same global. This slice proves neither session lifecycle nor peer identity, delivery guarantees, timeout behavior, size limits, or network error codes.

## Tests

- `tests/test_network_init_accessors_native.py` compiles and executes the native contracts. RED was observed before implementation as a missing-header/source compilation failure; this establishes the new-function missing-symbol blocker, not a behavioral assertion failure. GREEN: `.venv/bin/python -m pytest -q -ra tests/test_network_init_accessors_native.py` (1 passed).
- `tests/test_network_init_accessors_matching.py` compiles with MWCC, resolves `R_MIPS_26` and `R_MIPS_GPREL16` relocations, adds verified zero alignment padding, and compares all `0x70` target bytes. GREEN: `.venv/bin/python -m pytest -q -ra tests/test_network_init_accessors_native.py tests/test_network_init_accessors_matching.py tests/test_network_send_checked_337840.py tests/test_network_send_checked_337840_matching.py` (9 passed).
