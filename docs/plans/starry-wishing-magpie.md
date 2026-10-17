# Decompilation Observability Implementation Plan

## Context

Approved 2026-10-17 in this conversation. The original untracked copy in the shared main checkout disappeared during concurrent work; this worktree-owned execution copy preserves its decisions, completed-task briefs and remaining acceptance requirements. The full specification is the user's `/plan` request. Do not change decompiled functions or contact/reconfigure aoe1–aoe8/aoe-advisor.

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:executing-plans task-by-task. Track progress in this plan's ignored SDD ledger.

**Goal:** One offline-first source of commit-bound metrics for local JSON artifacts, tmux, static GitHub Pages and README SVGs.

**Architecture:** Audited pure-C++ ranges and independent behavioral/exact-matching checks produce immutable evidence; a common-Git-directory SQLite queue/store supports all worktrees. One projection handles ancestry, history/rates/ETA and every display. A strict allowlisted exporter separates local verification from opt-in GitHub publication.

**Tech Stack:** Python 3.14 Docker test image, argparse/sqlite3, jsonschema>=4,<5, Rich>=13,<15, HTML/CSS/JS/SVG, Node built-in tests, GitHub Actions/Pages.

**Spec:** Full user request and approved plan in the conversation, 2026-10-17. This recovery is a location change, not additional authorization or scope.

## Global constraints

- Preserve other contributors' dirty primary checkout, source/instruction/documentation changes and untracked docs/testing.md. Work only here, sync/rebase only when this worktree is clean, no PRs. No global settings/hooks, no original/compiler/dump/object commits.
- Builds/tests use docker-dev with TZ=America/Sao_Paulo; artifacts use UTC. Follow observed-assertion Red–Green–Refactor and docs/testing.md baseline/regression rules. Missing prerequisites/imports are blockers, not RED evidence.
- No GitHub writes, metrics-branch creation, Pages activation/deploy, commit-status writes or hook installation without subsequent explicit authorization. Demonstrate dry-run; publishing defaults to offline/no side effects.
- Origin is https://github.com/samuelcaldas/age-of-empires-2-decomp.git, main. Expected Pages path /age-of-empires-2-decomp/ is not a verified deployment. No runner installation, original/compiler upload, hosted matching claim or LLM polling.
- Only fresh exact original-code ranges from reviewed pure-C/C++ count. Exclude .s, asm in .cpp, manual instruction encodings, stubs, padding/data, ambiguous eligibility and duplicate/overlapping claims. Unknown global denominator means no global percent/ETA. LOAD size 4,075,488 is not a pure-code total.
- Distinguish branch/integrated, observed objdiff/verified ranges, behavioral/binary/full-suite gates, last attempt/last success, and unit matching/complete linked executable.
- Initial enrollment is one real serializer verifier: [0x328020,0x328100), 224 bytes, using existing native/mutation tests and exact matching test without altering them. Other objdiff units remain observed/unverified; the official metric is an audited lower bound, not exhaustive coverage.
- Do not edit upstream tools/project.py or import configure.py. Reuse its report format, not status flags/fuzzy percentages as proof. Follow existing atomic/hash/lock patterns without coupling to scripts/agy.
- New focused Python modules <200 lines; avoid broad generic managers. Store private logs separately; public schema recursively forbids extra fields and unrestricted diagnostics/paths.

## Review Focus

1. A failed newer attempt shows its own state and older success identity/age, never stale green as current.
2. Late old results, retries, merges and backfill cannot double count or roll latest backward.
3. Skips/xfails/missing phases/empty collection/process exit 0 alone cannot certify ranges.
4. Missing tools/mounts, racing inputs and dirty source claims are explicit blockers, not zero coverage or fake RED/GREEN evidence.
5. Public data is untrusted: schema limits, path/symlink defenses, no HTML/SVG injection or remote commands from payloads.

## Shared interfaces and policies

Implemented under scripts/observability/: strict model/schema/ranges/source policy; Git identity/staging; SQLite database/store/queue; registry, private pytest plugin, input fingerprints, Docker executor, snapshot/collector and observed objdiff adapter. Store is <git-common-dir>/observability; snapshots are immutable and materialized atomically, private diagnostics separate. Worktrees share producer ID/attempt sequence and exclusive leased claims with fencing. No fixed temporary filename.

