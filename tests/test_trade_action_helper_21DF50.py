"""Run the original-derived DF50 packet contract against native C++98 code."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "format_20_divisor_512",
    "format_19_divisor_256",
    "format_2_divisor_128",
    "default_divisor_64",
    "null_packet_allocation",
    "low_halfword_truncation",
    "selector_uses_halfword_not_byte",
    "negative_product_truncates_toward_zero",
    "positive_product_wraps_before_division",
    "minimum_halfwords_wrap_to_zero",
    "negative_product_wraps_positive",
    "zero_width",
    "negative_format_default",
]


@pytest.fixture(scope="module")
def helper_21DF50_test(tmp_path_factory):
    """Compile the actual helper and an argument-complete, sanitized harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_21DF50 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-21DF50")
    flags = ["-m32", "-std=c++98", "-fsanitize=undefined", "-fno-sanitize-recover=undefined"]
    probe = subprocess.run(
        [compiler, *flags, "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="typedef char PointerWidth[sizeof(void *) == 4 ? 1 : -1];\nint main() { return 0; }\n",
        capture_output=True, text=True, timeout=30,
    )
    if probe.returncode:
        pytest.skip(f"sanitized native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-21DF50-test"
    subprocess.run(
        [compiler, *flags, "-fno-builtin", "-Iinclude",
         "src/trade_action_helper_21DF50.cpp",
         "src/trade_action_helper_21DF50_test.cpp", "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True, timeout=30,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_helper_21DF50_behavior(helper_21DF50_test, case):
    """Verify each packet's arguments, allocation path, arithmetic, and call order."""
    result = subprocess.run(
        [str(helper_21DF50_test), str(case)], capture_output=True, text=True, timeout=10,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
