#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

class OtherPlayerBase {
public:
    char pad_00[0x1B30];
};

class OtherPlayer : public OtherPlayerBase {
public:
    virtual void* v0() { return 0; }
    virtual void* v1() { return 0; }
    virtual void* v2() { return 0; }
    virtual void* v3() { return 0; }
    virtual void* v4() { return 0; }
    virtual void* v5() { return 0; }
    virtual void* v6() { return 0; }
    virtual int CheckRelation(int self_id);
};

class MockOtherPlayer : public OtherPlayer {
public:
    int m_check_relation_return;
    int m_last_self_id;
    int m_check_relation_calls;

    MockOtherPlayer() : m_check_relation_return(1), m_last_self_id(-1), m_check_relation_calls(0) {}

    virtual int CheckRelation(int self_id) {
        m_check_relation_calls++;
        m_last_self_id = self_id;
        return m_check_relation_return;
    }
};

int OtherPlayer::CheckRelation(int self_id) {
    (void)self_id;
    return 0;
}

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
    char pad_BA4[0xBD8 - 0xBA4];
    unsigned char *m_stances;
};

struct TribeAI {
    char pad_00[0xAC];
    TribePlayer *m_player;
};

struct DiplomacyAI {
    void *m_vtable;
    char pad_04[0xA8];
    TribeAI *m_fieldAC;
    int m_fieldB0[10];
    int m_fieldD8[10];
    char m_field100[10];
};

extern "C" {
    int func_1401C0(DiplomacyAI *self, int player);
    int func_140220(DiplomacyAI *self, int player);
    int func_140280(DiplomacyAI *self, int player);
    int func_1402E0(DiplomacyAI *self, int player);
    void func_00140360();
}

struct TestContext {
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer player;
    PlayerMgr mgr;
    unsigned char stances[16];
    MockOtherPlayer mock_other_players[8];
    OtherPlayer *other_ptrs[8];
};

static void setup_context(TestContext *ctx, short num_players, int player_id) {
    memset(ctx, 0, sizeof(TestContext));

    ctx->mgr.m_num_players = num_players;
    for (int i = 0; i < 8; i++) {
        new (&ctx->mock_other_players[i]) MockOtherPlayer();
        ctx->other_ptrs[i] = &ctx->mock_other_players[i];
    }
    ctx->mgr.m_players = ctx->other_ptrs;

    ctx->player.m_mgr = &ctx->mgr;
    ctx->player.m_player_id = player_id;
    ctx->player.m_stances = ctx->stances;

    ctx->tribe_ai.m_player = &ctx->player;
    ctx->ai.m_fieldAC = &ctx->tribe_ai;
}

static void test_diplomacy_ai_relations_1401c0_stance_3_check() {
    TestContext ctx;
    // 4 players (1, 2, 3). player_id = 1.
    setup_context(&ctx, 3, 1);

    ctx.stances[2] = 3;
    ctx.stances[3] = 0;

    // Bounds checks: player <= 0 returns 0
    assert(func_1401C0(&ctx.ai, 0) == 0);
    assert(func_1401C0(&ctx.ai, -1) == 0);

    // player > num_players returns 0
    assert(func_1401C0(&ctx.ai, 4) == 0);

    // player == player_id returns 0 even if stance is 3
    ctx.stances[1] = 3;
    assert(func_1401C0(&ctx.ai, 1) == 0);

    // player 2 has stance 3 -> returns 1
    int res2 = func_1401C0(&ctx.ai, 2);
    assert(res2 == 1);

    // player 3 has stance 0 -> returns 0
    assert(func_1401C0(&ctx.ai, 3) == 0);

    printf("DIPLOMACY_AI_RELATIONS_TEST_0_1401C0_STANCE_3_CHECK_PASSED\n");
}

