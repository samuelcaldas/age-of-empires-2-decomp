#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <vector>
#include <string>
#include "tactical_ai_layout_341040.h"

struct CallRecord {
    const char* name;
    void* self;
    int arg1;
    int arg_count;
    int args[7];

    CallRecord(const char* n, void* s) : name(n), self(s), arg1(0), arg_count(0) {
        for (int i = 0; i < 7; ++i) args[i] = 0;
    }
    CallRecord(const char* n, void* s, int a) : name(n), self(s), arg1(a), arg_count(1) {
        args[0] = a;
        for (int i = 1; i < 7; ++i) args[i] = 0;
    }
    CallRecord(const char* n, void* s, int a1, int a2) : name(n), self(s), arg1(a1), arg_count(2) {
        args[0] = a1; args[1] = a2;
        for (int i = 2; i < 7; ++i) args[i] = 0;
    }
    CallRecord(const char* n, void* s, int a1, int a2, int a3, int a4, int a5, int a6)
        : name(n), self(s), arg1(a1), arg_count(6) {
        args[0] = a1; args[1] = a2; args[2] = a3; args[3] = a4; args[4] = a5; args[5] = a6;
        args[6] = 0;
    }
    CallRecord(const char* n, void* s, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
        : name(n), self(s), arg1(a1), arg_count(7) {
        args[0] = a1; args[1] = a2; args[2] = a3; args[3] = a4; args[4] = a5; args[5] = a6; args[6] = a7;
    }
};

static std::vector<CallRecord> g_call_history;

static void log_call(const char* name, void* self) {
    g_call_history.push_back(CallRecord(name, self));
}
static void log_call(const char* name, void* self, int arg1) {
    g_call_history.push_back(CallRecord(name, self, arg1));
}
static void log_call(const char* name, void* self, int a1, int a2) {
    g_call_history.push_back(CallRecord(name, self, a1, a2));
}
static void log_call(const char* name, void* self, int a1, int a2, int a3, int a4, int a5, int a6) {
    g_call_history.push_back(CallRecord(name, self, a1, a2, a3, a4, a5, a6));
}
static void log_call(const char* name, void* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
    g_call_history.push_back(CallRecord(name, self, a1, a2, a3, a4, a5, a6, a7));
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
void func_33A5D0(int a0, int a1, int a2, int a3, int a4, int a5) {
    g_func_33a5d0_called++;
    log_call("func_33A5D0", NULL, a0, a1, a2, a3, a4, a5);
}
int func_339900(TacticalObj_341040 *self, int a1) {
    log_call("func_339900", self, a1);
    g_func_339900_called++;
    g_last_339900_arg = a1;
    return g_func_339900_ret;
}
void func_339960(int a0, int a1, int a2, int a3, int a4, int a5, int a6) {
    g_func_339960_called++;
    g_last_339960_arg = a1;
    log_call("func_339960", NULL, a0, a1, a2, a3, a4, a5, a6);
}
int func_00340CF0(void *a0) {
    log_call("func_00340CF0", a0, 0);
    return g_func_340cf0_ret;
}
int func_340CF0(void *a0) { return func_00340CF0(a0); }

static int g_f844_val_during_func_340c30 = -1;

void func_00340C30(void *a0) {
    log_call("func_00340C30", a0, 0);
    g_f844_val_during_func_340c30 = -1;
    if (a0) {
        TacticalObj_341040 *obj = (TacticalObj_341040*)a0;
        if (obj->field_844) {
            g_f844_val_during_func_340c30 = *(int*)((char*)obj->field_844 + 2052);
        }
    }
}
void func_340C30(void *a0) { func_00340C30(a0); }

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
int func_00219BA0(void *a0, int a1 = 0) {
    log_call("func_00219BA0", a0, a1);
    g_last_219ba0_arg = a1;
    return 10;
}
int func_219BA0(void *a0, int a1 = 0) { return func_00219BA0(a0, a1); }
void func_1FBD30(void *a0, int a1) {
    log_call("func_1FBD30", a0, a1);
    g_func_1fbd30_called++;
    g_last_1fbd30_arg = a1;
}
static int g_field_84c_during_func_36acc0 = -1;
static TacticalObj_341040 *g_active_test_obj = NULL;

void func_36ACC0(int a0) {
    log_call("func_36ACC0", NULL, a0);
    if (g_active_test_obj) {
        g_field_84c_during_func_36acc0 = g_active_test_obj->field_84C;
    }
}
static const char* g_last_11abbc_src = NULL;
void func_11ABBC(void *dst, const char *src) {
    (void)dst;
    g_last_11abbc_src = src;
}
void func_36BD30(void *a0, int a1, int a2, const char *a3, int t0) { (void)a0; (void)a1; (void)a2; (void)a3; (void)t0; }
int func_1F6EA0(int a0, int a1) {
    log_call("func_1F6EA0", (void*)(long)a0, a1);
    return 0;
}
void *func_36C000(int a0) { (void)a0; return 0; }
void func_11A498(void *dst, void *src, int a2) { (void)dst; (void)src; (void)a2; }
char *func_33F820(void *a0) { (void)a0; static char mock_path[] = "host:/test/path"; return mock_path; }
char *func_33F8A0(void *a0) { (void)a0; static char mock_path[] = "host:/test/path"; return mock_path; }
int func_11ACD0(const char *s) { (void)s; return 15; }

extern const char aBesles50282age2G[] = "BESLES-50282age2_g??";
extern const char aBesles50282age2S[] = "BESLES-50282age2_s??";
extern const char aDmy[] = "dmy";
extern const char D_4D5508[] = "";
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
    g_call_history.clear();
    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 1, 0xFFFF);
    assert(res == 1);
    assert(obj.field_84C == 12);
    assert(obj.field_83C == 12);
    assert(g_call_history.size() == 2);
    assert(g_call_history[0].name == "func_33A730");
    assert(g_call_history[1].name == "func_36ACC0");
    assert(g_call_history[1].arg1 == 2);

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

static void test_func_342170_field_834_all_modes() {
    TacticalObj_341040 obj;
    MockSubObj mock_sub834;
    MockSubObj mock_field844;

    // Mode 11: field_84C transitions to 3, calls func_00341040 -> func_33A730
    std::memset(&obj, 0, sizeof(obj));
    obj.field_834 = &mock_sub834;
    obj.field_84C = 11;
    g_call_history.clear();
    int res = func_00342170(&obj, (int)(long)&mock_sub834, 1, 0, 0);
    assert(res == 1);
    assert(obj.field_84C == 3);
    assert(g_call_history.size() == 2);
    assert(g_call_history[0].name == "func_33A730");
    assert(g_call_history[1].name == "func_1F6EA0");
    assert(g_call_history[1].args[0] == 0xc3c7);

    // Mode 3: calls func_33A730, calls func_00340C30, writes *(field_844+2052) = 2
    std::memset(&obj, 0, sizeof(obj));
    obj.field_834 = &mock_sub834;
    obj.field_844 = &mock_field844;
    obj.field_84C = 3;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub834, 1, 0, 0);
    assert(res == 1);
    assert(g_call_history.size() == 2);
    assert(g_call_history[0].name == "func_33A730");
    assert(g_call_history[1].name == "func_00340C30");
    assert(g_call_history[1].self == &obj);
    assert(*(int*)((char*)obj.field_844 + 2052) == 2);

