// Tests for func_00279BA0 — Milestone 124 (244B)
// Verifies villager auto drop site search and deposit command.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_79ba0.h"

static int g_flag_checked = 0;
static int g_flag_set = 0;
static int g_drop_ordered = 0;
static short g_ordered_target_id = 0;

extern "C" {
    int func_26AD20(void *, int) {
        g_flag_checked++;
        return 0; // Not set
    }
    void func_26AD30(void *, int, int) {
        g_flag_set++;
    }
    int func_151970(void *) { return 2; }
    static unsigned char g_drop_site[256];
    static unsigned char g_drop_proto[64];
    void *func_332E60(void *, int) {
        short s_tid = 99;
        short s_ttype = 0x28;
        std::memcpy(g_drop_site + 0x24, &s_tid, sizeof(short));
        void *p_ptr = g_drop_proto;
#if defined(__LP64__) || defined(_LP64)
        std::memcpy(g_drop_site + 0x8, &p_ptr, sizeof(void *));
#else
        std::memcpy(g_drop_site + 0x4, &p_ptr, sizeof(void *));
#endif
        std::memcpy(g_drop_proto + 0xE, &s_ttype, sizeof(short));
        return g_drop_site;
    }
}

static void *mock_get_target_null(void *) { return nullptr; }
static void *mock_get_active_obj(void *) {
    static int dummy = 1;
    static int *dummy_ptr = &dummy;
    return &dummy_ptr;
}

static void mock_order_drop(void *, short target_id, short, float, float, float) {
    g_drop_ordered++;
    g_ordered_target_id = target_id;
}

static void test_flag_guard() {
    unsigned char self[256];
    auto check_set = [](void *, int) -> int { return 1; }; // Already set
    // Overriding behavior through local mock if needed
}

static void test_auto_find_drop_site_and_deposit() {
    unsigned char self[512], owner[0x2000], world[64];
    unsigned char target[256], target_proto[64];

    std::memset(self, 0, sizeof(self));
    std::memset(owner, 0, sizeof(owner));
    std::memset(world, 0, sizeof(world));
    std::memset(target, 0, sizeof(target));
    std::memset(target_proto, 0, sizeof(target_proto));

    void *self_vtbl[256];
    self_vtbl[55] = (void *)mock_get_target_null;
    self_vtbl[89] = (void *)mock_get_active_obj;
    self_vtbl[78] = (void *)mock_order_drop;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *owner_ptr = owner;
    void *world_ptr = world;
    void *target_proto_ptr = target_proto;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0x1730, &world_ptr, sizeof(void *));
    std::memcpy(target + 0x8, &target_proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0xB98, &world_ptr, sizeof(void *));
    std::memcpy(target + 0x4, &target_proto_ptr, sizeof(void *));
#endif

    short tid = 99;
    short ttype = 0x28;
    std::memcpy(target + 0x24, &tid, sizeof(short));
    std::memcpy(target_proto + 0xE, &ttype, sizeof(short));

    // Point g_drop_site mock to our target
    // Actually func_332E60 returns target
    auto mock_world_drop = +[](void *, int) -> void * {
        static unsigned char s_target[256], s_proto[64];
        short s_tid = 99;
        short s_ttype = 0x28;
        std::memcpy(s_target + 0x24, &s_tid, sizeof(short));
        void *p_ptr = s_proto;
#if defined(__LP64__) || defined(_LP64)
        std::memcpy(s_target + 0x8, &p_ptr, sizeof(void *));
#else
        std::memcpy(s_target + 0x4, &p_ptr, sizeof(void *));
#endif
        std::memcpy(s_proto + 0xE, &s_ttype, sizeof(short));
        return s_target;
    };
    // func_332E60 returns static drop site

    g_flag_checked = 0;
    g_flag_set = 0;
    g_drop_ordered = 0;

    int ret = func_00279BA0(self, 1);
    assert(ret == 1);
    assert(g_flag_checked == 1);
    assert(g_flag_set == 1);
    assert(g_drop_ordered == 1);

    printf("PASS test_auto_find_drop_site_and_deposit\n");
}

int main() {
    test_auto_find_drop_site_and_deposit();
    printf("All unit_action_build_79ba0 tests passed!\n");
    return 0;
}
