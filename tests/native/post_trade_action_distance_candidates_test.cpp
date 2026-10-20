#include <iostream>
#include <cassert>
#include <vector>
#include "post_trade_action_distance_candidates.h"
#include "trade_action_candidates_access.h"

using namespace trade_action_candidates;

static void *g_mock_item = 0;
static int g_mock_action = 600;
static float g_mock_distance = 10.0f;
static int g_last_lookup_item_id = -1;
static int g_lookup_calls = 0;
static int g_action_calls = 0;
static int g_distance_calls = 0;

static int s_pred_id = 99;

typedef void *(*LookupFn)(void *root, int item_id);
typedef float (*DistanceFn)(float x, float y, float z, void *item);

static LookupFn g_lookup_hook = 0;
static DistanceFn g_distance_hook = 0;

extern "C" {
void *func_332e60(void *root, int item_id) {
    g_lookup_calls++;
    g_last_lookup_item_id = item_id;
    if (g_lookup_hook) {
        return g_lookup_hook(root, item_id);
    }
    return g_mock_item;
}

int func_00147170(int entity_id) {
    g_action_calls++;
    return g_mock_action;
}

float func_00269190(float x, float y, float z, void *item) {
    g_distance_calls++;
    if (g_distance_hook) {
        return g_distance_hook(x, y, z, item);
    }
    return g_mock_distance;
}
}

int main(int argc, char **argv) {
    std::vector<char> storage(4096, 0);
    std::vector<char> mgr(1000, 0);
    std::vector<char> group(4000, 0);
    std::vector<char> item(256, 0);
    std::vector<char> proto(64, 0);
    std::vector<void *> vtable(100, 0);

    char *base = storage.data();
    store_integer(base, 176, reinterpret_cast<int>(mgr.data()));
    store_integer(mgr.data(), 172, reinterpret_cast<int>(group.data()));
    store_integer(group.data(), 2968, 0x1234);

    for (int i = 0; i < 100; ++i) {
        vtable[i] = reinterpret_cast<void *>(+[](void *) -> void * {
            return &s_pred_id;
        });
    }
    *reinterpret_cast<void ***>(item.data()) = vtable.data();
    *reinterpret_cast<void **>(item.data() + 4) = proto.data();
    *reinterpret_cast<short *>(proto.data() + 8) = 100; // valid proto (not 259 or 214)
    *reinterpret_cast<short *>(item.data() + 36) = 42;  // sub_id = 42
    *reinterpret_cast<float *>(item.data() + 64) = 5.0f; // health <= 7.0f
    *reinterpret_cast<float *>(item.data() + 76) = 1.0f; // z coordinate
    g_mock_item = item.data();

    // Pool setup: 1 item (id 10)
    int pool_data[4] = {10, 20, 30, 40};
    store_integer(base, 180, reinterpret_cast<int>(pool_data));
    store_integer(base, 184, 1);  // count = 1
    store_integer(base, 192, 10); // capacity = 10

    // Exclusion setup: empty
    int excl_data[4] = {999, 999, 999, 999};
    store_integer(base, 3184, reinterpret_cast<int>(excl_data));
    store_integer(base, 3188, 0);  // excl count = 0
    store_integer(base, 3196, 10); // excl capacity = 10

    int coords[2] = {100, 200};
    TradeActionState *state = reinterpret_cast<TradeActionState*>(base);

    // Case 1: valid candidate qualifies, returns sub_id 42
    g_mock_action = 600;
    g_mock_distance = 15.0f;
    int res1 = func_002B8E30(state, coords);
    assert(res1 == 42);

    // Case 2: item is in exclusion pool -> rejected, returns -1
    excl_data[0] = 10;
    store_integer(base, 3188, 1); // excl count = 1
    int res2 = func_002B8E30(state, coords);
    assert(res2 == -1);
    store_integer(base, 3188, 0); // restore

    // Case 3: proto rejected (field8 == 259) -> rejected, returns -1
    *reinterpret_cast<short *>(proto.data() + 8) = 259;
    int res3 = func_002B8E30(state, coords);
    assert(res3 == -1);
    *reinterpret_cast<short *>(proto.data() + 8) = 214;
    assert(func_002B8E30(state, coords) == -1);
    *reinterpret_cast<short *>(proto.data() + 8) = 100; // restore

    // Case 4: health rejected (health 8.0f > 7.0f) -> rejected, returns -1
    *reinterpret_cast<float *>(item.data() + 64) = 8.0f;
    int res4 = func_002B8E30(state, coords);
    assert(res4 == -1);
    *reinterpret_cast<float *>(item.data() + 64) = 5.0f; // restore

    // Case 5: action codes rejected ({702, 718, 700, 717}) -> rejected, returns -1
    for (int bad_act : {702, 718, 700, 717}) {
        g_mock_action = bad_act;
        assert(func_002B8E30(state, coords) == -1);
    }
    g_mock_action = 600; // restore

    // Case 6: min-distance selection between two items
    store_integer(base, 184, 2); // count = 2
    std::vector<char> item2(256, 0);
    std::vector<char> proto2(64, 0);
    *reinterpret_cast<void ***>(item2.data()) = vtable.data();
    *reinterpret_cast<void **>(item2.data() + 4) = proto2.data();
    *reinterpret_cast<short *>(proto2.data() + 8) = 100;
    *reinterpret_cast<short *>(item2.data() + 36) = 77; // sub_id = 77
    *reinterpret_cast<float *>(item2.data() + 64) = 3.0f;

    // Dispatch mock item based on item_id:
    // id 10 -> dist 50.0f, sub_id 42
    // id 20 -> dist 20.0f, sub_id 77 (closer!)
    static void *s_item1 = item.data();
    static void *s_item2 = item2.data();
    g_lookup_hook = +[](void *root, int id) -> void * {
        return (id == 10) ? s_item1 : s_item2;
    };
    g_distance_hook = +[](float x, float y, float z, void *it) -> float {
        return (it == s_item1) ? 50.0f : 20.0f;
    };

    int res6 = func_002B8E30(state, coords);
    assert(res6 == 77);

    std::cout << "POST TRADE ACTION DISTANCE CANDIDATES TEST PASSED\n";
    return 0;
}
