"""Exercise reference contracts and kill mutations for func_00329F00."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_profiler.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_profiler_test.cpp"
)
MUTATIONS = [
    ("corrupt_return", "return ret;", "return ret + 1;", "passthrough", "profiler return value mismatch"),
    ("corrupt_channel", "func_184B60(D_004E3180, 13, end - start);", "func_184B60(D_004E3180, 14, end - start);", "passthrough", "telemetry channel must be 13"),
    ("corrupt_delta", "func_184B60(D_004E3180, 13, end - start);", "func_184B60(D_004E3180, 13, end - start + 1);", "passthrough", "telemetry delta calculation failed"),
    ("corrupt_first_arg", "func_1F60F0(a0, a1, a2, a3, t0, t1);", "func_1F60F0((void*)((char*)a0 + 1), a1, a2, a3, t0, t1);", "passthrough", "arg0 mismatch"),
    ("corrupt_last_arg", "func_1F60F0(a0, a1, a2, a3, t0, t1);", "func_1F60F0(a0, a1, a2, a3, t0, (void*)((char*)t1 + 1));", "passthrough", "arg5 mismatch"),
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


def test_controller_profiler_reference_contract(tmp_path):
    """Check argument forwarding, timer sampling, delta reporting, and return passthrough."""
    binary = tmp_path / "ctrl_profiler_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_profiler_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
