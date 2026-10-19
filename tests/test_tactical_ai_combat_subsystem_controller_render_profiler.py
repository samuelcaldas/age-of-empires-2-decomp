"""Exercise reference contracts and kill mutations for func_0032C500."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_controller_render_profiler.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_render_profiler_test.cpp"
)
MUTATIONS = [
    ("corrupt_channel_6_val", "func_184B60(D_004E3180, 6, elapsed_time - metric_delta);", "func_184B60(D_004E3180, 6, elapsed_time - metric_delta + 1);", "null_target", "channel 6 delta mismatch"),
    ("corrupt_channel_12_val", "func_184B60(D_004E3180, 12, metric_delta);", "func_184B60(D_004E3180, 12, metric_delta + 1);", "null_target", "channel 12 delta mismatch"),
    ("corrupt_func_30_call", "self->m_vtable->func_30(self, 0);", "self->m_vtable->func_30(self, 1);", "null_target", "func_30 a1 must be 0"),
    ("corrupt_1abd90_a0", "func_1ABD90(self->m_field_20, &self->m_field_24, self->m_field_10B);", "func_1ABD90((void*)0, &self->m_field_24, self->m_field_10B);", "null_target", "func_1ABD90 a0 mismatch"),
    ("corrupt_1abd90_a2", "func_1ABD90(self->m_field_20, &self->m_field_24, self->m_field_10B);", "func_1ABD90(self->m_field_20, &self->m_field_24, (unsigned char)(self->m_field_10B + 1));", "null_target", "func_1ABD90 a2 mismatch"),
    ("corrupt_func_34_call", "self->m_vtable->func_34(self);", "/* omitted */", "null_target", "must call func_34 once"),
    ("corrupt_31aab0_call", "func_31AAB0(self);", "/* omitted */", "active_target", "must call func_31AAB0 once"),
    ("corrupt_184bb0_call", "func_184BB0(D_004E3180);", "/* omitted */", "null_target", "must call func_184BB0 once"),
    ("corrupt_branch_condition", "if (self->m_field_12C == 0 || self->m_target == 0)", "if (self->m_field_12C == 0 && self->m_target == 0)", "null_target", "must call func_30 once"),
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


def test_controller_render_profiler_reference_contract(tmp_path):
    """Check null target branch, active target branch, metric channels, and callback order."""
    binary = tmp_path / "ctrl_render_profiler_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_render_profiler_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
