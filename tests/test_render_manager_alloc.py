"""Native regressions for render_manager_alloc."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub-object 14C allocation success initializes and registers",
    "sub-object 14C allocation failure returns zero immediately",
    "sub-object 14C func_1DB500 failure returns zero",
    "sub-object 12C allocation success initializes and stores global",
    "sub-object 12C allocation failure clears global and returns zero",
]


@pytest.fixture(scope="module")
def render_manager_alloc_test(tmp_path_factory):
    """Compile render_manager_alloc source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_alloc regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-alloc")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-alloc-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render/render_manager_alloc.cpp",
            "tests/native/render_manager_alloc_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_alloc_behavior(render_manager_alloc_test, case):
    """Verify sub-object allocation and registration behavior."""
    result = subprocess.run([str(render_manager_alloc_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
