#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0xC];
    char *field_10;
    char pad_14[0x20];
    char field_34[0xC];
    int field_40;
    char pad_44[0x158];
    int field_19C;
    char field_1A0[0x100];
    char extra_pred[128]; // storage for 0x4C+
};

extern "C" {
    char D_48E100[258] = { 0 };

    static int s_142980_called = 0;
    static int s_142980_statuses[16] = { 2 };
    static int s_142980_types[16] = { 1 };
    static const char *s_142980_tokens[16] = { "cond" };
    static int s_142980_idx = 0;

    int func_142980(void *self) {
        TacticalAI2 *ai = (TacticalAI2*)self;
        s_142980_called++;
        int s = s_142980_statuses[s_142980_idx % 16];
        ai->field_19C = s_142980_types[s_142980_idx % 16];
        if (s_142980_tokens[s_142980_idx % 16]) {
            strcpy(ai->field_1A0, s_142980_tokens[s_142980_idx % 16]);
        }
        s_142980_idx++;
        return s;
    }

    static int s_144340_called = 0;
    static int s_144340_last_code = 0;
    static void *s_144340_last_param = 0;

    void func_144340(void *self, int code, void *param) {
        (void)self;
        s_144340_called++;
        s_144340_last_code = code;
        s_144340_last_param = param;
    }

    static int s_26b0a0_called = 0;
    static short s_tag1_ret[2] = { 0, 1 }; // tag 1 (connective, op 1)
    static short s_tag3_ret[2] = { 0, 4 }; // tag 3 (leaf cond, cond_id 4)
    static int s_find_tag1 = 0;
    static int s_find_tag3 = 0;

    void *func_26B0A0(void *table, const char *name, int a2) {
        (void)table;
        s_26b0a0_called++;
        if (a2 == 1 && s_find_tag1 && (name == 0 || strcmp(name, "leaf") != 0)) return s_tag1_ret;
        if (a2 == 3 && s_find_tag3) return s_tag3_ret;
        return 0;
    }

    static int s_142cc0_called = 0;
    static int s_142cc0_ret = 1;

    int func_00142CC0(void *self) {
        (void)self;
        s_142cc0_called++;
        return s_142cc0_ret;
    }

    static int s_1427a0_called = 0;
    static int s_1427a0_ret = 1;

    int func_001427A0(void *self) {
        (void)self;
        s_1427a0_called++;
        return s_1427a0_ret;
    }

    static int s_1446a0_called = 0;
    static int s_1446a0_param_count = 2;

    int func_1446A0(void *ptr) {
        (void)ptr;
        s_1446a0_called++;
        return s_1446a0_param_count;
    }

    static int s_114378_called = 0;

    int func_114378(const char *str) {
        s_114378_called++;
        return atoi(str);
    }

    static int s_142730_called = 0;
    static short s_sym_ret[2] = { 0, 88 };

    void *func_00142730(void *self, const char *token) {
        (void)self; (void)token;
        s_142730_called++;
        return s_sym_ret;
    }

    int func_00143020(TacticalAI2 *self, int a1);
}

static void init_ctype_table() {
    memset(D_48E100, 0, sizeof(D_48E100));
    for (int d = '0'; d <= '9'; d++) {
        D_48E100[d + 1] = 4;
    }
}

static void reset_mocks() {
    s_142980_called = 0;
    s_142980_idx = 0;
    s_144340_called = 0;
    s_144340_last_code = 0;
    s_144340_last_param = 0;
    s_26b0a0_called = 0;
    s_find_tag1 = 0;
    s_find_tag3 = 0;
    s_142cc0_called = 0;
    s_142cc0_ret = 1;
    s_1427a0_called = 0;
    s_1427a0_ret = 1;
    s_1446a0_called = 0;
    s_1446a0_param_count = 2;
    s_114378_called = 0;
    s_142730_called = 0;
}

static void test_tactical_ai_compiler_leaf_condition() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    char dummy_nodes[256];
    memset(dummy_nodes, 0, sizeof(dummy_nodes));
    ai.field_10 = dummy_nodes;
    ai.field_40 = 0;

    // Token 0: "greater-than" (tag 3, cond_id 4)
    // Param 0: "100" (number)
    // Param 1: "sym_val" (symbol -> 88)
    s_find_tag3 = 1;
    s_1446a0_param_count = 2;

    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "greater-than";
    s_142980_statuses[1] = 2; s_142980_types[1] = 1; s_142980_tokens[1] = "100";
    s_142980_statuses[2] = 2; s_142980_types[2] = 1; s_142980_tokens[2] = "sym_val";

    int res = func_00143020(&ai, 1); // a1 = 1 (top-level expression, no leading '(')

    assert(res == 1);
    assert(s_142980_called == 3);
    assert(s_1446a0_called == 1);
    assert(s_114378_called == 1);
    assert(s_142730_called == 1);
    assert(s_1427a0_called == 1);

    // Verify written predicate at 0x4C
    short *pred = (short*)((char*)&ai + 0x4C);
    assert(pred[0] == 3); // type 3
    assert(pred[1] == 4); // cond_id 4
    int *params = (int*)((char*)&ai + 0x50);
    assert(params[0] == 100);
    assert(params[1] == 88);

    // End of leaf condition test
    printf("TACTICAL_AI_COMPILER_TEST_0_LEAF_PASSED\n");
}

