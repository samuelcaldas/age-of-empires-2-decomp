#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct ErrorStruct {
    char msg1[0x104];
    int field_104;
    char msg2[0x80];
    int field_188;
};

struct ScopeContext {
    int field_0;
    char buf[0x400];
    char *field_6A8;
    int field_6AC;
    int field_6B0;
    int field_6B8;
    int field_6BC;
};

struct TacticalAI2 {
    void *m_vtable;
    char pad_004[0x194];
    int field_198;
    char pad_19C[0x108];
    int field_2A4;
    char field_2A8[0x400];
    char *field_6A8;
    int field_6AC;
    int field_6B0;
    ErrorStruct *field_6B4;
    int field_6B8;
    int field_6BC;
    int field_6C0;
    ScopeContext scopes[10];
    int field_2FB4;
    int field_2FB8[50];
};

extern "C" {
    char D_490F1C[8] = "";

    static int s_11abbc_called = 0;

    char *func_0011ABBC(char *dst, const char *src) {
        s_11abbc_called++;
        return strcpy(dst, src);
    }

    void func_1441B0(TacticalAI2 *self);
    void func_1442E0(TacticalAI2 *self);
    void func_144310(TacticalAI2 *self);
    void func_144340(TacticalAI2 *self, int a1, const char *a2);
}

static void reset_mocks() {
    s_11abbc_called = 0;
}

static void test_tactical_ai_scope_1441b0() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    ai.field_6C0 = 1;
    ai.field_2A4 = 111;
    ai.field_6AC = 222;
    char sample_token[] = "token";
    ai.field_6A8 = sample_token;
    ai.field_6B0 = 333;
    strcpy(ai.field_2A8, "scope_script_line");
    ai.field_6B8 = 444;
    ai.field_6BC = 555;

    func_1441B0(&ai);

    assert(ai.field_6C0 == 2);
    assert(ai.scopes[1].field_0 == 111);
    assert(ai.scopes[1].field_6AC == 222);
    assert(ai.scopes[1].field_6A8 == sample_token);
    assert(ai.scopes[1].field_6B0 == 333);
    assert(strcmp(ai.scopes[1].buf, "scope_script_line") == 0);
    assert(ai.scopes[1].field_6B8 == 444);
    assert(ai.scopes[1].field_6BC == 555);

    // End of test_tactical_ai_scope_1441b0

    printf("TACTICAL_AI_SCOPE_TEST_0_1441B0_PASSED\n");
}

static void test_tactical_ai_scope_1442e0() {
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    ai.field_2FB4 = 3;
    ai.field_198 = 77;

    func_1442E0(&ai);

    assert(ai.field_2FB4 == 4);
    assert(ai.field_2FB8[3] == 77);

    printf("TACTICAL_AI_SCOPE_TEST_1_1442E0_PASSED\n");
}

static void test_tactical_ai_scope_144310() {
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ErrorStruct err;
    memset(&err, 0xEE, sizeof(err));
    ai.field_6B4 = &err;

    func_144310(&ai);

    assert(err.msg1[0] == 0);
    assert(err.field_104 == -1);
    assert(err.msg2[0] == 0);
    assert(err.field_188 == 0x19);

    printf("TACTICAL_AI_SCOPE_TEST_2_144310_PASSED\n");
}

static void test_tactical_ai_scope_144340_null_err() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_6B4 = 0;

    func_144340(&ai, 5, "param");

    assert(s_11abbc_called == 0);

    printf("TACTICAL_AI_SCOPE_TEST_3_144340_NULL_ERR_PASSED\n");
}

static void test_tactical_ai_scope_144340_filename_and_param() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ErrorStruct err;
    memset(&err, 0, sizeof(err));
    ai.field_6B4 = &err;

    char filename[] = "myscript.per";
    ai.field_6AC = (int)(long)filename;
    ai.field_6B0 = 42; // line number

    func_144340(&ai, 3, "custom_error_param");

    assert(strcmp(err.msg1, "myscript.per") == 0);
    assert(err.field_104 == 42); // line number
    assert(strcmp(err.msg2, "custom_error_param") == 0);
    assert(err.field_188 == 3);

    printf("TACTICAL_AI_SCOPE_TEST_4_144340_FILENAME_PARAM_PASSED\n");
}

static void test_tactical_ai_scope_144340_empty_defaults() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ErrorStruct err;
    memset(&err, 0x55, sizeof(err));
    ai.field_6B4 = &err;

    ai.field_6AC = 0; // null filename -> default
    ai.field_6B0 = 10;

    func_144340(&ai, 4, 0); // null param -> default

    assert(strcmp(err.msg1, "") == 0);
    assert(err.field_104 == 10);
    assert(strcmp(err.msg2, "") == 0);
    assert(err.field_188 == 4);

    printf("TACTICAL_AI_SCOPE_TEST_5_144340_EMPTY_DEFAULTS_PASSED\n");
}

static void test_tactical_ai_scope_144340_no_line_codes() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ErrorStruct err;
    memset(&err, 0, sizeof(err));
    ai.field_6B4 = &err;
    ai.field_6B0 = 100;

    // Code 1: no line number
    func_144340(&ai, 1, "test");
    assert(err.field_104 == -1);
    assert(err.field_188 == 1);

    // Code 18: no line number
    func_144340(&ai, 18, "test");
    assert(err.field_104 == -1);
    assert(err.field_188 == 18);

    printf("TACTICAL_AI_SCOPE_TEST_6_144340_NO_LINE_CODES_PASSED\n");
}

static void test_tactical_ai_scope_144340_unknown_code() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ErrorStruct err;
    memset(&err, 0, sizeof(err));
    ai.field_6B4 = &err;

    func_144340(&ai, 999, "unknown");

    assert(err.field_104 == -1);
    assert(err.field_188 == 0x16); // mapped to 0x16

    printf("TACTICAL_AI_SCOPE_TEST_7_144340_UNKNOWN_CODE_PASSED\n");
}

static void test_tactical_ai_scope_layout() {
    assert(sizeof(ErrorStruct) == 0x18C);
    assert(sizeof(ScopeContext) == 0x418);
    assert(offsetof(ErrorStruct, msg1) == 0);
    assert(offsetof(ErrorStruct, field_104) == 0x104);
    assert(offsetof(ErrorStruct, msg2) == 0x108);
    assert(offsetof(ErrorStruct, field_188) == 0x188);

    assert(offsetof(TacticalAI2, field_6B4) == 0x6B4);
    assert(offsetof(TacticalAI2, field_6C0) == 0x6C0);
    assert(offsetof(TacticalAI2, scopes) == 0x6C4);
    assert(offsetof(TacticalAI2, field_2FB4) == 0x2FB4);
    assert(offsetof(TacticalAI2, field_2FB8) == 0x2FB8);

    printf("TACTICAL_AI_SCOPE_TEST_8_LAYOUT_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-8)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_tactical_ai_scope_1441b0();
    else if (mode == 1) test_tactical_ai_scope_1442e0();
    else if (mode == 2) test_tactical_ai_scope_144310();
    else if (mode == 3) test_tactical_ai_scope_144340_null_err();
    else if (mode == 4) test_tactical_ai_scope_144340_filename_and_param();
    else if (mode == 5) test_tactical_ai_scope_144340_empty_defaults();
    else if (mode == 6) test_tactical_ai_scope_144340_no_line_codes();
    else if (mode == 7) test_tactical_ai_scope_144340_unknown_code();
    else if (mode == 8) test_tactical_ai_scope_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
