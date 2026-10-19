#include <iostream>
#include <cassert>
#include <vector>
#include "trade_action_type_checker.h"
#include "trade_action_candidates_access.h"

using namespace trade_action_candidates;

static void *g_mock_item = 0;
static int g_mock_type = 600;

extern "C" {
void *func_332e60(void *root, int item_id) {
    return g_mock_item;
}

int func_001471A0(int entity_id) {
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
            static int s_pred_id = 42;
            return &s_pred_id;
        });
    }
    *reinterpret_cast<void ***>(item.data()) = vtable.data();
    g_mock_item = item.data();

    // Case 1: item matches target_type (600)
    g_mock_type = 600;
    int res1 = func_002B90A0(base, 10, 600);
    assert(res1 == 1);

    // Case 2: item type mismatch (target_type 613 != 600)
    int res2 = func_002B90A0(base, 10, 613);
    assert(res2 == 0);

    // Case 3: item is null
    g_mock_item = 0;
    int res3 = func_002B90A0(base, 10, 600);
    assert(res3 == 0);

    // Case 4: item predicate returns null
    g_mock_item = item.data();
    for (int i = 0; i < 100; ++i) {
        vtable[i] = reinterpret_cast<void *>(+[](void *) -> void * {
            return 0;
        });
    }
    int res4 = func_002B90A0(base, 10, 600);
    assert(res4 == 0);

    // Case 5: func_002B9130 stub execution
    func_002B9130();

    std::cout << "TRADE ACTION TYPE CHECKER TEST PASSED\n";
    return 0;
}
