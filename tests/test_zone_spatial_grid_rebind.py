"""Behavioral regression and mutation test suite for func_001F2EB0 rebind routine."""

from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]
HARNESS_SRC = ROOT / "tests/native/zone_spatial_grid_rebind_test.cpp"
IMPL_SRC = ROOT / "src/zone/zone_spatial_grid_rebind.cpp"


@pytest.fixture(scope="module")
def native_binary(tmp_path_factory):
    """Compile native behavioral test harness."""
    bin_path = tmp_path_factory.mktemp("bin") / "rebind_test"
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


def test_native_rebind_behavior(native_binary):
    """Run native binary and assert zero exit status."""
    res = subprocess.run([str(native_binary)], cwd=ROOT, capture_output=True, text=True)
    assert res.returncode == 0, f"Native test failed with code {res.returncode}:\n{res.stderr}"


MUTATIONS = {
    "invert_old_occupant_guard": (
        "if (self->field_10 != 0)",
        "if (self->field_10 == 0)"
    ),
    "omit_old_method_dc": (
        "self->field_10->method_DC(0);",
        "/* omitted */"
    ),
    "omit_field_10_assignment": (
        "self->field_10 = item1;",
        "/* omitted */"
    ),
    "omit_new_method_dc": (
        "self->field_10->method_DC(1);",
        "/* omitted */"
    ),
    "omit_new_method_28": (
        "self->field_10->method_28(2);",
        "/* omitted */"
    ),
    "corrupt_new_method_dc_arg": (
        "self->field_10->method_DC(1);",
        "self->field_10->method_DC(0);"
    ),
    "corrupt_new_method_28_arg": (
        "self->field_10->method_28(2);",
        "self->field_10->method_28(1);"
    ),
    "omit_flag_write": (
        "D_004D8E18 = 1;",
        "/* omitted */"
    ),
    "omit_mgr_call": (
        "D_004D89C0->method_C8(D_004D8940, 0, 0, 0);",
        "/* omitted */"
    ),
    "invert_item2_guard": (
        "if (item2 != 0)",
        "if (item2 == 0)"
    ),
    "omit_reset_call": (
        "func_001F2BD0(self);",
        "/* omitted */"
    ),
}


@pytest.mark.parametrize("mutation_key", sorted(MUTATIONS.keys()))
def test_mutations_trigger_assertion_failures(tmp_path, mutation_key):
    """Verify that any defect in rebind logic triggers an assertion failure in the harness."""
    orig_text = IMPL_SRC.read_text()
    target_pattern, replacement = MUTATIONS[mutation_key]
    assert target_pattern in orig_text, f"Pattern {target_pattern} not found in source"
    mutated_text = orig_text.replace(target_pattern, replacement, 1)

    mutated_src = tmp_path / "mutated_rebind.cpp"
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
