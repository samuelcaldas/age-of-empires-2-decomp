"""Exercise reference contracts and kill mutations for func_0032E4B0."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_controller_entity_bind.cpp"
NATIVE_TEST = (
    ROOT / "tests/native/tactical_ai_combat_subsystem_controller_entity_bind_test.cpp"
)
MUTATIONS = [
    ("corrupt_d400_mode", "func_0032D400(self, 41, 2,", "func_0032D400(self, 40, 2,", "pick_52", "func_0032D400 mode must be 41"),
    ("corrupt_d400_flag", "func_0032D400(self, 41, 2,", "func_0032D400(self, 41, 1,", "pick_52", "func_0032D400 flag must be 2"),
    ("corrupt_pick_52_gate", "== 52", "!= 52", "pick_52", "pick 52 hit must return 1"),
    ("corrupt_sub1c8c00_call", "sub_1C8C00(entity);", "sub_1C8C00(nullptr);", "pick_52", "sub_1C8C00 handle mismatch"),
    ("corrupt_sub1f6ea0_res", "void *handle = sub_1C8C00(entity);", "void *handle = (sub_1C8C00(entity), (void*)0x9999);", "pick_52", "sub_1F6EA0 res mismatch"),
    ("corrupt_sub1c8c10_call", "sub_1C8C10(entity);", "sub_1C8C10(nullptr);", "pick_52", "sub_1C8C10 handle mismatch"),
    ("corrupt_strcpy_call", "strcpy(out_name, str);", "/* omitted */", "pick_52", "out_name must receive bound name"),
    ("corrupt_return_hit", "return 1;\n    }", "return 0;\n    }", "pick_52", "pick 52 hit must return 1"),
    ("corrupt_fallback_return", "return sub_1F6EF0(self, x, y, out_name, a4);", "return sub_1F6EF0(self, x, y, out_name, a4) + 1;", "fallback", "non-52 return must propagate sub_1F6EF0 return value"),
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


def test_controller_entity_bind_reference_contract(tmp_path):
    """Check D400 mode 41 call, entity binding sequence, and fallback delegation."""
    binary = tmp_path / "ctrl_entity_bind_test"
    compile_native(SOURCE, binary)
    result = run_native(binary)
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("name,original,replacement,test_arg,expected_msg", MUTATIONS)
def test_controller_entity_bind_rejects_mutation(tmp_path, name, original, replacement, test_arg, expected_msg):
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
