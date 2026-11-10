#include <cassert>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "zone_deserialize_grid.h"

struct ZoneCell {
    char pad_0[5];
    unsigned char f_5;
    unsigned char f_6;
    char pad_7[21];
};

struct ZoneLayout {
    char pad_0[8];
    int width;
    int height;
    char pad_10[0x8E7C];
    ZoneCell **cells_ptr;
};

// Stream mock
static std::vector<unsigned char> s_stream_data;
static size_t s_stream_offset = 0;

static int s_func_1C98A0_called = 0;
static int s_func_1CF3E0_called = 0;
static int s_func_1CF9B0_called = 0;

static int s_last_w = 0;
static int s_last_h = 0;

extern "C" {
void func_00226D90(void *stream, void *data, int size) {
    (void)stream;
    assert(s_stream_offset + size <= s_stream_data.size());
    std::memcpy(data, &s_stream_data[s_stream_offset], size);
    s_stream_offset += size;
}

void func_1C98A0(void *self, int width, int height) {
    (void)self;
    s_func_1C98A0_called++;
    s_last_w = width;
    s_last_h = height;
}

void func_1CF3E0(void *self, int a1, int a2, short a3, short a4, int t1, int t2, int t3) {
    (void)self; (void)a1; (void)a2; (void)a3; (void)a4; (void)t1; (void)t2; (void)t3;
    s_func_1CF3E0_called++;
}

void func_1CF9B0(void *self, int a1, int a2, int a3, int t0, short a5, short a6, int t1, long long sp0, long long sp8) {
    (void)self; (void)a1; (void)a2; (void)a3; (void)t0; (void)a5; (void)a6; (void)t1; (void)sp0; (void)sp8;
    s_func_1CF9B0_called++;
}
}

template <typename T>
static void append_data(const T &val) {
    const unsigned char *p = reinterpret_cast<const unsigned char *>(&val);
    s_stream_data.insert(s_stream_data.end(), p, p + sizeof(T));
}

int main() {
    ZoneLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    int w = 3;
    int h = 2;
    zm.width = w;
    zm.height = h;

    ZoneCell row0[3];
    ZoneCell row1[3];
    std::memset(row0, 0, sizeof(row0));
    std::memset(row1, 0, sizeof(row1));

    ZoneCell *rows[2] = {row0, row1};
    zm.cells_ptr = rows;

    s_stream_data.clear();
    s_stream_offset = 0;

    // 1. width, height
    append_data(w);
    append_data(h);

    // 2. per cell (y in [0, h), x in [0, w)): 3 bytes b1, b2, b3
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            unsigned char b1 = (unsigned char)(10 * y + x + 1);
            unsigned char b2 = (unsigned char)(20 * y + x + 1);
            unsigned char b3 = 0xFF;
            append_data(b1);
            append_data(b2);
            append_data(b3);
        }
    }

    void *dummy_stream = (void *)0x5678;
    func_001CB4D0(&zm, dummy_stream);

    assert(s_func_1C98A0_called == 1);
    assert(s_last_w == 3);
    assert(s_last_h == 2);

    // Verify cell unpacking
    assert(row0[0].f_5 == 1);
    assert(row0[0].f_6 == 1);

    assert(row0[1].f_5 == 2);
    assert(row0[1].f_6 == 2);

    assert(row1[2].f_5 == 13);
    assert(row1[2].f_6 == 23);

    assert(s_func_1CF3E0_called == 1);
    assert(s_func_1CF9B0_called == 1);

    return 0;
}
