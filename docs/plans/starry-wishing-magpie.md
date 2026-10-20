# Global Decompilation Progress Watcher — Implementation Plan

## Context

The current observability tool verifies enrolled C/C++ slices and shows local status, but it has no global task feed or complete per-edition code denominator. It cannot yet truthfully show whole-edition percentages or a reliable finish estimate. This follow-on plan extends the already-merged observability system; it does not replace or revert that implementation.

The user requested a real-time global watcher for agent progress, percentage decompiled, and ETA from history. The user chose **four separate edition views**, with no combined cross-edition percentage: PC Conquerors 1.0c, PC AoK 2.0a, PS2 PAL SLES-50282, and PS2 NTSC-J SLPM-62076.

**Goal:** Provide a near-real-time view of explicit agent task states and verified decompilation progress per edition, enabling whole-edition percentage and ETA only after denominator/history audit gates pass.

**Architecture:** Extend the common-Git-directory SQLite store with a privacy-minimal, append-only task event stream. Add audited target-specific executable inventories and one projection that feeds JSON, terminal/tmux, and the static dashboard. Only exact C/C++ ranges with passing behavior evidence, bound to the same target/source tree and verified in the integrated first-parent history, count as decompiled. ETA uses comparable daily integrated byte deltas, not agent/commit counts.

**Tech stack:** Existing Python 3.14 CLI, SQLite, JSON Schema, Rich, static HTML/CSS/JavaScript/SVG, Node tests, and `docker-dev`.

**Spec:** User request and edition-scope decision from 2026-10-18. This file replaces the previous plan text at this path; all existing observability code remains as-is.

> **For agentic workers:** REQUIRED SUB-SKILL: Use `superpowers:executing-plans` task-by-task after approval. Follow repository Red–Green–Refactor rules and record evidence in an ignored task ledger.

## Global constraints

- Preserve the primary checkout and other contributors' changes, including untracked `docs/plans/purring-exploring-ritchie.md`; implement only in a dedicated isolated worktree. Sync only from a clean worktree. Never open a PR; do not push without a separate explicit request.
- Run builds/tests in `docker-dev`, with `TZ=America/Sao_Paulo`; use UTC for stored timestamps. Follow `docs/testing.md` TDD, baseline, regression, and static-check requirements. Missing dependencies are blockers, not RED evidence.
- No edits to decompiled functions or existing matching assertions. Do not edit upstream `tools/project.py` or import side-effectful `configure.py`.
- Report four edition metrics separately. Do not sum/average editions or deduplicate cross-edition shared code into a synthetic project percentage.
- The verified numerator is the unique union of exact-original C/C++ ranges with passing behavior and matching gates on the same source tree, integrated into that edition's target branch. Assembly, hand-coded instructions, stubs, semantic-only work, staged work, data, padding, third-party code without an explicit inclusion ruling, ambiguous ranges, and duplicates do not count.
- A whole-edition percentage requires a pinned target binary and a reviewed, complete in-scope code inventory. Unknown/unclassified code means global percentage and whole-edition ETA are unavailable. A partial audited-scope percentage must name that scope and must not be called whole-game progress.
- Task telemetry is opt-in and explicit. Do not infer active/completed work from sessions, worktrees, branches, commits, prompts, transcripts, or agy records. Never store prompts, transcripts, raw logs, raw session IDs, private paths, or unrestricted descriptions.
- The first release shares telemetry only among worktrees using the same `.git-common-dir`. Separate clones/machines require a later authenticated transport; do not imply global network aggregation.
- Public exports contain per-edition aggregates and bounded reason codes by default, never agent aliases or raw task events. No Pages configuration/deployment, public branch, hooks, CI permissions expansion, credentials, runner, or other remote writes without separate authorization.
- Preserve existing store data using additive versioned SQLite migrations. Keep new Python modules focused and below 200 lines.

## Current baseline and denominator blockers

- `scripts/observability/state.py::read_state()` reads snapshots/events/unfinished verification requests from `<git-common-dir>/observability/metrics.sqlite`; it is shared across worktrees of one clone only.
- `scripts/observability/projection.py::build_projection()` filters verified snapshots to the target first-parent history and unions registered exact ranges. `scripts/observability/history.py` calculates rates from comparable verified history only.
- `scripts/observability/verification.py` requires reviewed C++ eligibility and separate behavior/matching gates. The existing registry contains one 224-byte PAL serializer slice at `0x328020`, not a whole-target inventory.
- No general agent-task lifecycle telemetry exists. Session presence, native tests, branch names, source file sizes, or commit-message byte claims are not completion evidence.
- Current whole-target denominator blockers: PC Conquerors may use `age2_x1.icd`, not its pinned `age2_x1.exe` loader; AoK 2.0a has no pinned binary hash; the PAL ELF is stripped and its 4,075,488-byte LOAD range is not a code denominator; NTSC-J has no verified hash and only a placeholder split configuration.
- An edition may show bytes and a partial audited-scope ratio while these blockers remain, but its whole-edition percent/ETA must remain null with the blocker displayed.

