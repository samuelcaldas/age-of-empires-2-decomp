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
    char m_field100[10];

    int Save(void *stream);
};

extern "C" {
    static int s_280_called = 0;
    static int s_280_last_player = 0;
    static int s_280_return_table[16] = {0};

    static int s_2e0_called = 0;
    static int s_2e0_last_player = 0;
    static int s_2e0_return_table[16] = {0};

    static int s_b50_called = 0;
    static void *s_b50_last_self = 0;
    static int s_b50_last_player = 0;
    static int s_b50_last_a2 = 0;
    static int s_b50_last_a3 = 0;

    static int s_f70_called = 0;
    static void *s_f70_last_stream = 0;
    static int s_f70_total_bytes = 0;
    static char s_saved_buffer[256];

    int func_140280(void *self, int player) {
        (void)self;
        s_280_called++;
        s_280_last_player = player;
        if (player >= 0 && player < 16) {
            return s_280_return_table[player];
        }
        return 0;
    }

    int func_1402E0(void *self, int player) {
        (void)self;
        s_2e0_called++;
        s_2e0_last_player = player;
        if (player >= 0 && player < 16) {
            return s_2e0_return_table[player];
        }
        return 0;
    }

    void func_13FB50(void *self, int player, int a2, int a3) {
        s_b50_called++;
        s_b50_last_self = self;
        s_b50_last_player = player;
        s_b50_last_a2 = a2;
        s_b50_last_a3 = a3;
    }

    void func_00226F70(void *stream, void *src, int size) {
        s_f70_called++;
        s_f70_last_stream = stream;
        if (s_f70_total_bytes + size <= (int)sizeof(s_saved_buffer)) {
            memcpy(s_saved_buffer + s_f70_total_bytes, src, size);
        }
        s_f70_total_bytes += size;
    }

    int func_0013F910(DiplomacyAI *self);
}

