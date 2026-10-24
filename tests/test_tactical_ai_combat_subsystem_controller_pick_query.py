"""Exercise reference contracts and kill mutations for func_0032D400."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_pick_query.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_pick_query_test.cpp"
)
MUTATIONS = [
    ("corrupt_mode41_gate", "if (m == 41)", "if (m != 41)", "mode41_flag0", "mode 41 flag 0 zero return must return 50"),
    ("corrupt_mode41_zero_return", "return 50;\n        }", "return 51;\n        }", "mode41_flag0", "mode 41 flag 0 zero return must return 50"),
    ("corrupt_mode41_flag0_args", "0, 40, 15, 4, 1", "1, 40, 15, 4, 1", "mode41_flag0", "func_120 a3 mismatch (flag 0)"),
    ("corrupt_mode41_flag1_args", "10, 30, 15, 4, 1", "11, 30, 15, 4, 1", "mode41_flag1", "func_120 a3 mismatch (10)"),
    ("corrupt_mode41_buf_zero", "for (int i = 0; i < 20; ++i) {", "for (int i = 0; i < 10; ++i) {", "mode41_flag0", "mode 41 must zero first 20 bytes of buf"),
    ("corrupt_mode42_gate", "if (m == 42)", "if (m != 42)", "fallback", "fallback mode must not invoke func_120"),
    ("corrupt_mode42_recurse_mode", "func_0032D400(self, 41,", "func_0032D400(self, 40,", "mode42_recurse", "mode 42 recursion hit must return 52"),
    ("corrupt_fallback_mode", "sub_31C7F0(self, 40,", "sub_31C7F0(self, 41,", "fallback", "fallback mode mismatch"),
    ("corrupt_fallback_mask", "return ret & 0xFF;", "return ret & 0x0F;", "fallback", "fallback mode must return masked 8-bit result of sub_31C7F0"),
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


def test_controller_pick_query_reference_contract(tmp_path):
    """Check ABI arguments, mode 41 virtual dispatch, mode 42 recursion, and fallback return."""
    binary = tmp_path / "ctrl_pick_query_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_pick_query_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