static void test_tactical_ai_compiler_connective_unary() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    char dummy_nodes[256];
    memset(dummy_nodes, 0, sizeof(dummy_nodes));
    ai.field_10 = dummy_nodes;
    ai.field_40 = 0;

    // Connective "not": tag 1, op = 0 (unary)
    // Recurses func_00143020(self, 0):
    // Sub-token 0: '('
    // Sub-token 1: "leaf" (tag 3, 0 params)
    s_find_tag1 = 1;
    s_find_tag3 = 1;
    s_tag1_ret[1] = 0; // op 0 -> unary
    s_1446a0_param_count = 0;

    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "not";
    s_142980_statuses[1] = 2; s_142980_types[1] = 2; s_142980_tokens[1] = "(";
    s_142980_statuses[2] = 2; s_142980_types[2] = 1; s_142980_tokens[2] = "leaf";

    int res = func_00143020(&ai, 1);

    assert(res == 1);
    assert(s_142cc0_called == 1);
    assert(s_1427a0_called == 2);

    printf("TACTICAL_AI_COMPILER_TEST_1_CONNECTIVE_UNARY_PASSED\n");
}

static void test_tactical_ai_compiler_missing_lparen() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    // a1 == 0 requires leading '(' (field_19C == 2)
    s_142980_statuses[0] = 2;
    s_142980_types[0] = 1; // not '('

    int res = func_00143020(&ai, 0);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0xF);

    printf("TACTICAL_AI_COMPILER_TEST_2_MISSING_LPAREN_PASSED\n");
}

static void test_tactical_ai_compiler_eof_first() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_142980_statuses[0] = 1; // EOF

    int res = func_00143020(&ai, 1);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0x1A);

    printf("TACTICAL_AI_COMPILER_TEST_3_EOF_FIRST_PASSED\n");
}

static void test_tactical_ai_compiler_unknown_identifier() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_find_tag1 = 0;
    s_find_tag3 = 0; // neither tag 1 nor tag 3 found

    s_142980_statuses[0] = 2;
    s_142980_types[0] = 1;
    s_142980_tokens[0] = "bad_identifier";

    int res = func_00143020(&ai, 1);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 3);

    printf("TACTICAL_AI_COMPILER_TEST_4_UNKNOWN_IDENTIFIER_PASSED\n");
}

static void test_tactical_ai_compiler_invalid_token_type() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_142980_statuses[0] = 2;
    s_142980_types[0] = 3; // ')' instead of identifier

    int res = func_00143020(&ai, 1);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0xC);

    printf("TACTICAL_AI_COMPILER_TEST_5_INVALID_TOKEN_TYPE_PASSED\n");
}

static void test_tactical_ai_compiler_closing_fail() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    char dummy[64];
    memset(dummy, 0, sizeof(dummy));
    ai.field_10 = dummy;

    s_find_tag3 = 1;
    s_1446a0_param_count = 0;
    s_1427a0_ret = 0; // delimiter check fails

    s_142980_statuses[0] = 2;
    s_142980_types[0] = 1;
    s_142980_tokens[0] = "cond";

    int res = func_00143020(&ai, 1);

    assert(res == 0);
    assert(s_1427a0_called == 1);

    printf("TACTICAL_AI_COMPILER_TEST_6_CLOSING_FAIL_PASSED\n");
}

static void test_tactical_ai_compiler_layout() {
    assert(offsetof(TacticalAI2, field_10) == 0x10);
    assert(offsetof(TacticalAI2, field_34) == 0x34);
    assert(offsetof(TacticalAI2, field_40) == 0x40);
    assert(offsetof(TacticalAI2, field_19C) == 0x19C);
    assert(offsetof(TacticalAI2, field_1A0) == 0x1A0);

    printf("TACTICAL_AI_COMPILER_TEST_7_LAYOUT_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-7)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_tactical_ai_compiler_leaf_condition();
    else if (mode == 1) test_tactical_ai_compiler_connective_unary();
    else if (mode == 2) test_tactical_ai_compiler_missing_lparen();
    else if (mode == 3) test_tactical_ai_compiler_eof_first();
    else if (mode == 4) test_tactical_ai_compiler_unknown_identifier();
    else if (mode == 5) test_tactical_ai_compiler_invalid_token_type();
    else if (mode == 6) test_tactical_ai_compiler_closing_fail();
    else if (mode == 7) test_tactical_ai_compiler_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
