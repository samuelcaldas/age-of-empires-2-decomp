#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node328 {
    union {
        struct {
            short f0;
            short f2;
            char f4;
        };
        int words[82];
    };
};

struct Item16 {
    int f0;
    int f4;
    short f8;
    short fA;
    Node328 *nodes;
};

struct Item8 {
    short f0;
    short f2;
    short *table;
};

struct TacticalNode24 {
    char pad[24];
};

struct TacticalAI {
    void *m_vtable;
    char pad_04[0x8];
    short field_C;
    short field_E;
    TacticalNode24 *field_10;
    char pad_14[0xC];
    Item16 *field_20;
    Item8 *field_24;
    short *field_28;
    int field_2C;
    int field_30;
};

extern "C" {
    static int s_1a20_valid = 1;
    static int s_1a20_called = 0;
    static void *s_1a20_last_self = 0;
    static int s_1a20_last_a1 = 0;

    int func_00141A20(void *self, int a1) {
        s_1a20_called++;
        s_1a20_last_self = self;
        s_1a20_last_a1 = a1;
        return s_1a20_valid;
    }

    static int s_alloc_count = 0;
    static int s_last_alloc_size = 0;

    void *func_100730(int size) {
        s_alloc_count++;
        s_last_alloc_size = size;
        void *p = malloc(size > 0 ? size : 1);
        if (p) memset(p, 0, size > 0 ? size : 1);
        return p;
    }

    static int s_memcpy_called = 0;

    void func_117AF8(void *dest, const void *src, int n) {
        s_memcpy_called++;
        memcpy(dest, src, n);
    }

    static int s_free_count = 0;
    static void *s_last_freed_ptr = 0;

    void func_00100630(void *ptr) {
        s_free_count++;
        s_last_freed_ptr = ptr;
        if (ptr) free(ptr);
    }

    static int s_reset_count = 0;
    static void *s_last_reset_node = 0;

    void func_001444F0(void *node) {
        s_reset_count++;
        s_last_reset_node = node;
    }

    int func_00141250(TacticalAI *self, int a1, int a2, Node328 *a3);
    int func_00141370(TacticalAI *self, int a1);
    int func_00141470(TacticalAI *self);
    void func_001414A0(TacticalAI *self);
}

static void reset_mocks() {
    s_1a20_valid = 1;
    s_1a20_called = 0;
    s_1a20_last_self = 0;
    s_1a20_last_a1 = 0;
    s_alloc_count = 0;
    s_last_alloc_size = 0;
    s_memcpy_called = 0;
    s_free_count = 0;
    s_last_freed_ptr = 0;
    s_reset_count = 0;
    s_last_reset_node = 0;
}

static void test_tactical_ai_func_1250_success_no_table() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    Item16 item;
    memset(&item, 0, sizeof(item));
    item.f8 = 5; // capacity
    item.fA = 1; // current
    Node328 node_storage[5];
    memset(node_storage, 0, sizeof(node_storage));
    item.nodes = node_storage;
    ai.field_20 = &item;

    Node328 in_node;
    memset(&in_node, 0x77, sizeof(in_node));
    in_node.f0 = 99;
    in_node.f2 = 88;
    in_node.f4 = 0;

    int res = func_00141250(&ai, 0, -1, &in_node);

    assert(res == 1);
    assert(item.fA == 2);
    assert(node_storage[1].f0 == 1);
    assert(node_storage[1].f4 == 1);
    assert(node_storage[1].f2 == 88);

    printf("TACTICAL_AI_QUERY_TEST_0_FUNC_1250_NO_TABLE_PASSED\n");
}

static void test_tactical_ai_func_1250_success_with_table() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    Item16 item16;
    memset(&item16, 0, sizeof(item16));
    item16.f8 = 5;
    item16.fA = 0;
    Node328 node_storage[5];
    memset(node_storage, 0, sizeof(node_storage));
    item16.nodes = node_storage;
    ai.field_20 = &item16;

    Item8 item8;
    memset(&item8, 0, sizeof(item8));
    short table[4] = { -1, 33, -1, -1 };
    item8.table = table;
    ai.field_24 = &item8;

    Node328 in_node;
    memset(&in_node, 0, sizeof(in_node));

    int res = func_00141250(&ai, 0, 1, &in_node);

    assert(res == 0);
    assert(item16.fA == 1);
    assert(node_storage[0].f0 == 0);
    assert(node_storage[0].f4 == 1);
    assert(node_storage[0].f2 == 33);
    assert(table[1] == 0);

    printf("TACTICAL_AI_QUERY_TEST_1_FUNC_1250_WITH_TABLE_PASSED\n");
}

static void test_tactical_ai_func_1250_capacity_full() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    Item16 item;
    memset(&item, 0, sizeof(item));
    item.f8 = 3;
    item.fA = 3;
    ai.field_20 = &item;

    Node328 in_node;
    memset(&in_node, 0, sizeof(in_node));

    int res = func_00141250(&ai, 0, -1, &in_node);

    assert(res == -1);
    assert(item.fA == 3);

    printf("TACTICAL_AI_QUERY_TEST_2_FUNC_1250_CAPACITY_FULL_PASSED\n");
}

