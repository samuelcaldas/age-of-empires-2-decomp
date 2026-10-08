"""Build and run one `agy -p` invocation with the profile's settings.

Two timeouts apply. `--print-timeout` asks agy to stop on its own. The
subprocess timeout is a backstop with a grace period, in case agy ignores its
own limit. Neither flag makes a run safe on its own; the guard checks the
result.
"""

import json
import os
import shutil
import subprocess
from dataclasses import dataclass
from pathlib import Path

from errors import AgyUnavailableError
from profiles import Profile

AGY_ENV_VAR = "AGY_BIN"
DEFAULT_GRACE_SECONDS = 120


@dataclass(frozen=True)
class AgyRun:
    """What came back from one agy process. `returncode` is None when killed."""

    returncode: int | None
    stdout: str
    timed_out: bool


def resolve_agy(explicit: str | None) -> str:
    """Return the agy executable from `explicit`, then $AGY_BIN, then PATH.

    Raises:
        AgyUnavailableError: no executable could be found.
    """
    candidate = explicit or _env_agy() or shutil.which("agy")
    if not candidate or shutil.which(candidate) is None:
        raise AgyUnavailableError("agy executable not found; set --agy-bin or $AGY_BIN")
    return candidate


def _env_agy() -> str | None:
    return os.environ.get(AGY_ENV_VAR) or None


def build_command(
    agy_bin: str,
    profile: Profile,
    prompt: str,
    log_path: Path,
    add_dirs: list[Path],
    timeout_seconds: int,
) -> list[str]:
    """Return the argv for one agy run. Never includes a dangerous-permissions flag."""
    command = [
        agy_bin,
        "-p",
        prompt,
        "--output-format",
        "json",
        "--model",
        profile.model,
        "--effort",
        profile.effort,
        "--mode",
        profile.mode,
        "--print-timeout",
        f"{timeout_seconds}s",
        "--json-schema",
        str(profile.schema_path),
        "--log-file",
        str(log_path),
    ]
    if profile.is_read_only:
        command.append("--sandbox")
    for directory in add_dirs:
        command.extend(["--add-dir", str(directory)])
    return command


def run_agy(command: list[str], cwd: Path, timeout_seconds: int, grace_seconds: int) -> AgyRun:
    """Run `command` in `cwd` and return its output, or a timed-out marker."""
    try:
        completed = subprocess.run(
            command,
            cwd=cwd,
            capture_output=True,
            text=True,
            timeout=timeout_seconds + grace_seconds,
            check=False,
        )
    except subprocess.TimeoutExpired:
        return AgyRun(returncode=None, stdout="", timed_out=True)
    return AgyRun(returncode=completed.returncode, stdout=completed.stdout, timed_out=False)


def parse_output(stdout: str) -> dict | None:
    """Parse agy's JSON envelope. Returns None when the text is not a JSON object."""
    try:
        parsed = json.loads(stdout)
    except json.JSONDecodeError:
        return None
    return parsed if isinstance(parsed, dict) else None