Use build_projection(snapshots, graph, now) for all arithmetic. Graph includes first-parent main history, current HEAD and approved epoch/anchor; timestamps are observation time, not commit order. Branch commits are nonofficial and their matching does not certify a later merge tree. Keep latest_attempt, latest_successful_measurement, head_commit and measured_commit separate. Failed measurements have null coverage; old success is explicitly historical. Reject rewritten history until explicit epoch reset; no automatic cross-producer ordering by clock.

Rates use comparable net unique-byte deltas across complete 24-hour/7-day windows, endpoints within one-hour observation tolerance and actual elapsed time. Preserve regressions; no commit counts/agent counts/double deliveries. Binary/policy/scope/denominator changes start another series. Registry expansion for existing source is backfill: remeasure comparable baseline or mark delta incomparable.

ETA needs a verified pure-code denominator, positive comparable rate and >=3 independent daily deltas. Remaining / median positive rate gives central; max/min positive rates give optimistic/conservative. Expose zero/negative days, actual period and scenario limitations; no fake confidence interval. Otherwise return explicit unavailable reasons. Current full-game ETA remains unavailable.

Planned commands: python -m scripts.observability enqueue --commit HEAD --version SLES-50282; verify --commit HEAD --version SLES-50282 --profile audited; work --watch --interval 5; status [--json]; watch --interval 5 [--no-color]; export --output build/observability/public; site --input build/observability/public --output build/observability/site; publish --dry-run (also default), and future-authorized publish --apply [--deploy]. Hooks enqueue offline only, never build/network/fail a commit; provide an example, do not install/overwrite existing hooks. Forced retries create a new attempt, not duplicate coverage. Agent telemetry is unknown/not configured in v1.

## Tasks

For each task write and observe the behavioral RED before minimal GREEN/refactor; record exact tests and all deviations in the ignored ledger. Run focused/related tests and the full available suite before final integration; compare failures with unchanged baseline. Commit only owned files at verified milestones.

### Task 1 — Strict contracts, audited ranges and source eligibility

**Files:** schemas/observability, model.py/ranges.py/source_policy.py, requirements.txt; tests/observability/test_contracts.py/test_ranges.py/test_source_policy.py.
**Interfaces:** validate_snapshot(data, public=True); union_code_bytes(ranges); function_count(ranges); classify_source(entry, checkout); reviewed closure digests.
- [ ] RED/GREEN strict schema/unsafe values, [100,140)+[120,160)=60 unique bytes, zero/one/many and invalid intervals, duplicate functions and conflicting ownership.
- [ ] RED/GREEN source suffix is not proof; asm/header/macro/manual directives excluded; changed review/unknown include/path escape blocked.
- [ ] Finish focused tests/lint and milestone commit. See existing task-1 brief/ledger for exact observed evidence.

### Task 2 — Worktree-shared store, attempt states and durable queue

**Files:** database.py/store.py/queue.py/identity.py/atomic.py and matching tests.
**Interfaces:** MetricsStore.enqueue/claim/complete/append_event/record_snapshot/read_events/read_snapshots; resolve_repository; write_atomic.
- [ ] RED/GREEN temporary repos/worktrees and multiprocessing: shared idempotent queue, monotonic sequences, exclusive claims, lease expiry recovery/fencing.
- [ ] RED/GREEN immutable snapshots, invalid records rejected, late completion preserved, interrupted atomic writes preserve old data and clean temporaries.
- [ ] Finish focused tests/lint and milestone commit. See task-2 brief/ledger.

### Task 3 — Real verification adapter and pilot enrollment

**Files:** verification.py/pytest_plugin.py/objdiff.py/registry.py/snapshot.py/collector.py/staging.py/execution_inputs.py/docker_executor.py, config/observability/registry.json, .dockerignore and tests.
**Interfaces:** collect_gate_results; assess_evidence; verify_revision(claim, executor, store); read_objdiff_report; immutable source capture and content/input fingerprints.
- [ ] RED/GREEN stale report/config flags/native-only/fuzzy/process success never certify exact bytes; all required node phases, original/tool/config/tree identities and source reviews must hold.
- [ ] RED/GREEN dirty/racing source and unavailable mounts/prerequisites blocked, assertions failed, partial/unregistered inventory diagnostic only. Public diagnostics are fixed codes.
- [ ] Enroll serializer unchanged. Privately mount original/compiler/wibo read-only; do not embed them in images. Keep source/config/test children read-only while allowing isolated Ninja root metadata (documented observed integration ruling).
- [ ] Run actual pilot through docker-dev or record precise blocker. Preserve previous failed attempts. Finish tests/lint/commit and record real outcome. See task-3 brief/ledger.

