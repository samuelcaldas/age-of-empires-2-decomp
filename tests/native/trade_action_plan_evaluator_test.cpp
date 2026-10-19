#include <iostream>
#include <cassert>
#include <vector>
#include "trade_action_plan_evaluator.h"
#include "trade_action_candidates_access.h"

using namespace trade_action_candidates;

int g_1471a0_ret = 609;
int g_1471c0_ret = 50;
int g_1880d0_ret = 1;
void *g_mock_item = 0;

void *D_004E3180 = (void *)0x12345;

extern "C" {
int func_001471a0(int entity_id) {
    return g_1471a0_ret;
}
int func_001471c0(int entity_id) {
    return g_1471c0_ret;
}
void *func_00144d10(void *mgr, int idx) {
    return g_mock_item;
}
int func_001880d0(void *gp_obj) {
    return g_1880d0_ret;
}
int func_00123350(float val) {
    return static_cast<int>(val);
}
}

int main(int argc, char **argv) {
    std::vector<char> storage(4096, 0);
    std::vector<char> mgr(1000, 0);
    std::vector<char> item(256, 0);
    std::vector<char> proto(64, 0);
    std::vector<void *> vtable(100, 0);

    char *base = storage.data();
    store_integer(base, 176, reinterpret_cast<int>(mgr.data()));

    for (int i = 0; i < 100; ++i) {
        vtable[i] = reinterpret_cast<void *>(+[](void *) -> void * {
            static int s_pred_id = 1;
            return &s_pred_id;
        });
    }
    *reinterpret_cast<void ***>(item.data()) = vtable.data();
    *reinterpret_cast<void **>(item.data() + 4) = proto.data();
    *reinterpret_cast<short *>(proto.data() + 8) = 259;
    *reinterpret_cast<short *>(item.data() + 36) = 10;
    g_mock_item = item.data();

    // Setup 1 plan item at self + 0
    store_integer(base, 3092, 1); // limit = 1 item
    store_integer(base, 356, 10); // item id = 10
    store_integer(base, 360, 2);  // slot = 2

    // Setup rates inputs
    store_integer(base, 2612, 10);
    store_integer(base, 2768, 10);
    store_integer(base, 2608, 20);
    store_integer(base, 2772, 20);
    store_integer(base, 2616, 30);
    store_integer(base, 2764, 30);
    store_integer(base, 2604, 40);
    store_integer(base, 2760, 40);
    store_integer(base, 3096, 100);

    func_002B9140(base);

    // Assert that item matched type 609 at slot 2
    assert(integer_at(base, 3216 + 2 * 4) == 1);
    // Assert that slot in item memory was reset to 0 because item was not in pool
    assert(integer_at(base, 360) == 0);

    // Test case 2: item is in pool -> slot should NOT be reset
    int pool_data[2] = {10, 20};
    store_integer(base, 3184, reinterpret_cast<int>(pool_data));
    store_integer(base, 3188, 2); // count = 2
    store_integer(base, 3196, 5); // capacity = 5
    store_integer(base, 360, 3);  // slot = 3

    func_002B9140(base);
    assert(integer_at(base, 360) == 3); // slot preserved
    assert(integer_at(base, 3216 + 3 * 4) == 1);

    // Test case 3: verify selection sort in m_indices (3200..3212)
    // Indices must be sorted descending by rate (m_rates at 3232..3244)
    int idx0 = integer_at(base, 3200);
    int idx1 = integer_at(base, 3204);
    int idx2 = integer_at(base, 3208);
    int idx3 = integer_at(base, 3212);
    int rate0 = integer_at(base, 3232 + idx0 * 4);
    int rate1 = integer_at(base, 3232 + idx1 * 4);
    int rate2 = integer_at(base, 3232 + idx2 * 4);
    int rate3 = integer_at(base, 3232 + idx3 * 4);
    assert(rate0 >= rate1);
    assert(rate1 >= rate2);
    assert(rate2 >= rate3);

    std::cout << "TRADE ACTION PLAN EVALUATOR TEST PASSED\n";
    return 0;
}
