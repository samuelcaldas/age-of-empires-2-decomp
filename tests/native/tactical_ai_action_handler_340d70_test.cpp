#include <cassert>
#include <cstdio>
#include <cstring>
#include <new>
#include "tactical_ai_action_handler_340d70.h"

static int g_vfunc_1c_called = 0;
static int g_vfunc_1c_arg = -1;
static int g_vfunc_d0_called = 0;
static int g_func_21a1c0_called = 0;
static int g_func_341040_called = 0;

extern "C" {
int func_21A1C0(TacticalObj_340D70 *self) {
    (void)self;
    g_func_21a1c0_called++;
    return 0;
}

void func_341040(TacticalObj_340D70 *self) {
    (void)self;
    g_func_341040_called++;
}

int func_2261c0() {
    return 12345;
}
}

class TestTacticalObj_340D70 : public TacticalObj_340D70 {
public:
    void vfunc_00() override {}
    void vfunc_04() override {}
    void vfunc_08() override {}
    void vfunc_0c() override {}
    void vfunc_10() override {}
    void vfunc_1c(int a) override {
        g_vfunc_1c_called++;
        g_vfunc_1c_arg = a;
    }
    void vf_01() override {} void vf_02() override {} void vf_03() override {} void vf_04b() override {}
    void vf_05() override {} void vf_06() override {} void vf_07() override {} void vf_08b() override {}
    void vf_09() override {} void vf_10b() override {} void vf_11() override {} void vf_12() override {}
    void vf_13() override {} void vf_14b() override {} void vf_15() override {} void vf_16() override {}
    void vf_17() override {} void vf_18b() override {} void vf_19() override {} void vf_20b() override {}
    void vf_21() override {} void vf_22() override {} void vf_23() override {} void vf_24b() override {}
    void vf_25() override {} void vf_26() override {} void vf_27() override {} void vf_28b() override {}
    void vf_29() override {} void vf_30b() override {} void vf_31() override {} void vf_32() override {}
    void vf_33() override {} void vf_34b() override {} void vf_35() override {} void vf_36() override {}
    void vf_37() override {} void vf_38b() override {} void vf_39() override {} void vf_40b() override {}
    void vf_41() override {} void vf_42() override {} void vf_43() override {} void vf_44b() override {}
    void vfunc_d0(void *a1, int a2, int a3, int t0) override {
        (void)a1; (void)a2; (void)a3; (void)t0;
        g_vfunc_d0_called++;
    }
};

static void test_field840_minus_one_returns_zero() {
    TestTacticalObj_340D70 obj;
    std::memset(&obj, 0, sizeof(obj));
    new (&obj) TestTacticalObj_340D70();
    obj.field_840 = -1;

    int res = func_00340D70(&obj, 0, 0);
    assert(res == 0);
    std::printf("PASS test_field840_minus_one_returns_zero\n");
}

static void test_cmd_255_calls_vfunc1c_and_returns_zero() {
    TestTacticalObj_340D70 obj;
    std::memset(&obj, 0, sizeof(obj));
    new (&obj) TestTacticalObj_340D70();
    obj.field_840 = 0;

    g_vfunc_1c_called = 0;
    g_vfunc_1c_arg = -1;

    int res = func_00340D70(&obj, 255, 0);
    assert(res == 0);
    assert(g_vfunc_1c_called == 1);
    assert(g_vfunc_1c_arg == 1);
    std::printf("PASS test_cmd_255_calls_vfunc1c_and_returns_zero\n");
}

static void test_cmd_11_sets_fields() {
    TestTacticalObj_340D70 obj;
    std::memset(&obj, 0, sizeof(obj));
    new (&obj) TestTacticalObj_340D70();
    obj.field_840 = 0;
    obj.field_84C = 0;
    obj.field_83C = 0;

    int res = func_00340D70(&obj, 11, 0);
    assert(res == 0);
    assert(obj.field_84C == 12);
    assert(obj.field_83C == 12);
    std::printf("PASS test_cmd_11_sets_fields\n");
}

int main() {
    test_field840_minus_one_returns_zero();
    test_cmd_255_calls_vfunc1c_and_returns_zero();
    test_cmd_11_sets_fields();
    return 0;
}
