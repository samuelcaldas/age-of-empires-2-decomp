#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include "tactical_ai_combat_subsystem_controller_profiler.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

struct SystemManager {};
static SystemManager s_dummy_mgr;
SystemManager *D_004E3180 = &s_dummy_mgr;

static unsigned int s_timer_calls = 0;
static unsigned int s_timer_values[2] = { 1000, 1500 };

static int s_1f60f0_calls = 0;
static void *s_last_1f60f0_args[6] = { nullptr };
static int s_1f60f0_ret = 42;

static int s_184b60_calls = 0;
static SystemManager *s_last_184b60_mgr = nullptr;
static int s_last_184b60_channel = -1;
static unsigned int s_last_184b60_delta = 0;

extern "C" {
    unsigned int func_2261C0() {
        unsigned int val = s_timer_values[s_timer_calls % 2];
        s_timer_calls++;
        return val;
    }
    int func_1F60F0(void *a0, void *a1, void *a2, void *a3, void *t0, void *t1) {
        s_1f60f0_calls++;
        s_last_1f60f0_args[0] = a0;
        s_last_1f60f0_args[1] = a1;
        s_last_1f60f0_args[2] = a2;
        s_last_1f60f0_args[3] = a3;
        s_last_1f60f0_args[4] = t0;
        s_last_1f60f0_args[5] = t1;
        return s_1f60f0_ret;
    }
    void func_184B60(SystemManager *mgr, int channel, unsigned int delta) {
        s_184b60_calls++;
        s_last_184b60_mgr = mgr;
        s_last_184b60_channel = channel;
        s_last_184b60_delta = delta;
    }
}

static void reset_mocks() {
    s_timer_calls = 0;
    s_timer_values[0] = 1000;
    s_timer_values[1] = 1500;
    s_1f60f0_calls = 0;
    std::memset(s_last_1f60f0_args, 0, sizeof(s_last_1f60f0_args));
    s_1f60f0_ret = 42;
    s_184b60_calls = 0;
    s_last_184b60_mgr = nullptr;
    s_last_184b60_channel = -1;
    s_last_184b60_delta = 0;
}

static void test_profiler_passthrough() {
    reset_mocks();
    void *p0 = (void*)0x1000;
    void *p1 = (void*)0x2000;
    void *p2 = (void*)0x3000;
    void *p3 = (void*)0x4000;
    void *p4 = (void*)0x5000;
    void *p5 = (void*)0x6000;

    int ret = func_00329F00(p0, p1, p2, p3, p4, p5);

    TEST_ASSERT(ret == 42, "profiler return value mismatch");
    TEST_ASSERT(s_1f60f0_calls == 1, "profiler must call func_1F60F0 once");
    TEST_ASSERT(s_last_1f60f0_args[0] == p0, "arg0 mismatch");
    TEST_ASSERT(s_last_1f60f0_args[1] == p1, "arg1 mismatch");
    TEST_ASSERT(s_last_1f60f0_args[2] == p2, "arg2 mismatch");
    TEST_ASSERT(s_last_1f60f0_args[3] == p3, "arg3 mismatch");
    TEST_ASSERT(s_last_1f60f0_args[4] == p4, "arg4 mismatch");
    TEST_ASSERT(s_last_1f60f0_args[5] == p5, "arg5 mismatch");

    TEST_ASSERT(s_timer_calls == 2, "profiler must query timer twice");
    TEST_ASSERT(s_184b60_calls == 1, "profiler must notify telemetery once");
    TEST_ASSERT(s_last_184b60_mgr == D_004E3180, "telemetry manager mismatch");
    TEST_ASSERT(s_last_184b60_channel == 13, "telemetry channel must be 13");
    TEST_ASSERT(s_last_184b60_delta == 500, "telemetry delta calculation failed");
}

static void test_profiler_zero_delta() {
    reset_mocks();
    s_timer_values[0] = 5000;
    s_timer_values[1] = 5000;

    int ret = func_00329F00(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    TEST_ASSERT(ret == 42, "zero delta return value mismatch");
    TEST_ASSERT(s_last_184b60_delta == 0, "zero delta must report 0 elapsed");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "passthrough") == 0) { test_profiler_passthrough(); return 0; }
        if (std::strcmp(argv[1], "zero_delta") == 0) { test_profiler_zero_delta(); return 0; }
    }
    test_profiler_passthrough();
    test_profiler_zero_delta();
    return 0;
}
