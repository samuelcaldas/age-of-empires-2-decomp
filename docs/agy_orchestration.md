# agy orchestration

`agy` is an external CLI model worker. The project uses it for separable tasks
(web research, analysis of original binaries, fetching official files, splat
splits, and doc drafts). Claude stays the orchestrator and the final authority:
it decides what to ask, checks what comes back, and integrates the result.

Everything goes through one wrapper, `scripts/agy/`. Ad hoc `agy -p` calls are
not used for project work, because they gave no record of what was done and
nothing stopped them from writing outside their task.

## Layout

| Path | Role |
|---|---|
| `scripts/agy/delegate.py` | Runs one profile. Command-line entry point. |
| `scripts/agy/orchestrate.py` | Runs a batch: parallel, with `depends_on`. |
| `scripts/agy/profiles/*.yml` | One file per task type: model, effort, mode, timeout, writable paths, prompt. |
| `scripts/agy/schemas/*.json` | Output schema per profile. Passed to agy and checked again locally. |
| `scripts/agy/allowed_sources.yml` | URL prefixes that `fetch-official` may report as sources. |
| `build/agy/<key>/` | One directory per run: `prompt.md`, `meta.json`, `stdout.log`, `agy.log`, `result.json`. |
| `build/agy/batch-<id>/summary.json` | Batch state, rewritten on every change. |
| `.worktrees/agy-<key>` | The worktree and branch of a run. Kept after the run so it can be inspected. |
| `.claude/agents/agy-worker.md` | Thin Claude agent that calls the wrapper and reports its result. |
| `.claude/skills/agy-delegate/SKILL.md` | When to delegate and how to check the result. |

The package has no dependencies beyond the project's `requirements.txt`
(PyYAML) and, for tests, `requirements-dev.txt`. Its JSON Schema checker covers
only the subset the profiles use (`type`, `enum`, `properties`, `required`,
`additionalProperties: false`, `items`).

## Profiles

| Profile | Writes | Model (default) | Notes |
|---|---|---|---|
| `research` | nothing | `gemini-3.8-flash-medium` | Sourced report. Every finding carries a URL. |
| `binary-analysis` | nothing | `gemini-3.8-flash-medium` | Reads one binary by absolute path. Size, SHA-1, format, linker, section entropy. |
| `fetch-official` | `orig/<version>/*` in the worktree, copied to the main checkout only after checks | `gemini-3.1-pro-high` | See below. |
| `splat-split` | `config/<version>/config.yml` | `gemini-3.1-pro-high` | `TODO` values stay `TODO`. `configure.py`, `tools/`, and `build.sha1` are not writable. |
| `doc-draft` | `docs/*` | `gemini-3.1-pro-high` | Drafts from given findings. Open questions are listed, not guessed. |

## How a run works

1. **Validate first.** The profile, its inputs, and the agy executable are
   checked before anything is created. A path input must exist and resolve
   inside the repository. A bad input raises an error with no side effects.
2. **Key the run.** The key is a hash of the profile file, schema, rendered
   prompt, model, effort, timeout, and each path input's SHA-256. The same key
   means the same work.
3. **Reuse or run.** A run already in state `done` with the same key is
   returned as it was (`reused: true`). Anything else is run again.
4. **Isolate.** agy runs in a fresh worktree `.worktrees/agy-<key>` on branch
   `agy-<key>`, from the current `HEAD`. Creating worktrees takes an exclusive
   file lock, so parallel runs do not race on `.git`.
5. **Observe.** The main checkout is fingerprinted before and after the run
   (see the guard below).
6. **Judge.** The verdict has three states, in this precedence:
   - `rejected`: the run changed a path outside its writes list, or changed the
     main checkout while it ran.
   - `failed`: timed out, non-zero exit, `status` not `SUCCESS`, no
     `structured_output`, or output that does not match the schema.
   - `done`: none of the above.
7. **Promote (only `fetch-official`, only if `done`).** See below.
8. **Record.** `result.json` holds the outcome. `meta.json` holds the provenance
   and `git diff --stat` of the worktree. Nothing is merged.

Exit status of `delegate.py`: 0 for `done`, 1 for `failed` or `rejected`, 2
when validation failed before anything ran.

## What is enforced, and what is not

The wrapper does not rely on the model's obedience. A probe showed why: with
`--mode plan --sandbox`, agy still created a file when asked to. So both flags
are passed, but they are treated as advisory.

**Enforced by the wrapper:**

