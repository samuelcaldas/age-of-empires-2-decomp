"""Run a batch of agy tasks in parallel, respecting `depends_on`.

Batch file (YAML):

    name: first-pass
    max_parallel: 3
    tasks:
      - id: binary
        profile: binary-analysis
        inputs: {binary: orig/AGE2_X1_1_0C_EN/age2_x1.icd}
      - id: notes
        profile: doc-draft
        inputs: {topic: PS2 binary layout, sources: build/agy/binary/result.json}
        depends_on: [binary]

Each task runs through `delegate.run_task`, so a task that already completed
with the same inputs is reused and not run again. The batch summary is kept
in `build/agy/batch-<id>/summary.json` and rewritten on every state change.
A task whose dependency did not finish as `done` is marked `failed`.

Usage: python scripts/agy/orchestrate.py batch.yml [--max-parallel N]

Exit status: 0 when every task is `done`, 1 otherwise, 2 for an invalid batch.
"""

import argparse
import hashlib
import json
import re
import sys
from concurrent.futures import FIRST_COMPLETED, Future, ThreadPoolExecutor, wait
from dataclasses import dataclass, field
from pathlib import Path

import yaml

from delegate import detect_repo_root, run_task
from errors import AgyDelegationError
from run_store import RUNS_SUBDIR, write_json
from verdict import DONE, FAILED, REJECTED

DEFAULT_MAX_PARALLEL = 3
MAX_PARALLEL_LIMIT = 8
TASK_ID_PATTERN = re.compile(r"^[a-z][a-z0-9-]*$")
QUEUED, RUNNING = "queued", "running"
BLOCKING_STATES = (FAILED, REJECTED)


class BatchError(AgyDelegationError):
    """The batch file is malformed: duplicate ids, unknown dependencies, bad limits."""


@dataclass
class TaskSpec:
    """One task from the batch file, validated."""

    task_id: str
    profile: str
    inputs: dict[str, str]
    depends_on: list[str]


@dataclass
class BatchSpec:
    """A validated batch file. `digest` identifies the batch content."""

    name: str
    max_parallel: int
    tasks: list[TaskSpec]
    digest: str


@dataclass
class BatchState:
    """Mutable progress of a running batch, written out as summary.json."""

    spec: BatchSpec
    limit: int
    summary_path: Path
    states: dict[str, str] = field(default_factory=dict)
    records: dict[str, dict] = field(default_factory=dict)


def load_batch(path: Path) -> BatchSpec:
    """Read and validate a batch file.

    Raises:
        BatchError: the file is not a valid batch definition.
    """
    raw_bytes = path.read_bytes()
    data = yaml.safe_load(raw_bytes) or {}
    if not isinstance(data, dict):
        raise BatchError("batch file top level must be a mapping")
    tasks = [_build_task(entry) for entry in data.get("tasks", [])]
    _check_tasks(tasks)
    return BatchSpec(
        name=str(data.get("name", path.stem)),
        max_parallel=_max_parallel(data.get("max_parallel", DEFAULT_MAX_PARALLEL)),
        tasks=tasks,
        digest=hashlib.sha256(raw_bytes).hexdigest()[:12],
    )


def _build_task(entry: object) -> TaskSpec:
    if not isinstance(entry, dict) or "id" not in entry or "profile" not in entry:
        raise BatchError("each task needs 'id' and 'profile'")
    task_id = str(entry["id"])
    if not TASK_ID_PATTERN.match(task_id):
        raise BatchError(f"invalid task id: {task_id!r}")
    return TaskSpec(
        task_id=task_id,
        profile=str(entry["profile"]),
        inputs={str(key): str(value) for key, value in (entry.get("inputs") or {}).items()},
        depends_on=[str(item) for item in entry.get("depends_on") or []],
    )


def _check_tasks(tasks: list[TaskSpec]) -> None:
    if not tasks:
        raise BatchError("batch has no tasks")
    ids = [task.task_id for task in tasks]
    if len(set(ids)) != len(ids):
        raise BatchError(f"duplicate task ids: {sorted({i for i in ids if ids.count(i) > 1})}")
    for task in tasks:
        unknown = [dep for dep in task.depends_on if dep not in ids]
        if unknown:
            raise BatchError(f"task {task.task_id} depends on unknown tasks {unknown}")


def _max_parallel(value: object) -> int:
    if not isinstance(value, int) or isinstance(value, bool) or not 1 <= value <= MAX_PARALLEL_LIMIT:
        raise BatchError(f"max_parallel must be an integer from 1 to {MAX_PARALLEL_LIMIT}")
    return value


