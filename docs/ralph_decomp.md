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
| `RALPH_EFFORT` | empty | agy `--effort` level; leave empty when the model name already sets it (e.g. `gemini-3.8-flash-low`) |
| `RALPH_MIN_PCT` | 90 | Similarity needed to advance |
| `RALPH_MAX_ATTEMPTS` | 5 | Attempts per slice per pass |
| `RALPH_MAX_SLICE` | 0x800 | Max slice size |
| `RALPH_TIMEOUT` | 1800 | Seconds per agent call |
| `RALPH_DIR` | `build/ralph` | State (`state.json`), logs, lock, `guard.json` |
| `RALPH_STALL` | 2 | Attempts without `pct` improvement before the slice is `blocked` (0 = off) |
| `RALPH_MAX_PASSES` | 3 | Revisits per partial/blocked slice. After that the slice is unresolved and the loop can end |
| `RALPH_ASM_POLICY` | `once` | Slices with strong non-C hints: `once` (1 attempt, then `asm`), `skip` (mark `asm` at once), `off` |
| `RALPH_SUMMARY_EVERY` | 5 | Print a progress line every N slices (0 = off) |
| `RALPH_PARALLEL` | 2 | Slices per wave; agents of one wave run in parallel. `1` reproduces the sequential loop |
| `RALPH_UNAVAILABLE_RETRIES` | 3 | Retries of a call that failed with a transient model error (`... model ... is not recognized`) |
| `RALPH_UNAVAILABLE_BACKOFF` | 30 | Seconds before the first transient retry; doubles on each retry |
| `RALPH_WAIT_ON_QUOTA` | 0 | `0` stops on quota exhaustion (exit 3). `N` sleeps N seconds and retries the same call |
| `RALPH_PUSH` | 1 | `1`: after each promotion commit, `git fetch` + `git rebase origin/$RALPH_BRANCH` and `git push`. `0`: commit only |
| `RALPH_BRANCH` | `main` | Branch the promotion commits are rebased onto and pushed to |

Commits: each promotion commit has a generated message (`ralph_slice.py commit-message`): the `decomp(ps2): match <func> slice (<start> - <end>)`
subject, the measured similarity and attempt count, the agent, model and wave, and a `Co-Authored-By` trailer. If the rebase
conflicts, nothing is pushed, the rebase is aborted and the commit stays local. A failed push logs a message and the loop continues.

Gate: 100% → promote + commit. 90–99% → stays in `staging/`, status `partial`, cursor advances.
<90% → retry with compile/diff feedback; after max attempts `blocked`, skipped. The loop stops only when no
uncovered function, partial, or blocked slice remains. Partial/blocked slices are revisited after new ones run out.

Slicing (`scripts/ralph_slice.py`): first function not covered by sized `type:func` entries in `symbols.txt` or by loop state;
NOP padding skipped; ends at `jr $ra` + delay slot once all forward branch targets are resolved, or at a `j` tail call
to code before the function start + delay slot.

Environment failures are classified from the agent log (`ralph_slice.py classify-failure`):
`quota` (`RESOURCE_EXHAUSTED`, `credits balance is too low`), `model_config` (`invalid model selection`), and
`transient` (`model ... is not recognized`, retried with backoff). `quota` and `model_config` stop the loop with exit 3;
the slice is not recorded, so rerunning after the cause is fixed resumes it. Those failures never mark slices `blocked`.

Lock: `build/ralph/lock.pid` holds the pid of the running loop. A second instance refuses to start while that pid is alive
and is a `ralph_decomp.sh` process; a stale file is removed and logged.

Waves: `batch --count RALPH_PARALLEL` picks distinct slices (new first, then revisits). Agents of a wave run as background
jobs, each writing only `staging/<func>.cpp`. After all finish, one `guard verify --restore` runs, then measuring,
recording, promotion and metrics happen one slice at a time. A quota or model_config failure in any agent ends the wave
without recording that round.

## Environment-failure cleanup

`ralph_slice.py requeue-unavailable --state build/ralph/state.json [--dry-run]` removes `blocked` slices whose every
attempt log shows only environment failures, so they run again. It writes `state.json.bak-<timestamp>` first and changes
nothing when nothing matches.

## Metrics (`scripts/ralph_metrics.py`)

Events are JSON lines in `build/ralph/metrics/events.jsonl` (gitignored). Types: `attempt`, `slice_final`, `wave`,
`snapshot`, `agent_failure`, `backfill`. The loop writes them; the sequential part is the only writer.

- `backfill --state ... --events ...`: derives events from `state.json` history. Runs once per events file (the loop calls it
  at start). Backfilled attempts have `outcome=backfill` and no model or timing data, so they are excluded from the
  model charts. Backfilled snapshots are cumulative approximations (final statuses at each slice's last timestamp).
- `export --events ... --out docs/metrics/`: writes `progress.csv`, `attempts.csv`, `waves.csv`, `summary.json`. Run on
  demand only; these files are not committed automatically.
- `report --events ... --out build/ralph/metrics/report.html`: static HTML with inline SVG. Six charts: progress,
  bytes per hour, time per attempt by model, first-attempt success by model, similarity distribution, agent failures
  by class. Stdlib only.

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
- `summary`: bytes covered of `.text`, `cpp_bytes` (only `done`), `asm_bytes`, `partial_bytes`, `blocked_bytes`, counts per
  status, time spent, average per slice, naive ETA, `asm` list.
- `batch --count N`: up to N distinct work items for one wave. Unbounded regions (no function end) become `asm`, reason
  `no function end`, instead of stopping the loop. `next` is `batch --count 1`.
- `classify-failure --log`: `{"class": "quota|model_config|transient|none"}`.
- `requeue-unavailable`: see the cleanup section above.

Limits: disassembly uses capstone MIPS64 (R5900 MMI shows `.word`). Library asm segments in `config.yml` are not excluded.
`promote` is the existing `decomp_pipeline.py promote`; it does not create the per-slice header and test files recent
slices carry. The commit step stages `configure.py` and `config/` whole, so run with a clean tree.
Tests: `tests/test_ralph_slice.py`, `tests/test_ralph_metrics.py`.
