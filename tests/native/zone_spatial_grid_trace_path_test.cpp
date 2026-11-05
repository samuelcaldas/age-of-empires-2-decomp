#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_grid_trace_path.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct Vec2f {
    float x;
    float y;
};

struct GridBuffer {
    int count;          // 0x00
    Vec2f *buf_vec;     // 0x04
    int capacity;       // 0x08
    int *buf_int;       // 0x0C
};

static int s_calls_1e5380 = 0;

extern "C" {
int func_1E5380(void *self, int index) {
    s_calls_1e5380++;
    GridBuffer *gb = (GridBuffer *)self;
    gb->count = index; // mimics resize/grow
    return 0;
}
}

static void test_trace_path_insert() {
    GridBuffer gb;
    std::memset(&gb, 0, sizeof(gb));
    gb.count = 3;

    Vec2f vecs[10];
    int ints[10];
    std::memset(vecs, 0, sizeof(vecs));
    std::memset(ints, 0, sizeof(ints));

    vecs[0] = (Vec2f){ 1.0f, 1.0f }; ints[0] = 10;
    vecs[1] = (Vec2f){ 2.0f, 2.0f }; ints[1] = 20;
    vecs[2] = (Vec2f){ 3.0f, 3.0f }; ints[2] = 30;

    gb.buf_vec = vecs;
    gb.buf_int = ints;

    Vec2f new_pt = { 99.0f, 99.0f };
    s_calls_1e5380 = 0;

    // Insert at index 1
    func_001E5230(&gb, &new_pt, 1, 999);

    assert(s_calls_1e5380 == 1);
    // Element at 1 should now be new_pt and 999
    assert(vecs[1].x == 99.0f);
    assert(vecs[1].y == 99.0f);
    assert(ints[1] == 999);

    // Old element at 1 shifted to 2
    assert(vecs[2].x == 2.0f);
    assert(vecs[2].y == 2.0f);
    assert(ints[2] == 20);

    // Old element at 2 shifted to 3
    assert(vecs[3].x == 3.0f);
    assert(vecs[3].y == 3.0f);
    assert(ints[3] == 30);
}

int main() {
    test_trace_path_insert();
    std::printf("zone_spatial_grid_trace_path_test passed\n");
    return 0;
}
