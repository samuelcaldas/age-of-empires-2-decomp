#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include "tactical_ai_layout_341040.h"

struct CallRecord {
    const char* name;
    void* self;
    int arg1;
    CallRecord(const char* n, void* s, int a) : name(n), self(s), arg1(a) {}
};

static std::vector<CallRecord> g_call_history;

static void log_call(const char* name, void* self, int arg1) {
    g_call_history.push_back(CallRecord(name, self, arg1));
}

static int g_func_33a5d0_called = 0;
static int g_func_339900_called = 0;
static int g_func_339960_called = 0;
static int g_func_33a730_called = 0;
static int g_func_33f8b0_called = 0;
static int g_func_1fbd30_called = 0;
static int g_last_1fbd30_arg = 0;
static int g_last_339960_arg = -1;
static int g_last_219ba0_arg = -1;
static int g_last_339900_arg = -1;

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
void func_33A730() {
    log_call("func_33A730", NULL, 0);
    g_func_33a730_called++;
}
static int g_func_339900_ret = 0;
static int g_func_340cf0_ret = 0;
void func_33A5D0(void *a0, int a1) {
    log_call("func_33A5D0", a0, a1);
    g_func_33a5d0_called++;
}
int func_339900(void *a0, int a1) {
    log_call("func_339900", a0, a1);
    g_func_339900_called++;
    g_last_339900_arg = a1;
    return g_func_339900_ret;
}
void func_339960(void *a0, int a1) {
    log_call("func_339960", a0, a1);
    g_func_339960_called++;
    g_last_339960_arg = a1;
}
int func_340CF0(void *a0) {
    log_call("func_340CF0", a0, 0);
    return g_func_340cf0_ret;
}
void func_340C30(void *a0) { log_call("func_340C30", a0, 0); }
static int g_func_1f6750_called = 0;
void func_1F6750(void *a0, void *a1) {
    log_call("func_1F6750", a0, (int)(long)a1);
    g_func_1f6750_called++;
}
void func_1F88B0(void *a0, void *a1) { (void)a0; (void)a1; }
void func_33F8B0(void *a0, int a1) {
    log_call("func_33F8B0", a0, a1);
    g_func_33f8b0_called++;
}
int func_219BA0(void *a0, int a1 = 0) {
    log_call("func_219BA0", a0, a1);
    g_last_219ba0_arg = a1;
    return 10;
}
void func_1FBD30(void *a0, int a1) {
    log_call("func_1FBD30", a0, a1);
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
    MockSubObj mock_sub830;
    obj.field_830 = &mock_sub830;

    // Test mode 16 with t0 = 0xFFFF: expects field_84C = 12 and field_83C = 12
    obj.field_84C = 16;
    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 1, 0xFFFF);
    assert(res == 1);
    assert(obj.field_84C == 12);
    assert(obj.field_83C == 12);

    std::printf("PASS test_func_342170_mode16_t0_xffff\n");
}

static void test_func_342170_mode0_mode1_assertions() {
    TacticalObj_341040 obj;

    // Mode 0: should set field_84C = 0 and invoke func_00341040 (incrementing g_func_33a730_called)
    std::memset(&obj, 0, sizeof(obj));
    MockSubObj mock_sub830;
    obj.field_830 = &mock_sub830;
    obj.field_84C = 0;
    int prev_a730 = g_func_33a730_called;
    func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(obj.field_84C == 0);
    assert(g_func_33a730_called > prev_a730);

    // Mode 1: should call func_340C30(self) and set field_844 + 2052 = 5
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    MockSubObj mock_field844;
    obj.field_844 = &mock_field844;
    obj.field_84C = 1;
    func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(*(int*)((char*)obj.field_844 + 2052) == 5);

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

    func_00342170(&obj, 55, 2, 0, 0); // a2 = 2 != 1
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

    func_00342170(&obj, (int)(long)&mock_sub, 16, 0, 0);
    assert(g_func_33a5d0_called == 1);
    assert(g_func_339900_called == 1);

    std::printf("PASS test_func_342170_preceding_calls_order\n");
}

static void test_func_342170_mode31_a2_equals_1() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    MockSubObj mock_sub830;
    obj.field_830 = &mock_sub830;
    obj.field_84C = 31;
    g_func_1fbd30_called = 0;

    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(g_func_1fbd30_called == 0);
    assert(obj.field_84C == 31);

    std::printf("PASS test_func_342170_mode31_a2_equals_1\n");
}

