#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_elevation_mesh_remove.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static_assert(sizeof(void *) == 4, "PS2 pointer width");
static_assert(sizeof(int) == 4, "PS2 int width");
static_assert(sizeof(MeshVertex) == 8, "vertex size");
static_assert(offsetof(MeshVertex, m_id) == 0, "m_id");
static_assert(offsetof(MeshVertex, m_flags_4) == 4, "flags_4");
static_assert(offsetof(MeshVertex, m_flags_5) == 5, "flags_5");
static_assert(offsetof(MeshVertex, m_x) == 6, "m_x");
static_assert(offsetof(MeshVertex, m_y) == 7, "m_y");
static_assert(offsetof(ElevationMeshDescriptor, m_table_0) == 0x00, "table_0");
static_assert(offsetof(ElevationMeshDescriptor, m_table_8) == 0x08, "table_8");
static_assert(offsetof(ElevationMeshDescriptor, m_count) == 0x10, "count");

static void test_early_exits() {
    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_count = 0;

    int res = func_00328300(&desc, 10, 0);
    TEST_ASSERT(res == -1, "early exit remove count 0 failed");

    desc.m_count = 1;
    int table8[2] = {0, 0};
    desc.m_table_8 = table8;
    res = func_00328300(&desc, 10, 0);
    TEST_ASSERT(res == 0, "early exit remove tag count 0 failed");
}

static void test_not_found() {
    MeshVertex buffer[2];
    std::memset(buffer, 0, sizeof(buffer));
    buffer[0].m_id = 100;
    void *table0[1] = {buffer};
    int table8[1] = {1};

    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_count = 1;
    desc.m_table_0 = table0;
    desc.m_table_8 = table8;

    int res = func_00328300(&desc, 999, 0);
    TEST_ASSERT(res == -1, "not found remove failed");
    TEST_ASSERT(table8[0] == 1, "not found table count modified");
}

static void test_remove_single() {
    MeshVertex buffer[1];
    std::memset(buffer, 0, sizeof(buffer));
    buffer[0].m_id = 55;
    void *table0[1] = {buffer};
    int table8[1] = {1};

    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_count = 1;
    desc.m_table_0 = table0;
    desc.m_table_8 = table8;

    int res = func_00328300(&desc, 55, 0);
    TEST_ASSERT(res == 0, "single remove failed");
    TEST_ASSERT(table8[0] == 0, "single remove table count not decremented");
}

static void test_remove_swap_last() {
    MeshVertex buffer[3];
    std::memset(buffer, 0, sizeof(buffer));
    buffer[0].m_id = 10;
    buffer[1].m_id = 20;
    buffer[1].m_x = 5;
    buffer[2].m_id = 30;
    buffer[2].m_x = 9;

    void *table0[1] = {buffer};
    int table8[1] = {3};

    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_count = 1;
    desc.m_table_0 = table0;
    desc.m_table_8 = table8;

    int res = func_00328300(&desc, 20, 0);
    TEST_ASSERT(res == 1, "swap last remove failed");
    TEST_ASSERT(table8[0] == 2, "swap last table count decrement failed");
    TEST_ASSERT(buffer[1].m_id == 30, "swap last vertex data swap failed");
    TEST_ASSERT(buffer[1].m_x == 9, "swap last vertex data swap failed");

    res = func_00328300(&desc, 30, 0);
    TEST_ASSERT(res == 1, "swap last second remove failed");
    TEST_ASSERT(table8[0] == 1, "swap last second table count update failed");
    TEST_ASSERT(buffer[0].m_id == 10, "swap last second buffer element corrupted");
}

static void test_zero_count_tag_behavior() {
    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_count = 1;
    int table8[1] = {0};
    desc.m_table_8 = table8;

    int res = func_00328300(&desc, 100, 0);
    TEST_ASSERT(res == 0, "zero count tag behavior failed");
}

static void test_nonzero_tag_removal() {
    MeshVertex buffer[2];
    std::memset(buffer, 0, sizeof(buffer));
    buffer[0].m_id = 77;
    void *table0[2] = {0, buffer};
    int table8[2] = {0, 1};

    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_count = 2;
    desc.m_table_0 = table0;
    desc.m_table_8 = table8;

    int res = func_00328300(&desc, 77, 1); // nonzero tag index 1
    TEST_ASSERT(res == 0, "nonzero tag removal failed");
    TEST_ASSERT(table8[1] == 0, "nonzero tag removal count decrement failed");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "early_exits") == 0) { test_early_exits(); return 0; }
        if (std::strcmp(argv[1], "not_found") == 0) { test_not_found(); return 0; }
        if (std::strcmp(argv[1], "remove_single") == 0) { test_remove_single(); return 0; }
        if (std::strcmp(argv[1], "swap_last") == 0) { test_remove_swap_last(); return 0; }
        if (std::strcmp(argv[1], "zero_count") == 0) { test_zero_count_tag_behavior(); return 0; }
        if (std::strcmp(argv[1], "nonzero_tag") == 0) { test_nonzero_tag_removal(); return 0; }
    }
    test_early_exits();
    test_not_found();
    test_remove_single();
    test_remove_swap_last();
    test_zero_count_tag_behavior();
    test_nonzero_tag_removal();
    return 0;
}
