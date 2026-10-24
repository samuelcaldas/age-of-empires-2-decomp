"""Native semantic regressions for zone_screen_to_world."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
PROBE_SOURCE = """
#include <cassert>
#include <cstddef>
#include <cstring>
int main() {
    static_assert(sizeof(void *) == 4, "requires 32-bit pointers");
    static_assert(sizeof(int) == 4, "requires 32-bit integers");
}
"""

CASES = [
    ("case0_exact", "Transforms flat terrain screen coordinates to exact isometric world space (0.25, 0.25)"),
    ("case1_case5", "Calculates distinct slope-adjusted elevation offsets for cases 1 and 5"),
    ("case9_case13", "Calculates distinct slope-adjusted elevation offsets for cases 9 and 13"),
    ("all_cases", "Validates that all 17 slope cases execute valid math and produce distinct world coordinates"),
    ("default_cases", "When command byte is 17 or 255, branches to common calculation with selected_term=0 and writes outputs"),
    ("float_rounding", "Verifies floatX rounding occurs before Y subtraction preserving IEEE 754 precision"),
    ("dual_sided_slopes", "Verifies both positive and negative branches for all conditional slope commands"),
]


@pytest.fixture(scope="module")
def zone_screen_world_test_binary(tmp_path_factory):
    """Compile production zone_screen_to_world source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-s2w-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-s2w-test"
    sources = [
        "src/zone/zone_screen_to_world.cpp",
        "tests/native/zone_screen_to_world_test.cpp",
    ]
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude"] + sources + ["-o", str(binary)],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[c[0] for c in CASES])
def test_zone_screen_to_world_cases(zone_screen_world_test_binary, case, description):
    """Verify screen to world de-rotation, scale factors, jump table cases, and bounds guard."""
    result = subprocess.run(
        [str(zone_screen_world_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"


def test_zone_screen_to_world_old_formula_mutant_fails(tmp_path):
    """Ensure that the old erroneous multiplication formula fails the regression suite."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")

    src = (PROJECT_ROOT / "src/zone" / "zone_screen_to_world.cpp").read_text()
    # Mutate addition to multiplication: sum_term = s2 + ((2.0 * fy - 1.0) + 2.0 * fx) -> * 2.0 * fx
    target = "int64_t sum_term = func_122058(s2, func_122058(two_fy_minus_one, two_fx));"
    mutated = "int64_t sum_term = func_122058(s2, func_122118(two_fy_minus_one, two_fx));"
    mutated_src = src.replace(target, mutated)
    assert mutated_src != src, "mutation target not found"

    mut_src_file = tmp_path / "zone_screen_to_world_mut.cpp"
    mut_src_file.write_text(mutated_src)
    mut_bin = tmp_path / "zone-s2w-mut-bin"

    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude", str(mut_src_file), "tests/native/zone_screen_to_world_test.cpp", "-o", str(mut_bin)],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    res = subprocess.run([str(mut_bin), "case0_exact"], capture_output=True, text=True)
    assert res.returncode in (-6, 134), f"Expected SIGABRT but got returncode {res.returncode}"
    assert "Assertion" in res.stderr
    assert "zone_screen_to_world_test.cpp" in res.stderr
    assert "out_x == 0.25f" in res.stderr


def test_zone_screen_to_world_early_return_mutant_fails(tmp_path):
    """Ensure that the old erroneous early return on cmd > 16 fails default_cases."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")

    src = (PROJECT_ROOT / "src/zone" / "zone_screen_to_world.cpp").read_text()
    # Mutate to early return when cmd > 16
    target = "int64_t s2 = 0;"
    mutated = "if (cmd > 16) return;\n    int64_t s2 = 0;"
    mutated_src = src.replace(target, mutated)
    assert mutated_src != src, "mutation target not found"

    mut_src_file = tmp_path / "zone_screen_to_world_mut2.cpp"
    mut_src_file.write_text(mutated_src)
    mut_bin = tmp_path / "zone-s2w-mut2-bin"

    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude", str(mut_src_file), "tests/native/zone_screen_to_world_test.cpp", "-o", str(mut_bin)],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    res = subprocess.run([str(mut_bin), "default_cases"], capture_output=True, text=True)
    assert res.returncode in (-6, 134), f"Expected SIGABRT but got returncode {res.returncode}"
    assert "Assertion" in res.stderr
    assert "zone_screen_to_world_test.cpp" in res.stderr
    assert "out_x == 0.25f" in res.stderr


def test_zone_screen_to_world_cmd11_slope_mutant_fails(tmp_path):
    """Ensure that mutating the slope term in case 11 fails dual_sided_slopes assertions."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")

    src = (PROJECT_ROOT / "src/zone" / "zone_screen_to_world.cpp").read_text()
    target = "s2 = func_122118(FP_TWO, func_1220B0(FP_HALF, fx));"
    mutated = "s2 = func_122058(FP_TWO, func_1220B0(FP_HALF, fx));"
    mutated_src = src.replace(target, mutated)
    assert mutated_src != src, "mutation target not found"

    mut_src_file = tmp_path / "zone_screen_to_world_mut3.cpp"
    mut_src_file.write_text(mutated_src)
    mut_bin = tmp_path / "zone-s2w-mut3-bin"

    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude", str(mut_src_file), "tests/native/zone_screen_to_world_test.cpp", "-o", str(mut_bin)],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    res = subprocess.run([str(mut_bin), "dual_sided_slopes"], capture_output=True, text=True)
    assert res.returncode in (-6, 134), f"Expected SIGABRT but got returncode {res.returncode}"
    assert "Assertion" in res.stderr
    assert "zone_screen_to_world_test.cpp" in res.stderr
    assert "ox11_a == 1.0f" in res.stderr


def test_zone_screen_to_world_cmd2_family_mutant_fails(tmp_path):
    """Mutant A: Swapping term selection in case 2 triggers dual_sided_slopes assertion failure."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")

    src = (PROJECT_ROOT / "src/zone" / "zone_screen_to_world.cpp").read_text()
    target = """    case 2:
        if (func_100170(fx, FP_HALF)) {
            s2 = func_1220B0(func_1223C0(fx, FP_NEG2), func_1220B0(fy, FP_HALF));
        } else {
            s2 = func_1220B0(func_1223C0(func_1220B0(FP_ONE, fx), FP_NEG2), func_1220B0(fy, FP_HALF));
        }
        break;"""
    mutated = """    case 2:
        if (func_100170(fx, FP_HALF)) {
            s2 = func_1220B0(func_1223C0(func_1220B0(FP_ONE, fx), FP_NEG2), func_1220B0(fy, FP_HALF));
        } else {
            s2 = func_1220B0(func_1223C0(fx, FP_NEG2), func_1220B0(fy, FP_HALF));
        }
        break;"""
    mutated_src = src.replace(target, mutated)
    assert mutated_src != src, "mutation target for case 2 not found"

    mut_src_file = tmp_path / "zone_screen_to_world_mut_cmd2.cpp"
    mut_src_file.write_text(mutated_src)
    mut_bin = tmp_path / "zone-s2w-mut-cmd2-bin"

    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude", str(mut_src_file), "tests/native/zone_screen_to_world_test.cpp", "-o", str(mut_bin)],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    res = subprocess.run([str(mut_bin), "dual_sided_slopes"], capture_output=True, text=True)
    assert res.returncode in (-6, 134), f"Expected SIGABRT but got returncode {res.returncode}"
    assert "Assertion" in res.stderr
    assert "zone_screen_to_world_test.cpp" in res.stderr
    assert "ox2_a == 0.3125f" in res.stderr


def test_zone_screen_to_world_cmd3_family_mutant_fails(tmp_path):
    """Mutant B: Inverting raw screen_y condition in case 3 triggers dual_sided_slopes assertion failure."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")

    src = (PROJECT_ROOT / "src/zone" / "zone_screen_to_world.cpp").read_text()
    target = "if (func_100120(func_1223C0(fx, FP_TWO), s5_fp)) {"
    mutated = "if (func_100170(func_1223C0(fx, FP_TWO), s5_fp)) {"
    mutated_src = src.replace(target, mutated)
    assert mutated_src != src, "mutation target for case 3 not found"

    mut_src_file = tmp_path / "zone_screen_to_world_mut_cmd3.cpp"
    mut_src_file.write_text(mutated_src)
    mut_bin = tmp_path / "zone-s2w-mut-cmd3-bin"

    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude", str(mut_src_file), "tests/native/zone_screen_to_world_test.cpp", "-o", str(mut_bin)],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    res = subprocess.run([str(mut_bin), "dual_sided_slopes"], capture_output=True, text=True)
    assert res.returncode in (-6, 134), f"Expected SIGABRT but got returncode {res.returncode}"
    assert "Assertion" in res.stderr
    assert "zone_screen_to_world_test.cpp" in res.stderr
    assert "ox3_a == 1.9375f" in res.stderr


def test_zone_screen_to_world_cmd10_family_mutant_fails(tmp_path):
    """Mutant C: Inverting fy negation in case 10 triggers dual_sided_slopes assertion failure."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")

    src = (PROJECT_ROOT / "src/zone" / "zone_screen_to_world.cpp").read_text()
    target = "s2 = fy ^ FP_SIGN;"
    mutated = "s2 = fy;"
    mutated_src = src.replace(target, mutated)
    assert mutated_src != src, "mutation target for case 10 not found"

    mut_src_file = tmp_path / "zone_screen_to_world_mut_cmd10.cpp"
    mut_src_file.write_text(mutated_src)
    mut_bin = tmp_path / "zone-s2w-mut-cmd10-bin"

    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude", str(mut_src_file), "tests/native/zone_screen_to_world_test.cpp", "-o", str(mut_bin)],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    res = subprocess.run([str(mut_bin), "dual_sided_slopes"], capture_output=True, text=True)
    assert res.returncode in (-6, 134), f"Expected SIGABRT but got returncode {res.returncode}"
    assert "Assertion" in res.stderr
    assert "zone_screen_to_world_test.cpp" in res.stderr
    assert "ox10_a == 0.25f" in res.stderr




