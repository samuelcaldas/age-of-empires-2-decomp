"""Native regressions for render_manager_ui_alloc."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub-object 47C0 allocation success constructs and registers",
    "sub-object 47C0 allocation failure returns zero immediately",
    "teardown destroys active sub-object, clears global, and calls slot_88",
    "teardown with null sub-object skips destruction and calls slot_88",
]


@pytest.fixture(scope="module")
def render_manager_ui_alloc_test(tmp_path_factory):
    """Compile render_manager_ui_alloc source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_ui_alloc regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-ui-alloc")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-ui-alloc-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render/render_manager_ui_alloc.cpp",
            "tests/native/render_manager_ui_alloc_test.cpp",
            "tests/native/render_manager_ui_alloc_virtual_fixture.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_ui_alloc_behavior(render_manager_ui_alloc_test, case):
    """Verify UI sub-object allocation, configuration, and teardown."""
    result = subprocess.run([str(render_manager_ui_alloc_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
