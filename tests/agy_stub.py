#!/usr/bin/env python3
"""Fake `agy` for tests. Its behaviour is chosen by environment variables.

AGY_STUB_LOG      file that receives one JSON line per invocation (the prompt)
AGY_STUB_ACTION   none | write | write_abs | commit | sleep | exit3
AGY_STUB_PATH     target of write / write_abs / commit (relative to cwd, or absolute)
AGY_STUB_CONTENT  text written by write / write_abs / commit (default "x")
AGY_STUB_OUTPUT   JSON for structured_output, or "none" to omit it (default "{}")
AGY_STUB_STATUS   value of the envelope status field (default SUCCESS)
"""

import json
import os
import subprocess
import sys
import time
from pathlib import Path


def main() -> int:
    args = sys.argv[1:]
    prompt = args[args.index("-p") + 1]
    _log(prompt)
    _act(os.environ.get("AGY_STUB_ACTION", "none"))
    if os.environ.get("AGY_STUB_ACTION") == "exit3":
        return 3
    print(json.dumps(_envelope()))
    return 0


def _log(prompt: str) -> None:
    log_path = os.environ.get("AGY_STUB_LOG")
    if log_path:
        with open(log_path, "a", encoding="utf-8") as handle:
            handle.write(json.dumps({"prompt": prompt, "cwd": os.getcwd()}) + "\n")


def _act(action: str) -> None:
    if action == "sleep":
        time.sleep(30)
    elif action in ("write", "write_abs"):
        _write(Path(os.environ["AGY_STUB_PATH"]))
    elif action == "commit":
        _write(Path(os.environ["AGY_STUB_PATH"]))
        _commit()


def _write(path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(os.environ.get("AGY_STUB_CONTENT", "x"), encoding="utf-8")


def _commit() -> None:
    subprocess.run(["git", "add", "-A"], check=True)
    subprocess.run(
        ["git", "-c", "user.name=stub", "-c", "user.email=stub@example.invalid", "commit", "-q", "-m", "stub commit"],
        check=True,
    )


def _envelope() -> dict:
    envelope = {
        "conversation_id": "stub-conversation",
        "status": os.environ.get("AGY_STUB_STATUS", "SUCCESS"),
        "response": "stub response",
        "usage": {"input_tokens": 1, "output_tokens": 1},
    }
    output = os.environ.get("AGY_STUB_OUTPUT", "{}")
    if output != "none":
        envelope["structured_output"] = json.loads(output)
    return envelope


if __name__ == "__main__":
    sys.exit(main())
