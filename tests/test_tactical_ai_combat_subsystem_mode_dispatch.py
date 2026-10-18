"""Exercise reference contracts and kill mutations for func_00328820."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_mode_dispatch.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_mode_dispatch_test.cpp"
)
MUTATIONS = [
    ("lax_mode", "!is_mode_supported(mode, mgr)", "mode < 0"),
    ("invert_status", "func_185DC0(mgr, 0) != 0", "func_185DC0(mgr, 0) == 0"),
    ("invert_active_nonzero", "self->m_active != 0", "self->m_active == 0"),
    ("corrupt_action_args", "func_1A52D0(self, a1, a2);", "func_1A52D0(self, a1 + 1, a2 + 1);"),
    ("wrong_ret_one", "return 1;", "return 0;"),
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


def test_mode_dispatch_reference_contract(tmp_path):
    """Check mode validation, status branches, and action dispatch."""
    binary = tmp_path / "dispatch_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement", MUTATIONS)
def test_mode_dispatch_rejects_mutation(tmp_path, name, original, replacement):
    """Verify that every production source mutation fails the native contract."""
    source = SOURCE.read_text()
    assert original in source, f"Missing mutation anchor: {name}"
    mutated = tmp_path / f"{name}.cpp"
    mutated.write_text(source.replace(original, replacement, 1))
    binary = tmp_path / name
    compile_native(mutated, binary)
    result = run_native(binary)
    assert result.returncode != 0, f"Undetected mutation: {name}"
