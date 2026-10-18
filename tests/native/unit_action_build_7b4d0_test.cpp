// Tests for func_0027B4D0 — Milestone 134 (360B)
// Verifies combat event buffer insertion and automatic buffer compaction.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7b4d0.h"

extern "C" void *func_117CAC(void *dest, int val, unsigned long size) {
    return std::memset(dest, val, size);
}

struct EventRecord {
    short x;
    short y;
};

static void test_record_insertion_and_compaction() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));

    int count = 0;
    int capacity = 4; // Set small capacity for test
    std::memcpy(self + 0x5DC, &count, sizeof(int));
    std::memcpy(self + 0x5E0, &capacity, sizeof(int));

    // Insert 4 events
    func_0027B4D0(self, 0, 10.0f, 20.0f);
    func_0027B4D0(self, 0, 30.0f, 40.0f);
    func_0027B4D0(self, 0, 50.0f, 60.0f);
    func_0027B4D0(self, 0, 70.0f, 80.0f);

    int cur_count = *(int *)(self + 0x5DC);
    assert(cur_count == 4);

    EventRecord *records = (EventRecord *)self;
    assert(records[0].x == 10 && records[0].y == 20);
    assert(records[3].x == 70 && records[3].y == 80);

    // 5th insertion triggers compaction (halves 4 to 2, then inserts 3rd)
    func_0027B4D0(self, 0, 90.0f, 100.0f);

    cur_count = *(int *)(self + 0x5DC);
    assert(cur_count == 3);
    assert(records[0].x == 10 && records[0].y == 20); // record 0 preserved
    assert(records[1].x == 50 && records[1].y == 60); // record 2 moved to 1
    assert(records[2].x == 90 && records[2].y == 100); // new record at 2

    printf("PASS test_record_insertion_and_compaction\n");
}

int main() {
    test_record_insertion_and_compaction();
    printf("All unit_action_build_7b4d0 tests passed!\n");
    return 0;
}
