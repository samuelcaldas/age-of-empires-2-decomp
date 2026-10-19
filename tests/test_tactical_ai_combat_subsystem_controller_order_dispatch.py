"""Exercise reference contracts and kill mutations for func_0032E6B0."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_controller_order_dispatch.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_order_dispatch_test.cpp"
)
MUTATIONS = [
    ("corrupt_cleanup_check", "if (t0 != 0)", "if (t0 == 0)", "cleanup_t0", "t0!=0 must dispatch cleanup func_0032E820"),
    ("corrupt_t0_zero_check", "if (t0 == 0)", "if (t0 != 0)", "valid_slot", "valid slot on t0==0 must call sub_260ED0"),
    ("corrupt_sub260ed0_call", "sub_260ED0(self->m_sub12c->m_sub_target);", "/* omitted */", "valid_slot", "valid slot on t0==0 must call sub_260ED0"),
    ("corrupt_e640_call", "func_0032E640(self, 2);", "/* omitted */", "cleanup_t0", "must unconditionally dispatch func_0032E640"),
    ("corrupt_e640_id", "func_0032E640(self, 2);", "func_0032E640(self, 1);", "cleanup_t0", "func_0032E640 target id must be 2"),
    ("corrupt_sub260e50_action", "action_id, 0, param & 0xFF, a3);", "action_id + 1, 0, param & 0xFF, a3);", "final_dispatch", "sub_260E50 action_id must be 2961"),
    ("corrupt_action_id_record", "self->m_slot_action_ids[cur_slot] = action_id;", "self->m_slot_action_ids[cur_slot] = 0;", "final_dispatch", "dispatched action id must be recorded in table"),
    ("corrupt_slot_increment", "self->m_slot_count++;", "/* omitted */", "final_dispatch", "slot count must be incremented"),
    ("corrupt_slot_ptr_record", "self->m_slots[cur_slot] = (SlotEntry*)ret_slot;", "self->m_slots[cur_slot] = (SlotEntry*)((char*)ret_slot + 1);", "final_dispatch", "returned slot pointer must be recorded"),
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


def test_controller_order_dispatch_reference_contract(tmp_path):
    """Check cleanup dispatch, valid slot handling, func_0032E640 call, and final sub_260E50 dispatch."""
    binary = tmp_path / "ctrl_order_dispatch_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_order_dispatch_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
