#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct TacticalAI2 {
    char m_padding[0x40];
    int m_counter;
    char m_padding2[0x2FB4 - 0x44];
    int m_value;
    int m_extra[4];
};

extern "C" {
    static int s_144340_called = 0;
    static void *s_144340_last_ptr = 0;
    static int s_144340_last_a1 = 0;
    static int s_144340_last_a2 = 0;

    void func_144340(void *ptr, int a1, int a2) {
        s_144340_called++;
        s_144340_last_ptr = ptr;
        s_144340_last_a1 = a1;
        s_144340_last_a2 = a2;
    }

    int func_00142C80(TacticalAI2 *self);
    int func_00142C90(TacticalAI2 *self);
    int func_00142CA0(TacticalAI2 *self);
    int func_00142CC0(TacticalAI2 *self);
}

static void reset_mocks() {
    s_144340_called = 0;
    s_144340_last_ptr = 0;
    s_144340_last_a1 = 0;
    s_144340_last_a2 = 0;
}

static void test_tactical_ai_getters_2c80() {
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_value = 0;
    assert(func_00142C80(&ai) == 1);

    ai.m_value = 1;
    assert(func_00142C80(&ai) == 0);

    // End of test_tactical_ai_getters_2c80

    printf("TACTICAL_AI_GETTERS_TEST_0_2C80_PASSED\n");
}

static void test_tactical_ai_getters_2c90() {
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_value = 0x32;
    assert(func_00142C90(&ai) == 1);

    ai.m_value = 0;
    assert(func_00142C90(&ai) == 0);

    printf("TACTICAL_AI_GETTERS_TEST_1_2C90_PASSED\n");
}

static void test_tactical_ai_getters_2ca0() {
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_value = 2; // index 2 relative to &m_value
    ai.m_extra[0] = 111; // index 1
    ai.m_extra[1] = 222; // index 2

    assert(func_00142CA0(&ai) == 222);

    printf("TACTICAL_AI_GETTERS_TEST_2_2CA0_PASSED\n");
}

static void test_tactical_ai_getters_2cc0_success() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_counter = 5;

    int res = func_00142CC0(&ai);

    assert(res == 1);
    assert(ai.m_counter == 6);
    assert(s_144340_called == 0);

    printf("TACTICAL_AI_GETTERS_TEST_3_2CC0_SUCCESS_PASSED\n");
}

static void test_tactical_ai_getters_2cc0_overflow() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_counter = 15; // after +1 becomes 16 (0x10)

    int res = func_00142CC0(&ai);

    assert(res == 0);
    assert(ai.m_counter == 16);
    assert(s_144340_called == 1);
    assert(s_144340_last_ptr == &ai);
    assert(s_144340_last_a1 == 0x14);
    assert(s_144340_last_a2 == 0);

    printf("TACTICAL_AI_GETTERS_TEST_4_2CC0_OVERFLOW_PASSED\n");
}

static void test_tactical_ai_getters_layout() {
    assert(offsetof(TacticalAI2, m_counter) == 0x40);
    assert(offsetof(TacticalAI2, m_value) == 0x2FB4);

    printf("TACTICAL_AI_GETTERS_TEST_5_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_getters_2c80();
    else if (mode == 1) test_tactical_ai_getters_2c90();
    else if (mode == 2) test_tactical_ai_getters_2ca0();
    else if (mode == 3) test_tactical_ai_getters_2cc0_success();
    else if (mode == 4) test_tactical_ai_getters_2cc0_overflow();
    else if (mode == 5) test_tactical_ai_getters_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
