#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

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
    virtual int GetFact(int id);
};

struct MockAIObj : public AIObj {
    int m_calls;
    int m_recorded_ids[16];
    int m_return_values[16];

    MockAIObj() : m_calls(0) {
        memset(m_recorded_ids, 0, sizeof(m_recorded_ids));
        memset(m_return_values, 0, sizeof(m_return_values));
    }

    virtual int GetFact(int id) {
        if (m_calls < 16) {
            m_recorded_ids[m_calls++] = id;
        }
        if (id == 0x7C) return 111;
        if (id == 0x80) return 222;
        if (id == 0xBC) return 333;
        if (id == 0xC3) return 444;
        return 0;
    }
};

int AIObj::GetFact(int id) {
    (void)id;
    return 0;
}

struct DiplomacyAI {
    void *m_vtable;
    char pad_04[0xA8];
    AIObj *m_fieldAC;
    int m_fieldB0[10];
    int m_fieldD8[10];
    unsigned char m_field100[10];
};

extern "C" {
    static int s_fef0_called = 0;
    static void *s_fef0_last_self = 0;
    static int s_fef0_last_p1 = 0;
    static int s_fef0_last_p2 = 0;
    static int s_fef0_last_p3 = 0;
    static int s_fef0_last_p4 = 0;

    void func_13FEF0(void *self, int p1, int p2, int p3, int p4) {
        s_fef0_called++;
        s_fef0_last_self = self;
        s_fef0_last_p1 = p1;
        s_fef0_last_p2 = p2;
        s_fef0_last_p3 = p3;
        s_fef0_last_p4 = p4;
    }

    void func_0013FC80(DiplomacyAI *self, int player, int mode, int val);
    int func_0013FDA0(DiplomacyAI *self, int player);
    void func_0013FDF0(DiplomacyAI *self, int player, int val);
    void func_0013FE30(DiplomacyAI *self);
    int func_0013FEE0();
}

static void reset_mocks() {
    s_fef0_called = 0;
    s_fef0_last_self = 0;
    s_fef0_last_p1 = 0;
    s_fef0_last_p2 = 0;
    s_fef0_last_p3 = 0;
    s_fef0_last_p4 = 0;
}

struct TestHierarchy {
    DiplomacyAI ai;
    TribeAI tribe_ai;
    TribePlayer player;
    PlayerMgr mgr;
    MockAIObj mock_ai_obj;
};

static void setup_hierarchy(TestHierarchy *h, short num_players, int player_id) {
    memset(&h->ai, 0, sizeof(h->ai));
    memset(&h->tribe_ai, 0, sizeof(h->tribe_ai));
    memset(&h->player, 0, sizeof(h->player));
    memset(&h->mgr, 0, sizeof(h->mgr));

    h->mgr.m_num_players = num_players;
    h->player.m_mgr = &h->mgr;
    h->player.m_player_id = player_id;
    h->tribe_ai.m_player = &h->player;
    // Set AIObj vtable pointer
    new (&h->mock_ai_obj) MockAIObj();
    // For normal queries, m_fieldAC points to tribe_ai; for GetFact, mock_ai_obj is used
    h->ai.m_fieldAC = (AIObj*)&h->tribe_ai;
}

static void test_diplomacy_ai_helpers_fc80_bounds() {
    TestHierarchy h;
    setup_hierarchy(&h, 4, 1);

    h.ai.m_fieldB0[0] = 50;
    h.ai.m_fieldB0[1] = 50;

    // player <= 0 does nothing
    func_0013FC80(&h.ai, 0, 0, 80);
    func_0013FC80(&h.ai, -1, 0, 80);

    // player >= num_players does nothing
    func_0013FC80(&h.ai, 4, 0, 80);

    // Bounds check: values unmodified
    assert(h.ai.m_fieldB0[0] == 50);
    assert(h.ai.m_fieldB0[1] == 50);

    printf("DIPLOMACY_AI_HELPERS_TEST_0_FC80_BOUNDS_PASSED\n");
}

