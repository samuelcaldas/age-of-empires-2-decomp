"""Native regressions for unit_action_build_worker_query."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_002703C0 returns -1 immediately when task count is zero",
    "func_002703C0 returns task_id from slot 0 for worker indices within slot 0",
    "func_002703C0 returns task_id from slot 1 for worker indices within slot 1",
    "func_002703C0 returns -1 when worker index is beyond cumulative worker count",
]


@pytest.fixture(scope="module")
def build_worker_query_test(tmp_path_factory):
    """Compile the actual build_worker_query source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_worker_query regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-worker-query")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-worker-query-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_worker_query.cpp",
            "tests/native/unit_action_build_worker_query_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_worker_query_behavior(build_worker_query_test, case):
    """Verify worker task query, cumulative indexing, and boundary validation."""
    result = subprocess.run([str(build_worker_query_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
