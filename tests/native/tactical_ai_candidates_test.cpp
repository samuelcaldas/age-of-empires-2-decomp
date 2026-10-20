#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x30];
    void *field_34;
    char pad_38[0x4];
    void **field_3C;
    char pad_40[0x150];
    int field_190;
    char pad_194[0x8];
    int field_19C;
};

struct CandidateBuf {
    char tag;
    char pad;
    short val;
};

extern "C" {
    static int s_26b0a0_called = 0;
    static void *s_26b0a0_last_ptr = 0;
    static int s_26b0a0_last_a1 = 0;
    static int s_26b0a0_last_a2 = 0;
    static void *s_26b0a0_ret_ptr = 0;

    void *func_26B0A0(void *ptr, int a1, int a2) {
        s_26b0a0_called++;
        s_26b0a0_last_ptr = ptr;
        s_26b0a0_last_a1 = a1;
        s_26b0a0_last_a2 = a2;
        return s_26b0a0_ret_ptr;
    }

    static int s_26af90_called = 0;
    static void *s_26af90_last_ptr = 0;
    static int s_26af90_last_a1 = 0;
    static CandidateBuf s_26af90_last_buf;

    void *func_26AF90(void *ptr, int a1, void *a2) {
        s_26af90_called++;
        s_26af90_last_ptr = ptr;
        s_26af90_last_a1 = a1;
        if (a2) s_26af90_last_buf = *(CandidateBuf*)a2;
        return a2;
    }

    static int s_1370_called = 0;
    static void *s_1370_last_self = 0;
    static int s_1370_last_a1 = 0;
    static int s_1370_ret = 0;

    int func_00141370(void *self, int a1) {
        s_1370_called++;
        s_1370_last_self = self;
        s_1370_last_a1 = a1;
        return s_1370_ret;
    }

    static int s_142980_called = 0;
    static int s_142980_ret = 0;

    int func_142980(void *ptr) {
        (void)ptr;
        s_142980_called++;
        return s_142980_ret;
    }

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

    int func_00142680(TacticalAI2 *self, int a1);
    void *func_00142730(TacticalAI2 *self, int a1, int a2);
    int func_001427A0(TacticalAI2 *self);
}

static void reset_mocks() {
    s_26b0a0_called = 0;
    s_26b0a0_last_ptr = 0;
    s_26b0a0_last_a1 = 0;
    s_26b0a0_last_a2 = 0;
    s_26b0a0_ret_ptr = 0;

    s_26af90_called = 0;
    s_26af90_last_ptr = 0;
    s_26af90_last_a1 = 0;
    memset(&s_26af90_last_buf, 0, sizeof(s_26af90_last_buf));

    s_1370_called = 0;
    s_1370_last_self = 0;
    s_1370_last_a1 = 0;
    s_1370_ret = 0;

    s_142980_called = 0;
    s_142980_ret = 0;

    s_144340_called = 0;
    s_144340_last_ptr = 0;
    s_144340_last_a1 = 0;
    s_144340_last_a2 = 0;
}

static void test_tactical_ai_candidates_2680_cached() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_190 = 1;

    void *elements[2] = { 0, (void*)0x8888 };
    ai.field_3C = elements;

    CandidateBuf cached_item;
    cached_item.tag = 4;
    cached_item.val = 42;
    s_26b0a0_ret_ptr = &cached_item;

    int val = func_00142680(&ai, 10);

    assert(val == 42);
    assert(s_26b0a0_called == 1);
    assert(s_26b0a0_last_ptr == (void*)0x8888);
    assert(s_26b0a0_last_a1 == 10);
    assert(s_26b0a0_last_a2 == 4);
    assert(s_1370_called == 0); // did not call allocate

    assert(val == 42);

    printf("TACTICAL_AI_CANDIDATES_TEST_0_2680_CACHED_PASSED\n");
}

static void test_tactical_ai_candidates_2680_alloc_success() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_190 = 0;

    void *elements[1] = { (void*)0x7777 };
    ai.field_3C = elements;

    s_26b0a0_ret_ptr = 0; // cache miss
    s_1370_ret = 15;      // allocated id

    int val = func_00142680(&ai, 20);

    assert(val == 15);
    assert(s_26b0a0_called == 1);
    assert(s_1370_called == 1);
    assert(s_1370_last_self == &ai);
    assert(s_1370_last_a1 == 0);
    assert(s_26af90_called == 1);
    assert(s_26af90_last_ptr == (void*)0x7777);
    assert(s_26af90_last_a1 == 20);
    assert(s_26af90_last_buf.tag == 4);
    assert(s_26af90_last_buf.val == 15);

    printf("TACTICAL_AI_CANDIDATES_TEST_1_2680_ALLOC_SUCCESS_PASSED\n");
}

