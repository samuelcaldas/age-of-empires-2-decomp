// Tests for func_00278EF0 & func_00278FB0 — Milestone 117 (368B)
// Verifies batch garrison threat clearance and recalculation.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_78ef0.h"

static float g_threat_change = 0.0f;
extern "C" {
    int func_268500(void *) { return 1; }
    float func_2786F0(void *) { return 10.0f; }
    void func_278900(void *, float *accum, float dps) { *accum -= dps; }
    void func_278870(void *, float *accum, float dps) { *accum += dps; }
}

static void test_clear_and_recalc_garrison_threat() {
    unsigned char building[512], bldg_proto[512], unit1[256], unit2[256];
    unsigned char proto1[64], proto2[64];

    std::memset(building, 0, sizeof(building));
    std::memset(bldg_proto, 0, sizeof(bldg_proto));
    std::memset(unit1, 0, sizeof(unit1));
    std::memset(unit2, 0, sizeof(unit2));
    std::memset(proto1, 0, sizeof(proto1));
    std::memset(proto2, 0, sizeof(proto2));

    void *bldg_proto_ptr = bldg_proto;
    void *proto1_ptr = proto1;
    void *proto2_ptr = proto2;
    void *unit1_ptr = unit1;
    void *unit2_ptr = unit2;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(building + 0x8, &bldg_proto_ptr, sizeof(void *));
    std::memcpy(building + 0x40, &unit1_ptr, sizeof(void *));
    std::memcpy(unit1 + 0x8, &proto1_ptr, sizeof(void *));
    std::memcpy(unit1 + 0x40, &unit2_ptr, sizeof(void *));
    std::memcpy(unit2 + 0x8, &proto2_ptr, sizeof(void *));
#else
    std::memcpy(building + 0x4, &bldg_proto_ptr, sizeof(void *));
    std::memcpy(building + 0x20, &unit1_ptr, sizeof(void *));
    std::memcpy(unit1 + 0x4, &proto1_ptr, sizeof(void *));
    std::memcpy(unit1 + 0x20, &unit2_ptr, sizeof(void *));
    std::memcpy(unit2 + 0x4, &proto2_ptr, sizeof(void *));
#endif

    float reload = 2.0f;
    std::memcpy(bldg_proto + 0x100, &reload, sizeof(float));

    proto1[0] = 0x46; // Military
    proto2[0] = 0x46; // Military

    float initial_threat = 50.0f;
    std::memcpy(building + 0x120, &initial_threat, sizeof(float));

    // Clear: 2 units * 10.0f subtracted -> threat should be 30.0f
    func_00278EF0(building);
    float threat_cleared = *(float *)(building + 0x120);
    assert(threat_cleared == 30.0f);

    // Recalculate: 2 units * 10.0f added -> threat should be 50.0f
    func_00278FB0(building);
    float threat_recalc = *(float *)(building + 0x120);
    assert(threat_recalc == 50.0f);

    printf("PASS test_clear_and_recalc_garrison_threat\n");
}

int main() {
    test_clear_and_recalc_garrison_threat();
    printf("All unit_action_build_78ef0 tests passed!\n");
    return 0;
}
