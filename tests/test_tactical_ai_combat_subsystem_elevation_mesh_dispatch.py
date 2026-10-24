"""Exercise reference contracts and kill mutations for func_00328610."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_elevation_mesh_dispatch.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_elevation_mesh_dispatch_test.cpp"
)
MUTATIONS = [
    ("invert_gate", "!func_1A5010(self, a2, a3, &s_7C, &s_7E, &s_78)",
     "func_1A5010(self, a2, a3, &s_7C, &s_7E, &s_78)"),
    ("wrong_rejection_ret", "return 0;", "return 1;"),
    ("wrong_arg1_forward", "a1, a2, a3, a4, a5", "a1 + 1, a2, a3, a4, a5"),
    ("wrong_arg2_forward", "a1, a2, a3, a4, a5", "a1, a2 + 1, a3, a4, a5"),
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


def run_native(binary):
    """Run one fixture process, returning diagnostics and exit status."""
    return subprocess.run(
        [str(binary)], capture_output=True, text=True, timeout=10,
    )


def test_mesh_dispatch_reference_contract(tmp_path):
    """Check gate validation, argument forwarding, and return values."""
    binary = tmp_path / "dispatch_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement", MUTATIONS)
def test_mesh_dispatch_rejects_mutation(tmp_path, name, original, replacement):
    """Verify that every production source mutation fails the native contract."""
    source = SOURCE.read_text()
    assert original in source, f"Missing mutation anchor: {name}"
    mutated = tmp_path / f"{name}.cpp"
    mutated.write_text(source.replace(original, replacement))
    binary = tmp_path / name
    compile_native(mutated, binary)
    result = run_native(binary)
    assert result.returncode != 0, f"Undetected mutation: {name}"
