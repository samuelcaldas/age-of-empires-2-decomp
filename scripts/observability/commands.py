"""Local commands; collection is explicit and never publishes automatically."""

import json
from pathlib import Path
import time

from rich.console import Console

from .collector import verify_revision
from .docker_executor import DockerExecutor
from .execution_inputs import request_fingerprint
from .identity import git_output, resolve_repository
from .state import load_projection
from .store import MetricsStore
from .terminal import render_terminal, watch_terminal


def _inputs(args, repository):
    return Path(args.inputs) if args.inputs else Path(repository["common_dir"]).parent


def enqueue_command(args):
    """Queue one exact commit/tree locally; explicit retry creates a new attempt."""
    repository = resolve_repository(args.repo)
    root = Path(repository["root"])
    commit = git_output(root, "rev-parse", args.commit + "^{commit}")
    request = dict(commit=commit, tree=git_output(root, "rev-parse", commit + "^{tree}"),
                   edition=args.version, profile=args.profile,
                   fingerprint=request_fingerprint(root, _inputs(args, repository)))
    store = MetricsStore(repository["common_dir"])
    return store, store.enqueue(request, force=args.retry), repository


def _execute_claim(args, store, claim, repository):
    executor = DockerExecutor(repository["root"], _inputs(args, repository),
                              store.directory / "private", args.image)
    return verify_revision(claim, executor, store)


def verify_command(args):
    """Verify only the requested queue key, never steal another queued revision."""
    store, queued, repository = enqueue_command(args)
    claim = store.claim("explicit_verify", 900, key=queued["key"])
    if claim:
        return _execute_claim(args, store, claim, repository)
    results = [value for value in store.read_snapshots() if value["attempt_id"] == queued["attempt_id"]]
    return results[-1] if results else dict(state="running", attempt_id=queued["attempt_id"])


def work_command(args):
    """Process durable queued revisions in the foreground without any publication."""
    repository = resolve_repository(args.repo)
    store = MetricsStore(repository["common_dir"])
    while True:
        _work_once(args, store, repository)
        if args.once or not args.watch:
            return
        time.sleep(args.interval)


def _work_once(args, store, repository):
    claim = store.claim("foreground_worker", 900)
    if claim:
        print(json.dumps(_execute_claim(args, store, claim, repository), indent=2))


def status_command(args):
    """Print a read-only JSON or human view of exactly the shared projection."""
    projection = load_projection(args.repo, args.version)
    if args.json:
        print(json.dumps(projection, indent=2))
        return
    Console().print(render_terminal(projection))


def watch_command(args):
    """Display offline state until interrupted, without initializing the store."""
    resolve_repository(args.repo)
    watch_terminal(lambda: load_projection(args.repo, args.version), interval=args.interval,
                   once=args.once, no_color=args.no_color)
