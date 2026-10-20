#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct TacticalNode24 {
    char data[24];
};

struct Obj12 {
    char data[12];
};

struct PredicateItem {
    short type;
    short op_or_node;
    int a1;
    int a2;
    int a3;
    int t0;
};

struct Rule {
    char pad_0[6];
    unsigned char cond_count;
    unsigned char action_count;
    PredicateItem items[16];
};

struct TacticalAI {
    void *m_vtable;
    char pad_04[0xC];
    TacticalNode24 *field_10;
    char pad_14[0x4];
    Obj12 *field_18;
};

extern "C" {
    static int s_4550_called = 0;
    static void *s_4550_last_node = 0;
    static int s_4550_last_a1 = 0;
    static int s_4550_last_a2 = 0;
    static int s_4550_last_a3 = 0;
    static int s_4550_last_t0 = 0;
    static int s_4550_ret_values[16] = {0};
    static int s_4550_call_idx = 0;

    int func_144550(void *node, int a1, int a2, int a3, int t0) {
        s_4550_called++;
        s_4550_last_node = node;
        s_4550_last_a1 = a1;
        s_4550_last_a2 = a2;
        s_4550_last_a3 = a3;
        s_4550_last_t0 = t0;
        int ret = s_4550_ret_values[s_4550_call_idx % 16];
        s_4550_call_idx++;
        return ret;
    }

    static int s_c580_called = 0;
    static void *s_c580_last_obj = 0;
    static int s_c580_last_a1 = 0;
    static int s_c580_last_a2 = 0;
    static int s_c580_last_a3 = 0;
    static int s_c580_last_t0 = 0;

    void func_0013C580(void *obj, int a1, int a2, int a3, int t0) {
        s_c580_called++;
        s_c580_last_obj = obj;
        s_c580_last_a1 = a1;
        s_c580_last_a2 = a2;
        s_c580_last_a3 = a3;
        s_c580_last_t0 = t0;
    }

    int func_00141A70(TacticalAI *self, Rule *rule, int *p_idx);
    int func_00141C70(TacticalAI *self, Rule *rule);
}

static void reset_mocks() {
    s_4550_called = 0;
    s_4550_last_node = 0;
    s_4550_last_a1 = 0;
    s_4550_last_a2 = 0;
    s_4550_last_a3 = 0;
    s_4550_last_t0 = 0;
    memset(s_4550_ret_values, 0, sizeof(s_4550_ret_values));
    s_4550_call_idx = 0;

    s_c580_called = 0;
    s_c580_last_obj = 0;
    s_c580_last_a1 = 0;
    s_c580_last_a2 = 0;
    s_c580_last_a3 = 0;
    s_c580_last_t0 = 0;
}

static void test_tactical_ai_predicates_leaf() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    TacticalNode24 nodes[4];
    memset(nodes, 0, sizeof(nodes));
    ai.field_10 = nodes;

    Rule rule;
    memset(&rule, 0, sizeof(rule));
    rule.items[0].type = 3;
    rule.items[0].op_or_node = 2; // node index 2
    rule.items[0].a1 = 11;
    rule.items[0].a2 = 22;
    rule.items[0].a3 = 33;
    rule.items[0].t0 = 44;

    s_4550_ret_values[0] = 1;
    int idx = 0;
    int res = func_00141A70(&ai, &rule, &idx);

    assert(res == 1);
    assert(idx == 1);
    assert(s_4550_called == 1);
    assert(s_4550_last_node == &nodes[2]);
    assert(s_4550_last_a1 == 11);
    assert(s_4550_last_a2 == 22);
    assert(s_4550_last_a3 == 33);
    assert(s_4550_last_t0 == 44);
    assert(s_4550_called == 1);

    printf("TACTICAL_AI_PREDICATES_TEST_0_LEAF_PASSED\n");
}

static void test_tactical_ai_predicates_not() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    TacticalNode24 nodes[2];
    memset(nodes, 0, sizeof(nodes));
    ai.field_10 = nodes;

    Rule rule;
    memset(&rule, 0, sizeof(rule));
    // Item 0: NOT unary (type != 3, op_or_node == 0)
    rule.items[0].type = 0;
    rule.items[0].op_or_node = 0;
    // Item 1: Leaf (type == 3)
    rule.items[1].type = 3;
    rule.items[1].op_or_node = 0;

    s_4550_ret_values[0] = 1;
    int idx = 0;
    int res = func_00141A70(&ai, &rule, &idx);

    assert(res == 0); // NOT 1 -> 0
    assert(idx == 2);

    // Test NOT 0 -> 1
    reset_mocks();
    s_4550_ret_values[0] = 0;
    idx = 0;
    res = func_00141A70(&ai, &rule, &idx);
    assert(res == 1);

    printf("TACTICAL_AI_PREDICATES_TEST_1_NOT_PASSED\n");
}