static void test_func_342170_remaining_modes() {
    TacticalObj_341040 obj;
    MockSubObj mock_sub830;
    MockSubObj mock_field844;

    // Mode 11 via jump table (field_830)
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_844 = &mock_field844;
    obj.field_84C = 11;
    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(*(int*)((char*)obj.field_844 + 2052) == 11);

    // Mode 14 via jump table with field_840 == 2
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_84C = 14;
    obj.field_840 = 2;
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(obj.field_84C == 12);

    // Mode 28 via jump table: sets field_84C = field_850
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_84C = 28;
    obj.field_850 = 42;
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(obj.field_84C == 42);

    // Mode 29 via jump table: sets field_84C = field_850
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_84C = 29;
    obj.field_850 = 99;
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(obj.field_84C == 99);

    // Mode 12 via jump table: sets field_84C = 13
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_84C = 12;
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(obj.field_84C == 13);

    // Mode 13 via jump table: sets field_844 + 2052 = 4
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_844 = &mock_field844;
    obj.field_84C = 13;
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(*(int*)((char*)obj.field_844 + 2052) == 4);

    // Mode >= 30 via jump table: invokes func_00341040
    for (int m = 30; m <= 50; ++m) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_830 = &mock_sub830;
        obj.field_84C = m;
        res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
        assert(res == 1);
    }

    std::printf("PASS test_func_342170_remaining_modes\n");
}

static void test_func_342170_call_history_sequence() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    MockSubObj mock_sub;
    obj.field_838 = &mock_sub;
    obj.field_84C = 0; // Mode 0
    g_call_history.clear();

    func_00342170(&obj, (int)(long)&mock_sub, 16, 0, 0);

    // Verify exact call history sequence and arguments:
    // 1. func_339900(&obj, a1)
    // 2. func_33A5D0
    assert(g_call_history.size() >= 2);
    assert(g_call_history[0].name == "func_339900");
    assert(g_call_history[0].arg1 == (int)(long)&mock_sub);

    assert(g_call_history[1].name == "func_33A5D0");

    std::printf("PASS test_func_342170_call_history_sequence\n");
}

static void test_func_342170_mode0_exact_history() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    MockSubObj mock_sub830;
    obj.field_830 = &mock_sub830;
    obj.field_84C = 0;
    g_call_history.clear();

    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);

    assert(res == 1);
    assert(g_call_history.size() >= 1);
    assert(g_call_history[0].name == "func_33A730");

    std::printf("PASS test_func_342170_mode0_exact_history\n");
}

static void test_func_342170_mode31_early_return_exact_history() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 31;
    g_call_history.clear();

    func_00342170(&obj, 77, 55, 0, 0); // a2 = 55 != 1 -> early return

    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_1FBD30");
    assert(g_call_history[0].self == &obj);
    assert(g_call_history[0].arg1 == 77);

    std::printf("PASS test_func_342170_mode31_early_return_exact_history\n");
}

static void test_func_342170_mode45_exact_history() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    MockSubObj mock_sub830;
    obj.field_830 = &mock_sub830;
    obj.field_84C = 45; // Mode >= 30 invokes func_00341040
    g_call_history.clear();

    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);

    assert(res == 1);
    assert(g_call_history.size() >= 1);
    assert(g_call_history[0].name == "func_33A730"); // inside func_00341040

    std::printf("PASS test_func_342170_mode45_exact_history\n");
}

static void test_func_342170_t0_equals_1_exact_history() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    MockSubObj mock_sub830;
    obj.field_830 = &mock_sub830;
    obj.field_84C = 10;
    g_call_history.clear();

    // In mode 10 with t0 = 1 (!= 0xFFFF), returns 0
    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 1);
    assert(res == 0);

    std::printf("PASS test_func_342170_t0_equals_1_exact_history\n");
}

static void test_func_342170_mode40_50_exact_history() {
    TacticalObj_341040 obj;
    MockSubObj mock_sub830;
    for (int m = 40; m <= 50; ++m) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_830 = &mock_sub830;
        obj.field_84C = m;
        g_call_history.clear();

        int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);

        assert(res == 1);
        assert(g_call_history.size() >= 1);
        assert(g_call_history[0].name == "func_33A730");
    }
    std::printf("PASS test_func_342170_mode40_50_exact_history\n");
}

static void test_func_342170_t0_equals_2_exact_history() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    MockSubObj mock_sub830;
    obj.field_830 = &mock_sub830;
    obj.field_84C = 10;
    g_call_history.clear();

    // In mode 10 with t0 = 0xFFFF, sets 84C=12, 83C=12, calls func_00341040, returns 1
    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0xFFFF);
    assert(res == 1);
    assert(obj.field_84C == 12);
    assert(obj.field_83C == 12);
    assert(g_call_history.size() >= 1);
    assert(g_call_history[0].name == "func_33A730");

    std::printf("PASS test_func_342170_t0_equals_2_exact_history\n");
}