    // Modes 1, 2, 4, 7: calls func_00340C30, writes *(field_844+2052) = 2
    int modes_1_2_4_7[] = {1, 2, 4, 7};
    for (int i = 0; i < 4; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_834 = &mock_sub834;
        obj.field_844 = &mock_field844;
        obj.field_84C = modes_1_2_4_7[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub834, 1, 0, 0);
        assert(res == 1);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_00340C30");
        assert(g_call_history[0].self == &obj);
        assert(*(int*)((char*)obj.field_844 + 2052) == 2);
    }

    // Modes 18, 21, 22, 23, 24: field_84C transitions to 12, calls func_00341040
    int modes_18_24[] = {18, 21, 22, 23, 24};
    for (int i = 0; i < 5; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_834 = &mock_sub834;
        obj.field_84C = modes_18_24[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub834, 1, 0, 0);
        assert(res == 1);
        assert(obj.field_84C == 12);
        assert(g_call_history.size() == 2);
        assert(g_call_history[0].name == "func_33A730");
        assert(g_call_history[1].name == "func_36ACC0");
        assert(g_call_history[1].arg1 == 2);
    }

    // Mode 20 with field_840 boundary tests: in-bounds {2, 4, 5, 6} -> 18; out-of-bounds {1, 3, 7} -> 17
    int f840_in_20[] = {2, 4, 5, 6};
    for (int i = 0; i < 4; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_834 = &mock_sub834;
        obj.field_84C = 20;
        obj.field_840 = f840_in_20[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub834, 1, 0, 0);
        assert(res == 1);
        assert(obj.field_84C == 18);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_33A730");
    }
    int f840_out_20[] = {1, 3, 7};
    for (int i = 0; i < 3; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_834 = &mock_sub834;
        obj.field_84C = 20;
        obj.field_840 = f840_out_20[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub834, 1, 0, 0);
        assert(res == 1);
        assert(obj.field_84C == 17);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_33A730");
    }

