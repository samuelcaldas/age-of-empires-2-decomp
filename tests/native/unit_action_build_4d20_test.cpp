// Tests for func_274D20 — Milestone 81 (684B)
// Verifies particle scattering logic, capacity bounds, and target particle spawning.
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "unit_action_build_4d20.h"

static int g_f123350_calls = 0;
static int g_rand_calls = 0;
static int g_f53e0_calls = 0;
static int g_f58c0_calls = 0;

extern "C" int func_123350(float val) {
    g_f123350_calls++;
    return (int)std::round(val);
}

extern "C" int func_801AAB30() {
    g_rand_calls++;
    return 16384;
}

extern "C" void func_802753E0(void *, void *, int, float, float, float, float, float) {
    g_f53e0_calls++;
}

extern "C" void func_801958C0(void *, void *, float, float, float) {
    g_f58c0_calls++;
}

static void setup_test(unsigned char *self, unsigned char *proto, unsigned char *owner) {
    std::memset(self, 0, 512);
    std::memset(proto, 0, 512);
    std::memset(owner, 0, 256);

    void *proto_ptr = proto;
    void *owner_ptr = owner;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
#endif
}

static void test_spawn_particles_success() {
    unsigned char self[512], proto[512], owner[256];
    setup_test(self, proto, owner);

    short pos_104 = 1;
    std::memcpy(proto + 0x104, &pos_104, sizeof(short));
    short type_d = 0xD;
    std::memcpy(proto + 0xE, &type_d, sizeof(short));
    unsigned char cap = 3;
    std::memcpy(proto + 0x145, &cap, sizeof(unsigned char));

    float w = 2.0f, h = 2.0f;
    std::memcpy(proto + 0x14C, &w, sizeof(float));
    std::memcpy(proto + 0x150, &h, sizeof(float));

    g_f53e0_calls = 0;
    g_f58c0_calls = 0;

    func_274D20(self, (void *)0x1234, 10.0f, 20.0f, 30.0f);

    assert(g_f53e0_calls == 3);
    printf("PASS test_spawn_particles_success\n");
}

int main() {
    test_spawn_particles_success();
    printf("All unit_action_build_4d20 tests passed!\n");
    return 0;
}
