#include <cassert>
#include <cstdlib>
#include <vector>
#include "zone_spatial_grid_single_list_destructor.h"

struct Node {
    char pad_04[0x4];
    Node *next;
};

struct SingleList {
    Node *head;
};

static std::vector<void *> g_freed_nodes;
static int g_delete_call_count = 0;
static void *g_delete_last_ptr = 0;

extern "C" {
void func_116F68(void *ptr) {
    g_freed_nodes.push_back(ptr);
}

void func_100670(void *ptr) {
    g_delete_call_count++;
    g_delete_last_ptr = ptr;
}
}

static void test_null_self() {
    g_freed_nodes.clear();
    g_delete_call_count = 0;
    void *ret = func_001ECFE0(0, 1);
    assert(ret == 0);
    assert(g_freed_nodes.empty());
    assert(g_delete_call_count == 0);
}

static void test_empty_list_no_free() {
    g_freed_nodes.clear();
    g_delete_call_count = 0;
    SingleList list;
    list.head = 0;

    void *ret = func_001ECFE0(&list, 0);
    assert(ret == &list);
    assert(list.head == 0);
    assert(g_freed_nodes.empty());
    assert(g_delete_call_count == 0);
}

static void test_empty_list_with_free() {
    g_freed_nodes.clear();
    g_delete_call_count = 0;
    SingleList list;
    list.head = 0;

    void *ret = func_001ECFE0(&list, 1);
    assert(ret == &list);
    assert(list.head == 0);
    assert(g_freed_nodes.empty());
    assert(g_delete_call_count == 1);
    assert(g_delete_last_ptr == &list);
}

static void test_multi_node_list() {
    g_freed_nodes.clear();
    g_delete_call_count = 0;
    Node n3;
    n3.next = 0;
    Node n2;
    n2.next = &n3;
    Node n1;
    n1.next = &n2;

    SingleList list;
    list.head = &n1;

    void *ret = func_001ECFE0(&list, 0);
    assert(ret == &list);
    assert(list.head == 0);
    assert(g_freed_nodes.size() == 3);
    assert(g_freed_nodes[0] == &n1);
    assert(g_freed_nodes[1] == &n2);
    assert(g_freed_nodes[2] == &n3);
    assert(g_delete_call_count == 0);
}

static void test_multi_node_with_free() {
    g_freed_nodes.clear();
    g_delete_call_count = 0;
    Node n2;
    n2.next = 0;
    Node n1;
    n1.next = &n2;

    SingleList list;
    list.head = &n1;

    void *ret = func_001ECFE0(&list, 2);
    assert(ret == &list);
    assert(list.head == 0);
    assert(g_freed_nodes.size() == 2);
    assert(g_freed_nodes[0] == &n1);
    assert(g_freed_nodes[1] == &n2);
    assert(g_delete_call_count == 1);
    assert(g_delete_last_ptr == &list);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_null_self();
        test_empty_list_no_free();
        test_empty_list_with_free();
        test_multi_node_list();
        test_multi_node_with_free();
        return 0;
    }

    int test_case = std::atoi(argv[1]);
    switch (test_case) {
    case 0:
        test_null_self();
        break;
    case 1:
        test_empty_list_no_free();
        break;
    case 2:
        test_empty_list_with_free();
        break;
    case 3:
        test_multi_node_list();
        break;
    case 4:
        test_multi_node_with_free();
        break;
    default:
        return 1;
    }
    return 0;
}
