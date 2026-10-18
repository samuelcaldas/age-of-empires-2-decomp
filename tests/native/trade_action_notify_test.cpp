#include <iostream>
#include <cassert>
#include <vector>
#include "trade_action_notify_support.h"
#include "trade_action_candidates_access.h"

using namespace trade_action_candidates;

int main(int argc, char **argv) {
    reset_notify_support();
    std::vector<char> storage(4096, 0);
    std::vector<char> mgr(130000, 0);
    std::vector<char> group(8000, 0);
    std::vector<char> entity(256, 0);
    std::vector<void *> vtable(100, 0);
    std::vector<void *> action_vtable(20, 0);

    for (int i = 0; i < 20; ++i) {
        action_vtable[i] = reinterpret_cast<void *>(&mock_notify_order_fn);
    }
    for (int i = 0; i < 100; ++i) {
        vtable[i] = reinterpret_cast<void *>(+[](void *) -> void * {
            static int s_pred_id = 1;
            return &s_pred_id;
        });
    }

    char *base = storage.data();
    *reinterpret_cast<void **>(base + 176) = mgr.data();
    *reinterpret_cast<void **>(mgr.data() + 172) = group.data();
    *reinterpret_cast<void **>(mgr.data() + 0x1f348) = group.data();
    *reinterpret_cast<void **>(group.data() + 2968) = mgr.data();

    *reinterpret_cast<void ***>(group.data() + 6960) = action_vtable.data();
    *reinterpret_cast<void ***>(group.data()) = action_vtable.data();

    *reinterpret_cast<void ***>(entity.data()) = vtable.data();
    g_mock_entity = entity.data();

    *reinterpret_cast<float *>(entity.data() + 64) = 0.0f;

    // 1. Test order notification func_002B9770 (code 706)
    int res = func_002B9770(base, 50, 10);
    assert(res == 1);
    assert(g_order_dispatch_calls == 1);
    assert(g_order_dispatch_last_code == 706);
    assert(g_order_dispatch_last_item == 50);
    assert(g_order_dispatch_last_action == 10);

    // 2. Test order notification func_002B97D0 (code 710 with param)
    res = func_002B97D0(base, 51, 12, 0.0f, 0.0f, 3.14f);
    assert(res == 1);
    assert(g_order_dispatch_calls == 2);
    assert(g_order_dispatch_last_code == 710);
    assert(g_order_dispatch_last_item == 51);
    assert(g_order_dispatch_last_action == 12);
    assert(g_order_dispatch_last_f15 == 3.14f);

    // 3. Test order notification func_002B9830 (code 724)
    res = func_002B9830(base, 52, 1, 15, 0.0f, 0.0f, 0.0f, 0.0f);
    assert(res == 1);
    assert(g_order_dispatch_calls == 3);
    assert(g_order_dispatch_last_code == 724);
    assert(g_order_dispatch_last_item == 52);
    assert(g_order_dispatch_last_action == 15);

    // 4. Test func_002B9880: pool exclusion
    int pool_item = 50;
    *reinterpret_cast<int **>(base + 3184) = &pool_item;
    store_integer(base, 3188, 1);
    store_integer(base, 3196, 16);

    res = func_002B9880(base, 50, 10);
    assert(res == 0);

    // 5. Test func_002B9880: valid notification with class 600
    store_integer(base, 3188, 0); // clear pool
    g_1471a0_return_val = 600;
    res = func_002B9880(base, 50, 10);
    assert(res == 1);

    // 6. Test func_002B9880: class 613 acceptance
    g_1471a0_return_val = 613;
    res = func_002B9880(base, 53, 10);
    assert(res == 1);

    // 7. Test func_002B9880: health check (> 0.0f rejection when not in special classes)
    g_1471a0_return_val = 700;
    *reinterpret_cast<float *>(entity.data() + 64) = 100.0f;
    res = func_002B9880(base, 52, 10);
    assert(res == 0);
    *reinterpret_cast<float *>(entity.data() + 64) = 0.0f; // restore

    // 8. Test func_002B9880: type 710 with status 100 rejection
    g_147170_return_val = 710;
    g_147190_return_val = 100;
    res = func_002B9880(base, 54, 10);
    assert(res == 0);

    // 9. Test func_002B9880: type 702 rejection
    g_147170_return_val = 702;
    res = func_002B9880(base, 55, 10);
    assert(res == 0);

    // 10. Test func_002B9880: code 705 rejection
    g_147170_return_val = 500;
    g_14c430_return_val = 1;
    res = func_002B9880(base, 56, 10);
    assert(res == 0);

    // 11. Test func_002B9880: successful dispatch to func_002bb100 with return normalization
    g_14c430_return_val = 0;
    g_bb100_return_val = 5;
    res = func_002B9880(base, 57, 10);
    assert(res == 1);
    assert(g_bb100_calls == 1);

    std::cout << "TRADE ACTION NOTIFY TEST PASSED\n";
    return 0;
}
