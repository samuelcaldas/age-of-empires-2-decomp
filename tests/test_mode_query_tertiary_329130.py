"""Exercise reference contracts and kill mutations for func_00329130."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/mode_query_tertiary_329130.cpp"
NATIVE_TEST = ROOT / "tests/native/mode_query_tertiary_329130_test.cpp"
MUTATIONS = [
    ("invert_global_guard", "if (!D_004E2EA0)", "if (D_004E2EA0)", "null_global", "null global guard return 0 failed"),
    ("invert_func_1A5010", "if (func_1A5010(self, a1, a2, &x, &y, &extra))", "if (!func_1A5010(self, a1, a2, &x, &y, &extra))", "active_query", "active query secondary call count failed"),
    ("corrupt_h_offset", "float h = 0.5f;", "float h = 0.0f;", "active_query", "active query secondary fx coordinate mismatch"),
    ("corrupt_mask", "res = (unsigned char)mgr->query(0, h + x, h + y);", "res = (int)mgr->query(0, h + x, h + y);", "active_query", "active query return value masking failed"),
    ("omit_notify", "((GlobalContextNotify *)D_004E3180)->notify(0, 0);", "/* omitted */", "rejected_query", "rejected query must call global notify"),
    ("corrupt_notify_arg", "((GlobalContextNotify *)D_004E3180)->notify(0, 0);", "((GlobalContextNotify *)D_004E3180)->notify(1, 0);", "rejected_query", "rejected query global notify arg1 mismatch"),
    ("corrupt_return", "return res;", "return (res == 0);", "active_query", "active query return value masking failed"),
]


def compile_native(source, binary):
    """Compile a 32-bit candidate with the native contract fixture."""
    command = [
        "g++", "-std=c++11", "-O2", "-m32", "-fno-builtin",
        "-Wall", "-Wextra", "-Werror", "-fsanitize=undefined",
        "-fno-sanitize-recover=all", "-I", str(ROOT / "include"),
        str(source), str(NATIVE_TEST), "-o", str(binary),
    ]
    result = subprocess.run(command, capture_output=True, text=True, timeout=60)
    assert result.returncode == 0, result.stderr


def run_native(binary, arg=None):
    """Run one fixture process with optional test argument."""
    cmd = [str(binary)]
    if arg:
        cmd.append(arg)
    return subprocess.run(
        cmd, capture_output=True, text=True, timeout=10,
    )


def test_mode_query_reference_contract(tmp_path):
    """Check guard clauses, active query execution, secondary dispatch, and global notify."""
    binary = tmp_path / "mode_query_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_mode_query_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
    """Verify that every production source mutation fails via the specific expected assertion diagnostic."""
    source = SOURCE.read_text()
    assert original in source, f"Missing mutation anchor: {name}"
    mutated = tmp_path / f"{name}.cpp"
    mutated.write_text(source.replace(original, replacement))
    binary = tmp_path / name
    compile_native(mutated, binary)
    result = run_native(binary, test_arg)
    assert result.returncode != 0, f"Mutation survived without failure: {name}"
    assert expected_msg in result.stderr, f"Mutation killed by wrong failure or crash instead of expected assertion '{expected_msg}': {name}\nStderr: {result.stderr}"