## Review focus

1. Loader/binary ambiguity, unknown ranges, or incomplete inventory never produces a whole-edition percent/ETA (Task 1 tests).
2. Missing/expired heartbeat becomes stale/unknown, never active or completed (Tasks 2–3 tests).
3. A native/behavior pass without exact matching, or matching against a different tree, contributes zero verified bytes (Tasks 3–4 tests).
4. Branch names, merge commits, retries, squash/cherry-picks, and out-of-order events never double-count or falsely mark integration (Tasks 2 and 4 tests).
5. Missing daily observations, changed inventory/policy, stale state, or non-positive velocity yields an unavailable ETA, not zero work or an invented date (Task 5 tests).

## Metric and event contracts

### Per-edition metrics

For each target show separately:

- `verified_cpp_bytes`: unique, exact-matched, behavior-checked, integrated C/C++ bytes.
- `audited_code_bytes`: complete reviewed denominator for the named inventory revision.
- `whole_edition_percent`: `verified_cpp_bytes / audited_code_bytes * 100`, null unless binary identity and the complete in-scope inventory are approved.
- `audited_scope_percent`: optional partial ratio only with a clearly identified closed scope; never labeled whole-edition progress.
- `unknown_code_bytes`, reviewed excluded categories, inventory completeness/revision, binary hash and last audit.
- Task activity and staged bytes as separate panels; they never increase verified coverage.

The inventory classifies non-overlapping ranges as `game_engine`, `platform`, `third_party`, `loader`, `data`, `padding`, or `unknown`. Its policy explicitly states which code classes are in-scope. Third-party/runtime bytes are not silently discarded. Any unresolved executable range prevents claiming a complete edition denominator.

### Agent task events

Add schema-validated append-only events with: unique event ID, task/attempt IDs, configured local pseudonymous agent alias, edition, declared function/range reference, state, per-agent sequence, UTC timestamp, branch/base/candidate commit and tree when applicable, evidence refs, and bounded blocker code. Never store free-form prompts or test diagnostics.

State transitions: `queued`, `working`, `testing`, `behavior_passed`, `matching_passed`, `awaiting_integration`, `staged`, `integrated`, `blocked`, and `stale`. Behavior and matching gates stay distinct. Candidate-source changes invalidate earlier evidence. Integration requires first-parent target ancestry or an explicit, reviewed squash/cherry-pick tree mapping; branch naming alone is not integration.

Agents opt into the CLI protocol with `task start`, periodic `task heartbeat`, `task state`, and `task list`. Heartbeats default to 60 seconds and expire after five minutes; expiry means `stale/unknown`. A heartbeat reports activity only, not code progress. Existing sessions without published events remain unknown until they opt in.

### Velocity and ETA

Store one successful daily coverage observation per edition and comparison series. A no-change day is zero only when the observer recorded a successful current-tree observation; a missing observation is a gap. The comparison series binds binary SHA, inventory revision, target edition, verifier and policy revisions.

Require 14 complete comparable day-over-day deltas, current target/inventory validity, and fresh data for any ETA. Central ETA is remaining audited bytes divided by median daily net verified-byte rate. Show an observed scenario range only when its rates are positive, with sample window/count; it is observed variation, not a confidence interval. Include zero and negative deltas. No positive median, denominator gaps, stale data, or incompatible series means ETA unavailable. Distinguish ETA for the closed enrolled scope from ETA for the whole edition.

Historical backfill is allowed only from exact-match/behavior evidence tied to the historical source tree and binary. Git messages, nominal commit counts, source-file sizes, and tests existing in a commit do not prove historical matching or throughput.

## Existing interfaces to reuse

