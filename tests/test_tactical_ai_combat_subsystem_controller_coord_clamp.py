"""Exercise reference contracts and kill mutations for func_0032E580."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_coord_clamp.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_coord_clamp_test.cpp"
)
MUTATIONS = [
    ("corrupt_x_neg_check", "if (coords[0] < 0.0f)", "if (coords[0] > 0.0f)", "clamp_neg", "negative x must clamp to zero"),
    ("corrupt_x_neg_val", "coords[0] = 0.0f;", "coords[0] = 1.0f;", "clamp_neg", "negative x must clamp to zero"),
    ("corrupt_y_neg_check", "if (coords[1] < 0.0f)", "if (coords[1] > 0.0f)", "clamp_neg", "negative y must clamp to zero"),
    ("corrupt_y_neg_val", "coords[1] = 0.0f;", "coords[1] = 1.0f;", "clamp_neg", "negative y must clamp to zero"),
    ("corrupt_x_upper_val", "(float)self->m_bounds->max_x - 1.0f;", "(float)self->m_bounds->max_x;", "clamp_upper", "upper x must clamp to max_x - 1.0f"),
    ("corrupt_y_upper_val", "(float)self->m_bounds->max_y - 1.0f;", "(float)self->m_bounds->max_y;", "clamp_upper", "upper y must clamp to max_y - 1.0f"),
    ("corrupt_x_upper_check", "coords[0] > (float)self->m_bounds->max_x - 1.0f", "coords[0] < (float)self->m_bounds->max_x - 1.0f", "in_range", "in-range x must be preserved"),
    ("corrupt_y_upper_check", "coords[1] > (float)self->m_bounds->max_y - 1.0f", "coords[1] < (float)self->m_bounds->max_y - 1.0f", "in_range", "in-range y must be preserved"),
    ("corrupt_zero_x_boundary", "if (coords[0] < 0.0f) {\n        coords[0] = 0.0f;\n    }", "if (coords[0] <= 0.0f) {\n        coords[0] = -1.0f;\n    }", "boundary", "zero x boundary must be preserved"),
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


def test_controller_coord_clamp_reference_contract(tmp_path):
    """Check negative clamping, upper bound clamping, in-range preservation, and boundary edges."""
    binary = tmp_path / "ctrl_coord_clamp_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_coord_clamp_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
