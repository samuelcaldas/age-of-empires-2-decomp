#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Item16 {
    int f0;
    int f4;
    short f8;
    short fA;
    int fC;
};

struct Item8 {
    short f0;
    short f2;
    int f4;
};

struct TacticalAI {
    void *m_vtable;
    short field_4;
    short field_6;
    void **field_8;
    short field_C;
    short field_E;
    void *field_10;
    short field_14;
    short field_16;
    void *field_18;
    short field_1C;
    short pad_1E;
    Item16 *field_20;
    Item8 *field_24;
    int field_28;
    int field_2C;
    int field_30;
};

extern "C" {
    char D_4D7758[16] = "VTABLE_TACTICAL";
    char D_00144440[16] = "CTOR_NODE";
    char D_00144470[16] = "DTOR_NODE";

    void func_0013C4F0(void *self) {
        (void)self;
    }

    void func_0013C510(void *self) {
        (void)self;
    }

    static int s_alloc_count = 0;
    static int s_alloc_sizes[16] = {0};
    static void *s_alloc_ptrs[16] = {0};

    void *func_100730(int size) {
        void *p = malloc(size > 0 ? size : 1);
        if (s_alloc_count < 16) {
            s_alloc_sizes[s_alloc_count] = size;
            s_alloc_ptrs[s_alloc_count] = p;
        }
        s_alloc_count++;
        return p;
    }

    static int s_vec_count = 0;
    static void *s_vec_ptrs[4] = {0};
    static void *s_vec_ctors[4] = {0};
    static void *s_vec_dtors[4] = {0};
    static int s_vec_elem_sizes[4] = {0};
    static int s_vec_counts[4] = {0};

    void *func_1004E0(void *ptr, void *ctor, void *dtor, int elem_size, int count) {
        if (s_vec_count < 4) {
            s_vec_ptrs[s_vec_count] = ptr;
            s_vec_ctors[s_vec_count] = ctor;
            s_vec_dtors[s_vec_count] = dtor;
            s_vec_elem_sizes[s_vec_count] = elem_size;
            s_vec_counts[s_vec_count] = count;
        }
        s_vec_count++;
        return ptr;
    }

    TacticalAI *func_001407B0(TacticalAI *self, int a1, int a2, int a3, int t0);
}

static void reset_mocks() {
    for (int i = 0; i < s_alloc_count && i < 16; i++) {
        if (s_alloc_ptrs[i]) {
            free(s_alloc_ptrs[i]);
            s_alloc_ptrs[i] = 0;
        }
    }
    s_alloc_count = 0;
    memset(s_alloc_sizes, 0, sizeof(s_alloc_sizes));
    memset(s_alloc_ptrs, 0, sizeof(s_alloc_ptrs));

    s_vec_count = 0;
    memset(s_vec_ptrs, 0, sizeof(s_vec_ptrs));
    memset(s_vec_ctors, 0, sizeof(s_vec_ctors));
    memset(s_vec_dtors, 0, sizeof(s_vec_dtors));
    memset(s_vec_elem_sizes, 0, sizeof(s_vec_elem_sizes));
    memset(s_vec_counts, 0, sizeof(s_vec_counts));
}

static void test_tactical_ai_init_vtable_and_zeroes() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0xEE, sizeof(ai));

    TacticalAI *res = func_001407B0(&ai, 2, 3, 4, 5);

    assert(res == &ai);
    assert(ai.m_vtable == (void*)D_4D7758);
    assert(ai.field_6 == 0);
    assert(ai.field_E == 0);
    assert(ai.field_16 == 0);
    assert(ai.field_28 == 0);
    assert(ai.field_2C == 0);
    assert(ai.field_30 == 0);

    reset_mocks();
    printf("TACTICAL_AI_INIT_TEST_0_VTABLE_AND_ZEROES_PASSED\n");
}

static void test_tactical_ai_init_field8_allocation() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    TacticalAI *res = func_001407B0(&ai, 5, 2, 2, 2);

    assert(res == &ai);
    assert(ai.field_4 == 5);
    assert(s_alloc_count >= 1);
    assert(s_alloc_sizes[0] == 20); // 5 * 4
    assert(ai.field_8 == (void**)s_alloc_ptrs[0]);

    reset_mocks();
    printf("TACTICAL_AI_INIT_TEST_1_FIELD8_ALLOCATION_PASSED\n");
}

static void test_tactical_ai_init_field10_vector_init() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    TacticalAI *res = func_001407B0(&ai, 1, 7, 1, 1);

    assert(res == &ai);
    assert(ai.field_C == 7);
    assert(s_alloc_count >= 2);
    assert(s_alloc_sizes[1] == 7 * 24 + 16); // 184
    assert(s_vec_count >= 1);
    assert(s_vec_ctors[0] == (void*)D_00144440);
    assert(s_vec_dtors[0] == (void*)D_00144470);
    assert(s_vec_elem_sizes[0] == 24);
    assert(s_vec_counts[0] == 7);
    assert(ai.field_10 == s_alloc_ptrs[1]);

    reset_mocks();
    printf("TACTICAL_AI_INIT_TEST_2_FIELD10_VECTOR_INIT_PASSED\n");
}

