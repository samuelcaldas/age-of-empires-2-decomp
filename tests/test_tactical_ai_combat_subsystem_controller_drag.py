"""Exercise reference contracts and kill mutations for func_003299F0."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_drag.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_drag_test.cpp"
)
MUTATIONS = [
    ("omit_gate_check", "if (!check_drag_gate(self))", "if (false)", "gate_rejection", "busy manager must not query controller buffer"),
    ("corrupt_gate_lock", "if (!check_drag_gate(self)) {\n        func_00329450(self, 0);", "if (!check_drag_gate(self)) {\n        func_00329450(self, 1);", "gate_rejection", "busy manager must reset lock to 0"),
    ("corrupt_center_idle", "if (s2 == 0 && s3 == 0) {\n        func_00329450(self, 0);", "if (s2 == 0 && s3 == 0) {\n        func_00329450(self, 1);", "center_idle", "center idle must reset lock to 0"),
    ("corrupt_drag_enable", "func_00329450(self, 1);", "func_00329450(self, 0);", "drag_movement", "drag movement initial must set lock to 1"),
    ("corrupt_drag_movement_x", "func_204920(target, 0, target->m_x - speed, target->m_y - speed);", "func_204920(target, 0, target->m_x + speed, target->m_y - speed);", "drag_movement", "drag movement target X mismatch"),
    ("corrupt_drag_movement_y", "func_204920(target, 0, target->m_x - speed, target->m_y - speed);", "func_204920(target, 0, target->m_x - speed, target->m_y + speed);", "drag_movement", "drag movement target Y mismatch"),
    ("corrupt_drag_timestamp", "self->m_time_3428 = now;", "self->m_time_3428 = now + 1;", "drag_movement", "drag movement timestamp update failed"),
    ("corrupt_speed_clamping", "if (speed > sub28->m_max_speed_98) {\n            speed = sub28->m_max_speed_98;\n        }", "if (false) {\n            speed = sub28->m_max_speed_98;\n        }", "acceleration", "acceleration clamped speed target X mismatch"),
    ("corrupt_secondary_movement", "func_204920(target, 0, target->m_x - speed2, target->m_y + speed2);", "func_204920(target, 0, target->m_x + speed2, target->m_y + speed2);", "combined_inputs", "combined input last target X mismatch"),
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


def test_controller_drag_reference_contract(tmp_path):
    """Check gate validation, directional dispatch, velocity scaling, and callbacks."""
    binary = tmp_path / "ctrl_drag_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_drag_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
