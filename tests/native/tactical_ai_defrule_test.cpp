#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x3C];
    unsigned char field_40;
    char pad_41[0x9];
    char field_4A;
    char field_4B;
    char pad_4C[0x140];
    int field_18C;
    char pad_190[0x4];
    int field_194;
    int field_198;
    int field_19C;
    char field_1A0[0x100];
};

extern "C" {
    char D_48E100[258] = { 0 };
    char D_490F18[8] = "=>";

    static int s_142980_called = 0;
    static int s_142980_statuses[16] = { 2 };
    static int s_142980_types[16] = { 1 };
    static const char *s_142980_tokens[16] = { "rule_name" };
    static int s_142980_idx = 0;

    int func_142980(void *ptr) {
        TacticalAI2 *ai = (TacticalAI2*)ptr;
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
    static int s_144340_last_a1 = 0;

    void func_144340(void *ptr, int a1, int a2) {
        (void)ptr; (void)a2;
        s_144340_called++;
        s_144340_last_a1 = a1;
    }

    static int s_2680_called = 0;
    static int s_2680_ret = 77;

    int func_00142680(void *self, void *buf) {
        (void)self; (void)buf;
        s_2680_called++;
        return s_2680_ret;
    }

    static int s_2cc0_called = 0;
    static int s_2cc0_ret = 1;

    int func_00142CC0(void *self) {
        (void)self;
        s_2cc0_called++;
        return s_2cc0_ret;
    }

    static int s_3020_called = 0;
    static int s_3020_ret = 1;

    int func_00143020(void *self, int a1) {
        (void)self; (void)a1;
        s_3020_called++;
        return s_3020_ret;
    }

    int func_0011AA78(const char *s1, const char *s2) {
        return strcmp(s1, s2);
    }

    static int s_2d10_called = 0;
    static int s_2d10_ret = 1;

    int func_00142D10(void *self) {
        (void)self;
        s_2d10_called++;
        return s_2d10_ret;
    }

    int func_143E00(TacticalAI2 *self);
}

static void init_ctype_table() {
    memset(D_48E100, 0, sizeof(D_48E100));
    // D_48E100[ch + 1] & 3 is non-zero for letters (alpha)
    for (int c = 'a'; c <= 'z'; c++) D_48E100[c + 1] = 2;
    for (int c = 'A'; c <= 'Z'; c++) D_48E100[c + 1] = 1;
}

static void reset_mocks() {
    s_142980_called = 0;
    s_142980_idx = 0;
    s_144340_called = 0;
    s_144340_last_a1 = 0;
    s_2680_called = 0;
    s_2680_ret = 77;
    s_2cc0_called = 0;
    s_2cc0_ret = 1;
    s_3020_called = 0;
    s_3020_ret = 1;
    s_2d10_called = 0;
    s_2d10_ret = 1;
}

static void test_tactical_ai_defrule_success() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_198 = 1;
    ai.field_40 = 2;

    // Sequence:
    // 0: "my_rule" (type 1) -> rule id lookup
    // 1: "(" (type 2) -> condition 1
    // 2: "=>" (type 1) -> arrow
    // 3: "(" (type 2) -> action 1
    // 4: ")" (type 3) -> close
    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "my_rule";
    s_142980_statuses[1] = 2; s_142980_types[1] = 1; s_142980_tokens[1] = "=>";
    s_142980_statuses[2] = 2; s_142980_types[2] = 2; s_142980_tokens[2] = "(";
    s_142980_statuses[3] = 2; s_142980_types[3] = 3; s_142980_tokens[3] = ")";

    int res = func_143E00(&ai);

    assert(res == 1);
    assert(s_2680_called == 1);
    assert(ai.field_18C == 77);
    assert(s_3020_called == 1);
    assert(s_2d10_called == 1);
    assert(ai.field_4A == 3); // field_40 + 1
    assert(ai.field_4B == 3);

    // End of test_tactical_ai_defrule_success

    printf("TACTICAL_AI_DEFRULE_TEST_0_SUCCESS_PASSED\n");
}

static void test_tactical_ai_defrule_no_name() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_40 = 0;

    // Directly starts with condition
    s_142980_statuses[0] = 2; s_142980_types[0] = 2; s_142980_tokens[0] = "(";
    s_142980_statuses[1] = 2; s_142980_types[1] = 1; s_142980_tokens[1] = "=>";
    s_142980_statuses[2] = 2; s_142980_types[2] = 2; s_142980_tokens[2] = "(";
    s_142980_statuses[3] = 2; s_142980_types[3] = 3; s_142980_tokens[3] = ")";

    int res = func_143E00(&ai);

    assert(res == 1);
    assert(s_2680_called == 0); // no rule name lookup
    assert(s_3020_called == 1);
    assert(s_2d10_called == 1);

    printf("TACTICAL_AI_DEFRULE_TEST_1_NO_NAME_PASSED\n");
}

