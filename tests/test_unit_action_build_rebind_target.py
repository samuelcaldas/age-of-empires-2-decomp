"""Native regressions for unit_action_build_rebind_target."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_002709B0 preserves rate when workers are zero and target class is not 80",
    "func_002709B0 multiplies rate by 1.1f when self worker count is positive",
    "func_002709B0 divides rate by 1.1f when target class is 80 and target workers positive",
    "func_002709B0 applies both boost and resistance when both conditions are active",
]


@pytest.fixture(scope="module")
def build_rebind_target_test(tmp_path_factory):
    """Compile the actual build_rebind_target source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_rebind_target regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-rebind-target")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-rebind-target-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_rebind_target.cpp",
            "tests/native/unit_action_build_rebind_target_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_rebind_target_behavior(build_rebind_target_test, case):
    """Verify efficiency rate scaling, worker boosts, and class 80 resistance."""
    result = subprocess.run([str(build_rebind_target_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
