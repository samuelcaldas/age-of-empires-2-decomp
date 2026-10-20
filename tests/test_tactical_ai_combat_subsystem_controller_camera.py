"""Exercise reference contracts and kill mutations for func_0032BCE0."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_controller_camera.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_camera_test.cpp"
)
MUTATIONS = [
    ("corrupt_gate_return", "if (!check_camera_gate()) {\n        return 0;\n    }", "if (!check_camera_gate()) {\n        return 1;\n    }", "gate_rejection", "unsupported mode must return 0"),
    ("corrupt_busy_check", "if (func_185DC0(D_004E3180) != 0) return false;", "/* omitted */", "gate_rejection", "busy manager must return 0"),
    ("corrupt_state_19_check", "if (D_004E3180->m_field_1CC == 19)", "if (D_004E3180->m_field_1CC == 20)", "state_19_sub", "state 19 must call func_205EE0 once"),
    ("corrupt_ee0_call", "func_205EE0(target);", "/* omitted */", "state_19_sub", "state 19 must call func_205EE0 once"),
    ("corrupt_v28_call", "self->m_vtable->func_28(self, 1);", "self->m_vtable->func_28(self, 0);", "state_19_sub", "view func_28 a1 must be 1"),
    ("corrupt_mgr_18_a1", "D_004E3180->m_vtable->func_18(D_004E3180, 19, 1);", "D_004E3180->m_vtable->func_18(D_004E3180, 18, 1);", "state_19_sub", "mgr func_18 a1 must be 19"),
    ("corrupt_v108_action", "self->m_vtable->func_108(self, 9, a1, a2, a3, a4);", "self->m_vtable->func_108(self, 8, a1, a2, a3, a4);", "state_19_sub", "view func_108 a1 must be 9"),
    ("corrupt_target_null_check", "if (target != 0 && target->m_sub_ca8 != 0)", "if (target == 0)", "state_19_null_target", "null target must fallback to func_1F6510 once"),
    ("corrupt_1f6510_call", "func_1F6510(self);", "/* omitted */", "state_19_nosub", "state 19 without sub_ca8 must call func_1F6510 once"),
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


def test_controller_camera_reference_contract(tmp_path):
    """Check mode validation, state 19 dispatch, sub_ca8 target routing, and manager notification."""
    binary = tmp_path / "ctrl_cam_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_camera_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
