#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Candidate {
    char pad_0[2];
    short field_2;
};

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x3C];
    int field_40;
    char field_44[5];
    char field_49;
    char pad_4A[0x142];
    int field_18C;
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    char field_1A0[0x100];
};

extern "C" {
    char D_490EA0[16] = "load";
    char D_490EA8[16] = "load-random";
    char D_490EB8[16] = "defrule";
    char D_490EC0[16] = "defconst";
    char D_48E101[258] = { 0 };

    static int s_142980_called = 0;
    static int s_142980_statuses[8] = { 2 };
    static int s_142980_types[8] = { 1 };
    static const char *s_142980_tokens[8] = { "load" };
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
    static int s_144340_last_code = 0;
    static void *s_144340_last_param = 0;

    void func_144340(void *self, int code, void *param) {
        (void)self;
        s_144340_called++;
        s_144340_last_code = code;
        s_144340_last_param = param;
    }

    int func_0011AA78(const char *s1, const char *s2) {
        return strcmp(s1, s2);
    }

    char *func_0011ABBC(char *dst, const char *src) {
        return strcpy(dst, src);
    }

    static int s_1427a0_called = 0;
    static int s_1427a0_ret = 1;

    int func_001427A0(void *self) {
        (void)self;
        s_1427a0_called++;
        return s_1427a0_ret;
    }

    static int s_1441b0_called = 0;
    void func_1441B0(void *self) { (void)self; s_1441b0_called++; }

    static int s_142560_called = 0;
    static const char *s_142560_last_path = 0;
    static int s_142560_ret = 1;

    int func_00142560(void *self, const char *path) {
        (void)self;
        s_142560_called++;
        s_142560_last_path = path;
        return s_142560_ret;
    }

    static int s_144050_called = 0;
    void func_144050(void *self) { (void)self; s_144050_called++; }

    static int s_143ad0_called = 0;
    static int s_143ad0_ret = 1;

    int func_143AD0(void *self) {
        (void)self;
        s_143ad0_called++;
        return s_143ad0_ret;
    }

    static int s_145740_called = 0;
    static int s_145740_ret = 55;

    int func_145740(void *sub) {
        (void)sub;
        s_145740_called++;
        return s_145740_ret;
    }

    static int s_143e00_called = 0;
    static int s_143e00_ret = 1;

    int func_143E00(void *self) {
        (void)self;
        s_143e00_called++;
        return s_143e00_ret;
    }

    static int s_141250_called = 0;
    static int s_141250_ret = 1;

    int func_00141250(void *self, int a1, int a2, void *sub) {
        (void)self; (void)a1; (void)a2; (void)sub;
        s_141250_called++;
        return s_141250_ret;
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
        s_sym_ret.field_2 = 99;
        return &s_sym_ret;
    }

    static int s_142130_called = 0;
    static int s_142130_ret = 1;

    int func_00142130(void *self, int a1, const char *name, int val) {
        (void)self; (void)a1; (void)name; (void)val;
        s_142130_called++;
        return s_142130_ret;
    }

    int func_143440(TacticalAI2 *self);
}

static void init_ctype_table() {
    memset(D_48E101, 0, sizeof(D_48E101));
    for (int d = '0'; d <= '9'; d++) {
        D_48E101[d] = 4;
    }
}

static void reset_mocks() {
    s_142980_called = 0;
    s_142980_idx = 0;
    s_144340_called = 0;
    s_144340_last_code = 0;
    s_144340_last_param = 0;
    s_1427a0_called = 0;
    s_1427a0_ret = 1;
    s_1441b0_called = 0;
    s_142560_called = 0;
    s_142560_last_path = 0;
    s_142560_ret = 1;
    s_144050_called = 0;
    s_143ad0_called = 0;
    s_143ad0_ret = 1;
    s_145740_called = 0;
    s_145740_ret = 55;
    s_143e00_called = 0;
    s_143e00_ret = 1;
    s_141250_called = 0;
    s_141250_ret = 1;
    s_114378_called = 0;
    s_142730_called = 0;
    s_sym_found = 1;
    s_142130_called = 0;
    s_142130_ret = 1;
}

static void test_tactical_ai_analyzer_load() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    // Token 0: "load" (type 1)
    // Token 1: "script.per" (type 4, string)
    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "load";
    s_142980_statuses[1] = 2; s_142980_types[1] = 4; s_142980_tokens[1] = "script.per";

    int res = func_143440(&ai);

    assert(res == 1);
    assert(s_142980_called == 2);
    assert(s_1427a0_called == 1);
    assert(s_1441b0_called == 1);
    assert(s_142560_called == 1);
    assert(s_144050_called == 1);

    // End of test_tactical_ai_analyzer_load

    printf("TACTICAL_AI_ANALYZER_TEST_0_LOAD_PASSED\n");
}

