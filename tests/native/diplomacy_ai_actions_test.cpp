#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

class OtherPlayer {
public:
    char pad_00[0x54];
    char pad_54[0xB90 - 0x54];
    void *m_fieldB90;
    char pad_B94[0xBA6 - 0xB94];
    unsigned char m_status;
};

struct PlayerMgr {
    char pad_00[0x50];
    short m_num_players;
    short pad_52;
    OtherPlayer **m_players;
};

struct TribePlayer {
    char pad_00[0xB98];
    PlayerMgr *m_mgr;
    char pad_B9C[4];
    int m_player_id;
};

struct AIObj {
    virtual void* v0() { return 0; }
    virtual void* v1() { return 0; }
    virtual void* v2() { return 0; }
    virtual void* v3() { return 0; }
    virtual void* v4() { return 0; }
    virtual void* v5() { return 0; }
    virtual void* v6() { return 0; }
    virtual void* v7() { return 0; }
    virtual void* v8() { return 0; }
    virtual void* v9() { return 0; }
    virtual void* v10() { return 0; }
    virtual void* v11() { return 0; }
    virtual void* v12() { return 0; }
    virtual void* v13() { return 0; }
    virtual void* v14() { return 0; }
    virtual void* v15() { return 0; }
    virtual void* v16() { return 0; }
    virtual void* v17() { return 0; }
    virtual void* v18() { return 0; }
    virtual void* v19() { return 0; }
    virtual void* v20() { return 0; }
    virtual void* v21() { return 0; }
    virtual void* v22() { return 0; }
    virtual void* v23() { return 0; }
    virtual int Method24(int player);
};

struct MockAIObj : public AIObj {
    char pad_04[0xAC - sizeof(void*)];
    TribePlayer *m_player;
    int m_method24_returns[16];
    int m_method24_called;

    MockAIObj() : m_player(0), m_method24_called(0) {
        memset(pad_04, 0, sizeof(pad_04));
        for (int i = 0; i < 16; i++) {
            m_method24_returns[i] = 1;
        }
    }

    virtual int Method24(int player) {
        m_method24_called++;
        if (player >= 0 && player < 16) {
            return m_method24_returns[player];
        }
        return 0;
    }
};

int AIObj::Method24(int player) {
    (void)player;
    return 1;
}

struct TribeAI {
    char pad_00[0xAC];
    TribePlayer *m_player;
};

struct DiplomacyAI {
    void *m_vtable;
    char pad_04[0xA8];
    AIObj *m_fieldAC;
    int m_fieldB0[10];
    int m_fieldD8[10];
    unsigned char m_field100[10];
};

extern "C" {
    static int s_140280_returns[16] = {0};
    static int s_140280_calls = 0;

    static int s_140220_returns[16] = {0};
    static int s_140220_calls = 0;

    static int s_318280_returns[16] = {0};
    static int s_318280_calls = 0;

    static int s_1401c0_returns[16] = {0};
    static int s_1401c0_calls = 0;

    int func_140280(void *self, int player) {
        (void)self;
        s_140280_calls++;
        if (player >= 0 && player < 16) return s_140280_returns[player];
        return 0;
    }

    int func_140220(void *self, int player) {
        (void)self;
        s_140220_calls++;
        if (player >= 0 && player < 16) return s_140220_returns[player];
        return 0;
    }

    int func_318280(void *ptr) {
        s_318280_calls++;
        // If ptr encodes a player index
        size_t idx = (size_t)ptr;
        if (idx < 16) return s_318280_returns[idx];
        return 0;
    }

    int func_1401C0(void *self, int player) {
        (void)self;
        s_1401c0_calls++;
        if (player >= 0 && player < 16) return s_1401c0_returns[player];
        return 0;
    }

    int func_13FEF0(DiplomacyAI *self, int a1, int a2, int t0, int a3);
    int func_001400B0();
    int func_001400C0(DiplomacyAI *self, int a1, int a2);
}

static void reset_mocks() {
    memset(s_140280_returns, 0, sizeof(s_140280_returns));
    s_140280_calls = 0;

    memset(s_140220_returns, 0, sizeof(s_140220_returns));
    s_140220_calls = 0;

    memset(s_318280_returns, 0, sizeof(s_318280_returns));
    s_318280_calls = 0;

    memset(s_1401c0_returns, 0, sizeof(s_1401c0_returns));
    s_1401c0_calls = 0;
}

