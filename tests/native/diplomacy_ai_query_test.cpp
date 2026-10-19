#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct PlayerMgr {
    char pad_00[0x50];
    short m_num_players;
};

struct TribePlayer {
    char pad_00[0xB98];
    PlayerMgr *m_mgr;
    char pad_B9C[4];
    int m_player_id;
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
    unsigned char m_field100[10];
};

extern "C" {
    int func_0013FA90(DiplomacyAI *self, int player, int mode);
    void func_13FB50(DiplomacyAI *self, int player, int mode, int val);
}

static void setup_hierarchy(DiplomacyAI *ai, TribeAI *tribe_ai, TribePlayer *player, PlayerMgr *mgr,
                            short num_players, int player_id) {
    memset(ai, 0, sizeof(DiplomacyAI));
    memset(tribe_ai, 0, sizeof(TribeAI));
    memset(player, 0, sizeof(TribePlayer));
    memset(mgr, 0, sizeof(PlayerMgr));

    mgr->m_num_players = num_players;
    player->m_mgr = mgr;
    player->m_player_id = player_id;
    tribe_ai->m_player = player;
    ai->m_fieldAC = tribe_ai;
}

static void test_diplomacy_ai_query_fa90_bounds() {
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer player;
    PlayerMgr mgr;
    setup_hierarchy(&ai, &tribe_ai, &player, &mgr, 4, 1);

    // player <= 0 returns -1
    int res0 = func_0013FA90(&ai, 0, 0);
    int res_neg = func_0013FA90(&ai, -1, 0);

    // player >= num_players (4) returns -1
    int res_out = func_0013FA90(&ai, 4, 0);

    // Check bounds return -1
    assert(res0 == -1);
    assert(res_neg == -1);
    assert(res_out == -1);

    printf("DIPLOMACY_AI_QUERY_TEST_0_FA90_BOUNDS_PASSED\n");
}

static void test_diplomacy_ai_query_fa90_modes_0_2_invalid() {
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer player;
    PlayerMgr mgr;
    setup_hierarchy(&ai, &tribe_ai, &player, &mgr, 4, 1);

    ai.m_fieldB0[2] = 77;
    ai.m_fieldD8[2] = 88;

    // Mode 0: returns fieldB0[player]
    int res_m0 = func_0013FA90(&ai, 2, 0);
    assert(res_m0 == 77);

    // Mode 2: returns fieldD8[player]
    int res_m2 = func_0013FA90(&ai, 2, 2);
    assert(res_m2 == 88);

    // Invalid mode: returns -1
    int res_inv = func_0013FA90(&ai, 2, 99);
    assert(res_inv == -1);

    printf("DIPLOMACY_AI_QUERY_TEST_1_FA90_MODES_0_2_INVALID_PASSED\n");
}

static void test_diplomacy_ai_query_fa90_mode_1_score() {
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer player;
    PlayerMgr mgr;
    setup_hierarchy(&ai, &tribe_ai, &player, &mgr, 4, 1);

    // Case 1: fieldB0 = 49, fieldD8 = 49 -> d1 = 0, d2 = 0 -> score = 100
    ai.m_fieldB0[1] = 49;
    ai.m_fieldD8[1] = 49;
    int score1 = func_0013FA90(&ai, 1, 1);
    assert(score1 == 100);

    // Case 2: fieldB0 = 39 (d1 = 10), fieldD8 = 59 (d2 = 10) -> score = 100 - 20 = 80
    ai.m_fieldB0[2] = 39;
    ai.m_fieldD8[2] = 59;
    int score2 = func_0013FA90(&ai, 2, 1);
    assert(score2 == 80);

    // Case 3: score clamped to 0 when negative: B0 = 100 (d1 = 51), D8 = 100 (d2 = 51)
    // 100 - 51 - 51 = -2 -> 0
    ai.m_fieldB0[3] = 100;
    ai.m_fieldD8[3] = 100;
    int score3 = func_0013FA90(&ai, 3, 1);
    assert(score3 == 0);

    printf("DIPLOMACY_AI_QUERY_TEST_2_FA90_MODE_1_SCORE_PASSED\n");
}

