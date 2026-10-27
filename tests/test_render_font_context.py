"""Native semantic regressions for render_font_context."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "font context pointer setter and getter roundtrip"),
    ("1", "empty glyph table with immediate sentinel returns -1"),
    ("2", "single range table boundary and out-of-bounds checks"),
    ("3", "disjoint multi-range table gap rejection and offset resolution"),
]


@pytest.fixture(scope="module")
def font_context_test(tmp_path_factory):
    """Compile render_font_context with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_font_context tests require g++")
    fixture = tmp_path_factory.mktemp("render-font-context")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-font-context-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_font_context.cpp",
         "tests/native/render_font_context_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_render_font_context_behavior(font_context_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(font_context_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
