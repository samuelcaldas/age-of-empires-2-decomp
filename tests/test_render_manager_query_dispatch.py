"""Native regressions for render_manager_query_dispatch."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "boolean stubs func_00186e00 and func_00186e40 return 1",
    "func_00186dc0 forwards parameters to methodFC returning true",
    "func_00186dc0 forwards parameters to methodFC returning false",
    "func_00186e10 dispatches method100 returning boolean result",
]


@pytest.fixture(scope="module")
def render_manager_query_dispatch_test(tmp_path_factory):
    """Compile render_manager_query_dispatch source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_query_dispatch regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-query-dispatch")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-query-dispatch-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render/render_manager_query_dispatch.cpp",
            "tests/native/render_manager_query_dispatch_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_query_dispatch_behavior(render_manager_query_dispatch_test, case):
    """Verify render manager query dispatch behavior."""
    result = subprocess.run([str(render_manager_query_dispatch_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
