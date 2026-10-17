# Trade-action dispatcher at `0x2B66B0`

`src/trade_action_dispatcher.cpp` reconstructs the complex market and target dispatch function `func_002B66B0` (`0x2B66B0`–`0x2B76B0`, 4,088 instruction bytes + 8 bytes zero padding in `AOK.ELF`).

Its registered object remains **NonMatching**.

## Mapping and Binary Slice

The executable load segment maps file offset `0x1E0` to virtual address `0x100000`, giving:

```text
virtual_address = file_offset + 0xFFE20
file_offset = virtual_address - 0xFFE20
```

- VRAM range: `0x2B66B0`–`0x2B76B0` (slice: 4,096 bytes / `0x1000`).
- File offset range: `0x1B6890`–`0x1B7890`.
- Code ends at `0x2B76A8` with return `jr $ra` and delay slot at `0x2B76A4`.
- Trailing zero padding: 8 bytes (`0x2B76A8`–`0x2B76B0`).

## Modular Architecture

To adhere to Object Calisthenics (all source and test files strictly under 200 lines, guard clauses, and single responsibilities), the implementation is partitioned into modular internal headers:

- `include/trade_action_dispatcher.h`: Public C-linkage entry point declaration.
- `include/trade_action_dispatcher_access.h`: Strongly-typed field accessors and pointer offsets ensuring strict compatibility with 32-bit PS2 structures.
- `include/trade_action_dispatcher_direct.h`: Handlers for direct action IDs (`114`, `115`, `109`, `110`, `108`, `104`, and `136`).
- `include/trade_action_dispatcher_market.h`: Target team validation, list buffers, diplomatic adjustments, trade notifications, and candidate acceptance for action `513`.
- `include/trade_action_dispatcher_fallback.h`: Fallback candidate creation, quota budget evaluation, and the candidate loop.
- `src/trade_action_dispatcher.cpp`: Root coordinator entry point.

## Verification

- **Docker Environment**: Executed via `docker --context docker-dev run` using `aoe4-verification-final:20261015` with python at `/opt/venv/bin/python`.
- **Native Suite**: `tests/test_trade_action_dispatcher.py` compiles with `-m32` and `static_assert(sizeof(void *) == 4)`. All 16 unit and mutation tests pass.
- **Combined Regressions**: All 133 tests across adjacent trade modules pass.
- **Build System**: Slices registered in `config/SLES-50282/config.yml` and `configure.py`; Splat `config.json` regenerated with `tools/splat_to_config_json.py`; `ninja -n` dry-run executes cleanly with exit code 0.
