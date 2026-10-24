"""Native regressions for unit_action_teardown action deactivation and list destruction."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026C1F0 calls Method29 and Method34(-1)",
    "func_0026C2D0 calls Method29",
    "func_0026C360 teardown and guard on state 2",
]


@pytest.fixture(scope="module")
def teardown_test(tmp_path_factory):
    """Compile the actual teardown source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("teardown regressions require g++")
    fixture = tmp_path_factory.mktemp("action-teardown")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "teardown-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_teardown.cpp",
            "tests/native/unit_action_teardown_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_teardown_behavior(teardown_test, case):
    """Verify Method29/Method34 calls and sublist teardown guards."""
    result = subprocess.run([str(teardown_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
