"""Exercise reference contracts and kill mutations for func_0032C420."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_controller_child_sync.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_child_sync_test.cpp"
)
MUTATIONS = [
    ("corrupt_gate_check", "if (func_00323B50(self) == 0)", "if (func_00323B50(self) != 0)", "gate_fail", "failed child gate must return 0"),
    ("corrupt_gate_return", "if (func_00323B50(self) == 0) {\n        return 0;\n    }", "if (func_00323B50(self) == 0) {\n        return 1;\n    }", "gate_fail", "failed child gate must return 0"),
    ("corrupt_self_arg", "func_00323B50(self)", "func_00323B50((CombatSubsystemControllerInstance*)((char*)self + 1))", "gate_fail", "func_00323B50 self mismatch"),
    ("corrupt_view_null_check", "if (view != 0) {", "if (view == 0) {", "with_view", "must call view func_28 once"),
    ("corrupt_view_v28_call", "view->m_vtable->func_28(view, 1);", "view->m_vtable->func_28(view, 0);", "with_view", "view func_28 a1 must be 1"),
    ("corrupt_view_arg", "view->m_vtable->func_28(view, 1);", "view->m_vtable->func_28((void*)((char*)view + 1), 1);", "with_view", "view func_28 self mismatch"),
    ("corrupt_final_return", "return 1;\n}", "return 0;\n}", "with_view", "child sync with view must return 1"),
    ("corrupt_without_view_return", "return 1;\n}", "return 0;\n}", "without_view", "child sync without view must return 1"),
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


def test_controller_child_sync_reference_contract(tmp_path):
    """Check child gate failure, sync with view, and sync without view."""
    binary = tmp_path / "ctrl_child_sync_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_child_sync_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
