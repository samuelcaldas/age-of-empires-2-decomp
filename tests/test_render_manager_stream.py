"""Native regressions for render_manager_stream."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "payload cleanup, trailer read, virtual result and close order",
    "zero payload still dispatches and closes",
    "negative payload still dispatches and closes",
    "allocation failure closes without dispatch",
    "payload read result is ignored by original",
    "context factory forwards parent and zero flag",
    "context allocation failure skips constructor",
    "device status preserves negative result",
    "missing device returns zero without query",
    "negative stream-open flag opens device stream",
    "positive stream-open flag opens device stream",
]


@pytest.fixture(scope="module")
def render_manager_stream_test(tmp_path_factory):
    """Compile render_manager_stream source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_stream regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-stream")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-stream-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render_manager_stream.cpp",
            "tests/native/render_manager_stream_test.cpp",
            "tests/native/render_manager_stream_fixture.cpp",
            "tests/native/render_manager_stream_virtual_fixture.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_stream_behavior(render_manager_stream_test, case):
    """Verify render manager stream loader, factory, and status queries."""
    result = subprocess.run([str(render_manager_stream_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
