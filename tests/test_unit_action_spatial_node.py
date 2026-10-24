"""Native regressions for unit_action_spatial_node buffer allocation and spatial cleanup."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026A2A0 detach and cleanup",
    "func_0026A300 and func_0026A420 buffer allocation and release",
    "func_00269FF0/A0C0/A1B0 coordinate rounding and helper dispatch",
]


@pytest.fixture(scope="module")
def spatial_node_test(tmp_path_factory):
    """Compile the actual spatial_node source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("spatial_node regressions require g++")
    fixture = tmp_path_factory.mktemp("action-spatial-node")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "spatial-node-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_spatial_node.cpp",
            "tests/native/unit_action_spatial_node_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_spatial_node_behavior(spatial_node_test, case):
    """Verify spatial node buffers, detachment, and coordinate rounding."""
    result = subprocess.run([str(spatial_node_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
