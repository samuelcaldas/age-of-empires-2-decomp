"""Native regressions for unit_action_rebind scaling and edge cases."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "normal scaling",
    "16-bit sign-extended multiply 100000x30000/1",
    "16-bit signed boundary",
    "target_id callback ordering",
]


@pytest.fixture(scope="module")
def rebind_test(tmp_path_factory):
    """Compile the actual rebind source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("rebind regressions require g++")
    fixture = tmp_path_factory.mktemp("action-rebind")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "rebind-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_rebind.cpp",
            "tests/native/unit_action_rebind_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_rebind_behavior(rebind_test, case):
    """Verify signed-short scaling and callback-visible state and slot selection."""
    result = subprocess.run([str(rebind_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
