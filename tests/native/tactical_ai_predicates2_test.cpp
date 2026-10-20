#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct TacticalAI2 {
    void *m_vtable;
    char pad_004[0x194];
    int field_198;
    char pad_19C[0x4];
    char field_1A0[0x100];
};

extern "C" {
    char D_490ED0[20] = "#load-if-defined";
    char D_490EF0[24] = "#load-if-not-defined";
    char D_490F08[16] = "#else";
    char D_490F10[16] = "#end-if";

    int func_0011AA78(const char *s1, const char *s2) {
        return strcmp(s1, s2);
    }

    static int s_144340_called = 0;
    static int s_144340_last_a1 = 0;

    void func_144340(void *ptr, int a1, void *a2) {
        (void)ptr; (void)a2;
        s_144340_called++;
        s_144340_last_a1 = a1;
    }

    static int s_2c80_ret = 0;
    int func_00142C80(void *ptr) { (void)ptr; return s_2c80_ret; }

    static int s_2c90_ret = 0;
    int func_00142C90(void *ptr) { (void)ptr; return s_2c90_ret; }

    static int s_2ca0_ret = 1;
    int func_00142CA0(void *ptr) { (void)ptr; return s_2ca0_ret; }

    static int s_2830_ret = 1;
    int func_00142830(void *ptr) { (void)ptr; return s_2830_ret; }

    static int s_1442e0_called = 0;
    void func_1442E0(void *ptr) { (void)ptr; s_1442e0_called++; }

    static int s_144180_called = 0;
    void func_144180(void *ptr) { (void)ptr; s_144180_called++; }

    static void *s_2730_ret = (void*)0x1234;
    void *func_00142730(void *ptr, const char *name, int a2) {
        (void)ptr; (void)name; (void)a2;
        return s_2730_ret;
    }

    int func_143860(TacticalAI2 *self);
}

static void reset_mocks() {
    s_144340_called = 0;
    s_144340_last_a1 = 0;
    s_2c80_ret = 0;
    s_2c90_ret = 0;
    s_2ca0_ret = 1;
    s_2830_ret = 1;
    s_1442e0_called = 0;
    s_144180_called = 0;
    s_2730_ret = (void*)0x1234;
}

static void test_tactical_ai_predicates2_load_if_defined_hit() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    strcpy(ai.field_1A0, "#load-if-defined");
    ai.field_198 = 1;
    s_2730_ret = (void*)0x5555; // defined

    int res = func_143860(&ai);

    assert(res == 1);
    assert(s_1442e0_called == 1);
    assert(ai.field_198 == 1);

    // End of test_tactical_ai_predicates2_load_if_defined_hit

    printf("TACTICAL_AI_PREDICATES2_TEST_0_LOAD_IF_DEF_HIT_PASSED\n");
}

static void test_tactical_ai_predicates2_load_if_defined_miss() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    strcpy(ai.field_1A0, "#load-if-defined");
    ai.field_198 = 1;
    s_2730_ret = 0; // not defined

    int res = func_143860(&ai);

    assert(res == 1);
    assert(s_1442e0_called == 1);
    assert(ai.field_198 == 0);

    printf("TACTICAL_AI_PREDICATES2_TEST_1_LOAD_IF_DEF_MISS_PASSED\n");
}

static void test_tactical_ai_predicates2_load_if_not_defined_hit() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    strcpy(ai.field_1A0, "#load-if-not-defined");
    ai.field_198 = 1;
    s_2730_ret = 0; // not defined -> condition true

    int res = func_143860(&ai);

    assert(res == 1);
    assert(ai.field_198 == 1);

    printf("TACTICAL_AI_PREDICATES2_TEST_2_LOAD_IF_NOT_DEF_HIT_PASSED\n");
}

static void test_tactical_ai_predicates2_load_if_not_defined_miss() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    strcpy(ai.field_1A0, "#load-if-not-defined");
    ai.field_198 = 1;
    s_2730_ret = (void*)0x1234; // defined -> condition false

    int res = func_143860(&ai);

    assert(res == 1);
    assert(ai.field_198 == 0);

    printf("TACTICAL_AI_PREDICATES2_TEST_3_LOAD_IF_NOT_DEF_MISS_PASSED\n");
}