static void test_tactical_ai_predicates_and_xor() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    TacticalNode24 nodes[2];
    memset(nodes, 0, sizeof(nodes));
    ai.field_10 = nodes;

    Rule rule;
    memset(&rule, 0, sizeof(rule));
    // Op 1: AND
    rule.items[0].type = 0; rule.items[0].op_or_node = 1;
    rule.items[1].type = 3; rule.items[1].op_or_node = 0;
    rule.items[2].type = 3; rule.items[2].op_or_node = 0;

    s_4550_ret_values[0] = 1; s_4550_ret_values[1] = 1;
    int idx = 0;
    assert(func_00141A70(&ai, &rule, &idx) == 1);

    reset_mocks();
    s_4550_ret_values[0] = 1; s_4550_ret_values[1] = 0;
    idx = 0;
    assert(func_00141A70(&ai, &rule, &idx) == 0);

    // Op 2: XOR
    rule.items[0].op_or_node = 2;
    reset_mocks();
    s_4550_ret_values[0] = 1; s_4550_ret_values[1] = 0;
    idx = 0;
    assert(func_00141A70(&ai, &rule, &idx) == 1);

    reset_mocks();
    s_4550_ret_values[0] = 1; s_4550_ret_values[1] = 1;
    idx = 0;
    assert(func_00141A70(&ai, &rule, &idx) == 0);

    printf("TACTICAL_AI_PREDICATES_TEST_2_AND_XOR_PASSED\n");
}

static void test_tactical_ai_predicates_or_nor() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    TacticalNode24 nodes[2];
    memset(nodes, 0, sizeof(nodes));
    ai.field_10 = nodes;

    Rule rule;
    memset(&rule, 0, sizeof(rule));
    // Op 3: OR
    rule.items[0].type = 0; rule.items[0].op_or_node = 3;
    rule.items[1].type = 3; rule.items[1].op_or_node = 0;
    rule.items[2].type = 3; rule.items[2].op_or_node = 0;

    s_4550_ret_values[0] = 0; s_4550_ret_values[1] = 1;
    int idx = 0;
    assert(func_00141A70(&ai, &rule, &idx) == 1);

    reset_mocks();
    s_4550_ret_values[0] = 0; s_4550_ret_values[1] = 0;
    idx = 0;
    assert(func_00141A70(&ai, &rule, &idx) == 0);

    // Op 4: NOR
    rule.items[0].op_or_node = 4;
    reset_mocks();
    s_4550_ret_values[0] = 0; s_4550_ret_values[1] = 0;
    idx = 0;
    assert(func_00141A70(&ai, &rule, &idx) == 1);

    reset_mocks();
    s_4550_ret_values[0] = 1; s_4550_ret_values[1] = 0;
    idx = 0;
    assert(func_00141A70(&ai, &rule, &idx) == 0);

    printf("TACTICAL_AI_PREDICATES_TEST_3_OR_NOR_PASSED\n");
}

static void test_tactical_ai_predicates_xnor_nand() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    TacticalNode24 nodes[2];
    memset(nodes, 0, sizeof(nodes));
    ai.field_10 = nodes;

    Rule rule;
    memset(&rule, 0, sizeof(rule));
    // Op 5: XNOR
    rule.items[0].type = 0; rule.items[0].op_or_node = 5;
    rule.items[1].type = 3; rule.items[1].op_or_node = 0;
    rule.items[2].type = 3; rule.items[2].op_or_node = 0;

    s_4550_ret_values[0] = 1; s_4550_ret_values[1] = 1;
    int idx = 0;
    assert(func_00141A70(&ai, &rule, &idx) == 1);

    reset_mocks();
    s_4550_ret_values[0] = 1; s_4550_ret_values[1] = 0;
    idx = 0;
    assert(func_00141A70(&ai, &rule, &idx) == 0);

    // Op 6: NAND
    rule.items[0].op_or_node = 6;
    reset_mocks();
    s_4550_ret_values[0] = 1; s_4550_ret_values[1] = 0;
    idx = 0;
    assert(func_00141A70(&ai, &rule, &idx) == 1);

    reset_mocks();
    s_4550_ret_values[0] = 1; s_4550_ret_values[1] = 1;
    idx = 0;
    assert(func_00141A70(&ai, &rule, &idx) == 0);

    printf("TACTICAL_AI_PREDICATES_TEST_4_XNOR_NAND_PASSED\n");
}

