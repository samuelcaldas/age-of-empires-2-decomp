#include <cassert>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_link_header_clear.h"

struct TestNode {
    char pad_04[0x4];
    TestNode *next;
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

static void test_clear_empty_list() {
    g_freed_ptrs.clear();
    TestLinkHeader header;
    header.count = 5;
    header.head = 0;

    func_001EC9F0(&header);

    assert(header.count == 0);
    assert(header.head == 0);
    assert(g_freed_ptrs.empty());
}

static void test_clear_single_node() {
    g_freed_ptrs.clear();
    TestNode node;
    node.next = 0;

    TestLinkHeader header;
    header.count = 1;
    header.head = &node;

    func_001EC9F0(&header);

    assert(header.count == 0);
    assert(header.head == 0);
    assert(g_freed_ptrs.size() == 1);
    assert(g_freed_ptrs[0] == &node);
}

static void test_clear_multiple_nodes() {
    g_freed_ptrs.clear();
    TestNode n1, n2, n3;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = 0;

    TestLinkHeader header;
    header.count = 3;
    header.head = &n1;

    func_001EC9F0(&header);

    assert(header.count == 0);
    assert(header.head == 0);
    assert(g_freed_ptrs.size() == 3);
    assert(g_freed_ptrs[0] == &n1);
    assert(g_freed_ptrs[1] == &n2);
    assert(g_freed_ptrs[2] == &n3);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_clear_empty_list();
        test_clear_single_node();
        test_clear_multiple_nodes();
        return 0;
    }

    int test_case = std::atoi(argv[1]);
    switch (test_case) {
    case 0:
        test_clear_empty_list();
        break;
    case 1:
        test_clear_single_node();
        break;
    case 2:
        test_clear_multiple_nodes();
        break;
    default:
        return 1;
    }
    return 0;
}
