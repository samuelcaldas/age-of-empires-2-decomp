"""Exercise reference contracts and kill mutations for func_0032A8F0."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_controller_event.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_event_test.cpp"
)
MUTATIONS = [
    ("corrupt_gate_return", "if (!check_event_gate()) {\n        return 0;\n    }", "if (!check_event_gate()) {\n        return 1;\n    }", "gate_rejection", "unsupported mode must return 0"),
    ("corrupt_busy_return", "if (func_185DC0(D_004E3180) != 0) {\n        if (self->m_field_190 != 0) {\n            self->m_vtable->func_110(self);\n        } else {\n            func_1F65A0(self);\n        }\n        return 0;\n    }", "if (func_185DC0(D_004E3180) != 0) {\n        if (self->m_field_190 != 0) {\n            self->m_vtable->func_110(self);\n        } else {\n            func_1F65A0(self);\n        }\n        return 1;\n    }", "busy_branches", "busy manager branch must return 0"),
    ("invert_busy_190", "if (self->m_field_190 != 0) {\n            self->m_vtable->func_110(self);", "if (self->m_field_190 == 0) {\n            self->m_vtable->func_110(self);", "busy_branches", "busy with field_190 must call func_110"),
    ("corrupt_idle_190", "self->m_vtable->func_10C(self, a1, a2);\n        return 1;", "/* omitted */\n        return 1;", "idle_field_190", "idle field_190 must call func_10C"),
    ("corrupt_state_178_call", "self->m_vtable->func_28(self, 1);", "self->m_vtable->func_28(self, 0);", "idle_state_1_7_8", "func_28 a1 mismatch"),
    ("corrupt_other_v108", "self->m_vtable->func_108(self, 2, self->m_field_E0, self->m_field_E4, a3, a4);", "self->m_vtable->func_108(self, 1, self->m_field_E0, self->m_field_E4, a3, a4);", "idle_state_other", "func_108 a1 must be 2"),
    ("corrupt_other_v10c", "self->m_vtable->func_10C(self, a1, a2);\n    return 1;", "/* omitted */\n    return 1;", "idle_state_other", "state other must call func_10C"),
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


def test_controller_event_reference_contract(tmp_path):
    """Check mode validation, busy/idle manager routing, field_190 branching, and callback dispatch."""
    binary = tmp_path / "ctrl_event_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_event_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
