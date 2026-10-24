#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct TacticalNode {
    int field_0;
    int field_4;
    int field_8;
    char field_C;
    int (*field_10)();
    char field_14;
    char field_15;
    char field_16;
    char field_17;
};

extern "C" {
    static int s_0670_called = 0;
    static void *s_0670_last_ptr = 0;

    void func_00100670(void *ptr) {
        s_0670_called++;
        s_0670_last_ptr = ptr;
    }

    TacticalNode *func_00144434(TacticalNode *self);
    TacticalNode *func_00144464(TacticalNode *self, int a1);
    void func_001444B4(TacticalNode *self, int a1);
    void func_001444C0(TacticalNode *self, int unused, char a2, int (*a3)(), char t0, char t1, char t2, char t3);
    void func_001444E4(TacticalNode *self);
    void func_001444F0(TacticalNode *self);
    void func_00144524(TacticalNode *self);
    void func_00144530(TacticalNode *self);
    int func_144550(TacticalNode *self, int a1, int a2, int a3, int t0);
    int func_001446A0(TacticalNode *self);
}

static void reset_mocks() {
    s_0670_called = 0;
    s_0670_last_ptr = 0;
}

static void test_tactical_ai_node_ctor() {
    reset_mocks();
    TacticalNode node;
    memset(&node, 0xEE, sizeof(node));

    TacticalNode *res = func_00144434(&node);

    assert(res == &node);
    assert(node.field_0 == 0);
    assert(node.field_4 == 0);
    assert(node.field_8 == 0);
    assert(node.field_C == 0);
    assert(node.field_10 == 0);
    assert(node.field_14 == 0);
    assert(node.field_15 == 0);
    assert(node.field_16 == 0);
    assert(node.field_17 == 0);

    printf("TACTICAL_AI_NODE_ITEM_TEST_0_CTOR_PASSED\n");
}

static int s_dummy_called = 0;
static int dummy_func() {
    s_dummy_called++;
    return 777;
}

static void test_tactical_ai_node_dtor() {
    reset_mocks();
    TacticalNode node;
    memset(&node, 0, sizeof(node));
    node.field_10 = dummy_func;

    // Destructor with flag 0 -> no free
    TacticalNode *res = func_00144464(&node, 0);
    assert(res == &node);
    assert(node.field_10 == 0);
    assert(s_0670_called == 0);

    // Destructor with flag 1 -> calls func_00100670
    res = func_00144464(&node, 1);
    assert(res == &node);
    assert(s_0670_called == 1);
    assert(s_0670_last_ptr == &node);

    // Destructor with null -> returns null
    assert(func_00144464(0, 1) == 0);

    printf("TACTICAL_AI_NODE_ITEM_TEST_1_DTOR_PASSED\n");
}

static void test_tactical_ai_node_setters() {
    TacticalNode node;
    memset(&node, 0xFF, sizeof(node));

    func_001444B4(&node, 3);
    assert(node.field_0 == 3);
    assert(node.field_4 == 0);
    assert(node.field_8 == 0);

    func_001444C0(&node, 0, 2, dummy_func, 10, 20, 30, 40);
    assert(node.field_C == 2);
    assert(node.field_10 == dummy_func);
    assert(node.field_14 == 10);
    assert(node.field_15 == 20);
    assert(node.field_16 == 30);
    assert(node.field_17 == 40);

    printf("TACTICAL_AI_NODE_ITEM_TEST_2_SETTERS_PASSED\n");
}

static void test_tactical_ai_node_eval_field0_3() {
    TacticalNode node;
    memset(&node, 0, sizeof(node));
    s_dummy_called = 0;
    node.field_0 = 3;
    node.field_10 = dummy_func;

    func_001444E4(&node);
    assert(node.field_8 == 777);
    assert(s_dummy_called == 1);

    node.field_8 = 0;
    func_001444F0(&node);
    assert(node.field_8 == 777);
    assert(s_dummy_called == 2);

    // If field_0 != 3, does nothing
    node.field_0 = 1;
    node.field_8 = 123;
    func_001444E4(&node);
    assert(node.field_8 == 123);
    assert(s_dummy_called == 2);

    printf("TACTICAL_AI_NODE_ITEM_TEST_3_EVAL_FIELD0_3_PASSED\n");
}

static void test_tactical_ai_node_resets() {
    TacticalNode node;
    memset(&node, 0, sizeof(node));

    node.field_0 = 2;
    node.field_4 = 1;
    func_00144524(&node);
    assert(node.field_4 == 0);

    node.field_0 = 1;
    node.field_4 = 1;
    func_00144524(&node);
    assert(node.field_4 == 1); // only resets if field_0 == 2

    func_00144530(&node);
    assert(node.field_4 == 0); // unconditionally resets

    printf("TACTICAL_AI_NODE_ITEM_TEST_4_RESETS_PASSED\n");
}

