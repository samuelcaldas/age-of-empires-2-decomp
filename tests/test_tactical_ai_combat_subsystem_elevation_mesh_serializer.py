"""Exercise reference-derived serializer contracts and reject controlled mutations."""

from pathlib import Path
import subprocess

import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_elevation_mesh_serializer.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_elevation_mesh_serializer_test.cpp"
)
MUTATIONS = [
    ("empty_count", "    func_00226F70(stream, &self->m_count, 4);",
     "    if (self->m_count <= 0) return;\n"
     "    func_00226F70(stream, &self->m_count, 4);"),
    ("metadata_order", "&self->m_table_4[index]", "&self->m_table_8[index]"),
    ("payload_scale", "vertex_count) << 3", "vertex_count) << 2"),
    ("zero_payload", "vertex_count <= 0", "vertex_count < 0"),
    ("null_payload", "vertex_count <= 0",
     "vertex_count <= 0 || !self->m_table_0[index]"),
    ("phase_order", "    serialize_offset_tables(self, stream, index);\n"
     "    serialize_vertex_buffers(self, stream, index);",
     "    serialize_vertex_buffers(self, stream, index);\n"
     "    serialize_offset_tables(self, stream, index);"),
    ("negative_count", "index < self->m_count",
     "static_cast<unsigned int>(index) < "
     "static_cast<unsigned int>(self->m_count)"),
]


def compile_native(source, binary):
    """Compile a 32-bit candidate with the native reference-contract fixture."""
    command = [
        "g++", "-std=c++11", "-O2", "-m32", "-fno-builtin",
        "-Wall", "-Wextra", "-Werror", "-fsanitize=undefined",
        "-fno-sanitize-recover=all", "-I", str(ROOT / "include"),
        str(source), str(NATIVE_TEST), "-o", str(binary),
    ]
    result = subprocess.run(command, capture_output=True, text=True, timeout=60)
    assert result.returncode == 0, result.stderr


def run_native(binary):
    """Run one fixture process, returning diagnostics and its exit status."""
    return subprocess.run(
        [str(binary)], capture_output=True, text=True, timeout=10,
    )


def test_serializer_reference_contract(tmp_path):
    """Check ordered writes, descriptor layout, boundaries, and callback effects."""
    binary = tmp_path / "serializer_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement", MUTATIONS)
def test_serializer_rejects_mutation(tmp_path, name, original, replacement):
    """Require a real production-source mutation to fail the same native fixture."""
    source = SOURCE.read_text()
    assert original in source, f"Missing mutation anchor: {name}"
    mutated = tmp_path / f"{name}.cpp"
    mutated.write_text(source.replace(original, replacement))
    binary = tmp_path / name
    compile_native(mutated, binary)
    result = run_native(binary)
    assert result.returncode != 0, f"Undetected mutation: {name}"