static void test_tactical_ai_analyzer_load_random() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "load-random";

    int res = func_143440(&ai);

    assert(res == 1);
    assert(s_143ad0_called == 1);

    printf("TACTICAL_AI_ANALYZER_TEST_1_LOAD_RANDOM_PASSED\n");
}

static void test_tactical_ai_analyzer_defrule() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_198 = 1;
    ai.field_190 = 2;

    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "defrule";

    int res = func_143440(&ai);

    assert(res == 1);
    assert(ai.field_40 == 0);
    assert(s_145740_called == 1);
    assert(ai.field_18C == 55);
    assert(s_143e00_called == 1);
    assert(ai.field_194 == 1);
    assert(ai.field_49 == 1);
    assert(s_141250_called == 1);

    printf("TACTICAL_AI_ANALYZER_TEST_2_DEFRULE_PASSED\n");
}

static void test_tactical_ai_analyzer_defconst_int() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_198 = 1;
    ai.field_190 = 3;

    // Token 0: "defconst" (type 1)
    // Token 1: "my_const" (type 1)
    // Token 2: "500" (type 1, number)
    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "defconst";
    s_142980_statuses[1] = 2; s_142980_types[1] = 1; s_142980_tokens[1] = "my_const";
    s_142980_statuses[2] = 2; s_142980_types[2] = 1; s_142980_tokens[2] = "500";

    int res = func_143440(&ai);

    assert(res == 1);
    assert(s_114378_called == 1);
    assert(s_1427a0_called == 1);
    assert(s_142130_called == 1);

    printf("TACTICAL_AI_ANALYZER_TEST_3_DEFCONST_INT_PASSED\n");
}

static void test_tactical_ai_analyzer_defconst_sym() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_198 = 1;
    ai.field_190 = 3;

    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "defconst";
    s_142980_statuses[1] = 2; s_142980_types[1] = 1; s_142980_tokens[1] = "my_const";
    s_142980_statuses[2] = 2; s_142980_types[2] = 1; s_142980_tokens[2] = "other_const";

    int res = func_143440(&ai);

    assert(res == 1);
    assert(s_142730_called == 1);
    assert(s_1427a0_called == 1);
    assert(s_142130_called == 1);

    printf("TACTICAL_AI_ANALYZER_TEST_4_DEFCONST_SYM_PASSED\n");
}

static void test_tactical_ai_analyzer_unknown_keyword() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "bad_keyword";

    int res = func_143440(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 4);

    printf("TACTICAL_AI_ANALYZER_TEST_5_UNKNOWN_KEYWORD_PASSED\n");
}

static void test_tactical_ai_analyzer_first_eof() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_142980_statuses[0] = 1; // EOF

    int res = func_143440(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0x1A);

    printf("TACTICAL_AI_ANALYZER_TEST_6_FIRST_EOF_PASSED\n");
}

static void test_tactical_ai_analyzer_first_not_ident() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_142980_statuses[0] = 2; s_142980_types[0] = 2; // '(' instead of identifier

    int res = func_143440(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0xD);

    printf("TACTICAL_AI_ANALYZER_TEST_7_FIRST_NOT_IDENT_PASSED\n");
}

static void test_tactical_ai_analyzer_defrule_link_fail() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_198 = 1;

    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "defrule";
    s_141250_ret = -1; // link failure

    int res = func_143440(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 6);

    printf("TACTICAL_AI_ANALYZER_TEST_8_DEFRULE_LINK_FAIL_PASSED\n");
}

static void test_tactical_ai_analyzer_layout() {
    assert(offsetof(TacticalAI2, field_40) == 0x40);
    assert(offsetof(TacticalAI2, field_44) == 0x44);
    assert(offsetof(TacticalAI2, field_49) == 0x49);
    assert(offsetof(TacticalAI2, field_18C) == 0x18C);
    assert(offsetof(TacticalAI2, field_190) == 0x190);
    assert(offsetof(TacticalAI2, field_194) == 0x194);
    assert(offsetof(TacticalAI2, field_198) == 0x198);
    assert(offsetof(TacticalAI2, field_19C) == 0x19C);
    assert(offsetof(TacticalAI2, field_1A0) == 0x1A0);

    printf("TACTICAL_AI_ANALYZER_TEST_9_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_analyzer_load();
    else if (mode == 1) test_tactical_ai_analyzer_load_random();
    else if (mode == 2) test_tactical_ai_analyzer_defrule();
    else if (mode == 3) test_tactical_ai_analyzer_defconst_int();
    else if (mode == 4) test_tactical_ai_analyzer_defconst_sym();
    else if (mode == 5) test_tactical_ai_analyzer_unknown_keyword();
    else if (mode == 6) test_tactical_ai_analyzer_first_eof();
    else if (mode == 7) test_tactical_ai_analyzer_first_not_ident();
    else if (mode == 8) test_tactical_ai_analyzer_defrule_link_fail();
    else if (mode == 9) test_tactical_ai_analyzer_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
