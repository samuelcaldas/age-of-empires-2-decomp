import subprocess
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent

def test_unit_action_visibility():
    test_bin = REPO_ROOT / "build" / "tests" / "unit_action_visibility_test"
    test_bin.parent.mkdir(parents=True, exist_ok=True)

    src_file = REPO_ROOT / "src" / "unit" / "unit_action_visibility.cpp"
    test_cpp = REPO_ROOT / "tests" / "native" / "unit_action_visibility_test.cpp"
    include_dir = REPO_ROOT / "include"

    cmd = [
        "g++",
        "-m32",
        "-O2",
        f"-I{include_dir}",
        str(src_file),
        str(test_cpp),
        "-o",
        str(test_bin),
    ]

    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"

    run_res = subprocess.run([str(test_bin)], capture_output=True, text=True)
    assert run_res.returncode == 0, f"Execution failed: {run_res.stderr}"
