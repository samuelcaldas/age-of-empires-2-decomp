"""Exercise reference contracts and kill mutations for func_0032A060."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_action.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_action_test.cpp"
)
MUTATIONS = [
    ("corrupt_gate_return", "if (!check_action_gate()) {\n        return 0;\n    }", "if (!check_action_gate()) {\n        return 1;\n    }", "gate_rejection", "busy manager must return 0"),
    ("corrupt_default_return", "return 1;\n}", "return 0;\n}", "default_state", "default state must return 1"),
    ("corrupt_state_18_check", "case 18:", "case 17:", "state_18_success", "state 18 must call func_0032D400 once"),
    ("corrupt_res_check", "if ((res & 0xFF) == 52)", "if ((res & 0xFF) == 53)", "state_18_success", "state 18 must call func_205EE0"),
    ("corrupt_ee0_call", "func_205EE0(self->m_target);", "/* omitted */", "state_18_success", "state 18 must call func_205EE0"),
    ("corrupt_ca0_call", "func_205CA0(self->m_target, item, 1);", "func_205CA0(self->m_target, item, 0);", "state_18_success", "state 18 func_205CA0 flag must be 1"),
    ("corrupt_v28_call", "self->m_vtable->func_28(self, 1);", "/* omitted */", "state_18_success", "state 18 must call view func_28"),
    ("corrupt_state_1_check", "case 1:", "case 2:", "state_1_success", "state 1 must call func_0032D400 once"),
    ("corrupt_state_1_res", "if ((res & 0xFF) == 51)", "if ((res & 0xFF) == 50)", "state_1_success", "state 1 must call func_0032E580"),
    ("corrupt_state_1_e580", "func_0032E580(self, buf);", "/* omitted */", "state_1_success", "state 1 must call func_0032E580"),
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


def test_controller_action_reference_contract(tmp_path):
    """Check mode validation, action state machine dispatch, target resolution, and callbacks."""
    binary = tmp_path / "ctrl_action_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_action_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
