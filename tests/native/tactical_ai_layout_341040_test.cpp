#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include "tactical_ai_layout_341040.h"

static int g_last_arg = -1;
static int g_call_count = 0;

class MockSubObj : public TacticalSubObj {
public:
    void vfunc_00() override {}
};

extern "C" {
void func_33A730() {}
void func_11ABBC(void *dst, const char *src) { (void)dst; (void)src; }
void func_36BD30(void *a0, int a1, int a2, const char *a3, int t0) { (void)a0; (void)a1; (void)a2; (void)a3; (void)t0; }
void func_36ACC0(int a0) { (void)a0; }
int func_1F6EA0(int a0, int a1) { (void)a0; (void)a1; return 0; }
void *func_36C000(int a0) { (void)a0; return nullptr; }
void func_11A498(void *dst, void *src, int a2) { (void)dst; (void)src; (void)a2; }
char *func_33F820(void *a0) { (void)a0; static char mock_path[] = "host:/test/path"; return mock_path; }
char *func_33F8A0(void *a0) { (void)a0; static char mock_path[] = "host:/test/path"; return mock_path; }
int func_11ACD0(const char *s) { (void)s; return 15; }

extern const char aBesles50282age2G[] = "BESLES-50282age2_g??";
extern const char aBesles50282age2S[] = "BESLES-50282age2_s??";
extern const char aDmy[] = "dmy";
}

// Mock vtable for TacticalSubObj where index 65 records call
static void *mock_vtable[70];

static void init_mock_vtable() {
    static bool initialized = false;
    if (initialized) return;
    for (int i = 0; i < 70; i++) {
        mock_vtable[i] = (void*)+[](TacticalSubObj *self, int arg) {
            g_call_count++;
            g_last_arg = arg;
        };
    }
    initialized = true;
}

static void test_initial_layout_state() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));

    func_00341040(&obj);
    std::printf("PASS test_initial_layout_state\n");
}

static void test_func_342170_call_order_and_args() {
    init_mock_vtable();
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));

    MockSubObj sub;
    *(void***)&sub = mock_vtable;
    obj.field_828 = &sub;

    g_call_count = 0;
    g_last_arg = -1;

    obj.field_84C = 30;
    func_00342170(&obj);
    assert(g_call_count == 1);
    assert(g_last_arg == 0xc3d5);

    obj.field_84C = 35;
    func_00342170(&obj);
    assert(g_call_count == 2);
    assert(g_last_arg == 0xc3da);

    std::printf("PASS test_func_342170_call_order_and_args\n");
}

int main() {
    test_initial_layout_state();
    test_func_342170_call_order_and_args();
    std::printf("ALL TACTICAL AI LAYOUT TESTS PASSED\n");
    return 0;
}