def run_batch(repo_root: Path, batch: BatchSpec, agy_bin: str | None, max_parallel: int | None = None) -> dict:
    """Run every task in dependency order and return the final summary."""
    state = BatchState(
        spec=batch,
        limit=max_parallel or batch.max_parallel,
        summary_path=_summary_path(repo_root, batch),
        states={task.task_id: QUEUED for task in batch.tasks},
    )
    with ThreadPoolExecutor(max_workers=state.limit) as pool:
        _schedule(pool, repo_root, agy_bin, state)
    return _summary(state)


def _schedule(pool: ThreadPoolExecutor, repo_root: Path, agy_bin: str | None, state: BatchState) -> None:
    in_flight: dict[Future, str] = {}
    _save(state)
    while _unfinished(state) or in_flight:
        _block_tasks_with_failed_dependencies(state)
        _submit_ready(pool, repo_root, agy_bin, state, in_flight)
        if not in_flight:
            _fail_stalled(state)
            return
        finished, _ = wait(in_flight, return_when=FIRST_COMPLETED)
        for future in finished:
            _record(state, in_flight.pop(future), future)


def _unfinished(state: BatchState) -> bool:
    return any(value == QUEUED for value in state.states.values())


def _block_tasks_with_failed_dependencies(state: BatchState) -> None:
    for task in state.spec.tasks:
        if state.states[task.task_id] != QUEUED:
            continue
        blocker = next((dep for dep in task.depends_on if state.states[dep] in BLOCKING_STATES), None)
        if blocker is not None:
            _mark(state, task.task_id, FAILED, [f"dependency {blocker} is {state.states[blocker]}"])


def _submit_ready(pool: ThreadPoolExecutor, repo_root: Path, agy_bin: str | None, state: BatchState, in_flight: dict) -> None:
    for task in state.spec.tasks:
        if len(in_flight) >= state.limit:
            return
        if state.states[task.task_id] == QUEUED and _deps_done(task, state):
            state.states[task.task_id] = RUNNING
            in_flight[pool.submit(run_task, repo_root, task.profile, task.inputs, agy_bin)] = task.task_id
            _save(state)


def _deps_done(task: TaskSpec, state: BatchState) -> bool:
    return all(state.states[dep] == DONE for dep in task.depends_on)


def _record(state: BatchState, task_id: str, future: Future) -> None:
    try:
        result = future.result()
    except (AgyDelegationError, RuntimeError) as error:
        _mark(state, task_id, FAILED, [str(error)])
        return
    _mark(state, task_id, result["state"], result["reasons"], result)


def _mark(state: BatchState, task_id: str, new_state: str, reasons: list[str], result: dict | None = None) -> None:
    state.states[task_id] = new_state
    entry = state.records.setdefault(task_id, {})
    entry["reasons"] = reasons
    if result is not None:
        entry.update(_record_fields(result))
    _save(state)


def _record_fields(result: dict) -> dict:
    return {
        "profile": result["profile"],
        "run_dir": result["run_dir"],
        "reused": result["reused"],
        "changed_files": result["changed_files"],
        "promoted_to": result["promoted_to"],
    }


def _fail_stalled(state: BatchState) -> None:
    for task_id, value in state.states.items():
        if value == QUEUED:
            _mark(state, task_id, FAILED, ["unresolvable dependencies (cycle or blocked)"])


def _save(state: BatchState) -> None:
    write_json(state.summary_path, _summary(state))


def _summary_path(repo_root: Path, batch: BatchSpec) -> Path:
    directory = repo_root / RUNS_SUBDIR / f"batch-{batch.digest}"
    directory.mkdir(parents=True, exist_ok=True)
    return directory / "summary.json"


def _summary(state: BatchState) -> dict:
    tasks = {}
    for task in state.spec.tasks:
        entry = {"state": state.states[task.task_id], "reasons": []}
        entry.update(state.records.get(task.task_id, {}))
        tasks[task.task_id] = entry
    return {
        "batch": state.spec.name,
        "batch_id": state.spec.digest,
        "max_parallel": state.limit,
        "tasks": tasks,
    }


def _parse_args(argv: list[str] | None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run a batch of agy tasks.")
    parser.add_argument("batch", type=Path, help="batch YAML file")
    parser.add_argument("--max-parallel", type=int, help="override the batch's parallel limit")
    parser.add_argument("--agy-bin", help="agy executable (default: $AGY_BIN or PATH)")
    parser.add_argument("--repo", type=Path, help="repository root (default: git top level)")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Command-line entry point. Returns the process exit status."""
    args = _parse_args(argv)
    try:
        batch = load_batch(args.batch)
        summary = run_batch(args.repo or detect_repo_root(), batch, args.agy_bin, args.max_parallel)
    except (AgyDelegationError, OSError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 2
    print(json.dumps(summary, indent=2, ensure_ascii=False))
    return 0 if all(task["state"] == DONE for task in summary["tasks"].values()) else 1


if __name__ == "__main__":
    sys.exit(main())
