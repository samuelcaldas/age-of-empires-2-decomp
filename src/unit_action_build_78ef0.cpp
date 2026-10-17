#pragma exceptions off
#include "unit_action_build_78ef0.h"

extern "C" {
    int func_268500(void *building);
    float func_2786F0(void *building);
    void func_278900(void *unit, float *threat_accum, float dps);
    void func_278870(void *unit, float *threat_accum, float dps);
}

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET    0x8
#define GARRISON_NEXT_OFFSET 0x40
#else
#define UNIT_PROTO_OFFSET    0x4
#define GARRISON_NEXT_OFFSET 0x20
#endif

typedef void (*ThreatUpdateFn)(void *unit, float *threat_accum, float dps);

static float get_building_threat_dps(void *building) {
    if (func_268500(building) == 0) return 0.0f;
    void *proto = *(void **)((char *)building + UNIT_PROTO_OFFSET);
    if (*(float *)((char *)proto + 0x100) <= 0.0f) return 0.0f;
    float dps = func_2786F0(building);
    return (dps <= 0.0f) ? 0.0f : dps;
}

static void iterate_garrison_threat(void *building, float dps, ThreatUpdateFn update_fn) {
    void *current = *(void **)((char *)building + GARRISON_NEXT_OFFSET);
    float *accum = (float *)((char *)building + 0x120);
    while (current != 0) {
        void *proto = *(void **)((char *)current + UNIT_PROTO_OFFSET);
        if (*(unsigned char *)proto == 0x46) {
            update_fn(current, accum, dps);
        }
        current = *(void **)((char *)current + GARRISON_NEXT_OFFSET);
    }
}

void func_00278EF0(void *building) {
    float dps = get_building_threat_dps(building);
    if (dps <= 0.0f) return;
    iterate_garrison_threat(building, dps, func_278900);
}

void func_00278FB0(void *building) {
    float dps = get_building_threat_dps(building);
    if (dps <= 0.0f) return;
    iterate_garrison_threat(building, dps, func_278870);
}
