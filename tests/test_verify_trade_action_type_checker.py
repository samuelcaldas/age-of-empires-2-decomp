"""Unit tests for tools/verify_trade_action_type_checker.py."""

from pathlib import Path
import subprocess
import sys

import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]
VERIFY_SCRIPT = PROJECT_ROOT / "tools" / "verify_trade_action_type_checker.py"


def test_verify_trade_action_type_checker_passes():
    """Verify that the robust ELF relocation matcher exits 0 and reports 160/160 match."""
    res = subprocess.run(
        [sys.executable, str(VERIFY_SCRIPT)],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
    )
    assert res.returncode == 0, f"Verifier failed:\nstdout:\n{res.stdout}\nstderr:\n{res.stderr}"
    assert "SUCCESS: Exact 100.0% byte-for-byte match (160/160 bytes identical)!" in res.stdout
    assert "func_002B90A0: section=5, size=144 bytes" in res.stdout
    assert "func_002B9130: section=9, size=8 bytes" in res.stdout
    assert "Padding to 160 bytes: 8 bytes" in res.stdout
