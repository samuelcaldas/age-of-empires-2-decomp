"""Exercise reference contracts and kill mutations for func_00329310."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_update.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_update_test.cpp"
)
MUTATIONS = [
    ("omit_pre_call", "func_329550(self);", "/* omitted */", "call_counts", "pre-hook call count mismatch"),
    ("omit_virt_call", "self->func_138();", "/* omitted */", "call_counts", "virtual method call count mismatch"),
    ("omit_post_call", "func_1F4FA0(self);", "/* omitted */", "call_counts", "post-hook call count mismatch"),
    ("swap_pre_virt", "func_329550(self);\n    self->func_138();", "self->func_138();\n    func_329550(self);", "sequence", "pre-hook func_329550 must be called first"),
    ("swap_virt_post", "self->func_138();\n    func_1F4FA0(self);", "func_1F4FA0(self);\n    self->func_138();", "sequence", "virtual method func_138 must be called second"),
    ("corrupt_pre_receiver", "func_329550(self);", "func_329550(0);", "receivers", "pre-hook receiver mismatch"),
    ("corrupt_post_receiver", "func_1F4FA0(self);", "func_1F4FA0(0);", "receivers", "post-hook receiver mismatch"),
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


def test_controller_update_reference_contract(tmp_path):
    """Check pre-hook call, virtual slot 0x140 dispatch, post-hook call, and receivers."""
    binary = tmp_path / "ctrl_update_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_update_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
