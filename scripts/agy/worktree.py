"""Git worktrees for agy runs, plus file locks that serialize shared state.

Every run gets its own worktree at `.worktrees/agy-<key>` on branch
`agy/<key>`. Creating a worktree takes an exclusive lock, because concurrent
`git worktree add` calls contend on `.git`. Runs also hold a shared lock on
the main checkout, so a promotion (which writes into the main checkout) waits
until no run is observing it.
"""

import fcntl
import shutil
import subprocess
from contextlib import contextmanager
from pathlib import Path
from typing import Iterator

from run_store import RUNS_SUBDIR

WORKTREES_SUBDIR = Path(".worktrees")
WORKTREE_LOCK_NAME = ".worktree.lock"
MAIN_LOCK_NAME = ".main.lock"


def git(cwd: Path, *args: str) -> str:
    """Run `git` with `args` in `cwd` and return stdout. Raises on failure."""
    result = subprocess.run(
        ["git", *args],
        cwd=cwd,
        capture_output=True,
        text=True,
        check=False,
    )
    if result.returncode != 0:
        raise RuntimeError(f"git {' '.join(args)} failed in {cwd}: {result.stderr.strip()}")
    return result.stdout


def head_sha(repo_root: Path) -> str:
    """Return the full SHA of HEAD in the main checkout."""
    return git(repo_root, "rev-parse", "HEAD").strip()


def worktree_path(repo_root: Path, name: str) -> Path:
    """Return where the worktree called `name` lives."""
    return repo_root / WORKTREES_SUBDIR / name


@contextmanager
def file_lock(repo_root: Path, lock_name: str, exclusive: bool) -> Iterator[None]:
    """Hold an advisory lock on `build/agy/<lock_name>` for the block."""
    lock_dir = repo_root / RUNS_SUBDIR
    lock_dir.mkdir(parents=True, exist_ok=True)
    mode = fcntl.LOCK_EX if exclusive else fcntl.LOCK_SH
    with (lock_dir / lock_name).open("w") as handle:
        fcntl.flock(handle, mode)
        try:
            yield
        finally:
            fcntl.flock(handle, fcntl.LOCK_UN)


def create_worktree(repo_root: Path, name: str, base_sha: str) -> Path:
    """Create a fresh worktree `name` at `base_sha`, replacing any leftover one.

    The branch is named after the worktree. A leftover branch or directory
    from an earlier failed attempt is removed first, since the run key
    guarantees it belongs to the same work.
    """
    with file_lock(repo_root, WORKTREE_LOCK_NAME, exclusive=True):
        _discard_leftovers(repo_root, name)
        path = worktree_path(repo_root, name)
        git(repo_root, "worktree", "add", "-b", name, str(path), base_sha)
    return path


def remove_worktree(repo_root: Path, name: str) -> None:
    """Remove the worktree `name` and its branch, if they exist."""
    with file_lock(repo_root, WORKTREE_LOCK_NAME, exclusive=True):
        _discard_leftovers(repo_root, name)


def _discard_leftovers(repo_root: Path, name: str) -> None:
    path = worktree_path(repo_root, name)
    if path.exists():
        _remove_registered_or_orphaned(repo_root, path)
    if _branch_exists(repo_root, name):
        git(repo_root, "branch", "-D", name)


def _remove_registered_or_orphaned(repo_root: Path, path: Path) -> None:
    try:
        git(repo_root, "worktree", "remove", "--force", str(path))
    except RuntimeError:
        shutil.rmtree(path)
        git(repo_root, "worktree", "prune")


def _branch_exists(repo_root: Path, name: str) -> bool:
    result = subprocess.run(
        ["git", "show-ref", "--verify", "--quiet", f"refs/heads/{name}"],
        cwd=repo_root,
        check=False,
    )
    return result.returncode == 0
