# Testing and regression prevention

The mandatory red–green–refactor policy is in
[CLAUDE.md](../CLAUDE.md#mandatory-test-driven-development). `AGENTS.md` and
`GEMINI.md` link to that same file, so delegated agents share the policy.

## Test environment

Run builds and tests using the `docker-dev` context. Build the existing test
image from the repository root:

```sh
docker --context docker-dev build -f tests/Dockerfile -t aoe-tests:verification .
```

Run the full suite with a mounted checkout:

```sh
docker --context docker-dev run --rm \
  -e TZ=America/Sao_Paulo \
  --mount "type=bind,source=$(pwd),target=/workspace" \
  aoe-tests:verification python -m pytest -q -ra
```

For red and green iterations, replace the final command with a focused node ID,
for example:

```sh
python -m pytest -q -ra tests/test_unit_action_build_worker.py
```

Run that command inside the same test container, not on the host. Then expand to
the affected subsystem and finally the full suite. Tests can write build outputs
into the mounted checkout. Use an isolated checkout for baseline comparisons;
preserve other contributors' uncommitted changes. A bind mount is resolved on the
Docker daemon host: this example requires the checkout at the same path on that
host. Do not send `.env`, game binaries, or licensed compilers to a public runner.

Inspect the selected tests before running them. Some matching tests require
licensed compilers, original binaries, prebuilt objects, or platform-specific
paths beyond what `tests/Dockerfile` provides. Provision those prerequisites
privately. Record skips and missing prerequisites explicitly; a successful native
run does not establish target binary matching. Use the relevant slice's documented
matching command and preserve verified symbol boundaries, relocations, and hashes.

## Completion evidence

For each behavior changed, include:

- The regression test and the original behavior or analysis it checks.
- The red command and expected failure observed before implementation.
- The green command and result after implementation.
- Subsystem and full-suite results, including failure and skip counts.
- Target matching results for changed matched functions, or the precise blocker.

For a pure refactor, report characterization results before and after instead of
inventing a failing behavior. For a documentation-only change, run static checks
such as `git diff --check` and verify changed local Markdown links resolve.

If a test fails, determine whether the same failure occurs on the unchanged
baseline with identical prerequisites. Do not weaken assertions, silently exclude
tests, or label missing-tool failures as successful red evidence. Keep the
regression test permanently, and require the evidence above from delegated work.

## Enforcement boundary

These are repository instructions and completion gates for contributors and
agents, not an installed Git hook or a server-side merge restriction. A green
suite catches covered regressions but cannot prove test-first chronology or the
absence of untested bugs. No automatic hook, CI job, or remote branch protection
is installed by this policy.
