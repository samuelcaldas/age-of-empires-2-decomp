"""Native regressions for render_manager_device."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "device reset calls func_344580 when device is present",
    "device reset skips call when device is null",
    "device metrics queries all three parameters",
    "device actuators return 1 when all three succeed",
    "device actuators fail fast on first check",
    "device actuators fail fast on second check",
    "device actuators fail on third check",
    "device tail call forwards device handle to func_344920",
]


@pytest.fixture(scope="module")
def render_manager_device_test(tmp_path_factory):
    """Compile render_manager_device source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_device regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-device")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-device-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render/render_manager_device.cpp",
            "tests/native/render_manager_device_test.cpp",
            "tests/native/render_manager_device_virtual_fixture.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_device_behavior(render_manager_device_test, case):
    """Verify render manager device reset, query, actuator, and tail-call behavior."""
    result = subprocess.run([str(render_manager_device_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
