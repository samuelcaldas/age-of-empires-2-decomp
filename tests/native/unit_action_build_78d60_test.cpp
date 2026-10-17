// Tests for func_278D60 & func_278E30 — Milestone 116 (388B)
// Verifies garrison threat addition/subtraction and entry/exit effect triggers.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_78d60.h"

static int g_garrison_added = 0;
static float g_threat_val = 0.0f;
static int g_sound_triggered = 0;
static int g_sound_param = 0;

extern "C" {
    float func_2786F0(void *) { return 12.0f; }
    void func_278870(void *, float *accum, float dps) { *accum += dps; }
    void func_278900(void *, float *accum, float dps) { *accum -= dps; }
    void func_268980(void *, void *) { g_garrison_added++; }
    int func_268500(void *) { return 1; }
    int func_268530(void *) { return 1; }
    void func_1827B0(void *, int) {}
    void func_2C2D20(void *, int, int p1, int, int) {
        g_sound_triggered++;
        g_sound_param = p1;
    }
}

static void test_garrison_and_ungarrison() {
    unsigned char building[512], bldg_proto[512], unit[256], unit_proto[64], sound_sys[64];
    std::memset(building, 0, sizeof(building));
    std::memset(bldg_proto, 0, sizeof(bldg_proto));
    std::memset(unit, 0, sizeof(unit));
    std::memset(unit_proto, 0, sizeof(unit_proto));
    std::memset(sound_sys, 0, sizeof(sound_sys));

    void *bldg_proto_ptr = bldg_proto;
    void *unit_proto_ptr = unit_proto;
    void *sound_sys_ptr = sound_sys;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(building + 0x8, &bldg_proto_ptr, sizeof(void *));
    std::memcpy(building + 0x18, &sound_sys_ptr, sizeof(void *));
    std::memcpy(unit + 0x8, &unit_proto_ptr, sizeof(void *));
#else
    std::memcpy(building + 0x4, &bldg_proto_ptr, sizeof(void *));
    std::memcpy(building + 0xC, &sound_sys_ptr, sizeof(void *));
    std::memcpy(unit + 0x4, &unit_proto_ptr, sizeof(void *));
#endif

    unit_proto[0] = 0x46; // Military unit type
    int effect_id = 100;
    std::memcpy(bldg_proto + 0x164, &effect_id, sizeof(int));

    float initial_threat = 20.0f;
    std::memcpy(building + 0x120, &initial_threat, sizeof(float));

    g_garrison_added = 0;
    g_sound_triggered = 0;
    g_sound_param = 0;

    // Garrison unit: threat += 12.0f -> 32.0f, sound param 0x5A
    func_278D60(building, unit);
    float threat_after = *(float *)(building + 0x120);
    assert(threat_after == 32.0f);
    assert(g_garrison_added == 1);
    assert(g_sound_triggered == 1);
    assert(g_sound_param == 0x5A);

    // Ungarrison unit: threat -= 12.0f -> 20.0f, sound param 0x5B
    func_278E30(building, unit);
    float threat_final = *(float *)(building + 0x120);
    assert(threat_final == 20.0f);
    assert(g_sound_triggered == 2);
    assert(g_sound_param == 0x5B);

    printf("PASS test_garrison_and_ungarrison\n");
}

int main() {
    test_garrison_and_ungarrison();
    printf("All unit_action_build_78d60 tests passed!\n");
    return 0;
}
