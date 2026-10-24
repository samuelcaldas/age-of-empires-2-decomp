"""Native regressions for unit_action_build_notify_workers."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00270660 returns early when task count is zero",
    "func_00270660 returns early when Method219 returns 1 with item 103",
    "func_00270660 creates and adds item when no subactions exist in list",
    "func_00270660 triggers DeleteHead and worker pop when Action method returns 3",
]


@pytest.fixture(scope="module")
def build_notify_workers_test(tmp_path_factory):
    """Compile the actual build_notify_workers source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_notify_workers regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-notify-workers")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-notify-workers-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_notify_workers.cpp",
            "tests/native/unit_action_build_notify_workers_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_notify_workers_behavior(build_notify_workers_test, case):
    """Verify task item notification, rate thresholds, and subaction execution."""
    result = subprocess.run([str(build_notify_workers_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
