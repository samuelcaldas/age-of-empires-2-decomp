"""Native regression tests for func_001F2C20 spatial grid occupant advance."""

from pathlib import Path
import subprocess

import pytest


ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/zone_spatial_grid_advance.cpp"
MUTATIONS = (
    (
        "wrong_lookup_item",
        "func_001F6CB0(self->field_0C)",
        "func_001F6CB0(self->field_10)",
        "item == reinterpret_cast<SpatialItem *>(expected_current_item)",
    ),
    (
        "wrong_virtual_argument",
        "item->method_DC(1)",
        "item->method_DC(0)",
        "method_55_arg == 1",
    ),
    (
        "wrong_first_setter_self",
        "func_001F2AB0(self, item)",
        "func_001F2AB0(0, item)",
        "self == reinterpret_cast<ZoneSpatialGrid *>(observed_grid)",
    ),
    (
        "wrong_second_setter_self",
        "func_001F2AC0(self, item)",
        "func_001F2AC0(0, item)",
        "self == reinterpret_cast<ZoneSpatialGrid *>(observed_grid)",
    ),
    (
        "wrong_first_setter_item",
        "func_001F2AB0(self, item)",
        "func_001F2AB0(self, self->field_0C)",
        "item == reinterpret_cast<SpatialItem *>(expected_next_item)",
    ),
    (
        "wrong_second_setter_item",
        "func_001F2AC0(self, item)",
        "func_001F2AC0(self, self->field_0C)",
        "item == reinterpret_cast<SpatialItem *>(expected_next_item)",
    ),
    (
        "store_before_virtual",
        "    item->method_DC(1);",
        "    self->field_0C = item;\n    item->method_DC(1);",
        "observed_grid->field_0C == expected_current_item",
    ),
    (
        "store_before_first_setter",
        "    func_001F2AB0(self, item);",
        "    self->field_0C = item;\n    func_001F2AB0(self, item);",
        "observed_grid->field_0C == expected_current_item",
    ),
    (
        "store_before_second_setter",
        "    func_001F2AC0(self, item);",
        "    self->field_0C = item;\n    func_001F2AC0(self, item);",
        "observed_grid->field_0C == expected_current_item",
    ),
    (
        "swapped_setters",
        "    func_001F2AB0(self, item);\n    func_001F2AC0(self, item);",
        "    func_001F2AC0(self, item);\n    func_001F2AB0(self, item);",
        "call_log[2] == 201",
    ),
)


def _compile_and_run(source, executable):
    command = [
        "g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
        "tests/native/zone_spatial_grid_advance_test.cpp",
        str(source), "-o", str(executable),
    ]
    compiled = subprocess.run(command, capture_output=True, text=True, cwd=ROOT)
    assert compiled.returncode == 0, compiled.stdout + compiled.stderr
    return subprocess.run([str(executable)], capture_output=True, text=True)


@pytest.fixture(scope="module")
def native_baseline(tmp_path_factory):
    """Require the real implementation to pass before testing its mutants."""
    directory = tmp_path_factory.mktemp("advance-native")
    completed = _compile_and_run(SOURCE, directory / "baseline")
    assert completed.returncode == 0, completed.stderr
    return SOURCE.read_text()


def test_zone_spatial_grid_advance_no_asm():
    """Verify that zone_spatial_grid_advance.cpp contains zero assembly code."""
    assert SOURCE.is_file(), "Source file does not exist"
    content = SOURCE.read_text()
    assert "__asm__" not in content, "Inline assembly detected in source"
    assert "asm(" not in content, "Inline assembly detected in source"
    assert ".word" not in content, "Raw opcode word detected in source"


def test_zone_spatial_grid_advance_native(tmp_path):
    """Exercise the production implementation through the native harness."""
    completed = _compile_and_run(SOURCE, tmp_path / "advance-native")
    assert completed.returncode == 0, completed.stdout + completed.stderr


@pytest.mark.parametrize("name,before,after,assertion", MUTATIONS,
                         ids=[entry[0] for entry in MUTATIONS])
def test_native_harness_rejects_argument_and_order_mutants(
    native_baseline, tmp_path, name, before, after, assertion,
):
    """Require a specific behavioral assertion for each compiled mutation."""
    assert native_baseline.count(before) == 1
    source = tmp_path / f"{name}.cpp"
    source.write_text(native_baseline.replace(before, after))
    completed = _compile_and_run(source, tmp_path / name)
    assert completed.returncode == -6, completed.stdout + completed.stderr
    assert assertion in completed.stderr
