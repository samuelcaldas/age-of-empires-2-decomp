// Tests for func_2777A0 — Milestone 104 (1456B)
// Verifies AoE blast damage and tile area traversal.
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "unit_action_build_77a0.h"

extern "C" {
    int func_123350(float val) {
        return (int)std::floor(val);
    }
    int func_367560(void *) {
        return 0xFF;
    }
    int func_1AAB30() {
        return 0; // 0 roll -> 100% accuracy check pass
    }
}

static float mock_calculate_damage(void *, void *) {
    return 10.0f;
}

static float g_last_damage = 0.0f;
static void mock_take_damage(void *, short, int, void *, void *, int, float damage) {
    g_last_damage = damage;
}

static bool g_destroyed = false;
static void mock_destroy(void *, int, int) {
    g_destroyed = true;
}

static void test_zero_radius() {
    unsigned char self[256], proto[512];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));
    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif
    float radius = 0.0f;
    std::memcpy(proto + 0xFC, &radius, sizeof(float));
    int result = func_2777A0(self, 10.0f, 10.0f, nullptr, nullptr, nullptr);
    assert(result == 0);
    printf("PASS test_zero_radius\n");
}

static void test_blast_damage_application() {
    unsigned char self[256], self_proto[512], owner[0x4000], world[512], map[0x10000];
    std::memset(self, 0, sizeof(self));
    std::memset(self_proto, 0, sizeof(self_proto));
    std::memset(owner, 0, sizeof(owner));
    std::memset(world, 0, sizeof(world));
    std::memset(map, 0, sizeof(map));

    void *self_vtbl[100];
    self_vtbl[66] = (void *)mock_calculate_damage;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *self_proto_ptr = self_proto;
    void *owner_ptr = owner;
    void *world_ptr = world;
    void *map_ptr = map;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &self_proto_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0x1730, &world_ptr, sizeof(void *));
    std::memcpy(world + 0x78, &map_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &self_proto_ptr, sizeof(void *));
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0xB98, &world_ptr, sizeof(void *));
    std::memcpy(world + 0x3C, &map_ptr, sizeof(void *));
#endif

    float blast_radius = 5.0f;
    std::memcpy(self_proto + 0xFC, &blast_radius, sizeof(float));
    short accuracy = 100;
    std::memcpy(self_proto + 0x106, &accuracy, sizeof(short));
    float alliance_thresh = 0.5f;
    std::memcpy(self_proto + 0xF8, &alliance_thresh, sizeof(float));

    short map_w = 20, map_h = 20;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(map + 0x10, &map_w, sizeof(short));
    std::memcpy(map + 0x18, &map_h, sizeof(short));
#else
    std::memcpy(map + 0x8, &map_w, sizeof(short));
    std::memcpy(map + 0xC, &map_h, sizeof(short));
#endif

    unsigned char row[28 * 20];
    std::memset(row, 0, sizeof(row));
    void *row_ptrs[20];
    for (int i = 0; i < 20; ++i) row_ptrs[i] = row;
    void **row_ptrs_addr = row_ptrs;
    std::memcpy(map + 0x8E8C, &row_ptrs_addr, sizeof(void *));

    // Place entity at tile (10, 10)
    unsigned char *tile = row + (10 * 28);
    tile[0xD] = 1;

    unsigned char entity[256], entity_proto[256];
    std::memset(entity, 0, sizeof(entity));
    std::memset(entity_proto, 0, sizeof(entity_proto));

    void *entity_vtbl[100];
    entity_vtbl[33] = (void *)mock_take_damage;
    entity_vtbl[37] = (void *)mock_destroy;
    void *entity_vtbl_ptr = entity_vtbl;
    std::memcpy(entity, &entity_vtbl_ptr, sizeof(void *));

    void *entity_proto_ptr = entity_proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(entity + 0x8, &entity_proto_ptr, sizeof(void *));
#else
    std::memcpy(entity + 0x4, &entity_proto_ptr, sizeof(void *));
#endif

    float entity_x = 10.0f, entity_y = 10.0f;
    std::memcpy(entity + 0x44, &entity_x, sizeof(float));
    std::memcpy(entity + 0x48, &entity_y, sizeof(float));
    float health = 0.5f; // < 1.0f -> triggers destroy!
    std::memcpy(entity + 0x30, &health, sizeof(float));

    void *entity_list[4] = { entity, nullptr, nullptr, nullptr };
    void **entity_list_ptr = entity_list;
    std::memcpy(tile + 0x14, &entity_list_ptr, sizeof(void *));

    g_last_damage = 0.0f;
    g_destroyed = false;
    int result = func_2777A0(self, 10.0f, 10.0f, nullptr, nullptr, nullptr);
    assert(result == 1);
    assert(g_last_damage > 0.0f);
    assert(g_destroyed == true);
    printf("PASS test_blast_damage_application\n");
}

int main() {
    test_zero_radius();
    test_blast_damage_application();
    printf("All unit_action_build_77a0 tests passed!\n");
    return 0;
}
