"""Exercise reference contracts and kill mutations for func_0032E460."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_selection_box_clear.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_selection_box_clear_test.cpp"
)
MUTATIONS = [
    ("corrupt_31a720_call", "sub_31A720(self, -1, -1, -1, -1);", "/* omitted */", "clear_contracts", "must call sub_31A720 once"),
    ("corrupt_31a720_a1", "sub_31A720(self, -1, -1, -1, -1);", "sub_31A720(self, 0, -1, -1, -1);", "clear_contracts", "sub_31A720 a1 must be -1"),
    ("corrupt_31a720_a2", "sub_31A720(self, -1, -1, -1, -1);", "sub_31A720(self, -1, 0, -1, -1);", "clear_contracts", "sub_31A720 a2 must be -1"),
    ("corrupt_31a720_a3", "sub_31A720(self, -1, -1, -1, -1);", "sub_31A720(self, -1, -1, 0, -1);", "clear_contracts", "sub_31A720 a3 must be -1"),
    ("corrupt_31a720_t0", "sub_31A720(self, -1, -1, -1, -1);", "sub_31A720(self, -1, -1, -1, 0);", "clear_contracts", "sub_31A720 t0 must be -1"),
    ("corrupt_func28_call", "self->func_28(1);", "/* omitted */", "clear_contracts", "must call func_28 once"),
    ("corrupt_func28_a1", "self->func_28(1);", "self->func_28(0);", "clear_contracts", "func_28 a1 must be 1"),
    ("corrupt_call_order", "sub_31A720(self, -1, -1, -1, -1);\n    self->func_28(1);", "self->func_28(1);\n    sub_31A720(self, -1, -1, -1, -1);", "clear_contracts", "sub_31A720 must be called before func_28"),
    ("corrupt_return_val", "return 0;\n}", "return 1;\n}", "clear_contracts", "func_0032E460 must return 0"),
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


def test_controller_selection_box_clear_reference_contract(tmp_path):
    """Check exact sub_31A720 args, func_28 call order, and return 0."""
    binary = tmp_path / "ctrl_box_clear_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_selection_box_clear_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