### Task 4 — One projection, history, velocity and ETA

**Files:** history.py/projection.py; tests/observability/test_history.py/test_projection.py.
**Interfaces:** build_projection(snapshots, graph, now); window_rate(history, hours); estimate_completion(history, denominator), schema-backed reason results.
- [ ] RED: out-of-order completions preserve newer first-parent commit; branch+merge and retries never double count; newer failure displays previous success as historical only.
- [ ] RED: rewrite blocks continuation, changed binary/policy/denominator/scope breaks series, registry backfill is not delivery, removals retain negative net deltas.
- [ ] RED: 100 bytes /24h =100/24 bytes/hour; duplicate observations unchanged; incomplete 24h/7d unavailable; cover one-hour tolerance, negative/zero and clock anomalies.
- [ ] RED: daily rates100,200,300 and600 remaining yield central3d/optimistic2d/conservative6d; unknown denominator or insufficient/invalid data gives no ETA.
- [ ] GREEN/refactor one projection with ancestry and explicit series; all contract/store/history tests and serialization round trips pass; commit.

### Task 5 — CLI, hook example and persistent terminal

**Files:** __main__.py/cli.py/terminal.py, hooks/observability/post-commit.example; test_cli.py/test_terminal.py/test_hook.py.
**Interfaces:** CLI uses store/projection; render_terminal(projection,width,color) renders only; watch read-only, work explicit executor.
- [ ] RED: commands, invalid inputs/intervals, absent repo, offline/JSON mode, HEAD vs measured, no inferred telemetry.
- [ ] RED: hook enqueue idempotent/offline and nonblocking; missing tool/store failures cannot fail commits; existing hooks not modified.
- [ ] RED: resize, NO_COLOR/non-TTY, empty/stale state, refresh failure, Ctrl+C safe.
- [ ] GREEN: implement documented commands, optional forced retry, five-second default refresh and worker. No automatic publication.
- [ ] Demonstrate one worker and watcher in a new owned tmux session, preserve other sessions; report missing prerequisites. Run suite/lint, commit.

### Task 6 — Allowlisted export, static site and SVG badges

**Files:** publication.py pure export, site.py, web/index.html/styles.css/app.mjs/view_model.mjs; test_export.py/test_site.py/test_web.mjs, Dockerfile.web.
**Interfaces:** make_public_bundle(snapshots,projection); build_site(bundle_dir,output_dir) -> exact file/digest manifest. Revalidate public schema.
- [ ] Invoke dataviz before chart/indicator implementation.
- [ ] RED: no raw logs/private paths/source/object/unknown extensions/symlinks/traversal in export; escape SVG/HTML, no script injection.
- [ ] RED: terminal/JSON/site/SVG agree on bytes/status/commit; unknown percent not0%; synthetic examples not live data.
- [ ] RED Node tests: relative /age-of-empires-2-decomp/ paths, nulls/malformed fetch/stale state/text-safe DOM; UI does not recompute rates.
- [ ] GREEN accessible light/dark static site, relative URLs, no backend/CDN/badge service; data/latest.json and bounded history; SVG bytes/state/measurement time+identity.
- [ ] Poll Pages15s with explicit error/stale/cache behavior; badge dates honest about static/cache lag. Local subpath HTTP/browser smoke; all screenshots in .playwright-mcp; report unavailable browser check honestly. Run suites/lint/commit.

### Task 7 — Opt-in GitHub transport and trusted Pages workflow

