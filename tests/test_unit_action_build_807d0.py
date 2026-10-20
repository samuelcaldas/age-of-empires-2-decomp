import subprocess
from pathlib import Path
import pytest

REPO_ROOT = Path(__file__).resolve().parents[1]
SRC_FILE = REPO_ROOT / "src" / "unit_action_build_807d0.cpp"
TEST_FILE = REPO_ROOT / "tests" / "native" / "unit_action_build_807d0_test.cpp"
INCLUDE_DIR = REPO_ROOT / "include"


@pytest.fixture(scope="module")
def native_binary(tmp_path_factory):
    bin_path = tmp_path_factory.mktemp("bin") / "unit_action_build_807d0_test"
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


def test_build_807d0_behavior(native_binary):
    """Run native behavioral test suite for func_002807D0."""
    res = subprocess.run([str(native_binary)], capture_output=True, text=True)
    assert res.returncode == 0, f"Test failed: {res.stderr}\n{res.stdout}"
    assert "All unit_action_build_807d0 tests passed!" in res.stdout
