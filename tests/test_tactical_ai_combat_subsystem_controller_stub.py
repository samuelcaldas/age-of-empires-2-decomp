"""Exercise reference contracts and kill mutations for func_0032C5F0."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_stub.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_stub_test.cpp"
)
MUTATIONS = [
    ("corrupt_mutate_word0", "(void)self;", "if (self) *(int*)self = 0xDEAD0001;", "noop", "func_0032C5F0 must not mutate instance memory (word 0)"),
    ("corrupt_mutate_word1", "(void)self;", "if (self) *((int*)self + 1) = 0xDEAD0002;", "noop", "func_0032C5F0 must not mutate instance memory (word 1)"),
    ("corrupt_mutate_word2", "(void)self;", "if (self) *((int*)self + 2) = 0xDEAD0003;", "noop", "func_0032C5F0 must not mutate instance memory (word 2)"),
    ("corrupt_mutate_word3", "(void)self;", "if (self) *((int*)self + 3) = 0xDEAD0004;", "noop", "func_0032C5F0 must not mutate instance memory (word 3)"),
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


def test_controller_stub_reference_contract(tmp_path):
    """Check noop memory preservation and null self handling."""
    binary = tmp_path / "ctrl_stub_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_stub_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
