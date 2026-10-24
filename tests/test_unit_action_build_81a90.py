import subprocess
from pathlib import Path
import pytest

REPO_ROOT = Path(__file__).resolve().parents[1]
SRC_FILE = REPO_ROOT / "src/unit" / "unit_action_build_81a90.cpp"
TEST_FILE = REPO_ROOT / "tests" / "native" / "unit_action_build_81a90_test.cpp"
INCLUDE_DIR = REPO_ROOT / "include"


@pytest.fixture(scope="module")
def native_binary(tmp_path_factory):
    bin_path = tmp_path_factory.mktemp("bin") / "unit_action_build_81a90_test"
    cmd = [
        "g++",
        "-m32",
        "-O0",
        "-g",
        "-std=c++98",
        f"-I{INCLUDE_DIR}",
        str(SRC_FILE),
        str(TEST_FILE),
        "-o",
        str(bin_path),
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"
    return bin_path


def test_build_81a90_behavior(native_binary):
    """Run native behavioral test suite for func_00281A90."""
    res = subprocess.run([str(native_binary)], capture_output=True, text=True)
    assert res.returncode == 0, f"Test failed: {res.stderr}\n{res.stdout}"


@pytest.mark.parametrize(
    "name,original,replacement",
    [
        (
            "no_flag_set",
            "D_4E3414 = 1;",
            "/* D_4E3414 = 1; */",
        ),
        (
            "mutate_filter_72",
            "if (building_id == 72) return;",
            "if (building_id == 73) return;",
        ),
        (
            "mutate_filter_117",
            "if (building_id == 117) return;",
            "if (building_id == 118) return;",
        ),
        (
            "mutate_filter_neg399",
            "if (building_id == -399) return;",
            "if (building_id == -400) return;",
        ),
        (
            "mutate_range_upper",
            "int v = (building_id < -397);",
            "int v = (building_id < -398);",
        ),
        (
            "skip_validation_1",
            "if (!func_00203010(D_4E3420, building_id)) {",
            "if (0) {",
        ),
        (
            "mutate_ratio",
            "1.0f",
            "0.5f",
        ),
        (
            "skip_resolution_check",
            "if (id == -1) {",
            "if (0) {",
        ),
    ],
)
def test_build_81a90_rejects_mutations(tmp_path, name, original, replacement):
    """Verify that intentional logic mutations in unit_action_build_81a90 fail the native tests."""
    src_content = SRC_FILE.read_text(encoding="utf-8")
    assert original in src_content, f"Mutation target {original!r} not found for {name}"
    mutated_src = src_content.replace(original, replacement, 1)

    mutated_file = tmp_path / "mutated_unit_action_build_81a90.cpp"
    mutated_file.write_text(mutated_src, encoding="utf-8")

    bin_path = tmp_path / f"test_{name}"
    cmd = [
        "g++",
        "-m32",
        "-O0",
        "-g",
        "-std=c++98",
        f"-I{INCLUDE_DIR}",
        str(mutated_file),
        str(TEST_FILE),
        "-o",
        str(bin_path),
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True)
    assert compile_res.returncode == 0, f"Mutation {name} failed compilation unexpectedly: {compile_res.stderr}"

    run_res = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert run_res.returncode != 0, f"Mutation {name} was not caught by test suite! Binary returned 0."
