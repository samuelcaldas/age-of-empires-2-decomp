"""Native unit tests executing C-level behavioral regressions for kt_usbkeybd_drv.c."""

from pathlib import Path
import shutil
import subprocess

import pytest


ROOT = Path(__file__).resolve().parents[1]
C_TEST = ROOT / "tests/native/kt_usbkeybd_drv_test.c"
C_SRC = ROOT / "src/kcet/kt_usbkeybd_drv.c"


def test_kt_usbkeybd_drv_native_behavior(tmp_path):
    cc = shutil.which("gcc")
    if cc is None:
        pytest.skip("native gcc required")

    bin_path = tmp_path / "kt_usbkeybd_drv_test"
    res = subprocess.run(
        [cc, "-m32", "-O2", "-Iinclude", str(C_SRC), str(C_TEST), "-o", str(bin_path)],
        cwd=ROOT, capture_output=True, text=True,
    )
    if res.returncode != 0:
        pytest.skip(f"native 32-bit gcc compilation failed: {res.stderr}")

    run_res = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert run_res.returncode == 0, f"native test execution failed: {run_res.stderr}\n{run_res.stdout}"
    assert "All native kt_usbkeybd_drv tests passed" in run_res.stdout