    // Mode 15 with field_840 boundary tests: in-bounds {2, 4} -> 18; out-of-bounds {1, 3, 5, 6, 7} -> writes 12
    int f840_in_15[] = {2, 4};
    for (int i = 0; i < 2; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_834 = &mock_sub834;
        obj.field_84C = 15;
        obj.field_840 = f840_in_15[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub834, 1, 0, 0);
        assert(res == 1);
        assert(obj.field_84C == 18);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_33A730");
    }
    int f840_out_15[] = {1, 3, 5, 6, 7};
    for (int i = 0; i < 5; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_834 = &mock_sub834;
        obj.field_844 = &mock_field844;
        obj.field_84C = 15;
        obj.field_840 = f840_out_15[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub834, 1, 0, 0);
        assert(res == 1);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_00340C30");
        assert(*(int*)((char*)obj.field_844 + 2052) == 12);
    }

    // Mode 14 with field_840 boundary tests: in-bounds {2, 4, 5, 6} -> 18; out-of-bounds {1, 3, 7} -> 17
    for (int i = 0; i < 4; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_834 = &mock_sub834;
        obj.field_84C = 14;
        obj.field_840 = f840_in_20[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub834, 1, 0, 0);
        assert(res == 1);
        assert(obj.field_84C == 18);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_33A730");
    }
    for (int i = 0; i < 3; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_834 = &mock_sub834;
        obj.field_84C = 14;
        obj.field_840 = f840_out_20[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub834, 1, 0, 0);
        assert(res == 1);
        assert(obj.field_84C == 17);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_33A730");
    }

    std::printf("PASS test_func_342170_field_834_all_modes\n");
}

