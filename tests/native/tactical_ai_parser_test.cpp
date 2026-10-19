#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Obj12 {
    char data[12];
};

struct PredicateItem {
    short type;
    short op_or_node;
    int a1;
    int a2;
    int a3;
    int t0;
};

struct Candidate {
    char pad_0[2];
    short field_2;
};

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x14];
    Obj12 *field_18;
    char pad_1C[0x18];
    void *field_34;
    char pad_38[0x8];
    int field_40;
    char pad_44[0x8];
    PredicateItem field_4C[1];
    char pad_60[0x138];
    int field_198;
    int field_19C;
    char field_1A0[0x100];
};

extern "C" {
    char D_48E100[258] = { 0 };

    static int s_142980_called = 0;
    static int s_142980_statuses[8] = { 2, 2, 2, 2 };
    static int s_142980_types[8] = { 1, 1, 1, 1 };
    static const char *s_142980_tokens[8] = { "my_action", "123", "my_sym", "\"str\"" };
    static int s_142980_idx = 0;

    int func_142980(void *self) {
        TacticalAI2 *ai = (TacticalAI2*)self;
        s_142980_called++;
        int s = s_142980_statuses[s_142980_idx % 8];
        ai->field_19C = s_142980_types[s_142980_idx % 8];
        if (s_142980_tokens[s_142980_idx % 8]) {
            strcpy(ai->field_1A0, s_142980_tokens[s_142980_idx % 8]);
        }
        s_142980_idx++;
        return s;
    }

    static int s_144340_called = 0;
    static void *s_144340_last_self = 0;
    static int s_144340_last_code = 0;
    static void *s_144340_last_param = 0;

    void func_144340(void *self, int code, void *param) {
        s_144340_called++;
        s_144340_last_self = self;
        s_144340_last_code = code;
        s_144340_last_param = param;
    }

    static int s_26b0a0_called = 0;
    static Candidate s_cand_ret;
    static int s_cand_found = 1;

    void *func_26B0A0(void *table, char *name, int a2) {
        (void)table; (void)name; (void)a2;
        s_26b0a0_called++;
        if (!s_cand_found) return 0;
        s_cand_ret.field_2 = 5; // node index 5
        return &s_cand_ret;
    }

    static int s_13c650_called = 0;
    static int s_param_count = 3;

    int func_0013C650(void *action) {
        (void)action;
        s_13c650_called++;
        return s_param_count;
    }

    static int s_1410e0_called = 0;
    static int s_1410e0_ret = 77;

    int func_001410E0(void *self, char *str) {
        (void)self; (void)str;
        s_1410e0_called++;
        return s_1410e0_ret;
    }

    static int s_114378_called = 0;

    int func_114378(const char *str) {
        s_114378_called++;
        return atoi(str);
    }

    static int s_142730_called = 0;
    static Candidate s_sym_ret;
    static int s_sym_found = 1;

    void *func_00142730(void *self, char *token, int a2) {
        (void)self; (void)token; (void)a2;
        s_142730_called++;
        if (!s_sym_found) return 0;
        s_sym_ret.field_2 = 42;
        return &s_sym_ret;
    }

    static int s_1427a0_called = 0;
    static int s_1427a0_ret = 1;

    int func_001427A0(void *self) {
        (void)self;
        s_1427a0_called++;
        return s_1427a0_ret;
    }

    int func_00142D10(TacticalAI2 *self);
}

static void init_ctype_table() {
    memset(D_48E100, 0, sizeof(D_48E100));
    for (int d = '0'; d <= '9'; d++) {
        D_48E100[d + 1] = 4; // digit flag
    }
}

static void reset_mocks() {
    s_142980_called = 0;
    s_142980_idx = 0;
    s_144340_called = 0;
    s_144340_last_self = 0;
    s_144340_last_code = 0;
    s_144340_last_param = 0;
    s_26b0a0_called = 0;
    s_cand_found = 1;
    s_13c650_called = 0;
    s_param_count = 3;
    s_1410e0_called = 0;
    s_1410e0_ret = 77;
    s_114378_called = 0;
    s_142730_called = 0;
    s_sym_found = 1;
    s_1427a0_called = 0;
    s_1427a0_ret = 1;
}

static void test_tactical_ai_parser_success() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    Obj12 objs[10];
    memset(objs, 0, sizeof(objs));
    ai.field_18 = objs;
    ai.field_40 = 0;
    ai.field_198 = 1; // enable string interning

    // Token 0: "my_action" (type 1)
    // Token 1: "123" (type 1, number -> a1 = 123)
    // Token 2: "my_sym" (type 1, symbol -> a2 = 42)
    // Token 3: "str" (type 4, string -> a3 = 77)
    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "my_action";
    s_142980_statuses[1] = 2; s_142980_types[1] = 1; s_142980_tokens[1] = "123";
    s_142980_statuses[2] = 2; s_142980_types[2] = 1; s_142980_tokens[2] = "my_sym";
    s_142980_statuses[3] = 2; s_142980_types[3] = 4; s_142980_tokens[3] = "test_string";
    s_param_count = 3;

    int res = func_00142D10(&ai);

    assert(res == 1);
    assert(s_142980_called == 4);
    assert(s_26b0a0_called == 1);
    assert(s_13c650_called == 1);
    assert(ai.field_4C[0].type == 1);
    assert(ai.field_4C[0].op_or_node == 5);
    assert(ai.field_4C[0].a1 == 123);
    assert(ai.field_4C[0].a2 == 42);
    assert(ai.field_4C[0].a3 == 77);
    assert(s_1427a0_called == 1);

    // End of test_tactical_ai_parser_success

    printf("TACTICAL_AI_PARSER_TEST_0_SUCCESS_PASSED\n");
}

