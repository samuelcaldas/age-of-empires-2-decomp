"""Native regressions for unit_action_build_anim."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026E560 guard checks on null inputs",
    "func_0026E560 frame determination and dispatch",
    "func_0026E710 flag 0x200 set and helper dispatch",
]


@pytest.fixture(scope="module")
def build_anim_test(tmp_path_factory):
    """Compile the actual build_anim source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_anim regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-anim")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-anim-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_anim.cpp",
            "tests/native/unit_action_build_anim_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_anim_behavior(build_anim_test, case):
    """Verify animation frame selection, tile checking, and recursive dispatch."""
    result = subprocess.run([str(build_anim_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