static void test_tactical_ai_init_field18_vector_init() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    TacticalAI *res = func_001407B0(&ai, 1, 1, 9, 1);

    assert(res == &ai);
    assert(ai.field_14 == 9);
    assert(s_alloc_count >= 3);
    assert(s_alloc_sizes[2] == 9 * 12 + 16); // 124
    assert(s_vec_count == 2);
    assert(s_vec_ctors[1] == (void*)func_0013C4F0);
    assert(s_vec_dtors[1] == (void*)func_0013C510);
    assert(s_vec_elem_sizes[1] == 12);
    assert(s_vec_counts[1] == 9);
    assert(ai.field_18 == s_alloc_ptrs[2]);

    reset_mocks();
    printf("TACTICAL_AI_INIT_TEST_3_FIELD18_VECTOR_INIT_PASSED\n");
}

static void test_tactical_ai_init_field20_item16_init() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    TacticalAI *res = func_001407B0(&ai, 1, 1, 1, 4);

    assert(res == &ai);
    assert(ai.field_1C == 4);
    assert(s_alloc_count >= 4);
    assert(s_alloc_sizes[3] == 4 * 16); // 64
    assert(ai.field_20 == (Item16*)s_alloc_ptrs[3]);
    for (int i = 0; i < 4; i++) {
        assert(ai.field_20[i].f0 == 0);
        assert(ai.field_20[i].f4 == -1);
        assert(ai.field_20[i].f8 == 0);
        assert(ai.field_20[i].fA == 0);
        assert(ai.field_20[i].fC == 0);
    }

    reset_mocks();
    printf("TACTICAL_AI_INIT_TEST_4_FIELD20_ITEM16_INIT_PASSED\n");
}

static void test_tactical_ai_init_field24_item8_init() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    TacticalAI *res = func_001407B0(&ai, 1, 1, 1, 4);

    assert(res == &ai);
    assert(ai.field_1C == 4);
    assert(s_alloc_count == 5);
    assert(s_alloc_sizes[4] == 4 * 8); // 32
    assert(ai.field_24 == (Item8*)s_alloc_ptrs[4]);
    for (int i = 0; i < 4; i++) {
        assert(ai.field_24[i].f0 == 0);
        assert(ai.field_24[i].f2 == 0);
        assert(ai.field_24[i].f4 == 0);
    }

    reset_mocks();
    printf("TACTICAL_AI_INIT_TEST_5_FIELD24_ITEM8_INIT_PASSED\n");
}

static void test_tactical_ai_init_zero_counts() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0xAA, sizeof(ai));

    TacticalAI *res = func_001407B0(&ai, 0, 0, 0, 0);

    assert(res == &ai);
    assert(ai.field_4 == 0);
    assert(ai.field_C == 0);
    assert(ai.field_14 == 0);
    assert(ai.field_1C == 0);
    assert(s_alloc_count == 5);
    assert(s_alloc_sizes[0] == 0);
    assert(s_alloc_sizes[1] == 16);
    assert(s_alloc_sizes[2] == 16);
    assert(s_alloc_sizes[3] == 0);
    assert(s_alloc_sizes[4] == 0);

    reset_mocks();
    printf("TACTICAL_AI_INIT_TEST_6_ZERO_COUNTS_PASSED\n");
}

static void test_tactical_ai_init_layout() {
    assert(sizeof(Item16) == 16);
    assert(sizeof(Item8) == 8);
    assert(offsetof(TacticalAI, m_vtable) == 0);
    assert(offsetof(TacticalAI, field_4) == 4);
    assert(offsetof(TacticalAI, field_6) == 6);
    assert(offsetof(TacticalAI, field_8) == 8);
    assert(offsetof(TacticalAI, field_C) == 0xC);
    assert(offsetof(TacticalAI, field_E) == 0xE);
    assert(offsetof(TacticalAI, field_10) == 0x10);
    assert(offsetof(TacticalAI, field_14) == 0x14);
    assert(offsetof(TacticalAI, field_16) == 0x16);
    assert(offsetof(TacticalAI, field_18) == 0x18);
    assert(offsetof(TacticalAI, field_1C) == 0x1C);
    assert(offsetof(TacticalAI, field_20) == 0x20);
    assert(offsetof(TacticalAI, field_24) == 0x24);
    assert(offsetof(TacticalAI, field_28) == 0x28);
    assert(offsetof(TacticalAI, field_2C) == 0x2C);
    assert(offsetof(TacticalAI, field_30) == 0x30);

    printf("TACTICAL_AI_INIT_TEST_7_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_init_vtable_and_zeroes();
    else if (mode == 1) test_tactical_ai_init_field8_allocation();
    else if (mode == 2) test_tactical_ai_init_field10_vector_init();
    else if (mode == 3) test_tactical_ai_init_field18_vector_init();
    else if (mode == 4) test_tactical_ai_init_field20_item16_init();
    else if (mode == 5) test_tactical_ai_init_field24_item8_init();
    else if (mode == 6) test_tactical_ai_init_zero_counts();
    else if (mode == 7) test_tactical_ai_init_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
