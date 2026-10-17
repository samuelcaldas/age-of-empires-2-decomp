#include "trade_action_candidates_test_support.h"

int g_1471a0_calls = 0;
int g_1471a0_return_val = 0;
int g_1471c0_calls = 0;
int g_1471c0_return_val = 0;
int g_147190_calls = 0;
int g_147190_return_val = 0;
int g_332e60_calls = 0;

void *g_mock_candidate_entity = 0;
void *g_mock_linked_entity = 0;

void reset_candidates_test_support() {
    g_1471a0_calls = 0;
    g_1471a0_return_val = 0;
    g_1471c0_calls = 0;
    g_1471c0_return_val = 0;
    g_147190_calls = 0;
    g_147190_return_val = 0;
    g_332e60_calls = 0;
    g_mock_candidate_entity = 0;
    g_mock_linked_entity = 0;
}

extern "C" {
void *func_00332e60(void *manager, int id) {
    g_332e60_calls++;
    if (id == 100 || id == 101 || id == 102 || id == 200 || id == 201) {
        return g_mock_candidate_entity;
    }
    if (id == 500) {
        return g_mock_linked_entity;
    }
    return 0;
}

int func_001471a0(int entity_id) {
    g_1471a0_calls++;
    return g_1471a0_return_val;
}

int func_001471c0(int entity_id) {
    g_1471c0_calls++;
    return g_1471c0_return_val;
}

int func_00147190(int entity_id) {
    g_147190_calls++;
    return g_147190_return_val;
}
}