static void reset_mocks() {
    s_280_called = 0;
    s_280_last_player = 0;
    memset(s_280_return_table, 0, sizeof(s_280_return_table));

    s_2e0_called = 0;
    s_2e0_last_player = 0;
    memset(s_2e0_return_table, 0, sizeof(s_2e0_return_table));

    s_b50_called = 0;
    s_b50_last_self = 0;
    s_b50_last_player = 0;
    s_b50_last_a2 = 0;
    s_b50_last_a3 = 0;

    s_f70_called = 0;
    s_f70_last_stream = 0;
    s_f70_total_bytes = 0;
    memset(s_saved_buffer, 0, sizeof(s_saved_buffer));
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

static void test_diplomacy_ai_save_f910_skips_self_player_id() {
    reset_mocks();
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer player;
    PlayerMgr mgr;
    setup_hierarchy(&ai, &tribe_ai, &player, &mgr, 3, 1);

    int res = func_0013F910(&ai);

    assert(res == 1);
    assert(s_280_called == 2);
    assert(s_280_last_player == 2);

    printf("DIPLOMACY_AI_SAVE_TEST_0_F910_SKIPS_SELF_PLAYER_ID_PASSED\n");
}

static void test_diplomacy_ai_save_f910_branch1_140280_true_1402e0_false() {
    reset_mocks();
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer player;
    PlayerMgr mgr;
    // 3 players: i = 1, 2. Self id = 2.
    // i = 1: 140280 = 1, 1402E0 = 0 -> calls func_13FB50(&ai, 1, 0, 1)
    setup_hierarchy(&ai, &tribe_ai, &player, &mgr, 3, 2);
    s_280_return_table[1] = 1;
    s_2e0_return_table[1] = 0;

    int res = func_0013F910(&ai);

    assert(res == 1);
    assert(s_b50_called == 1);
    assert(s_b50_last_self == &ai);
    assert(s_b50_last_player == 1);
    assert(s_b50_last_a2 == 0);
    assert(s_b50_last_a3 == 1);

    printf("DIPLOMACY_AI_SAVE_TEST_1_F910_BRANCH1_PASSED\n");
}

static void test_diplomacy_ai_save_f910_branch2_140280_false_1402e0_true() {
    reset_mocks();
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer player;
    PlayerMgr mgr;
    // 3 players: i = 1, 2. Self id = 2.
    // i = 1: 140280 = 0, 1402E0 = 1 -> calls func_13FB50(&ai, 1, 2, 1)
    setup_hierarchy(&ai, &tribe_ai, &player, &mgr, 3, 2);
    s_280_return_table[1] = 0;
    s_2e0_return_table[1] = 1;

    int res = func_0013F910(&ai);

    assert(res == 1);
    assert(s_b50_called == 1);
    assert(s_b50_last_self == &ai);
    assert(s_b50_last_player == 1);
    assert(s_b50_last_a2 == 2);
    assert(s_b50_last_a3 == 1);

    printf("DIPLOMACY_AI_SAVE_TEST_2_F910_BRANCH2_PASSED\n");
}

static void test_diplomacy_ai_save_f910_both_true_or_both_false_no_call() {
    reset_mocks();
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer player;
    PlayerMgr mgr;
    // 4 players: i = 1, 2, 3. Self id = 99.
    // i = 1: both true (1, 1) -> no call
    // i = 2: both false (0, 0) -> no call
    setup_hierarchy(&ai, &tribe_ai, &player, &mgr, 3, 99);
    s_280_return_table[1] = 1;
    s_2e0_return_table[1] = 1;
    s_280_return_table[2] = 0;
    s_2e0_return_table[2] = 0;

    int res = func_0013F910(&ai);

    assert(res == 1);
    assert(s_b50_called == 0);

    printf("DIPLOMACY_AI_SAVE_TEST_3_F910_BOTH_TRUE_OR_FALSE_NO_CALL_PASSED\n");
}

static void test_diplomacy_ai_save_f910_num_players_1_no_loop() {
    reset_mocks();
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer player;
    PlayerMgr mgr;
    setup_hierarchy(&ai, &tribe_ai, &player, &mgr, 1, 0);

    int res = func_0013F910(&ai);

    assert(res == 1);
    assert(s_280_called == 0);
    assert(s_2e0_called == 0);
    assert(s_b50_called == 0);

    printf("DIPLOMACY_AI_SAVE_TEST_4_F910_NUM_PLAYERS_1_NO_LOOP_PASSED\n");
}

static void test_diplomacy_ai_save_save_stream_writes() {
    reset_mocks();
    DiplomacyAI ai;
    memset(&ai, 0, sizeof(ai));

    for (int i = 0; i <= 9; i++) {
        ai.m_fieldB0[i] = 1000 + i;
        ai.m_fieldD8[i] = 2000 + i;
        ai.m_field100[i] = (char)(30 + i);
    }

    int res = ai.Save((void*)0x9ABC);

    assert(res == 1);
    assert(s_f70_called == 30);
    assert(s_f70_last_stream == (void*)0x9ABC);
    assert(s_f70_total_bytes == 90);

    // Verify written data layout
    int offset = 0;
    for (int i = 0; i <= 9; i++) {
        int val_b0 = *(int*)(s_saved_buffer + offset);
        offset += 4;
        assert(val_b0 == 1000 + i);

        int val_d8 = *(int*)(s_saved_buffer + offset);
        offset += 4;
        assert(val_d8 == 2000 + i);

        char val_100 = *(char*)(s_saved_buffer + offset);
        offset += 1;
        assert(val_100 == (char)(30 + i));
    }

    printf("DIPLOMACY_AI_SAVE_TEST_5_SAVE_STREAM_WRITES_PASSED\n");
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
    if (mode == 0) test_diplomacy_ai_save_f910_skips_self_player_id();
    else if (mode == 1) test_diplomacy_ai_save_f910_branch1_140280_true_1402e0_false();
    else if (mode == 2) test_diplomacy_ai_save_f910_branch2_140280_false_1402e0_true();
    else if (mode == 3) test_diplomacy_ai_save_f910_both_true_or_both_false_no_call();
    else if (mode == 4) test_diplomacy_ai_save_f910_num_players_1_no_loop();
    else if (mode == 5) test_diplomacy_ai_save_save_stream_writes();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
