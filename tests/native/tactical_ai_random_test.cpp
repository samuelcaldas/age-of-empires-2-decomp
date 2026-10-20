#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x198];
    int field_19C;
    char field_1A0[0x100];
};

extern "C" {
    char D_48E100[258] = { 0 };

    static int s_call_seq = 0;
    static int s_1aab30_called = 0;
    static int s_1aab30_seq = 0;
    static int s_1aab30_ret = 0;

    int func_1AAB30(void) {
        s_1aab30_called++;
        s_1aab30_seq = ++s_call_seq;
        return s_1aab30_ret;
    }

    static int s_142980_called = 0;
    static int s_142980_seq = 0;
    static int s_142980_statuses[16] = { 2 };
    static int s_142980_types[16] = { 4 };
    static const char *s_142980_tokens[16] = { "script.per" };
    static int s_142980_idx = 0;

    int func_142980(void *self) {
        TacticalAI2 *ai = (TacticalAI2*)self;
        s_142980_called++;
        if (s_142980_called == 1) {
            s_142980_seq = ++s_call_seq;
        }
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

    static int s_114378_called = 0;

    int func_114378(const char *str) {
        s_114378_called++;
        return atoi(str);
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
    static char s_142560_last_path[256] = {0};
    static int s_142560_ret = 1;

    int func_00142560(void *self, const char *path) {
        (void)self;
        s_142560_called++;
        if (path) strcpy(s_142560_last_path, path);
        return s_142560_ret;
    }

    static int s_144050_called = 0;
    void func_144050(void *self) { (void)self; s_144050_called++; }

    int func_143AD0(TacticalAI2 *self);
}

static void init_ctype_table() {
    memset(D_48E100, 0, sizeof(D_48E100));
    for (int d = '0'; d <= '9'; d++) {
        D_48E100[d + 1] = 4;
    }
}

static void reset_mocks() {
    s_call_seq = 0;
    s_1aab30_called = 0;
    s_1aab30_seq = 0;
    s_1aab30_ret = 0;
    s_142980_called = 0;
    s_142980_seq = 0;
    s_142980_idx = 0;
    s_144340_called = 0;
    s_144340_last_code = 0;
    s_144340_last_param = 0;
    s_114378_called = 0;
    s_1427a0_called = 0;
    s_1427a0_ret = 1;
    s_1441b0_called = 0;
    s_142560_called = 0;
    memset(s_142560_last_path, 0, sizeof(s_142560_last_path));
    s_142560_ret = 1;
    s_144050_called = 0;
}

static void test_tactical_ai_random_state0_file() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    // Token 0: string literal "main.per" (type 4)
    s_142980_statuses[0] = 2; s_142980_types[0] = 4; s_142980_tokens[0] = "main.per";

    int res = func_143AD0(&ai);

    assert(s_1aab30_seq == 1); // ELF: func_1AAB30 (RNG) called first to establish target_weight
    assert(s_142980_seq == 2); // ELF: func_142980 (scanner) called second
    assert(res == 1);
    assert(s_1427a0_called == 1);
    assert(s_1441b0_called == 1);
    assert(s_142560_called == 1);
    assert(strcmp(s_142560_last_path, "main.per") == 0);
    assert(s_144050_called == 1);

    // End of test_tactical_ai_random_state0_file

    printf("TACTICAL_AI_RANDOM_TEST_0_STATE0_FILE_PASSED\n");
}

static void test_tactical_ai_random_weighted_hit() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_1aab30_ret = 29; // target_weight = (29 % 100) + 1 = 30
    // Token 0: weight 50 (type 1) -> accum = 50 >= 30 -> selected!
    // Token 1: "ai1.per" (type 4)
    // Token 2: ')' (type 3) -> ends
    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "50";
    s_142980_statuses[1] = 2; s_142980_types[1] = 4; s_142980_tokens[1] = "ai1.per";
    s_142980_statuses[2] = 2; s_142980_types[2] = 3; s_142980_tokens[2] = ")";

    int res = func_143AD0(&ai);

    assert(res == 1);
    assert(s_142560_called == 1);
    assert(strcmp(s_142560_last_path, "ai1.per") == 0);

    printf("TACTICAL_AI_RANDOM_TEST_1_WEIGHTED_HIT_PASSED\n");
}

