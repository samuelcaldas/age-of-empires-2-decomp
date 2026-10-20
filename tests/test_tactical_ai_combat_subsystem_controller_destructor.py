"""Exercise reference contracts and kill mutations for func_003292A0."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_controller_destructor.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_destructor_test.cpp"
)
MUTATIONS = [
    ("invert_null_check", "if (self != 0)", "if (self == 0)", "non_deleting", "destructor must install D_004DED20 vtable"),
    ("omit_vtable", "self->m_vtable = D_004DED20;", "/* omitted */", "non_deleting", "destructor must install D_004DED20 vtable"),
    ("omit_member_cleanup", "func_32E820(self);", "/* omitted */", "non_deleting", "member cleanup func_32E820 must be called once"),
    ("omit_base_dtor", "func_318760(self, 0);", "/* omitted */", "non_deleting", "base destructor func_318760 must be called once"),
    ("corrupt_base_arg", "func_318760(self, 0);", "func_318760(self, 1);", "non_deleting", "base destructor flags must be 0"),
    ("invert_delete_flag", "if ((short)flags > 0)", "if ((short)flags <= 0)", "non_deleting", "non-deleting destructor must not call operator delete"),
    ("omit_delete", "func_100670(self);", "/* omitted */", "deleting", "deleting destructor must call operator delete once"),
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


def test_controller_destructor_reference_contract(tmp_path):
    """Check null guard, member cleanup, base dtor, delete dispatch, and return value."""
    binary = tmp_path / "ctrl_dtor_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_destructor_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
