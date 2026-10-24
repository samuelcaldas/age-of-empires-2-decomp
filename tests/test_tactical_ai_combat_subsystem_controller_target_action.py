"""Exercise reference contracts and kill mutations for func_0032CBA0."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_target_action.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_target_action_test.cpp"
)
MUTATIONS = [
    ("corrupt_e820_call", "func_0032E820(self);", "/* omitted */", "gate_zero", "must call func_0032E820 first"),
    ("corrupt_entry_gate", "if (D_004E2EA0 == 0)", "if (D_004E2EA0 != 0)", "gate_zero", "D_004E2EA0==0 must return 0"),
    ("corrupt_gate_return", "if (D_004E2EA0 == 0) {\n        return 0;\n    }", "if (D_004E2EA0 == 0) {\n        return 1;\n    }", "gate_zero", "D_004E2EA0==0 must return 0"),
    ("corrupt_d400_check", "!= 51", "== 51", "d400_miss", "func_0032D400 miss must return 0"),
    ("corrupt_d400_a1", "func_0032D400(self, 40, 0, a1, a2, buf, 0, 1)", "func_0032D400(self, 41, 0, a1, a2, buf, 0, 1)", "d400_miss", "func_0032D400 a1 must be 40"),
    ("corrupt_d400_a2", "func_0032D400(self, 40, 0, a1, a2, buf, 0, 1)", "func_0032D400(self, 40, 1, a1, a2, buf, 0, 1)", "d400_miss", "func_0032D400 a2 must be 0"),
    ("corrupt_e580_call", "func_0032E580(self, buf);", "/* omitted */", "success", "must call func_0032E580 once"),
    ("corrupt_e6b0_call", "func_0032E6B0(self, 2962, 0, 0, 0);", "/* omitted */", "success", "must call func_0032E6B0 once"),
    ("corrupt_success_return", "return 1;\n}", "return 0;\n}", "success", "target action success must return 1"),
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


def test_controller_target_action_reference_contract(tmp_path):
    """Check cleanup dispatch, entry gate, raycast gate, buffer forwarding, and return values."""
    binary = tmp_path / "ctrl_target_action_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_target_action_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
