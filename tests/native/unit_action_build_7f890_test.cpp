// Tests for func_0027F890 (and func_27F890) — Milestone 148 (1680B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7f890.h"

struct ActionArg {
    int field_0;
    int field_4;
};

// Global pointer D_4E35DC
extern "C" {
    int D_4E35DC = 0;
}

static int g_factory_calls[25] = {0};
static int g_init_calls[25] = {0};
static void *g_init_self = NULL;
static int g_init_field4 = -1;
static int g_func_138D50_called = 0;

static unsigned char g_dummy_items[25][16];
static unsigned char g_dummy_fallback[16];
static bool g_factory_null = false;

#define DEFINE_MOCKS(i, fact_name, init_name) \
    extern "C" void *fact_name(void *) { \
        g_factory_calls[i]++; \
        if (g_factory_null) return NULL; \
        return g_dummy_items[i]; \
    } \
    extern "C" void init_name(void *item, void *self, int field_4) { \
        g_init_calls[i]++; \
        g_init_self = self; \
        g_init_field4 = field_4; \
    }

DEFINE_MOCKS(0, func_366C60, func_3521C0)
DEFINE_MOCKS(1, func_366D10, func_35D6F0)
DEFINE_MOCKS(2, func_366D70, func_3633B0)
DEFINE_MOCKS(3, func_366C80, func_354990)
DEFINE_MOCKS(4, func_366CD0, func_359640)
DEFINE_MOCKS(5, func_366CF0, func_35CA30)
DEFINE_MOCKS(6, func_366C50, func_351160)
DEFINE_MOCKS(7, func_366DB0, func_365F00)
DEFINE_MOCKS(8, func_366CA0, func_356C90)
DEFINE_MOCKS(9, func_366CB0, func_357230)
DEFINE_MOCKS(10, func_366CC0, func_3574F0)
DEFINE_MOCKS(11, func_366CE0, func_35A140)
extern "C" void *func_366D50(void *) {
    g_factory_calls[12]++;
    if (g_factory_null) return NULL;
    return g_dummy_items[12];
}
extern "C" void func_360000(void *item, void *self, int field_4, int arg4) {
    g_init_calls[12]++;
    g_init_self = self;
    g_init_field4 = field_4;
    assert(arg4 == 1);
}
DEFINE_MOCKS(13, func_366D80, func_363940)
DEFINE_MOCKS(14, func_366C40, func_3505B0)
DEFINE_MOCKS(15, func_366BD0, func_34A520)
DEFINE_MOCKS(16, func_366D30, func_35EE30)
DEFINE_MOCKS(17, func_366D20, func_35E4A0)
DEFINE_MOCKS(18, func_366C90, func_3566C0)
DEFINE_MOCKS(19, func_366D40, func_35F9E0)
DEFINE_MOCKS(20, func_366D90, func_364D70)
DEFINE_MOCKS(21, func_366DA0, func_3656F0)
DEFINE_MOCKS(22, func_366C70, func_353650)
DEFINE_MOCKS(23, func_366D60, func_3612E0)
DEFINE_MOCKS(24, func_366D00, func_35CEB0)

extern "C" {
    void *func_138D50(void *self, void *arg1, short code) {
        g_func_138D50_called++;
        return g_dummy_fallback;
    }
}

static const short k_codes[25] = {
    0x65, 0x66, 0x67, 0x68, 0x69, 0x7b, 0x6b, 0x78,
    0x6c, 0x79, 0x7a, 0x6e, 0x6a, 0x6f, 0xc, 0x3,
    0x83, 0x84, 0x85, 0x7c, 0x7d, 0x86, 0x87, 0x95,
    0x88
};

static void test_all_factories() {
    unsigned char dummy_self[32];
    ActionArg arg;
    arg.field_0 = 10;
    arg.field_4 = 42;

    g_factory_null = false;
    for (size_t i = 0; i < 25; ++i) {
        memset(g_factory_calls, 0, sizeof(g_factory_calls));
        memset(g_init_calls, 0, sizeof(g_init_calls));
        g_init_self = NULL;
        g_init_field4 = -1;
        g_func_138D50_called = 0;

        void *res = func_0027F890(dummy_self, &arg, k_codes[i]);
        assert(res == g_dummy_items[i]);
        assert(g_factory_calls[i] == 1);
        assert(g_init_calls[i] == 1);
        assert(g_init_self == dummy_self);
        assert(g_init_field4 == 42);
        assert(g_func_138D50_called == 0);
    }
    printf("PASS test_all_factories (25 action codes verified)\n");
}

static void test_factory_null() {
    unsigned char dummy_self[32];
    ActionArg arg;
    arg.field_4 = 99;
    g_factory_null = true;

    for (size_t i = 0; i < 25; ++i) {
        memset(g_factory_calls, 0, sizeof(g_factory_calls));
        memset(g_init_calls, 0, sizeof(g_init_calls));
        void *res = func_0027F890(dummy_self, &arg, k_codes[i]);
        assert(res == NULL);
        assert(g_factory_calls[i] == 1);
        assert(g_init_calls[i] == 0);
    }
    g_factory_null = false;
    printf("PASS test_factory_null\n");
}

static void test_fallback() {
    unsigned char dummy_self[32];
    ActionArg arg;
    arg.field_4 = 100;
    short unhandled[] = {0, 1, 2, 4, 0x10, 0x50, 0x100, -1};
    const size_t count = sizeof(unhandled) / sizeof(unhandled[0]);

    for (size_t i = 0; i < count; ++i) {
        g_func_138D50_called = 0;
        void *res = func_0027F890(dummy_self, &arg, unhandled[i]);
        assert(res == g_dummy_fallback);
        assert(g_func_138D50_called == 1);
    }
    printf("PASS test_fallback\n");
}

static void test_alias() {
    unsigned char dummy_self[32];
    ActionArg arg;
    arg.field_4 = 77;
    memset(g_factory_calls, 0, sizeof(g_factory_calls));
    void *res = func_27F890(dummy_self, &arg, 0x65);
    assert(res == g_dummy_items[0]);
    assert(g_factory_calls[0] == 1);
    printf("PASS test_alias\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) {
            test_all_factories();
            test_factory_null();
            return 0;
        } else if (case_num == 1) {
            test_fallback();
            return 0;
        } else if (case_num == 2) {
            test_alias();
            return 0;
        } else {
            fprintf(stderr, "Unknown test case %d\n", case_num);
            return 1;
        }
    }
    test_all_factories();
    test_factory_null();
    test_fallback();
    test_alias();
    printf("All unit_action_build_7f890 tests passed!\n");
    return 0;
}
