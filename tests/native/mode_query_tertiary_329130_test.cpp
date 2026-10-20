#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstddef>
#include <cstring>
#include "mode_query_tertiary_329130.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static_assert(sizeof(void *) == 4, "PS2 pointer width");
static_assert(sizeof(int) == 4, "PS2 int width");
static_assert(offsetof(ModeQueryTertiaryDescriptor, m_subsystem) == 0x120, "m_subsystem offset");

struct MockSecondary : public SecondarySubsystem {
    int m_last_zero;
    float m_last_fx;
    float m_last_fy;
    int m_ret_val;
    int m_query_call_count;

    MockSecondary() : m_last_zero(-1), m_last_fx(0.0f), m_last_fy(0.0f),
                      m_ret_val(0x142), m_query_call_count(0) {}

    void dummy0() override {}
    void dummy1() override {}
    void dummy2() override {}
    void dummy3() override {}
    void dummy4() override {}
    void dummy5() override {}
    void dummy6() override {}
    void dummy7() override {}
    void dummy8() override {}
    void dummy9() override {}
    void dummy10() override {}
    void dummy11() override {}
    void dummy12() override {}
    void dummy13() override {}
    void dummy14() override {}
    void dummy15() override {}
    void dummy16() override {}
    void dummy17() override {}
    void dummy18() override {}
    void dummy19() override {}
    void dummy20() override {}
    void dummy21() override {}
    void dummy22() override {}
    void dummy23() override {}
    void dummy24() override {}
    void dummy25() override {}
    void dummy26() override {}
    void dummy27() override {}
    void dummy28() override {}
    void dummy29() override {}
    void dummy30() override {}
    void dummy31() override {}
    void dummy32() override {}
    void dummy33() override {}
    void dummy34() override {}
    void dummy35() override {}
    void dummy36() override {}
    void dummy37() override {}
    void dummy38() override {}
    void dummy39() override {}
    void dummy40() override {}
    void dummy41() override {}
    void dummy42() override {}
    void dummy43() override {}

    int query(int zero, float fx, float fy) override {
        m_query_call_count++;
        m_last_zero = zero;
        m_last_fx = fx;
        m_last_fy = fy;
        return m_ret_val;
    }
};

struct MockGlobal : public GlobalContextNotify {
    int m_notify_count;
    int m_last_a1;
    int m_last_a2;

    MockGlobal() : m_notify_count(0), m_last_a1(-1), m_last_a2(-1) {}

    void g0() override {}
    void g1() override {}
    void g2() override {}
    void g3() override {}

    void notify(int a1, int a2) override {
        m_notify_count++;
        m_last_a1 = a1;
        m_last_a2 = a2;
    }
};

void *D_004E2EA0 = nullptr;
void *D_004E3180 = nullptr;

static int s_func_1A5010_ret = 1;
static short s_mock_out_x = 10;
static short s_mock_out_y = 20;
static int s_func_1A5010_call_count = 0;

extern "C" {
int func_1A5010(void *, int, int, short *out_x, short *out_y, void *) {
    s_func_1A5010_call_count++;
    *out_x = s_mock_out_x;
    *out_y = s_mock_out_y;
    return s_func_1A5010_ret;
}
}

static void test_null_global_guard() {
    MockGlobal global_obj;
    MockSecondary sec_obj;
    D_004E2EA0 = nullptr;
    D_004E3180 = &global_obj;

    ModeQueryTertiaryDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_subsystem = &sec_obj;

    int res = func_00329130(&desc, 1, 2);
    TEST_ASSERT(res == 0, "null global guard return 0 failed");
}

static void test_func_1A5010_rejection() {
    MockGlobal global_obj;
    D_004E2EA0 = (void *)1;
    D_004E3180 = &global_obj;

    MockSecondary sec_obj;
    ModeQueryTertiaryDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_subsystem = &sec_obj;

    s_func_1A5010_ret = 0;
    s_func_1A5010_call_count = 0;

    int res = func_00329130(&desc, 10, 20);
    TEST_ASSERT(res == 0, "rejected query return value failed");
    TEST_ASSERT(sec_obj.m_query_call_count == 0, "rejected query should not call secondary");
    TEST_ASSERT(global_obj.m_notify_count == 1, "rejected query must call global notify");
    TEST_ASSERT(global_obj.m_last_a1 == 0, "rejected query global notify arg1 mismatch");
    TEST_ASSERT(global_obj.m_last_a2 == 0, "rejected query global notify arg2 mismatch");
}

static void test_active_query_contract() {
    MockGlobal global_obj;
    D_004E2EA0 = (void *)1;
    D_004E3180 = &global_obj;

    MockSecondary sec_obj;
    sec_obj.m_ret_val = 0x142; // Masked with 0xFF -> 0x42

    ModeQueryTertiaryDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_subsystem = &sec_obj;

    s_func_1A5010_ret = 1;
    s_mock_out_x = 10;
    s_mock_out_y = 20;

    int res = func_00329130(&desc, 5, 8);
    TEST_ASSERT(sec_obj.m_query_call_count == 1, "active query secondary call count failed");
    TEST_ASSERT(res == 0x42, "active query return value masking failed");
    TEST_ASSERT(sec_obj.m_last_zero == 0, "active query secondary arg0 mismatch");
    TEST_ASSERT(sec_obj.m_last_fx == 10.5f, "active query secondary fx coordinate mismatch");
    TEST_ASSERT(sec_obj.m_last_fy == 20.5f, "active query secondary fy coordinate mismatch");
    TEST_ASSERT(global_obj.m_notify_count == 1, "active query global notify count failed");
    TEST_ASSERT(global_obj.m_last_a1 == 0, "active query global notify arg1 mismatch");
    TEST_ASSERT(global_obj.m_last_a2 == 0, "active query global notify arg2 mismatch");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "null_global") == 0) { test_null_global_guard(); return 0; }
        if (std::strcmp(argv[1], "rejected_query") == 0) { test_func_1A5010_rejection(); return 0; }
        if (std::strcmp(argv[1], "active_query") == 0) { test_active_query_contract(); return 0; }
    }
    test_null_global_guard();
    test_func_1A5010_rejection();
    test_active_query_contract();
    return 0;
}
