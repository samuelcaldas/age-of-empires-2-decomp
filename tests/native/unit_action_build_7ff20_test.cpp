// Tests for func_0027FF20 (and func_27FF20) — Milestone 149 (1860B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7ff20.h"

struct ActionManager {
    int field_0;
    int field_4;
};

struct ActionDesc {
    char padding[6];
    short code;
};

extern "C" {
    int D_4E35DC = 0;
}

static int g_factory_calls[20] = {0};
static int g_init_arg2_calls[20] = {0};
static int g_init_float_calls[20] = {0};
static void *g_last_item = NULL;
static int g_last_field4 = -1;
static void *g_last_desc = NULL;
static void *g_last_arg2 = NULL;
static float g_last_f1 = 0.0f;
static float g_last_f2 = 0.0f;
static float g_last_f3 = 0.0f;
static int g_fallback_calls = 0;

static unsigned char g_dummy_items[20][16];
static unsigned char g_dummy_fallback[16];
static bool g_factory_null = false;

// Mock definitions
#define DEFINE_DUAL_MOCKS(idx, fact, init_arg2, init_flt) \
    extern "C" void *fact(void *) { \
        g_factory_calls[idx]++; \
        if (g_factory_null) return NULL; \
        return g_dummy_items[idx]; \
    } \
    extern "C" void init_arg2(void *item, int f4, void *desc, void *arg2) { \
        g_init_arg2_calls[idx]++; \
        g_last_item = item; \
        g_last_field4 = f4; \
        g_last_desc = desc; \
        g_last_arg2 = arg2; \
    } \
    extern "C" void init_flt(void *item, int f4, void *desc, float f1, float f2, float f3) { \
        g_init_float_calls[idx]++; \
        g_last_item = item; \
        g_last_field4 = f4; \
        g_last_desc = desc; \
        g_last_f1 = f1; \
        g_last_f2 = f2; \
        g_last_f3 = f3; \
    }

DEFINE_DUAL_MOCKS(0, func_366C60, func_352230, func_3522E0)
DEFINE_DUAL_MOCKS(1, func_366C80, func_354AD0, func_354B90)
DEFINE_DUAL_MOCKS(2, func_366CD0, func_359670, func_3596F0)

extern "C" void *func_366CF0(void *) {
    g_factory_calls[3]++;
    if (g_factory_null) return NULL;
    return g_dummy_items[3];
}
extern "C" void func_35CA80(void *item, int f4, int minus1) {
    g_init_arg2_calls[3]++;
    g_last_item = item;
    g_last_field4 = f4;
    assert(minus1 == -1);
}

DEFINE_DUAL_MOCKS(4, func_366C50, func_351190, func_3511F0)

extern "C" void *func_366DB0(void *) {
    g_factory_calls[5]++;
    if (g_factory_null) return NULL;
    return g_dummy_items[5];
}
extern "C" void func_365FA0(void *item, int f4) {
    g_init_arg2_calls[5]++;
    g_last_item = item;
    g_last_field4 = f4;
}

DEFINE_DUAL_MOCKS(6, func_366CA0, func_356D10, func_356D90)

extern "C" void *func_366CB0(void *) {
    g_factory_calls[7]++;
    if (g_factory_null) return NULL;
    return g_dummy_items[7];
}
extern "C" void func_357260(void *item, int f4, void *desc) {
    g_init_arg2_calls[7]++;
    g_last_item = item;
    g_last_field4 = f4;
    g_last_desc = desc;
}

extern "C" void *func_366CC0(void *) {
    g_factory_calls[8]++;
    if (g_factory_null) return NULL;
    return g_dummy_items[8];
}
extern "C" void func_357540(void *item, int f4, void *desc, void *arg2) {
    g_init_arg2_calls[8]++;
    g_last_item = item;
    g_last_field4 = f4;
    g_last_desc = desc;
    g_last_arg2 = arg2;
}

extern "C" void *func_366D60(void *) {
    g_factory_calls[9]++;
    if (g_factory_null) return NULL;
    return g_dummy_items[9];
}
extern "C" void func_361370(void *item, int f4, void *desc, void *arg2) {
    g_init_arg2_calls[9]++;
    g_last_item = item;
    g_last_field4 = f4;
    g_last_desc = desc;
    g_last_arg2 = arg2;
}

