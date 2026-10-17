// Tests for func_00279700 & func_00279760 — Milestone 122 (552B)
// Verifies farm exhaustion and villager resource drop site dispatch.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_79700.h"

static int g_farm_depleted = 0;
static int g_new_task_created = 0;

extern "C" {
    void func_267E60(void *) { g_farm_depleted++; }
    static unsigned char g_drop_site[256];
    void *func_332E60(void *) { return g_drop_site; }
    int func_139720(void *) { return 1; }
    void *func_139860(void *) { return nullptr; }
    void *func_366D60(void *) {
        static int mock_task = 1;
        return &mock_task;
    }
    void func_361370(void *, void *, void *, void *) { g_new_task_created++; }
    void func_138D10(void *) {}
}

static void *mock_eval_path(void *, void *, int, float, float, float) {
    static int mock_path = 2;
    return &mock_path;
}

static void mock_assign_task(void *, void *) {}

static void test_farm_exhaustion() {
    unsigned char self[256], proto[64];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif
    short farm_type = 0x2A;
    std::memcpy(proto + 0xE, &farm_type, sizeof(short));

    // Remaining > 0 -> no depletion
    float remaining = 100.0f;
    std::memcpy(self + 0x40, &remaining, sizeof(float));
    g_farm_depleted = 0;
    func_00279700(self);
    assert(g_farm_depleted == 0);

    // Remaining <= 0 -> depleted
    remaining = 0.0f;
    std::memcpy(self + 0x40, &remaining, sizeof(float));
    func_00279700(self);
    assert(g_farm_depleted == 1);

    printf("PASS test_farm_exhaustion\n");
}

static void test_create_drop_task() {
    unsigned char self[512], owner[0x2000], world[64], action_mgr[64];
    std::memset(self, 0, sizeof(self));
    std::memset(owner, 0, sizeof(owner));
    std::memset(world, 0, sizeof(world));
    std::memset(action_mgr, 0, sizeof(action_mgr));

    void *self_vtbl[256];
    self_vtbl[198] = (void *)mock_eval_path;
    self_vtbl[196] = (void *)mock_assign_task;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *owner_ptr = owner;
    void *world_ptr = world;
    void *action_mgr_ptr = action_mgr;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    std::memcpy(self + 0x138, &action_mgr_ptr, sizeof(void *));
    std::memcpy(owner + 0x1730, &world_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    std::memcpy(self + 0xCC, &action_mgr_ptr, sizeof(void *));
    std::memcpy(owner + 0xB98, &world_ptr, sizeof(void *));
#endif

    g_new_task_created = 0;
    int ret = func_00279760(self, nullptr, 0);
    assert(ret == 1);
    assert(g_new_task_created == 1);
    printf("PASS test_create_drop_task\n");
}

int main() {
    test_farm_exhaustion();
    test_create_drop_task();
    printf("All unit_action_build_79700 tests passed!\n");
    return 0;
}
