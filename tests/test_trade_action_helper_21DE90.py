"""Run the DE90 dispatch contract against the actual native C++98 helper."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "all_registers_palette_and_stack_forwarded",
    "first_three_arguments_sign_extend_only",
    "null_reserved_packet_still_dispatches",
    "zero_arguments_still_dispatch",
]


@pytest.fixture(scope="module")
def helper_21DE90_test(tmp_path_factory):
    """Compile the helper with complete callee contracts and sanitizers."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_21DE90 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-21DE90")
    flags = ["-m32", "-std=c++98", "-fsanitize=undefined", "-fno-sanitize-recover=undefined"]
    probe = subprocess.run(
        [compiler, *flags, "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="typedef char PointerWidth[sizeof(void *) == 4 ? 1 : -1];\nint main() { return 0; }\n",
        capture_output=True, text=True, timeout=30,
    )
    if probe.returncode:
        pytest.skip(f"sanitized native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-21DE90-test"
    subprocess.run(
        [compiler, *flags, "-fno-builtin", "-Iinclude",
         "src/trade_action_helper_21DE90.cpp",
         "src/trade_action_helper_21DE90_test.cpp", "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True, timeout=30,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_helper_21DE90_behavior(helper_21DE90_test, case):
    """Check forwarding, reservation sizes, and unconditional call ordering."""
    result = subprocess.run(
        [str(helper_21DE90_test), str(case)], capture_output=True, text=True, timeout=10,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
