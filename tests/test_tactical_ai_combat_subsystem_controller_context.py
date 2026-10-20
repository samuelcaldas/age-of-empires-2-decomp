"""Exercise reference contracts and kill mutations for func_0032BF70."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_controller_context.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_context_test.cpp"
)
MUTATIONS = [
    ("corrupt_gate_return", "if (!check_context_gate()) {\n        return 0;\n    }", "if (!check_context_gate()) {\n        return 1;\n    }", "gate_rejection", "unsupported mode must return 0"),
    ("corrupt_active_190_check", "if (self->m_field_190 != 0) {", "if (self->m_field_190 == 0) {", "active_190", "must call func_110 once"),
    ("corrupt_1f65a0_call", "func_1F65A0(self);", "/* omitted */", "idle_fallback", "must call func_1F65A0 once"),
    ("corrupt_state_20_check", "if (D_004E3180->m_field_1CC == 20)", "if (D_004E3180->m_field_1CC == 21)", "state_20_hit", "must call func_0032D400 once"),
    ("corrupt_v8c_call", "view->m_vtable->func_8C(view, -1);", "/* omitted */", "state_20_hit", "must dispatch func_8C on hit 52"),
    ("corrupt_busy_check", "if (func_185DC0(D_004E3180) != 0)", "if (func_185DC0(D_004E3180) == 0)", "busy", "busy manager must return 0"),
    ("corrupt_busy_return", "if (func_185DC0(D_004E3180) != 0) {\n        return 0;\n    }", "if (func_185DC0(D_004E3180) != 0) {\n        return 1;\n    }", "busy", "busy manager must return 0"),
    ("corrupt_225590_arg", "func_225590(18);", "func_225590(19);", "idle_fallback", "func_225590 arg must be 18"),
    ("corrupt_fallback_v28", "func_205EE0(self->m_target);\n        self->m_vtable->func_28(self, 1);", "func_205EE0(self->m_target);\n        self->m_vtable->func_28(self, 0);", "idle_fallback", "view func_28 a1 must be 1"),
    ("corrupt_state_21_dispatch", "func_31A720(self, -1, -1, -1, -1);", "/* omitted */", "state_21", "must call func_31A720 once"),
    ("corrupt_t0_zero_dispatch", "self->m_vtable->func_12C(self, a1, a2, 1, -1);", "/* omitted */", "t0_split", "must call view func_12C once"),
    ("corrupt_t0_nonzero_32d400", "func_0032D400(self, 40, 0, a1, a2, buf2, 0, 1)", "func_0032D400(self, 41, 0, a1, a2, buf2, 0, 1)", "t0_split", "func_0032D400 a1 must be 40"),
    ("corrupt_sub_a0_check", "D_004E3180->m_sub_a0->m_val_a0 == 2", "D_004E3180->m_sub_a0->m_val_a0 == 3", "state_21", "must call func_31A720 once"),
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


def test_controller_context_reference_contract(tmp_path):
    """Check mode validation, active field_190, state 20 dispatch, busy rejection, and fallback routing."""
    binary = tmp_path / "ctrl_context_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_context_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