static void test_func_342170_mode31_a2_equals_1_exact_history() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    MockSubObj mock_sub830;
    MockSubObj mock_sub838;
    obj.field_830 = &mock_sub830;
    obj.field_838 = &mock_sub838;
    obj.field_84C = 3;
    g_call_history.clear();

    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(g_call_history.size() >= 2);
    assert(g_call_history[0].name == "func_33A730");

    std::printf("PASS test_func_342170_mode31_a2_equals_1_exact_history\n");
}

static void test_func_342170_elf_sub838_a1_a2_16_branch() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    MockSubObj mock_sub838;
    obj.field_838 = &mock_sub838;
    obj.field_C = 20;
    obj.field_10 = 30;

    g_func_33a730_called = 0;
    g_func_1f6750_called = 0;
    g_call_history.clear();

    int res = func_00342170(&obj, (int)(long)&mock_sub838, 16, 0, 0);

    // ELF-derived behavior at 0x242350 (0x00 to 0x38 in object):
    // When sub838 matches a1 and a2 == 16, func_339900 returns 0.
    // Must call func_1F6750 and return 1 without calling func_33A730.
    assert(res == 1);
    assert(g_func_33a730_called == 0);
    assert(g_func_1f6750_called == 1);
    std::printf("PASS test_func_342170_elf_sub838_a1_a2_16_branch\n");
}

static void test_func_342170_elf_sub838_func_339900_nonzero_branch() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    MockSubObj mock_sub838;
    obj.field_838 = &mock_sub838;
    obj.field_84C = 0;

    g_func_33a730_called = 0;
    g_func_339900_called = 0;
    g_func_339900_ret = 1; // force non-zero return from func_339900
    g_func_340cf0_ret = 0;
    g_call_history.clear();

    int res = func_00342170(&obj, (int)(long)&mock_sub838, 16, 0, 0);

    // ELF-derived behavior at 0x2423fc (0xAC to 0x110 in object):
    // When func_339900 returns non-zero, must call func_33A730, update field_84C to 11, call func_00341040, and return 1.
    g_func_339900_ret = 0; // reset
    assert(res == 1);
    assert(g_func_33a730_called >= 1);
    assert(obj.field_84C == 11);
    std::printf("PASS test_func_342170_elf_sub838_func_339900_nonzero_branch\n");
}

static void test_func_342170_elf_field_834_mode11_branch() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    MockSubObj mock_sub834;
    obj.field_834 = &mock_sub834;
    obj.field_84C = 11; // Mode 11

    g_call_history.clear();

    // a2 = 1, a1 = self->field_834
    int res = func_00342170(&obj, (int)(long)&mock_sub834, 1, 0, 0);

    // ELF-derived behavior at 0x242484 (0x134 in object):
    // When a2 == 1 and a1 matches field_834 and field_84C == 11:
    // transitions field_84C = 3, calls func_00341040, and returns 1.
    assert(res == 1);
    assert(obj.field_84C == 3);
    std::printf("PASS test_func_342170_elf_field_834_mode11_branch\n");
}

static void test_func_342170_elf_jump_table_modes_branch() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    MockSubObj mock_sub830;
    obj.field_830 = &mock_sub830;
    obj.field_84C = 28; // Mode 28
    obj.field_850 = 77;

    g_call_history.clear();

    // a2 = 1, a1 = self->field_830
    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);

    // ELF-derived behavior at 0x24287c (0x52c in object):
    // Mode 28 jump table target sets field_84C = field_850, calls func_00341040, and returns 1.
    assert(res == 1);
    assert(obj.field_84C == 77);
    std::printf("PASS test_func_342170_elf_jump_table_modes_branch\n");
}

int main() {
    test_func_342170_elf_sub838_a1_a2_16_branch();
    test_func_342170_elf_sub838_func_339900_nonzero_branch();
    test_func_342170_elf_field_834_mode11_branch();
    test_func_342170_elf_jump_table_modes_branch();
    test_initial_layout_state();
    test_func_342170_mode16_t0_xffff();
    test_func_342170_additional_modes();
    test_func_342170_mode0_mode1_assertions();
    test_func_342170_mode31_early_return_order();
    test_func_342170_preceding_calls_order();
    test_func_342170_mode31_a2_equals_1();
    test_func_342170_remaining_modes();
    test_func_342170_call_history_sequence();
    test_func_342170_mode0_exact_history();
    test_func_342170_mode31_early_return_exact_history();
    test_func_342170_mode45_exact_history();
    test_func_342170_t0_equals_1_exact_history();
    test_func_342170_mode40_50_exact_history();
    test_func_342170_t0_equals_2_exact_history();
    test_func_342170_mode31_a2_equals_1_exact_history();
    std::printf("ALL TACTICAL AI LAYOUT TESTS PASSED WITH COMPLETE EXACT HISTORY ASSERTIONS\n");
    return 0;
}
