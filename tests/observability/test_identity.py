"""Resolve shared state from Git, not from per-worktree build directories."""

from pathlib import Path
import subprocess

from scripts.observability.identity import resolve_repository


def git(path, *arguments):
    return subprocess.run(["git", "-C", str(path), *arguments], check=True,
                          capture_output=True, text=True).stdout.strip()


def make_repository(path):
    path.mkdir()
    git(path, "init", "-b", "main")
    git(path, "config", "user.name", "Fixture")
    git(path, "config", "user.email", "fixture@example.invalid")
    (path / "source.txt").write_text("original")
    git(path, "add", ".")
    git(path, "commit", "-m", "initial")
    return path


def test_worktrees_resolve_one_common_store(tmp_path):
    root = make_repository(tmp_path / "root")
    linked = tmp_path / "linked"
    git(root, "worktree", "add", "-b", "other", str(linked))
    first, second = resolve_repository(root), resolve_repository(linked)
    assert first.get("common_dir") == str(root / ".git")
    assert second.get("common_dir") == first["common_dir"]
    assert second["commit"] == git(root, "rev-parse", "HEAD")
    assert Path(second["root"]) == linked