static void test_tactical_ai_func_1370_invalid_index() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    s_1a20_valid = 0;

    int res = func_00141370(&ai, 7);

    assert(res == -1);
    assert(s_1a20_called == 1);
    assert(s_1a20_last_self == &ai);
    assert(s_1a20_last_a1 == 7);

    printf("TACTICAL_AI_QUERY_TEST_3_FUNC_1370_INVALID_INDEX_PASSED\n");
}

static void test_tactical_ai_func_1370_fast_path() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    s_1a20_valid = 1;

    Item8 item;
    memset(&item, 0, sizeof(item));
    item.f0 = 10;
    item.f2 = 2;
    ai.field_24 = &item;

    int res = func_00141370(&ai, 0);

    assert(res == 2);
    assert(item.f2 == 3);
    assert(item.f0 == 10);
    assert(s_alloc_count == 0);

    printf("TACTICAL_AI_QUERY_TEST_4_FUNC_1370_FAST_PATH_PASSED\n");
}

static void test_tactical_ai_func_1370_expansion_path() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    s_1a20_valid = 1;

    Item8 item;
    memset(&item, 0, sizeof(item));
    item.f0 = 2;
    item.f2 = 2;
    short *initial_table = (short*)malloc(2 * sizeof(short));
    initial_table[0] = 50;
    initial_table[1] = 60;
    item.table = initial_table;
    ai.field_24 = &item;

    int res = func_00141370(&ai, 0);

    assert(res == 2);
    assert(item.f2 == 3);
    assert(item.f0 == 102); // 2 + 100
    assert(s_alloc_count == 1);
    assert(s_last_alloc_size == 102 * 2);
    assert(s_free_count == 1);
    assert(s_last_freed_ptr == initial_table);
    assert(item.table[0] == 50);
    assert(item.table[1] == 60);
    for (int i = 2; i < 102; i++) {
        assert(item.table[i] == -1);
    }

    free(item.table);
    printf("TACTICAL_AI_QUERY_TEST_5_FUNC_1370_EXPANSION_PATH_PASSED\n");
}

static void test_tactical_ai_func_1370_expansion_overflow() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    s_1a20_valid = 1;

    Item8 item;
    memset(&item, 0, sizeof(item));
    item.f0 = 1950;
    item.f2 = 1950;
    short *dummy_table = (short*)malloc(2);
    item.table = dummy_table;
    ai.field_24 = &item;

    int res = func_00141370(&ai, 0);

    assert(res == -1);
    assert(item.f0 == 2050); // incremented by 100 before limit check
    assert(s_alloc_count == 0);

    free(dummy_table);
    printf("TACTICAL_AI_QUERY_TEST_6_FUNC_1370_EXPANSION_OVERFLOW_PASSED\n");
}

static void test_tactical_ai_func_1470() {
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    ai.field_28 = 0;
    assert(func_00141470(&ai) == -1);

    short val = 0x1234;
    ai.field_28 = &val;
    assert(func_00141470(&ai) == 0x1234);

    short neg = -5;
    ai.field_28 = &neg;
    assert(func_00141470(&ai) == -5);

    printf("TACTICAL_AI_QUERY_TEST_7_FUNC_1470_PASSED\n");
}

static void test_tactical_ai_func_14a0() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    TacticalNode24 nodes[3];
    memset(nodes, 0, sizeof(nodes));
    ai.field_E = 3;
    ai.field_10 = nodes;

    func_001414A0(&ai);

    assert(s_reset_count == 3);
    assert(s_last_reset_node == &nodes[2]);

    printf("TACTICAL_AI_QUERY_TEST_8_FUNC_14A0_PASSED\n");
}

static void test_tactical_ai_query_layout() {
    assert(sizeof(Node328) == 328);
    assert(sizeof(Item16) == 16);
    assert(sizeof(Item8) == 8);
    assert(sizeof(TacticalNode24) == 24);
    assert(offsetof(TacticalAI, m_vtable) == 0);
    assert(offsetof(TacticalAI, field_C) == 0xC);
    assert(offsetof(TacticalAI, field_E) == 0xE);
    assert(offsetof(TacticalAI, field_10) == 0x10);
    assert(offsetof(TacticalAI, field_20) == 0x20);
    assert(offsetof(TacticalAI, field_24) == 0x24);
    assert(offsetof(TacticalAI, field_28) == 0x28);
    assert(offsetof(TacticalAI, field_2C) == 0x2C);
    assert(offsetof(TacticalAI, field_30) == 0x30);

    printf("TACTICAL_AI_QUERY_TEST_9_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_func_1250_success_no_table();
    else if (mode == 1) test_tactical_ai_func_1250_success_with_table();
    else if (mode == 2) test_tactical_ai_func_1250_capacity_full();
    else if (mode == 3) test_tactical_ai_func_1370_invalid_index();
    else if (mode == 4) test_tactical_ai_func_1370_fast_path();
    else if (mode == 5) test_tactical_ai_func_1370_expansion_path();
    else if (mode == 6) test_tactical_ai_func_1370_expansion_overflow();
    else if (mode == 7) test_tactical_ai_func_1470();
    else if (mode == 8) test_tactical_ai_func_14a0();
    else if (mode == 9) test_tactical_ai_query_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
