"""Native regression tests for post_trade_action_distance_candidates."""

from pathlib import Path
import shutil
import subprocess

import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]


@pytest.fixture(scope="module")
def distance_candidates_binary(tmp_path_factory):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("dist_cand") / "post-trade-action-distance-candidates-test"
    result = subprocess.run(
        [
            compiler,
            "-m32",
            "-fno-builtin",
            "-Iinclude",
            "src/trade/post_trade_action_distance_candidates.cpp",
            "tests/native/post_trade_action_distance_candidates_test.cpp",
            "-o",
            str(binary),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, result.stderr
    return binary


def test_distance_candidates_behavior(distance_candidates_binary):
    result = subprocess.run(
        [str(distance_candidates_binary)],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"test failed:\nstdout:\n{result.stdout}\nstderr:\n{result.stderr}"
    assert "POST TRADE ACTION DISTANCE CANDIDATES TEST PASSED" in result.stdout


@pytest.mark.parametrize(
    ("name", "orig_str", "mutated_str", "expected_err"),
    [
        ("corrupted_default_return", "int best_item = -1;", "int best_item = 999;", "Assertion `res1 == 42' failed"),
        ("corrupted_health_threshold", "> 7.0f", "> 99.0f", "Assertion `res4 == -1' failed"),
        ("corrupted_proto_check", "field8 == 259", "field8 == 9999", "Assertion `res3 == -1' failed"),
        ("inverted_distance_selection", "best_dist <= dist", "dist <= best_dist", "Assertion `res6 == 77' failed"),
    ],
)
def test_distance_candidates_mutants_fail(tmp_path, name, orig_str, mutated_str, expected_err):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")

    src = (PROJECT_ROOT / "src/trade" / "post_trade_action_distance_candidates.cpp").read_text()
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
            "tests/native/post_trade_action_distance_candidates_test.cpp",
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
