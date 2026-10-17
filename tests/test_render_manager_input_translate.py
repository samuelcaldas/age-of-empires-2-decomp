"""Native regressions for render_manager_input_translate."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "ignored return key with repeat 1 returns zero and preserves output",
    "primary message match with zero mask returns 1",
    "primary message match with specific wParam returns 1",
    "secondary message match with zero mask returns -1",
    "secondary message match with specific wParam returns -1",
    "unrecognized message returns zero and sets output to null",
]


@pytest.fixture(scope="module")
def render_manager_input_translate_test(tmp_path_factory):
    """Compile render_manager_input_translate source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_input_translate regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-input-translate")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-input-translate-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render_manager_input_translate.cpp",
            "tests/native/render_manager_input_translate_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_input_translate_behavior(render_manager_input_translate_test, case):
    """Verify input message translation behavior across primary, secondary, and filter cases."""
    result = subprocess.run([str(render_manager_input_translate_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
