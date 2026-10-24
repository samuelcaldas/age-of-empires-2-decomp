"""Exercise reference contracts and kill mutations for func_0032E640."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_decrement_by_id.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_decrement_by_id_test.cpp"
)
MUTATIONS = [
    ("corrupt_active_check", "entry->active == 1", "entry->active != 1", "inactive", "inactive entry count must not be decremented"),
    ("corrupt_active_val", "entry->active == 1", "entry->active == 0", "one_match", "matching active entry count must be decremented by decrement value"),
    ("corrupt_id_check", "entry->id == id", "entry->id != id", "mismatch", "mismatched id entry count must not be decremented"),
    ("corrupt_decrement_op", "entry->count -= entry->decrement;", "entry->count += entry->decrement;", "one_match", "matching active entry count must be decremented by decrement value"),
    ("corrupt_decrement_val", "entry->count -= entry->decrement;", "entry->count -= 1;", "one_match", "matching active entry count must be decremented by decrement value"),
    ("corrupt_loop_break", "entry->count -= entry->decrement;", "entry->count -= entry->decrement; break;", "multiple", "second matching entry count must be 270"),
    ("corrupt_loop_start", "int i = 0;", "int i = 1;", "multiple", "first matching entry count must be 90"),
    ("corrupt_zero_bound", "i < self->m_count", "i < 1", "zero_count", "zero count table must not be decremented"),
    ("corrupt_count_target", "entry->count -=", "entry->id -=", "one_match", "matching active entry count must be decremented by decrement value"),
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


def test_controller_decrement_by_id_reference_contract(tmp_path):
    """Check single match decrement, zero entries, inactive/mismatched entries, and multiple matches."""
    binary = tmp_path / "ctrl_dec_by_id_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_decrement_by_id_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
