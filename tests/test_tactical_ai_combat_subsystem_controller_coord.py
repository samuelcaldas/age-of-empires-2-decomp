"""Exercise reference contracts and kill mutations for func_0032BE50."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_coord.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_coord_test.cpp"
)
MUTATIONS = [
    ("corrupt_gate_return", "if (!check_coord_gate()) {\n        return 0;\n    }", "if (!check_coord_gate()) {\n        return 1;\n    }", "gate_rejection", "unsupported mode must return 0"),
    ("corrupt_busy_check", "if (func_185DC0(D_004E3180) != 0)", "if (func_185DC0(D_004E3180) == 0)", "busy_active", "busy manager with active field must return 0"),
    ("corrupt_manager_arg", "func_185DC0(D_004E3180)", "func_185DC0((SystemManager*)((char*)D_004E3180 + 1))", "busy_active", "func_185DC0 must receive D_004E3180"),
    ("corrupt_busy_field_check", "if (self->m_field_190 != 0) {\n            self->m_vtable->func_110(self);", "if (self->m_field_190 == 0) {\n            self->m_vtable->func_110(self);", "busy_active", "must call func_110 once"),
    ("corrupt_busy_v110_call", "self->m_vtable->func_110(self);", "/* omitted */", "busy_active", "must call func_110 once"),
    ("corrupt_busy_1f65a0_call", "func_1F65A0(self);", "/* omitted */", "busy_inactive", "must call func_1F65A0 once"),
    ("corrupt_idle_field_check", "if (self->m_field_190 != 0) {\n        self->m_vtable->func_10C(self, a1, a2);", "if (self->m_field_190 == 0) {\n        self->m_vtable->func_10C(self, a1, a2);", "idle_active", "idle manager with active field must return 1"),
    ("corrupt_idle_v10c_call", "self->m_vtable->func_10C(self, a1, a2);", "self->m_vtable->func_110(self); (void)a1; (void)a2;", "idle_active", "must call func_10C once"),
    ("corrupt_idle_v10c_arg", "self->m_vtable->func_10C(self, a1, a2);", "self->m_vtable->func_10C(self, a1 + 1, a2);", "idle_active", "func_10C a1 mismatch"),
    ("corrupt_idle_active_return", "self->m_vtable->func_10C(self, a1, a2);\n        return 1;", "self->m_vtable->func_10C(self, a1, a2);\n        return 0;", "idle_active", "idle manager with active field must return 1"),
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


def test_controller_coord_reference_contract(tmp_path):
    """Check mode validation, busy dispatch, idle dispatch, and vtable notifications."""
    binary = tmp_path / "ctrl_coord_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_coord_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
