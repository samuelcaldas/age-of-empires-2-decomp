"""Exercise reference contracts and kill mutations for func_0032C320."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_pulse.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_pulse_test.cpp"
)
MUTATIONS = [
    ("corrupt_return_prop", "int ret = func_00323860(self);", "int ret = func_00323860(self) + 1;", "return_prop", "must propagate func_00323860 return value 42"),
    ("corrupt_view_v28_call", "view->m_vtable->func_28(view, 1);", "view->m_vtable->func_28(view, 0);", "view_cb", "view func_28 a1 must be 1"),
    ("corrupt_gate_341c", "if (self->m_field_341C == 0)", "if (self->m_field_341C != 0)", "gates", "must suppress func_1880D0 on m_field_341C==0"),
    ("corrupt_gate_1880d0", "if (func_1880D0(D_004E3180) == 0)", "if (func_1880D0(D_004E3180) != 0)", "gates", "must suppress division on func_1880D0==0"),
    ("corrupt_gate_190", "if (self->m_field_190 != 2)", "if (self->m_field_190 == 2)", "gates", "must suppress division on m_field_190!=2"),
    ("corrupt_den_clamp", "if (den == 0) {\n        den = 1;\n    }", "/* omitted */", "division", "division by zero"),
    ("corrupt_threshold", "if (quotient < 81)", "if (quotient < 80)", "division", "m_field_3424 must not be set when quotient < 81"),
    ("corrupt_3424_set", "self->m_field_3424 = 1;", "self->m_field_3424 = 0;", "idle_success", "m_field_3424 must be set to 1"),
    ("corrupt_busy_check", "if (func_185DC0(D_004E3180) != 0)", "if (func_185DC0(D_004E3180) == 0)", "idle_success", "must call func_185F00 once"),
    ("corrupt_185f00_a1", "func_185F00(D_004E3180, 1, 1);", "func_185F00(D_004E3180, 0, 1);", "idle_success", "func_185F00 a1 must be 1"),
    ("corrupt_3420_set", "self->m_field_3420 = 1;", "self->m_field_3420 = 0;", "idle_success", "m_field_3420 must be set to 1"),
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


def test_controller_pulse_reference_contract(tmp_path):
    """Check return propagation, view callback, early gates, division threshold, and idle success."""
    binary = tmp_path / "ctrl_pulse_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_pulse_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
