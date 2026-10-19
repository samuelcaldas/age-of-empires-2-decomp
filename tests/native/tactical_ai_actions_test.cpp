#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x18];
    short field_1C;
    char pad_1E[0x16];
    void *field_34;
    char pad_38[0x4];
    void **field_3C;
    int field_40;
    char field_44[0x148];
    int field_18C;
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    char field_1A0[0x100];
    int field_2A0;
    int field_2A4;
    char field_2A8[0x400];
    char *field_6A8;
    int field_6AC;
    int field_6B0;
    int field_6B4;
    int field_6B8;
    int field_6BC;
    int field_6C0;
    char field_6C4[0x28F0];
    int field_2FB4;
    char field_2FB8[0xC8];
    int field_3080;
};

extern "C" {
    char D_4D7768[16] = "VT_TACTICAL2";

    static int s_base_ctor_called = 0;
    static void *s_base_ctor_self = 0;
    static int s_base_ctor_a1 = 0;
    static int s_base_ctor_a2 = 0;
    static int s_base_ctor_a3 = 0;
    static int s_base_ctor_t0 = 0;

    void *func_001407B0(void *self, int a1, int a2, int a3, int t0) {
        s_base_ctor_called++;
        s_base_ctor_self = self;
        s_base_ctor_a1 = a1;
        s_base_ctor_a2 = a2;
        s_base_ctor_a3 = a3;
        s_base_ctor_t0 = t0;
        return self;
    }

    static int s_base_load_called = 0;
    static void *s_base_load_self = 0;
    static void *s_base_load_stream = 0;

    void *func_001409B0(void *self, void *stream) {
        s_base_load_called++;
        s_base_load_self = self;
        s_base_load_stream = stream;
        ((TacticalAI2*)self)->field_1C = 4; // simulate base load setting field_1C
        return self;
    }

    static int s_26ad90_called = 0;
    static void *s_26ad90_ptr = 0;
    static int s_26ad90_id = 0;

    void func_26AD90(void *ptr, int id) {
        s_26ad90_called++;
        s_26ad90_ptr = ptr;
        s_26ad90_id = id;
    }

    static int s_145680_called = 0;
    static void *s_145680_ptr = 0;

    void func_145680(void *ptr) {
        s_145680_called++;
        s_145680_ptr = ptr;
    }

    static int s_alloc_count = 0;
    static int s_last_alloc_size = 0;

    void *func_100730(int size) {
        s_alloc_count++;
        s_last_alloc_size = size;
        void *p = malloc(size > 0 ? size : 1);
        if (p) memset(p, 0xEE, size > 0 ? size : 1);
        return p;
    }

    TacticalAI2 *func_00141D40(TacticalAI2 *self, int a1, int a2, int a3, int t0);
    TacticalAI2 *func_00141EC0(TacticalAI2 *self, void *stream);
}

static void reset_mocks() {
    s_base_ctor_called = 0;
    s_base_ctor_self = 0;
    s_base_ctor_a1 = 0;
    s_base_ctor_a2 = 0;
    s_base_ctor_a3 = 0;
    s_base_ctor_t0 = 0;

    s_base_load_called = 0;
    s_base_load_self = 0;
    s_base_load_stream = 0;

    s_26ad90_called = 0;
    s_26ad90_ptr = 0;
    s_26ad90_id = 0;

    s_145680_called = 0;
    s_145680_ptr = 0;

    s_alloc_count = 0;
    s_last_alloc_size = 0;
}

static void test_tactical_ai_actions_1d40_full() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0xAA, sizeof(ai));

    TacticalAI2 *res = func_00141D40(&ai, 10, 20, 30, 5);

    assert(res == &ai);
    assert(s_base_ctor_called == 1);
    assert(s_base_ctor_self == &ai);
    assert(s_base_ctor_a1 == 10);
    assert(s_base_ctor_a2 == 20);
    assert(s_base_ctor_a3 == 30);
    assert(s_base_ctor_t0 == 5);

    assert(ai.m_vtable == (void*)D_4D7768);
    assert(s_26ad90_called == 1);
    assert(s_26ad90_ptr == &ai.field_34);
    assert(s_26ad90_id == 0x3F5);

    assert(s_145680_called == 1);
    assert(s_145680_ptr == ai.field_44);

    assert(s_alloc_count == 1);
    assert(s_last_alloc_size == 5 * 4);
    assert(ai.field_3C != 0);
    for (int i = 0; i < 5; i++) {
        assert(ai.field_3C[i] == 0);
    }

    assert(ai.field_40 == 0);
    assert(ai.field_18C == -1);
    assert(ai.field_190 == 0);
    assert(ai.field_194 == 0);
    assert(ai.field_198 == 1);
    assert(ai.field_19C == 0);
    assert(ai.field_1A0[0] == 0);
    assert(ai.field_2A0 == 0);
    assert(ai.field_2A4 == 0);
    assert(ai.field_2A8[0] == 0);
    assert(ai.field_6A8 == &ai.field_2A8[0]);
    assert(ai.field_6AC == 0);
    assert(ai.field_6B0 == 0);
    assert(ai.field_6B4 == 0);
    assert(ai.field_6B8 == 0);
    assert(ai.field_6BC == 0);
    assert(ai.field_6C0 == 0);
    assert(ai.field_2FB4 == 0);
    assert(ai.field_3080 == 0);

    for (size_t i = 0; i < sizeof(ai.field_6C4); i++) {
        assert(ai.field_6C4[i] == 0);
    }
    for (size_t i = 0; i < sizeof(ai.field_2FB8); i++) {
        assert(ai.field_2FB8[i] == 0);
    }

    assert(ai.field_198 == 1);

    free(ai.field_3C);
    printf("TACTICAL_AI_ACTIONS_TEST_0_1D40_FULL_PASSED\n");
}