static void test_func_342170_field_830_all_modes() {
    TacticalObj_341040 obj;
    MockSubObj mock_sub830;
    MockSubObj mock_field844;
    static const int f840_in_20[] = {2, 4, 5, 6};
    static const int f840_out_20[] = {1, 3, 7};
    static const int f840_in_15[] = {2, 4};
    static const int f840_out_15[] = {1, 3, 5, 6, 7};

    // Mode 0: calls func_00341040 -> func_33A730
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_84C = 0;
    g_call_history.clear();
    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_33A730");

    // Mode 1: calls func_00340C30, writes 5
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_844 = &mock_field844;
    obj.field_84C = 1;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_00340C30");
    assert(*(int*)((char*)obj.field_844 + 2052) == 5);

    // Modes 2, 4: calls func_00340C30, writes 7
    int modes_2_4[] = {2, 4};
    for (int i = 0; i < 2; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_830 = &mock_sub830;
        obj.field_844 = &mock_field844;
        obj.field_84C = modes_2_4[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
        assert(res == 1);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_00340C30");
        assert(*(int*)((char*)obj.field_844 + 2052) == 7);
    }

    // Modes 5, 6: calls func_00340C30, writes 1
    int modes_5_6[] = {5, 6};
    for (int i = 0; i < 2; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_830 = &mock_sub830;
        obj.field_844 = &mock_field844;
        obj.field_84C = modes_5_6[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
        assert(res == 1);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_00340C30");
        assert(*(int*)((char*)obj.field_844 + 2052) == 1);
    }

    // Mode 7: calls func_00340C30, writes 9
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_844 = &mock_field844;
    obj.field_84C = 7;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_00340C30");
    assert(*(int*)((char*)obj.field_844 + 2052) == 9);

    // Mode 8: t0!=0xFFFF returns 0, t0==0xFFFF writes 6
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_844 = &mock_field844;
    obj.field_84C = 8;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 0);
    assert(g_call_history.size() == 0);

    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0xFFFF);
    assert(res == 1);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_00340C30");
    assert(*(int*)((char*)obj.field_844 + 2052) == 6);

    // Mode 9: t0!=0xFFFF returns 0, t0==0xFFFF writes 3
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_844 = &mock_field844;
    obj.field_84C = 9;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 0);
    assert(g_call_history.size() == 0);

    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0xFFFF);
    assert(res == 1);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_00340C30");
    assert(*(int*)((char*)obj.field_844 + 2052) == 3);

    // Mode 10: t0!=0xFFFF returns 0, t0==0xFFFF sets 84C=12, 83C=12
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_84C = 10;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 0);
    assert(g_call_history.size() == 0);

    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0xFFFF);
    assert(res == 1);
    assert(obj.field_84C == 12);
    assert(obj.field_83C == 12);
    assert(g_call_history.size() == 2);
    assert(g_call_history[0].name == "func_33A730");
    assert(g_call_history[1].name == "func_36ACC0");
    assert(g_call_history[1].arg1 == 2);

    // Mode 11: calls func_00340C30, writes 11
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_844 = &mock_field844;
    obj.field_84C = 11;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_00340C30");
    assert(*(int*)((char*)obj.field_844 + 2052) == 11);

    // Mode 12: sets field_84C = 13, calls func_00341040
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_84C = 12;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(obj.field_84C == 13);
    assert(g_call_history.size() == 2);
    assert(g_call_history[0].name == "func_33A730");
    assert(g_call_history[1].name == "func_36ACC0");
    assert(g_call_history[1].arg1 == 1);

    // Mode 13: calls func_00340C30, writes 4
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_844 = &mock_field844;
    obj.field_84C = 13;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_00340C30");
    assert(*(int*)((char*)obj.field_844 + 2052) == 4);

    // Mode 14 with field_840 boundary tests: in-bounds {2, 4, 5, 6} -> sets 12; out-of-bounds {1, 3, 7} -> writes 12
    for (int i = 0; i < 4; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_830 = &mock_sub830;
        obj.field_84C = 14;
        obj.field_840 = f840_in_20[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
        assert(res == 1);
        assert(obj.field_84C == 12);
        assert(g_call_history.size() == 2);
        assert(g_call_history[0].name == "func_33A730");
        assert(g_call_history[1].name == "func_36ACC0");
        assert(g_call_history[1].arg1 == 2);
    }
    for (int i = 0; i < 3; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_830 = &mock_sub830;
        obj.field_844 = &mock_field844;
        obj.field_84C = 14;
        obj.field_840 = f840_out_20[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
        assert(res == 1);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_00340C30");
        assert(*(int*)((char*)obj.field_844 + 2052) == 12);
    }

    // Mode 15 with field_840 boundary tests: in-bounds {2, 4} -> calls func_36ACC0(7), sets 16; out-of-bounds {1, 3, 5, 6, 7} -> sets 17
    for (int i = 0; i < 2; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_830 = &mock_sub830;
        obj.field_84C = 15;
        obj.field_840 = f840_in_15[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
        assert(res == 1);
        assert(obj.field_84C == 16);
        assert(g_call_history.size() == 2);
        assert(g_call_history[0].name == "func_36ACC0");
        assert(g_call_history[0].arg1 == 7);
        assert(g_call_history[1].name == "func_33A730");
    }
    for (int i = 0; i < 5; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_830 = &mock_sub830;
        obj.field_84C = 15;
        obj.field_840 = f840_out_15[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
        assert(res == 1);
        assert(obj.field_84C == 17);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_33A730");
    }

    // Mode 16: t0!=0xFFFF returns 0, t0==0xFFFF sets 84C=12, 83C=12
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_84C = 16;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 0);
    assert(g_call_history.size() == 0);

    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0xFFFF);
    assert(res == 1);
    assert(obj.field_84C == 12);
    assert(obj.field_83C == 12);
    assert(g_call_history.size() == 2);
    assert(g_call_history[0].name == "func_33A730");
    assert(g_call_history[1].name == "func_36ACC0");
    assert(g_call_history[1].arg1 == 2);

    // Mode 17: sets field_84C = 12
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_84C = 17;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(obj.field_84C == 12);
    assert(g_call_history.size() == 2);
    assert(g_call_history[0].name == "func_33A730");
    assert(g_call_history[1].name == "func_36ACC0");
    assert(g_call_history[1].arg1 == 2);

    // Modes 18, 21, 22, 23, 24: calls func_00340C30, writes 3
    int modes_18_24[] = {18, 21, 22, 23, 24};
    for (int i = 0; i < 5; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_830 = &mock_sub830;
        obj.field_844 = &mock_field844;
        obj.field_84C = modes_18_24[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
        assert(res == 1);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_00340C30");
        assert(*(int*)((char*)obj.field_844 + 2052) == 3);
    }

    // Mode 19: sets field_84C = 20
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_84C = 19;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(obj.field_84C == 20);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_33A730");

    // Mode 20 with field_840 boundary tests: in-bounds {2, 4, 5, 6} -> sets 17; out-of-bounds {1, 3, 7} -> writes 12
    for (int i = 0; i < 4; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_830 = &mock_sub830;
        obj.field_84C = 20;
        obj.field_840 = f840_in_20[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
        assert(res == 1);
        assert(obj.field_84C == 17);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_33A730");
    }
    for (int i = 0; i < 3; ++i) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_830 = &mock_sub830;
        obj.field_844 = &mock_field844;
        obj.field_84C = 20;
        obj.field_840 = f840_out_20[i];
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
        assert(res == 1);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_00340C30");
        assert(*(int*)((char*)obj.field_844 + 2052) == 12);
    }

    // Mode 25: writes 3
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_844 = &mock_field844;
    obj.field_84C = 25;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_00340C30");
    assert(*(int*)((char*)obj.field_844 + 2052) == 3);

    // Mode 26: writes 6
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_844 = &mock_field844;
    obj.field_84C = 26;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_00340C30");
    assert(*(int*)((char*)obj.field_844 + 2052) == 6);

    // Mode 27: sets field_84C = 12, field_83C = 12
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_84C = 27;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(obj.field_84C == 12);
    assert(obj.field_83C == 12);
    assert(g_call_history.size() == 2);
    assert(g_call_history[0].name == "func_33A730");
    assert(g_call_history[1].name == "func_36ACC0");
    assert(g_call_history[1].arg1 == 2);

    // Mode 28: sets field_84C = field_850 (55)
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_84C = 28;
    obj.field_850 = 55;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(obj.field_84C == 55);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_33A730");

    // Mode 29: sets field_84C = field_850 (88)
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_84C = 29;
    obj.field_850 = 88;
    g_call_history.clear();
    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(obj.field_84C == 88);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_33A730");

    // Modes 30 through 50: invokes func_00341040, asserts exact history and state
    for (int m = 30; m <= 50; ++m) {
        std::memset(&obj, 0, sizeof(obj));
        obj.field_830 = &mock_sub830;
        obj.field_84C = m;
        g_call_history.clear();
        res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
        assert(res == 1);
        assert(obj.field_84C == m);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_33A730");
        assert(g_call_history[0].self == NULL);
        assert(g_call_history[0].arg1 == 0);
    }

    std::printf("PASS test_func_342170_field_830_all_modes\n");
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
    MockSubObj mock_sub834;
    obj.field_830 = &mock_sub830;
    obj.field_834 = &mock_sub834;
    *(int*)((char*)&mock_sub830 + 552) = 450;
    *(int*)((char*)&mock_sub834 + 552) = 451;
    obj.field_84C = 45; // Mode >= 30 invokes func_00341040
    g_call_history.clear();

    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);

    assert(res == 1);
    assert(obj.field_84C == 45);
    assert(*(int*)((char*)obj.field_830 + 552) == 0);
    assert(*(int*)((char*)obj.field_834 + 552) == 0);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_33A730"); // inside func_00341040
    assert(g_call_history[0].self == NULL);
    assert(g_call_history[0].arg1 == 0);

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
    assert(g_call_history.size() == 0);

    std::printf("PASS test_func_342170_t0_equals_1_exact_history\n");
}

static void test_func_342170_mode30_50_exact_history() {
    TacticalObj_341040 obj;
    for (int m = 30; m <= 50; ++m) {
        std::memset(&obj, 0, sizeof(obj));
        MockSubObj mock_sub830;
        MockSubObj mock_sub834;
        obj.field_830 = &mock_sub830;
        obj.field_834 = &mock_sub834;
        *(int*)((char*)&mock_sub830 + 552) = m * 10;
        *(int*)((char*)&mock_sub834 + 552) = m * 20;
        obj.field_84C = m;
        g_call_history.clear();

        int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);

        assert(res == 1);
        assert(obj.field_84C == m);
        assert(*(int*)((char*)obj.field_830 + 552) == 0);
        assert(*(int*)((char*)obj.field_834 + 552) == 0);
        assert(g_call_history.size() == 1);
        assert(g_call_history[0].name == "func_33A730");
        assert(g_call_history[0].self == NULL);
        assert(g_call_history[0].arg1 == 0);
    }
    std::printf("PASS test_func_342170_mode30_50_exact_history\n");
}

