"""Exercise original destructor table, flag, call-order, and byte contracts."""

from pathlib import Path
import subprocess

import pytest


ROOT = Path(__file__).resolve().parents[1]


@pytest.fixture(scope="module")
def state_executable(tmp_path_factory):
    """Compile the real C++ destructor with observable helper boundaries."""
    executable = tmp_path_factory.mktemp("block63-state") / "state-test"
    completed = subprocess.run(
        ["g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
         "tests/native/zone_spatial_grid_block63_state_test.cpp",
         "src/zone/zone_spatial_grid_destructor.cpp", "-o", str(executable)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert completed.returncode == 0, completed.stderr
    return executable


def _run(executable, case, value):
    completed = subprocess.run(
        [str(executable), case, str(value)], capture_output=True, text=True,
    )
    assert completed.returncode == 0, completed.stderr


@pytest.mark.parametrize("mask", [0, 1, 0x200, 0x155, 0x3FF])
def test_tables_preserve_all_unwritten_bytes(state_executable, mask):
    """Check zero, one, and many allocations, callback order, and guards."""
    _run(state_executable, "tables", mask)


@pytest.mark.parametrize("flag", [-32768, -1, 0, 1, 2, 32767])
def test_delete_requires_signed_positive_short(state_executable, flag):
    """Reject bit tests and unsigned comparisons for deleting flags."""
    _run(state_executable, "flag", flag)


def test_null_object_has_no_side_effects(state_executable):
    """A null object must invoke none of the cleanup helpers."""
    _run(state_executable, "null", 0)
