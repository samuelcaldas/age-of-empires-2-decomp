"""Exercise original linked-list traversal, callbacks, and reload semantics."""

from pathlib import Path
import subprocess

import pytest


ROOT = Path(__file__).resolve().parents[1]


@pytest.fixture(scope="module")
def list_executable(tmp_path_factory):
    """Compile the destructor against dynamic list fixtures."""
    executable = tmp_path_factory.mktemp("block63-list") / "list-test"
    completed = subprocess.run(
        ["g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
         "tests/native/zone_spatial_grid_block63_list_test.cpp",
         "src/zone_spatial_grid_destructor.cpp", "-o", str(executable)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert completed.returncode == 0, completed.stderr
    return executable


def _run(executable, argument):
    completed = subprocess.run(
        [str(executable), str(argument)], capture_output=True, text=True,
    )
    assert completed.returncode == 0, completed.stderr


@pytest.mark.parametrize("count", [0, 1, 2])
def test_list_traversal_counts(list_executable, count):
    """Process empty, single-element, and multi-element sentinel lists."""
    _run(list_executable, count)


def test_list_reloads_head_pointer_from_object(list_executable):
    """Do not cache self->field_14 across wrapper-release calls."""
    _run(list_executable, "head-reload")


def test_list_reloads_element_pointer_after_item_destructor(list_executable):
    """A virtual destructor may modify the node wrapper before free."""
    _run(list_executable, "element-reload")