static void test_func_342170_field_830_negative_and_boundary_modes() {
    TacticalObj_341040 obj;
    MockSubObj mock_sub830;
    MockSubObj mock_sub834;

    // Test exact boundary at mode 30 (unsigned 30 >= 30, dispatches to default func_00341040)
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_834 = &mock_sub834;
    *(int*)((char*)&mock_sub830 + 552) = 300;
    *(int*)((char*)&mock_sub834 + 552) = 301;
    obj.field_84C = 30;
    g_call_history.clear();

    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(obj.field_84C == 30);
    assert(*(int*)((char*)obj.field_830 + 552) == 0);
    assert(*(int*)((char*)obj.field_834 + 552) == 0);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_33A730");

    // Test negative mode -1: sltiu at, v0, 30 evaluates 0xFFFFFFFF >= 30 -> safely dispatches to default
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_834 = &mock_sub834;
    *(int*)((char*)&mock_sub830 + 552) = 111;
    *(int*)((char*)&mock_sub834 + 552) = 222;
    obj.field_84C = -1;
    g_call_history.clear();

    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(obj.field_84C == -1);
    assert(*(int*)((char*)obj.field_830 + 552) == 0);
    assert(*(int*)((char*)obj.field_834 + 552) == 0);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_33A730");

    // Test negative mode -100: safely dispatches to default
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_834 = &mock_sub834;
    *(int*)((char*)&mock_sub830 + 552) = 333;
    *(int*)((char*)&mock_sub834 + 552) = 444;
    obj.field_84C = -100;
    g_call_history.clear();

    res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(obj.field_84C == -100);
    assert(*(int*)((char*)obj.field_830 + 552) == 0);
    assert(*(int*)((char*)obj.field_834 + 552) == 0);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_33A730");

    std::printf("PASS test_func_342170_field_830_negative_and_boundary_modes\n");
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
    assert(g_call_history.size() == 2);
    assert(g_call_history[0].name == "func_33A730");
    assert(g_call_history[1].name == "func_36ACC0");
    assert(g_call_history[1].arg1 == 2);

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

    // Exact 4-call sequence and all multi-arguments:
    assert(g_call_history.size() == 4);
    assert(g_call_history[0].name == "func_339900");
    assert(g_call_history[0].self == &obj);
    assert(g_call_history[0].args[0] == (int)(long)&mock_sub838);

    assert(g_call_history[1].name == "func_33A5D0");
    assert(g_call_history[1].args[0] == 0);
    assert(g_call_history[1].args[1] == 0);
    assert(g_call_history[1].args[2] == 0);
    assert(g_call_history[1].args[3] == 1);
    assert(g_call_history[1].args[4] == 0);
    assert(g_call_history[1].args[5] == 0);

    assert(g_call_history[2].name == "func_339960");
    assert(g_call_history[2].args[0] == 0);
    assert(g_call_history[2].args[1] == 120); // field_C(20) + 100
    assert(g_call_history[2].args[2] == 127); // field_10(30) + 97
    assert(g_call_history[2].args[3] == 168);
    assert(g_call_history[2].args[4] == 22);
    assert(g_call_history[2].args[5] == 8);
    assert(g_call_history[2].args[6] == 6);

    assert(g_call_history[3].name == "func_1F6750");
    assert(g_call_history[3].self == &obj);
    assert(g_call_history[3].args[0] == (int)(long)&mock_sub838);

    std::printf("PASS test_func_342170_elf_sub838_a1_a2_16_branch\n");
}