static void test_tactical_ai_parser_eof_first() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_142980_statuses[0] = 1; // EOF
    int res = func_00142D10(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0x1A);

    printf("TACTICAL_AI_PARSER_TEST_1_EOF_FIRST_PASSED\n");
}

static void test_tactical_ai_parser_invalid_first_tok() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_142980_statuses[0] = 2;
    s_142980_types[0] = 2; // '(' instead of identifier

    int res = func_00142D10(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0xC);

    printf("TACTICAL_AI_PARSER_TEST_2_INVALID_FIRST_TOK_PASSED\n");
}

static void test_tactical_ai_parser_unknown_action() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_142980_statuses[0] = 2;
    s_142980_types[0] = 1;
    s_cand_found = 0; // candidate not found

    int res = func_00142D10(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0x3);

    printf("TACTICAL_AI_PARSER_TEST_3_UNKNOWN_ACTION_PASSED\n");
}

static void test_tactical_ai_parser_invalid_param_type() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    Obj12 objs[10];
    memset(objs, 0, sizeof(objs));
    ai.field_18 = objs;

    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "action";
    s_142980_statuses[1] = 2; s_142980_types[1] = 3; // ')' invalid param type
    s_param_count = 1;

    int res = func_00142D10(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0xC);

    printf("TACTICAL_AI_PARSER_TEST_4_INVALID_PARAM_TYPE_PASSED\n");
}

static void test_tactical_ai_parser_string_intern_fail() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    Obj12 objs[10];
    memset(objs, 0, sizeof(objs));
    ai.field_18 = objs;
    ai.field_198 = 1;

    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "action";
    s_142980_statuses[1] = 2; s_142980_types[1] = 4; s_142980_tokens[1] = "str";
    s_param_count = 1;
    s_1410e0_ret = -1; // intern failure

    int res = func_00142D10(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0x15);

    printf("TACTICAL_AI_PARSER_TEST_5_STRING_INTERN_FAIL_PASSED\n");
}

static void test_tactical_ai_parser_symbol_lookup_fail() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    Obj12 objs[10];
    memset(objs, 0, sizeof(objs));
    ai.field_18 = objs;

    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "action";
    s_142980_statuses[1] = 2; s_142980_types[1] = 1; s_142980_tokens[1] = "unknown_sym";
    s_param_count = 1;
    s_sym_found = 0; // symbol lookup fails

    int res = func_00142D10(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0x3);

    printf("TACTICAL_AI_PARSER_TEST_6_SYMBOL_LOOKUP_FAIL_PASSED\n");
}

static void test_tactical_ai_parser_closing_fail() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    Obj12 objs[10];
    memset(objs, 0, sizeof(objs));
    ai.field_18 = objs;

    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "action";
    s_param_count = 0; // 0 params
    s_1427a0_ret = 0;  // closing delimiter fails

    int res = func_00142D10(&ai);

    assert(res == 0);
    assert(s_1427a0_called == 1);

    printf("TACTICAL_AI_PARSER_TEST_7_CLOSING_FAIL_PASSED\n");
}

static void test_tactical_ai_parser_layout() {
    assert(sizeof(PredicateItem) == 20);
    assert(sizeof(Candidate) == 4);
    assert(offsetof(TacticalAI2, field_18) == 0x18);
    assert(offsetof(TacticalAI2, field_34) == 0x34);
    assert(offsetof(TacticalAI2, field_40) == 0x40);
    assert(offsetof(TacticalAI2, field_4C) == 0x4C);
    assert(offsetof(TacticalAI2, field_198) == 0x198);
    assert(offsetof(TacticalAI2, field_19C) == 0x19C);
    assert(offsetof(TacticalAI2, field_1A0) == 0x1A0);

    printf("TACTICAL_AI_PARSER_TEST_8_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_parser_success();
    else if (mode == 1) test_tactical_ai_parser_eof_first();
    else if (mode == 2) test_tactical_ai_parser_invalid_first_tok();
    else if (mode == 3) test_tactical_ai_parser_unknown_action();
    else if (mode == 4) test_tactical_ai_parser_invalid_param_type();
    else if (mode == 5) test_tactical_ai_parser_string_intern_fail();
    else if (mode == 6) test_tactical_ai_parser_symbol_lookup_fail();
    else if (mode == 7) test_tactical_ai_parser_closing_fail();
    else if (mode == 8) test_tactical_ai_parser_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
