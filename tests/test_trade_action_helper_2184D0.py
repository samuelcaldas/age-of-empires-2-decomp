"""Native semantic regressions for trade_action_helper_2184D0."""

from pathlib import Path
import shutil
import signal
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
    ("10", "zero x step traps before grid callbacks"),
    ("11", "zero y step traps before grid callbacks"),
    ("12", "field 188 state two exits before fallback callback"),
    ("13", "y values reload after callbacks across multiple rows"),
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
         "-include", "tests/native/trade_action_helper_2184D0_break_fixture.h",
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


@pytest.mark.parametrize(
    "mutation,expected_signal,case",
    [
        ("wrong-break-code", -signal.SIGABRT, "10"),
        ("removed-break", -signal.SIGFPE, "10"),
        ("altered-zero-guard", -signal.SIGFPE, "10"),
        ("removed-state-two-guard", -signal.SIGABRT, "12"),
    ],
)
def test_zero_step_trap_regression_rejects_mutations(
    helper_2184D0_test, tmp_path, mutation, expected_signal, case
):
    """Require trap and state-gate mutants to fail at the expected signal."""
    compiler = shutil.which("g++")
    assert compiler is not None
    source = PROJECT_ROOT / "src/trade_action_helper_2184D0.cpp"
    original = source.read_text()
    guard = "    if (step == 0) {\n        __I_break(7);\n    }\n"
    if mutation == "wrong-break-code":
        changed = original.replace("__I_break(7)", "__I_break(6)", 1)
    elif mutation == "removed-break":
        changed = original.replace(guard, "", 1)
    elif mutation == "altered-zero-guard":
        changed = original.replace("if (step == 0)", "if (step > 0)", 1)
    else:
        changed = original.replace(
            "if (state == 2 || state == 3)", "if (state == 3)", 1
        )
    assert changed != original
    source_copy = tmp_path / "trade_action_helper_2184D0_mutant.cpp"
    source_copy.write_text(changed)
    binary = tmp_path / "mutant-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude", "-include",
         "tests/native/trade_action_helper_2184D0_break_fixture.h", str(source_copy),
         "tests/native/trade_action_helper_2184D0_support.cpp",
         "tests/native/trade_action_helper_2184D0_cases.cpp",
         "tests/native/trade_action_helper_2184D0_test.cpp", "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    result = subprocess.run([str(binary), case], capture_output=True, text=True)
    assert result.returncode == expected_signal, result.stderr
