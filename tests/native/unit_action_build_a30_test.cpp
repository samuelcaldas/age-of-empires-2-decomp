// Tests for func_00271A30 — Milestone 63 (272B)
// Verifies Euclidean footprint distance calculation, minimum distance clamping (0.1f),
// and travel work scaling by game speed / unit rate parameters.
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include "unit_action_build_a30.h"

extern "C" float func_1234E0(float val) {
    return std::sqrt(val);
}

static void setup_hierarchy(unsigned char *self, unsigned char *proto,
                            unsigned char *owner, unsigned char *mgr,
                            unsigned char *cfg) {
    std::memset(self, 0, 256);
    std::memset(proto, 0, 256);
    std::memset(owner, 0, 4096);
    std::memset(mgr, 0, 256);
    std::memset(cfg, 0, 256);

#if defined(__LP64__) || defined(_LP64)
    void *proto_ptr = proto;
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
    void *owner_ptr = owner;
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
#else
    void *proto_ptr = proto;
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
    void *owner_ptr = owner;
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
#endif

    void *mgr_ptr = mgr;
    std::memcpy(owner + 0xB98, &mgr_ptr, sizeof(void *));
    void *cfg_ptr = cfg;
    std::memcpy(mgr + 0x3C, &cfg_ptr, sizeof(void *));

    float origin_x = 10.0f, origin_y = 20.0f;
    std::memcpy(self + 0x44, &origin_x, sizeof(float));
    std::memcpy(self + 0x48, &origin_y, sizeof(float));

    float half_width = 1.0f, half_height = 1.0f;
    std::memcpy(proto + 0x20, &half_width, sizeof(float));
    std::memcpy(proto + 0x24, &half_height, sizeof(float));

    int denom = 100;
    std::memcpy(cfg + 0x8, &denom, sizeof(int));
}

static void test_zero_distance_clamped_to_min() {
    unsigned char self[256], proto[256], owner[4096], mgr[256], cfg[256];
    setup_hierarchy(self, proto, owner, mgr, cfg);

    float res = func_00271A30(self, 10.0f, 20.0f, 1.0f, 1.0f);
    assert(std::fabs(res - 0.0602f) < 1e-4f);
    printf("PASS test_zero_distance_clamped_to_min: %f\n", res);
}

static void test_nonzero_distance_calculation() {
    unsigned char self[256], proto[256], owner[4096], mgr[256], cfg[256];
    setup_hierarchy(self, proto, owner, mgr, cfg);

    float res = func_00271A30(self, 17.0f, 20.0f, 2.0f, 2.0f);
    assert(std::fabs(res - 2.72f) < 1e-4f);
    printf("PASS test_nonzero_distance_calculation: %f\n", res);
}

int main() {
    test_zero_distance_clamped_to_min();
    test_nonzero_distance_calculation();
    printf("All unit_action_build_a30 tests passed!\n");
    return 0;
}
