"""Native regressions for unit_action_tile_node attachment and detachment logic."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00269D80 detach and guards",
    "func_00269E50 attach with previous detach",
    "func_00269F30 teardown idempotence",
]


@pytest.fixture(scope="module")
def tile_node_test(tmp_path_factory):
    """Compile the actual tile_node source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tile_node regressions require g++")
    fixture = tmp_path_factory.mktemp("action-tile-node")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tile-node-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_tile_node.cpp",
            "tests/native/unit_action_tile_node_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tile_node_behavior(tile_node_test, case):
    """Verify tile node attachment, detachment, and list helper invocations."""
    result = subprocess.run([str(tile_node_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
