"""Exercise reference contracts and kill mutations for func_0032E0E0."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_terrain_action.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_terrain_action_test.cpp"
)
MUTATIONS = [
    ("corrupt_e820_call", "func_0032E820(self);", "/* omitted */", "gate_zero", "must call func_0032E820 first"),
    ("corrupt_d4e2ea0_gate", "if (D_004E2EA0 == 0)", "if (D_004E2EA0 != 0)", "gate_zero", "D_004E2EA0==0 must return 0"),
    ("corrupt_target_func168_check", "func_168(target, sp104, sp110, -1, -1, -1, -1, 0) == 0", "func_168(target, sp104, sp110, -1, -1, -1, -1, 0) != 0", "target_zero", "target query zero must return 0"),
    ("corrupt_pick_d400_mode", "func_0032D400(self, 42, 1,", "func_0032D400(self, 41, 1,", "pick_50", "func_0032D400 mode must be 42"),
    ("corrupt_pick_d400_flag", "func_0032D400(self, 42, 1,", "func_0032D400(self, 42, 0,", "pick_50", "func_0032D400 flag must be 1"),
    ("corrupt_pick_50_check", "!= 50", "== 50", "pick_50", "pick query 50 must return 0"),
    ("corrupt_e580_call", "func_0032E580(self, buf);", "/* omitted */", "success", "must call func_0032E580 once"),
    ("corrupt_order_2961_action", "func_0032E6B0(self, 2961,", "func_0032E6B0(self, 2962,", "success", "func_0032E6B0 a1 must be 2961"),
    ("corrupt_mgr_call", "D_004E3180->m_vtable->func_18(D_004E3180, 0, 0);", "/* omitted */", "success", "must call manager func_18 once"),
    ("corrupt_mgr_slot", "D_004E3180->m_vtable->func_18(", "D_004E3180->m_vtable->func_14(", "success", "must not call adjacent manager vtable slots"),
    ("corrupt_mgr_a1", "D_004E3180->m_vtable->func_18(D_004E3180, 0, 0);", "D_004E3180->m_vtable->func_18(D_004E3180, 1, 0);", "success", "manager a1 must be 0"),
    ("corrupt_mgr_a2", "D_004E3180->m_vtable->func_18(D_004E3180, 0, 0);", "D_004E3180->m_vtable->func_18(D_004E3180, 0, 1);", "success", "manager a2 must be 0"),
    ("corrupt_mgr_receiver", "D_004E3180->m_vtable->func_18(D_004E3180, 0, 0);", "D_004E3180->m_vtable->func_18(nullptr, 0, 0);", "success", "manager receiver mismatch"),
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


def test_controller_terrain_action_reference_contract(tmp_path):
    """Check cleanup dispatch, D_004E2EA0 gate, target query, pick query 50, and success path."""
    binary = tmp_path / "ctrl_terrain_action_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_terrain_action_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
