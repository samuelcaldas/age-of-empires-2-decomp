#include <iostream>
#include <cassert>
#include <vector>
#include "post_trade_action_plan_step.h"
#include "trade_action_candidates_access.h"

using namespace trade_action_candidates;

static void *g_mock_item = 0;
static int g_mock_helper_2261c0_res = 12345;
static int g_call_seq = 0;
static int g_lookup_calls = 0;
static int g_lookup_seq = 0;
static void *g_last_lookup_root = 0;
static int g_last_lookup_item_id = -1;
static int g_helper_2261c0_calls = 0;
static int g_get_id_calls = 0;
static int g_get_id_seq = 0;
static int g_mock_action_1471a0 = 600;
static int g_mock_action_147170 = 0;
static int g_mock_action_147190 = 0;
static int g_action_1471a0_calls = 0;
static int g_action_147170_calls = 0;
static int g_action_147190_calls = 0;
static int g_mock_2baa20_res = 0;
static int g_dispatcher_2baa20_calls = 0;
static int g_last_2baa20_cat = -1;

static int g_mock_2c1920_res = 1;
static int g_2c1920_calls = 0;
static void *g_last_2c1920_self = 0;
static void *g_last_2c1920_record = 0;
static int g_last_2c1920_mode = -1;

static int s_pred_id = 100;
static int *s_pred_ptr = &s_pred_id;

extern "C" {
void *func_332e60(void *root, int item_id) {
    g_lookup_calls++;
    g_lookup_seq = ++g_call_seq;
    g_last_lookup_root = root;
    g_last_lookup_item_id = item_id;
    return g_mock_item;
}

int func_002261C0(void *item) {
    g_helper_2261c0_calls++;
    return g_mock_helper_2261c0_res;
}

int func_001471A0(int entity_id) {
    g_action_1471a0_calls++;
    return g_mock_action_1471a0;
}

int func_00147170(int entity_id) {
    g_action_147170_calls++;
    return g_mock_action_147170;
}

int func_00147190(int entity_id) {
    g_action_147190_calls++;
    return g_mock_action_147190;
}

int func_002C1920(void *self, void *record, void *stack_arr, int mode) {
    g_2c1920_calls++;
    g_last_2c1920_self = self;
    g_last_2c1920_record = record;
    g_last_2c1920_mode = mode;
    return g_mock_2c1920_res;
}

int func_002BAA20(void *self, int a1, int a2, int a3, void *arr) {
    g_dispatcher_2baa20_calls++;
    g_last_2baa20_cat = a2;
    return g_mock_2baa20_res;
}
}