static void test_tactical_ai_random_multi_weighted() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_1aab30_ret = 74; // target_weight = 75
    // Choice 1: weight 40, "first.per" -> accum 40 < 75 -> skipped
    // Choice 2: weight 40, "second.per" -> accum 80 >= 75 -> loaded!
    // Token 4: ')'
    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "40";
    s_142980_statuses[1] = 2; s_142980_types[1] = 4; s_142980_tokens[1] = "first.per";
    s_142980_statuses[2] = 2; s_142980_types[2] = 1; s_142980_tokens[2] = "40";
    s_142980_statuses[3] = 2; s_142980_types[3] = 4; s_142980_tokens[3] = "second.per";
    s_142980_statuses[4] = 2; s_142980_types[4] = 3; s_142980_tokens[4] = ")";

    int res = func_143AD0(&ai);

    assert(res == 1);
    assert(s_142560_called == 1);
    assert(strcmp(s_142560_last_path, "second.per") == 0);

    printf("TACTICAL_AI_RANDOM_TEST_2_MULTI_WEIGHTED_PASSED\n");
}

static void test_tactical_ai_random_fallback_loaded() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_1aab30_ret = 89; // target_weight = 90
    // Choice 1: weight 30, "w1.per" -> accum 30 < 90
    // Choice 2: fallback "fallback.per" (type 4 without preceding weight)
    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "30";
    s_142980_statuses[1] = 2; s_142980_types[1] = 4; s_142980_tokens[1] = "w1.per";
    s_142980_statuses[2] = 2; s_142980_types[2] = 4; s_142980_tokens[2] = "fallback.per";

    int res = func_143AD0(&ai);

    assert(res == 1);
    assert(s_142560_called == 1);
    assert(strcmp(s_142560_last_path, "fallback.per") == 0);

    printf("TACTICAL_AI_RANDOM_TEST_3_FALLBACK_LOADED_PASSED\n");
}

static void test_tactical_ai_random_fallback_ignored_if_loaded() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_1aab30_ret = 19; // target_weight = 20
    // Choice 1: weight 50, "picked.per" -> loaded!
    // Choice 2: fallback "ignored.per"
    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "50";
    s_142980_statuses[1] = 2; s_142980_types[1] = 4; s_142980_tokens[1] = "picked.per";
    s_142980_statuses[2] = 2; s_142980_types[2] = 4; s_142980_tokens[2] = "ignored.per";

    int res = func_143AD0(&ai);

    assert(res == 1);
    assert(s_142560_called == 1);
    assert(strcmp(s_142560_last_path, "picked.per") == 0); // only picked was loaded

    printf("TACTICAL_AI_RANDOM_TEST_4_FALLBACK_IGNORED_PASSED\n");
}

static void test_tactical_ai_random_state0_invalid_tok() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    // Token: '(' (type 2) in state 0 -> error
    s_142980_statuses[0] = 2; s_142980_types[0] = 2;

    int res = func_143AD0(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0xC);

    printf("TACTICAL_AI_RANDOM_TEST_5_STATE0_INVALID_TOK_PASSED\n");
}

static void test_tactical_ai_random_state1_expected_string() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    // Token 0: weight "50" -> state 1
    // Token 1: number "20" (type 1) instead of string -> error
    s_142980_statuses[0] = 2; s_142980_types[0] = 1; s_142980_tokens[0] = "50";
    s_142980_statuses[1] = 2; s_142980_types[1] = 1; s_142980_tokens[1] = "20";

    int res = func_143AD0(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0xC);

    printf("TACTICAL_AI_RANDOM_TEST_6_STATE1_EXPECTED_STRING_PASSED\n");
}

static void test_tactical_ai_random_eof() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_142980_statuses[0] = 1; // EOF

    int res = func_143AD0(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0x1A);

    printf("TACTICAL_AI_RANDOM_TEST_7_EOF_PASSED\n");
}

static void test_tactical_ai_random_err() {
    init_ctype_table();
    reset_mocks();

    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    s_142980_statuses[0] = 0; // syntax error

    int res = func_143AD0(&ai);

    assert(res == 0);
    assert(s_144340_called == 0);

    printf("TACTICAL_AI_RANDOM_TEST_8_ERR_PASSED\n");
}

static void test_tactical_ai_random_layout() {
    assert(offsetof(TacticalAI2, field_19C) == 0x19C);
    assert(offsetof(TacticalAI2, field_1A0) == 0x1A0);

    printf("TACTICAL_AI_RANDOM_TEST_9_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_random_state0_file();
    else if (mode == 1) test_tactical_ai_random_weighted_hit();
    else if (mode == 2) test_tactical_ai_random_multi_weighted();
    else if (mode == 3) test_tactical_ai_random_fallback_loaded();
    else if (mode == 4) test_tactical_ai_random_fallback_ignored_if_loaded();
    else if (mode == 5) test_tactical_ai_random_state0_invalid_tok();
    else if (mode == 6) test_tactical_ai_random_state1_expected_string();
    else if (mode == 7) test_tactical_ai_random_eof();
    else if (mode == 8) test_tactical_ai_random_err();
    else if (mode == 9) test_tactical_ai_random_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
