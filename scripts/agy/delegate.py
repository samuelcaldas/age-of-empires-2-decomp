"""Run one agy task profile in its own worktree and record what happened.

Usage (from the main checkout):

    python scripts/agy/delegate.py --task binary-analysis \
        --input binary=orig/AGE2_X1_1_0C_EN/age2_x1.icd

Every run is validated first, then executed in `.worktrees/agy-<key>`. The
main checkout is watched before and after, and the worktree is checked
against the profile's writes list. A completed run with the same key is
reused, so repeating a task does no work twice.

Exit status: 0 when the run is `done`, 1 for `failed` or `rejected`, 2 for
errors detected before anything ran.
"""

import argparse
import json
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path

from agy_client import DEFAULT_GRACE_SECONDS, build_command, resolve_agy, run_agy
from errors import AgyDelegationError, InputError
from guard import diff_snapshots, main_checkout_snapshot, worktree_changes
from profiles import Profile, load_profile
from promote import PromotionError, load_allowed_prefixes, promote_official_binary
from run_store import make_run_key, read_json, run_directory, write_json
from task_inputs import ResolvedInput, input_directories, input_fingerprint, render_text, resolve_inputs
from verdict import DONE, FAILED, Verdict, judge
from worktree import MAIN_LOCK_NAME, create_worktree, file_lock, head_sha

POST_STEPS = frozenset({"fetch-official"})


@dataclass(frozen=True)
class RunPlan:
    """Everything decided before the model is called. Its key identifies the work."""

    repo_root: Path
    profile: Profile
    inputs: list[ResolvedInput]
    prompt: str
    writes: tuple[str, ...]
    key: str
    timeout_seconds: int
    grace_seconds: int
    agy_bin: str

    @property
    def worktree_name(self) -> str:
        """Name of the worktree and of its branch."""
        return f"agy-{self.key}"

    def input_value(self, name: str) -> str:
        """Return the value of the named input. Raises InputError when it is absent."""
        for item in self.inputs:
            if item.name == name:
                return item.value
        raise InputError(f"{self.profile.name}: input '{name}' was not provided")


def run_task(
    repo_root: Path,
    profile_name: str,
    raw_inputs: dict[str, str],
    agy_bin: str | None = None,
    timeout_seconds: int | None = None,
    grace_seconds: int = DEFAULT_GRACE_SECONDS,
) -> dict:
    """Validate, then run (or reuse) one task. Returns the result record.

    Raises:
        AgyDelegationError: the profile, inputs, or agy executable are invalid.
            Nothing has been run or written when this is raised.
    """
    agy = resolve_agy(agy_bin)
    profile = load_profile(profile_name)
    inputs = resolve_inputs(profile, raw_inputs, repo_root)
    plan = _build_plan(repo_root, profile, inputs, agy, timeout_seconds, grace_seconds)
    stored = _reusable_result(plan)
    if stored is not None:
        return stored
    return _execute(plan)


def _build_plan(
    repo_root: Path,
    profile: Profile,
    inputs: list[ResolvedInput],
    agy: str,
    timeout_seconds: int | None,
    grace_seconds: int,
) -> RunPlan:
    timeout = timeout_seconds or profile.timeout_seconds
    if timeout <= 0:
        raise InputError("timeout must be a positive number of seconds")
    writes = tuple(render_text(pattern, inputs) for pattern in profile.writes)
    prompt = render_text(profile.prompt, inputs) + "\n\n" + _scope_note(writes)
    key = make_run_key(profile, prompt, input_fingerprint(inputs), timeout)
    return RunPlan(repo_root, profile, inputs, prompt, writes, key, timeout, grace_seconds, agy)


def _scope_note(writes: tuple[str, ...]) -> str:
    if not writes:
        return "Scope: read-only. Do not create, change, or delete any file in the repository."
    return "Scope: you may write only to these paths: " + ", ".join(writes) + "."


def _reusable_result(plan: RunPlan) -> dict | None:
    stored = read_json(run_directory(plan.repo_root, plan.key) / "result.json")
    if stored is None or stored.get("state") != DONE:
        return None
    return {**stored, "reused": True}


def _execute(plan: RunPlan) -> dict:
    run_dir = run_directory(plan.repo_root, plan.key)
    (run_dir / "prompt.md").write_text(plan.prompt, encoding="utf-8")
    base = head_sha(plan.repo_root)
    _write_meta(plan, run_dir, base, {"state": "running"})
    worktree, run, before, after = _run_in_worktree(plan, base)
    changes = worktree_changes(worktree, base)
    (run_dir / "stdout.log").write_text(run.stdout, encoding="utf-8")
    verdict = judge(plan.profile, plan.writes, run, changes, diff_snapshots(before, after))
    promoted = None
    if verdict.state == DONE and plan.profile.name in POST_STEPS:
        verdict, promoted = _promote(plan, worktree, verdict)
    return _finish(plan, run_dir, base, worktree, changes, verdict, promoted)


