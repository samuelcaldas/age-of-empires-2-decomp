# Trade action route buffers

## Verified functions

The configured PS2 Metrowerks toolchain produces exact original instruction bytes
for all four functions in `src/trade_action_route_finish.cpp`:

| Function | Original virtual address | Instruction bytes | Match |
|---|---|---|---|
| Action-entry unpacker | `0x1508F0` | 44 | 100% |
| Action-entry growth and insertion | `0x150920` | 928 | 100% |
| Secondary-item unpacker | `0x150CC0` | 32 | 100% |
| Secondary-item growth and append | `0x150CE0` | 612 | 100% |

These are **1,616 instruction bytes**, plus 16 alignment bytes in the
`[0x1508F0, 0x150F50)` slice. All implementations are C++, with no inline assembly
or instruction-word substitutions. The matching test resolves the object's
`R_MIPS_26` relocations before comparing the literal bytes to the original ELF;
it does not rely on objdiff ignoring relocation differences.

## Correct ELF mapping

The executable load segment maps file offset `0x1E0` to virtual address
`0x100000`, so within that segment:

```text
virtual_address = file_offset + 0xFFE20
```

The former slice used `0xFFE10`, making its displayed addresses 16 bytes too
low. Consequently, jumps appeared to skip the first four prologue instructions.
The actual wrapper targets are the body entries `0x150920` and `0x150CE0`.

The corrected file range is `[0x50AD0, 0x51130)`. The final `jr` is at virtual
address `0x150F3C`, its required delay slot is at `0x150F40` (file `0x51120`),
and alignment ends at `0x150F50`. The former boundary at file `0x51120`
excluded that delay slot. Adjacent slices were not globally remapped by this
change; their labels require their own ELF-mapping audit.

## Data layout and preserved behavior

`TradeAction` stores entry/item counts at `0x31`/`0x32`, capacities at
`0x33`/`0x34`, and buffer pointers at `0x3C`/`0x40`.

- `ActionEntry` is 24 bytes: four shorts and four floats. Growth copies each
  field separately. Append reloads the byte count between stores. Front
  insertion shifts forward in increasing index order, reproducing the original
  overwrite behavior rather than replacing it with a conventional reverse move.
- `TradeItem2` is 20 bytes: three shorts, two padding bytes, and three words.
  Growth zeroes the new buffer, initializes identifiers to `-1`, and copies only
  the six fields, leaving padding zero. All incoming records append; the final
  word is data, not an insertion flag.
- Allocation failure returns zero without changing buffer ownership, capacity,
  or count. Capacity grows by one. Byte-count/capacity wrap at 256 is retained
  because this is matching reconstruction, not a behavioral repair.

The C++ helpers are explicitly inline with `#pragma inline_depth(4)`. Shallower
inlining leaves a copy-helper call and changes the stack frame. Keeping the
array index inside the field-copy helper also preserves the original register
allocation. No function body exceeds 15 lines, and there are no `else` branches.

## Regression validation

`tests/test_trade_action_route_finish.py` compiles the actual C++ source as
32-bit code with deterministic allocation doubles. Its eight cases cover empty
and populated buffers, nonzero item data, zeroed copy padding, both allocation
failure paths, all wrapper fields, forward-shift behavior, and byte-count wrap.
Compile-time assertions verify the record sizes and pointer offsets.

Build the development test image from the repository root:

```sh
docker --context docker-dev build --network host \
  -t aoe-decomp-tests -f tests/Dockerfile .
docker --context docker-dev run --rm --ulimit core=0 \
  -v "$PWD:/workspace" aoe-decomp-tests \
  python -m pytest tests/test_trade_action_route_finish.py -q
```

With the licensed original ELF and freshly built MWCC object accessible inside
the development container, also run:

```sh
python -m pytest tests/test_ps2_route_finish_matching.py -q
python -m flake8 configure.py tests/test_trade_action_route_finish.py \
  tests/test_ps2_route_finish_matching.py
```

The four literal-byte tests skip if either ignored input is unavailable; a
skipped test is not evidence of a match. Worktree symlinks to ignored inputs must
be mounted at their resolved absolute locations inside the container.

At this step, the registered-unit report was **51,584 / 104,132 exact code bytes**
and **482 / 579 exact functions** across 134 registered units. These are not
whole-game coverage figures and do not establish a complete or playable build.
