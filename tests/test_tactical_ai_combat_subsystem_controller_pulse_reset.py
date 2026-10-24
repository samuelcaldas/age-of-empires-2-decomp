"""Exercise reference contracts and kill mutations for func_0032C480."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_pulse_reset.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_pulse_reset_test.cpp"
)
MUTATIONS = [
    ("corrupt_341c_gate", "if (self->m_field_341C != 0) {", "if (self->m_field_341C == 0) {", "full_reset", "m_field_3424 must be reset to 0"),
    ("corrupt_1880d0_gate", "if (func_1880D0(D_004E3180) != 0) {", "if (func_1880D0(D_004E3180) == 0) {", "full_reset", "m_field_3424 must be reset to 0"),
    ("corrupt_190_gate", "if (self->m_field_190 == 2) {", "if (self->m_field_190 != 2) {", "full_reset", "m_field_3424 must be reset to 0"),
    ("corrupt_clear_3424", "self->m_field_3424 = 0;", "/* omitted */", "full_reset", "m_field_3424 must be reset to 0"),
    ("corrupt_3420_check", "if (self->m_field_3420 != 0) {", "if (self->m_field_3420 == 0) {", "full_reset", "must call func_185F00 once"),
    ("corrupt_185f00_call", "func_185F00(D_004E3180, 0, 0);", "/* omitted */", "full_reset", "must call func_185F00 once"),
    ("corrupt_185f00_a1", "func_185F00(D_004E3180, 0, 0);", "func_185F00(D_004E3180, 1, 0);", "full_reset", "func_185F00 a1 must be 0"),
    ("corrupt_clear_3420", "self->m_field_3420 = 0;", "/* omitted */", "full_reset", "m_field_3420 must be reset to 0"),
    ("corrupt_324470_call", "func_00324470(self);", "/* omitted */", "full_reset", "must call func_00324470 once"),
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


def test_controller_pulse_reset_reference_contract(tmp_path):
    """Check full pulse reset, inactive 3420 path, and gate suppression."""
    binary = tmp_path / "ctrl_pulse_reset_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_pulse_reset_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
