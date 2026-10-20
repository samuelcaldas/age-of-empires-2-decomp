#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct TacticalAIScoring {
    char pad_00[0x19C];
    int m_field19C;
    char pad_1A0[0x6B8 - 0x1A0];
    unsigned short *m_tokens;
    int m_token_idx;
};

extern "C" {
    char D_490E9C[8] = "\n";

    static int s_142980_called = 0;
    static int s_142980_ret = 0;

    int func_142980(void *self) {
        (void)self;
        s_142980_called++;
        return s_142980_ret;
    }

    static int s_144340_called = 0;
    static void *s_144340_last_ptr = 0;
    static int s_144340_last_code = 0;
    static int s_144340_last_param = 0;

    void func_144340(void *self, int code, int param) {
        s_144340_called++;
        s_144340_last_ptr = self;
        s_144340_last_code = code;
        s_144340_last_param = param;
    }

    static int s_11a7bc_called = 0;

    void *func_11A7BC(char *dst, const char *src) {
        s_11a7bc_called++;
        return strcat(dst, src);
    }

    static int s_21a4a0_called = 0;
    static char s_21a4a0_buf[32];

    void *func_21A4A0(int token) {
        s_21a4a0_called++;
        snprintf(s_21a4a0_buf, sizeof(s_21a4a0_buf), "TOK%d ", token);
        return s_21a4a0_buf;
    }

    int func_00142830(void *self);
    int func_001428B0(void *self, char *str);
}

static void reset_mocks() {
    s_142980_called = 0;
    s_142980_ret = 0;
    s_144340_called = 0;
    s_144340_last_ptr = 0;
    s_144340_last_code = 0;
    s_144340_last_param = 0;
    s_11a7bc_called = 0;
    s_21a4a0_called = 0;
}

static void test_tactical_ai_scoring_2830_success() {
    reset_mocks();
    TacticalAIScoring ai;
    memset(&ai, 0, sizeof(ai));
    ai.m_field19C = 1;
    s_142980_ret = 2;

    int res = func_00142830(&ai);

    assert(res == 1);
    assert(s_142980_called == 1);
    assert(s_144340_called == 0);

    assert(res == 1);

    printf("TACTICAL_AI_SCORING_TEST_0_2830_SUCCESS_PASSED\n");
}

static void test_tactical_ai_scoring_2830_invalid_19c() {
    reset_mocks();
    TacticalAIScoring ai;
    memset(&ai, 0, sizeof(ai));
    ai.m_field19C = 2; // != 1
    s_142980_ret = 2;

    int res = func_00142830(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_ptr == &ai);
    assert(s_144340_last_code == 0x10);

    printf("TACTICAL_AI_SCORING_TEST_1_2830_INVALID_19C_PASSED\n");
}

static void test_tactical_ai_scoring_2830_res_1() {
    reset_mocks();
    TacticalAIScoring ai;
    memset(&ai, 0, sizeof(ai));
    s_142980_ret = 1;

    int res = func_00142830(&ai);

    assert(res == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_code == 0x1A);

    printf("TACTICAL_AI_SCORING_TEST_2_2830_RES_1_PASSED\n");
}

static void test_tactical_ai_scoring_2830_res_0() {
    reset_mocks();
    TacticalAIScoring ai;
    memset(&ai, 0, sizeof(ai));
    s_142980_ret = 0;

    int res = func_00142830(&ai);

    assert(res == 0);
    assert(s_144340_called == 0);

    printf("TACTICAL_AI_SCORING_TEST_3_2830_RES_0_PASSED\n");
}

static void test_tactical_ai_scoring_28b0_newline() {
    reset_mocks();
    TacticalAIScoring ai;
    memset(&ai, 0, sizeof(ai));

    unsigned short tokens[2] = { 0xFFFE, 0xFFFF };
    ai.m_tokens = tokens;
    ai.m_token_idx = 0;

    char out_str[64];
    memset(out_str, 0xAA, sizeof(out_str));

    int res = func_001428B0(&ai, out_str);

    assert(res == 1);
    assert(strcmp(out_str, "\n") == 0);
    assert(ai.m_token_idx == 1);

    printf("TACTICAL_AI_SCORING_TEST_4_28B0_NEWLINE_PASSED\n");
}

static void test_tactical_ai_scoring_28b0_words_and_newline() {
    reset_mocks();
    TacticalAIScoring ai;
    memset(&ai, 0, sizeof(ai));

    unsigned short tokens[4] = { 10, 20, 0xFFFE, 0xFFFF };
    ai.m_tokens = tokens;
    ai.m_token_idx = 0;

    char out_str[128];
    memset(out_str, 0, sizeof(out_str));

    int res = func_001428B0(&ai, out_str);

    assert(res == 1);
    assert(strcmp(out_str, "TOK10 TOK20 \n") == 0);
    assert(ai.m_token_idx == 3);
    assert(s_21a4a0_called == 2);

    printf("TACTICAL_AI_SCORING_TEST_5_28B0_WORDS_AND_NEWLINE_PASSED\n");
}

static void test_tactical_ai_scoring_28b0_eof() {
    reset_mocks();
    TacticalAIScoring ai;
    memset(&ai, 0, sizeof(ai));

    unsigned short tokens[1] = { 0xFFFF };
    ai.m_tokens = tokens;
    ai.m_token_idx = 0;

    char out_str[64];
    memset(out_str, 0xBB, sizeof(out_str));

    int res = func_001428B0(&ai, out_str);

    assert(res == 0);
    assert(out_str[0] == 0);
    assert(ai.m_token_idx == 0);

    printf("TACTICAL_AI_SCORING_TEST_6_28B0_EOF_PASSED\n");
}

static void test_tactical_ai_scoring_layout() {
    assert(offsetof(TacticalAIScoring, m_field19C) == 0x19C);
    assert(offsetof(TacticalAIScoring, m_tokens) == 0x6B8);
    assert(offsetof(TacticalAIScoring, m_token_idx) == 0x6BC);

    printf("TACTICAL_AI_SCORING_TEST_7_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_scoring_2830_success();
    else if (mode == 1) test_tactical_ai_scoring_2830_invalid_19c();
    else if (mode == 2) test_tactical_ai_scoring_2830_res_1();
    else if (mode == 3) test_tactical_ai_scoring_2830_res_0();
    else if (mode == 4) test_tactical_ai_scoring_28b0_newline();
    else if (mode == 5) test_tactical_ai_scoring_28b0_words_and_newline();
    else if (mode == 6) test_tactical_ai_scoring_28b0_eof();
    else if (mode == 7) test_tactical_ai_scoring_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
