"""Native semantic regressions for trade_action_candidates."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "flag a3 resets count at 3172"),
    ("1", "empty item list returns 0 matches"),
    ("2", "mode a2 < 0 matches score < threshold"),
    ("3", "mode a2 < 0 rejects score >= threshold"),
    ("4", "mode a2 > 0 rejects score <= threshold"),
    ("5", "mode a2 == 0 matches score == threshold"),
    ("6", "mode a2 == 0 rejects score != threshold"),
    ("7", "excluded list skips candidate"),
    ("8", "pred_1471a0 == -1 flags special candidate"),
    ("9", "pred_1471a0 == 600 with type 27 flags special candidate"),
    ("10", "pred_1471a0 == 600 with type != 27 does not flag"),
    ("11", "pred_1471a0 == 600 with missing linked entity flags special candidate"),
    ("12", "existing candidate id is not re-appended but still counts"),
    ("13", "func_002B7BB0 with secondary list a3 == 1"),
    ("14", "func_002B7BB0 with primary list only a3 == 0"),
    ("15", "func_002B8560 matches candidate and returns sub_id"),
    ("16", "func_002B8560 returns -1 when predicate returns 0"),
    ("17", "func_002B8560 returns -1 when func_002bf050 returns non-zero"),
    ("18", "func_002B8560 returns -1 when candidate is in pool exclusion"),
    ("19", "func_002B8980 returns candidate with best distance"),
    ("20", "func_002B8980 returns -1 when no candidate matches predicate"),
    ("21", "func_002B8980 with flag 1 selects candidate"),
    ("22", "func_002B90A0 returns 1 on matching target type"),
    ("23", "func_002B90A0 returns 0 on mismatching target type"),
    ("24", "func_002B90A0 returns 0 when item lookup fails"),
    ("25", "func_002B9140 computes rate distribution successfully"),
    ("26", "func_002B9140 counts matching candidate plan items"),
]


@pytest.fixture(scope="module")
def candidates_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("candidates") / "trade-action-candidates-test"
    result = subprocess.run(
        [
            compiler,
            "-m32",
            "-fno-builtin",
            "-Iinclude",
            "src/trade_action_candidates.cpp",
            "src/trade_action_candidates_extra.cpp",
            "tests/native/trade_action_candidates_test.cpp",
            "tests/native/trade_action_candidates_test_support.cpp",
            "tests/native/trade_action_candidates_cases_part1.cpp",
            "tests/native/trade_action_candidates_cases_part2.cpp",
            "-o",
            str(binary),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, result.stderr
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_candidates_behavior(candidates_test_binary, case, description):
    """Check trade_action_candidates execution in isolated native process."""
    result = subprocess.run(
        [str(candidates_test_binary), case],
        capture_output=True,
        text=True,
        cwd=PROJECT_ROOT,
    )
    assert result.returncode == 0, f"Case {case} failed: {result.stderr}\n{result.stdout}"
    assert f"CANDIDATES TEST {case} PASSED" in result.stdout


MUTANTS = [
    (
        "mode_less_operator",
        "return score < threshold;",
        "return score <= threshold;",
        "res == 0",
    ),
    (
        "mode_greater_operator",
        "return score > threshold;",
        "return score >= threshold;",
        "res == 0",
    ),
    (
        "classification_target_type",
        "return short_at(field4, 14) == 27;",
        "return short_at(field4, 14) == 28;",
        "res == 3",
    ),
    (
        "secondary_list_condition",
        "int secondary_count = integer_at(self, 264);",
        "int secondary_count = 0;",
        "res == 5",
    ),
    (
        "selector_predicate_check",
        "if ((func_002bfcd0(self, sub_id) & 0xFF) == 1) {",
        "if ((func_002bfcd0(self, sub_id) & 0xFF) == 2) {",
        "res == 42",
    ),
    (
        "distance_candidate_condition",
        "return scan_distance_candidates(self, coords, mode, flag);",
        "return -1;",
        "res == 42",
    ),
    (
        "type_checker_match",
        "return func_001471a0(pred(item)) == target_type ? 1 : 0;",
        "return func_001471a0(pred(item)) != target_type ? 1 : 0;",
        "res == 1",
    ),
    (
        "rate_adjustment_diff",
        "int diff = integer_at(self, 3096) - sum;",
        "int diff = 0;",
        "*reinterpret_cast<int *>(base + 3240) == 25",
    ),
    (
        "reset_candidate_count",
        "if (a3 == 1) {\n        store_integer(self, 3172, 0);\n    }",
        "if (a3 == 1) {\n        /* noop */\n    }",
        "*reinterpret_cast<int *>(base + 3172) == 3",
    ),
]


@pytest.mark.parametrize(
    "name,original,mutated,diagnostic",
    MUTANTS,
    ids=[item[0] for item in MUTANTS],
)
def test_candidates_source_mutants_fail_at_expected_assertion(
    tmp_path, name, original, mutated, diagnostic
):
    """Require compiled source mutants to hit their targeted native assertion."""
    source = (
        PROJECT_ROOT / "include" / "trade_action_candidates_dual.h"
        if "mode_" in name
        else PROJECT_ROOT / "src" / "trade_action_candidates_extra.cpp"
        if "rate_" in name or "selector_" in name or "distance_" in name or "type_" in name
        else PROJECT_ROOT / "src" / "trade_action_candidates.cpp"
    )
    source_name = source.name
    source_text = source.read_text()
    assert source_text.count(original) == 1, (
        f"{name} mutation anchor must be unique"
    )
    mutant_source = tmp_path / source_name
    mutant_source.write_text(source_text.replace(original, mutated, 1))
    binary = tmp_path / f"trade-action-candidates-{name}-mutant"
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    compile_result = subprocess.run(
        [
            compiler,
            "-m32",
            "-fno-builtin",
            f"-I{tmp_path}",
            "-Iinclude",
            str(mutant_source) if source.name == "trade_action_candidates.cpp" else "src/trade_action_candidates.cpp",
            str(mutant_source) if source.name == "trade_action_candidates_extra.cpp" else "src/trade_action_candidates_extra.cpp",
            "tests/native/trade_action_candidates_test.cpp",
            "tests/native/trade_action_candidates_test_support.cpp",
            "tests/native/trade_action_candidates_cases_part1.cpp",
            "tests/native/trade_action_candidates_cases_part2.cpp",
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
    case_num = (
        "0" if "reset" in name
        else "3" if "less" in name
        else "4" if "greater" in name
        else "13" if "secondary" in name
        else "15" if "selector" in name
        else "19" if "distance" in name
        else "22" if "type_checker" in name
        else "25" if "rate" in name
        else "9"
    )
    result = subprocess.run([str(binary), case_num], capture_output=True, text=True)
    assert result.returncode == -6, (
        f"{name} mutant did not terminate via SIGABRT: {result.stderr}"
    )
    assert "Assertion" in result.stderr, (
        f"{name} mutant did not hit native assert: {result.stderr}"
    )
    assert diagnostic in result.stderr, (
        f"{name} mutant hit wrong assertion: {result.stderr}"
    )
    assert source.read_text() == source_text
