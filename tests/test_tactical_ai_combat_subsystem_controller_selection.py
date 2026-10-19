"""Exercise reference contracts and kill mutations for func_0032AAD0."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_controller_selection.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_selection_test.cpp"
)
MUTATIONS = [
    ("corrupt_gate_return", "if (!check_selection_gate()) {\n        return 0;\n    }", "if (!check_selection_gate()) {\n        return 1;\n    }", "gate_rejection", "unsupported mode must return 0"),
    ("corrupt_field_190_return", "if (self->m_field_190 != 0) {\n        self->m_vtable->func_110(self);\n        return 1;\n    }", "if (self->m_field_190 != 0) {\n        self->m_vtable->func_110(self);\n        return 0;\n    }", "field_190_branch", "field_190 branch must return 1"),
    ("corrupt_field_190_call", "self->m_vtable->func_110(self);", "/* omitted */", "field_190_branch", "field_190 branch must call func_110"),
    ("corrupt_busy_return", "if (func_185DC0(D_004E3180) != 0) {\n        return 0;\n    }", "if (func_185DC0(D_004E3180) != 0) {\n        return 1;\n    }", "busy_manager", "busy manager path must return 0"),
    ("corrupt_idle_return", "return 1;\n}", "return 0;\n}", "idle_manager", "idle manager path must return 1"),
    ("corrupt_1f65a0_call", "func_1F65A0(self);", "/* omitted */", "busy_manager", "busy manager path must call func_1F65A0"),
    ("corrupt_225590_arg", "func_225590(18);", "func_225590(19);", "idle_manager", "func_225590 argument must be 18"),
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


def test_controller_selection_reference_contract(tmp_path):
    """Check mode validation, field_190 branching, busy manager handling, and idle dispatch."""
    binary = tmp_path / "ctrl_sel_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_selection_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
