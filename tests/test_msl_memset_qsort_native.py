import subprocess
import tempfile
from pathlib import Path
import pytest

ROOT = Path(__file__).resolve().parents[1]
TEST_SRC = ROOT / "tests" / "native" / "msl_memset_qsort_test.c"
MEMSET_SRC = ROOT / "src" / "msl" / "memset.c"
QSORT_SRC = ROOT / "src" / "msl" / "qsort.c"

def test_msl_memset_qsort_native_behavior():
    assert TEST_SRC.exists(), f"Missing test source {TEST_SRC}"
    assert MEMSET_SRC.exists(), f"Missing implementation {MEMSET_SRC}"
    assert QSORT_SRC.exists(), f"Missing implementation {QSORT_SRC}"

    with tempfile.TemporaryDirectory() as tmp_dir:
        binary = Path(tmp_dir) / "msl_test"
        compile_cmd = [
            "gcc",
            "-O2",
            "-I", str(ROOT / "include"),
            str(TEST_SRC),
            str(MEMSET_SRC),
            str(QSORT_SRC),
            "-o", str(binary),
        ]
        res = subprocess.run(compile_cmd, capture_output=True, text=True)
        assert res.returncode == 0, f"Compilation failed: {res.stdout}\n{res.stderr}"

        run_res = subprocess.run([str(binary)], capture_output=True, text=True)
        assert run_res.returncode == 0, f"Test failed with code {run_res.returncode}: {run_res.stderr}"
        assert "MSL_MEMSET_QSORT_TEST_PASSED" in run_res.stdout
