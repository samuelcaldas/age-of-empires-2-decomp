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
}

extern "C" {
int func_002bb100(void *self, int item_id, int action_type) {
    g_bb100_calls++;
    return g_bb100_return_val;
}

int func_001471a0(int entity_id) {
    return g_1471a0_return_val;
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

int func_0014c430(int entity_id, int code) {
    return g_14c430_return_val;
}

void *func_00332e60(void *manager, int id) {
    g_entity_lookup_calls++;
    g_entity_lookup_id = id;
    return g_mock_entity;
}
}
