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
    std::vector<char> group(4096, 0);
    std::vector<char> entity(256, 0);
    std::vector<void *> vtable(100, 0);

    char *base = storage.data();
    *reinterpret_cast<void **>(base + 176) = mgr.data();
    *reinterpret_cast<void **>(mgr.data() + 0x1f348) = group.data();
    *reinterpret_cast<void **>(group.data() + 2968) = mgr.data();

    vtable[356 / 4] = reinterpret_cast<void *>(+[](void *) { return 1; });
    *reinterpret_cast<void ***>(entity.data()) = vtable.data();
    g_mock_entity = entity.data();

    // Set entity health > 0.0f at offset 64
    *reinterpret_cast<float *>(entity.data() + 64) = 100.0f;

    // 1. Test pool exclusion
    int pool_item = 50;
    *reinterpret_cast<int **>(base + 3184) = &pool_item;
    store_integer(base, 3188, 1);
    store_integer(base, 3196, 16);

    int res = func_002B9770(base, 50, 10);
    assert(res == 0); // Excluded by pool membership

    // 2. Test valid notification via func_002B9770
    store_integer(base, 3188, 0); // not in pool
    res = func_002B9770(base, 50, 10);
    assert(res == 1);
    assert(g_bb100_calls == 1);

    // 3. Test func_002B97D0 (with float param stored at offset 3224)
    res = func_002B97D0(base, 51, 12, 3.14f);
    assert(res == 1);
    assert(*reinterpret_cast<float *>(base + 3224) == 3.14f);

    // 4. Test qualification branch: health <= 0.0f rejection (with class != 600/613/602/618/605)
    g_1471a0_return_val = 700;
    *reinterpret_cast<float *>(entity.data() + 64) = 0.0f;
    res = func_002B9770(base, 52, 10);
    assert(res == 0); // rejected due to health <= 0.0f
    *reinterpret_cast<float *>(entity.data() + 64) = 100.0f; // restore health

    // 5. Test qualification branch: class 613 acceptance
    g_1471a0_return_val = 613;
    res = func_002B9770(base, 53, 10);
    assert(res == 1);

    // 6. Test qualification branch: type 710 with status 100
    g_1471a0_return_val = 500;
    g_147170_return_val = 710;
    g_147190_return_val = 100;
    res = func_002B9770(base, 54, 10);
    assert(res == 1);

    // 7. Test qualification branch: type 710 with status != 100 rejection
    g_147190_return_val = 99;
    res = func_002B9770(base, 55, 10);
    assert(res == 0);

    // 8. Test return normalization (func_002bb100 returns non-zero like 5 -> normalized to 1)
    g_1471a0_return_val = 600;
    g_bb100_return_val = 5;
    res = func_002B9770(base, 56, 10);
    assert(res == 1);

    // 9. Test batch notification func_002B9830 with capacity bound
    std::vector<int> candidates = {101, 102, 103};
    *reinterpret_cast<int **>(base + 3168) = candidates.data();
    store_integer(base, 3172, 3); // count = 3
    store_integer(base, 3180, 2); // capacity = 2 (should stop at index 1)
    int batch_res = func_002B9830(base, 10, 0, 0);
    assert(batch_res == 2);

    std::cout << "TRADE ACTION NOTIFY TEST PASSED\n";
    return 0;
}