static void test_tactical_ai_actions_1d40_zero_cap() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    TacticalAI2 *res = func_00141D40(&ai, 0, 0, 0, 0);

    assert(res == &ai);
    assert(s_alloc_count == 1);
    assert(s_last_alloc_size == 0);

    free(ai.field_3C);
    printf("TACTICAL_AI_ACTIONS_TEST_1_1D40_ZERO_CAP_PASSED\n");
}

static void test_tactical_ai_actions_1ec0_load() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0x55, sizeof(ai));

    TacticalAI2 *res = func_00141EC0(&ai, (void*)0x7777);

    assert(res == &ai);
    assert(s_base_load_called == 1);
    assert(s_base_load_self == &ai);
    assert(s_base_load_stream == (void*)0x7777);

    assert(ai.m_vtable == (void*)D_4D7768);
    assert(s_26ad90_called == 1);
    assert(s_26ad90_ptr == &ai.field_34);
    assert(s_26ad90_id == 0x3F5);

    assert(s_145680_called == 1);
    assert(s_145680_ptr == ai.field_44);

    assert(s_alloc_count == 1);
    assert(s_last_alloc_size == 4 * 4); // field_1C was simulated as 4
    assert(ai.field_3C != 0);
    for (int i = 0; i < 4; i++) {
        assert(ai.field_3C[i] == 0);
    }

    free(ai.field_3C);
    printf("TACTICAL_AI_ACTIONS_TEST_2_1EC0_LOAD_PASSED\n");
}

static void test_tactical_ai_actions_layout() {
    assert(offsetof(TacticalAI2, m_vtable) == 0);
    assert(offsetof(TacticalAI2, field_1C) == 0x1C);
    assert(offsetof(TacticalAI2, field_34) == 0x34);
    assert(offsetof(TacticalAI2, field_3C) == 0x3C);
    assert(offsetof(TacticalAI2, field_40) == 0x40);
    assert(offsetof(TacticalAI2, field_44) == 0x44);
    assert(offsetof(TacticalAI2, field_18C) == 0x18C);
    assert(offsetof(TacticalAI2, field_190) == 0x190);
    assert(offsetof(TacticalAI2, field_194) == 0x194);
    assert(offsetof(TacticalAI2, field_198) == 0x198);
    assert(offsetof(TacticalAI2, field_19C) == 0x19C);
    assert(offsetof(TacticalAI2, field_1A0) == 0x1A0);
    assert(offsetof(TacticalAI2, field_2A0) == 0x2A0);
    assert(offsetof(TacticalAI2, field_2A4) == 0x2A4);
    assert(offsetof(TacticalAI2, field_2A8) == 0x2A8);
    assert(offsetof(TacticalAI2, field_6A8) == 0x6A8);
    assert(offsetof(TacticalAI2, field_6AC) == 0x6AC);
    assert(offsetof(TacticalAI2, field_6B0) == 0x6B0);
    assert(offsetof(TacticalAI2, field_6B4) == 0x6B4);
    assert(offsetof(TacticalAI2, field_6B8) == 0x6B8);
    assert(offsetof(TacticalAI2, field_6BC) == 0x6BC);
    assert(offsetof(TacticalAI2, field_6C0) == 0x6C0);
    assert(offsetof(TacticalAI2, field_6C4) == 0x6C4);
    assert(offsetof(TacticalAI2, field_2FB4) == 0x2FB4);
    assert(offsetof(TacticalAI2, field_2FB8) == 0x2FB8);
    assert(offsetof(TacticalAI2, field_3080) == 0x3080);
    assert(sizeof(TacticalAI2) == 0x3084);

    printf("TACTICAL_AI_ACTIONS_TEST_3_LAYOUT_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-3)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_tactical_ai_actions_1d40_full();
    else if (mode == 1) test_tactical_ai_actions_1d40_zero_cap();
    else if (mode == 2) test_tactical_ai_actions_1ec0_load();
    else if (mode == 3) test_tactical_ai_actions_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
