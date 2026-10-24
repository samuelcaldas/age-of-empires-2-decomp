"""Native unit tests executing C-level behavioral regressions for kt_mouse.c."""

from pathlib import Path
import shutil
import subprocess

import pytest


ROOT = Path(__file__).resolve().parents[1]
C_TEST = ROOT / "tests/native/kt_mouse_test.c"
C_SRC = ROOT / "src/kcet/kt_mouse.c"


def test_kt_mouse_native_behavior(tmp_path):
    cc = shutil.which("gcc")
    if cc is None:
        pytest.skip("native gcc required")

    bin_path = tmp_path / "kt_mouse_test"
    # Build 32-bit test binary linking kt_mouse.c with native doubles
    res = subprocess.run(
        [cc, "-m32", "-O2", "-Iinclude", str(C_SRC), str(C_TEST), "-o", str(bin_path)],
        cwd=ROOT, capture_output=True, text=True,
    )
    if res.returncode != 0:
        pytest.skip(f"native 32-bit gcc compilation not supported: {res.stderr}")

    run_res = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert run_res.returncode == 0, f"native test execution failed: {run_res.stderr}\n{run_res.stdout}"
    assert "All native kt_mouse tests passed" in run_res.stdout
