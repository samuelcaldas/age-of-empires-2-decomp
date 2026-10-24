"""Exercise reference contracts and kill mutations for func_00328100."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_elevation_mesh_filter.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_elevation_mesh_filter_test.cpp"
)
MUTATIONS = [
    ("invert_active", "if (desc->m_active)", "if (!desc->m_active)", "inactive_rejection", "inactive entity rejection active id mismatch"),
    ("corrupt_id", "entity->m_id", "static_cast<short>(0)", "grid_filtering", "grid entity filtering entity id mismatch"),
    ("corrupt_tag", "desc->m_tag", "static_cast<unsigned char>(0)", "grid_filtering", "grid entity filtering tag mismatch"),
    ("freeze_coords", "i < count; i++, coords++", "i < count; i++", "grid_filtering", "grid entity filtering entity id mismatch"),
    ("guard_count", "if (count <= 0) return;", "if (true) return;", "grid_filtering", "grid entity filtering call count contract violated"),
    ("guard_mesh_count", "if (self->m_count == 0)", "if (self->m_count != 0)", "early_exits", "early exit zero mesh count failed"),
    ("off_by_one_loop", "i < count", "i <= count", "grid_filtering", "grid entity filtering call count contract violated"),
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


def run_native(binary, arg=Null if "Null" in globals() else None):
    """Run one fixture process with optional test argument."""
    cmd = [str(binary)]
    if arg:
        cmd.append(arg)
    return subprocess.run(
        cmd, capture_output=True, text=True, timeout=10,
    )


def test_mesh_filter_reference_contract(tmp_path):
    """Check guard clauses, entity filtering, layout, and callback arguments."""
    binary = tmp_path / "filter_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_mesh_filter_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
    """Verify that every production source mutation fails via the specific expected assertion diagnostic."""
    source = SOURCE.read_text()
    assert original in source, f"Missing mutation anchor: {name}"
    mutated = tmp_path / f"{name}.cpp"
    mutated.write_text(source.replace(original, replacement))
    binary = tmp_path / name
    compile_native(mutated, binary)
    result = run_native(binary, test_arg)
    assert result.returncode != 0, f"Mutation survived without failure: {name}"
    assert expected_msg in result.stderr, f"Mutation killed by wrong failure or crash instead of expected assertion '{expected_msg}': {name}\nStderr: {result.stderr}"
