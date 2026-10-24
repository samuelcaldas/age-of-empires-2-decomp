"""Exercise reference contracts and kill mutations for func_0032E220."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_command_router.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_command_router_test.cpp"
)
MUTATIONS = [
    ("corrupt_e820_call", "func_0032E820(self);", "/* omitted */", "gate_zero", "must call func_0032E820 first"),
    ("corrupt_d4e2ea0_gate", "if (D_004E2EA0 == 0)", "if (D_004E2EA0 != 0)", "gate_zero", "D_004E2EA0==0 must return 0"),
    ("corrupt_target_func168_check", "func_168(target, sp120, sp126, -1, -1, -1, -1, 0) == 0", "func_168(target, sp120, sp126, -1, -1, -1, -1, 0) != 0", "target_zero", "target query zero must return 0"),
    ("corrupt_entity_sound_id", "sub_31A160(self, 1500, a3);", "sub_31A160(self, 1501, a3);", "entity_hit", "sub_31A160 sound_id must be 1500"),
    ("corrupt_entity_sound_param", "sub_31A160(self, 1500, a3);", "sub_31A160(self, 1500, a3 + 1);", "entity_hit", "sub_31A160 param must be a3"),
    ("corrupt_pick_d400_check", "== 51", "!= 51", "raycast_hit", "raycast hit success must return 1"),
    ("corrupt_order_2961_action", "func_0032E6B0(self, 2961,", "func_0032E6B0(self, 2962,", "raycast_hit", "func_0032E6B0 a1 must be 2961"),
    ("corrupt_func28_call", "self->m_vtable->func_28(self, 1);", "/* omitted */", "raycast_hit", "must call self func_28 once"),
    ("corrupt_mgr_slot", "D_004E3180->m_vtable->func_18(", "D_004E3180->m_vtable->func_14(", "entity_hit", "must not call adjacent manager vtable slots"),
    ("corrupt_mgr_receiver", "D_004E3180->m_vtable->func_18(D_004E3180, 0, 0);", "D_004E3180->m_vtable->func_18(nullptr, 0, 0);", "entity_hit", "manager receiver mismatch"),
    ("corrupt_mgr_a1", "D_004E3180->m_vtable->func_18(D_004E3180, 0, 0);", "D_004E3180->m_vtable->func_18(D_004E3180, 1, 0);", "entity_hit", "manager a1 must be 0"),
    ("corrupt_mgr_a2", "D_004E3180->m_vtable->func_18(D_004E3180, 0, 0);", "D_004E3180->m_vtable->func_18(D_004E3180, 0, 1);", "entity_hit", "manager a2 must be 0"),
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


def test_controller_command_router_reference_contract(tmp_path):
    """Check cleanup dispatch, D_004E2EA0 gate, target query, entity branch, raycast miss/hit, and manager dispatch."""
    binary = tmp_path / "ctrl_cmd_router_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_command_router_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
