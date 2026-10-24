"""Exercise reference contracts and kill mutations for func_003286C0."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_mode_filter.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_mode_filter_test.cpp"
)
MUTATIONS = [
    ("omit_status", "if (func_185DC0(D_004E3180, 0) != 0) return 0;", "/* omitted */"),
    ("omit_mode", "if (!is_valid_mode(mode, mgr)) return 0;", "/* omitted */"),
    ("wrong_subtype", "subtype == 0x6F", "subtype == 0x6E"),
    ("wrong_state", "m_state == 2", "m_state == 3"),
    ("omit_fallback", "mode == 4 || mode == 6 || mode == 7", "false"),
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


def test_mode_filter_reference_contract(tmp_path):
    """Check status check, mode validation, action dispatch, and fallback."""
    binary = tmp_path / "filter_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement", MUTATIONS)
def test_mode_filter_rejects_mutation(tmp_path, name, original, replacement):
    """Verify that every production source mutation fails the native contract."""
    source = SOURCE.read_text()
    assert original in source, f"Missing mutation anchor: {name}"
    mutated = tmp_path / f"{name}.cpp"
    mutated.write_text(source.replace(original, replacement))
    binary = tmp_path / name
    compile_native(mutated, binary)
    result = run_native(binary)
    assert result.returncode != 0, f"Undetected mutation: {name}"
