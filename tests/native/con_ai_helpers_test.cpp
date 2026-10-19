#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct SubListConItem {
    int m_dummy;
};

extern "C" {
    static int s_f4b0_called = 0;
    static float s_f4b0_last_x = 0.0f;
    static float s_f4b0_last_y = 0.0f;
    static SubListConItem *s_f4b0_return_item = 0;

    static int s_e1c0_called = 0;
    static SubListConItem *s_e1c0_last_item = 0;

    static int s_e1b0_called = 0;
    static SubListConItem *s_e1b0_last_item = 0;

    SubListConItem *func_0013F4B0(void *self, float x, float y) {
        (void)self;
        s_f4b0_called++;
        s_f4b0_last_x = x;
        s_f4b0_last_y = y;
        return s_f4b0_return_item;
    }

    void func_0013E1C0(SubListConItem *item) {
        s_e1c0_called++;
        s_e1c0_last_item = item;
    }

    void func_0013E1B0(SubListConItem *item) {
        s_e1b0_called++;
        s_e1b0_last_item = item;
    }

    void func_0013F3F0(void *self, float x, float y, int count);
    void func_0013F450(void *self, float x, float y, int count);
}

static void reset_mocks() {
    s_f4b0_called = 0;
    s_f4b0_last_x = 0.0f;
    s_f4b0_last_y = 0.0f;
    s_f4b0_return_item = 0;
    s_e1c0_called = 0;
    s_e1c0_last_item = 0;
    s_e1b0_called = 0;
    s_e1b0_last_item = 0;
}

static void test_con_ai_helpers_f3f0_null() {
    reset_mocks();
    s_f4b0_return_item = 0;

    func_0013F3F0((void*)0x1234, 1.5f, 2.5f, 5);

    assert(s_f4b0_called == 1);
    assert(s_f4b0_last_x == 1.5f);
    assert(s_f4b0_last_y == 2.5f);
    assert(s_e1c0_called == 0);

    printf("CON_AI_HELPERS_TEST_0_F3F0_NULL_PASSED\n");
}

static void test_con_ai_helpers_f3f0_found() {
    reset_mocks();
    SubListConItem item;
    s_f4b0_return_item = &item;

    func_0013F3F0((void*)0x1234, 3.5f, 4.5f, 3);
    assert(s_f4b0_called == 1);
    assert(s_f4b0_last_x == 3.5f);
    assert(s_f4b0_last_y == 4.5f);
    assert(s_e1c0_called == 3);
    assert(s_e1c0_last_item == &item);

    printf("CON_AI_HELPERS_TEST_1_F3F0_FOUND_PASSED\n");
}

static void test_con_ai_helpers_f3f0_zero_count() {
    reset_mocks();
    SubListConItem item;
    s_f4b0_return_item = &item;

    func_0013F3F0((void*)0x1234, 5.5f, 6.5f, 0);
    assert(s_f4b0_called == 1);
    assert(s_e1c0_called == 0);

    printf("CON_AI_HELPERS_TEST_2_F3F0_ZERO_COUNT_PASSED\n");
}

static void test_con_ai_helpers_f450_null() {
    reset_mocks();
    s_f4b0_return_item = 0;

    func_0013F450((void*)0x5678, 10.0f, 20.0f, 4);
    assert(s_f4b0_called == 1);
    assert(s_f4b0_last_x == 10.0f);
    assert(s_f4b0_last_y == 20.0f);
    assert(s_e1b0_called == 0);

    printf("CON_AI_HELPERS_TEST_3_F450_NULL_PASSED\n");
}

static void test_con_ai_helpers_f450_found() {
    reset_mocks();
    SubListConItem item;
    s_f4b0_return_item = &item;

    func_0013F450((void*)0x5678, 30.0f, 40.0f, 4);
    assert(s_f4b0_called == 1);
    assert(s_f4b0_last_x == 30.0f);
    assert(s_f4b0_last_y == 40.0f);
    assert(s_e1b0_called == 4);
    assert(s_e1b0_last_item == &item);

    printf("CON_AI_HELPERS_TEST_4_F450_FOUND_PASSED\n");
}

static void test_con_ai_helpers_f450_zero_count() {
    reset_mocks();
    SubListConItem item;
    s_f4b0_return_item = &item;

    func_0013F450((void*)0x5678, 50.0f, 60.0f, 0);
    assert(s_f4b0_called == 1);
    assert(s_e1b0_called == 0);

    printf("CON_AI_HELPERS_TEST_5_F450_ZERO_COUNT_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-5)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_con_ai_helpers_f3f0_null();
    else if (mode == 1) test_con_ai_helpers_f3f0_found();
    else if (mode == 2) test_con_ai_helpers_f3f0_zero_count();
    else if (mode == 3) test_con_ai_helpers_f450_null();
    else if (mode == 4) test_con_ai_helpers_f450_found();
    else if (mode == 5) test_con_ai_helpers_f450_zero_count();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
