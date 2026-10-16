"""Native regressions for unit_action_state_mgr state notifications and frame updates."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026A460 coordinate rounding and helpers",
    "func_0026A540 notification dispatch based on func_26AD20",
    "func_0026A680 frame store and idempotence",
]


@pytest.fixture(scope="module")
def state_mgr_test(tmp_path_factory):
    """Compile the actual state_mgr source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("state_mgr regressions require g++")
    fixture = tmp_path_factory.mktemp("action-state-mgr")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "state-mgr-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_state_mgr.cpp",
            "tests/native/unit_action_state_mgr_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_state_mgr_behavior(state_mgr_test, case):
    """Verify state change notifications and animation frame updates."""
    result = subprocess.run([str(state_mgr_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
