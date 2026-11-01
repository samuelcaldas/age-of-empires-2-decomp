import subprocess
from pathlib import Path
import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]

def test_tactical_ai_action_handler_340d70_native_behavior(tmp_path):
    out_bin = tmp_path / "tactical_ai_action_handler_340d70_test"
    cmd_compile = [
        "g++", "-m32", "-O2",
        f"-I{PROJECT_ROOT}/include",
        f"-I{PROJECT_ROOT}/tests/native",
        str(PROJECT_ROOT / "src/ai/tactical_ai_action_handler_340d70.cpp"),
        str(PROJECT_ROOT / "tests/native/tactical_ai_action_handler_340d70_test.cpp"),
        "-o", str(out_bin)
    ]
    res_compile = subprocess.run(cmd_compile, capture_output=True, text=True)
    assert res_compile.returncode == 0, f"Compilation failed: {res_compile.stderr}"

    res_run = subprocess.run([str(out_bin)], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
    assert "PASS test_field840_minus_one_returns_zero" in res_run.stdout
    assert "PASS test_cmd_255_calls_vfunc1c_and_returns_zero" in res_run.stdout
    assert "PASS test_cmd_11_sets_fields" in res_run.stdout
