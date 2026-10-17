#include <cassert>
#include <cstdio>
#include <cstring>
#include <new>
#include "tactical_ai_handler_340c30.h"

static int g_func_2261c0_time = 0;
static int g_func_33a730_calls = 0;
static void *g_func_20bf20_arg = nullptr;
static void *g_func_1f2900_a0 = nullptr;
static const char *g_func_1f2900_a1 = nullptr;
static int g_func_1f2900_a2 = -1;
static void *g_vfunc_1c_arg0 = nullptr;
static int g_vfunc_1c_arg1 = -1;
static void *g_func_340360_arg = nullptr;

char D_00A80BB0[64] = {0};
extern "C" const char aMemorycardScreen[] = "Memorycard Screen";

extern "C" {
int func_2261c0() {
    return g_func_2261c0_time;
}

void func_33A730() {
    g_func_33a730_calls++;
}

void func_20BF20(void *ptr) {
    g_func_20bf20_arg = ptr;
}

void func_1F2900(void *a0, const char *a1, int a2) {
    g_func_1f2900_a0 = a0;
    g_func_1f2900_a1 = a1;
    g_func_1f2900_a2 = a2;
}

void func_340360(void *ptr) {
    g_func_340360_arg = ptr;
}
}

class TestTacticalObj : public TacticalObj_340C30 {
public:
    void vfunc_00() override {}
    void vfunc_04() override {}
    void vfunc_08() override {}
    void vfunc_0c() override {}
    void vfunc_10() override {}
    void vfunc_1c(int a) override {
        g_vfunc_1c_arg0 = this;
        g_vfunc_1c_arg1 = a;
    }
};

static void test_field84_equals_one_recent_time_sets_field858() {
    TestTacticalObj obj;
    std::memset(&obj, 0, sizeof(obj));
    new (&obj) TestTacticalObj();
    obj.field_84 = 1;
    obj.field_854 = 1000;
    obj.field_858 = 0;

    g_func_2261c0_time = 1500; // 1500 - 1000 = 500 (< 1000)

    func_00340C30(&obj);

    assert(obj.field_858 == 1);
    std::printf("PASS test_field84_equals_one_recent_time_sets_field858\n");
}

static void test_field84_not_one_triggers_full_reset() {
    TestTacticalObj obj;
    std::memset(&obj, 0, sizeof(obj));
    new (&obj) TestTacticalObj();
    obj.field_84 = 0;
    obj.field_83C = 5;
    obj.field_840 = 6;
    obj.field_84C = 7;
    obj.field_854 = 123;
    obj.field_858 = 99;
    obj.field_844 = (void*)0x1234;

    g_func_33a730_calls = 0;
    g_func_20bf20_arg = nullptr;
    g_func_1f2900_a0 = nullptr;
    g_func_1f2900_a1 = nullptr;
    g_func_1f2900_a2 = -1;
    g_vfunc_1c_arg0 = nullptr;
    g_vfunc_1c_arg1 = -1;
    g_func_340360_arg = nullptr;

    func_00340C30(&obj);

    assert(obj.field_83C == -1);
    assert(obj.field_840 == -1);
    assert(obj.field_84C == -1);
    assert(obj.field_854 == 0);
    assert(obj.field_858 == 0);
    assert(g_func_33a730_calls == 1);
    assert(g_func_20bf20_arg == &obj);
    assert(g_func_1f2900_a2 == 0);
    assert(g_vfunc_1c_arg0 == &obj);
    assert(g_vfunc_1c_arg1 == 0);
    assert(g_func_340360_arg == (void*)0x1234);
    std::printf("PASS test_field84_not_one_triggers_full_reset\n");
}

int main() {
    test_field84_equals_one_recent_time_sets_field858();
    test_field84_not_one_triggers_full_reset();
    return 0;
}
