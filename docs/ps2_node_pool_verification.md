# Spatial node-pool verification

## Current status

Block 59 is **not approved as Matching**. Earlier reports claiming 100% objdiff
matching were incorrect. A fresh build of
`3bb604f0975265a75bb82246493e4cb6893b4edf` produced 98.31169%, rather than the
99.61039% seen with previously modified generated targets.

The C++ function does reproduce all 308 original instruction bytes after six
explicit relocations. This is a separate result from matching the generated
reference object's relocation records. Neither `metadata.complete` nor
`complete_code` proves an instruction-byte match.

The unresolved setup, clear, expand, and add-zone units remain `NonMatching`.
Their completion flags must not inflate registered completion totals. Init and
destructor are also registered `NonMatching`. A read-only boundary audit found
that the configured start addresses and symbols for setup, destructor, and clear
are `0x10` later than the original entries (`0x1F1ED0`, `0x1F1FC0`, and
`0x1F2010`). The init slice start `0xF20A0` maps to `0x1F1EC0`, not its declared
`0x1F1ED0`. Fresh objdiff 100% results for init and destructor therefore do not
establish that their slices cover the correct original bytes.

## Clean baseline

The original executable's `PT_LOAD` mapping places file offset `0x1E0` at virtual
address `0x100000`. For Block 59:

| Property | Value |
|---|---|
| Entry point | `0x1F21E0` |
| Original file offset | `0xF23C0` |
| Instruction bytes | 308 (`0x134`) |
| Final delay-slot address | `0x1F2310` |
| Instruction end, exclusive | `0x1F2314` |
| Slice end, exclusive | `0x1F2320` |
| Alignment padding | 12 bytes |
| MWCC function section index in the observed object | 7 |

Always select the compiled function's section using its symbol's `st_shndx`.
Metrowerks objects can contain multiple sections with the same name. Selecting
an arbitrary `.text` section is not reliable.

The fresh report recorded these fuzzy comparison percentages:

| Unit | Original code bytes | Fuzzy match |
|---|---:|---:|
| init | 8 | 100% |
| setup | 228 | 98.070175% |
| destructor | 68 | 100% |
| clear | 196 | 99.081635% |
| expand | 244 | 99.09836% |
| add-zone | 308 | 98.31169% |

These percentages describe the clean generated reference comparison. They do not
mean that the unmatched units contain those percentages of verified exact bytes.
Setup also references `func_1F21E0`, while the add-zone symbol is
`func_001F21E0`; the Block 57 native fixture defines the unpadded spelling, which
hides that mismatch. Correcting these boundaries and symbols is separate work.

## Block 59 relocation evidence

The compiled function contains precisely these six relocations:

| Function-relative offset | Type | Original destination |
|---|---|---|
| `0x3C` | `R_MIPS_HI16` | Format string at `0x492790` |
| `0x40` | `R_MIPS_LO16` | Format string at `0x492790` |
| `0x44` | `R_MIPS_HI16` | Filename string at `0x492740` |
| `0x48` | `R_MIPS_LO16` | Filename string at `0x492740` |
| `0x4C` | `R_MIPS_26` | `func_118de0` at `0x118DE0` |
| `0x94` | `R_MIPS_26` | `func_117CAC` at `0x117CAC` |

The local string symbols were `@8` and `@9` in the observed object. Those names
are compiler details, not stable identities. The strings are
`%s(%d) Used_Zones == Max_Zones(%d)\n` and `obmanager.cpp`. Each complete
null-terminated string occurs once in the original loaded executable data.

Resolving those six records produced the same SHA-256 for the compiled function
and original 308-byte range:

```text
8d97779dc448b60936fd0826701a62f27f015b3c3e446b768e7bfbb0506bfcda
```

The untouched generated target contains **32** relocations, not six. Twenty-six
additional relocations treat structure offsets as address references. The
reference also names the string symbols differently. Therefore literal C++ code
equality does not establish identical reference relocation records, and the
strict matching gate remains unresolved. Do not fix this by hand-editing ignored
`build/SLES-50282/asm/*.s` files.

## Regression evidence

Builds and tests use `docker --context docker-dev` with
`aoe-tests:verification`, `TZ=America/Sao_Paulo`, and private inputs mounted
read-only at their resolved absolute paths. Container tool downloads needed
`--network host` after bridge-network DNS failed. No original executable or
licensed compiler is included in this change.

On the unchanged review commit, Blocks 57–59 passed all nine focused tests.
The completion-registration regression test then failed four assertions with
`assert True is False`, before changing the four registrations. The same four
cases passed after the correction. The corrected subsystem run passed 13 tests.
The full available suite passed 2,609 tests in 132.96 seconds, with no failures or
skips. These are configuration-behavior and regression results, not substitutes
for reconstructed C++ behavior coverage or exact binary matching.

The regression node is:

```sh
python -m pytest -q -ra \
  tests/test_zone_spatial_grid_block59.py::test_unverified_node_pool_units_are_incomplete
```

Run it inside the test container described in [testing.md](testing.md). The
node-pool subsystem command is:

```sh
python -m pytest -q -ra \
  tests/test_zone_spatial_grid_block57.py \
  tests/test_zone_spatial_grid_block58.py \
  tests/test_zone_spatial_grid_block59.py
```

Native behavioral tests and target comparison remain separate gates. Existing
fixtures do not comprehensively establish allocation-helper semantics, every
boundary case, or cross-unit linkage. Block 60 remains separate, unapproved work.