DEFINE_DUAL_MOCKS(10, func_366CE0, func_35A210, func_35A2E0)
DEFINE_DUAL_MOCKS(11, func_366D50, func_360080, func_360110)
DEFINE_DUAL_MOCKS(12, func_366D80, func_363A00, func_363AE0)

extern "C" void *func_366BD0(void *) {
    g_factory_calls[13]++;
    if (g_factory_null) return NULL;
    return g_dummy_items[13];
}
extern "C" void func_34A590(void *item, int f4, void *desc, void *arg2) {
    g_init_arg2_calls[13]++;
    g_last_item = item;
    g_last_field4 = f4;
    g_last_desc = desc;
    g_last_arg2 = arg2;
}

extern "C" void *func_366C40(void *) {
    g_factory_calls[14]++;
    if (g_factory_null) return NULL;
    return g_dummy_items[14];
}
extern "C" void func_3505E0(void *item, int f4, void *desc, float f1, float f2, float f3) {
    g_init_float_calls[14]++;
    g_last_item = item;
    g_last_field4 = f4;
    g_last_desc = desc;
    g_last_f1 = f1;
    g_last_f2 = f2;
    g_last_f3 = f3;
}

extern "C" void *func_366D30(void *) {
    g_factory_calls[15]++;
    if (g_factory_null) return NULL;
    return g_dummy_items[15];
}
extern "C" void func_35EE90(void *item, int f4, void *desc, float f1, float f2, float f3) {
    g_init_float_calls[15]++;
    g_last_item = item;
    g_last_field4 = f4;
    g_last_desc = desc;
    g_last_f1 = f1;
    g_last_f2 = f2;
    g_last_f3 = f3;
}

extern "C" void *func_366D20(void *) {
    g_factory_calls[16]++;
    if (g_factory_null) return NULL;
    return g_dummy_items[16];
}
extern "C" void func_35E530(void *item, int f4, void *desc, void *arg2) {
    g_init_arg2_calls[16]++;
    g_last_item = item;
    g_last_field4 = f4;
    g_last_desc = desc;
    g_last_arg2 = arg2;
}

extern "C" void *func_366D90(void *) {
    g_factory_calls[17]++;
    if (g_factory_null) return NULL;
    return g_dummy_items[17];
}
extern "C" void func_364E20(void *item, int f4, void *arg2, int minus1, float f1, float f2) {
    g_init_arg2_calls[17]++;
    g_last_item = item;
    g_last_field4 = f4;
    g_last_arg2 = arg2;
    assert(minus1 == -1);
    g_last_f1 = f1;
    g_last_f2 = f2;
}

extern "C" void *func_366C70(void *) {
    g_factory_calls[18]++;
    if (g_factory_null) return NULL;
    return g_dummy_items[18];
}
extern "C" void func_353680(void *item, int f4, void *arg2) {
    g_init_arg2_calls[18]++;
    g_last_item = item;
    g_last_field4 = f4;
    g_last_arg2 = arg2;
}

extern "C" void *func_366D00(void *) {
    g_factory_calls[19]++;
    if (g_factory_null) return NULL;
    return g_dummy_items[19];
}
extern "C" void func_35CF40(void *item, int f4, void *desc, void *arg2) {
    g_init_arg2_calls[19]++;
    g_last_item = item;
    g_last_field4 = f4;
    g_last_desc = desc;
    g_last_arg2 = arg2;
}

extern "C" {
    void *func_138F90(void *self, void *desc, void *arg2, float f1, float f2, float f3) {
        g_fallback_calls++;
        g_last_desc = desc;
        g_last_arg2 = arg2;
        g_last_f1 = f1;
        g_last_f2 = f2;
        g_last_f3 = f3;
        return g_dummy_fallback;
    }
}

static const short k_codes[20] = {
    0x65, 0x68, 0x69, 0x7b, 0x6b, 0x78, 0x6c, 0x79, 0x7a, 0x95,
    0x6e, 0x6a, 0x6f, 0x03, 0x0c, 0x83, 0x84, 0x7d, 0x87, 0x88
};

// Which cases only use float initializers (indices 14=0x0c, 15=0x83)
static bool is_float_only_case(size_t i) {
    return (i == 14 || i == 15);
}

