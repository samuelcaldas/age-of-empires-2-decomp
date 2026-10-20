"""Exercise reference contracts and kill mutations for func_00328300."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_elevation_mesh_remove.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_elevation_mesh_remove_test.cpp"
)
MUTATIONS = [
    ("guard_count", "if (self->m_count == 0) return -1;", "if (self->m_count < 0) return -1;"),
    ("guard_tag", "if (count == 0) return 0;", "if (count < 0) return 0;"),
    ("omit_swap", "vertices[i] = vertices[last];", "/* omitted */"),
    ("omit_dec", "self->m_table_8[tag]--;", "/* omitted */"),
    ("invert_id", "vertices[i].m_id == id", "vertices[i].m_id != id"),
    ("wrong_ret", "return i;", "return 0;"),
    ("wrong_not_found", "return -1;", "return 0;"),
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


def test_mesh_remove_reference_contract(tmp_path):
    """Check guard clauses, removal swap, counter update, and return values."""
    binary = tmp_path / "remove_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement", MUTATIONS)
def test_mesh_remove_rejects_mutation(tmp_path, name, original, replacement):
    """Verify that every production source mutation fails the native contract."""
    source = SOURCE.read_text()
    assert original in source, f"Missing mutation anchor: {name}"
    mutated = tmp_path / f"{name}.cpp"
    mutated.write_text(source.replace(original, replacement))
    binary = tmp_path / name
    compile_native(mutated, binary)
    result = run_native(binary)
    assert result.returncode != 0, f"Undetected mutation: {name}"
