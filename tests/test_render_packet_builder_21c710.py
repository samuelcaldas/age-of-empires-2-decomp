"""Native semantic regressions for render_packet_builder_21c710."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_0021C710 packet construction and register 0x14 direct write"),
    ("1", "func_0021C790 packet construction and register 0x16 direct write"),
    ("2", "func_0021C810 packet construction and register 0x3B bitfield write"),
    ("3", "func_0021C8D0 packet construction and register 0x4F bitfield write"),
]


@pytest.fixture(scope="module")
def helper_21C710_test(tmp_path_factory):
    """Compile render_packet_builder_21c710 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_packet_builder_21c710 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-21C710")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-21C710-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_packet_builder_21c710.cpp",
         "tests/native/render_packet_builder_21c710_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_21C710_behavior(helper_21C710_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_21C710_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