static void test_tactical_ai_node_144550_field0_3() {
    TacticalNode node;
    memset(&node, 0, sizeof(node));
    node.field_0 = 3;
    node.field_8 = 42;

    int res = func_144550(&node, 1, 2, 3, 4);
    assert(res == 42);

    printf("TACTICAL_AI_NODE_ITEM_TEST_5_144550_FIELD0_3_PASSED\n");
}

static int s_cached_eval_count = 0;
static int cached_func() {
    s_cached_eval_count++;
    return 100 + s_cached_eval_count;
}

static void test_tactical_ai_node_144550_field0_2_cached() {
    TacticalNode node;
    memset(&node, 0, sizeof(node));
    node.field_0 = 2;
    node.field_4 = 0;
    node.field_10 = cached_func;
    s_cached_eval_count = 0;

    // First call: evaluates
    int res1 = func_144550(&node, 0, 0, 0, 0);
    assert(res1 == 101);
    assert(node.field_4 == 1);
    assert(node.field_8 == 101);
    assert(s_cached_eval_count == 1);

    // Second call: returns cached without re-evaluating
    int res2 = func_144550(&node, 0, 0, 0, 0);
    assert(res2 == 101);
    assert(s_cached_eval_count == 1);

    // Reset field_4: allows next evaluation
    node.field_4 = 0;
    int res3 = func_144550(&node, 0, 0, 0, 0);
    assert(res3 == 102);
    assert(s_cached_eval_count == 2);

    printf("TACTICAL_AI_NODE_ITEM_TEST_6_144550_FIELD0_2_CACHED_PASSED\n");
}

static int fn_0() { return 10; }
static int fn_1(int a) { return a * 2; }
static int fn_2(int a, int b) { return a + b; }
static int fn_3(int a, int b, int c) { return a + b + c; }
static int fn_4(int a, int b, int c, int d) { return a + b + c + d; }

static void test_tactical_ai_node_144550_field0_1_params() {
    TacticalNode node;
    memset(&node, 0, sizeof(node));
    node.field_0 = 1;

    // 0 params
    node.field_C = 0;
    node.field_10 = fn_0;
    assert(func_144550(&node, 1, 2, 3, 4) == 10);

    // 1 param
    node.field_C = 1;
    node.field_10 = (int (*)())fn_1;
    assert(func_144550(&node, 5, 2, 3, 4) == 10);

    // 2 params
    node.field_C = 2;
    node.field_10 = (int (*)())fn_2;
    assert(func_144550(&node, 10, 20, 3, 4) == 30);

    // 3 params
    node.field_C = 3;
    node.field_10 = (int (*)())fn_3;
    assert(func_144550(&node, 10, 20, 30, 4) == 60);

    // 4 params
    node.field_C = 4;
    node.field_10 = (int (*)())fn_4;
    assert(func_144550(&node, 10, 20, 30, 40) == 100);

    printf("TACTICAL_AI_NODE_ITEM_TEST_7_144550_FIELD0_1_PARAMS_PASSED\n");
}

static void test_tactical_ai_node_1446a0() {
    TacticalNode node;
    memset(&node, 0, sizeof(node));
    node.field_C = 7;

    assert(func_001446A0(&node) == 7);

    node.field_C = (char)0xFE;
    assert(func_001446A0(&node) == 0xFE);

    printf("TACTICAL_AI_NODE_ITEM_TEST_8_1446A0_PASSED\n");
}

static void test_tactical_ai_node_layout() {
    assert(sizeof(TacticalNode) == 24);
    assert(offsetof(TacticalNode, field_0) == 0);
    assert(offsetof(TacticalNode, field_4) == 4);
    assert(offsetof(TacticalNode, field_8) == 8);
    assert(offsetof(TacticalNode, field_C) == 0xC);
    assert(offsetof(TacticalNode, field_10) == 0x10);
    assert(offsetof(TacticalNode, field_14) == 0x14);
    assert(offsetof(TacticalNode, field_15) == 0x15);
    assert(offsetof(TacticalNode, field_16) == 0x16);
    assert(offsetof(TacticalNode, field_17) == 0x17);

    printf("TACTICAL_AI_NODE_ITEM_TEST_9_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_node_ctor();
    else if (mode == 1) test_tactical_ai_node_dtor();
    else if (mode == 2) test_tactical_ai_node_setters();
    else if (mode == 3) test_tactical_ai_node_eval_field0_3();
    else if (mode == 4) test_tactical_ai_node_resets();
    else if (mode == 5) test_tactical_ai_node_144550_field0_3();
    else if (mode == 6) test_tactical_ai_node_144550_field0_2_cached();
    else if (mode == 7) test_tactical_ai_node_144550_field0_1_params();
    else if (mode == 8) test_tactical_ai_node_1446a0();
    else if (mode == 9) test_tactical_ai_node_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