struct TestContext {
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer self_player;
    PlayerMgr mgr;
    OtherPlayer other_players[8];
    OtherPlayer *other_ptrs[8];
    MockAIObj mock_ai_obj;
};

static void setup_context(TestContext *ctx, short num_players, int self_id) {
    memset(ctx, 0, sizeof(TestContext));
    reset_mocks();

    ctx->mgr.m_num_players = num_players;
    for (int i = 0; i < 8; i++) {
        ctx->other_ptrs[i] = &ctx->other_players[i];
        ctx->other_players[i].m_status = 1; // default active
        ctx->other_players[i].m_fieldB90 = (void*)(size_t)i; // index as ptr
    }
    ctx->mgr.m_players = ctx->other_ptrs;

    ctx->self_player.m_mgr = &ctx->mgr;
    ctx->self_player.m_player_id = self_id;
    ctx->tribe_ai.m_player = &ctx->self_player;

    new (&ctx->mock_ai_obj) MockAIObj();
    ctx->mock_ai_obj.m_player = &ctx->self_player;
    ctx->ai.m_fieldAC = &ctx->mock_ai_obj;
}

static void test_diplomacy_ai_actions_fef0_skips_self_and_status2() {
    TestContext ctx;
    // 4 players (1, 2, 3). self_id = 1.
    setup_context(&ctx, 4, 1);

    // player 2 has status 2 (dead/resigned)
    ctx.other_players[2].m_status = 2;

    // player 3 is valid
    ctx.ai.m_fieldB0[3] = 45;

    int best = func_13FEF0(&ctx.ai, 0, 0, 0, 0);

    // Player 3 is the only valid active player
    assert(best == 3);

    printf("DIPLOMACY_AI_ACTIONS_TEST_0_FEF0_SKIPS_SELF_AND_STATUS2_PASSED\n");
}

static void test_diplomacy_ai_actions_fef0_a1_positive_and_a2_checks() {
    TestContext ctx;
    // 4 players (1, 2, 3). self_id = 1.
    setup_context(&ctx, 4, 1);

    ctx.ai.m_fieldB0[2] = 50;
    ctx.ai.m_fieldB0[3] = 40;

    // If a1 > 0, a2 == 2, and func_140280 == 1 -> player 2 skipped
    s_140280_returns[2] = 1;
    int best = func_13FEF0(&ctx.ai, 1, 2, 0, 0);
    // player 2 was skipped because of (a1 > 0 && a2 == 2 && 140280), so best is player 3
    assert(best == 3);

    printf("DIPLOMACY_AI_ACTIONS_TEST_1_FEF0_A1_POSITIVE_AND_A2_CHECKS_PASSED\n");
}

static void test_diplomacy_ai_actions_fef0_skip_conditions() {
    TestContext ctx;
    // 4 players (1, 2, 3). self_id = 1.
    setup_context(&ctx, 4, 1);

    ctx.ai.m_fieldB0[2] = 80;
    ctx.ai.m_fieldB0[3] = 70;

    // Test func_140280 == 1 skips player 2
    s_140280_returns[2] = 1;
    assert(func_13FEF0(&ctx.ai, 0, 0, 0, 0) == 3);
    s_140280_returns[2] = 0;

    // Test func_140220 == 1 skips player 2
    s_140220_returns[2] = 1;
    assert(func_13FEF0(&ctx.ai, 0, 0, 0, 0) == 3);
    s_140220_returns[2] = 0;

    // Test Method24 == 0 skips player 2
    ctx.mock_ai_obj.m_method24_returns[2] = 0;
    assert(func_13FEF0(&ctx.ai, 0, 0, 0, 0) == 3);

    printf("DIPLOMACY_AI_ACTIONS_TEST_2_FEF0_SKIP_CONDITIONS_PASSED\n");
}

