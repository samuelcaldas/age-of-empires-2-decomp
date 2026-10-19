#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Item16 {
    void *field_0;
    int pad[3];
};

struct Node328 {
    char pad_0[2];
    short next;
    char pad_4;
    char field_5;
    char pad_6[322];
};

struct Obj2C {
    char pad_0[0xC];
    Node328 *nodes;
};

struct Obj30 {
    char pad_0[2];
    short count;
    short *table;
};

struct TacticalAI {
    void *m_vtable;
    char pad_04[0x18];
    short field_1C;
    short pad_1E;
    Item16 *field_20;
    char pad_24[0x8];
    Obj2C *field_2C;
    Obj30 *field_30;
};

extern "C" {
    int func_001418E0(TacticalAI *self, int a1);
    int func_00141980(TacticalAI *self, int a1);
    int func_00141A20(TacticalAI *self, int a1);
}

static void test_tactical_ai_nodes_18e0_success() {
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    Node328 nodes[4];
    memset(nodes, 0, sizeof(nodes));
    nodes[1].field_5 = 1;
    nodes[1].next = 3;
    nodes[3].field_5 = 1;
    nodes[3].next = -1;

    Obj2C obj2c;
    memset(&obj2c, 0, sizeof(obj2c));
    obj2c.nodes = nodes;
    ai.field_2C = &obj2c;

    short table[3] = { -1, 1, -1 };
    Obj30 obj30;
    memset(&obj30, 0, sizeof(obj30));
    obj30.count = 3;
    obj30.table = table;
    ai.field_30 = &obj30;

    int res = func_001418E0(&ai, 1);

    assert(res == 1);
    assert(nodes[1].field_5 == 0);
    assert(nodes[3].field_5 == 0);
    assert(table[1] == 1);

    printf("TACTICAL_AI_NODES_TEST_0_18E0_SUCCESS_PASSED\n");
}

static void test_tactical_ai_nodes_18e0_null_obj30() {
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_30 = 0;

    int res = func_001418E0(&ai, 0);

    assert(res == 0);

    printf("TACTICAL_AI_NODES_TEST_1_18E0_NULL_OBJ30_PASSED\n");
}

static void test_tactical_ai_nodes_18e0_negative_index() {
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    Obj30 obj30;
    memset(&obj30, 0, sizeof(obj30));
    obj30.count = 5;
    ai.field_30 = &obj30;

    int res = func_001418E0(&ai, -1);

    assert(res == 0);

    printf("TACTICAL_AI_NODES_TEST_2_18E0_NEGATIVE_INDEX_PASSED\n");
}

static void test_tactical_ai_nodes_18e0_out_of_bounds() {
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    Obj30 obj30;
    memset(&obj30, 0, sizeof(obj30));
    obj30.count = 2;
    ai.field_30 = &obj30;

    assert(func_001418E0(&ai, 2) == 0);
    assert(func_001418E0(&ai, 100) == 0);

    printf("TACTICAL_AI_NODES_TEST_3_18E0_OUT_OF_BOUNDS_PASSED\n");
}

static void test_tactical_ai_nodes_1980_success() {
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    Node328 nodes[4];
    memset(nodes, 0, sizeof(nodes));
    nodes[0].field_5 = 0;
    nodes[0].next = 2;
    nodes[2].field_5 = 0;
    nodes[2].next = -1;

    Obj2C obj2c;
    memset(&obj2c, 0, sizeof(obj2c));
    obj2c.nodes = nodes;
    ai.field_2C = &obj2c;

    short table[2] = { 0, -1 };
    Obj30 obj30;
    memset(&obj30, 0, sizeof(obj30));
    obj30.count = 2;
    obj30.table = table;
    ai.field_30 = &obj30;

    int res = func_00141980(&ai, 0);

    assert(res == 1);
    assert(nodes[0].field_5 == 1);
    assert(nodes[2].field_5 == 1);

    printf("TACTICAL_AI_NODES_TEST_4_1980_SUCCESS_PASSED\n");
}

static void test_tactical_ai_nodes_1980_null_obj30() {
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_30 = 0;

    int res = func_00141980(&ai, 0);

    assert(res == 0);

    printf("TACTICAL_AI_NODES_TEST_5_1980_NULL_OBJ30_PASSED\n");
}

static void test_tactical_ai_nodes_1980_out_of_bounds() {
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    Obj30 obj30;
    memset(&obj30, 0, sizeof(obj30));
    obj30.count = 1;
    ai.field_30 = &obj30;

    assert(func_00141980(&ai, -5) == 0);
    assert(func_00141980(&ai, 1) == 0);

    printf("TACTICAL_AI_NODES_TEST_6_1980_OUT_OF_BOUNDS_PASSED\n");
}

static void test_tactical_ai_nodes_1a20_valid() {
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    ai.field_1C = 3;
    Item16 items[3];
    memset(items, 0, sizeof(items));
    items[0].field_0 = (void*)0x1234; // occupied
    items[1].field_0 = 0;             // free
    items[2].field_0 = (void*)0x5678; // occupied
    ai.field_20 = items;

    assert(func_00141A20(&ai, 0) == 1);
    assert(func_00141A20(&ai, 1) == 0);
    assert(func_00141A20(&ai, 2) == 1);

    printf("TACTICAL_AI_NODES_TEST_7_1A20_VALID_PASSED\n");
}

static void test_tactical_ai_nodes_1a20_out_of_bounds() {
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    ai.field_1C = 2;

    assert(func_00141A20(&ai, -1) == 0);
    assert(func_00141A20(&ai, 2) == 0);
    assert(func_00141A20(&ai, 10) == 0);

    printf("TACTICAL_AI_NODES_TEST_8_1A20_OUT_OF_BOUNDS_PASSED\n");
}

static void test_tactical_ai_nodes_layout() {
    assert(sizeof(Node328) == 328);
    assert(sizeof(Item16) == 16);
    assert(offsetof(Node328, next) == 2);
    assert(offsetof(Node328, field_5) == 5);
    assert(offsetof(Obj2C, nodes) == 0xC);
    assert(offsetof(Obj30, count) == 2);
    assert(offsetof(Obj30, table) == 4);
    assert(offsetof(TacticalAI, field_1C) == 0x1C);
    assert(offsetof(TacticalAI, field_20) == 0x20);
    assert(offsetof(TacticalAI, field_2C) == 0x2C);
    assert(offsetof(TacticalAI, field_30) == 0x30);

    printf("TACTICAL_AI_NODES_TEST_9_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_nodes_18e0_success();
    else if (mode == 1) test_tactical_ai_nodes_18e0_null_obj30();
    else if (mode == 2) test_tactical_ai_nodes_18e0_negative_index();
    else if (mode == 3) test_tactical_ai_nodes_18e0_out_of_bounds();
    else if (mode == 4) test_tactical_ai_nodes_1980_success();
    else if (mode == 5) test_tactical_ai_nodes_1980_null_obj30();
    else if (mode == 6) test_tactical_ai_nodes_1980_out_of_bounds();
    else if (mode == 7) test_tactical_ai_nodes_1a20_valid();
    else if (mode == 8) test_tactical_ai_nodes_1a20_out_of_bounds();
    else if (mode == 9) test_tactical_ai_nodes_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
