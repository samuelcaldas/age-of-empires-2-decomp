#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_grid_link_header_prepend.h"

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

static bool g_alloc_fail = false;

extern "C" {
void *func_1143F8(int count, int elem_size) {
    if (g_alloc_fail) {
        return 0;
    }
    return std::calloc(count, elem_size);
}
}

static void test_alloc_failure() {
    g_alloc_fail = true;
    TestLinkHeader header;
    header.count = 3;
    header.head = (TestNode *)0x1234;

    int item = 42;
    void *ret = func_001ECAF0(&header, &item);

    assert(ret == 0);
    assert(header.count == 3);
    assert(header.head == (TestNode *)0x1234);

    g_alloc_fail = false;
}

static void test_prepend_to_empty_list() {
    TestLinkHeader header;
    header.count = 0;
    header.head = 0;

    int item = 100;
    void *ret = func_001ECAF0(&header, &item);

    assert(ret != 0);
    TestNode *node = (TestNode *)ret;
    assert(header.head == node);
    assert(header.count == 1);
    assert(node->data == &item);
    assert(node->next == 0);
    assert(node->prev == 0);

    std::free(node);
}

static void test_prepend_to_non_empty_list() {
    TestLinkHeader header;
    header.count = 0;
    header.head = 0;

    int item1 = 1;
    int item2 = 2;

    TestNode *node1 = (TestNode *)func_001ECAF0(&header, &item1);
    assert(node1 != 0);
    assert(header.count == 1);
    assert(header.head == node1);

    TestNode *node2 = (TestNode *)func_001ECAF0(&header, &item2);
    assert(node2 != 0);
    assert(header.count == 2);
    assert(header.head == node2);
    assert(node2->next == node1);
    assert(node2->prev == 0);
    assert(node1->prev == node2);
    assert(node1->next == 0);
    assert(node2->data == &item2);
    assert(node1->data == &item1);

    std::free(node1);
    std::free(node2);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_alloc_failure();
        test_prepend_to_empty_list();
        test_prepend_to_non_empty_list();
        return 0;
    }

    int test_case = std::atoi(argv[1]);
    switch (test_case) {
    case 0:
        test_alloc_failure();
        break;
    case 1:
        test_prepend_to_empty_list();
        break;
    case 2:
        test_prepend_to_non_empty_list();
        break;
    default:
        return 1;
    }
    return 0;
}
