#include <cassert>
#include <cstdio>
#include <cstring>
#include "tactical_ai_layout_341040.h"

static int g_func_33a5d0_called = 0;
static int g_func_339960_called = 0;
static int g_func_339900_called = 0;
static int g_func_340cf0_called = 0;
static int g_func_340c30_called = 0;
static int g_func_1f6750_called = 0;
static int g_func_1f88b0_called = 0;
static int g_call_seq[20];
static int g_seq_idx = 0;

class MockSubObj : public TacticalSubObj {
public:
    void vfunc_00() {}
    char pad[2060];
};

extern "C" {
void func_33A730() {}
void func_33A5D0(void *a0, int a1) {
    (void)a0;
    (void)a1;
    g_func_33a5d0_called++;
    g_call_seq[g_seq_idx++] = 1; // func_33A5D0
}
void func_339900(void *a0, int a1) {
    (void)a0;
    (void)a1;
    g_func_339900_called++;
    g_call_seq[g_seq_idx++] = 2; // func_339900
}
void func_339960(void *a0, int a1) {
    (void)a0;
    (void)a1;
    g_func_339960_called++;
    g_call_seq[g_seq_idx++] = 3; // func_339960
}
void func_340CF0(void *a0) {
    (void)a0;
    g_func_340cf0_called++;
    g_call_seq[g_seq_idx++] = 6; // func_340CF0
}
void func_340C30(void *a0) {
    (void)a0;
    g_func_340c30_called++;
    g_call_seq[g_seq_idx++] = 7; // func_340C30
}
void func_1F6750(void *a0, void *a1) {
    (void)a0;
    (void)a1;
    g_func_1f6750_called++;
    g_call_seq[g_seq_idx++] = 4; // func_1F6750 (must be before func_1F88B0)
}
void func_1F88B0(void *a0, void *a1) {
    (void)a0;
    (void)a1;
    g_func_1f88b0_called++;
    g_call_seq[g_seq_idx++] = 5; // func_1F88B0 (must be after func_1F6750)
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

static void test_func_342170_branches_and_strict_call_order() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));

    MockSubObj sub;
    obj.field_838 = &sub;

    // Test mode 30 branch and argument passing (a1=100, a2=200, a3=300)
    g_seq_idx = 0;
    g_func_33a5d0_called = 0;
    g_func_339960_called = 0;
    g_func_1f6750_called = 0;
    g_func_1f88b0_called = 0;

    obj.field_84C = 30;
    func_00342170(&obj, 100, 200, 300);

    assert(g_func_33a5d0_called == 1);
    assert(g_func_339960_called == 1);
    assert(obj.field_83C == 1);
    assert(obj.field_84C == 30);
    assert(*(int*)((char*)&sub + 2052) == 30); // Write at 0x3423AC

    // Verify strict call order:
    // [1: func_33A5D0, 3: func_339960, 4: func_1F6750, 5: func_1F88B0]
    assert(g_seq_idx == 4);
    assert(g_call_seq[0] == 1);
    assert(g_call_seq[1] == 3);
    assert(g_call_seq[2] == 4); // 1F6750 must precede 1F88B0
    assert(g_call_seq[3] == 5); // 1F88B0 must follow 1F6750

    // Test mode 31 transition
    g_seq_idx = 0;
    obj.field_84C = 31;
    func_00342170(&obj, 100, 200, 300);
    assert(obj.field_83C == 1);

    // Test mode 35 transition
    g_seq_idx = 0;
    obj.field_84C = 35;
    func_00342170(&obj, 100, 200, 300);
    assert(obj.field_83C == 2);

    std::printf("PASS test_func_342170_branches_and_strict_call_order\n");
}

int main() {
    test_initial_layout_state();
    test_func_342170_branches_and_strict_call_order();
    std::printf("ALL TACTICAL AI LAYOUT TESTS PASSED WITH STRICT CALL ORDER\n");
    return 0;
}
