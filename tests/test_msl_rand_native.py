import subprocess
import tempfile
from pathlib import Path
import pytest

ROOT = Path(__file__).resolve().parents[1]
TEST_SRC = ROOT / "tests" / "native" / "msl_rand_test.c"
RAND_SRC = ROOT / "src" / "msl" / "rand.c"
SRAND_SRC = ROOT / "src" / "msl" / "srand.c"

def test_msl_rand_srand_native_behavior():
    assert TEST_SRC.exists(), f"Missing test source {TEST_SRC}"
    assert RAND_SRC.exists(), f"Missing implementation {RAND_SRC}"
    assert SRAND_SRC.exists(), f"Missing implementation {SRAND_SRC}"

    with tempfile.TemporaryDirectory() as tmp_dir:
        binary = Path(tmp_dir) / "msl_rand_test"
        compile_cmd = [
            "gcc",
            "-O2",
            "-I", str(ROOT / "include"),
            str(TEST_SRC),
            str(RAND_SRC),
            str(SRAND_SRC),
            "-o", str(binary),
        ]
        res = subprocess.run(compile_cmd, capture_output=True, text=True)
        assert res.returncode == 0, f"Compilation failed: {res.stdout}\n{res.stderr}"

        run_res = subprocess.run([str(binary)], capture_output=True, text=True)
        assert run_res.returncode == 0, f"Test failed with code {run_res.returncode}: {run_res.stderr}"
        assert "MSL_RAND_SRAND_TEST_PASSED" in run_res.stdout
