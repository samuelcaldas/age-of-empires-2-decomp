"""Native resize guards, clamping, and callback argument regressions."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
PROBE_SOURCE = '#include <cassert>\nint main() { static_assert(sizeof(void *) == 4, "32-bit"); }\n'
CASES = ("reject", "clamp")


@pytest.fixture(scope="module")
def resize_test_binary(tmp_path_factory):
    """Compile the production resize function with its ABI-sized fixture."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    build_dir = tmp_path_factory.mktemp("zone-dispatch-resize")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(build_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = build_dir / "zone-dispatch-resize-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude", "src/zone/zone_dispatch.cpp",
         "tests/native/zone_dispatch_fixture_support.cpp",
         "tests/native/zone_dispatch_resize_test.cpp", "-o", str(binary)],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


@pytest.mark.parametrize("case", CASES)
def test_resize_production_contracts(resize_test_binary, case):
    """Check the actual resize function for the selected contract case."""
    result = subprocess.run([str(resize_test_binary), case], capture_output=True, text=True)
    assert result.returncode == 0, f"{case} resize contract failed: {result.stderr}"
