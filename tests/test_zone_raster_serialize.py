import os
import subprocess
import pytest

PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def test_zone_raster_serialize_native(tmp_path):
    test_src = """
#include <cassert>
#include <vector>
#include "zone_raster_serialize.h"

struct CallRecord {
    void *stream;
    const void *data;
    int size;
};

static std::vector<CallRecord> g_calls;

extern "C" int func_226F70(void *stream, void *data, int size) {
    CallRecord rec;
    rec.stream = stream;
    rec.data = data;
    rec.size = size;
    g_calls.push_back(rec);
    return 0;
}

struct ZoneLayout {
    char pad_0[0x8ED0];
    int f_8ED0;
    int f_8ED4;
    int *f_8ED8;
    short **f_8EDC;
};

int main() {
    ZoneLayout zm;
    for (unsigned int i = 0; i < sizeof(zm); i++) ((char *)&zm)[i] = 0;

    int dummy_stream = 42;
    zm.f_8ED0 = 0; // count = 0
    zm.f_8ED4 = 100;

    func_001CAC90(&zm, &dummy_stream);
    assert(g_calls.size() == 2);
    assert(g_calls[0].stream == &dummy_stream);
    assert(g_calls[0].size == 4);
    assert(g_calls[1].stream == &dummy_stream);
    assert(g_calls[1].size == 4);

    g_calls.clear();

    // Now test with count = 1
    int ids[1] = { 55 };
    short buf[4] = { 1, 0, 10, 20 }; // count = 1, pad, dx, dy
    short *bufs[1] = { buf };

    zm.f_8ED0 = 1;
    zm.f_8ED8 = ids;
    zm.f_8EDC = bufs;

    func_001CAC90(&zm, &dummy_stream);
    // Expect:
    // 1. &zm.f_8ED0 (4)
    // 2. &zm.f_8ED4 (4)
    // 3. ids (1 * 4 = 4)
    // 4. &pt_count (4)
    // 5. &buf[2] (1 * 4 = 4)
    assert(g_calls.size() == 5);
    assert(g_calls[2].size == 4);
    assert(g_calls[3].size == 4);
    assert(g_calls[4].size == 4);

    return 0;
}
"""
    native_cpp = tmp_path / "test.cpp"
    native_cpp.write_text(test_src)
    bin_path = tmp_path / "test_bin"

    cmd = [
        "g++", "-m32", "-O2",
        f"-I{os.path.join(PROJECT_ROOT, 'include')}",
        str(native_cpp),
        os.path.join(PROJECT_ROOT, "src/zone/zone_raster_serialize.cpp"),
        "-o", str(bin_path)
    ]
    subprocess.run(cmd, check=True)
    subprocess.run([str(bin_path)], check=True)
