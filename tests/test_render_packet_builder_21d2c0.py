"""Native regressions for render_packet_builder_21d2c0."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "builds solid rect fill packet with RGBAQ and 4 vertices"),
    ("1", "allocates packet buffer when input ctx is null"),
]


@pytest.fixture(scope="module")
def packet_builder_21d2c0_test(tmp_path_factory):
    """Compile render_packet_builder_21d2c0 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_packet_builder_21d2c0 tests require g++")
    fixture = tmp_path_factory.mktemp("packet-builder-21d2c0")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "packet-builder-21d2c0-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_packet_builder_21d2c0.cpp",
         "tests/native/render_packet_builder_21d2c0_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_packet_builder_21d2c0_behavior(packet_builder_21d2c0_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(packet_builder_21d2c0_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
