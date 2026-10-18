#include <cassert>
#include <cstdio>
#include <cstring>
#include "tactical_ai_layout_341040.h"

static int g_func_33a5d0_called = 0;
static int g_func_339960_called = 0;
static int g_func_339900_called = 0;
static int g_func_1f6750_called = 0;
static int g_func_1f88b0_called = 0;
static int g_call_seq[10];
static int g_seq_idx = 0;

class MockSubObj : public TacticalSubObj {
public:
    void vfunc_00() {}
};

extern "C" {
void func_33A730() {}
void func_33A5D0(void *a0, int a1) {
    (void)a0;
    (void)a1;
    g_func_33a5d0_called++;
    g_call_seq[g_seq_idx++] = 1;
}
void func_339900(void *a0, int a1) {
    (void)a0;
    (void)a1;
    g_func_339900_called++;
    g_call_seq[g_seq_idx++] = 2;
}
void func_339960(void *a0, int a1) {
    (void)a0;
    (void)a1;
    g_func_339960_called++;
    g_call_seq[g_seq_idx++] = 3;
}
void func_1F6750(void *a0, void *a1) {
    (void)a0;
    (void)a1;
    g_func_1f6750_called++;
    g_call_seq[g_seq_idx++] = 4;
}
void func_1F88B0(void *a0, void *a1) {
    (void)a0;
    (void)a1;
    g_func_1f88b0_called++;
    g_call_seq[g_seq_idx++] = 5;
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

static void test_func_342170_branches_and_call_order() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));

    MockSubObj sub;
    obj.field_838 = &sub;

    g_seq_idx = 0;
    g_func_33a5d0_called = 0;
    g_func_339960_called = 0;
    g_func_1f6750_called = 0;
    g_func_1f88b0_called = 0;

    obj.field_84C = 30;
    func_00342170(&obj);

    assert(g_func_33a5d0_called == 1);
    assert(g_func_339960_called == 1);
    assert(g_func_1f6750_called == 1);
    assert(g_func_1f88b0_called == 1);
    assert(obj.field_83C == 1);

    // Verify exact call order: [func_33A5D0(1), func_339960(3), func_1F6750(4), func_1F88B0(5)]
    assert(g_seq_idx == 4);
    assert(g_call_seq[0] == 1);
    assert(g_call_seq[1] == 3);
    assert(g_call_seq[2] == 4);
    assert(g_call_seq[3] == 5);

    std::printf("PASS test_func_342170_branches_and_call_order\n");
}

int main() {
    test_initial_layout_state();
    test_func_342170_branches_and_call_order();
    std::printf("ALL TACTICAL AI LAYOUT TESTS PASSED WITH STRICT ASSERTIONS\n");
    return 0;
}
