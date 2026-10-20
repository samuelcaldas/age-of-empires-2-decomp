"""Exercise reference contracts and kill mutations for func_003283C0."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_elevation_mesh_nearest.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_elevation_mesh_nearest_test.cpp"
)
MUTATIONS = [
    ("guard_tag", "tag < 0", "tag <= 0"),
    ("guard_upper", "tag >= self->m_count", "tag > self->m_count"),
    ("init_best_dist", "best_dist = 9999;", "best_dist = 0;"),
    ("omit_exclude", "vertices->m_id == exclude_list[k]", "false"),
    ("omit_clamp", "best_dist >= 256", "false"),
    ("wrong_clamp_val", "best_dist = 255;", "best_dist = 254;"),
    ("wrong_bias", "0.61f", "0.0f"),
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


def test_mesh_nearest_reference_contract(tmp_path):
    """Check guard clauses, distance search, exclusion, and clamping."""
    binary = tmp_path / "nearest_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement", MUTATIONS)
def test_mesh_nearest_rejects_mutation(tmp_path, name, original, replacement):
    """Verify that every production source mutation fails the native contract."""
    source = SOURCE.read_text()
    assert original in source, f"Missing mutation anchor: {name}"
    mutated = tmp_path / f"{name}.cpp"
    mutated.write_text(source.replace(original, replacement))
    binary = tmp_path / name
    compile_native(mutated, binary)
    result = run_native(binary)
    assert result.returncode != 0, f"Undetected mutation: {name}"
