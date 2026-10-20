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
    char *field_2A0;
    char pad_2A4[4];
    char field_2A8[0x400];
    char *field_6A8;
    char pad_6AC[4];
    int field_6B0;
};

extern "C" {
    static int s_28b0_called = 0;
    static void *s_28b0_last_self = 0;
    static char *s_28b0_last_buf = 0;
    static const char *s_28b0_refill_str = 0;
    static int s_28b0_ret = 1;

    int func_001428B0(TacticalAI2 *self, char *buf) {
        s_28b0_called++;
        s_28b0_last_self = self;
        s_28b0_last_buf = buf;
        if (s_28b0_refill_str) {
            strcpy(buf, s_28b0_refill_str);
        }
        return s_28b0_ret;
    }

    static int s_144340_called = 0;
    static void *s_144340_last_self = 0;
    static int s_144340_last_a1 = 0;
    static int s_144340_last_a2 = 0;

    void func_144340(TacticalAI2 *self, int a1, int a2) {
        s_144340_called++;
        s_144340_last_self = self;
        s_144340_last_a1 = a1;
        s_144340_last_a2 = a2;
    }

    int func_142980(TacticalAI2 *self);
}

static void reset_mocks() {
    s_28b0_called = 0;
    s_28b0_last_self = 0;
    s_28b0_last_buf = 0;
    s_28b0_refill_str = 0;
    s_28b0_ret = 1;

    s_144340_called = 0;
    s_144340_last_self = 0;
    s_144340_last_a1 = 0;
    s_144340_last_a2 = 0;
}

static void test_tactical_ai_scanner_identifier() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    char input[] = "defrule my_rule (";
    ai.field_6A8 = input;

    int tok = func_142980(&ai);

    assert(tok == 2);
    assert(ai.field_19C == 1);
    assert(strcmp(ai.field_1A0, "defrule") == 0);
    assert(*ai.field_6A8 == 'm'); // advanced past space

    assert(ai.field_19C == 1);

    printf("TACTICAL_AI_SCANNER_TEST_0_IDENTIFIER_PASSED\n");
}

static void test_tactical_ai_scanner_lparen() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    char input[] = "  (foo";
    ai.field_6A8 = input;

    int tok = func_142980(&ai);

    assert(tok == 2);
    assert(ai.field_19C == 2);
    assert(strcmp(ai.field_1A0, "(") == 0);
    assert(*ai.field_6A8 == 'f');

    printf("TACTICAL_AI_SCANNER_TEST_1_LPAREN_PASSED\n");
}

static void test_tactical_ai_scanner_rparen() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    char input[] = " ) bar";
    ai.field_6A8 = input;

    int tok = func_142980(&ai);

    assert(tok == 2);
    assert(ai.field_19C == 3);
    assert(strcmp(ai.field_1A0, ")") == 0);
    assert(*ai.field_6A8 == ' ');

    printf("TACTICAL_AI_SCANNER_TEST_2_RPAREN_PASSED\n");
}

static void test_tactical_ai_scanner_quote() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    char input[] = " \"hello world\" end";
    ai.field_6A8 = input;

    int tok = func_142980(&ai);

    assert(tok == 2);
    assert(ai.field_19C == 4);
    assert(strcmp(ai.field_1A0, "hello world") == 0);
    assert(*ai.field_6A8 == ' ');

    printf("TACTICAL_AI_SCANNER_TEST_3_QUOTE_PASSED\n");
}

static void test_tactical_ai_scanner_quote_err_nl() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    char input[] = "\"unterminated\nnewline";
    ai.field_6A8 = input;

    int tok = func_142980(&ai);

    assert(tok == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_self == &ai);
    assert(s_144340_last_a1 == 9);

    printf("TACTICAL_AI_SCANNER_TEST_4_QUOTE_ERR_NL_PASSED\n");
}

static void test_tactical_ai_scanner_quote_err_eof() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    char input[] = "\"unterminated_eof";
    ai.field_6A8 = input;

    int tok = func_142980(&ai);

    assert(tok == 0);
    assert(s_144340_called == 1);
    assert(s_144340_last_self == &ai);
    assert(s_144340_last_a1 == 9);

    printf("TACTICAL_AI_SCANNER_TEST_5_QUOTE_ERR_EOF_PASSED\n");
}

static void test_tactical_ai_scanner_comment_refill() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    char input[] = "; this is a comment";
    ai.field_6A8 = input;
    s_28b0_refill_str = "next_line_token";
    s_28b0_ret = 1;

    int tok = func_142980(&ai);

    assert(tok == 2);
    assert(ai.field_6B0 == 1);
    assert(s_28b0_called == 1);
    assert(s_28b0_last_buf == ai.field_2A8);
    assert(ai.field_19C == 1);
    assert(strcmp(ai.field_1A0, "next_line_token") == 0);

    printf("TACTICAL_AI_SCANNER_TEST_6_COMMENT_REFILL_PASSED\n");
}

static void test_tactical_ai_scanner_refill_eof() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    char input[] = ""; // empty line
    ai.field_6A8 = input;
    s_28b0_ret = 0;    // EOF from refill

    int tok = func_142980(&ai);

    assert(tok == 1);
    assert(ai.field_6B0 == 1);
    assert(s_28b0_called == 1);

    printf("TACTICAL_AI_SCANNER_TEST_7_REFILL_EOF_PASSED\n");
}

static void test_tactical_ai_scanner_whitespace() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    char input[] = " \t\r\n  token";
    ai.field_6A8 = input;

    int tok = func_142980(&ai);

    assert(tok == 2);
    assert(strcmp(ai.field_1A0, "token") == 0);

    printf("TACTICAL_AI_SCANNER_TEST_8_WHITESPACE_PASSED\n");
}

static void test_tactical_ai_scanner_layout() {
    assert(offsetof(TacticalAI2, field_19C) == 0x19C);
    assert(offsetof(TacticalAI2, field_1A0) == 0x1A0);
    assert(offsetof(TacticalAI2, field_2A0) == 0x2A0);
    assert(offsetof(TacticalAI2, field_2A8) == 0x2A8);
    assert(offsetof(TacticalAI2, field_6A8) == 0x6A8);
    assert(offsetof(TacticalAI2, field_6B0) == 0x6B0);

    printf("TACTICAL_AI_SCANNER_TEST_9_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_scanner_identifier();
    else if (mode == 1) test_tactical_ai_scanner_lparen();
    else if (mode == 2) test_tactical_ai_scanner_rparen();
    else if (mode == 3) test_tactical_ai_scanner_quote();
    else if (mode == 4) test_tactical_ai_scanner_quote_err_nl();
    else if (mode == 5) test_tactical_ai_scanner_quote_err_eof();
    else if (mode == 6) test_tactical_ai_scanner_comment_refill();
    else if (mode == 7) test_tactical_ai_scanner_refill_eof();
    else if (mode == 8) test_tactical_ai_scanner_whitespace();
    else if (mode == 9) test_tactical_ai_scanner_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
