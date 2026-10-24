"""Exercise reference contracts and kill mutations for func_00329450."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_lock.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_lock_test.cpp"
)
MUTATIONS = [
    ("corrupt_same_lock", "if (a1 == self->m_field_342C) {", "if (a1 != self->m_field_342C) {", "same_lock", "same lock should not perform manager calls"),
    ("corrupt_flag_gate", "if (self->m_field_341C == 0) {", "if (self->m_field_341C != 0) {", "flag_gate", "gate zero must not set field_3424"),
    ("corrupt_mgr_active", "if (func_1880D0(D_004E3180) == 0) {", "if (func_1880D0(D_004E3180) != 0) {", "mgr_inactive", "inactive mgr must not set field_3424"),
    ("corrupt_threshold", "if (v0 / s1 > 40) {", "if (v0 / s1 > 50) {", "enable_success", "enable success field_3424 must be 1"),
    ("corrupt_busy_check", "if (func_185DC0(D_004E3180) == 0) {", "if (func_185DC0(D_004E3180) != 0) {", "enable_success", "enable success field_3420 must be 1"),
    ("corrupt_mode_check", "if (self->m_field_3410 != 0) {", "if (self->m_field_3410 == 0) {", "disable_mode_active", "active mode disable must preserve field_3424"),
    ("corrupt_notify_lock", "func_185F00(D_004E3180, 1, 1);", "func_185F00(D_004E3180, 0, 1);", "enable_success", "enable success notify a1 mismatch"),
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


def test_controller_lock_reference_contract(tmp_path):
    """Check lock transitions, ratio threshold, mode active guard, and manager notification."""
    binary = tmp_path / "ctrl_lock_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_lock_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
