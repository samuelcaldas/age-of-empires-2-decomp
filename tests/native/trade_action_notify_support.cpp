#include "trade_action_notify_support.h"

int g_bb100_calls = 0;
int g_bb100_return_val = 1;
int g_entity_lookup_calls = 0;
int g_entity_lookup_id = -1;
int g_1471a0_return_val = 600;
int g_1471c0_return_val = 0;
int g_147170_return_val = 0;
int g_147190_return_val = 0;
int g_14c430_return_val = 0;
void *g_mock_entity = 0;

int g_order_dispatch_calls = 0;
int g_order_dispatch_last_code = 0;
int g_order_dispatch_last_item = 0;
int g_order_dispatch_last_action = 0;
float g_order_dispatch_last_f15 = 0.0f;

void reset_notify_support() {
    g_bb100_calls = 0;
    g_bb100_return_val = 1;
    g_entity_lookup_calls = 0;
    g_entity_lookup_id = -1;
    g_1471a0_return_val = 600;
    g_1471c0_return_val = 0;
    g_147170_return_val = 0;
    g_147190_return_val = 0;
    g_14c430_return_val = 0;
    g_mock_entity = 0;

    g_order_dispatch_calls = 0;
    g_order_dispatch_last_code = 0;
    g_order_dispatch_last_item = 0;
    g_order_dispatch_last_action = 0;
    g_order_dispatch_last_f15 = 0.0f;
}

void mock_notify_order_fn(void *world, void *ba0, int item_id, int code,
                          int t0, int t1, int t2, int t3,
                          int action_type,
                          float f12, float f13, float f14, float f15) {
    g_order_dispatch_calls++;
    g_order_dispatch_last_code = code;
    g_order_dispatch_last_item = item_id;
    g_order_dispatch_last_action = action_type;
    g_order_dispatch_last_f15 = f15;
}

extern "C" {
int func_2BB100(void *self, int item_id, int action_type) {
    g_bb100_calls++;
    return g_bb100_return_val;
}

int func_002bb100(void *self, int item_id, int action_type) {
    return func_2BB100(self, item_id, action_type);
}

int func_001471A0(int entity_id) {
    return g_1471a0_return_val;
}

int func_001471a0(int entity_id) {
    return func_001471A0(entity_id);
}

int func_001471c0(int entity_id) {
    return g_1471c0_return_val;
}

int func_00147170(int entity_id) {
    return g_147170_return_val;
}

int func_00147190(int entity_id) {
    return g_147190_return_val;
}

int func_0014C430(int entity_id, int code) {
    return g_14c430_return_val;
}

int func_0014c430(int entity_id, int code) {
    return func_0014C430(entity_id, code);
}

void *func_332e60(void *manager, int id) {
    g_entity_lookup_calls++;
    g_entity_lookup_id = id;
    return g_mock_entity;
}

void *func_00332e60(void *manager, int id) {
    return func_332e60(manager, id);
}
}