// Which cases are dual (indices 0, 1, 2, 4, 6, 10, 11, 12)
static bool is_dual_case(size_t i) {
    return (i == 0 || i == 1 || i == 2 || i == 4 || i == 6 || i == 10 || i == 11 || i == 12);
}

// Which cases accept and forward arg2 in arg2-mode
static bool takes_arg2_in_arg2_mode(size_t i) {
    return (is_dual_case(i) || i == 8 || i == 9 || i == 13 || i == 16 || i == 17 || i == 18 || i == 19);
}

// Which cases accept and forward action_desc in arg2-mode
static bool takes_desc_in_arg2_mode(size_t i) {
    return (is_dual_case(i) || i == 7 || i == 8 || i == 9 || i == 13 || i == 16 || i == 19);
}

static void test_all_factories_with_arg2() {
    ActionManager dummy_self;
    dummy_self.field_0 = 1;
    dummy_self.field_4 = 42;
    unsigned char dummy_arg2[16];

    g_factory_null = false;
    for (size_t i = 0; i < 20; ++i) {
        memset(g_factory_calls, 0, sizeof(g_factory_calls));
        memset(g_init_arg2_calls, 0, sizeof(g_init_arg2_calls));
        memset(g_init_float_calls, 0, sizeof(g_init_float_calls));
        g_last_item = NULL;
        g_last_field4 = -1;
        g_last_desc = NULL;
        g_last_arg2 = NULL;
        g_last_f1 = 0.0f;
        g_last_f2 = 0.0f;
        g_last_f3 = 0.0f;
        g_fallback_calls = 0;

        ActionDesc desc;
        desc.code = k_codes[i];

        void *res = func_0027FF20(&dummy_self, &desc, dummy_arg2, 1.0f, 2.0f, 3.0f);
        assert(res == g_dummy_items[i]);
        assert(g_factory_calls[i] == 1);
        assert(g_fallback_calls == 0);
        assert(g_last_item == g_dummy_items[i]);
        assert(g_last_field4 == 42); // asserts forwarded field_4

        if (is_float_only_case(i)) {
            // Cases 0x0C and 0x83 take floats regardless of arg2
            assert(g_init_float_calls[i] == 1);
            assert(g_init_arg2_calls[i] == 0);
            assert(g_last_desc == &desc);
            assert(g_last_f1 == 1.0f);
            assert(g_last_f2 == 2.0f);
            assert(g_last_f3 == 3.0f);
        } else {
            // All other cases select the arg2 initializer path
            assert(g_init_arg2_calls[i] == 1);
            assert(g_init_float_calls[i] == 0);
            if (takes_desc_in_arg2_mode(i)) {
                assert(g_last_desc == &desc); // asserts forwarded descriptor (including case 0x79)
            }
            if (takes_arg2_in_arg2_mode(i)) {
                assert(g_last_arg2 == dummy_arg2); // asserts forwarded arg2
            }
            if (i == 17) {
                // Case 0x7D forwards arg2 AND f1, f2
                assert(g_last_f1 == 1.0f);
                assert(g_last_f2 == 2.0f);
            }
        }
    }
    printf("PASS test_all_factories_with_arg2\n");
}

