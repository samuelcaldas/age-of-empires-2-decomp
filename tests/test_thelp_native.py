"""Native unit tests executing C-level behavioral regressions for thelp_overlay.c."""

from pathlib import Path
import shutil
import subprocess

import pytest


ROOT = Path(__file__).resolve().parents[1]
C_TEST = ROOT / "tests/native/thelp_test.c"
C_SRC = ROOT / "src/thelp_overlay.c"


def test_thelp_native_behavior(tmp_path):
    cc = shutil.which("gcc")
    if cc is None:
        pytest.skip("native gcc required")

    bin_path = tmp_path / "thelp_test"
    result = subprocess.run(
        [cc, "-O2", "-Iinclude", str(C_SRC), str(C_TEST), "-o", str(bin_path)],
        cwd=ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, result.stdout + result.stderr

    run_result = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert run_result.returncode == 0, run_result.stdout + run_result.stderr
    assert "All native thelp tests passed successfully." in run_result.stdout
