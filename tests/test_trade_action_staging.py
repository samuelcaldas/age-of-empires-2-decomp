"""Native behavioral regressions for trade-action staging helpers."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
FIXTURE = r'''
#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");
static_assert(sizeof(int) == 4, "native fixture requires 32-bit integers");

extern "C" {
void func_00217730(void *, int);
void func_002177C0(void *, int *, int, int);
void *D_004E3058;
}

static unsigned char object[0x148];
static void *vtable[11];
static int lookup_index;
static int lookup_values[3];
static int expected_fields[6];
static int stage;
static int expected_lookup_index;

static int *field(int offset) {
    return reinterpret_cast<int *>(object + offset);
}

extern "C" void *func_00185E20(void *source, int index) {
    assert(source == D_004E3058);
    assert(index == expected_lookup_index);
    lookup_index = index;
    return lookup_values[0] == -999 ? 0 : lookup_values;
}

extern "C" void func_00217B50(void *self) {
    assert(self == object);
    assert(stage == 0);
    for (int index = 0; index < 6; index++) {
        assert(*field(0x12C + index * 4) == expected_fields[index]);
    }
    stage = 1;
}

static void callback(void *self, int argument) {
    assert(self == object);
    assert(argument == 1);
    assert(stage == 1);
    stage = 2;
}

static void prepare(int index, int *values, int a2, int a3) {
    std::memset(object, 0xA5, sizeof(object));
    vtable[10] = reinterpret_cast<void *>(callback);
    *reinterpret_cast<void ***>(object) = vtable;
    D_004E3058 = object + 0x100;
    expected_lookup_index = index < 0 ? 2 : index;
    lookup_values[0] = values[0];
    lookup_values[1] = values[1];
    lookup_values[2] = values[2];
    for (int slot = 0; slot < 4; slot++) {
        expected_fields[slot] = values[0];
    }
    expected_fields[4] = a2;
    expected_fields[5] = a3;
    stage = 0;
}

static void check_result() {
    assert(stage == 2);
    for (int offset = 4; offset < 0x12C; offset++) assert(object[offset] == 0xA5);
    for (int offset = 0x144; offset < static_cast<int>(sizeof(object)); offset++) {
        assert(object[offset] == 0xA5);
    }
}

int main(int argc, char **argv) {
    assert(argc == 2);
    int values[3] = {7, 8, 9};
    if (std::strcmp(argv[1], "lookup") == 0) {
        int indices[] = {-1, 0, 1, 5};
        for (int index : indices) {
            prepare(index, values, 8, 9);
            func_00217730(object, index);
            check_result();
        }
        return 0;
    }
    if (std::strcmp(argv[1], "null") == 0) {
        int empty[3] = {-999, 0, 0};
        prepare(5, empty, 0, 0);
        for (int slot = 0; slot < 6; slot++) expected_fields[slot] = 0;
        func_00217730(object, 5);
        check_result();
        return 0;
    }
    if (std::strcmp(argv[1], "copy") == 0) {
        int distinct[4] = {17, 23, 31, 47};
        prepare(0, values, 59, 61);
        for (int slot = 0; slot < 4; slot++) expected_fields[slot] = distinct[slot];
        expected_fields[4] = 59;
        expected_fields[5] = 61;
        func_002177C0(object, distinct, 59, 61);
        check_result();
        return 0;
    }
    assert(false);
}
'''


@pytest.fixture(scope="module")
def staging_test(tmp_path_factory):
    """Compile the real source with native 32-bit boundary doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade-action staging regressions require g++")
    fixture = tmp_path_factory.mktemp("trade-action-staging")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    harness = fixture / "staging_test.cpp"
    harness.write_text(FIXTURE, encoding="utf-8")
    binary = fixture / "staging-test"
    subprocess.run(
        [compiler, "-m32", "-Iinclude", "src/trade_action_helper_217730.cpp",
         str(harness), "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", ["lookup", "null", "copy"])
def test_trade_action_staging_behavior(staging_test, case):
    """Verify selected indexes, staged fields, and call ordering natively."""
    result = subprocess.run([str(staging_test), case], capture_output=True, text=True)
    assert result.returncode == 0, f"{case}: {result.stderr}"
