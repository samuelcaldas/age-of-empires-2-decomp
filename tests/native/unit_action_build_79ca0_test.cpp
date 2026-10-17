// Tests for func_00279CA0 — Milestone 125 (216B)
// Verifies resuming saved gather order by target ID or coordinates.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_79ca0.h"

static int g_flag_cleared = 0;
static int g_order_resumed = 0;
static void *g_resumed_target = nullptr;
static float g_resumed_x = 0.0f;

extern "C" {
    int func_26AD20(void *, int) { return 1; } // Flag is set
    void func_26AD60(void *, int) { g_flag_cleared++; }
    static unsigned char g_target_obj[64];
    void *func_332E60(void *, int) { return g_target_obj; }
}

static void mock_resume_order(void *, void *target, int, int, float x, float, float) {
    g_order_resumed++;
    g_resumed_target = target;
    g_resumed_x = x;
}

static void test_resume_by_target_id() {
    unsigned char self[512], owner[0x2000], world[64];
    std::memset(self, 0, sizeof(self));
    std::memset(owner, 0, sizeof(owner));
    std::memset(world, 0, sizeof(world));

    void *self_vtbl[256];
    self_vtbl[192] = (void *)mock_resume_order;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *owner_ptr = owner;
    void *world_ptr = world;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0x1730, &world_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0xB98, &world_ptr, sizeof(void *));
#endif

    short target_id = 45;
    std::memcpy(self + 0x10E, &target_id, sizeof(short));
    float sx = 123.0f, sy = 456.0f;
    std::memcpy(self + 0x110, &sx, sizeof(float));
    std::memcpy(self + 0x114, &sy, sizeof(float));

    g_flag_cleared = 0;
    g_order_resumed = 0;
    g_resumed_target = nullptr;

    func_00279CA0(self);

    assert(g_flag_cleared == 1);
    assert(g_order_resumed == 1);
    assert(g_resumed_target != nullptr);
    assert(g_resumed_x == 123.0f);
    printf("PASS test_resume_by_target_id\n");
}

int main() {
    test_resume_by_target_id();
    printf("All unit_action_build_79ca0 tests passed!\n");
    return 0;
}
