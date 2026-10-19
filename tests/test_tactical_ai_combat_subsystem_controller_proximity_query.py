"""Exercise reference contracts and kill mutations for func_0032DA90."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_controller_proximity_query.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_proximity_query_test.cpp"
)
MUTATIONS = [
    ("corrupt_out_status_zero", "*out_status = 0;", "*out_status = 1;", "zero_return", "out_status must be zeroed on entry"),
    ("corrupt_func120_gate", "if (res == 0)", "if (res != 0)", "zero_return", "func_120 zero return must return 0"),
    ("corrupt_func120_arg_a3", "10, 30, 15, 4, 1", "11, 30, 15, 4, 1", "zero_return", "func_120 a3 mismatch (10)"),
    ("corrupt_func120_arg_t0", "10, 30, 15, 4, 1", "10, 31, 15, 4, 1", "zero_return", "func_120 t0 mismatch (30)"),
    ("corrupt_func120_arg_t1", "10, 30, 15, 4, 1", "10, 30, 16, 4, 1", "zero_return", "func_120 t1 mismatch (15)"),
    ("corrupt_func120_arg_t2", "10, 30, 15, 4, 1", "10, 30, 15, 5, 1", "zero_return", "func_120 t2 mismatch (4)"),
    ("corrupt_func120_arg_t3", "10, 30, 15, 4, 1", "10, 30, 15, 4, 2", "zero_return", "func_120 t3 mismatch (1)"),
    ("corrupt_out_status_hit", "*out_status = 1;", "*out_status = 0;", "hit_return", "out_status must be set to 1 on hit"),
    ("corrupt_hit_return", "return 1;\n}", "return 0;\n}", "hit_return", "func_120 hit return must return 1"),
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
    """Run one fixture process, returning diagnostics and exit status."""
    cmd = [str(binary)]
    if arg:
        cmd.append(arg)
    return subprocess.run(
        cmd, capture_output=True, text=True, timeout=10,
    )


def test_controller_proximity_query_reference_contract(tmp_path):
    """Check ABI arguments, out_status zeroing, func_120 dispatch, and hit return."""
    binary = tmp_path / "ctrl_prox_query_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_proximity_query_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
    """Verify that every production source mutation fails via the specific expected assertion diagnostic."""
    source = SOURCE.read_text()
    assert original in source, f"Missing mutation anchor: {name}"
    mutated = tmp_path / f"{name}.cpp"
    mutated.write_text(source.replace(original, replacement, 1))
    binary = tmp_path / name
    compile_native(mutated, binary)
    result = run_native(binary, test_arg)
    assert result.returncode != 0, f"Mutation survived without failure: {name}"
    assert expected_msg in result.stderr, f"Mutation killed by wrong failure or crash instead of expected assertion '{expected_msg}': {name}\nStderr: {result.stderr}"
