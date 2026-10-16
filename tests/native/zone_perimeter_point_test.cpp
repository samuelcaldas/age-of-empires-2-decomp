#include "zone_raster_fixture_common.h"

extern "C" {
void func_001CAC00(void *self, short *buffer, short dx, short dy);
}

void test_perimeter_point_null_and_zero() {
    func_001CAC00(nullptr, nullptr, 5, 5);

    short buf[16];
    std::memset(buf, 0x55, sizeof(buf));
    buf[0] = 0;   // count = 0
    buf[1] = 5;   // capacity = 5
    func_001CAC00(nullptr, buf, 0, 0);
    assert(buf[0] == 0);
    assert(buf[1] == 5);
}

void test_perimeter_point_deduplication_and_capacity() {
    short buf[32];
    std::memset(buf, 0xEE, sizeof(buf));
    buf[0] = 0;   // count = 0
    buf[1] = 2;   // capacity = 2

    func_001CAC00(nullptr, buf, 10, 20);
    assert(buf[0] == 1);
    assert(buf[2] == 10);
    assert(buf[3] == 20);

    // Duplicate rejection
    func_001CAC00(nullptr, buf, 10, 20);
    assert(buf[0] == 1);

    // Second point reaches capacity
    func_001CAC00(nullptr, buf, 30, 40);
    assert(buf[0] == 2);
    assert(buf[4] == 30);
    assert(buf[5] == 40);

    // Overflow rejected; sentinels preserved
    func_001CAC00(nullptr, buf, 50, 60);
    assert(buf[0] == 2);
    assert(buf[6] == static_cast<short>(0xEEEE));
    assert(buf[7] == static_cast<short>(0xEEEE));
}

void test_perimeter_point_many_points() {
    short buf[64];
    std::memset(buf, 0, sizeof(buf));
    buf[0] = 0;
    buf[1] = 10;

    const short points[][2] = {
        {1, 2}, {-3, 4}, {5, -6}, {-7, -8}, {9, 10}
    };
    for (int i = 0; i < 5; i++) {
        func_001CAC00(nullptr, buf, points[i][0], points[i][1]);
    }
    assert(buf[0] == 5);
    for (int i = 0; i < 5; i++) {
        assert(buf[(i + 1) * 2 + 0] == points[i][0]);
        assert(buf[(i + 1) * 2 + 1] == points[i][1]);
    }
}