static void test_tactical_ai_predicates_default_op() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    Rule rule;
    memset(&rule, 0, sizeof(rule));
    rule.items[0].type = 0; rule.items[0].op_or_node = 99; // invalid op
    rule.items[1].type = 3;
    rule.items[2].type = 3;

    int idx = 0;
    assert(func_00141A70(&ai, &rule, &idx) == 0);

    printf("TACTICAL_AI_PREDICATES_TEST_5_DEFAULT_OP_PASSED\n");
}

static void test_tactical_ai_1c70_cond_fail() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    Rule rule;
    memset(&rule, 0, sizeof(rule));
    rule.cond_count = 2;
    rule.action_count = 3;
    rule.items[0].type = 3;
    rule.items[1].type = 3;
    rule.items[2].type = 0;

    s_4550_ret_values[0] = 0; // First condition fails

    int res = func_00141C70(&ai, &rule);

    assert(res == 0);
    assert(s_4550_called == 1);
    assert(s_c580_called == 0); // No actions executed

    printf("TACTICAL_AI_PREDICATES_TEST_6_1C70_COND_FAIL_PASSED\n");
}

static void test_tactical_ai_1c70_actions_success() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    Obj12 objs[3];
    memset(objs, 0, sizeof(objs));
    ai.field_18 = objs;

    Rule rule;
    memset(&rule, 0, sizeof(rule));
    rule.cond_count = 1;
    rule.action_count = 3;
    // Cond 0: passes
    rule.items[0].type = 3;
    rule.items[0].op_or_node = 0;

    // Action 1
    rule.items[1].op_or_node = 1;
    rule.items[1].a1 = 100;
    rule.items[1].a2 = 200;
    rule.items[1].a3 = 300;
    rule.items[1].t0 = 400;

    // Action 2
    rule.items[2].op_or_node = 2;
    rule.items[2].a1 = 500;
    rule.items[2].a2 = 600;
    rule.items[2].a3 = 700;
    rule.items[2].t0 = 800;

    s_4550_ret_values[0] = 1;

    int res = func_00141C70(&ai, &rule);

    assert(res == 1);
    assert(s_4550_called == 1);
    assert(s_c580_called == 2);
    assert(s_c580_last_obj == &objs[2]);
    assert(s_c580_last_a1 == 500);
    assert(s_c580_last_a2 == 600);
    assert(s_c580_last_a3 == 700);
    assert(s_c580_last_t0 == 800);

    printf("TACTICAL_AI_PREDICATES_TEST_7_1C70_ACTIONS_SUCCESS_PASSED\n");
}

static void test_tactical_ai_predicates_layout() {
    assert(sizeof(PredicateItem) == 20);
    assert(offsetof(PredicateItem, type) == 0);
    assert(offsetof(PredicateItem, op_or_node) == 2);
    assert(offsetof(PredicateItem, a1) == 4);
    assert(offsetof(PredicateItem, a2) == 8);
    assert(offsetof(PredicateItem, a3) == 12);
    assert(offsetof(PredicateItem, t0) == 16);
    assert(offsetof(Rule, cond_count) == 6);
    assert(offsetof(Rule, action_count) == 7);
    assert(offsetof(Rule, items) == 8);
    assert(offsetof(TacticalAI, field_10) == 0x10);
    assert(offsetof(TacticalAI, field_18) == 0x18);

    printf("TACTICAL_AI_PREDICATES_TEST_8_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_predicates_leaf();
    else if (mode == 1) test_tactical_ai_predicates_not();
    else if (mode == 2) test_tactical_ai_predicates_and_xor();
    else if (mode == 3) test_tactical_ai_predicates_or_nor();
    else if (mode == 4) test_tactical_ai_predicates_xnor_nand();
    else if (mode == 5) test_tactical_ai_predicates_default_op();
    else if (mode == 6) test_tactical_ai_1c70_cond_fail();
    else if (mode == 7) test_tactical_ai_1c70_actions_success();
    else if (mode == 8) test_tactical_ai_predicates_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