static void test_diplomacy_ai_relations_140220_stance_1_check() {
    TestContext ctx;
    setup_context(&ctx, 3, 1);

    ctx.stances[2] = 1;
    ctx.stances[3] = 2;

    // Bounds checks: player <= 0 returns 0
    assert(func_140220(&ctx.ai, 0) == 0);
    assert(func_140220(&ctx.ai, -1) == 0);

    // player > num_players returns 0
    assert(func_140220(&ctx.ai, 4) == 0);

    // player == player_id returns 0 even if stance is 1
    ctx.stances[1] = 1;
    assert(func_140220(&ctx.ai, 1) == 0);

    // player 2 has stance 1 -> returns 1
    assert(func_140220(&ctx.ai, 2) == 1);

    // player 3 has stance 2 -> returns 0
    assert(func_140220(&ctx.ai, 3) == 0);

    printf("DIPLOMACY_AI_RELATIONS_TEST_1_140220_STANCE_1_CHECK_PASSED\n");
}

static void test_diplomacy_ai_relations_140280_self_and_stance_0_check() {
    TestContext ctx;
    setup_context(&ctx, 3, 1);

    ctx.stances[1] = 5; // self has non-zero stance
    ctx.stances[2] = 0; // player 2 has stance 0
    ctx.stances[3] = 1; // player 3 has stance 1

    // player == player_id returns 1 regardless of stance
    assert(func_140280(&ctx.ai, 1) == 1);

    // player <= 0 returns 0 (unless self_id is <= 0)
    assert(func_140280(&ctx.ai, 0) == 0);
    assert(func_140280(&ctx.ai, -1) == 0);

    // player > num_players returns 0
    assert(func_140280(&ctx.ai, 4) == 0);

    // player 2 has stance 0 -> returns 1
    assert(func_140280(&ctx.ai, 2) == 1);

    // player 3 has stance 1 -> returns 0
    assert(func_140280(&ctx.ai, 3) == 0);

    printf("DIPLOMACY_AI_RELATIONS_TEST_2_140280_SELF_AND_STANCE_0_CHECK_PASSED\n");
}

static void test_diplomacy_ai_relations_1402e0_bounds_and_null() {
    TestContext ctx;
    setup_context(&ctx, 3, 1);

    // player <= 0 returns 0
    assert(func_1402E0(&ctx.ai, 0) == 0);
    assert(func_1402E0(&ctx.ai, -1) == 0);

    // player >= num_players returns 0
    assert(func_1402E0(&ctx.ai, 3) == 0);
    assert(func_1402E0(&ctx.ai, 4) == 0);

    // other == NULL returns 0
    ctx.mgr.m_players[2] = 0;
    assert(func_1402E0(&ctx.ai, 2) == 0);

    printf("DIPLOMACY_AI_RELATIONS_TEST_3_1402E0_BOUNDS_AND_NULL_PASSED\n");
}

static void test_diplomacy_ai_relations_1402e0_check_relation_called() {
    TestContext ctx;
    setup_context(&ctx, 4, 1);

    // player 2 returns 1
    ctx.mock_other_players[2].m_check_relation_return = 1;
    assert(func_1402E0(&ctx.ai, 2) == 1);
    assert(ctx.mock_other_players[2].m_check_relation_calls == 1);
    assert(ctx.mock_other_players[2].m_last_self_id == 1);

    // player 3 returns 0
    ctx.mock_other_players[3].m_check_relation_return = 0;
    assert(func_1402E0(&ctx.ai, 3) == 0);
    assert(ctx.mock_other_players[3].m_check_relation_calls == 1);
    assert(ctx.mock_other_players[3].m_last_self_id == 1);

    printf("DIPLOMACY_AI_RELATIONS_TEST_4_1402E0_CHECK_RELATION_CALLED_PASSED\n");
}

static void test_diplomacy_ai_relations_00140360_callable() {
    // Simply verify func_00140360 is callable and executes cleanly
    func_00140360();

    printf("DIPLOMACY_AI_RELATIONS_TEST_5_00140360_CALLABLE_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-5)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_diplomacy_ai_relations_1401c0_stance_3_check();
    else if (mode == 1) test_diplomacy_ai_relations_140220_stance_1_check();
    else if (mode == 2) test_diplomacy_ai_relations_140280_self_and_stance_0_check();
    else if (mode == 3) test_diplomacy_ai_relations_1402e0_bounds_and_null();
    else if (mode == 4) test_diplomacy_ai_relations_1402e0_check_relation_called();
    else if (mode == 5) test_diplomacy_ai_relations_00140360_callable();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
