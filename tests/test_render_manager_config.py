"""Native regressions for render_manager_config."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00187ca0 when field_1AC is null does nothing",
    "func_00187ca0 when field_1AC is valid unpacks snapshot",
    "func_00187ea0 packs snapshot buffer",
]


@pytest.fixture(scope="module")
def render_manager_config_test(tmp_path_factory):
    """Compile render_manager_config source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_config regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-config")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-config-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render_manager_config.cpp",
            "tests/native/render_manager_config_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_config_behavior(render_manager_config_test, case):
    """Verify render manager config behavior."""
    result = subprocess.run([str(render_manager_config_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
