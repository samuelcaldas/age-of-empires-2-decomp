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
| `RALPH_DIR` | `build/ralph` | State (`state.json`), logs, lock, `guard.json` |
| `RALPH_STALL` | 2 | Attempts without `pct` improvement before the slice is `blocked` (0 = off) |
| `RALPH_MAX_PASSES` | 3 | Revisits per partial/blocked slice. After that the slice is unresolved and the loop can end |
| `RALPH_ASM_POLICY` | `once` | Slices with strong non-C hints: `once` (1 attempt, then `asm`), `skip` (mark `asm` at once), `off` |
| `RALPH_SUMMARY_EVERY` | 5 | Print a progress line every N slices (0 = off) |

Gate: 100% → promote + commit. 90–99% → stays in `staging/`, status `partial`, cursor advances.
<90% → retry with compile/diff feedback; after max attempts `blocked`, skipped. The loop stops only when no
uncovered function, partial, or blocked slice remains. Partial/blocked slices are revisited after new ones run out.

Slicing (`scripts/ralph_slice.py`): first function not covered by sized `type:func` entries in `symbols.txt` or by loop state;
NOP padding skipped; ends at `jr $ra` + delay slot once all forward branch targets are resolved.

## Helper commands (`scripts/ralph_slice.py`)

- `next`: JSON for the next slice. New slices carry `hints` (`syscall`, `cop0`, `cache`, `sync`, `mmi`, `lq_sq`, `break`,
  `undecodable`) and `likely_asm`, true only for the strong hints `syscall` or `cop0`. `lq_sq` and `mmi` are common in
  normal R5900 code, so they are informational only. Revisits are ordered by status, then fewest passes, then least
  recently visited, so a partial that never reaches 100% cannot starve the others. When nothing is left, `kind: done`
  lists `unresolved` slices.
- `record`: one call per attempt (`--seconds`, `--stall N`). Keeps `history` (`pct`, `seconds`, `timestamp`) and prints
  the resulting `status`; the bash loop stops its inner loop on any status other than `retry`.
- `mark --status asm --reason ...`: terminal status for code that is not C. Not revisited, counted as covered. The
  agent triggers it by ending its reply with `UNMATCHABLE: <reason>`.
- `measure`: adds `side_by_side` (original vs. compiled disassembly around divergences, capped at 60 lines).
- `guard snapshot|verify [--restore]`: fingerprints `scripts tests configure.py config src include` and lists untracked
  files outside `staging/` and `build/`. The loop snapshots before each agent call and restores after: changed files
  go back via `git checkout --`, new strays are deleted. Files already uncommitted at snapshot time are only reported
  (`unrestorable`), never overwritten.
- `summary`: bytes covered of `.text`, counts per status, time spent, average per slice, naive ETA, `asm` list.

Limits: disassembly uses capstone MIPS64 (R5900 MMI shows `.word`). Library asm segments in `config.yml` are not excluded.
`promote` is the existing `decomp_pipeline.py promote`; it does not create the per-slice header and test files recent
slices carry. The commit step stages `configure.py` and `config/` whole, so run with a clean tree.
Tests: `tests/test_ralph_slice.py`.