static void test_all_factories_with_floats() {
    ActionManager dummy_self;
    dummy_self.field_4 = 99;

    g_factory_null = false;
    for (size_t i = 0; i < 20; ++i) {
        memset(g_factory_calls, 0, sizeof(g_factory_calls));
        memset(g_init_arg2_calls, 0, sizeof(g_init_arg2_calls));
        memset(g_init_float_calls, 0, sizeof(g_init_float_calls));
        g_last_item = NULL;
        g_last_field4 = -1;
        g_last_desc = NULL;
        g_last_arg2 = (void *)0xdead;
        g_last_f1 = 0.0f;
        g_last_f2 = 0.0f;
        g_last_f3 = 0.0f;
        g_fallback_calls = 0;

        ActionDesc desc;
        desc.code = k_codes[i];

        // arg2 is NULL -> selects float path for dual cases and float-only cases
        void *res = func_0027FF20(&dummy_self, &desc, NULL, 4.0f, 5.0f, 6.0f);
        assert(res == g_dummy_items[i]);
        assert(g_factory_calls[i] == 1);
        assert(g_fallback_calls == 0);
        assert(g_last_item == g_dummy_items[i]);
        assert(g_last_field4 == 99); // asserts forwarded field_4

        if (is_dual_case(i) || is_float_only_case(i)) {
            assert(g_init_float_calls[i] == 1);
            assert(g_init_arg2_calls[i] == 0);
            assert(g_last_desc == &desc);
            assert(g_last_f1 == 4.0f); // first float
            assert(g_last_f2 == 5.0f); // second float
            assert(g_last_f3 == 6.0f); // third float explicitly asserted!
        } else {
            // Single cases without float variant still call their single initializer
            assert(g_init_arg2_calls[i] == 1);
            assert(g_init_float_calls[i] == 0);
            if (takes_arg2_in_arg2_mode(i)) {
                assert(g_last_arg2 == NULL);
            }
            if (i == 17) {
                // Case 0x7D forwards both float arguments f1 and f2 even with arg2=NULL
                assert(g_last_f1 == 4.0f);
                assert(g_last_f2 == 5.0f);
            }
        }
    }
    printf("PASS test_all_factories_with_floats\n");
}

static void test_factory_null() {
    ActionManager dummy_self;
    dummy_self.field_4 = 77;
    unsigned char dummy_arg2[16];

    g_factory_null = true;
    for (size_t i = 0; i < 20; ++i) {
        memset(g_factory_calls, 0, sizeof(g_factory_calls));
        memset(g_init_arg2_calls, 0, sizeof(g_init_arg2_calls));
        memset(g_init_float_calls, 0, sizeof(g_init_float_calls));
        g_fallback_calls = 0;

        ActionDesc desc;
        desc.code = k_codes[i];

        void *res = func_0027FF20(&dummy_self, &desc, dummy_arg2, 1.0f, 2.0f, 3.0f);
        assert(res == NULL);
        assert(g_factory_calls[i] == 1);
        // Initializers must NOT be called when factory returns NULL!
        assert(g_init_arg2_calls[i] == 0);
        assert(g_init_float_calls[i] == 0);
        assert(g_fallback_calls == 0);
    }
    g_factory_null = false;
    printf("PASS test_factory_null\n");
}

static void test_fallback() {
    ActionManager dummy_self;
    unsigned char dummy_arg2[16];
    short unhandled[] = {0, 1, 2, 4, 0x10, 0x50, 0x100, -1};
    const size_t count = sizeof(unhandled) / sizeof(unhandled[0]);

    for (size_t i = 0; i < count; ++i) {
        g_fallback_calls = 0;
        ActionDesc desc;
        desc.code = unhandled[i];

        void *res = func_0027FF20(&dummy_self, &desc, dummy_arg2, 7.0f, 8.0f, 9.0f);
        assert(res == g_dummy_fallback);
        assert(g_fallback_calls == 1);
        assert(g_last_desc == &desc);
        assert(g_last_arg2 == dummy_arg2);
        assert(g_last_f1 == 7.0f);
        assert(g_last_f2 == 8.0f);
        assert(g_last_f3 == 9.0f);
    }
    printf("PASS test_fallback\n");
}

static void test_alias() {
    ActionManager dummy_self;
    dummy_self.field_4 = 55;
    ActionDesc desc;
    desc.code = 0x65;
    unsigned char dummy_arg2[16];
    memset(g_factory_calls, 0, sizeof(g_factory_calls));

    void *res = func_27FF20(&dummy_self, &desc, dummy_arg2, 1.0f, 2.0f, 3.0f);
    assert(res == g_dummy_items[0]);
    assert(g_factory_calls[0] == 1);
    printf("PASS test_alias\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) {
            test_all_factories_with_arg2();
            return 0;
        } else if (case_num == 1) {
            test_all_factories_with_floats();
            return 0;
        } else if (case_num == 2) {
            test_factory_null();
            return 0;
        } else if (case_num == 3) {
            test_fallback();
            return 0;
        } else if (case_num == 4) {
            test_alias();
            return 0;
        }
    }
    test_all_factories_with_arg2();
    test_all_factories_with_floats();
    test_factory_null();
    test_fallback();
    test_alias();
    printf("All unit_action_build_7ff20 tests passed!\n");
    return 0;
}