static void test_func_342170_elf_sub838_func_339900_nonzero_branch() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    MockSubObj mock_sub838;
    MockSubObj mock_field844;
    obj.field_838 = &mock_sub838;
    obj.field_844 = &mock_field844;
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
    assert(obj.field_84C == 11);
    assert(g_call_history.size() == 7);
    assert(g_call_history[0].name == "func_339900");
    assert(g_call_history[0].self == &obj);
    assert(g_call_history[1].name == "func_33A730");
    assert(g_call_history[2].name == "func_00340CF0");
    assert(g_call_history[2].self == &obj);
    assert(g_call_history[3].name == "func_1F6EA0");
    assert(g_call_history[3].self == &obj);
    assert(g_call_history[3].args[0] == 0xc356);
    assert(g_call_history[4].name == "func_00219BA0");
    assert(g_call_history[4].self == &mock_sub838);
    assert(g_call_history[5].name == "func_33F8B0");
    assert(g_call_history[5].self == &mock_field844);
    assert(g_call_history[5].arg1 == 10);
    assert(g_call_history[6].name == "func_33A730"); // inside func_00341040
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

static void test_func_341040_field_840_value_2_routes_to_age2S() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.field_84C = 12; // Mode 12 in func_00341040
    obj.field_840 = 2;  // Value 2: not 3, not 4, not 6 -> must select aBesles50282age2S
    g_last_11abbc_src = NULL;
    g_call_history.clear();

    func_00341040(&obj);

    // Verified disassembly at 0x3411e4-0x341224:
    // field_840 == 3, 4, 6 selects aBesles50282age2G
    // All other values (including 2) must select aBesles50282age2S
    assert(g_last_11abbc_src != NULL);
    assert(g_last_11abbc_src == aBesles50282age2S);
    std::printf("PASS test_func_341040_field_840_value_2_routes_to_age2S\n");
}

