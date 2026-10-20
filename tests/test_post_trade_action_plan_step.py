"""Native regression tests for post_trade_action_plan_step."""

from pathlib import Path
import shutil
import subprocess

import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]


@pytest.fixture(scope="module")
def plan_step_binary(tmp_path_factory):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("plan_step") / "post-trade-action-plan-step-test"
    result = subprocess.run(
        [
            compiler,
            "-m32",
            "-fno-builtin",
            "-Iinclude",
            "src/post_trade_action_plan_step.cpp",
            "tests/native/post_trade_action_plan_step_test.cpp",
            "-o",
            str(binary),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, result.stderr
    return binary


def test_plan_step_behavior(plan_step_binary):
    result = subprocess.run(
        [str(plan_step_binary)],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"test failed:\nstdout:\n{result.stdout}\nstderr:\n{result.stderr}"
    assert "POST TRADE ACTION PLAN STEP TEST PASSED" in result.stdout


@pytest.mark.parametrize(
    ("name", "orig_str", "mutated_str", "expected_err"),
    [
        (
            "corrupted_missing_item_return",
            "if (idx >= limit) {\n        return 0;\n    }",
            "if (idx >= limit) {\n        return 999;\n    }",
            "Assertion `res1 == 0' failed",
        ),
        (
            "corrupted_action_600",
            "== 600",
            "== 9999",
            "Assertion `g_action_1471a0_calls == 1' failed",
        ),
        (
            "inverted_rate_check",
            "rates1[field_4] > rates2[field_4]",
            "rates1[field_4] < rates2[field_4]",
            "Assertion `g_2c1920_calls == 1' failed",
        ),
        (
            "inverted_bubble_sort",
            "scores[k] < scores[k + 1]",
            "scores[k] > scores[k + 1]",
            "Assertion `g_last_2baa20_cat == 2' failed",
        ),
        (
            "corrupted_fallback_dispatch",
            "rec->m_item_id, -1, 1",
            "rec->m_item_id, 999, 1",
            "Assertion `g_last_2baa20_cat == -1' failed",
        ),
    ],
)
def test_plan_step_mutants_fail(tmp_path, name, orig_str, mutated_str, expected_err):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")

    src = (PROJECT_ROOT / "src" / "post_trade_action_plan_step.cpp").read_text()
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
            "tests/native/post_trade_action_plan_step_test.cpp",
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
