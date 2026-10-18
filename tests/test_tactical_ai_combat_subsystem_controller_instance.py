"""Exercise reference contracts and kill mutations for func_003291F0."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_controller_instance.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_instance_test.cpp"
)
MUTATIONS = [
    ("omit_base_call", "func_318340(self);", "/* omitted */", "base_call", "base constructor must be called exactly once"),
    ("corrupt_vtable", "self->m_vtable = D_004DED20;", "self->m_vtable = 0;", "vtable", "vtable pointer must be set to D_004DED20"),
    ("corrupt_field_dc", "self->m_field_DC = 10;", "self->m_field_DC = 0;", "field_dc", "field_DC must be initialized to 10"),
    ("corrupt_field_2398", "self->m_field_2398 = 41;", "self->m_field_2398 = 0;", "field_2398", "field_2398 must be initialized to 41"),
    ("corrupt_field_341c", "self->m_field_341C = 1;", "self->m_field_341C = 0;", "scalar_flags", "field_341C must be 1"),
    ("corrupt_table_zero", "self->m_field_3434[i] = 0;", "self->m_field_3434[i] = 1;", "table_entries", "field_3434 array slot must be 0"),
    ("corrupt_table_negative", "self->m_field_345C[i] = -1;", "self->m_field_345C[i] = 0;", "table_entries", "field_345C array slot must be -1"),
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


def test_controller_instance_reference_contract(tmp_path):
    """Check base constructor, vtable, fields, slot tables, and return value."""
    binary = tmp_path / "ctrl_inst_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_instance_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
