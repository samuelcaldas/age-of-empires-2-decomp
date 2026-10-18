// Tests for func_0027B810, func_0027B850, func_0027B890, func_0027B8D0 — Milestone 137 (320B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7b810.h"

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

static void test_find_by_type() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));

    Node nodes[3];
    std::memset(nodes, 0, sizeof(nodes));

    nodes[0].type = 10;
    nodes[0].next = &nodes[1];

    nodes[1].type = 20;
    nodes[1].next = &nodes[2];

    nodes[2].type = 30;
    nodes[2].next = 0;

    void *head = &nodes[0];
    std::memcpy(self + 0x1E0, &head, sizeof(void *));

    // Existing type
    assert(func_0027B810(self, 20) == &nodes[1]);
    // Non-existing type
    assert(func_0027B810(self, 99) == 0);

    printf("PASS test_find_by_type\n");
}

static void test_find_by_index() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));

    Node nodes[3];
    std::memset(nodes, 0, sizeof(nodes));

    nodes[0].count = 100;
    nodes[0].next = &nodes[1];

    nodes[1].count = 200;
    nodes[1].next = &nodes[2];

    nodes[2].count = 300;
    nodes[2].next = 0;

    void *head = &nodes[0];
    std::memcpy(self + 0x1E0, &head, sizeof(void *));

    void *out = 0;
    // 1-based index: 2 -> nodes[1]
    assert(func_0027B850(self, 2, &out) == 1);
    assert(out == &nodes[1]);

    // Out of bounds
    out = (void *)0x1234;
    assert(func_0027B850(self, 5, &out) == 0);
    assert(out == 0);

    printf("PASS test_find_by_index\n");
}

static void test_find_by_count() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));

    Node nodes[3];
    std::memset(nodes, 0, sizeof(nodes));

    nodes[0].count = 100;
    nodes[0].next = &nodes[1];

    nodes[1].count = 200;
    nodes[1].next = &nodes[2];

    nodes[2].count = 300;
    nodes[2].next = 0;

    void *head = &nodes[0];
    std::memcpy(self + 0x1E0, &head, sizeof(void *));

    void *out = 0;
    assert(func_0027B890(self, 200, &out) == 1);
    assert(out == &nodes[1]);

    out = (void *)0x1234;
    assert(func_0027B890(self, 999, &out) == 0);
    assert(out == 0);

    printf("PASS test_find_by_count\n");
}

static void test_query_count_position() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));

    Node nodes[4];
    std::memset(nodes, 0, sizeof(nodes));

    nodes[0].count = 10;
    nodes[0].next = &nodes[1];

    nodes[1].count = 50;
    nodes[1].next = &nodes[2];

    nodes[2].count = 50;
    nodes[2].next = &nodes[3];

    nodes[3].count = 90;
    nodes[3].next = 0;

    void *head = &nodes[0];
    std::memcpy(self + 0x1E0, &head, sizeof(void *));

    int out_pos = 0;
    char out_count = 0;

    // Search for 50: first match at position 2, total matches 2
    func_0027B8D0(self, 50, &out_pos, &out_count);
    assert(out_pos == 2);
    assert(out_count == 2);

    // Search for non-existent 99: pos = -1, count = -1
    func_0027B8D0(self, 99, &out_pos, &out_count);
    assert(out_pos == -1);
    assert(out_count == -1);

    printf("PASS test_query_count_position\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) test_find_by_type();
        else if (case_num == 1) test_find_by_index();
        else if (case_num == 2) test_find_by_count();
        else if (case_num == 3) test_query_count_position();
        return 0;
    }
    test_find_by_type();
    test_find_by_index();
    test_find_by_count();
    test_query_count_position();
    printf("All unit_action_build_7b810 tests passed!\n");
    return 0;
}