**Files:** github.py/publication.py; .github/workflows/observability-ci.yml/observability-pages.yml; test_publication.py/test_workflows.py.
**Interfaces:** plan_publication(bundle,repository) pure/offline; apply_publication(plan,transport,deploy) only explicit apply. Test with injected transport and disposable local bare remotes, no GitHub writes.
- [ ] RED: omitted flags/dry-run no network/writes; wrong repo, unpushed commit, invalid manifest/payload or epoch rejected; no credentials exported.
- [ ] GREEN dedicated decomp-metrics branch contains only sanitized immutable snapshots and canonical projection. Use temp isolated repo, bounded optimistic FF append/retry, no force push, no main metrics commits. Same ID/different content conflicts.
- [ ] RED/GREEN concurrent publishers and old results: preserve all records, recompute latest by trusted source first-parent graph and producer sequence, not arrival/time; prevent rollback; do not trust payload integration flags.
- [ ] --apply appends only; explicit --apply --deploy dispatches trusted default-branch Pages workflow. Retry dispatch without duplicate append. No real outward action during implementation.
- [ ] CI source push: read-only synthetic/schema/web checks, no originals/compilers/hosted matching/untrusted commands.
- [ ] Pages workflow_dispatch deploy boolean defaults false; fetch current metrics only as data with trusted source tooling, validate schema/manifest/source graph/projection/size, build/upload allowlisted artifact. Pin official actions immutably.
- [ ] Entire Pages fetch/build/deploy workflow in one concurrency group cancel-in-progress:false; re-read canonical metrics after acquiring it. Pending site refresh coalescing never drops verification/history. Preserve FF ledger/ancestry invariants; rewrites block. Only deploy job pages:write/id-token:write plus github-pages environment; reads contents:read. Never execute metrics-branch code.
- [ ] Optional separately enabled commit status decomp/local-verification with minimal permissions, local-provenance label and non-green failed/blocked results; no privileges for untrusted forks.
- [ ] Tests triggers/permissions/deploy=false/forged payload/out-of-order/dry-run receipts. Run suites/lint/commit.

### Task 8 — Documentation, baseline and E2E acceptance

**Files:** docs/observability.md, narrow README.md/docs/README.md edits and owned test/config refinements. Do not commit/modify another contributor's untracked docs/testing.md.
- [ ] Document trust/enrollment/denominator/freshness/history/epochs/shared store/private Docker prerequisites and remote bind-mount visibility.
- [ ] Replace stale bootstrap README with factual explanation, expected dashboard/SVG links marked pending activation, image cache/latency.
- [ ] Exact local/tmux commands, optional safe hook instructions and explicit publication activation. Manual GitHub Pages source/Actions permissions/environment/token setup; no runner install.
- [ ] Compare complete suite with unchanged isolated baseline under same prerequisites. Fix new failures, report every failure/skip and no weakened assertions.
- [ ] E2E: empty store unavailable; pure exact unique ranges consistent across outputs; actual pilot or blocker; shared concurrent queue+interruption+leases; newer failed attempt vs historical success; no duplicate/rollback on retries/merges/backfill; unknown denominator/sparse history no ETA; offline tmux/subpath site; dry-run/local bare remotes no GitHub mutations; full/static/docs results recorded.
- [ ] Fresh whole-branch reviewer; fix Important/Critical with observed RED/GREEN and suite, ledger Minor deferrals and all rulings. Do not merge into dirty main or publish without authorization.

## Verification commands

Use the private standard image aoe-observability:verification; build tests/Dockerfile through docker-dev. Bridge outbound networking timed out; host-network builds have been tested working, without host config changes. Remote daemon sees this worktree path; otherwise populate a dedicated private Docker volume, never assume client-local bind visibility.

- Focused RED/GREEN: docker --context docker-dev exec aoe-observability-tests python3 -m pytest -q -ra tests/observability/<test-file-or-node>
- Feature: same command with tests/observability.
- Lint: same container python3 -m flake8 scripts/observability tests/observability.
- Final full suite in newly built standard image: python -m pytest -q -ra, compare untouched baseline with identical assets.
- Web: private Node24 Docker stage, node --test tests/observability/test_web.mjs.
- git diff --check and changed Markdown link validation. Keep outputs in this plan's ignored workspace, not public payloads.

## Rollout boundary

Deliver code, tests, local artifacts/tmux/site demos, CI definitions and dry-run proof only. No GitHub push, metrics-branch creation, Pages deployment/activation, status write, hook installation or automatic network publication is authorized. The initial verified224-byte pilot is a truthful lower bound, not an exhaustive re-audit of all existing decompilation.
