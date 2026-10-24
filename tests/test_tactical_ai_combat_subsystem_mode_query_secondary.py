"""Exercise reference contracts and kill mutations for func_00329070."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_mode_query_secondary.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_mode_query_secondary_test.cpp"
)
MUTATIONS = [
    ("omit_global", "D_004E2EA0 == 0", "false"),
    ("invert_gate", "func_1A5010(self, a1, a2, &s_3C, &s_3E, &s_38) != 0",
     "func_1A5010(self, a1, a2, &s_3C, &s_3E, &s_38) == 0"),
    ("wrong_bias", "0.5f", "0.0f"),
    ("omit_mgr_call", "D_004E3180->m_vtable->func_18(D_004E3180, 0, 0);", "/* omitted */"),
    ("omit_b4_call", "ret = (unsigned char)obj->m_vtable->func_B4(obj, 0, (float)s_3C + 0.5f, (float)s_3E + 0.5f);",
     "(void)obj;"),
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


def test_mode_query_secondary_reference_contract(tmp_path):
    """Check global flag guard, gate validation, coordinate bias, and vtable dispatch."""
    binary = tmp_path / "query_sec_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement", MUTATIONS)
def test_mode_query_secondary_rejects_mutation(tmp_path, name, original, replacement):
    """Verify that every production source mutation fails the native contract."""
    source = SOURCE.read_text()
    assert original in source, f"Missing mutation anchor: {name}"
    mutated = tmp_path / f"{name}.cpp"
    mutated.write_text(source.replace(original, replacement, 1))
    binary = tmp_path / name
    compile_native(mutated, binary)
    result = run_native(binary)
    assert result.returncode != 0, f"Undetected mutation: {name}"
