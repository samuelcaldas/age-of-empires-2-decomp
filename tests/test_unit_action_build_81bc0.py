import subprocess
from pathlib import Path
import pytest

REPO_ROOT = Path(__file__).resolve().parents[1]
SRC_FILE = REPO_ROOT / "src/unit" / "unit_action_build_81bc0.cpp"
TEST_FILE = REPO_ROOT / "tests" / "native" / "unit_action_build_81bc0_test.cpp"
INCLUDE_DIR = REPO_ROOT / "include"


@pytest.fixture(scope="module")
def native_binary(tmp_path_factory):
    bin_path = tmp_path_factory.mktemp("bin") / "unit_action_build_81bc0_test"
    cmd = [
        "g++",
        "-m32",
        "-O0",
        "-g",
        "-std=c++98",
        f"-I{INCLUDE_DIR}",
        str(SRC_FILE),
        str(TEST_FILE),
        "-o",
        str(bin_path),
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"
    return bin_path


def test_build_81bc0_dispatch_argument(native_binary):
    """Run native test verifying func_00281BC0 distinct dispatch argument (mode == 1)."""
    res = subprocess.run([str(native_binary)], capture_output=True, text=True)
    assert res.returncode == 0, f"Test failed: {res.stderr}\n{res.stdout}"
