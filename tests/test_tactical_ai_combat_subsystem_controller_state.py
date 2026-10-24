"""Exercise reference contracts and kill mutations for func_00329FA0."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_state.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_state_test.cpp"
)
MUTATIONS = [
    ("corrupt_gate_return", "return 0;", "return 1;", "gate_rejection", "unsupported mode must return 0"),
    ("corrupt_case_1", "field_1CC == 1", "field_1CC == 2", "cases_1_7_8", "field_1CC 1 must call func_28 once"),
    ("corrupt_case_7", "field_1CC == 7", "field_1CC == 6", "cases_1_7_8", "field_1CC 7 must call func_28 once"),
    ("corrupt_case_8", "field_1CC == 8", "field_1CC == 9", "cases_1_7_8", "field_1CC 8 must call func_28 once"),
    ("corrupt_notify_arg", "self->m_vtable->func_28(self, 1);", "self->m_vtable->func_28(self, 0);", "cases_1_7_8", "func_28 argument must be 1"),
    ("corrupt_success_return", "return 1;", "return 0;", "other_cases", "field_1CC 0 must return 1"),
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


def test_controller_state_reference_contract(tmp_path):
    """Check mode validation, field_1CC set evaluation, view notification, and return paths."""
    binary = tmp_path / "ctrl_state_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_state_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
