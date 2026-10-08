"""Shared fixtures: a throwaway git repository and a fake agy executable."""

import json
import subprocess
import sys
from pathlib import Path

import pytest

TESTS_DIR = Path(__file__).resolve().parent
AGY_DIR = TESTS_DIR.parent / "scripts" / "agy"
sys.path.insert(0, str(AGY_DIR))

GIT_IDENTITY = ["-c", "user.name=test", "-c", "user.email=test@example.invalid"]
GITIGNORE = "build/\n.worktrees/\norig/*/*\n!orig/*/.gitkeep\n"
BINARY_BYTES = b"MZ" + bytes(range(256)) * 4


def run_git(cwd: Path, *args: str) -> None:
    subprocess.run(["git", *GIT_IDENTITY, *args], cwd=cwd, check=True, capture_output=True)


@pytest.fixture
def repo(tmp_path: Path) -> Path:
    """A committed git repository laid out like the real project."""
    root = tmp_path / "repo"
    (root / "docs").mkdir(parents=True)
    (root / "orig" / "AGE2").mkdir(parents=True)
    (root / ".gitignore").write_text(GITIGNORE, encoding="utf-8")
    (root / "configure.py").write_text("# original\n", encoding="utf-8")
    (root / "docs" / "README.md").write_text("# docs\n", encoding="utf-8")
    (root / "orig" / "AGE2" / "age2.icd").write_bytes(BINARY_BYTES)
    run_git(root, "init", "-q", "-b", "main")
    run_git(root, "add", "-A")
    run_git(root, "commit", "-q", "-m", "initial")
    return root


@pytest.fixture
def fake_agy(tmp_path: Path, monkeypatch: pytest.MonkeyPatch) -> str:
    """An executable that runs tests/agy_stub.py with the current interpreter."""
    launcher = tmp_path / "agy"
    launcher.write_text(f'#!/bin/sh\nexec "{sys.executable}" "{TESTS_DIR / "agy_stub.py"}" "$@"\n', encoding="utf-8")
    launcher.chmod(0o755)
    log = tmp_path / "invocations.jsonl"
    monkeypatch.setenv("AGY_STUB_LOG", str(log))
    monkeypatch.setenv("AGY_STUB_ACTION", "none")
    monkeypatch.delenv("AGY_STUB_OUTPUT", raising=False)
    monkeypatch.delenv("AGY_STUB_STATUS", raising=False)
    monkeypatch.delenv("AGY_BIN", raising=False)
    return str(launcher)


def invocation_count(tmp_path: Path) -> int:
    """Return how many times the fake agy was started (one log line per start)."""
    log = tmp_path / "invocations.jsonl"
    if not log.exists():
        return 0
    return len(log.read_text(encoding="utf-8").splitlines())


def invocation_prompts(tmp_path: Path) -> list[str]:
    """Return the prompts the fake agy received, in order."""
    log = tmp_path / "invocations.jsonl"
    if not log.exists():
        return []
    return [json.loads(line)["prompt"] for line in log.read_text(encoding="utf-8").splitlines()]
