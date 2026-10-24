"""Native regression tests for trade_action_type_checker."""

from pathlib import Path
import shutil
import subprocess

import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]


@pytest.fixture(scope="module")
def type_checker_binary(tmp_path_factory):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("type_checker") / "trade-action-type-checker-test"
    result = subprocess.run(
        [
            compiler,
            "-m32",
            "-fno-builtin",
            "-Iinclude",
            "src/trade/trade_action_type_checker.cpp",
            "tests/native/trade_action_type_checker_test.cpp",
            "-o",
            str(binary),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, result.stderr
    return binary


def test_type_checker_behavior(type_checker_binary):
    result = subprocess.run(
        [str(type_checker_binary)],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"type checker failed:\nstdout:\n{result.stdout}\nstderr:\n{result.stderr}"
    assert "TRADE ACTION TYPE CHECKER TEST PASSED" in result.stdout


@pytest.mark.parametrize(
    ("name", "orig_str", "mutated_str", "expected_err"),
    [
        ("inverted_return", "return 1;", "return 0;", "Assertion `res1 == 1' failed"),
        ("corrupted_root", "2968", "2972", "Assertion `g_last_lookup_root == reinterpret_cast<void*>(0x1234)' failed"),
        ("corrupted_item_id", "func_332e60(group->m_root, item_id)", "func_332e60(group->m_root, item_id + 1)", "Assertion `g_last_lookup_item_id == 10' failed"),
    ],
)
def test_type_checker_mutants_fail(tmp_path, name, orig_str, mutated_str, expected_err):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")

    src = (PROJECT_ROOT / "src/trade" / "trade_action_type_checker.cpp").read_text()
    assert orig_str in src, f"Expected '{orig_str}' in source"
    mutant_src = src.replace(orig_str, mutated_str, 1)

    mutant_file = tmp_path / f"mutant_{name}.cpp"
    mutant_file.write_text(mutant_src)

    binary = tmp_path / f"bin_{name}"
    comp_res = subprocess.run(
        [
            compiler,
            "-m32",
            "-fno-builtin",
            "-Iinclude",
            str(mutant_file),
            "tests/native/trade_action_type_checker_test.cpp",
            "-o",
            str(binary),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
    )
    assert comp_res.returncode == 0, comp_res.stderr

    run_res = subprocess.run([str(binary)], capture_output=True, text=True)
    assert run_res.returncode != 0, f"Mutant {name} unexpectedly passed!"
    assert expected_err in run_res.stderr, f"Mutant {name} error mismatch:\n{run_res.stderr}"