int main(int argc, char **argv) {
    std::vector<char> storage(4096, 0);
    std::vector<char> mgr(1000, 0);
    std::vector<char> group(4000, 0);
    std::vector<char> item(256, 0);
    std::vector<void *> vtable(100, 0);

    for (int i = 0; i < 100; ++i) {
        vtable[i] = reinterpret_cast<void *>(+[](void *) -> void * {
            g_get_id_calls++;
            g_get_id_seq = ++g_call_seq;
            return s_pred_ptr;
        });
    }
    *reinterpret_cast<void ***>(item.data()) = vtable.data();
    *reinterpret_cast<float *>(item.data() + 64) = 5.0f; // health > 0.0f

    char *base = storage.data();
    store_integer(base, 176, reinterpret_cast<int>(mgr.data()));
    store_integer(mgr.data(), 172, reinterpret_cast<int>(group.data()));
    store_integer(group.data(), 2968, 0x1234);

    // Plan record setup: 1 record at self + 356
    store_integer(base, 3092, 1); // m_limit = 1 record
    store_integer(base, 356 + 0, 10); // record 0 item_id = 10
    store_integer(base, 356 + 4, 0);  // record 0 field_4 = 0
    store_integer(base, 356 + 8, 0);  // record 0 field_8 = 0
    store_integer(base, 356 + 12, 0); // record 0 field_c = 0
    store_integer(base, 356 + 20, 0); // record 0 field_14 = 0

    TradeActionState *state = reinterpret_cast<TradeActionState*>(base);

    // Case 1: missing item_id in plan records -> returns 0
    int res1 = func_002B9B30(state, 999, 0);
    assert(res1 == 0);

    // Case 2: item_id in records, but entity lookup returns NULL -> returns 0
    g_mock_item = 0;
    g_lookup_calls = 0;
    g_helper_2261c0_calls = 0;
    g_action_1471a0_calls = 0;
    g_action_147170_calls = 0;
    g_dispatcher_2baa20_calls = 0;

    int res2 = func_002B9B30(state, 10, 0);
    assert(res2 == 0);
    assert(g_lookup_calls == 1);
    assert(g_last_lookup_root == reinterpret_cast<void*>(0x1234));
    assert(g_last_lookup_item_id == 10);
    assert(g_action_1471a0_calls == 0);
    assert(g_action_147170_calls == 0);
    assert(g_dispatcher_2baa20_calls == 0);

    // Case 3: entity valid, but get_id() returns NULL -> returns 0
    g_mock_item = item.data();
    s_pred_ptr = 0; // null predicate
    g_call_seq = 0;
    g_lookup_calls = 0;
    g_get_id_calls = 0;
    g_lookup_seq = 0;
    g_get_id_seq = 0;
    g_action_1471a0_calls = 0;
    g_action_147170_calls = 0;
    g_dispatcher_2baa20_calls = 0;

    int res3 = func_002B9B30(state, 10, 0);
    assert(res3 == 0);
    assert(g_lookup_calls == 1);
    assert(g_get_id_calls == 1);
    assert(g_lookup_seq < g_get_id_seq);
    assert(g_action_1471a0_calls == 0);
    assert(g_action_147170_calls == 0);
    assert(g_dispatcher_2baa20_calls == 0);

    // Case 4: item qualified (func_001471A0 == 600) -> returns 1
    // and side effect: record + 20 updated with func_002261C0 result (12345)
    s_pred_ptr = &s_pred_id;
    g_mock_item = item.data();
    *reinterpret_cast<float *>(item.data() + 64) = 0.0f; // health <= 0.0f so it relies on action == 600
    g_mock_helper_2261c0_res = 12345;
    g_mock_action_1471a0 = 600;
    store_integer(base, 356 + 20, 0); // reset field_14 before call

    g_action_1471a0_calls = 0;
    int res4 = func_002B9B30(state, 10, 0);
    assert(res4 == 1);
    assert(g_action_1471a0_calls == 1);
    int rec_field20 = *reinterpret_cast<int*>(base + 356 + 20);
    assert(rec_field20 == 12345);

    // Case 4b: action 602 qualification -> returns 1
    g_mock_action_1471a0 = 602;
    int res4b = func_002B9B30(state, 10, 0);
    assert(res4b == 1);

    // Case 4c: action 618 qualification -> returns 1
    g_mock_action_1471a0 = 618;
    int res4c = func_002B9B30(state, 10, 0);
    assert(res4c == 1);

    // Case 5: health check qualification
    // When action is not {600, 602, 618} but health > 0.0f -> returns 1
    g_mock_action_1471a0 = 500;
    *reinterpret_cast<float *>(item.data() + 64) = 5.0f; // health > 0.0f

    int res5 = func_002B9B30(state, 10, 0);
    assert(res5 == 1);

    // Case 6: nonpositive health check with action code 702 qualification
    *reinterpret_cast<float *>(item.data() + 64) = 0.0f; // health <= 0.0f
    g_mock_action_1471a0 = 500;
    g_mock_action_147170 = 702;

    int res6 = func_002B9B30(state, 10, 0);
    assert(res6 == 1);

    // Case 7: nonpositive health with action code 710 and subtype 100 qualification
    *reinterpret_cast<float *>(item.data() + 64) = 0.0f;
    g_mock_action_1471a0 = 500;
    g_mock_action_147170 = 710;
    g_mock_action_147190 = 100;

    int res7 = func_002B9B30(state, 10, 0);
    assert(res7 == 1);

    // Case 8: record field_4 == -1 and field_8 > field_c with action != -1 returns 1
    *reinterpret_cast<float *>(item.data() + 64) = 0.0f;
    g_mock_action_1471a0 = 500; // != -1 and not {600, 602, 618}
    g_mock_action_147170 = 0;   // not 702 or 710
    store_integer(base, 356 + 4, -1); // field_4 = -1
    store_integer(base, 356 + 8, 1);  // field_8 = 1
    store_integer(base, 356 + 12, 0); // field_c = 0 (field_8 > field_c)

    int res8 = func_002B9B30(state, 10, 0);
    assert(res8 == 1);

    // Case 9: record field_4 == -1 with action == -1 calls func_002BAA20;
    // when func_002BAA20 returns 1 -> returns -1
    *reinterpret_cast<float *>(item.data() + 64) = 0.0f;
    g_mock_action_1471a0 = -1; // action == -1
    g_mock_action_147170 = 0;
    g_mock_2baa20_res = 1;     // dispatcher returns 1
    g_dispatcher_2baa20_calls = 0;
    store_integer(base, 356 + 4, -1);
    store_integer(base, 356 + 8, 1);
    store_integer(base, 356 + 12, 0);

    int res9 = func_002B9B30(state, 10, 0);
    assert(res9 == -1);
    assert(g_dispatcher_2baa20_calls == 1);

    // Case 10: when func_002BAA20 returns 0 (not 1):
    // resets record field_4, field_8, field_c to -1 and continues (eventually returns 1)
    *reinterpret_cast<float *>(item.data() + 64) = 0.0f;
    g_mock_action_1471a0 = -1;
    g_mock_action_147170 = 0;
    g_mock_2baa20_res = 0;     // dispatcher returns 0
    store_integer(base, 356 + 4, -1);
    store_integer(base, 356 + 8, 200);
    store_integer(base, 356 + 12, 50); // field_8 > field_c

    int res10 = func_002B9B30(state, 10, 0);
    assert(res10 == 1);
    int rec_f4 = *reinterpret_cast<int*>(base + 356 + 4);
    int rec_f8 = *reinterpret_cast<int*>(base + 356 + 8);
    int rec_fc = *reinterpret_cast<int*>(base + 356 + 12);
    assert(rec_f4 == -1);
    assert(rec_f8 == -1);
    assert(rec_fc == -1);

    // Case 11: record field_4 != -1 with rate check passing (rate1 > rate2)
    // and func_001471A0 == -1: invokes func_002C1920(self, &record, stack_arr, mode)
    // when func_002C1920 returns non-zero -> returns 1
    *reinterpret_cast<float *>(item.data() + 64) = 0.0f;
    g_mock_action_1471a0 = -1;
    g_mock_action_147170 = 0;
    store_integer(base, 356 + 4, 0); // field_4 = 0 (!= -1)
    store_integer(base, 3216 + 0, 10); // rate1[0] = 10 (offset 3216 = 0xC90)
    store_integer(base, 3232 + 0, 5);  // rate2[0] = 5  (offset 3232 = 0xCA0) -> rate1 > rate2!
    g_mock_2c1920_res = 1;
    g_2c1920_calls = 0;

    int res11 = func_002B9B30(state, 10, 42);
    assert(res11 == 1);
    assert(g_2c1920_calls == 1);
    assert(g_last_2c1920_self == state);
    assert(g_last_2c1920_record == reinterpret_cast<void*>(base + 356));
    assert(g_last_2c1920_mode == 42);

    // Case 12: callback-zero branch: when func_002C1920 returns 0:
    // falls through to field_8 > field_c check, reaches func_002BAA20 dispatcher
    // when dispatcher returns 1 -> returns -1
    *reinterpret_cast<float *>(item.data() + 64) = 0.0f;
    g_mock_action_1471a0 = -1;
    g_mock_action_147170 = 0;
    store_integer(base, 356 + 4, 0); // field_4 = 0 (!= -1)
    store_integer(base, 3216 + 0, 10);
    store_integer(base, 3232 + 0, 5);  // rate1 > rate2
    g_mock_2c1920_res = 0;             // callback returns 0!
    g_2c1920_calls = 0;
    store_integer(base, 356 + 8, 1);   // field_8 = 1
    store_integer(base, 356 + 12, 0);  // field_c = 0 (field_8 > field_c)
    g_mock_2baa20_res = 1;             // dispatcher returns 1
    g_dispatcher_2baa20_calls = 0;

    int res12 = func_002B9B30(state, 10, 0);
    assert(res12 == -1);
    assert(g_2c1920_calls == 1);
    assert(g_dispatcher_2baa20_calls == 1);

    // Case 13: field_8 <= field_c enters 4-category evaluation;
    // category 2 rate1 < rate2 has highest score, sorts to index 0,
    // invoking func_002BAA20 with cat=2; when dispatcher returns 1 -> returns -1
    *reinterpret_cast<float *>(item.data() + 64) = 0.0f;
    g_mock_action_1471a0 = 500;
    g_mock_action_147170 = 0;
    store_integer(base, 356 + 4, -1);
    store_integer(base, 356 + 8, 0);   // field_8 = 0
    store_integer(base, 356 + 12, 1);  // field_c = 1 (field_8 <= field_c!)
    // category rates: category 2 diff=80/100 -> score 80 (highest!)
    store_integer(base, 3216 + 0, 100); store_integer(base, 3232 + 0, 100);
    store_integer(base, 3216 + 4, 50);  store_integer(base, 3232 + 4, 100);
    store_integer(base, 3216 + 8, 20);  store_integer(base, 3232 + 8, 100);
    store_integer(base, 3216 + 12, 100); store_integer(base, 3232 + 12, 100);
    g_mock_2baa20_res = 1;             // dispatcher returns 1
    g_dispatcher_2baa20_calls = 0;
    g_last_2baa20_cat = -1;

    int res13 = func_002B9B30(state, 10, 0);
    assert(res13 == -1);
    assert(g_dispatcher_2baa20_calls >= 1);
    assert(g_last_2baa20_cat == 2);

    // Case 14: all 4 categories skipped (rate1 >= rate2);
    // field_4 == -1 triggers final fallback dispatch func_002BAA20(self, item_id, -1, 1, stack_arr)
    // and returns 1
    *reinterpret_cast<float *>(item.data() + 64) = 0.0f;
    g_mock_action_1471a0 = 500;
    g_mock_action_147170 = 0;
    store_integer(base, 356 + 4, -1);
    store_integer(base, 356 + 8, 0);
    store_integer(base, 356 + 12, 1);
    // all categories have rate1 >= rate2:
    store_integer(base, 3216 + 0, 50); store_integer(base, 3232 + 0, 50);
    store_integer(base, 3216 + 4, 50); store_integer(base, 3232 + 4, 50);
    store_integer(base, 3216 + 8, 50); store_integer(base, 3232 + 8, 50);
    store_integer(base, 3216 + 12, 50); store_integer(base, 3232 + 12, 50);
    g_mock_2baa20_res = 0;
    g_dispatcher_2baa20_calls = 0;
    g_last_2baa20_cat = -999;

    int res14 = func_002B9B30(state, 10, 0);
    assert(res14 == 1);
    assert(g_dispatcher_2baa20_calls == 1);
    assert(g_last_2baa20_cat == -1); // cat -1 passed to final dispatch

    // Case 15: func_002C1920 returns 0x100 (low byte 0):
    // must fall through to field_8 > field_c and dispatcher, returning -1
    *reinterpret_cast<float *>(item.data() + 64) = 0.0f;
    g_mock_action_1471a0 = -1;
    g_mock_action_147170 = 0;
    store_integer(base, 356 + 4, 0); // field_4 = 0 (!= -1)
    store_integer(base, 3216 + 0, 10);
    store_integer(base, 3232 + 0, 5);  // rate1 > rate2
    g_mock_2c1920_res = 0x100;         // returns 0x100 (low byte 0x00!)
    g_2c1920_calls = 0;
    store_integer(base, 356 + 8, 1);   // field_8 = 1
    store_integer(base, 356 + 12, 0);  // field_c = 0 (field_8 > field_c)
    g_mock_2baa20_res = 1;             // dispatcher returns 1
    g_dispatcher_2baa20_calls = 0;

    int res15 = func_002B9B30(state, 10, 0);
    assert(res15 == -1);
    assert(g_2c1920_calls == 1);
    assert(g_dispatcher_2baa20_calls == 1);

    std::cout << "POST TRADE ACTION PLAN STEP TEST PASSED (CASES 1-15)\n";
    return 0;
}
