// Tests for func_274FD0 — Milestone 82 (1028B)
// Verifies construction progress coordination: sound triggers, dust scattering,
// and base action worker delegation.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_4fd0.h"

static int g_query_result = 1;
static int g_sound_calls = 0;
static int g_dust_calls = 0;
static int g_worker_calls = 0;

extern "C" int func_123350(float val) { return (int)val; }
extern "C" int func_801AAB30() { return 1000; }
extern "C" void func_803675D0(void *) { g_sound_calls++; }
extern "C" void func_802753E0(void *, void *, int, float, float, float, float, float) { g_dust_calls++; }
extern "C" int func_80195660(void *, void *, void *) { g_worker_calls++; return 42; }

static int mock_query(void *) { return g_query_result; }

static void setup_test(unsigned char *self, unsigned char *proto, void **vtbl) {
    std::memset(self, 0, 512);
    std::memset(proto, 0, 256);
    std::memset(vtbl, 256 * sizeof(void *), 0);

    vtbl[218] = (void *)mock_query;
    void *vtbl_ptr = vtbl;
    std::memcpy(self, &vtbl_ptr, sizeof(void *));

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif

    float w = 4.0f, h = 4.0f;
    std::memcpy(proto + 0x14C, &w, sizeof(float));
    std::memcpy(proto + 0x150, &h, sizeof(float));
}

static void test_active_coordination_triggers_effects() {
    unsigned char self[512], proto[256];
    void *vtbl[256];
    setup_test(self, proto, vtbl);

    g_query_result = 1;
    g_sound_calls = 0;
    g_dust_calls = 0;
    g_worker_calls = 0;

    int res = func_274FD0(self, nullptr, nullptr);
    assert(res == 42);
    assert(g_sound_calls == 1);
    assert(g_dust_calls == 1);
    assert(g_worker_calls == 1);
    printf("PASS test_active_coordination_triggers_effects\n");
}

static void test_inactive_skips_effects() {
    unsigned char self[512], proto[256];
    void *vtbl[256];
    setup_test(self, proto, vtbl);

    g_query_result = 0;
    g_sound_calls = 0;
    g_dust_calls = 0;
    g_worker_calls = 0;

    int res = func_274FD0(self, nullptr, nullptr);
    assert(res == 42);
    assert(g_sound_calls == 0);
    assert(g_dust_calls == 0);
    assert(g_worker_calls == 1);
    printf("PASS test_inactive_skips_effects\n");
}

int main() {
    test_active_coordination_triggers_effects();
    test_inactive_skips_effects();
    printf("All unit_action_build_4fd0 tests passed!\n");
    return 0;
}