- **Worktree scope.** `git status --ignored`, plus `git diff --name-only <base>`
  (which includes commits the model made), is matched against the profile's
  `writes` patterns. A read-only profile has no patterns, so any change is a
  violation.
- **Main checkout scope.** Fingerprints of `git status` for the main checkout,
  plus size and mtime for `orig/` and `config/` (which git does not list), are
  compared before and after. A write that lands outside the worktree is caught.
  Only `.worktrees/` and `build/` are excluded.
- **Output.** The envelope status, exit code, timeout, and the schema are checked
  locally, not just by agy.
- **Downloads.** For `fetch-official`, the reported `source_url` must start with
  an entry in `allowed_sources.yml`. The file's real SHA-1 must equal both the
  expected SHA-1 given as input and the SHA-1 the model reported. An existing
  file in `orig/` with different content is never overwritten.
- **Inputs.** Unknown inputs, missing required inputs, empty values, and path
  inputs that resolve outside the repository are errors.
- **No permission bypass.** `--dangerously-skip-permissions` is never passed.

**Not enforced. Keep these in mind:**

- **Network access.** agy needs its own network access to run, so the wrapper
  cannot block web access for analysis profiles. Only the prompts forbid it.
  Web text is data, and the prompts say so, but a claim sourced from the web
  must still be checked by Claude before it is used.
- **What the model reads.** Detection covers writes, not reads. A read of a file
  outside the repository is not visible to the wrapper.
- **`fetch-official` URL checks** cover the URL the model reports, not every
  request it made. The downloaded file itself is verified by SHA-1, which is the
  check that matters.
- **Concurrent edits.** A change made by a person in the main checkout while a
  run is in progress is reported as the run's own change, so the run is
  `rejected`. Avoid editing the main checkout during a batch.
- **Concurrency across processes.** Locks in `build/agy/` serialize the
  worktree creation and the promotion. Two batches started from different
  checkouts do not share them.

## Promotion of `fetch-official`

The model downloads into its worktree at `orig/<version>/<file>`. The wrapper
then:

1. checks `source_url` against `allowed_sources.yml`;
2. checks that `file_path` starts with `orig/<version>/` and contains no `..`;
3. computes the file's SHA-1 and compares it with `expected_sha1`;
4. copies the file to the main checkout, atomically, under an exclusive lock.

Leaked betas, cracks, repacks, and unofficial mirrors are excluded (see
[ADR 0001](adr/0001-target-editions.md)). An archive.org item may be added to
`allowed_sources.yml` only after a person has reviewed that item.

The expected SHA-1 comes from a source outside the model: `config/<VERSION>/build.sha1`
for a pinned version, or the value recorded in [game_files.md](game_files.md).
Do not pass a SHA-1 the model suggested.

## Usage

Run from the main checkout. The venv must have the requirements installed.

```sh
# One task
.venv/bin/python scripts/agy/delegate.py --task binary-analysis \
  --input binary=orig/AGE2_X1_1_0C_EN/age2_x1.icd

# A batch (3 parallel by default; --max-parallel to change)
.venv/bin/python scripts/agy/orchestrate.py batch.yml
```

Batch file:

```yaml
name: first-pass
max_parallel: 3
tasks:
  - id: binary
    profile: binary-analysis
    inputs: {binary: orig/AGE2_X1_1_0C_EN/age2_x1.icd}
  - id: notes
    profile: doc-draft
    inputs: {topic: PC binary layout, target: docs/drafts/pc_layout.md, findings: "..."}
    depends_on: [binary]
```

A task whose dependency is not `done` is marked `failed` with the reason. A
dependency cycle is reported as `failed`, not left hanging.

The `agy` executable is taken from `--agy-bin`, then `$AGY_BIN`, then `PATH`.

## Verification

- `tests/test_agy_delegate.py` uses a fake agy (`tests/agy_stub.py`) and a
  temporary git repository. It covers profile and schema validation, input
  rejection, read-only and write scope, the main checkout guard, timeouts, bad
  exit and status, idempotent reruns, the promotion checks, and batch ordering
  and dependency failure. It needs no network.
- Run it with `.venv/bin/python -m pytest tests` and lint with
  `.venv/bin/flake8 scripts/agy tests`.

## Cleaning up

A run's worktree is kept until it has been inspected. After integrating or
discarding a result:

```sh
git worktree remove .worktrees/agy-<key>
git branch -D agy-<key>
```

The `build/agy/` directory is ignored by git through `build/`.
