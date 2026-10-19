"""Exercise reference contracts and kill mutations for func_0032E820."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_controller_cleanup.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_cleanup_test.cpp"
)
MUTATIONS = [
    ("corrupt_null_guard",      "if (self == 0)",                    "if (self != 0)",
     None,         "matching active slot must call sub_260ED0"),
    ("corrupt_flag_bit",        "(entry->flag & 4) == 4",            "(entry->flag & 2) == 2",
     "matching_slot", "matching active slot must call sub_260ED0"),
    ("corrupt_action_id_cmp",
     "(int)sub->action_id == self->m_slot_action_ids[i]",
     "(int)sub->action_id == 0",
     "matching_slot", "matching active slot must call sub_260ED0"),
    ("omit_sub260ed0_call",     "sub_260ED0(self->m_sub12c->m_sub_target);", "/* omitted */;",
     "matching_slot", "matching active slot must call sub_260ED0"),
    ("omit_slot_clear",         "self->m_slots[i] = 0;",             "/* not cleared */;",
     "matching_slot", "slot must be cleared after return"),
    ("loop_limit_1",            "i < 10",                            "i < 1",
     "slot_9",     "slot 9 must be traversed and cleared on match"),
    ("loop_limit_9",            "i < 10",                            "i < 9",
     "slot_9",     "slot 9 must be traversed and cleared on match"),
    ("signed_compare_wrong",
     "(int)sub->action_id == self->m_slot_action_ids[i]",
     "(unsigned short)sub->action_id == (unsigned)self->m_slot_action_ids[i]",
     "signed_id",  "signed negative action_id must sign-extend and match"),
    ("clear_before_callback",
     """                if (self->m_sub12c != 0) {
                    sub_260ED0(self->m_sub12c->m_sub_target);
                }
                self->m_slots[i] = 0;""",
     """                self->m_slots[i] = 0;
                if (self->m_sub12c != 0) {
                    sub_260ED0(self->m_sub12c->m_sub_target);
                }""",
     "matching_slot", "slot must remain intact during callback"),
    ("omit_slot_count_reset",   "self->m_slot_count = 0;",          "/* omitted */;",
     "slot_count_reset", "m_slot_count must be reset to 0 after cleanup"),
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


def test_controller_cleanup_reference_contract(tmp_path):
    """Check null-self guard, 10-slot traversal, signed id, and sub_260ED0 dispatch."""
    binary = tmp_path / "ctrl_cleanup_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_cleanup_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
    """Verify that every production source mutation fails via the specific expected assertion diagnostic."""
    source = SOURCE.read_text()
    assert original in source, f"Missing mutation anchor: {name}"
    mutated = tmp_path / f"{name}.cpp"
    mutated.write_text(source.replace(original, replacement, 1))
    binary = tmp_path / name
    compile_native(mutated, binary)
    result = run_native(binary, test_arg)
    assert result.returncode != 0, f"Mutation survived without failure: {name}"
    if expected_msg:
        assert expected_msg in result.stderr, (
            f"Mutation killed by wrong failure instead of expected assertion '{expected_msg}': {name}\n"
            f"Stderr: {result.stderr}"
        )