- `scripts/observability/store.py`, `database.py`, and `queue.py`: transactional shared SQLite state, leases, fencing, immutable verification snapshots.
- `scripts/observability/state.py::read_state()` and `load_projection()`: read-only local projection; extend with versioned task events and all-edition loading.
- `scripts/observability/projection.py::build_projection()`, `scripts/observability/ranges.py::union_code_bytes()`, and `scripts/observability/history.py`: preserve range union, first-parent integration, comparable rates, and unavailable reasons.
- `scripts/observability/verification.py` and `config/observability/registry.json`: source review and independently verified exact evidence, never infer from objdiff status flags.
- `scripts/observability/terminal.py` and `scripts/observability/web/*`: present the same projection, with no UI-side percentage/rate arithmetic.

## Implementation tasks

Follow Red–Green–Refactor for each behavior; run focused tests, related tests, full available suite, lint, and doc-link checks. Record command output. Keep the existing pilot and original assertions intact.

### Task 1 — Edition inventory and denominator readiness

**Files:** new `schemas/observability/target-inventory-v1.schema.json`, `config/observability/targets/<edition>.json`, `scripts/observability/inventory.py`; `tests/observability/test_inventory.py`.

- [ ] Define an inventory manifest with pinned original identity/hash, source binary path, segment hashes, disjoint address ranges, classification, inclusion decision, evidence, review identity, revision, completeness status, and unknown byte total.
- [ ] Test overlap/gap detection, unknown executable ranges, data/padding separation, wrong binary hash, unsupported target, and reject the 4,075,488-byte PAL LOAD range as a code denominator.
- [ ] Establish readiness gates for each edition: resolve Conquerors `.exe` vs `.icd`; pin AoK 2.0a original; classify PAL code/data/library/loader ranges; pin NTSC-J and replace placeholder inventory. Do not manufacture completion; an unaudited target stays unavailable.
- [ ] Keep the 224-byte serializer enrollment as a verified lower-bound fixture; do not expand the registry based on task telemetry.

### Task 2 — Additive task event store and state machine

**Files:** `database.py`, `store.py`, new `task_events.py`; task-event schema; `tests/observability/test_task_store.py`.

- [ ] Add a schema-versioned migration and append-only task event table without rewriting prior snapshots.
- [ ] Test concurrent writers from two worktrees sharing one common dir, event ID replay, per-agent sequence ordering, transaction rollback, restart, stale heartbeat expiry, and read-only inspection.
- [ ] Test legal/illegal state transitions; expiry produces stale/unknown, not done; no free text, raw logs, prompt text, session IDs, or absolute paths enter public records.
- [ ] Keep producer/task actor aliases explicitly configured and local; independent repositories are not silently merged.

### Task 3 — Opt-in task CLI and evidence-bound lifecycle

**Files:** `arguments.py`, `cli.py`, `task_events.py`, `CLAUDE.md`, `docs/observability.md`; `test_task_cli.py`, `test_task_lifecycle.py`.

- [ ] Add `task start --task-id --agent --edition --range --branch --base`, `task heartbeat --task-id`, `task state --task-id --state`, and `task list [--edition]`.
- [ ] Require task ranges to exist in the target inventory or be explicitly marked `unknown/proposed`; proposed ranges can show active activity but never increase coverage.
- [ ] Test malformed/overlapping/out-of-target ranges, event replay, invalid state changes, stale work, candidate SHA changes invalidating gate results, and blocked/staged states.
- [ ] Require the existing verifier to produce behavior and exact-match evidence bound to the same source tree; the task CLI cannot declare itself verified/integrated.
- [ ] Document adoption for future agents. Do not auto-message or scrape current sessions; tasks without events remain unknown.

### Task 4 — Four-edition global projection and inventory-safe percentage

**Files:** new `global_projection.py`, extend `projection.py` and `state.py`; `test_global_projection.py`.

- [ ] Load four separate target histories and inventories. Preserve current per-edition code/status and target-ready reasons.
- [ ] Count numerator from unique exact verified address ranges only after behavior and matching pass on the same pinned target; require integrated first-parent ancestry or reviewed tree mapping.
- [ ] Tests prove branch/staged/semantic-only/assembly/nonmatching/failed/duplicate/overlapping work contributes zero; four editions never pool or deduplicate each other's code.
- [ ] Return whole-edition percent only for complete audited inventories. If only an enrolled scope is closed, show a separate labeled scoped ratio and whole-edition unavailable reason.
- [ ] Handle instrumented lower-bound output, unknown ranges, inventory revision changes, stale refs, rewrites, squash mapping, and in-flight failed attempts without stale-green behavior.

### Task 5 — Daily historical observations, velocity, and ETA

**Files:** extend `history.py` and `global_projection.py`; daily rollup storage; `test_global_history.py`.