static void test_diplomacy_ai_query_fb50_bounds() {
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer player;
    PlayerMgr mgr;
    setup_hierarchy(&ai, &tribe_ai, &player, &mgr, 4, 1);

    ai.m_fieldB0[0] = 50;
    ai.m_fieldB0[1] = 50;

    // player <= 0 does nothing
    func_13FB50(&ai, 0, 0, 10);
    assert(ai.m_fieldB0[0] == 50);

    func_13FB50(&ai, -2, 0, 10);

    // player >= num_players does nothing
    func_13FB50(&ai, 4, 0, 10);

    printf("DIPLOMACY_AI_QUERY_TEST_3_FB50_BOUNDS_PASSED\n");
}

static void test_diplomacy_ai_query_fb50_mode_0_clamping() {
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer player;
    PlayerMgr mgr;
    setup_hierarchy(&ai, &tribe_ai, &player, &mgr, 5, 1);

    // player 1 has field100 == 1 -> clamped to [0, 100]
    ai.m_field100[1] = 1;
    ai.m_fieldB0[1] = 90;
    func_13FB50(&ai, 1, 0, 20); // 90 + 20 = 110 -> 100
    assert(ai.m_fieldB0[1] == 100);

    func_13FB50(&ai, 1, 0, -200); // 100 - 200 = -100 -> 0
    assert(ai.m_fieldB0[1] == 0);

    // player 2 has field100 == 0 -> clamped to [50, 100]
    ai.m_field100[2] = 0;
    ai.m_fieldB0[2] = 60;
    func_13FB50(&ai, 2, 0, -30); // 60 - 30 = 30 -> 50
    assert(ai.m_fieldB0[2] == 50);

    func_13FB50(&ai, 2, 0, 100); // 50 + 100 = 150 -> 100
    assert(ai.m_fieldB0[2] == 100);

    printf("DIPLOMACY_AI_QUERY_TEST_4_FB50_MODE_0_CLAMPING_PASSED\n");
}

static void test_diplomacy_ai_query_fb50_mode_1_noop() {
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer player;
    PlayerMgr mgr;
    setup_hierarchy(&ai, &tribe_ai, &player, &mgr, 4, 1);

    ai.m_fieldB0[2] = 45;
    ai.m_fieldD8[2] = 45;

    // Mode 1: no-op
    func_13FB50(&ai, 2, 1, 10);
    assert(ai.m_fieldB0[2] == 45);
    assert(ai.m_fieldD8[2] == 45);

    printf("DIPLOMACY_AI_QUERY_TEST_5_FB50_MODE_1_NOOP_PASSED\n");
}

static void test_diplomacy_ai_query_fb50_mode_2_clamping() {
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer player;
    PlayerMgr mgr;
    setup_hierarchy(&ai, &tribe_ai, &player, &mgr, 5, 1);

    // player 1 has field100 == 1 -> clamped to [0, 100]
    ai.m_field100[1] = 1;
    ai.m_fieldD8[1] = 80;
    func_13FB50(&ai, 1, 2, 50); // 80 + 50 = 130 -> 100
    assert(ai.m_fieldD8[1] == 100);

    func_13FB50(&ai, 1, 2, -150); // 100 - 150 = -50 -> 0
    assert(ai.m_fieldD8[1] == 0);

    // player 2 has field100 == 0 -> clamped to [0, 48]
    ai.m_field100[2] = 0;
    ai.m_fieldD8[2] = 30;
    func_13FB50(&ai, 2, 2, 30); // 30 + 30 = 60 -> 48
    assert(ai.m_fieldD8[2] == 48);

    func_13FB50(&ai, 2, 2, -100); // 48 - 100 = -52 -> 0
    assert(ai.m_fieldD8[2] == 0);

    printf("DIPLOMACY_AI_QUERY_TEST_6_FB50_MODE_2_CLAMPING_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-6)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_diplomacy_ai_query_fa90_bounds();
    else if (mode == 1) test_diplomacy_ai_query_fa90_modes_0_2_invalid();
    else if (mode == 2) test_diplomacy_ai_query_fa90_mode_1_score();
    else if (mode == 3) test_diplomacy_ai_query_fb50_bounds();
    else if (mode == 4) test_diplomacy_ai_query_fb50_mode_0_clamping();
    else if (mode == 5) test_diplomacy_ai_query_fb50_mode_1_noop();
    else if (mode == 6) test_diplomacy_ai_query_fb50_mode_2_clamping();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