def _run_in_worktree(plan: RunPlan, base: str):
    """Run agy in a fresh worktree. The shared lock keeps promotions out of the window."""
    with file_lock(plan.repo_root, MAIN_LOCK_NAME, exclusive=False):
        worktree = create_worktree(plan.repo_root, plan.worktree_name, base)
        command = _command(plan, run_directory(plan.repo_root, plan.key))
        before = main_checkout_snapshot(plan.repo_root)
        run = run_agy(command, worktree, plan.timeout_seconds, plan.grace_seconds)
        after = main_checkout_snapshot(plan.repo_root)
    return worktree, run, before, after


def _command(plan: RunPlan, run_dir: Path) -> list[str]:
    return build_command(
        plan.agy_bin,
        plan.profile,
        plan.prompt,
        run_dir / "agy.log",
        input_directories(plan.inputs),
        plan.timeout_seconds,
    )


def _promote(plan: RunPlan, worktree: Path, verdict: Verdict) -> tuple[Verdict, str | None]:
    try:
        with file_lock(plan.repo_root, MAIN_LOCK_NAME, exclusive=True):
            target = promote_official_binary(
                plan.repo_root,
                worktree,
                plan.input_value("version"),
                plan.input_value("expected_sha1"),
                verdict.output,
                load_allowed_prefixes(),
            )
    except PromotionError as error:
        failed = Verdict(FAILED, [str(error)], verdict.output, verdict.conversation_id, verdict.usage)
        return failed, None
    return verdict, str(target)


def _finish(
    plan: RunPlan,
    run_dir: Path,
    base: str,
    worktree: Path,
    changes: list[str],
    verdict: Verdict,
    promoted: str | None,
) -> dict:
    result = {
        "profile": plan.profile.name,
        "key": plan.key,
        "state": verdict.state,
        "reasons": verdict.reasons,
        "output": verdict.output,
        "changed_files": changes,
        "promoted_to": promoted,
        "reused": False,
        "run_dir": str(run_dir),
        "worktree": str(worktree),
        "branch": plan.worktree_name,
        "base_sha": base,
        "conversation_id": verdict.conversation_id,
        "usage": verdict.usage,
    }
    write_json(run_dir / "result.json", result)
    _write_meta(plan, run_dir, base, {"state": verdict.state, "changed_files": changes, "diff_stat": _diff_stat(worktree, base)})
    return result


def _write_meta(plan: RunPlan, run_dir: Path, base: str, extra: dict) -> None:
    meta = {
        "profile": plan.profile.name,
        "key": plan.key,
        "model": plan.profile.model,
        "effort": plan.profile.effort,
        "mode": plan.profile.mode,
        "timeout_seconds": plan.timeout_seconds,
        "read_only": plan.profile.is_read_only,
        "writes": list(plan.writes),
        "inputs": input_fingerprint(plan.inputs),
        "base_sha": base,
        "branch": plan.worktree_name,
        **extra,
    }
    write_json(run_dir / "meta.json", meta)


def _diff_stat(worktree: Path, base: str) -> str:
    result = subprocess.run(
        ["git", "diff", "--stat", base],
        cwd=worktree,
        capture_output=True,
        text=True,
        check=False,
    )
    return result.stdout.strip()


def detect_repo_root() -> Path:
    """Return the top of the git checkout containing the current directory."""
    result = subprocess.run(
        ["git", "rev-parse", "--show-toplevel"],
        capture_output=True,
        text=True,
        check=False,
    )
    if result.returncode != 0:
        raise InputError("not inside a git checkout; pass --repo")
    return Path(result.stdout.strip())


def parse_inputs(pairs: list[str]) -> dict[str, str]:
    """Turn `name=value` strings into a dict. Raises InputError on a missing '='."""
    parsed = {}
    for pair in pairs:
        name, separator, value = pair.partition("=")
        if not separator or not name:
            raise InputError(f"--input must look like name=value, got {pair!r}")
        parsed[name] = value
    return parsed


def _parse_args(argv: list[str] | None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run one agy task profile.")
    parser.add_argument("--task", required=True, help="profile name, e.g. binary-analysis")
    parser.add_argument("--input", action="append", default=[], metavar="NAME=VALUE")
    parser.add_argument("--repo", type=Path, help="repository root (default: git top level)")
    parser.add_argument("--agy-bin", help="agy executable (default: $AGY_BIN or PATH)")
    parser.add_argument("--timeout", type=int, help="override the profile timeout, in seconds")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Command-line entry point. Returns the process exit status."""
    args = _parse_args(argv)
    try:
        result = run_task(
            args.repo or detect_repo_root(),
            args.task,
            parse_inputs(args.input),
            args.agy_bin,
            args.timeout,
        )
    except AgyDelegationError as error:
        print(f"error: {error}", file=sys.stderr)
        return 2
    print(json.dumps(result, indent=2, ensure_ascii=False))
    return 0 if result["state"] == DONE else 1


if __name__ == "__main__":
    sys.exit(main())