static void test_func_342170_f844_mutation_precedes_func_340c30() {
    TacticalObj_341040 obj;
    MockSubObj mock_sub834;
    char mock_field844[2056];
    std::memset(&obj, 0, sizeof(obj));
    std::memset(mock_field844, 0, sizeof(mock_field844));
    obj.field_834 = &mock_sub834;
    obj.field_844 = &mock_field844;
    obj.field_84C = 1; // Routes to set_handler_state(self, 2)
    g_call_history.clear();
    g_f844_val_during_func_340c30 = -1;

    int res = func_00342170(&obj, (int)(long)&mock_sub834, 1, 0, 0);
    assert(res == 1);
    assert(g_call_history.size() == 1);
    assert(g_call_history[0].name == "func_00340C30");
    // Verified PS2 disassembly at 0x3423b0-0x3423c0:
    // field_844+2052 mutation executes before or in the branch/call delay slot of func_00340C30
    assert(g_f844_val_during_func_340c30 == 2);
    std::printf("PASS test_func_342170_f844_mutation_precedes_func_340c30\n");
}

static void test_func_342170_field_830_mode15_mutation_precedes_func_36acc0() {
    TacticalObj_341040 obj;
    MockSubObj mock_sub830;
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_84C = 15;
    obj.field_840 = 2; // in-bounds: 2 or 4 -> routes to field_84C = 16, func_36ACC0(7)
    g_call_history.clear();
    g_active_test_obj = &obj;
    g_field_84c_during_func_36acc0 = -1;

    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    assert(g_call_history.size() == 2);
    assert(g_call_history[0].name == "func_36ACC0");
    assert(g_call_history[0].arg1 == 7);
    assert(g_call_history[1].name == "func_33A730");
    // Verified PS2 disassembly 0x3424fc-0x34250c (inst 384-394):
    // field_84C = 16 mutation executes before or in the call delay slot of func_36ACC0
    assert(g_field_84c_during_func_36acc0 == 16);
    g_active_test_obj = NULL;
    std::printf("PASS test_func_342170_field_830_mode15_mutation_precedes_func_36acc0\n");
}

