"""Native semantic regressions for trade_action_dispatcher."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "null self returns early"),
    ("1", "unknown action id with non-existent entity returns early"),
    ("2", "action 114 dispatches to func_002a03c0 with flag 1"),
    ("3", "action 115 dispatches to func_002a03c0 with flag 0"),
    ("4", "action 109 dispatches to func_002a03f0 with flag 1"),
    ("5", "action 110 dispatches to func_002a03f0 with flag 0"),
    ("6", "action 108 dispatches to func_00297390"),
    ("7", "action 104 dispatches to func_002c29e0"),
    ("8", "action 513 same team aborts before target buffers"),
    ("9", "action 513 type 4 unit dispatches to func_002bfe30"),
    ("10", "action 513 type 21 unit dispatches to func_002b9770 and func_002a0420"),
    ("11", "action 513 target type 60 aborts before mutation"),
    ("12", "action 513 found candidate is assigned and dispatched"),
]


@pytest.fixture(scope="module")
def dispatcher_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("dispatcher") / "trade-action-dispatcher-test"
    result = subprocess.run(
        [
            compiler,
            "-m32",
            "-fno-builtin",
            "-Iinclude",
            "src/trade_action_dispatcher.cpp",
            "tests/native/trade_action_dispatcher_test.cpp",
            "tests/native/trade_action_dispatcher_test_support.cpp",
            "tests/native/trade_action_dispatcher_cases_part1.cpp",
            "tests/native/trade_action_dispatcher_cases_part2.cpp",
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
def test_dispatcher_behavior(dispatcher_test_binary, case, description):
    """Check trade_action_dispatcher execution in isolated native process."""
    result = subprocess.run(
        [str(dispatcher_test_binary), case], capture_output=True, text=True
    )
    assert result.returncode == 0, f"{description}: {result.stderr}"


MUTANTS = [
    (
        "action_114_flag",
        "func_002a03c0(target_list, item_id, 1);",
        "func_002a03c0(target_list, item_id, 0);",
        "g_2a03c0_last_flag == 1",
    ),
    (
        "action_109_flag",
        "func_002a03f0(target_list, item_id, 1);",
        "func_002a03f0(target_list, item_id, 0);",
        "g_2a03f0_last_flag == 1",
    ),
    (
        "action_513_type4_ids",
        "func_002bfe30(self, item_number, short_at(target, 36));",
        "func_002bfe30(self, short_at(target, 36), item_number);",
        "g_2bfe30_last_id1 == 41",
    ),
]


@pytest.mark.parametrize(
    "name,original,mutated,diagnostic",
    MUTANTS,
    ids=[item[0] for item in MUTANTS],
)
def test_dispatcher_source_mutants_fail_at_expected_assertion(
    tmp_path, name, original, mutated, diagnostic
):
    """Require compiled source mutants to hit their targeted native assertion."""
    source = (
        PROJECT_ROOT / "src" / "trade_action_dispatcher.cpp"
        if "513" in name
        else PROJECT_ROOT / "include" / "trade_action_dispatcher_direct.h"
    )
    source_name = source.name
    source_text = source.read_text()
    assert source_text.count(original) == 1, (
        f"{name} mutation anchor must be unique"
    )
    mutant_source = tmp_path / source_name
    mutant_source.write_text(source_text.replace(original, mutated, 1))
    binary = tmp_path / f"trade-action-dispatcher-{name}-mutant"
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
            str(mutant_source)
            if source.suffix == ".cpp"
            else "src/trade_action_dispatcher.cpp",
            "tests/native/trade_action_dispatcher_test.cpp",
            "tests/native/trade_action_dispatcher_test_support.cpp",
            "tests/native/trade_action_dispatcher_cases_part1.cpp",
            "tests/native/trade_action_dispatcher_cases_part2.cpp",
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
    case_num = "9" if "513" in name else "2" if "114" in name else "4"
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
