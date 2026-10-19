#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Msg {
    char type;
    char pad;
    short val;
};

struct TacticalAI2 {
    void *m_vtable;
    char pad_004[0x34 - 4];
    char m_field34[8];
    void **m_field3C;
};

extern "C" {
    static int s_26af90_called = 0;
    static void *s_26af90_last_ptr = 0;
    static int s_26af90_last_a1 = 0;
    static int s_26af90_override_val = -1;
    static Msg s_26af90_ret_msg;

    Msg *func_26AF90(void *ptr, int a1, Msg *a2) {
        s_26af90_called++;
        s_26af90_last_ptr = ptr;
        s_26af90_last_a1 = a1;
        s_26af90_ret_msg = *a2;
        if (s_26af90_override_val >= 0) {
            s_26af90_ret_msg.val = (short)s_26af90_override_val;
        }
        return &s_26af90_ret_msg;
    }

    static int s_1170_called = 0;
    static void *s_1170_last_self = 0;
    static int s_1170_last_a1 = 0;
    static int s_1170_last_a2 = 0;
    static int s_1170_last_a3 = 0;
    static int s_1170_ret = 0;

    int func_00141170(void *self, int a1, int a2, int a3) {
        s_1170_called++;
        s_1170_last_self = self;
        s_1170_last_a1 = a1;
        s_1170_last_a2 = a2;
        s_1170_last_a3 = a3;
        return s_1170_ret;
    }

    int func_00142130(TacticalAI2 *self, int a1, int a2, int a3);
    int func_001421A0(TacticalAI2 *self, int a1, int a2);
    int func_00142200(TacticalAI2 *self, int a1, int a2);
    int func_00142260(TacticalAI2 *self, int a1, int a2, int a3, int t0);
}

static void reset_mocks() {
    s_26af90_called = 0;
    s_26af90_last_ptr = 0;
    s_26af90_last_a1 = 0;
    s_26af90_override_val = -1;
    memset(&s_26af90_ret_msg, 0, sizeof(s_26af90_ret_msg));

    s_1170_called = 0;
    s_1170_last_self = 0;
    s_1170_last_a1 = 0;
    s_1170_last_a2 = 0;
    s_1170_last_a3 = 0;
    s_1170_ret = 0;
}

static void test_tactical_ai_dispatch_2130() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    void *elements[3] = { (void*)0x1111, (void*)0x2222, (void*)0x3333 };
    ai.m_field3C = elements;

    // Match
    int res = func_00142130(&ai, 1, 10, 42);
    assert(res == 1);
    assert(s_26af90_called == 1);
    assert(s_26af90_last_ptr == (void*)0x2222);
    assert(s_26af90_last_a1 == 10);

    // Mismatch
    s_26af90_override_val = 999;
    res = func_00142130(&ai, 1, 10, 42);
    assert(res == 0);

    assert(s_26af90_called == 2);

    printf("TACTICAL_AI_DISPATCH_TEST_0_2130_PASSED\n");
}

static void test_tactical_ai_dispatch_21a0() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    // Match
    int res = func_001421A0(&ai, 5, 20);
    assert(res == 1);
    assert(s_26af90_called == 1);
    assert(s_26af90_last_ptr == ai.m_field34);
    assert(s_26af90_last_a1 == 5);

    // Mismatch
    s_26af90_override_val = 999;
    res = func_001421A0(&ai, 5, 20);
    assert(res == 0);

    printf("TACTICAL_AI_DISPATCH_TEST_1_21A0_PASSED\n");
}

static void test_tactical_ai_dispatch_2200() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    // Match
    int res = func_00142200(&ai, 7, 77);
    assert(res == 1);
    assert(s_26af90_called == 1);
    assert(s_26af90_last_ptr == ai.m_field34);
    assert(s_26af90_last_a1 == 7);

    // Mismatch
    s_26af90_override_val = 0;
    res = func_00142200(&ai, 7, 77);
    assert(res == 0);

    printf("TACTICAL_AI_DISPATCH_TEST_2_2200_PASSED\n");
}

static void test_tactical_ai_dispatch_2260_fail1170() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_1170_ret = -1;
    int res = func_00142260(&ai, 1, 2, 3, 4);

    assert(res == 0);
    assert(s_1170_called == 1);
    assert(s_1170_last_self == &ai);
    assert(s_1170_last_a1 == 2);
    assert(s_1170_last_a2 == 3);
    assert(s_1170_last_a3 == 4);
    assert(s_26af90_called == 0); // No message dispatched

    printf("TACTICAL_AI_DISPATCH_TEST_3_2260_FAIL1170_PASSED\n");
}

static void test_tactical_ai_dispatch_2260_success() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_1170_ret = 88;
    int res = func_00142260(&ai, 3, 4, 5, 6);

    assert(res == 1);
    assert(s_1170_called == 1);
    assert(s_26af90_called == 1);
    assert(s_26af90_last_ptr == ai.m_field34);
    assert(s_26af90_last_a1 == 3);

    // Mismatch
    s_26af90_override_val = 999;
    res = func_00142260(&ai, 3, 4, 5, 6);
    assert(res == 0);

    printf("TACTICAL_AI_DISPATCH_TEST_4_2260_SUCCESS_PASSED\n");
}

static void test_tactical_ai_dispatch_layout() {
    assert(offsetof(TacticalAI2, m_field34) == 0x34);
    assert(offsetof(TacticalAI2, m_field3C) == 0x3C);

    printf("TACTICAL_AI_DISPATCH_TEST_5_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_dispatch_2130();
    else if (mode == 1) test_tactical_ai_dispatch_21a0();
    else if (mode == 2) test_tactical_ai_dispatch_2200();
    else if (mode == 3) test_tactical_ai_dispatch_2260_fail1170();
    else if (mode == 4) test_tactical_ai_dispatch_2260_success();
    else if (mode == 5) test_tactical_ai_dispatch_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
