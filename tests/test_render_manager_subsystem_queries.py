"""Native regressions for render_manager_subsystem_queries."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00186000 forwards parameter and func_00186010 queries item buffer",
    "func_00186080 linear search in field_9CC and func_001860c0 tail calls",
    "func_001860d0 and func_00186110 state synchronization",
    "func_00186150 mode setup, func_001861a0 globals, and func_001861c0 tail call",
]


@pytest.fixture(scope="module")
def render_manager_subsystem_queries_test(tmp_path_factory):
    """Compile render_manager_subsystem_queries source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_subsystem_queries regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-subsystem-queries")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-subsystem-queries-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render/render_manager_subsystem_queries.cpp",
            "tests/native/render_manager_subsystem_queries_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_subsystem_queries_behavior(render_manager_subsystem_queries_test, case):
    """Verify render manager subsystem queries behavior."""
    result = subprocess.run([str(render_manager_subsystem_queries_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