static void test_tactical_ai_predicates2_nesting_limit() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    strcpy(ai.field_1A0, "#load-if-defined");
    s_2c90_ret = 1; // nesting depth limit reached

    int res = func_143860(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_a1 == 0x13);

    printf("TACTICAL_AI_PREDICATES2_TEST_4_NESTING_LIMIT_PASSED\n");
}

static void test_tactical_ai_predicates2_syntax_fail() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    strcpy(ai.field_1A0, "#load-if-defined");
    s_2830_ret = 0; // syntax error

    int res = func_143860(&ai);

    assert(res == 0);

    printf("TACTICAL_AI_PREDICATES2_TEST_5_SYNTAX_FAIL_PASSED\n");
}

static void test_tactical_ai_predicates2_else_success() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    strcpy(ai.field_1A0, "#else");
    ai.field_198 = 0;
    s_2c80_ret = 0; // valid open if
    s_2ca0_ret = 1;

    int res = func_143860(&ai);

    assert(res == 1);
    assert(ai.field_198 == 1); // flipped from 0 to 1

    printf("TACTICAL_AI_PREDICATES2_TEST_6_ELSE_SUCCESS_PASSED\n");
}

static void test_tactical_ai_predicates2_else_no_open_if() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    strcpy(ai.field_1A0, "#else");
    s_2c80_ret = 1; // no open if

    int res = func_143860(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_a1 == 0x17);

    printf("TACTICAL_AI_PREDICATES2_TEST_7_ELSE_NO_OPEN_IF_PASSED\n");
}

static void test_tactical_ai_predicates2_endif_success() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    strcpy(ai.field_1A0, "#end-if");
    s_2c80_ret = 0;

    int res = func_143860(&ai);

    assert(res == 1);
    assert(s_144180_called == 1);

    printf("TACTICAL_AI_PREDICATES2_TEST_8_ENDIF_SUCCESS_PASSED\n");
}

static void test_tactical_ai_predicates2_endif_no_open_if() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    strcpy(ai.field_1A0, "#end-if");
    s_2c80_ret = 1; // no open if

    int res = func_143860(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_a1 == 0x18);

    printf("TACTICAL_AI_PREDICATES2_TEST_9_ENDIF_NO_OPEN_IF_PASSED\n");
}

static void test_tactical_ai_predicates2_unknown_directive() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    strcpy(ai.field_1A0, "#unknown");

    int res = func_143860(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_a1 == 5);

    printf("TACTICAL_AI_PREDICATES2_TEST_10_UNKNOWN_DIRECTIVE_PASSED\n");
}

static void test_tactical_ai_predicates2_layout() {
    assert(offsetof(TacticalAI2, field_198) == 0x198);
    assert(offsetof(TacticalAI2, field_1A0) == 0x1A0);

    printf("TACTICAL_AI_PREDICATES2_TEST_11_LAYOUT_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-11)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_tactical_ai_predicates2_load_if_defined_hit();
    else if (mode == 1) test_tactical_ai_predicates2_load_if_defined_miss();
    else if (mode == 2) test_tactical_ai_predicates2_load_if_not_defined_hit();
    else if (mode == 3) test_tactical_ai_predicates2_load_if_not_defined_miss();
    else if (mode == 4) test_tactical_ai_predicates2_nesting_limit();
    else if (mode == 5) test_tactical_ai_predicates2_syntax_fail();
    else if (mode == 6) test_tactical_ai_predicates2_else_success();
    else if (mode == 7) test_tactical_ai_predicates2_else_no_open_if();
    else if (mode == 8) test_tactical_ai_predicates2_endif_success();
    else if (mode == 9) test_tactical_ai_predicates2_endif_no_open_if();
    else if (mode == 10) test_tactical_ai_predicates2_unknown_directive();
    else if (mode == 11) test_tactical_ai_predicates2_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
