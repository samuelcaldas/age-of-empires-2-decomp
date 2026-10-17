"""Native regressions for render_manager_messages."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "render manager mode 1 message table resolution",
    "render manager mode 2 direct ID and default handling",
]


@pytest.fixture(scope="module")
def render_manager_messages_test(tmp_path_factory):
    """Compile render_manager_messages source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_messages regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-messages")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-messages-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render_manager_messages.cpp",
            "tests/native/render_manager_messages_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_messages_behavior(render_manager_messages_test, case):
    """Verify render manager message table and default handling behavior."""
    result = subprocess.run([str(render_manager_messages_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
