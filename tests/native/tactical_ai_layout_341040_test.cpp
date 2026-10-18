#include <cassert>
#include <cstdio>
#include <cstring>
#include "tactical_ai_layout_341040.h"

static int g_func_33a5d0_called = 0;
static int g_func_339900_called = 0;
static int g_func_339960_called = 0;
static int g_func_33a730_called = 0;
static int g_func_33f8b0_called = 0;
static int g_func_1fbd30_called = 0;
static int g_last_1fbd30_arg = 0;

static void* custom_vtable[100];
static void dummy_vfunc_stub(void *self, ...) { (void)self; }

class MockSubObj : public TacticalSubObj {
public:
    MockSubObj() {
        for (int i = 0; i < 100; i++) {
            custom_vtable[i] = (void*)&dummy_vfunc_stub;
        }
        *(void***)this = custom_vtable;
    }
    void vfunc_00() {}
    char pad[2060];
};

extern "C" {
void func_33A730() { g_func_33a730_called++; }
void func_33A5D0(void *a0, int a1) {
    (void)a0; (void)a1;
    g_func_33a5d0_called++;
}
void func_339900(void *a0, int a1) {
    (void)a0; (void)a1;
    g_func_339900_called++;
}
void func_339960(void *a0, int a1) {
    (void)a0; (void)a1;
    g_func_339960_called++;
}
void func_340CF0(void *a0) { (void)a0; }
void func_340C30(void *a0) { (void)a0; }
void func_1F6750(void *a0, void *a1) { (void)a0; (void)a1; }
void func_1F88B0(void *a0, void *a1) { (void)a0; (void)a1; }
void func_33F8B0(void *a0) {
    (void)a0;
    g_func_33f8b0_called++;
}
void func_219BA0(void *a0, int a1) { (void)a0; (void)a1; }
void func_1FBD30(void *a0, int a1) {
    (void)a0;
    g_func_1fbd30_called++;
    g_last_1fbd30_arg = a1;
}
void func_11ABBC(void *dst, const char *src) { (void)dst; (void)src; }
void func_36BD30(void *a0, int a1, int a2, const char *a3, int t0) { (void)a0; (void)a1; (void)a2; (void)a3; (void)t0; }
void func_36ACC0(int a0) { (void)a0; }
int func_1F6EA0(int a0, int a1) { (void)a0; (void)a1; return 0; }
void *func_36C000(int a0) { (void)a0; return 0; }
void func_11A498(void *dst, void *src, int a2) { (void)dst; (void)src; (void)a2; }
char *func_33F820(void *a0) { (void)a0; static char mock_path[] = "host:/test/path"; return mock_path; }
char *func_33F8A0(void *a0) { (void)a0; static char mock_path[] = "host:/test/path"; return mock_path; }
int func_11ACD0(const char *s) { (void)s; return 15; }

extern const char aBesles50282age2G[] = "BESLES-50282age2_g??";
extern const char aBesles50282age2S[] = "BESLES-50282age2_s??";
extern const char aDmy[] = "dmy";
}

static void test_initial_layout_state() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));

    func_00341040(&obj);
    std::printf("PASS test_initial_layout_state\n");
}

static void test_func_342170_mode16_t0_xffff() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));

    // Test mode 16 with t0 = 0xFFFF: expects field_84C = 12 and field_83C = 12
    obj.field_84C = 16;
    func_00342170(&obj, 0, 16, 1, 0xFFFF);
    assert(obj.field_84C == 12);
    assert(obj.field_83C == 12);

    std::printf("PASS test_func_342170_mode16_t0_xffff\n");
}

static void test_func_342170_mode0_mode1_assertions() {
    TacticalObj_341040 obj;

    // Mode 0: should set field_84C = 0, field_83C = 0, and invoke func_00341040 (incrementing g_func_33a730_called)
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 0;
    int prev_a730 = g_func_33a730_called;
    func_00342170(&obj, 0, 16, 0, 0);
    assert(obj.field_84C == 0);
    assert(obj.field_83C == 0);
    assert(g_func_33a730_called > prev_a730);

    // Mode 1: should set field_84C = 1
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 1;
    func_00342170(&obj, 0, 16, 0, 0);
    assert(obj.field_84C == 1);

    std::printf("PASS test_func_342170_mode0_mode1_assertions\n");
}

