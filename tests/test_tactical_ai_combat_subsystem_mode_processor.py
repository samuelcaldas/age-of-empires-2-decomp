"""Exercise reference contracts and kill mutations for func_00328D50."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_mode_processor.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_mode_processor_test.cpp"
)
MUTATIONS = [
    ("lax_mode", "!is_mode_supported(mode)", "mode < 0"),
    ("invert_active", "self->m_active != 0", "self->m_active == 0"),
    ("invert_type", "type != 1 && type != 2", "type == 0"),
    ("wrong_bias", "0.5f", "0.0f"),
    ("omit_cleanup", "func_205EE0(self->m_obj_120);", "(void)self->m_obj_120;"),
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


def test_mode_processor_reference_contract(tmp_path):
    """Check mode validation, active branch, coordinate placement, and fallback."""
    binary = tmp_path / "processor_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement", MUTATIONS)
def test_mode_processor_rejects_mutation(tmp_path, name, original, replacement):
    """Verify that every production source mutation fails the native contract."""
    source = SOURCE.read_text()
    assert original in source, f"Missing mutation anchor: {name}"
    mutated = tmp_path / f"{name}.cpp"
    mutated.write_text(source.replace(original, replacement, 1))
    binary = tmp_path / name
    compile_native(mutated, binary)
    result = run_native(binary)
    assert result.returncode != 0, f"Undetected mutation: {name}"
