// Tests for func_00273970 — Milestone 76 (2384B)
// Verifies ActionBuild state transition validation, attachment checks,
// cost refunds, and final state transition dispatch via func_00268200.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_3970.h"

static int g_f8200_calls = 0;
static int g_last_state = -1;
static int g_cost_refund_calls = 0;
static int g_last_refund_res = 0;
static int g_v68_calls = 0;

extern "C" void func_00275A40(void *) {}
extern "C" int func_00268530(void *) { return 1; }
extern "C" void func_001827B0(void *, void *) {}
extern "C" int func_123350(float) { return 0; }
extern "C" void func_001CF350(void *, void *, int) {}

extern "C" int func_00268200(void *, int state) {
    g_f8200_calls++;
    g_last_state = state;
    return 1;
}

static void mock_v68(void *, void *) {
    g_v68_calls++;
}

static void mock_refund(void *, int res_id) {
    g_cost_refund_calls++;
    g_last_refund_res = res_id;
}

static void setup_test(unsigned char *self, unsigned char *proto,
                       unsigned char *owner, unsigned char *stats,
                       unsigned char *field_70, void **self_vtbl,
                       void **owner_vtbl) {
    std::memset(self, 0, 512);
    std::memset(proto, 0, 512);
    std::memset(owner, 0, 8192);
    std::memset(stats, 0, 1024);
    std::memset(field_70, 0, 1024);
    std::memset(self_vtbl, 0, 64 * sizeof(void *));
    std::memset(owner_vtbl, 0, 64 * sizeof(void *));

    self_vtbl[26] = (void *)mock_v68;
    owner_vtbl[30] = (void *)mock_refund;

    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *proto_ptr = proto;
    void *owner_ptr = owner;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
#endif

    void *stats_ptr = stats;
    std::memcpy(owner + 0xBAC, &stats_ptr, sizeof(void *));
    void *field_70_ptr = field_70;
    std::memcpy(owner + 0x70, &field_70_ptr, sizeof(void *));
    void *owner_vtbl_ptr = owner_vtbl;
    std::memcpy(owner + 0x1B30, &owner_vtbl_ptr, sizeof(void *));
}

static void test_state_transition_dispatched() {
    unsigned char self[512], proto[512], owner[8192], stats[1024], field_70[1024];
    void *self_vtbl[64], *owner_vtbl[64];
    setup_test(self, proto, owner, stats, field_70, self_vtbl, owner_vtbl);

    g_f8200_calls = 0;
    g_last_state = -1;

    int res = func_00273970(self, 4);
    assert(res == 1);
    assert(g_f8200_calls == 1);
    assert(g_last_state == 4);
    printf("PASS test_state_transition_dispatched\n");
}

static void test_refund_triggered_on_negative_stats() {
    unsigned char self[512], proto[512], owner[8192], stats[1024], field_70[1024];
    void *self_vtbl[64], *owner_vtbl[64];
    setup_test(self, proto, owner, stats, field_70, self_vtbl, owner_vtbl);

    g_cost_refund_calls = 0;
    float neg_val = -10.0f;
    std::memcpy(stats + 0x24C, &neg_val, sizeof(float));
    std::memcpy(stats + 0x290, &neg_val, sizeof(float));

    int res = func_00273970(self, 2);
    assert(res == 1);
    assert(g_cost_refund_calls == 2);
    printf("PASS test_refund_triggered_on_negative_stats\n");
}

int main() {
    test_state_transition_dispatched();
    test_refund_triggered_on_negative_stats();
    printf("All unit_action_build_3970 tests passed!\n");
    return 0;
}