static void test_diplomacy_ai_helpers_fc80_mode_0_clamping() {
    TestHierarchy h;
    setup_hierarchy(&h, 5, 1);

    // player 1 has field100 == 1 -> clamped to [0, 100]
    h.ai.m_field100[1] = 1;
    func_0013FC80(&h.ai, 1, 0, 150);
    assert(h.ai.m_fieldB0[1] == 100);

    func_0013FC80(&h.ai, 1, 0, -20);
    assert(h.ai.m_fieldB0[1] == 0);

    func_0013FC80(&h.ai, 1, 0, 75);
    assert(h.ai.m_fieldB0[1] == 75);

    // player 2 has field100 == 0 -> clamped to [50, 100]
    h.ai.m_field100[2] = 0;
    func_0013FC80(&h.ai, 2, 0, 30);
    assert(h.ai.m_fieldB0[2] == 50);

    func_0013FC80(&h.ai, 2, 0, 120);
    assert(h.ai.m_fieldB0[2] == 100);

    func_0013FC80(&h.ai, 2, 0, 65);
    assert(h.ai.m_fieldB0[2] == 65);

    printf("DIPLOMACY_AI_HELPERS_TEST_1_FC80_MODE_0_CLAMPING_PASSED\n");
}

static void test_diplomacy_ai_helpers_fc80_mode_1_noop() {
    TestHierarchy h;
    setup_hierarchy(&h, 4, 1);

    h.ai.m_fieldB0[2] = 40;
    h.ai.m_fieldD8[2] = 60;

    // Mode 1: no-op
    func_0013FC80(&h.ai, 2, 1, 99);
    assert(h.ai.m_fieldB0[2] == 40);
    assert(h.ai.m_fieldD8[2] == 60);

    printf("DIPLOMACY_AI_HELPERS_TEST_2_FC80_MODE_1_NOOP_PASSED\n");
}

static void test_diplomacy_ai_helpers_fc80_mode_2_clamping() {
    TestHierarchy h;
    setup_hierarchy(&h, 5, 1);

    // player 1 has field100 == 1 -> clamped to [0, 100]
    h.ai.m_field100[1] = 1;
    func_0013FC80(&h.ai, 1, 2, 110);
    assert(h.ai.m_fieldD8[1] == 100);

    func_0013FC80(&h.ai, 1, 2, -50);
    assert(h.ai.m_fieldD8[1] == 0);

    func_0013FC80(&h.ai, 1, 2, 45);
    assert(h.ai.m_fieldD8[1] == 45);

    // player 2 has field100 == 0 -> clamped to [0, 48]
    h.ai.m_field100[2] = 0;
    func_0013FC80(&h.ai, 2, 2, 90);
    assert(h.ai.m_fieldD8[2] == 48);

    func_0013FC80(&h.ai, 2, 2, -10);
    assert(h.ai.m_fieldD8[2] == 0);

    func_0013FC80(&h.ai, 2, 2, 35);
    assert(h.ai.m_fieldD8[2] == 35);

    printf("DIPLOMACY_AI_HELPERS_TEST_3_FC80_MODE_2_CLAMPING_PASSED\n");
}

static void test_diplomacy_ai_helpers_fda0_check() {
    TestHierarchy h;
    setup_hierarchy(&h, 4, 1);

    h.ai.m_field100[1] = 1;
    h.ai.m_field100[2] = 0;
    h.ai.m_field100[3] = 2;

    // Bounds checks
    assert(func_0013FDA0(&h.ai, 0) == 0);
    assert(func_0013FDA0(&h.ai, -1) == 0);
    assert(func_0013FDA0(&h.ai, 4) == 0);

    // Player 1 has m_field100 == 1 -> returns 1
    assert(func_0013FDA0(&h.ai, 1) == 1);

    // Player 2 has m_field100 == 0 -> returns 0
    assert(func_0013FDA0(&h.ai, 2) == 0);

    // Player 3 has m_field100 == 2 -> returns 0
    assert(func_0013FDA0(&h.ai, 3) == 0);

    printf("DIPLOMACY_AI_HELPERS_TEST_4_FDA0_CHECK_PASSED\n");
}

