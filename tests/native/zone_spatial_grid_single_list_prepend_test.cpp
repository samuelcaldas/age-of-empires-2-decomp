#include <cassert>
#include <cstddef>
#include <cstdlib>
#include "zone_spatial_grid_single_list_prepend.h"

struct Node {
    void *data;
    Node *next;
    float fx;
    float fy;
    char flag;
};

struct SingleList {
    Node *head;
};

static Node g_pool[16];
static int g_alloc_index = 0;

extern "C" {
void *func_1143F8(int count, int elem_size) {
    assert(count == 1);
    assert(elem_size == 0x14);
    assert(g_alloc_index < 16);
    return &g_pool[g_alloc_index++];
}
}

static void test_layout() {
    assert(offsetof(Node, data) == 0x0);
    assert(offsetof(Node, next) == 0x4);
    assert(offsetof(Node, fx) == 0x8);
    assert(offsetof(Node, fy) == 0xC);
    assert(offsetof(Node, flag) == 0x10);
}

static void test_prepend_single() {
    g_alloc_index = 0;
    SingleList list;
    list.head = 0;

    int dummy = 42;
    func_001ED060(&list, &dummy, 5, 1.25f, 3.75f);

    assert(list.head == &g_pool[0]);
    assert(list.head->data == &dummy);
    assert(list.head->next == 0);
    assert(list.head->flag == 5);
    assert(list.head->fx == 1.25f);
    assert(list.head->fy == 3.75f);
}

static void test_prepend_multiple() {
    g_alloc_index = 0;
    SingleList list;
    list.head = 0;

    int d1 = 100;
    int d2 = 200;
    int d3 = 300;

    func_001ED060(&list, &d1, 1, 10.0f, 20.0f);
    func_001ED060(&list, &d2, 2, 30.0f, 40.0f);
    func_001ED060(&list, &d3, 3, 50.0f, 60.0f);

    assert(list.head == &g_pool[2]);
    assert(list.head->data == &d3);
    assert(list.head->flag == 3);
    assert(list.head->fx == 50.0f);
    assert(list.head->fy == 60.0f);

    assert(list.head->next == &g_pool[1]);
    assert(list.head->next->data == &d2);
    assert(list.head->next->flag == 2);
    assert(list.head->next->fx == 30.0f);
    assert(list.head->next->fy == 40.0f);

    assert(list.head->next->next == &g_pool[0]);
    assert(list.head->next->next->data == &d1);
    assert(list.head->next->next->next == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_layout();
        test_prepend_single();
        test_prepend_multiple();
        return 0;
    }

    int test_case = std::atoi(argv[1]);
    switch (test_case) {
    case 0:
        test_layout();
        break;
    case 1:
        test_prepend_single();
        break;
    case 2:
        test_prepend_multiple();
        break;
    default:
        return 1;
    }
    return 0;
}
