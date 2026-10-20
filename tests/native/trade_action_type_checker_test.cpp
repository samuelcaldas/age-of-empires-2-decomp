#include <iostream>
#include <cassert>
#include <vector>
#include "trade_action_type_checker.h"
#include "trade_action_candidates_access.h"

using namespace trade_action_candidates;

static void *g_mock_item = 0;
static int g_mock_type = 600;
static void *g_last_lookup_root = 0;
static int g_last_lookup_item_id = -1;
static int g_last_predicate_entity_id = -1;
static int g_lookup_calls = 0;
static int g_predicate_calls = 0;

static int s_pred_id = 42;

extern "C" {
void *func_332e60(void *root, int item_id) {
    g_lookup_calls++;
    g_last_lookup_root = root;
    g_last_lookup_item_id = item_id;
    return g_mock_item;
}

int func_001471A0(int entity_id) {
    g_predicate_calls++;
    g_last_predicate_entity_id = entity_id;
    return g_mock_type;
}
}

int main(int argc, char **argv) {
    std::vector<char> storage(1024, 0);
    std::vector<char> mgr(130000, 0);
    std::vector<char> group(4096, 0);
    std::vector<char> item(256, 0);
    std::vector<void *> vtable(100, 0);

    char *base = storage.data();
    store_integer(base, 176, reinterpret_cast<int>(mgr.data()));
    store_integer(mgr.data(), 127816, reinterpret_cast<int>(group.data()));
    store_integer(group.data(), 2968, 0x1234);

    for (int i = 0; i < 100; ++i) {
        vtable[i] = reinterpret_cast<void *>(+[](void *) -> void * {
            return &s_pred_id;
        });
    }
    *reinterpret_cast<void ***>(item.data()) = vtable.data();
    g_mock_item = item.data();

    // Case 1: item matches target_type (600), verify argument forwarding
    g_mock_type = 600;
    s_pred_id = 42;
    int res1 = func_002B90A0(base, 10, 600);
    assert(res1 == 1);
    assert(g_last_lookup_root == reinterpret_cast<void*>(0x1234));
    assert(g_last_lookup_item_id == 10);
    assert(g_last_predicate_entity_id == 42);

    // Case 2: item type mismatch (target_type 613 != 600), verify item_id forwarding
    int res2 = func_002B90A0(base, 77, 613);
    assert(res2 == 0);
    assert(g_last_lookup_item_id == 77);
    assert(g_last_predicate_entity_id == 42);

    // Case 3: item is null
    g_mock_item = 0;
    int res3 = func_002B90A0(base, 88, 600);
    assert(res3 == 0);
    assert(g_last_lookup_item_id == 88);

    // Case 4: item predicate returns null
    g_mock_item = item.data();
    for (int i = 0; i < 100; ++i) {
        vtable[i] = reinterpret_cast<void *>(+[](void *) -> void * {
            return 0;
        });
    }
    int res4 = func_002B90A0(base, 99, 600);
    assert(res4 == 0);
    assert(g_last_lookup_item_id == 99);

    // Case 5: distinct entity ID and target type forwarding
    for (int i = 0; i < 100; ++i) {
        vtable[i] = reinterpret_cast<void *>(+[](void *) -> void * {
            return &s_pred_id;
        });
    }
    s_pred_id = 12345;
    g_mock_type = 718;
    int res5 = func_002B90A0(base, 555, 718);
    assert(res5 == 1);
    assert(g_last_lookup_item_id == 555);
    assert(g_last_predicate_entity_id == 12345);

    // Case 6: func_002B9130 stub execution
    func_002B9130();

    std::cout << "TRADE ACTION TYPE CHECKER TEST PASSED\n";
    return 0;
}
