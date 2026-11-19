"""Behavioral tests for the commit and push step of scripts/ralph_decomp.sh (against a local bare remote)."""

from __future__ import annotations

import shutil
import subprocess
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "ralph_decomp.sh"


def _git(cwd: Path, *args: str) -> str:
    done = subprocess.run(["git", "-C", str(cwd), "-c", "user.name=t", "-c", "user.email=t@t", *args],
                          check=True, capture_output=True, text=True)
    return done.stdout


def _shell(cwd: Path, script: str, env_extra: dict | None = None) -> subprocess.CompletedProcess:
    env = {"PATH": "/usr/bin:/bin", "RALPH_LIB_ONLY": "1", "HOME": str(cwd),
           "GIT_AUTHOR_NAME": "t", "GIT_AUTHOR_EMAIL": "t@t", "GIT_COMMITTER_NAME": "t",
           "GIT_COMMITTER_EMAIL": "t@t", **(env_extra or {})}
    return subprocess.run(["bash", "-c", f"source scripts/ralph_decomp.sh; {script}"], cwd=cwd, env=env,
                          capture_output=True, text=True)


@pytest.fixture
def remote(tmp_path):
    """A bare origin and two clones of it. ``work`` runs the loop; ``other`` pushes elsewhere."""
    origin = tmp_path / "origin.git"
    subprocess.run(["git", "init", "-q", "--bare", "-b", "main", str(origin)], check=True)
    seed = tmp_path / "seed"
    subprocess.run(["git", "init", "-q", "-b", "main", str(seed)], check=True)
    (seed / "README").write_text("seed\n")
    _git(seed, "add", "README")
    _git(seed, "commit", "-q", "-m", "seed")
    _git(seed, "remote", "add", "origin", str(origin))
    _git(seed, "push", "-q", "origin", "main")
    work = tmp_path / "work"
    subprocess.run(["git", "clone", "-q", str(origin), str(work)], check=True)
    other = tmp_path / "other"
    subprocess.run(["git", "clone", "-q", str(origin), str(other)], check=True)
    (work / "scripts").mkdir()
    shutil.copy(SCRIPT, work / "scripts" / "ralph_decomp.sh")
    shutil.copy(ROOT / "scripts" / "ralph_slice.py", work / "scripts" / "ralph_slice.py")
    (work / ".venv").symlink_to(ROOT / ".venv")
    return origin, work, other


def _origin_log(origin: Path) -> list[str]:
    return _git(origin, "log", "--format=%s", "main").splitlines()


def _local_commit(repo: Path, name: str) -> None:
    (repo / name).write_text(name + "\n")
    _git(repo, "add", name)
    _git(repo, "commit", "-q", "-m", f"add {name}")


def test_publish_pushes_local_commits_to_origin(remote):
    origin, work, _ = remote
    _local_commit(work, "a.txt")
    result = _shell(work, "publish_commits")
    assert result.returncode == 0, result.stderr
    assert _origin_log(origin)[0] == "add a.txt"


def test_publish_rebases_onto_moved_origin_before_pushing(remote):
    origin, work, other = remote
    _local_commit(other, "theirs.txt")
    _git(other, "push", "-q", "origin", "main")
    _local_commit(work, "mine.txt")
    result = _shell(work, "publish_commits")
    assert result.returncode == 0, result.stderr
    assert _origin_log(origin)[:2] == ["add mine.txt", "add theirs.txt"]


def test_publish_is_skipped_when_disabled(remote):
    origin, work, _ = remote
    _local_commit(work, "b.txt")
    result = _shell(work, "publish_commits", {"RALPH_PUSH": "0"})
    assert result.returncode == 0
    assert _origin_log(origin) == ["seed"]


def test_rebase_conflict_aborts_and_pushes_nothing(remote):
    origin, work, other = remote
    (other / "same.txt").write_text("theirs\n")
    _git(other, "add", "same.txt")
    _git(other, "commit", "-q", "-m", "theirs same")
    _git(other, "push", "-q", "origin", "main")
    (work / "same.txt").write_text("mine\n")
    _git(work, "add", "same.txt")
    _git(work, "commit", "-q", "-m", "mine same")
    result = _shell(work, "publish_commits")
    assert result.returncode != 0
    assert _origin_log(origin)[0] == "theirs same"
    assert not (work / ".git" / "rebase-merge").exists() and not (work / ".git" / "rebase-apply").exists()


def test_commit_promotion_commits_generated_message_and_publishes(remote):
    origin, work, _ = remote
    for path in ("src/kcet/func_00105428.cpp", "config/SLES-50282/config.yml",
                 "config/SLES-50282/symbols.txt", "configure.py"):
        (work / path).parent.mkdir(parents=True, exist_ok=True)
        (work / path).write_text("x\n")
    result = _shell(work, "commit_promotion func_00105428 0x105428 8 100.0 1 13 3 agy gemini")
    assert result.returncode == 0, result.stderr
    subject = _git(work, "log", "-1", "--format=%s").strip()
    assert subject == "decomp(ps2): match func_00105428 slice (0x00105428 - 0x00105430)"
    assert "Co-Authored-By: Claude Haiku 5.5" in _git(work, "log", "-1", "--format=%B")
    assert _origin_log(origin)[0] == subject
