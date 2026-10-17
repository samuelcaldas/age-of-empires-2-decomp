// Tests for func_002789A0 — Milestone 115 (948B)
// Verifies allied foundation and garrison/boarding validation.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_789a0.h"

static int g_func_314550_ret = 1;
extern "C" int func_314550(void *, void *, int, int) {
    return g_func_314550_ret;
}

static int mock_relation_allied(void *, void *) {
    return 1;
}

static int mock_validate_action(void *) {
    return 1;
}

static void test_null_target_owner() {
    unsigned char self[256];
    assert(func_002789A0(self, nullptr, 0, 0) == 0);
    printf("PASS test_null_target_owner\n");
}

static void test_allied_builder_mode() {
    unsigned char self[256], self_proto[64], self_owner[0x4000], target_owner[0x4000];
    unsigned char relation_obj[64], target_units[64], target_unit[64], world[64];

    std::memset(self, 0, sizeof(self));
    std::memset(self_proto, 0, sizeof(self_proto));
    std::memset(self_owner, 0, sizeof(self_owner));
    std::memset(target_owner, 0, sizeof(target_owner));
    std::memset(relation_obj, 0, sizeof(relation_obj));
    std::memset(target_units, 0, sizeof(target_units));
    std::memset(target_unit, 0, sizeof(target_unit));
    std::memset(world, 0, sizeof(world));

    void *self_vtbl[100];
    self_vtbl[56] = (void *)mock_validate_action;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *self_proto_ptr = self_proto;
    void *self_owner_ptr = self_owner;
    void *target_units_ptr = target_units;
    void *target_unit_ptr = target_unit;
    void *world_ptr = world;
    void *relation_obj_ptr = relation_obj;

    void *relation_fn = (void *)mock_relation_allied;
    std::memcpy(relation_obj + 0x24, &relation_fn, sizeof(void *));

    void **target_units_arr = (void **)target_units;
    target_units_arr[0] = target_unit_ptr;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &self_proto_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &self_owner_ptr, sizeof(void *));
    std::memcpy(self_owner + 0x1730, &world_ptr, sizeof(void *));
    std::memcpy(self_owner + 0x2E60, &relation_obj_ptr, sizeof(void *));
    std::memcpy(target_owner + 0x2E60, &relation_obj_ptr, sizeof(void *));
    std::memcpy(target_owner + 0xE0, &target_units_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &self_proto_ptr, sizeof(void *));
    std::memcpy(self + 0x8, &self_owner_ptr, sizeof(void *));
    std::memcpy(self_owner + 0xB98, &world_ptr, sizeof(void *));
    std::memcpy(self_owner + 0x1B30, &relation_obj_ptr, sizeof(void *));
    std::memcpy(target_owner + 0x1B30, &relation_obj_ptr, sizeof(void *));
    std::memcpy(target_owner + 0x70, &target_units_ptr, sizeof(void *));
#endif

    short builder_type = 20; // Villager / builder
    std::memcpy(self_proto + 0xE, &builder_type, sizeof(short));
    self[0x39] = 2; // Builder mode

    target_unit[0] = 0x46; // Target unit state

    int ret = func_002789A0(self, target_owner, 0, 1);
    assert(ret == 1);
    printf("PASS test_allied_builder_mode\n");
}

int main() {
    test_null_target_owner();
    test_allied_builder_mode();
    printf("All unit_action_build_789a0 tests passed!\n");
    return 0;
}