static void test_diplomacy_ai_helpers_fdf0_set() {
    TestHierarchy h;
    setup_hierarchy(&h, 4, 1);

    // Out of bounds checks
    func_0013FDF0(&h.ai, 0, 5);
    assert(h.ai.m_field100[0] == 0);

    func_0013FDF0(&h.ai, -1, 5);

    func_0013FDF0(&h.ai, 4, 5);

    // Valid player set
    func_0013FDF0(&h.ai, 1, 1);
    assert(h.ai.m_field100[1] == 1);

    func_0013FDF0(&h.ai, 2, 255);
    assert(h.ai.m_field100[2] == 255);

    printf("DIPLOMACY_AI_HELPERS_TEST_5_FDF0_SET_PASSED\n");
}

static void test_diplomacy_ai_helpers_fe30_facts_and_call() {
    reset_mocks();
    TestHierarchy h;
    setup_hierarchy(&h, 4, 1);

    // Point fieldAC to mock_ai_obj
    h.ai.m_fieldAC = &h.mock_ai_obj;
    h.mock_ai_obj.m_return_values[0] = 111; // fact 0x7c return value (ignored)
    h.mock_ai_obj.m_return_values[1] = 222; // fact 0x80 -> p1
    h.mock_ai_obj.m_return_values[2] = 333; // fact 0xbc -> p2
    h.mock_ai_obj.m_return_values[3] = 444; // fact 0xc3 -> p3

    func_0013FE30(&h.ai);

    assert(h.mock_ai_obj.m_calls == 4);
    bool has_7c = false, has_80 = false, has_bc = false, has_c3 = false;
    for (int i = 0; i < 4; i++) {
        if (h.mock_ai_obj.m_recorded_ids[i] == 0x7C) has_7c = true;
        if (h.mock_ai_obj.m_recorded_ids[i] == 0x80) has_80 = true;
        if (h.mock_ai_obj.m_recorded_ids[i] == 0xBC) has_bc = true;
        if (h.mock_ai_obj.m_recorded_ids[i] == 0xC3) has_c3 = true;
    }
    assert(has_7c && has_80 && has_bc && has_c3);

    assert(s_fef0_called == 1);
    assert(s_fef0_last_self == &h.ai);
    assert(s_fef0_last_p1 == 111);
    assert(s_fef0_last_p2 == 222);
    assert(s_fef0_last_p3 == 333);
    assert(s_fef0_last_p4 == 444);

    printf("DIPLOMACY_AI_HELPERS_TEST_6_FE30_FACTS_AND_CALL_PASSED\n");
}

static void test_diplomacy_ai_helpers_fee0_returns_minus_one() {
    int val = func_0013FEE0();
    assert(val == -1);

    printf("DIPLOMACY_AI_HELPERS_TEST_7_FEE0_RETURNS_MINUS_ONE_PASSED\n");
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
    if (mode == 0) test_diplomacy_ai_helpers_fc80_bounds();
    else if (mode == 1) test_diplomacy_ai_helpers_fc80_mode_0_clamping();
    else if (mode == 2) test_diplomacy_ai_helpers_fc80_mode_1_noop();
    else if (mode == 3) test_diplomacy_ai_helpers_fc80_mode_2_clamping();
    else if (mode == 4) test_diplomacy_ai_helpers_fda0_check();
    else if (mode == 5) test_diplomacy_ai_helpers_fdf0_set();
    else if (mode == 6) test_diplomacy_ai_helpers_fe30_facts_and_call();
    else if (mode == 7) test_diplomacy_ai_helpers_fee0_returns_minus_one();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
