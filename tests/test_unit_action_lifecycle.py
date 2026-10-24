"""Native regressions for unit_action_lifecycle action teardown and initialization."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026BA70 lifecycle teardown and flag clearing",
    "func_0026BDF0 lifecycle initialization and flag setting",
]


@pytest.fixture(scope="module")
def lifecycle_test(tmp_path_factory):
    """Compile the actual lifecycle source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("lifecycle regressions require g++")
    fixture = tmp_path_factory.mktemp("action-lifecycle")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "lifecycle-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_lifecycle.cpp",
            "tests/native/unit_action_lifecycle_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_lifecycle_behavior(lifecycle_test, case):
    """Verify action lifecycle teardown, initialization, and list calls."""
    result = subprocess.run([str(lifecycle_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
