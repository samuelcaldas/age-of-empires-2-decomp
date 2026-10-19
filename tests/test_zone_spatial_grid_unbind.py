"""Behavioral regression and mutation test suite for func_001F2CB0 unbind routine."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
HARNESS_SRC = ROOT / "tests/native/zone_spatial_grid_unbind_test.cpp"
IMPL_SRC = ROOT / "src/zone_spatial_grid_unbind.cpp"


@pytest.fixture(scope="module")
def native_binary(tmp_path_factory):
    """Compile native behavioral test harness."""
    bin_path = tmp_path_factory.mktemp("bin") / "unbind_test"
    cmd = [
        "g++", "-m32", "-std=c++98", "-O2",
        "-Iinclude",
        str(HARNESS_SRC),
        str(IMPL_SRC),
        "-o", str(bin_path)
    ]
    res = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed:\n{res.stderr}"
    return bin_path


def test_native_unbind_behavior(native_binary):
    """Run native binary and assert zero exit status."""
    res = subprocess.run([str(native_binary)], cwd=ROOT, capture_output=True, text=True)
    assert res.returncode == 0, f"Native test failed with code {res.returncode}:\n{res.stderr}"


MUTATIONS = {
    "invert_elem_null_guard": (
        "if (elem == 0) {\n        return 0;\n    }",
        "if (elem != 0) {\n        return 0;\n    }"
    ),
    "invert_node_null_guard": (
        "if (node == 0) {\n        return 0;\n    }",
        "if (node != 0) {\n        return 0;\n    }"
    ),
    "omit_count_decrement": (
        "self->field_18--;",
        "/* omitted */"
    ),
    "double_count_decrement": (
        "self->field_18--;",
        "self->field_18 -= 2;"
    ),
    "omit_unlink_prev": (
        "node->next->prev = node->prev;",
        "/* omitted */"
    ),
    "omit_unlink_next": (
        "node->prev->next = node->next;",
        "/* omitted */"
    ),
    "corrupt_unlink_pointers": (
        "node->next->prev = node->prev;",
        "node->next->prev = node->next;"
    ),
    "omit_method_call": (
        "node->elem->method_08(1);",
        "/* omitted */"
    ),
    "corrupt_method_argument": (
        "node->elem->method_08(1);",
        "node->elem->method_08(2);"
    ),
    "omit_node_free": (
        "func_00116F68(node);",
        "/* omitted */"
    ),
    "corrupt_return_value": (
        "return 1;",
        "return 0;"
    ),
}


@pytest.mark.parametrize("mutation_key", sorted(MUTATIONS.keys()))
def test_mutations_trigger_assertion_failures(tmp_path, mutation_key):
    """Verify that any defect in unbind logic triggers an assertion failure in the harness."""
    orig_text = IMPL_SRC.read_text()
    target_pattern, replacement = MUTATIONS[mutation_key]
    assert target_pattern in orig_text, f"Pattern {target_pattern} not found in source"
    mutated_text = orig_text.replace(target_pattern, replacement, 1)

    mutated_src = tmp_path / "mutated_unbind.cpp"
    mutated_src.write_text(mutated_text)
    mutated_bin = tmp_path / "mutated_bin"

    cmd = [
        "g++", "-m32", "-std=c++98", "-O2",
        "-Iinclude",
        str(HARNESS_SRC),
        str(mutated_src),
        "-o", str(mutated_bin)
    ]
    compile_res = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    assert compile_res.returncode == 0, f"Compilation of mutation failed: {compile_res.stderr}"

    run_res = subprocess.run([str(mutated_bin)], cwd=ROOT, capture_output=True, text=True)
    assert run_res.returncode != 0, f"Mutation '{mutation_key}' passed unexpectedly without assertion failure"
