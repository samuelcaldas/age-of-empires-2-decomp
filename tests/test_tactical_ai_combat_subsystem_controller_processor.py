"""Exercise reference contracts and kill mutations for func_00329550."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_processor.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_processor_test.cpp"
)
MUTATIONS = [
    ("omit_gate_check", "if (!check_controller_gate(self))", "if (false)", "gate_rejection", "unsupported mode must return 0"),
    ("corrupt_gate_reset", "if (!check_controller_gate(self)) {\n        func_00329350(self, 0);", "if (!check_controller_gate(self)) {\n        func_00329350(self, 1);", "gate_rejection", "unsupported mode must reset mode to 0"),
    ("corrupt_center_reset", "if (s0 == 0 && s1 == 0) {\n        func_00329350(self, 0);", "if (s0 == 0 && s1 == 0) {\n        func_00329350(self, 1);", "center_idle", "center no-scroll must reset mode to 0"),
    ("wrong_enable_mode", "func_00329350(self, 1);", "func_00329350(self, 0);", "left_edge", "left edge mode call arg mismatch"),
    ("corrupt_left_movement", "func_204920(target, 0, target->m_x - speed, target->m_y - speed);", "func_204920(target, 0, target->m_x + speed, target->m_y + speed);", "left_edge", "left edge target X mismatch"),
    ("corrupt_right_movement", "func_204920(target, 0, target->m_x + speed, target->m_y + speed);", "func_204920(target, 0, target->m_x - speed, target->m_y - speed);", "right_edge", "right edge target X mismatch"),
    ("corrupt_time_update", "self->m_time_340C = now;", "self->m_time_340C = now + 1;", "left_edge", "left edge timestamp update failed"),
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


def test_controller_processor_reference_contract(tmp_path):
    """Check gate validation, bounds evaluation, movement dispatch, and callbacks."""
    binary = tmp_path / "ctrl_proc_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_processor_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
