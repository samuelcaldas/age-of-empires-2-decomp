"""Native semantic regressions for render_helper_217B50."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_00217B50 arg1=0 skips func_00213FA0"),
    ("1", "func_00217B50 0x128 retains value 4"),
    ("2", "func_00217B50 1A8 clearing path with vslot 1C(p, 0)"),
    ("3", "func_00217B50 callback 16C mutation with fresh pointer reload"),
    ("4", "func_00217B50 field 0x84 == 0 blocks vslot 1C dispatch"),
    ("5", "func_00217B50 tail store sentinel 0x12345678"),
    ("6", "func_00217B50 f140==0 bypasses division and sets 0x122=1"),
    ("7", "func_00217B50 normal division with zero numerator"),
    ("8", "func_00217B50 division by zero aborts execution (denom 0 case 1)"),
    ("9", "func_00217B50 division by zero aborts execution (denom 0 case 2)"),
]


@pytest.fixture(scope="module")
def helper_217B50_test(tmp_path_factory):
    """Compile render_helper_217B50 with test shim harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_helper_217B50 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-217B50")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-217B50-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-DTRADE_ACTION_HELPER_217B50_TEST_SHIM", "-Iinclude",
         "src/render/render_helper_217B50.cpp",
         "tests/native/render_helper_217B50_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_217B50_behavior(helper_217B50_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_217B50_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout


def test_mutation_break_code_6_source_proof(tmp_path):
    """Read source, assert count(kBreakCode = 7) == 1, write tmp copy with 6, compile with harness and assert case 8 fails with exact assertion."""
    source_path = PROJECT_ROOT / "src/render/render_helper_217B50.cpp"
    source_code = source_path.read_text(encoding="utf-8")
    assert source_code.count("enum { kBreakCode = 7 };") == 1

    mutated_code = source_code.replace("enum { kBreakCode = 7 };", "enum { kBreakCode = 6 };")
    mutated_src = tmp_path / "render_helper_217B50_mutated.cpp"
    mutated_src.write_text(mutated_code, encoding="utf-8")

    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("mutation proof requires g++")

    binary = tmp_path / "mutant-test"
    comp_result = subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-DTRADE_ACTION_HELPER_217B50_TEST_SHIM", "-Iinclude",
         str(mutated_src),
         str(PROJECT_ROOT / "tests/native/render_helper_217B50_test.cpp"),
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    assert comp_result.returncode == 0, f"Mutant compilation failed: {comp_result.stderr}"

    run_result = subprocess.run([str(binary), "8"], cwd=PROJECT_ROOT, capture_output=True, text=True)
    assert run_result.returncode == -6
    stderr = run_result.stderr
    assert "Assertion" in stderr
    assert "render_helper_217B50_test.cpp" in stderr
    assert "ex.code == 7" in stderr
