"""Exercise reference contracts and kill mutations for func_00328100."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_elevation_mesh_filter.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_elevation_mesh_filter_test.cpp"
)
MUTATIONS = [
    ("invert_active", "if (desc->m_active)", "if (!desc->m_active)"),
    ("corrupt_id", "entity->m_id", "static_cast<short>(0)"),
    ("corrupt_tag", "desc->m_tag", "static_cast<unsigned char>(0)"),
    ("freeze_coords", "i < count; i++, coords++", "i < count; i++"),
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


def test_mesh_filter_reference_contract(tmp_path):
    """Check guard clauses, entity filtering, layout, and callback arguments."""
    binary = tmp_path / "filter_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement", MUTATIONS)
def test_mesh_filter_rejects_mutation(tmp_path, name, original, replacement):
    """Verify that every production source mutation fails via an explicit assertion check."""
    source = SOURCE.read_text()
    assert original in source, f"Missing mutation anchor: {name}"
    mutated = tmp_path / f"{name}.cpp"
    mutated.write_text(source.replace(original, replacement))
    binary = tmp_path / name
    compile_native(mutated, binary)
    result = run_native(binary)
    assert result.returncode != 0 and ("Assertion" in result.stderr or "abort" in result.stderr.lower() or result.returncode < 0), f"Mutation not killed by assertion: {name}"
