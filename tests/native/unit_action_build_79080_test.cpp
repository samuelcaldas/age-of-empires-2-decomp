// Tests for func_00279080 — Milestone 118 (144B)
// Verifies sprite transition with facet preservation and effect trigger.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_79080.h"

static int g_effect_triggered = 0;
static int g_flag_cleared = 0;
static void *g_sprite_set = nullptr;

extern "C" {
    int func_26AD20(void *, int) { return 1; }
    void func_1827B0(void *, int) { g_effect_triggered++; }
    void func_26AD60(void *, int) { g_flag_cleared++; }
    void func_1DC9D0(void *, void *sprite) { g_sprite_set = sprite; }
}

static void test_same_sprite_noop() {
    unsigned char self[256];
    void *sprite = (void *)0x1234;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x20, &sprite, sizeof(void *));
#else
    std::memcpy(self + 0x10, &sprite, sizeof(void *));
#endif
    g_sprite_set = nullptr;
    func_00279080(self, sprite);
    assert(g_sprite_set == nullptr);
    printf("PASS test_same_sprite_noop\n");
}

static void test_sprite_transition_preserves_facet() {
    unsigned char self[256], proto[512], owner[0x2000], world[512], sound_sys[64];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));
    std::memset(owner, 0, sizeof(owner));
    std::memset(world, 0, sizeof(world));
    std::memset(sound_sys, 0, sizeof(sound_sys));

    void *proto_ptr = proto;
    void *owner_ptr = owner;
    void *world_ptr = world;
    void *sound_sys_ptr = sound_sys;

    void *old_sprite = (void *)0x1111;
    void *new_sprite = (void *)0x2222;

    int effects_table[4] = { 10, 20, 30, 40 };
    int *effects_ptr = effects_table;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    std::memcpy(self + 0x18, &sound_sys_ptr, sizeof(void *));
    std::memcpy(self + 0x20, &old_sprite, sizeof(void *));
    std::memcpy(owner + 0x1730, &world_ptr, sizeof(void *));
    std::memcpy(world + 0x98, &effects_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    std::memcpy(self + 0xC, &sound_sys_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &old_sprite, sizeof(void *));
    std::memcpy(owner + 0xB98, &world_ptr, sizeof(void *));
    std::memcpy(world + 0x4C, &effects_ptr, sizeof(void *));
#endif

    int effect_idx = 1;
    std::memcpy(proto + 0x15C, &effect_idx, sizeof(int));
    self[0x35] = 7; // Facet to preserve

    g_effect_triggered = 0;
    g_flag_cleared = 0;
    g_sprite_set = nullptr;

    func_00279080(self, new_sprite);

    assert(g_effect_triggered == 1);
    assert(g_flag_cleared == 1);
    assert(g_sprite_set == new_sprite);
    assert(self[0x35] == 7);
    printf("PASS test_sprite_transition_preserves_facet\n");
}

int main() {
    test_same_sprite_noop();
    test_sprite_transition_preserves_facet();
    printf("All unit_action_build_79080 tests passed!\n");
    return 0;
}
