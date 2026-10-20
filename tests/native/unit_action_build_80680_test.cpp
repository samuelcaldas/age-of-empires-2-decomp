// Tests for func_00280680 (and func_280680) — Milestone 151 (236B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include "unit_action_build_80680.h"

struct ActionManager {
    void *vtable;
    int field_4;
    void *action_list_head; // offset 8
};

struct ListNode {
    void *item;       // offset 0
    ListNode *next;   // offset 4
};

struct MockAction {
    void **vtable;    // offset 0
    int status;
    int cleaned_up;
};

extern "C" {
    int D_4E35DC = 0;
}

static std::vector<void *> g_freed_nodes;
static std::vector<void *> g_cleaned_items_366af0;
static std::vector<void *> g_cleaned_items_vtable26;
static std::vector<int> g_call_order; // 1: func_366af0, 2: vtable[26], 3: FreeNode

static void *g_vtable_entries[32];

static int mock_get_status(void *self) {
    MockAction *act = (MockAction *)self;
    return act->status;
}

static void mock_cleanup(void *self) {
    MockAction *act = (MockAction *)self;
    act->cleaned_up++;
    g_cleaned_items_vtable26.push_back(self);
    g_call_order.push_back(2);
}

extern "C" {
    void func_366AF0(void *factory, void *item) {
        assert(factory == &D_4E35DC);
        g_cleaned_items_366af0.push_back(item);
        g_call_order.push_back(1);
    }

    void func_138B50(void *mgr, void *node) {
        g_freed_nodes.push_back(node);
        g_call_order.push_back(3);
    }
}

static void init_vtable() {
    static bool inited = false;
    if (!inited) {
        memset(g_vtable_entries, 0, sizeof(g_vtable_entries));
        g_vtable_entries[10] = (void *)&mock_get_status; // slot 10 in C++ class
        g_vtable_entries[12] = (void *)&mock_get_status; // offset 0x30
        g_vtable_entries[24] = (void *)&mock_cleanup;    // slot 24 in C++ class
        g_vtable_entries[26] = (void *)&mock_cleanup;    // offset 0x68
        inited = true;
    }
}

static void test_empty_list() {
    ActionManager mgr;
    mgr.action_list_head = NULL;
    int count = func_00280680(&mgr);
    assert(count == 0);
    assert(mgr.action_list_head == NULL);
    printf("PASS test_empty_list\n");
}

static void test_active_count_and_removal() {
    init_vtable();
    g_freed_nodes.clear();
    g_cleaned_items_366af0.clear();
    g_cleaned_items_vtable26.clear();
    g_call_order.clear();

    MockAction act0, act1, act2, act3;
    act0.vtable = g_vtable_entries; act0.status = 2; act0.cleaned_up = 0; // retain
    act1.vtable = g_vtable_entries; act1.status = 1; act1.cleaned_up = 0; // remove
    act2.vtable = g_vtable_entries; act2.status = 3; act2.cleaned_up = 0; // remove
    act3.vtable = g_vtable_entries; act3.status = 0; act3.cleaned_up = 0; // retain

    ListNode n0, n1, n2, n3;
    n0.item = &act0; n0.next = &n1;
    n1.item = &act1; n1.next = &n2;
    n2.item = &act2; n2.next = &n3;
    n3.item = &act3; n3.next = NULL;

    ActionManager mgr;
    mgr.action_list_head = &n0;

    int active_count = func_00280680(&mgr);
    assert(active_count == 2); // act0 and act3 survive

    // Check list structure: n0 -> n3 -> NULL
    assert(mgr.action_list_head == &n0);
    assert(n0.next == &n3);
    assert(n3.next == NULL);

    // Check removals
    assert(g_freed_nodes.size() == 2);
    assert(g_freed_nodes[0] == &n1);
    assert(g_freed_nodes[1] == &n2);

    assert(g_cleaned_items_366af0.size() == 2);
    assert(g_cleaned_items_366af0[0] == &act1);
    assert(g_cleaned_items_366af0[1] == &act2);

    assert(g_cleaned_items_vtable26.size() == 2);
    assert(g_cleaned_items_vtable26[0] == &act1);
    assert(g_cleaned_items_vtable26[1] == &act2);

    // Check call order: for each removed node: 1 (func_366af0), then 2 (vtable[26]), then 3 (FreeNode)
    assert(g_call_order.size() == 6);
    assert(g_call_order[0] == 1 && g_call_order[1] == 2 && g_call_order[2] == 3);
    assert(g_call_order[3] == 1 && g_call_order[4] == 2 && g_call_order[5] == 3);

    // Retained actions were not cleaned up
    assert(act0.cleaned_up == 0);
    assert(act3.cleaned_up == 0);

    printf("PASS test_active_count_and_removal\n");
}

static void test_remove_head_node() {
    init_vtable();
    g_freed_nodes.clear();
    g_cleaned_items_366af0.clear();
    g_cleaned_items_vtable26.clear();

    MockAction act0, act1;
    act0.vtable = g_vtable_entries; act0.status = 1; act0.cleaned_up = 0; // remove head
    act1.vtable = g_vtable_entries; act1.status = 4; act1.cleaned_up = 0; // retain

    ListNode n0, n1;
    n0.item = &act0; n0.next = &n1;
    n1.item = &act1; n1.next = NULL;

    ActionManager mgr;
    mgr.action_list_head = &n0;

    int active_count = func_00280680(&mgr);
    assert(active_count == 1);
    assert(mgr.action_list_head == &n1);
    assert(n1.next == NULL);
    assert(g_freed_nodes.size() == 1);
    assert(g_freed_nodes[0] == &n0);
    printf("PASS test_remove_head_node\n");
}

static void test_alias() {
    ActionManager mgr;
    mgr.action_list_head = NULL;
    int count = func_280680(&mgr);
    assert(count == 0);
    printf("PASS test_alias\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) {
            test_empty_list();
            return 0;
        } else if (case_num == 1) {
            test_active_count_and_removal();
            return 0;
        } else if (case_num == 2) {
            test_remove_head_node();
            return 0;
        } else if (case_num == 3) {
            test_alias();
            return 0;
        }
    }
    test_empty_list();
    test_active_count_and_removal();
    test_remove_head_node();
    test_alias();
    printf("All unit_action_build_80680 tests passed!\n");
    return 0;
}