static void test_func_342170_mode8_32bit_exact_t0_matching() {
    TacticalObj_341040 obj;
    MockSubObj mock_sub830;
    char mock_field844[2056];
    std::memset(&obj, 0, sizeof(obj));
    std::memset(mock_field844, 0, sizeof(mock_field844));
    obj.field_830 = &mock_sub830;
    obj.field_844 = &mock_field844;
    obj.field_84C = 8; // Mode 8
    g_call_history.clear();

    // In original PS2 ELF at 0x242790 (0x440):
    // 440: li v0, 0xffff
    // 444: beq t0, v0, 454
    // 44c: b 620 (return 0)
    // Full 32-bit comparison: t0 = 0x1000FFFF must NOT match 0x0000FFFF, must return 0 without mutating state
    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0x1000FFFF);
    assert(res == 0);
    assert(g_call_history.size() == 0);
    assert(*(int*)((char*)obj.field_844 + 2052) == 0);
    std::printf("PASS test_func_342170_mode8_32bit_exact_t0_matching\n");
}

static void test_func_342170_mode3_null_sub838_transitions_to_mode11() {
    TacticalObj_341040 obj;
    MockSubObj mock_sub830;
    std::memset(&obj, 0, sizeof(obj));
    obj.field_830 = &mock_sub830;
    obj.field_838 = NULL;
    obj.field_84C = 3; // Mode 3
    g_call_history.clear();

    int res = func_00342170(&obj, (int)(long)&mock_sub830, 1, 0, 0);
    assert(res == 1);
    // In original PS2 ELF at 0x3426b4 (0x544):
    // 544: beqz v0, 594 (if !field_838 goto 594: field_84C = 11)
    assert(obj.field_84C == 11);
    std::printf("PASS test_func_342170_mode3_null_sub838_transitions_to_mode11\n");
}

int main() {
    test_func_342170_mode3_null_sub838_transitions_to_mode11();
    test_func_342170_mode8_32bit_exact_t0_matching();
    test_func_342170_field_830_mode15_mutation_precedes_func_36acc0();
    test_func_342170_f844_mutation_precedes_func_340c30();
    test_func_341040_field_840_value_2_routes_to_age2S();
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
    test_func_342170_field_834_all_modes();
    test_func_342170_field_830_all_modes();
    test_func_342170_call_history_sequence();
    test_func_342170_mode0_exact_history();
    test_func_342170_mode31_early_return_exact_history();
    test_func_342170_mode45_exact_history();
    test_func_342170_t0_equals_1_exact_history();
    test_func_342170_mode30_50_exact_history();
    test_func_342170_field_830_negative_and_boundary_modes();
    test_func_342170_t0_equals_2_exact_history();
    test_func_342170_mode31_a2_equals_1_exact_history();
    std::printf("ALL TACTICAL AI LAYOUT TESTS PASSED WITH COMPLETE EXACT HISTORY ASSERTIONS\n");
    return 0;
}
