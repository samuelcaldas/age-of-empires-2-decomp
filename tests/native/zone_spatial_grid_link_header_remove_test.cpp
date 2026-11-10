#include <cassert>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_link_header_remove.h"

struct TestNode {
    void *data;
    TestNode *next;
    TestNode *prev;
};

struct TestLinkHeader {
    short count;
    char pad_02[2];
    TestNode *head;
};

static std::vector<void *> g_freed_ptrs;

extern "C" {
void func_116F68(void *ptr) {
    g_freed_ptrs.push_back(ptr);
}
}

static void test_empty_list_does_nothing() {
    g_freed_ptrs.clear();
    TestLinkHeader header;
    header.count = 0;
    header.head = 0;

    int elem = 42;
    func_001ECA40(&header, &elem, 0);

    assert(header.count == 0);
    assert(header.head == 0);
    assert(g_freed_ptrs.empty());
}

static void test_remove_by_node_ptr_head() {
    g_freed_ptrs.clear();
    TestNode n1, n2;
    int e1 = 1, e2 = 2;
    n1.data = &e1; n1.prev = 0; n1.next = &n2;
    n2.data = &e2; n2.prev = &n1; n2.next = 0;

    TestLinkHeader header;
    header.count = 2;
    header.head = &n1;

    func_001ECA40(&header, 0, &n1);

    assert(header.count == 1);
    assert(header.head == &n2);
    assert(n2.prev == 0);
    assert(g_freed_ptrs.size() == 1);
    assert(g_freed_ptrs[0] == &n1);
}

static void test_remove_by_node_ptr_tail() {
    g_freed_ptrs.clear();
    TestNode n1, n2;
    int e1 = 1, e2 = 2;
    n1.data = &e1; n1.prev = 0; n1.next = &n2;
    n2.data = &e2; n2.prev = &n1; n2.next = 0;

    TestLinkHeader header;
    header.count = 2;
    header.head = &n1;

    func_001ECA40(&header, 0, &n2);

    assert(header.count == 1);
    assert(header.head == &n1);
    assert(n1.next == 0);
    assert(g_freed_ptrs.size() == 1);
    assert(g_freed_ptrs[0] == &n2);
}

static void test_search_and_remove_by_elem() {
    g_freed_ptrs.clear();
    TestNode n1, n2, n3;
    int e1 = 10, e2 = 20, e3 = 30;
    n1.data = &e1; n1.prev = 0; n1.next = &n2;
    n2.data = &e2; n2.prev = &n1; n2.next = &n3;
    n3.data = &e3; n3.prev = &n2; n3.next = 0;

    TestLinkHeader header;
    header.count = 3;
    header.head = &n1;

    // Search for e2
    func_001ECA40(&header, &e2, 0);

    assert(header.count == 2);
    assert(header.head == &n1);
    assert(n1.next == &n3);
    assert(n3.prev == &n1);
    assert(g_freed_ptrs.size() == 1);
    assert(g_freed_ptrs[0] == &n2);

    // Search for non-existent element
    int missing = 999;
    func_001ECA40(&header, &missing, 0);
    assert(header.count == 2);
    assert(header.head == &n1);
    assert(g_freed_ptrs.size() == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_empty_list_does_nothing();
        test_remove_by_node_ptr_head();
        test_remove_by_node_ptr_tail();
        test_search_and_remove_by_elem();
        return 0;
    }

    int test_case = std::atoi(argv[1]);
    switch (test_case) {
    case 0:
        test_empty_list_does_nothing();
        break;
    case 1:
        test_remove_by_node_ptr_head();
        break;
    case 2:
        test_remove_by_node_ptr_tail();
        break;
    case 3:
        test_search_and_remove_by_elem();
        break;
    default:
        return 1;
    }
    return 0;
}
