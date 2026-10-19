# Spatial node-pool node free verification (Block 61)

## Current status

Block 61 (`zone_spatial_grid_node_pool_free_node`, `func_001F24A0`) is
implemented in pure C++ in `src/zone_spatial_grid_node_pool_free_node.cpp`.

The implementation matches all 60 instruction bytes (`0x3C`) of the original
PlayStation 2 PAL executable (`orig/SLES-50282/AOK.ELF`) with zero relocations.
As directed by repository coordination, `config.yml` and `symbols.txt` remain
untouched pending integration review.

## Binary slice boundaries

The executable `PT_LOAD` mapping places file offset `0x1E0` at virtual address
`0x100000`, so `VA = file_offset + 0xFFE20`.

| Property | Value |
|---|---|
| Function | `func_001F24A0` |
| Virtual address | `0x1F24A0` |
| File offset start | `0xF2680` |
| Code size | 60 bytes (`0x3C`, 15 instructions) |
| Delay slot instruction | `0x1F24D8` (file offset `0xF26B8`) |
| Slice end | `0xF26C0` (virtual address `0x1F24E0`) |
| Alignment padding | 4 bytes (`nop`) |

## Preserved behavior

`func_001F24A0(NodePool *self, void *node)` returns a 64-byte node to the pool:

1. Writes the current free-list head pointer (`self->field_138820`) into the
   link pointer at `node + 12`.
2. Updates `self->field_138820` to point to `node`.
3. Increments the available node counter (`self->field_138830++`).
4. Returns via `jr $ra` with the available counter write stored in the branch
   delay slot at `0x1F24D8`.
5. Leaf function without stack frame allocation (`$sp` unmodified).

## Binary instruction matching

The compiled function produces exact original instruction bytes:

```text
fb467cfae86b078f0ebdc534f3f57c6eab81f7043084da724d2867060e515f4b
```

Because the function is self-contained and only accesses structure fields via
immediate arithmetic, both the original binary slice and the compiled object
contain zero relocations.

## Verification tooling

- `scripts/verify_node_pool_free_node.py`: Verifies 60/60 byte equality against
  the pinned original ELF and validates zero relocations.
- `scripts/verify_node_pool_free_node_cli.py`: Command-line tool exiting 0 on
  verified match.
- `tests/test_node_pool_free_node_provenance.py`: 5 test cases asserting
  exact bytes, mutation rejection, and CLI exit codes.
- `tests/native/zone_spatial_grid_block61_test.cpp`: Native 32-bit test
  verifying ABI layout, empty-list push, chaining, and payload preservation.
- `tests/test_zone_spatial_grid_block61.py`: Pytest driver for native test and
  no-assembly verification.

## Regression validation

- Native behavioral test: 4 test scenarios passed in C++98 `-m32`.
- Block 61 provenance suite (`test_node_pool_free_node_provenance.py`): 5 passed in 0.36s.
- Focused Block 61 module (`test_zone_spatial_grid_block61.py`): 2 passed in 0.18s.
- Full available repository test suite in `docker-dev`: 2,613 passed in 135.06s with zero failures and zero skips.
- Static checks: Clean under `flake8`, Markdown link validation, and `git diff --check`.

