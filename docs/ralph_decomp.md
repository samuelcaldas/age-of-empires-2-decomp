# Ralph decomp loop

`scripts/ralph_decomp.sh` decompiles the PS2 `.text` (0x100000–0x4E2FE0) slice by slice.
Only code generation is non-static; slicing, prompt, compile, diff, gate, promote and commit are scripted.

```sh
AGENT=agy scripts/ralph_decomp.sh          # default agent; also codex, claude, or an executable path
RALPH_DRY_RUN=1 scripts/ralph_decomp.sh    # build next prompt only, no agent call
```

Prompt delivery: `agy --print "<prompt>"`, `codex exec -` (stdin), `claude -p` (stdin). A custom executable gets the prompt on stdin.

| Variable | Default | Meaning |
|---|---|---|
| `AGENT` | `agy` | Agent CLI |
| `RALPH_MODEL` | CLI default | Model override |
| `RALPH_MIN_PCT` | 90 | Similarity needed to advance |
| `RALPH_MAX_ATTEMPTS` | 5 | Attempts per slice per pass |
| `RALPH_MAX_SLICE` | 0x800 | Max slice size |
| `RALPH_TIMEOUT` | 1800 | Seconds per agent call |
| `RALPH_DIR` | `build/ralph` | State (`state.json`), logs, lock |

Gate: 100% → promote + commit. 90–99% → stays in `staging/`, status `partial`, cursor advances.
<90% → retry with compile/diff feedback; after max attempts `blocked`, skipped. The loop stops only when no
uncovered function, partial, or blocked slice remains. Partial/blocked slices are revisited after new ones run out.

Slicing (`scripts/ralph_slice.py`): first function not covered by sized `type:func` entries in `symbols.txt` or by loop state;
NOP padding skipped; ends at `jr $ra` + delay slot once all forward branch targets are resolved.

Limits: disassembly uses capstone MIPS64 (R5900 MMI shows `.word`). Library asm segments in `config.yml` are not excluded.
`promote` is the existing `decomp_pipeline.py promote`; it does not create the per-slice header and test files recent
slices carry. The commit step stages `configure.py` and `config/` whole, so run with a clean tree.
Tests: `tests/test_ralph_slice.py`.