- [ ] Record at most one successful observation per UTC day and `(edition, binary SHA, inventory revision, policy revision)`. Distinguish observed zero delta from missing daily data.
- [ ] Test backfill rejection without tree/hash-bound evidence, changes of scope/binary, regressions, zero days, missing days, duplicate daily writes, and clock anomalies.
- [ ] Require 14 complete comparable daily deltas, closed denominator, positive median throughput, and fresh observation for ETA. Use median for central estimate; label any range as observed scenario variation, never as statistical confidence.
- [ ] Show scoped ETA separately from whole-edition ETA. If the inventory is incomplete, only the scoped ETA may be available.
- [ ] Do not infer velocity from commits/day, agent task counts, code-file sizes, heartbeats, or historical commit-message claims.

### Task 6 — Global CLI/tmux and static dashboard

**Files:** `arguments.py`, `cli.py`, `terminal.py`, `site.py`, `web/index.html`, `web/app.mjs`, `web/view_model.mjs`, `web/chart.mjs`; Python/Node tests.

- [ ] Add `status --all-editions [--json]` and `watch --all-editions --interval 5`. Poll the local shared store every five seconds and render four independent edition cards.
- [ ] Show audited denominator/completeness, verified exact bytes/percent, current target HEAD vs measured commit, active/stale task states, last update, daily speed, and scoped/full ETA with explicit unavailable reasons.
- [ ] Agent aliases/tasks show locally only; public Pages payload defaults to aggregate per-edition counts and metrics with no task aliases, raw event data, logs or private paths.
- [ ] Test JSON/terminal/site parity, NO_COLOR/resize/Ctrl+C, empty/stale/unavailable DB, two-worktree events, subpath URLs, malformed hostile payloads, accessibility/table fallback, no task-driven percentage, and no UI-side calculations.
- [ ] Keep Pages activation, public event publication, GitHub settings, and network deployment behind existing explicit authorization boundaries. Fix workflow fail-closed behavior before any later deployment.

### Task 7 — Adoption, docs, and rollout gate

**Files:** `docs/observability.md`, `docs/README.md`, `README.md`, `CLAUDE.md`; integration tests.

- [ ] Document each per-edition target status, binary/inventory blockers, verified-vs-task distinction, local clone sharing, event schema, TTL, ETA sample threshold, and commands for tmux.
- [ ] Run end-to-end with synthetic targets and the actual unchanged serializer exact-matching fixture. Synthetic data is always labeled fixture; never claim it is live.
- [ ] Run observability Python tests, Node tests, `flake8`, changed Markdown link checks, and the full available test suite in `docker-dev`; report all failures/skips/prerequisites against an unchanged baseline.
- [ ] Test migration on a copy of the existing DB and concurrent event production/read from multiple worktrees. Preserve local root untracked files and all other agents' work.
- [ ] Default output with all four incomplete inventories must show four unavailable whole-edition percentages and ETAs, verified bytes lower-bound, visible readiness blockers, and explicit active/stale task status.
- [ ] No GitHub push, Pages activation/deployment, global config, hook installation, or live event publication during implementation without separate authorization.

## Verification commands

Run only after plan approval and in an isolated worktree. Verify the checkout is mounted at the same path on the `docker-dev` daemon; use a private volume if not. Follow `docs/testing.md`.

```sh
docker --context docker-dev run --rm \
  -e TZ=America/Sao_Paulo \
  --mount "type=bind,source=$(pwd),target=/workspace" \
  aoe-tests:verification python -m pytest -q -ra tests/observability

docker --context docker-dev run --rm \
  -e TZ=America/Sao_Paulo \
  --mount "type=bind,source=$(pwd),target=/workspace" \
  aoe-tests:verification python -m flake8 scripts/observability tests/observability

docker --context docker-dev run --rm \
  --mount "type=bind,source=$(pwd),target=/workspace" \
  -w /workspace node:24-bookworm-slim node --test tests/observability/test_web.mjs
```

Verify daily series behavior with a frozen clock, event concurrency/migration on temporary Git repos/worktrees, consistent per-edition JSON/terminal/web output, `git diff --check`, and changed Markdown links. Do not run/modify other agents' tmux sessions.

## Honest rollout policy

The initial useful release can show opt-in active/stale tasks and the existing 224-byte verified lower bound. This is not a whole-game percentage. Whole-edition percentages remain unavailable until each target is pinned and its complete in-scope code denominator is audited. ETA remains unavailable until 14 comparable complete daily deltas exist under the same edition, binary, inventory and policy. Never replace these unavailable states with a guessed percentage/date.
