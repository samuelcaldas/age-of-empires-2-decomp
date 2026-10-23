import subprocess
import tempfile
from pathlib import Path
import pytest

ROOT = Path(__file__).resolve().parents[1]
TEST_SRC = ROOT / "tests" / "native" / "msl_string_test.c"
STRCPY_SRC = ROOT / "src" / "msl" / "strcpy.c"
STRCAT_SRC = ROOT / "src" / "msl" / "strcat.c"
STRCMP_SRC = ROOT / "src" / "msl" / "strcmp.c"

def test_msl_string_native_behavior():
    assert TEST_SRC.exists(), f"Missing test source {TEST_SRC}"
    assert STRCPY_SRC.exists(), f"Missing implementation {STRCPY_SRC}"
    assert STRCAT_SRC.exists(), f"Missing implementation {STRCAT_SRC}"
    assert STRCMP_SRC.exists(), f"Missing implementation {STRCMP_SRC}"

    with tempfile.TemporaryDirectory() as tmp_dir:
        binary = Path(tmp_dir) / "msl_string_test"
        compile_cmd = [
            "gcc",
            "-O2",
            "-I", str(ROOT / "include"),
            str(TEST_SRC),
            str(STRCPY_SRC),
            str(STRCAT_SRC),
            str(STRCMP_SRC),
            "-o", str(binary),
        ]
        res = subprocess.run(compile_cmd, capture_output=True, text=True)
        assert res.returncode == 0, f"Compilation failed: {res.stdout}\n{res.stderr}"

        run_res = subprocess.run([str(binary)], capture_output=True, text=True)
        assert run_res.returncode == 0, f"Test failed with code {run_res.returncode}: {run_res.stderr}"
        assert "MSL_STRING_TEST_PASSED" in run_res.stdout
