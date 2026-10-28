"""Native semantic regressions for render_font_lookup."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "font glyph lookup valid char routing"),
    ("1", "font glyph lookup missing char returns -1"),
    ("2", "multiple font tables routing independence"),
]


@pytest.fixture(scope="module")
def font_lookup_test(tmp_path_factory):
    """Compile render_font_lookup with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_font_lookup tests require g++")
    fixture = tmp_path_factory.mktemp("render-font-lookup")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-font-lookup-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_font_context.cpp",
         "src/render/render_font_lookup.cpp",
         "tests/native/render_font_lookup_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_render_font_lookup_behavior(font_lookup_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(font_lookup_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
