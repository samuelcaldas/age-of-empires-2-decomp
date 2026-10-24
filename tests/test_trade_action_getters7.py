"""Native semantic regressions for trade_action_getters7."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "out of bounds negative index returns early"),
    ("1", "out of bounds high index returns early"),
    ("2", "ID 5 negative and positive store"),
    ("3", "BEC == 1 limits execution on negative input"),
    ("4", "ID 0x68 increment resolution with pointer chain and mode 2 flag 1"),
    ("5", "ID 0x10 mode 2 flag 0 scale factor 0.75 yielding 75.0f scaled with custom return 731"),
    ("6", "ID 0x10 mode 1 flag 0 scale factor 1.0 yielding 100.0f scaled"),
    ("7", "ID 0x68 increment resolution with mode 2 flag 0 yielding 260"),
    ("8", "ID 0xE3 mode 1 flag 0 scale factor 1.0 yielding 100.0f scaled"),
    ("9", "ID 0x10 mode 1 flag 1 scale factor 0.8 yielding 80.0f scaled"),
    ("10", "ID 0x10 mode 2 flag 1 scale factor 0.75 yielding 75.0f scaled"),
    ("11", "Scaler returns 0 forces slot to 1"),
    ("12", "BEC == 1 with late cap on ID 0x14 clamping to 50"),
    ("13", "Tail ID 0x56 helper call verification"),
    ("14", "Tail ID 0x57 helper call verification"),
    ("15", "Tail ID 0x69 helper call verification"),
    ("16", "ID 0x24 and 0x3A mode 2 flag 0 scale factor 0.6 yielding 60.0f scaler input with custom return 59"),
    ("17", "ID 0x24 and 0x3A scaler returns 0 forces slot to 1"),
    ("18", "Parameterized matrix test for f20 IDs 0x24 and 0x3A across modes 2, 3, 4 and flags 0, 1"),
    ("19", "Parameterized matrix test for f21 IDs 0x10, 0x1A, 0x3B, 0x3C across modes 2, 3, 4 and flags 0, 1"),
    ("20", "Parameterized matrix test for f22 IDs 0x13, 0x14 across modes 2, 3, 4 and flags 0, 1"),
    ("21", "Parameterized matrix test for f23 IDs 0xE3, 0xE4 across modes 2, 3, 4 and flags 0, 1"),
]


@pytest.fixture(scope="module")
def getters7_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("getters7") / "trade-action-getters7-test"
    result = subprocess.run(
        [compiler, "-fno-builtin", "-Iinclude",
         "src/trade/trade_action_getters7.cpp",
         "tests/native/trade_action_getters7_test.cpp",
         "tests/native/trade_action_getters7_test_support.cpp",
         "tests/native/trade_action_getters7_test_cases_part1.cpp",
         "tests/native/trade_action_getters7_test_cases_part2.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stderr
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_getters7_behavior(getters7_test_binary, case, description):
    """Check trade_action_getters7 execution in isolated native process."""
    result = subprocess.run(
        [str(getters7_test_binary), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"{description}: {result.stderr}"


MUTANTS = [
    (
        "factor",
        "if (mode == 2) return 0.6f;",
        "if (mode == 2) return 0.75f;",
        "std::fabs(last_scaled_val - expected_scaled) < 0.0001f",
    ),
    (
        "store",
        "        *table_slot = scaled;",
        "",
        "*slot == expected_mock_return",
    ),
]


@pytest.mark.parametrize(
    "name,original,mutated,diagnostic",
    MUTANTS,
    ids=[item[0] for item in MUTANTS],
)
def test_getters7_source_mutants_fail_at_expected_assertion(
    tmp_path, name, original, mutated, diagnostic
):
    """Require compiled source mutants to hit their targeted native assertion."""
    source = PROJECT_ROOT / "src/trade/trade_action_getters7.cpp"
    source_text = source.read_text()
    assert source_text.count(original) == 1, (
        f"{name} mutation anchor must be unique"
    )
    mutant_source = tmp_path / "trade_action_getters7.cpp"
    mutant_source.write_text(source_text.replace(original, mutated, 1))
    binary = tmp_path / f"trade-action-getters7-{name}-mutant"
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    compile_result = subprocess.run(
        [
            compiler,
            "-fno-builtin",
            "-Iinclude",
            str(mutant_source),
            "tests/native/trade_action_getters7_test.cpp",
            "tests/native/trade_action_getters7_test_support.cpp",
            "tests/native/trade_action_getters7_test_cases_part1.cpp",
            "tests/native/trade_action_getters7_test_cases_part2.cpp",
            "-o",
            str(binary),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
    )
    assert compile_result.returncode == 0, (
        f"{name} mutant failed to compile: {compile_result.stderr}"
    )
    result = subprocess.run([str(binary), "18"], capture_output=True, text=True)
    assert result.returncode == -6, (
        f"{name} mutant did not terminate via SIGABRT: {result.stderr}"
    )
    assert "Assertion" in result.stderr, (
        f"{name} mutant did not hit native assert: {result.stderr}"
    )
    assert "trade_action_getters7_matrix_support.h" in result.stderr, result.stderr
    assert diagnostic in result.stderr, (
        f"{name} mutant hit wrong assertion: {result.stderr}"
    )
    assert source.read_text() == source_text