static void test_tactical_ai_candidates_2680_alloc_fail() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_190 = 0;

    void *elements[1] = { (void*)0x7777 };
    ai.field_3C = elements;

    s_26b0a0_ret_ptr = 0;
    s_1370_ret = -1; // allocate failed

    int val = func_00142680(&ai, 30);

    assert(val == -1);
    assert(s_1370_called == 1);
    assert(s_26af90_called == 0); // no cache insert

    printf("TACTICAL_AI_CANDIDATES_TEST_2_2680_ALLOC_FAIL_PASSED\n");
}

static void test_tactical_ai_candidates_2730_first_hit() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_190 = 2;

    void *elements[3] = { 0, 0, (void*)0x9999 };
    ai.field_3C = elements;
    s_26b0a0_ret_ptr = (void*)0xAAAA;

    void *res = func_00142730(&ai, 1, 2);

    assert(res == (void*)0xAAAA);
    assert(s_26b0a0_called == 1);
    assert(s_26b0a0_last_ptr == (void*)0x9999);
    assert(s_26b0a0_last_a1 == 1);
    assert(s_26b0a0_last_a2 == 2);

    printf("TACTICAL_AI_CANDIDATES_TEST_3_2730_FIRST_HIT_PASSED\n");
}

static void test_tactical_ai_candidates_2730_second_call() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_190 = 0;

    void *elements[1] = { (void*)0x1111 };
    ai.field_3C = elements;

    // Custom mock: first call returns 0, second call returns 0xBBBB
    struct SeqMock {
        static void *call(void *ptr, int a1, int a2) {
            (void)ptr; (void)a1; (void)a2;
            return (void*)0xBBBB;
        }
    };
    s_26b0a0_ret_ptr = 0; // causes second call

    void *res = func_00142730(&ai, 5, 6);

    assert(res == 0); // because s_26b0a0_ret_ptr was 0 for both
    assert(s_26b0a0_called == 2);
    assert(s_26b0a0_last_ptr == &ai.field_34);
    assert(s_26b0a0_last_a1 == 5);
    assert(s_26b0a0_last_a2 == 6);

    printf("TACTICAL_AI_CANDIDATES_TEST_4_2730_SECOND_CALL_PASSED\n");
}

static void test_tactical_ai_candidates_27a0_success() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_19C = 3;
    s_142980_ret = 2; // status 2

    int res = func_001427A0(&ai);

    assert(res == 1);
    assert(s_142980_called == 1);
    assert(s_144340_called == 0);

    printf("TACTICAL_AI_CANDIDATES_TEST_5_27A0_SUCCESS_PASSED\n");
}

static void test_tactical_ai_candidates_27a0_invalid_19c() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_19C = 5; // != 3
    s_142980_ret = 2;

    int res = func_001427A0(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_ptr == &ai);
    assert(s_144340_last_a1 == 8);
    assert(s_144340_last_a2 == 0);

    printf("TACTICAL_AI_CANDIDATES_TEST_6_27A0_INVALID_19C_PASSED\n");
}

static void test_tactical_ai_candidates_27a0_status_1() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    s_142980_ret = 1;

    int res = func_001427A0(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_ptr == &ai);
    assert(s_144340_last_a1 == 0x1A);
    assert(s_144340_last_a2 == 0);

    printf("TACTICAL_AI_CANDIDATES_TEST_7_27A0_STATUS_1_PASSED\n");
}

static void test_tactical_ai_candidates_27a0_status_0() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    s_142980_ret = 0;

    int res = func_001427A0(&ai);

    assert(res == 0);
    assert(s_144340_called == 0); // no error logged for status 0

    printf("TACTICAL_AI_CANDIDATES_TEST_8_27A0_STATUS_0_PASSED\n");
}

static void test_tactical_ai_candidates_layout() {
    assert(sizeof(CandidateBuf) == 4);
    assert(offsetof(CandidateBuf, tag) == 0);
    assert(offsetof(CandidateBuf, val) == 2);
    assert(offsetof(TacticalAI2, field_34) == 0x34);
    assert(offsetof(TacticalAI2, field_3C) == 0x3C);
    assert(offsetof(TacticalAI2, field_190) == 0x190);
    assert(offsetof(TacticalAI2, field_19C) == 0x19C);

    printf("TACTICAL_AI_CANDIDATES_TEST_9_LAYOUT_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-9)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_tactical_ai_candidates_2680_cached();
    else if (mode == 1) test_tactical_ai_candidates_2680_alloc_success();
    else if (mode == 2) test_tactical_ai_candidates_2680_alloc_fail();
    else if (mode == 3) test_tactical_ai_candidates_2730_first_hit();
    else if (mode == 4) test_tactical_ai_candidates_2730_second_call();
    else if (mode == 5) test_tactical_ai_candidates_27a0_success();
    else if (mode == 6) test_tactical_ai_candidates_27a0_invalid_19c();
    else if (mode == 7) test_tactical_ai_candidates_27a0_status_1();
    else if (mode == 8) test_tactical_ai_candidates_27a0_status_0();
    else if (mode == 9) test_tactical_ai_candidates_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
