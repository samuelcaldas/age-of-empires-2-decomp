#include "trade_action_candidates_test_support.h"

int g_1471a0_calls = 0;
int g_1471a0_return_val = 0;
int g_1471c0_calls = 0;
int g_1471c0_return_val = 0;
int g_147190_calls = 0;
int g_147190_return_val = 0;
int g_332e60_calls = 0;
int g_2bf050_calls = 0;
int g_2bf050_return_val = 0;
int g_2bfcd0_calls = 0;
int g_2bfcd0_return_val = 0;
int g_269190_calls = 0;
float g_269190_return_val = 0.0f;
int g_144d10_calls = 0;
int g_1880d0_calls = 0;
int g_1880d0_return_val = 0;

void *g_mock_candidate_entity = 0;
void *g_mock_linked_entity = 0;
void *D_004E3180 = 0;

void reset_candidates_test_support() {
    g_1471a0_calls = 0;
    g_1471a0_return_val = 0;
    g_1471c0_calls = 0;
    g_1471c0_return_val = 0;
    g_147190_calls = 0;
    g_147190_return_val = 0;
    g_332e60_calls = 0;
    g_2bf050_calls = 0;
    g_2bf050_return_val = 0;
    g_2bfcd0_calls = 0;
    g_2bfcd0_return_val = 0;
    g_269190_calls = 0;
    g_269190_return_val = 0.0f;
    g_144d10_calls = 0;
    g_1880d0_calls = 0;
    g_1880d0_return_val = 0;
    g_mock_candidate_entity = 0;
    g_mock_linked_entity = 0;
}

extern "C" {
void *func_00332e60(void *manager, int id) {
    g_332e60_calls++;
    if (id == 100 || id == 101 || id == 102 || id == 200 || id == 201 || id == 300 || id == 301) {
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

int func_002bf050(void *self, int item_id) {
    g_2bf050_calls++;
    return g_2bf050_return_val;
}

int func_002bfcd0(void *self, short sub_id) {
    g_2bfcd0_calls++;
    return g_2bfcd0_return_val;
}

float func_00269190(float x, float y, void *item) {
    g_269190_calls++;
    return g_269190_return_val;
}

void *func_00144d10(void *mgr, int idx) {
    g_144d10_calls++;
    return g_mock_candidate_entity;
}

int func_001880d0(void *gp_obj) {
    g_1880d0_calls++;
    return g_1880d0_return_val;
}

int func_00123350(float val) {
    return static_cast<int>(val);
}
}