static void test_diplomacy_ai_actions_fef0_score_calculation_t0_1_and_other() {
    TestContext ctx;
    // 4 players (1, 2, 3). self_id = 1.
    setup_context(&ctx, 4, 1);

    ctx.ai.m_fieldB0[2] = 50;
    ctx.ai.m_fieldB0[3] = 50;

    s_318280_returns[2] = 20;
    s_318280_returns[3] = 10;

    // With a3 = 2, t0 = 1: score += val / a3
    // player 2: score = 50 + 20/2 = 60
    // player 3: score = 50 + 10/2 = 55
    // player 2 wins
    int best1 = func_13FEF0(&ctx.ai, 0, 0, 1, 2);
    assert(best1 == 2);

    // With a3 = 2, t0 = 0: score -= val / a3
    // player 2: score = 50 - 20/2 = 40
    // player 3: score = 50 - 10/2 = 45
    // player 3 wins
    int best2 = func_13FEF0(&ctx.ai, 0, 0, 0, 2);
    assert(best2 == 3);

    printf("DIPLOMACY_AI_ACTIONS_TEST_3_FEF0_SCORE_CALCULATION_PASSED\n");
}

static void test_diplomacy_ai_actions_fef0_no_valid_player_returns_minus_one() {
    TestContext ctx;
    // num_players = 2, self_id = 1 -> loop player = 1 < 2, skips player 1 (self), terminates
    setup_context(&ctx, 2, 1);

    int best = func_13FEF0(&ctx.ai, 0, 0, 0, 0);
    assert(best == -1);

    printf("DIPLOMACY_AI_ACTIONS_TEST_4_FEF0_NO_VALID_PLAYER_PASSED\n");
}

static void test_diplomacy_ai_actions_001400b0_returns_zero() {
    int res = func_001400B0();
    assert(res == 0);

    printf("DIPLOMACY_AI_ACTIONS_TEST_5_001400B0_RETURNS_ZERO_PASSED\n");
}

static void test_diplomacy_ai_actions_001400c0_basic_selection() {
    TestContext ctx;
    // 4 players (1, 2, 3). self_id = 1.
    setup_context(&ctx, 4, 1);

    ctx.other_players[2].m_status = 2; // player 2 dead
    ctx.ai.m_fieldD8[2] = 100;
    ctx.ai.m_fieldD8[3] = 40;

    // player 2 skipped due to status 2, player 3 selected
    int best = func_001400C0(&ctx.ai, 0, 0);
    assert(best == 3);

    printf("DIPLOMACY_AI_ACTIONS_TEST_6_001400C0_BASIC_SELECTION_PASSED\n");
}

static void test_diplomacy_ai_actions_001400c0_a1_positive_a2_filter() {
    TestContext ctx;
    // 4 players (1, 2, 3). self_id = 1.
    setup_context(&ctx, 4, 1);

    ctx.ai.m_fieldD8[2] = 80;
    ctx.ai.m_fieldD8[3] = 60;

    // a1 > 0, a2 == 2, and func_1401C0 == 1 -> player 2 skipped
    s_1401c0_returns[2] = 1;
    int best = func_001400C0(&ctx.ai, 1, 2);
    assert(best == 3);

    printf("DIPLOMACY_AI_ACTIONS_TEST_7_001400C0_A1_POSITIVE_A2_FILTER_PASSED\n");
}

static void test_diplomacy_ai_actions_001400c0_no_valid_player_returns_minus_one() {
    TestContext ctx;
    setup_context(&ctx, 1, 0);

    int best = func_001400C0(&ctx.ai, 0, 0);
    assert(best == -1);

    printf("DIPLOMACY_AI_ACTIONS_TEST_8_001400C0_NO_VALID_PLAYER_PASSED\n");
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
    if (mode == 0) test_diplomacy_ai_actions_fef0_skips_self_and_status2();
    else if (mode == 1) test_diplomacy_ai_actions_fef0_a1_positive_and_a2_checks();
    else if (mode == 2) test_diplomacy_ai_actions_fef0_skip_conditions();
    else if (mode == 3) test_diplomacy_ai_actions_fef0_score_calculation_t0_1_and_other();
    else if (mode == 4) test_diplomacy_ai_actions_fef0_no_valid_player_returns_minus_one();
    else if (mode == 5) test_diplomacy_ai_actions_001400b0_returns_zero();
    else if (mode == 6) test_diplomacy_ai_actions_001400c0_basic_selection();
    else if (mode == 7) test_diplomacy_ai_actions_001400c0_a1_positive_a2_filter();
    else if (mode == 8) test_diplomacy_ai_actions_001400c0_no_valid_player_returns_minus_one();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
