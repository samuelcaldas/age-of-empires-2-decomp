"""Native semantic regressions for trade_action_helper_2184D0."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "zero step and zero span still dispatch once"),
    ("1", "span five and step two visits three positions"),
    ("2", "failed clipping restores previously saved manager fields"),
    ("3", "grid counts reload spans changed by begin callback"),
    ("4", "handler mutations affect later positions and arguments"),
    ("5", "field 188 three exits without callbacks"),
    ("6", "zero spans with nonzero steps still visit once"),
    ("7", "rectangle branch preserves callback arguments and cleanup"),
    ("8", "fallback virtual calls use exact receiver and argument"),
    ("9", "clipping mutations are reloaded for grid counts"),
]


@pytest.fixture(scope="module")
def helper_2184D0_test(tmp_path_factory):
    """Compile the production helper with the native callback harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_2184D0 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-2184d0")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-2184d0-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/trade_action_helper_2184D0.cpp",
         "tests/native/trade_action_helper_2184D0_support.cpp",
         "tests/native/trade_action_helper_2184D0_cases.cpp",
         "tests/native/trade_action_helper_2184D0_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_2184D0_behavior(helper_2184D0_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_2184D0_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
