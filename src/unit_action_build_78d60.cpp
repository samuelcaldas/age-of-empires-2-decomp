#pragma exceptions off
#include "unit_action_build_78d60.h"

extern "C" {
    float func_2786F0(void *unit);
    void func_278870(void *unit, float *threat_accum, float dps);
    void func_278900(void *unit, float *threat_accum, float dps);
    void func_268980(void *building, void *unit);
    int func_268500(void *building);
    int func_268530(void *building);
    void func_1827B0(void *sound_sys, int effect_id);
    void func_2C2D20(void *sound_sys, int effect_id, int p1, int p2, int p3);
}

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET    0x8
#define BUILDING_SOUND_OFFSET 0x18
#else
#define UNIT_PROTO_OFFSET    0x4
#define BUILDING_SOUND_OFFSET 0xC
#endif

static void update_garrison_threat(void *building, void *unit, bool is_adding) {
    void *unit_proto = *(void **)((char *)unit + UNIT_PROTO_OFFSET);
    if (*(unsigned char *)unit_proto != 0x46) return;
    float dps = func_2786F0(unit);
    float *accum = (float *)((char *)building + 0x120);
    if (is_adding) {
        func_278870(unit, accum, dps);
        return;
    }
    func_278900(unit, accum, dps);
}

static void trigger_garrison_sound(void *building, int effect_id, bool is_garrison) {
    if (func_268500(building) == 0) return;
    if (func_268530(building) != 1) return;
    void *sound_sys = *(void **)((char *)building + BUILDING_SOUND_OFFSET);
    if (is_garrison) {
        func_1827B0(sound_sys, effect_id);
        func_2C2D20(sound_sys, effect_id, 0x5A, 0, 0);
        return;
    }
    func_1827B0(sound_sys, effect_id);
    func_2C2D20(sound_sys, effect_id, 0x5B, 0, 0);
}

void func_278D60(void *building, void *unit) {
    update_garrison_threat(building, unit, true);
    func_268980(building, unit);
    void *bldg_proto = *(void **)((char *)building + UNIT_PROTO_OFFSET);
    int effect_id = *(int *)((char *)bldg_proto + 0x164);
    if (effect_id == 0) return;
    trigger_garrison_sound(building, effect_id, true);
}

void func_278E30(void *building, void *unit) {
    update_garrison_threat(building, unit, false);
    void *bldg_proto = *(void **)((char *)building + UNIT_PROTO_OFFSET);
    int effect_id = *(int *)((char *)bldg_proto + 0x164);
    if (effect_id == 0) return;
    trigger_garrison_sound(building, effect_id, false);
}
