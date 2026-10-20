#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_destructor.h"
#include "zone_spatial_grid_block63_layout.h"

struct GuardedGrid {
    unsigned char before[16];
    SpatialGridLayout grid;
    unsigned char after[16];
};

static SpatialGridLayout *observed_grid;
static char table_payloads[10];
static std::vector<int> operations;
static int table_call_count;

extern "C" void *D_004D9AD0[16] = {0};

extern "C" void func_001F34D0(ZoneSpatialGrid *self) {
    assert(self == reinterpret_cast<ZoneSpatialGrid *>(observed_grid));
    assert(observed_grid->vtable == D_004D9AD0);
    operations.push_back(1);
}

extern "C" void func_00116F68(void *) {
    assert(false && "A null list must not call the wrapper allocator");
}

extern "C" void func_0021B430(void *pointer) {
    int index = static_cast<char *>(pointer) - table_payloads;
    assert(index >= 0 && index < 10);
    assert(observed_grid->tables[index] == pointer);
    assert(observed_grid->buckets[index][0] == 0xA5);
    assert(observed_grid->counts[index] == 100 + index);
    assert(observed_grid->metadata[0] == (table_call_count == 0 ? 200 : 0));
    operations.push_back(10 + index);
    ++table_call_count;
}

extern "C" void func_001F32F0(ZoneSpatialGrid *self) {
    assert(self == reinterpret_cast<ZoneSpatialGrid *>(observed_grid));
    operations.push_back(2);
}

extern "C" void func_100670(void *pointer) {
    assert(pointer == observed_grid);
    assert(operations.back() == 2);
    operations.push_back(3);
}

static void initialize(GuardedGrid &storage, unsigned mask) {
    std::memset(&storage, 0xA5, sizeof(storage));
    storage.grid.head = 0;
    for (int index = 0; index < 10; ++index) {
        storage.grid.tables[index] = (mask & (1U << index)) ? &table_payloads[index] : 0;
        storage.grid.counts[index] = 100 + index;
        storage.grid.metadata[index] = 200 + index;
    }
}

static void expect_cleanup(GuardedGrid &expected, unsigned mask) {
    expected.grid.vtable = D_004D9AD0;
    for (int index = 0; index < 10; ++index) {
        if (!(mask & (1U << index))) continue;
        expected.grid.tables[index] = 0;
        expected.grid.buckets[index][0] = 0;
        expected.grid.counts[index] = 0;
        expected.grid.metadata[0] = 0;
    }
}

static void reset_observation(SpatialGridLayout &grid) {
    observed_grid = &grid;
    operations.clear();
    table_call_count = 0;
}

static void assert_order(unsigned mask, bool deletes_self) {
    std::vector<int> expected;
    expected.push_back(1);
    for (int index = 0; index < 10; ++index) {
        if (mask & (1U << index)) expected.push_back(10 + index);
    }
    expected.push_back(2);
    if (deletes_self) expected.push_back(3);
    assert(operations == expected);
}

static void test_tables(unsigned mask) {
    GuardedGrid actual;
    GuardedGrid expected;
    initialize(actual, mask);
    std::memcpy(&expected, &actual, sizeof(actual));
    expect_cleanup(expected, mask);
    reset_observation(actual.grid);
    ZoneSpatialGrid *pointer = reinterpret_cast<ZoneSpatialGrid *>(&actual.grid);
    assert(func_001F2590(pointer, 0) == pointer);
    assert(std::memcmp(&actual, &expected, sizeof(actual)) == 0);
    assert_order(mask, false);
}

static void test_flag(short flag) {
    GuardedGrid storage;
    initialize(storage, 0);
    reset_observation(storage.grid);
    ZoneSpatialGrid *pointer = reinterpret_cast<ZoneSpatialGrid *>(&storage.grid);
    assert(func_001F2590(pointer, flag) == pointer);
    assert_order(0, flag > 0);
}

static void test_null() {
    operations.clear();
    assert(func_001F2590(0, SHRT_MAX) == 0);
    assert(operations.empty());
}

static void test_layout() {
    assert(sizeof(void *) == 4);
    assert(sizeof(SpatialGridLayout) == 0xAB4);
    assert(offsetof(SpatialGridLayout, head) == 0x14);
    assert(offsetof(SpatialGridLayout, tables) == 0x20);
    assert(offsetof(SpatialGridLayout, buckets) == 0x48);
    assert(offsetof(SpatialGridLayout, counts) == 0xA48);
    assert(offsetof(SpatialGridLayout, metadata) == 0xA70);
}

int main(int argc, char **argv) {
    assert(argc == 3);
    test_layout();
    if (std::strcmp(argv[1], "tables") == 0) {
        test_tables(static_cast<unsigned>(std::strtoul(argv[2], 0, 0)));
        return 0;
    }
    if (std::strcmp(argv[1], "flag") == 0) {
        test_flag(static_cast<short>(std::strtol(argv[2], 0, 0)));
        return 0;
    }
    test_null();
    return 0;
}
