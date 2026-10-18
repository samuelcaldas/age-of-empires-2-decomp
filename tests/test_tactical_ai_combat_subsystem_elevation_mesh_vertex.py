"""Exercise reference contracts and kill mutations for func_00328230."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_elevation_mesh_vertex.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_elevation_mesh_vertex_test.cpp"
)
MUTATIONS = [
    ("guard_count", "if (self->m_count == 0) return;", "if (self->m_count < 0) return;"),
    ("guard_entity", "if (!entity) return;", "if (false) return;"),
    ("corrupt_id", "*(int *)(buf + 0) = id;", "*(int *)(buf + 0) = id + 1;"),
    ("corrupt_x", "buf[6] = (char)x;", "buf[6] = (char)(x + 1);"),
    ("corrupt_y", "buf[7] = (char)y;", "buf[7] = (char)(y + 1);"),
    ("omit_inc", "self->m_table_8[tag]++;", "/* omitted */"),
    ("wrong_stride", "self->m_table_8[tag] * 8", "self->m_table_8[tag] * 4"),
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


def test_mesh_vertex_reference_contract(tmp_path):
    """Check guard clauses, vertex serialization, layout, and table count."""
    binary = tmp_path / "vertex_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement", MUTATIONS)
def test_mesh_vertex_rejects_mutation(tmp_path, name, original, replacement):
    """Verify that every production source mutation fails the native contract."""
    source = SOURCE.read_text()
    assert original in source, f"Missing mutation anchor: {name}"
    mutated = tmp_path / f"{name}.cpp"
    mutated.write_text(source.replace(original, replacement))
    binary = tmp_path / name
    compile_native(mutated, binary)
    result = run_native(binary)
    assert result.returncode != 0, f"Undetected mutation: {name}"
