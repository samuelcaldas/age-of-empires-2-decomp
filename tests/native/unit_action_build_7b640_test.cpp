// Tests for func_0027B620, func_0027B630, func_0027B6B0 (Milestone 135)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7b640.h"

struct EventRecord {
    short x;
    short y;
};

static void test_getter_7b620() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));
    int count = 42;
    std::memcpy(self + 0x5DC, &count, sizeof(int));

    assert(func_0027B620(self) == 42);
    assert(func_0027B640(self) == 42);
    printf("PASS test_getter_7b620\n");
}

static void test_query_7b630() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));
    int count = 5;
    std::memcpy(self + 0x5DC, &count, sizeof(int));

    EventRecord *records = (EventRecord *)self;
    records[2].x = 100;
    records[2].y = 200;

    float out_x = -1.0f, out_y = -1.0f;

    // Out of bounds
    assert(func_0027B630(self, 0, -1, &out_x, &out_y) == 0);
    assert(func_0027B630(self, 0, 5, &out_x, &out_y) == 0);

    // Flag != 0: returns 1 without writing outputs
    out_x = -99.0f;
    out_y = -99.0f;
    assert(func_0027B630(self, 1, 2, &out_x, &out_y) == 1);
    assert(out_x == -99.0f && out_y == -99.0f);

    // Flag == 0: writes coordinates and returns 1
    assert(func_0027B630(self, 0, 2, &out_x, &out_y) == 1);
    assert(out_x == 100.0f && out_y == 200.0f);

    // Test alias
    out_x = 0.0f; out_y = 0.0f;
    assert(func_0027B650(self, 0, 2, &out_x, &out_y) == 1);
    assert(out_x == 100.0f && out_y == 200.0f);

    printf("PASS test_query_7b630\n");
}

static void test_allocator_7b6b0() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));

    // Fill all 36 entries with non-zero markers (occupied)
    for (int i = 0; i < 36; ++i) {
        int marker = 100 + i;
        std::memcpy(self + 0x1E4 + (i * 28) + 0x8, &marker, sizeof(int));
    }

    // All occupied -> returns nullptr
    assert(func_0027B6B0(self) == nullptr);

    // Free slot at index 7 (set marker to 0)
    int zero_marker = 0;
    std::memcpy(self + 0x1E4 + (7 * 28) + 0x8, &zero_marker, sizeof(int));

    void *found = func_0027B6B0(self);
    assert(found == (void *)(self + 0x1E4 + (7 * 28)));

    // Test alias
    assert(func_0027B6D0(self) == (void *)(self + 0x1E4 + (7 * 28)));

    printf("PASS test_allocator_7b6b0\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) test_getter_7b620();
        else if (case_num == 1) test_query_7b630();
        else if (case_num == 2) test_allocator_7b6b0();
        return 0;
    }
    test_getter_7b620();
    test_query_7b630();
    test_allocator_7b6b0();
    printf("All unit_action_build_7b640 tests passed!\n");
    return 0;
}