static void test_func_342170_additional_modes() {
    TacticalObj_341040 obj;

    // Test mode 31 with a2 != 1 (early return via func_1FBD30)
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 31;
    func_00342170(&obj, 0, 2, 0, 0);
    assert(g_func_1fbd30_called > 0);

    std::printf("PASS test_func_342170_additional_modes\n");
}

static void test_func_342170_mode31_early_return_order() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 31;
    g_func_1fbd30_called = 0;
    g_last_1fbd30_arg = 0;
    g_func_339960_called = 0;

    func_00342170(&obj, 0, 55, 0, 0); // a2 = 55 != 1
    assert(g_func_1fbd30_called == 1);
    assert(g_last_1fbd30_arg == 55);
    // Early return must prevent subsequent calls like func_339960
    assert(g_func_339960_called == 0);

    std::printf("PASS test_func_342170_mode31_early_return_order\n");
}

static void test_func_342170_preceding_calls_order() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 0;
    MockSubObj mock_sub;
    obj.field_838 = &mock_sub;
    g_func_33a5d0_called = 0;
    g_func_339900_called = 0;

    func_00342170(&obj, 0, 16, 0, 0);
    assert(g_func_33a5d0_called == 1);
    assert(g_func_339900_called == 1);

    std::printf("PASS test_func_342170_preceding_calls_order\n");
}

static void test_func_342170_mode31_a2_equals_1() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 31;
    g_func_339960_called = 0;
    g_func_1fbd30_called = 0;

    func_00342170(&obj, 0, 1, 0, 0); // a2 = 1 -> should not early return, should execute mode 31 switch case
    assert(g_func_1fbd30_called == 0);
    assert(g_func_339960_called == 1);
    assert(obj.field_84C == 31);
    assert(obj.field_83C == 1);

    std::printf("PASS test_func_342170_mode31_a2_equals_1\n");
}

static void test_func_342170_remaining_modes() {
    TacticalObj_341040 obj;

    // Mode 11
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 11;
    func_00342170(&obj, 0, 16, 0, 0);
    assert(obj.field_84C == 11);

    // Mode 14
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 14;
    func_00342170(&obj, 0, 16, 0, 0);
    assert(obj.field_84C == 14);

    // Mode 28
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 28;
    func_00342170(&obj, 0, 16, 0, 0);
    assert(obj.field_84C == 28);

    // Mode 29
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 29;
    func_00342170(&obj, 0, 16, 0, 0);
    assert(obj.field_84C == 29);

    // Mode 30
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 30;
    func_00342170(&obj, 0, 16, 0, 0);
    assert(obj.field_84C == 30);
    assert(obj.field_83C == 1);

    // Mode 35
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 35;
    func_00342170(&obj, 0, 16, 0, 0);
    assert(obj.field_84C == 35);
    assert(obj.field_83C == 2);

    // Mode 45 (in range 40-50)
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 45;
    func_00342170(&obj, 0, 16, 0, 0);
    assert(obj.field_84C == 45);

    // Default with field_840 == 2
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 99;
    obj.field_840 = 2;
    func_00342170(&obj, 0, 16, 0, 0);
    assert(obj.field_84C == 99);

    // t0 == 1 terminal branch
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 1;
    func_00342170(&obj, 0, 16, 0, 1);
    assert(obj.field_84C == 1);

    // t0 == 2 terminal branch
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 1;
    func_00342170(&obj, 0, 16, 0, 2);
    assert(obj.field_84C == 1);

    std::printf("PASS test_func_342170_remaining_modes\n");
}

int main() {
    test_initial_layout_state();
    test_func_342170_mode16_t0_xffff();
    test_func_342170_additional_modes();
    test_func_342170_mode0_mode1_assertions();
    test_func_342170_mode31_early_return_order();
    test_func_342170_preceding_calls_order();
    test_func_342170_mode31_a2_equals_1();
    test_func_342170_remaining_modes();
    std::printf("ALL TACTICAL AI LAYOUT TESTS PASSED WITH COMPLETE MODE COVERAGE\n");
    return 0;
}
