"""Native regressions for render_manager_accessors."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00185d00 allocates 0x9D94 and constructs object",
    "func_00185d40 tail-calls func_226610 and func_00185d60 sets coordinates",
    "func_00185d70 updates player context and dispatches callback",
    "func_00185dc0 evaluates refresh mode and dispatches func_190AF0",
    "func_00185e20 indexes surface entry when non-null",
]


@pytest.fixture(scope="module")
def render_manager_accessors_test(tmp_path_factory):
    """Compile render_manager_accessors source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_accessors regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-accessors")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-accessors-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render_manager_accessors.cpp",
            "tests/native/render_manager_accessors_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_accessors_behavior(render_manager_accessors_test, case):
    """Verify render manager accessors behavior."""
    result = subprocess.run([str(render_manager_accessors_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