static void test_tactical_ai_defrule_multiple_items() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    // 2 conditions, 2 actions
    s_142980_statuses[0] = 2; s_142980_types[0] = 2; s_142980_tokens[0] = "("; // cond 1
    s_142980_statuses[1] = 2; s_142980_types[1] = 2; s_142980_tokens[1] = "("; // cond 2
    s_142980_statuses[2] = 2; s_142980_types[2] = 1; s_142980_tokens[2] = "=>";
    s_142980_statuses[3] = 2; s_142980_types[3] = 2; s_142980_tokens[3] = "("; // act 1
    s_142980_statuses[4] = 2; s_142980_types[4] = 2; s_142980_tokens[4] = "("; // act 2
    s_142980_statuses[5] = 2; s_142980_types[5] = 3; s_142980_tokens[5] = ")"; // close

    int res = func_143E00(&ai);

    assert(res == 1);
    assert(s_3020_called == 2);
    assert(s_2d10_called == 2);
    assert(s_2cc0_called == 3); // 1 for 2nd cond, 2 for 2 actions

    printf("TACTICAL_AI_DEFRULE_TEST_2_MULTIPLE_ITEMS_PASSED\n");
}

static void test_tactical_ai_defrule_missing_cond_before_arrow() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    // Arrow immediately without condition
    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "=>";

    int res = func_143E00(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_a1 == 0xE);

    printf("TACTICAL_AI_DEFRULE_TEST_3_MISSING_COND_PASSED\n");
}

static void test_tactical_ai_defrule_invalid_arrow() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    // Condition 1 followed by non-arrow token
    s_142980_statuses[0] = 2; s_142980_types[0] = 2; s_142980_tokens[0] = "(";
    s_142980_statuses[1] = 2; s_142980_types[1] = 1; s_142980_tokens[1] = "bad_arrow";

    int res = func_143E00(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_a1 == 7);

    printf("TACTICAL_AI_DEFRULE_TEST_4_INVALID_ARROW_PASSED\n");
}

static void test_tactical_ai_defrule_cond_fail() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_142980_statuses[0] = 2; s_142980_types[0] = 2; s_142980_tokens[0] = "(";
    s_3020_ret = 0; // cond compile fails

    int res = func_143E00(&ai);

    assert(res == 0);

    printf("TACTICAL_AI_DEFRULE_TEST_5_COND_FAIL_PASSED\n");
}

static void test_tactical_ai_defrule_missing_action() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    // Condition -> Arrow -> Closing ')' without action
    s_142980_statuses[0] = 2; s_142980_types[0] = 2; s_142980_tokens[0] = "(";
    s_142980_statuses[1] = 2; s_142980_types[1] = 1; s_142980_tokens[1] = "=>";
    s_142980_statuses[2] = 2; s_142980_types[2] = 3; s_142980_tokens[2] = ")";

    int res = func_143E00(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_a1 == 0x11);

    printf("TACTICAL_AI_DEFRULE_TEST_6_MISSING_ACTION_PASSED\n");
}

static void test_tactical_ai_defrule_action_fail() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_142980_statuses[0] = 2; s_142980_types[0] = 2; s_142980_tokens[0] = "(";
    s_142980_statuses[1] = 2; s_142980_types[1] = 1; s_142980_tokens[1] = "=>";
    s_142980_statuses[2] = 2; s_142980_types[2] = 2; s_142980_tokens[2] = "(";
    s_2d10_ret = 0; // action parse fails

    int res = func_143E00(&ai);

    assert(res == 0);

    printf("TACTICAL_AI_DEFRULE_TEST_7_ACTION_FAIL_PASSED\n");
}

static void test_tactical_ai_defrule_missing_close_paren() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    // Condition -> Arrow -> Action -> token that is not ')'
    s_142980_statuses[0] = 2; s_142980_types[0] = 2; s_142980_tokens[0] = "(";
    s_142980_statuses[1] = 2; s_142980_types[1] = 1; s_142980_tokens[1] = "=>";
    s_142980_statuses[2] = 2; s_142980_types[2] = 2; s_142980_tokens[2] = "(";
    s_142980_statuses[3] = 2; s_142980_types[3] = 1; s_142980_tokens[3] = "bad_end";

    int res = func_143E00(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_a1 == 8);

    printf("TACTICAL_AI_DEFRULE_TEST_8_MISSING_CLOSE_PAREN_PASSED\n");
}

static void test_tactical_ai_defrule_layout() {
    assert(offsetof(TacticalAI2, field_40) == 0x40);
    assert(offsetof(TacticalAI2, field_4A) == 0x4A);
    assert(offsetof(TacticalAI2, field_4B) == 0x4B);
    assert(offsetof(TacticalAI2, field_18C) == 0x18C);
    assert(offsetof(TacticalAI2, field_198) == 0x198);
    assert(offsetof(TacticalAI2, field_19C) == 0x19C);
    assert(offsetof(TacticalAI2, field_1A0) == 0x1A0);

    printf("TACTICAL_AI_DEFRULE_TEST_9_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_defrule_success();
    else if (mode == 1) test_tactical_ai_defrule_no_name();
    else if (mode == 2) test_tactical_ai_defrule_multiple_items();
    else if (mode == 3) test_tactical_ai_defrule_missing_cond_before_arrow();
    else if (mode == 4) test_tactical_ai_defrule_invalid_arrow();
    else if (mode == 5) test_tactical_ai_defrule_cond_fail();
    else if (mode == 6) test_tactical_ai_defrule_missing_action();
    else if (mode == 7) test_tactical_ai_defrule_action_fail();
    else if (mode == 8) test_tactical_ai_defrule_missing_close_paren();
    else if (mode == 9) test_tactical_ai_defrule_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
