"""Behavioral regression tests for trade_action_state_updates."""

from pathlib import Path
import subprocess

PROJECT_ROOT = Path(__file__).resolve().parent.parent


def test_trade_action_state_updates_native():
    """Compile and execute native behavioral test."""
    test_src = PROJECT_ROOT / "tests/native/trade_action_state_updates_test.cpp"
    bin_path = PROJECT_ROOT / "tests/native/trade_action_state_updates_test"
    cmd = [
        "g++", "-m32", "-O2", "-Iinclude",
        str(test_src),
        "-o", str(bin_path)
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"

    run_res = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert run_res.returncode == 0, f"Execution failed: {run_res.stderr}"
    assert "All tests passed successfully!" in run_res.stdout
    bin_path.unlink(missing_ok=True)
