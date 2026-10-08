"""Detect what an agy run changed, and reject changes the profile did not allow.

The model cannot be trusted to respect its prompt or `--mode`: a probe showed
that `--mode plan --sandbox` still lets the model create files. So the
wrapper checks after the fact in three places:

1. The worktree: every changed or ignored path must match the profile's
   `writes` list (empty list means read-only, so any change is a violation).
2. The main checkout: snapshotted before and after the run. Writes from the
   model that land outside the worktree show up as differences.
3. Ignored but important trees (`orig/`, `config/`): git status does not list
   them, so they are compared by size and mtime.
"""

import os
from fnmatch import fnmatchcase
from pathlib import Path

from worktree import git

WATCHED_IGNORED_DIRS = ("orig", "config")
EXCLUDED_PREFIXES = (".worktrees/", "build/")
PORCELAIN_FLAGS = ("status", "--porcelain=v1", "-z", "--untracked-files=all", "--no-renames")


def main_checkout_snapshot(repo_root: Path) -> dict[str, str]:
    """Return a fingerprint for each relevant path in the main checkout."""
    snapshot = {}
    for code, path in _status_entries(repo_root, "--ignored=no"):
        if not _is_excluded(path):
            snapshot[path] = f"{code}:{_stat_token(repo_root / path)}"
    for directory in WATCHED_IGNORED_DIRS:
        snapshot.update(_stat_tree(repo_root, directory))
    return snapshot


def diff_snapshots(before: dict[str, str], after: dict[str, str]) -> list[str]:
    """Return the paths whose fingerprint differs between two snapshots, sorted."""
    changed = set(before) ^ set(after)
    changed |= {path for path in before.keys() & after.keys() if before[path] != after[path]}
    return sorted(changed)


def worktree_changes(worktree: Path, base_sha: str) -> list[str]:
    """Return every path the worktree differs from `base_sha`, including ignored ones.

    Committed changes count too, so a commit made by the model is still seen.
    """
    tracked = git(worktree, "diff", "--name-only", base_sha).splitlines()
    untracked = [path for code, path in _status_entries(worktree, "--ignored=matching") if code in ("??", "!!")]
    return sorted(set(tracked) | set(untracked))


def disallowed_paths(paths: list[str], writes: tuple[str, ...]) -> list[str]:
    """Return the paths not covered by any `writes` pattern. Empty `writes` covers nothing."""
    return [path for path in paths if not any(fnmatchcase(path, pattern) for pattern in writes)]


def _status_entries(cwd: Path, *extra: str) -> list[tuple[str, str]]:
    output = git(cwd, *PORCELAIN_FLAGS, *extra)
    entries = [entry for entry in output.split("\0") if entry]
    return [(entry[:2], entry[3:]) for entry in entries]


def _is_excluded(path: str) -> bool:
    return path.startswith(EXCLUDED_PREFIXES)


def _stat_tree(repo_root: Path, directory: str) -> dict[str, str]:
    root = repo_root / directory
    if not root.is_dir():
        return {}
    found = {}
    for current, _, names in os.walk(root):
        for name in names:
            full = Path(current) / name
            found[full.relative_to(repo_root).as_posix()] = _stat_token(full)
    return found


def _stat_token(path: Path) -> str:
    if not path.exists():
        return "missing"
    info = path.stat()
    return f"{info.st_size}:{info.st_mtime_ns}"
