// Tests for func_277190 — Milestone 102 (696B)
// Verifies ActionBuild spatial tile footprint and directional sector testing.
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "unit_action_build_7190.h"

struct SpatialFacetEntry {
    float min_angle1;
    float max_angle1;
    float min_angle2;
    float max_angle2;
    float offset_x;
    float offset_y;
    float offset_z;
    float offset_w;
};

SpatialFacetEntry D_00486C70[25];

extern "C" float func_33D590(float dy, float dx) {
    return std::atan2(dy, dx);
}

extern "C" int func_277180(void *) {
    return 1;
}

static void setup_facet_table() {
    std::memset(D_00486C70, 0, sizeof(D_00486C70));
    // Facet 0: sector 1 [0.0, 1.0], sector 2 [2.0, 3.0]
    D_00486C70[0].min_angle1 = 0.0f;
    D_00486C70[0].max_angle1 = 1.0f;
    D_00486C70[0].min_angle2 = 2.0f;
    D_00486C70[0].max_angle2 = 3.0f;
}

static void test_out_of_bounds() {
    unsigned char map[0x10000];
    std::memset(map, 0, sizeof(map));
    int width = 10, height = 10;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(map + 0x10, &width, sizeof(int));
    std::memcpy(map + 0x18, &height, sizeof(int));
#else
    std::memcpy(map + 0x8, &width, sizeof(int));
    std::memcpy(map + 0xC, &height, sizeof(int));
#endif
    float angle = -1.0f;
    int counter = 0;
    assert(func_277190(nullptr, nullptr, -1, 5, 0, 0, 0, 0, map, nullptr, &angle, &counter) == 0);
    assert(func_277190(nullptr, nullptr, 5, -1, 0, 0, 0, 0, map, nullptr, &angle, &counter) == 0);
    assert(func_277190(nullptr, nullptr, 10, 5, 0, 0, 0, 0, map, nullptr, &angle, &counter) == 0);
    assert(func_277190(nullptr, nullptr, 5, 10, 0, 0, 0, 0, map, nullptr, &angle, &counter) == 0);
    printf("PASS test_out_of_bounds\n");
}

static void test_entity_match_facet_range1() {
    setup_facet_table();
    unsigned char map[0x10000];
    std::memset(map, 0, sizeof(map));
    int width = 10, height = 10;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(map + 0x10, &width, sizeof(int));
    std::memcpy(map + 0x18, &height, sizeof(int));
#else
    std::memcpy(map + 0x8, &width, sizeof(int));
    std::memcpy(map + 0xC, &height, sizeof(int));
#endif

    unsigned char row[28 * 10];
    std::memset(row, 0, sizeof(row));
    void *row_ptrs[10];
    for (int i = 0; i < 10; ++i) row_ptrs[i] = row;
    void **row_ptrs_addr = row_ptrs;
    std::memcpy(map + 0x8E8C, &row_ptrs_addr, sizeof(void *));

    unsigned char *tile = row + (2 * 28);
    tile[0xD] = 1; // 1 entity
    unsigned char entity[256], proto[256];
    std::memset(entity, 0, sizeof(entity));
    std::memset(proto, 0, sizeof(proto));
    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(entity + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(entity + 0x4, &proto_ptr, sizeof(void *));
#endif
    short type = 0x22;
    std::memcpy(proto + 0xE, &type, sizeof(short));
    entity[0x35] = 0; // facet 0

    void *entity_list[4] = { entity, nullptr, nullptr, nullptr };
    void **entity_list_ptr = entity_list;
    std::memcpy(tile + 0x14, &entity_list_ptr, sizeof(void *));

    unsigned char self[256], target[256];
    std::memset(self, 0, sizeof(self));
    std::memset(target, 0, sizeof(target));
    float self_x = 0.0f, self_y = 0.0f;
    float target_x = 10.0f, target_y = 5.0f; // angle ~ 0.46 rad (in [0.0, 1.0])
    std::memcpy(self + 0x44, &self_x, sizeof(float));
    std::memcpy(self + 0x48, &self_y, sizeof(float));
    std::memcpy(target + 0x44, &target_x, sizeof(float));
    std::memcpy(target + 0x48, &target_y, sizeof(float));

    float angle = -1.0f;
    int counter = 0;
    int ret = func_277190(self, target, 2, 2, 0, 0, 0, 0, map, nullptr, &angle, &counter);
    assert(ret == 1);
    assert(counter == 1);
    printf("PASS test_entity_match_facet_range1\n");
}

int main() {
    test_out_of_bounds();
    test_entity_match_facet_range1();
    printf("All unit_action_build_7190 tests passed!\n");
    return 0;
}
