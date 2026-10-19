"""Behavioral regression and mutation test suite for func_001F2E00 lookup node routine."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
HARNESS_SRC = ROOT / "tests/native/zone_spatial_grid_lookup_node_test.cpp"
IMPL_SRC = ROOT / "src/zone_spatial_grid_lookup_node.cpp"


@pytest.fixture(scope="module")
def native_binary(tmp_path_factory):
    """Compile native behavioral test harness."""
    bin_path = tmp_path_factory.mktemp("bin") / "lookup_node_test"
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


def test_native_lookup_node_behavior(native_binary):
    """Run native binary and assert zero exit status."""
    res = subprocess.run([str(native_binary)], cwd=ROOT, capture_output=True, text=True)
    assert res.returncode == 0, f"Native test failed with code {res.returncode}:\n{res.stderr}"


MUTATIONS = {
    "invert_null_handle_check": (
        "if (handle == 0)",
        "if (handle != 0)"
    ),
    "forward_traversal_instead_of_backward": (
        "curr = self->field_14->prev;",
        "curr = self->field_14->next;"
    ),
    "forward_advance_instead_of_backward": (
        "curr = curr->prev;",
        "curr = curr->next;"
    ),
    "invert_strcmp_condition": (
        ") != 0) {",
        ") == 0) {"
    ),
    "omit_found_node_return": (
        "return curr;",
        "return 0;"
    ),
}


@pytest.mark.parametrize("mutation_key", sorted(MUTATIONS.keys()))
def test_mutations_trigger_assertion_failures(tmp_path, mutation_key):
    """Verify that any defect in lookup node logic triggers an assertion failure in the harness."""
    orig_text = IMPL_SRC.read_text()
    target_pattern, replacement = MUTATIONS[mutation_key]
    assert target_pattern in orig_text, f"Pattern {target_pattern} not found in source"
    mutated_text = orig_text.replace(target_pattern, replacement, 1)

    mutated_src = tmp_path / "mutated_lookup_node.cpp"
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
