#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_lookup_node.h"

struct MockListNode {
    void *elem;
    MockListNode *next;
    MockListNode *prev;
};

struct MockGrid {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    MockListNode *field_14;
    int field_18;
};

static std::vector<int> call_log;
static std::vector<void *> observed_extracted_elems;
static std::vector<const void *> observed_strcmp_s1;
static std::vector<const void *> observed_strcmp_s2;

extern "C" {
void *func_001F6CD0(SpatialItem *item) {
    call_log.push_back(100);
    observed_extracted_elems.push_back(item);
    // In our test, item itself points to the string key
    return reinterpret_cast<void *>(item);
}

int func_0011AA78(const void *s1, const void *s2) {
    call_log.push_back(200);
    observed_strcmp_s1.push_back(s1);
    observed_strcmp_s2.push_back(s2);
    if (s1 == NULL || s2 == NULL) {
        return (s1 == s2) ? 0 : 1;
    }
    return std::strcmp(reinterpret_cast<const char *>(s1), reinterpret_cast<const char *>(s2));
}
}

int main() {
    assert(offsetof(MockGrid, field_14) == 0x14);
    assert(offsetof(MockListNode, elem) == 0x00);
    assert(offsetof(MockListNode, next) == 0x04);
    assert(offsetof(MockListNode, prev) == 0x08);

    MockGrid grid;
    std::memset(&grid, 0, sizeof(grid));
    ZoneSpatialGrid *grid_ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);

    MockListNode sentinel;
    sentinel.elem = NULL;
    sentinel.next = &sentinel;
    sentinel.prev = &sentinel;
    grid.field_14 = &sentinel;

    // Test Case 1: Null handle
    // Must return NULL immediately; 0 calls
    call_log.clear();
    ListNode *res1 = func_001F2E00(grid_ptr, NULL);
    assert(res1 == NULL);
    assert(call_log.empty());

    // Test Case 2: Empty list (sentinel->prev == sentinel)
    // Must return NULL immediately without strcmp calls
    call_log.clear();
    char target_key[] = "item_target";
    ListNode *res2 = func_001F2E00(grid_ptr, target_key);
    assert(res2 == NULL);
    assert(call_log.empty());

    // Setup 2-node list: sentinel <-> node1 <-> node2 <-> sentinel
    char key1[] = "alpha";
    char key2[] = "beta";

    MockListNode node1;
    node1.elem = key1;
    node1.next = NULL;
    node1.prev = NULL;

    MockListNode node2;
    node2.elem = key2;
    node2.next = NULL;
    node2.prev = NULL;

    sentinel.next = &node1;
    node1.prev = &sentinel;
    node1.next = &node2;
    node2.prev = &node1;
    node2.next = &sentinel;
    sentinel.prev = &node2;

    // Test Case 3: Item not found in list
    // Must traverse backward (node2 then node1) and return NULL
    call_log.clear();
    observed_extracted_elems.clear();
    observed_strcmp_s1.clear();
    observed_strcmp_s2.clear();

    char missing_key[] = "gamma";
    ListNode *res3 = func_001F2E00(grid_ptr, missing_key);
    assert(res3 == NULL);

    // Call count: 2 nodes checked -> 2 pairs of (func_001F6CD0, func_0011AA78)
    assert(call_log.size() == 4);
    assert(call_log[0] == 100); // node2 func_001F6CD0
    assert(call_log[1] == 200); // node2 strcmp
    assert(call_log[2] == 100); // node1 func_001F6CD0
    assert(call_log[3] == 200); // node1 strcmp

    // Backward order: node2 ("beta") first, then node1 ("alpha")
    assert(observed_extracted_elems[0] == key2);
    assert(observed_extracted_elems[1] == key1);
    assert(observed_strcmp_s2[0] == missing_key);
    assert(observed_strcmp_s2[1] == missing_key);

    // Test Case 4: Item found in list (matching node1 "alpha")
    call_log.clear();
    observed_extracted_elems.clear();
    observed_strcmp_s1.clear();
    observed_strcmp_s2.clear();

    ListNode *res4 = func_001F2E00(grid_ptr, key1);
    assert(res4 == reinterpret_cast<ListNode *>(&node1));

    // Traversal checked node2 (no match: 100, 200), then node1 (match: 100, 200, plus loop exit check: 100, 200)
    assert(call_log.size() >= 4);
    assert(observed_extracted_elems[0] == key2); // node2 checked first
    assert(observed_extracted_elems[1] == key1); // node1 checked second

    // Test Case 5: Duplicate node order (backward search preference)
    // Setup list: sentinel <-> nodeA ("dup") <-> nodeB ("dup") <-> sentinel
    char dup_key[] = "duplicate";
    MockListNode nodeA;
    nodeA.elem = dup_key;
    MockListNode nodeB;
    nodeB.elem = dup_key;

    sentinel.next = &nodeA;
    nodeA.prev = &sentinel;
    nodeA.next = &nodeB;
    nodeB.prev = &nodeA;
    nodeB.next = &sentinel;
    sentinel.prev = &nodeB;

    call_log.clear();
    observed_extracted_elems.clear();

    ListNode *res5 = func_001F2E00(grid_ptr, dup_key);
    // Backward search must hit nodeB (tail) first and return nodeB!
    assert(res5 == reinterpret_cast<ListNode *>(&nodeB));
    assert(observed_extracted_elems[0] == dup_key); // nodeB checked first

    return 0;
}
