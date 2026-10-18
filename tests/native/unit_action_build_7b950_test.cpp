// Tests for func_0027B950 (and func_27B950) — Milestone 138 (320B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7b950.h"

struct Node {
    unsigned char type;
    unsigned char pad[3];
    int count;
    int timestamp;
    float val1;
    float val2;
    float param;
    void *next;
};

static int g_func_117CAC_called = 0;
static void *g_last_cleared_ptr = 0;

extern "C" {
    void *func_117CAC(void *dest, int val, unsigned int size) {
        g_func_117CAC_called++;
        g_last_cleared_ptr = dest;
        return std::memset(dest, val, size);
    }
}

static void test_fewer_than_4_nodes() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));

    Node nodes[2];
    std::memset(nodes, 0, sizeof(nodes));

    nodes[0].type = 0xB;
    nodes[0].next = &nodes[1];

    nodes[1].type = 0xB;
    nodes[1].next = 0;

    void *head = &nodes[0];
    std::memcpy(self + 0x1E0, &head, sizeof(void *));

    Node new_node;
    std::memset(&new_node, 0, sizeof(new_node));
    new_node.type = 0xB;
    new_node.param = 0.0f;

    int ret = func_0027B950(self, &new_node);
    assert(ret == 1);
    assert(new_node.param == 1.0f);

    printf("PASS test_fewer_than_4_nodes\n");
}

static void test_prune_lowest_candidate() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));

    Node nodes[4];
    std::memset(nodes, 0, sizeof(nodes));

    // 4 existing type 0xB nodes:
    // nodes[0]: val2 = 30.0f
    // nodes[1]: val2 = 10.0f (lowest val2, so new_val2 (50.0) - 10.0 = 40.0 is max diff!)
    // nodes[2]: val2 = 25.0f
    // nodes[3]: val2 = 40.0f
    nodes[0].type = 0xB; nodes[0].val2 = 30.0f; nodes[0].next = &nodes[1];
    nodes[1].type = 0xB; nodes[1].val2 = 10.0f; nodes[1].next = &nodes[2];
    nodes[2].type = 0xB; nodes[2].val2 = 25.0f; nodes[2].next = &nodes[3];
    nodes[3].type = 0xB; nodes[3].val2 = 40.0f; nodes[3].next = 0;

    void *head = &nodes[0];
    std::memcpy(self + 0x1E0, &head, sizeof(void *));

    Node new_node;
    std::memset(&new_node, 0, sizeof(new_node));
    new_node.type = 0xB;
    new_node.val2 = 50.0f;

    g_func_117CAC_called = 0;
    int ret = func_0027B950(self, &new_node);
    assert(ret == 1);

    // nodes[1] should be unlinked and cleared:
    // nodes[0]->next should now point to nodes[2]
    assert(nodes[0].next == &nodes[2]);
    assert(g_func_117CAC_called == 1);
    assert(g_last_cleared_ptr == &nodes[1]);

    printf("PASS test_prune_lowest_candidate\n");
}

static void test_purge_new_node_if_no_lower_candidate() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));

    Node nodes[4];
    std::memset(nodes, 0, sizeof(nodes));

    // 4 existing type 0xB nodes all have val2 >= 100.0f
    for (int i = 0; i < 4; ++i) {
        nodes[i].type = 0xB;
        nodes[i].val2 = 100.0f + (float)i * 10.0f;
        nodes[i].next = (i < 3) ? &nodes[i + 1] : 0;
    }

    Node new_node;
    std::memset(&new_node, 0, sizeof(new_node));
    new_node.type = 0xB;
    new_node.val2 = 5.0f; // Lower than all existing nodes -> no candidate has curr->val2 < new_val2!
    new_node.next = &nodes[0];

    // new_node is at the head of self->list_head
    void *head = &new_node;
    std::memcpy(self + 0x1E0, &head, sizeof(void *));

    g_func_117CAC_called = 0;
    int ret = func_0027B950(self, &new_node);
    assert(ret == 0);

    // new_node should be unlinked from head:
    assert(*(void **)(self + 0x1E0) == &nodes[0]);
    assert(g_func_117CAC_called == 1);
    assert(g_last_cleared_ptr == &new_node);

    // Verify alias func_27B950
    assert(func_27B950(self, &new_node) == 0);

    printf("PASS test_purge_new_node_if_no_lower_candidate\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) test_fewer_than_4_nodes();
        else if (case_num == 1) test_prune_lowest_candidate();
        else if (case_num == 2) test_purge_new_node_if_no_lower_candidate();
        return 0;
    }
    test_fewer_than_4_nodes();
    test_prune_lowest_candidate();
    test_purge_new_node_if_no_lower_candidate();
    printf("All unit_action_build_7b950 tests passed!\n");
    return 0;
}
