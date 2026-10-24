"""Native unit tests executing C-level behavioral regressions for kt_hd.c."""

from pathlib import Path
import shutil
import subprocess

import pytest


ROOT = Path(__file__).resolve().parents[1]
C_TEST = ROOT / "tests/native/kt_hd_test.c"
C_SRC = ROOT / "src/kcet/kt_hd.c"


def test_kt_hd_native_behavior(tmp_path):
    cc = shutil.which("gcc")
    if cc is None:
        pytest.skip("native gcc required")

    bin_path = tmp_path / "kt_hd_test"
    res = subprocess.run(
        [cc, "-O2", "-Iinclude", str(C_SRC), str(C_TEST), "-o", str(bin_path)],
        cwd=ROOT, capture_output=True, text=True,
    )
    if res.returncode != 0:
        pytest.fail(f"native gcc compilation failed: {res.stderr}\n{res.stdout}")

    run_res = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert run_res.returncode == 0, f"native test execution failed: {run_res.stderr}\n{run_res.stdout}"
    assert "All native kt_hd tests passed successfully." in run_res.stdout
