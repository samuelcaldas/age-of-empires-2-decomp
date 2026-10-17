#include "trade_action_dispatcher_test_support.h"

int g_2261c0_calls = 0;
int g_2a03c0_calls = 0;
int g_2a03c0_last_flag = -1;
int g_2a03f0_calls = 0;
int g_2a03f0_last_flag = -1;
int g_297390_calls = 0;
int g_2c29e0_calls = 0;
int g_2c29e0_last_target_idx = -1;
int g_1471c0_calls = 0;
int g_2d1a40_calls = 0;
int g_2be490_calls = 0;
int g_2bfe30_calls = 0;
int g_2b9770_calls = 0;
int g_2a0420_calls = 0;
int g_2b9770_last_id = -1;
int g_2b9770_last_value = -1;
int g_2bfe30_last_id1 = -1;
int g_2bfe30_last_id2 = -1;
int g_2a0420_last_id1 = -1;
int g_2a0420_last_id2 = -1;
int g_144d20_calls = 0;
int g_2ac300_calls = 0;
int g_2ac370_calls = 0;
int g_2be250_calls = 0;
int g_2be250_last_mode = -1;

void *g_mock_last_lookup_entity = 0;
int g_mock_last_lookup_id = -1;
void *g_mock_entity = 0;
void *g_mock_zero_id_entity = 0;
void *g_mock_target_ent = 0;
void *g_mock_found_ent = 0;
int g_mock_mode_flag = 0;

void reset_dispatcher_test_support() {
    g_2261c0_calls = 0;
    g_2a03c0_calls = 0;
    g_2a03c0_last_flag = -1;
    g_2a03f0_calls = 0;
    g_2a03f0_last_flag = -1;
    g_297390_calls = 0;
    g_2c29e0_calls = 0;
    g_2c29e0_last_target_idx = -1;
    g_1471c0_calls = 0;
    g_2d1a40_calls = 0;
    g_2be490_calls = 0;
    g_2bfe30_calls = 0;
    g_2b9770_calls = 0;
    g_2a0420_calls = 0;
    g_2b9770_last_id = -1;
    g_2b9770_last_value = -1;
    g_2bfe30_last_id1 = -1;
    g_2bfe30_last_id2 = -1;
    g_2a0420_last_id1 = -1;
    g_2a0420_last_id2 = -1;
    g_144d20_calls = 0;
    g_2ac300_calls = 0;
    g_2ac370_calls = 0;
    g_2be250_calls = 0;
    g_2be250_last_mode = -1;
    g_mock_entity = 0;
    g_mock_zero_id_entity = 0;
    g_mock_target_ent = 0;
    g_mock_found_ent = 0;
    g_mock_mode_flag = 0;
}

extern "C" {
void *D_004E3180 = 0;
float D_004E2808 = 10000.0f;

void *func_00332e60(void *manager, int id) {
    g_mock_last_lookup_id = id;
    if (id == 1) return g_mock_entity;
    if (id == 2) return g_mock_target_ent;
    if (id == 0) return g_mock_zero_id_entity;
    return 0;
}

int func_002261c0() {
    g_2261c0_calls++;
    return 0;
}

void func_002a03c0(void *target, int id, int flag) {
    g_2a03c0_calls++;
    g_2a03c0_last_flag = flag;
}

void func_002a03f0(void *target, int id, int flag) {
    g_2a03f0_calls++;
    g_2a03f0_last_flag = flag;
}

void func_00297390(void *target, void *entity, int zero) {
    g_297390_calls++;
}

int func_001471c0(void *entity) {
    g_1471c0_calls++;
    return 0;
}

void func_002d1a40(void *entity) {
    g_2d1a40_calls++;
}

void func_002c29e0(void *self, int target_idx) {
    g_2c29e0_calls++;
    g_2c29e0_last_target_idx = target_idx;
}

void *func_002be490(void *self, short id) {
    g_2be490_calls++;
    return 0;
}

int func_00332da0(void *ptr) { return 0; }
void func_002bea40(void *target, int mode) {}
int func_00202b10(void *world) { return 0; }
void func_0013fdf0(void *diplomacy, int team, int zero) {}
void func_0013fc80(void *mgr, int id, int zero, int val) {}
void func_00140360(void *mgr, int id, int mode) {}
void func_0013fb50(void *mgr, int id, int mode, int val) {}
int func_001233e0(float val) { return static_cast<int>(val); }
int func_00123350(float val) { return static_cast<int>(val); }
void func_0029dd20(void *target_list, int zero, int x, int y, int team,
                   int manager_team, int zero_a, int zero_b, int route_flags, int unknown) {}
void func_002bfe30(void *self, short id1, short id2) {
    g_2bfe30_calls++;
    g_2bfe30_last_id1 = id1;
    g_2bfe30_last_id2 = id2;
}
void func_002b9770(void *self, short id, int val) {
    g_2b9770_calls++;
    g_2b9770_last_id = id;
    g_2b9770_last_value = val;
}
void func_002a0420(void *target, short id1, short id2) {
    g_2a0420_calls++;
    g_2a0420_last_id1 = id1;
    g_2a0420_last_id2 = id2;
}
int func_00297b50(void *target, void *entity) { return g_mock_mode_flag; }
void *func_002be250(void *self, int mode, int val, int *coords) {
    g_2be250_calls++;
    g_2be250_last_mode = mode;
    return g_mock_found_ent;
}
int func_002ac300(void *target, int mode) { g_2ac300_calls++; return 0; }
void func_002ac370(void *target, void *self, void *mgr, int mode, int zero) { g_2ac370_calls++; }
void *func_00144d20(void *manager, int first, int mode, int third, int fourth,
                    int fifth, int sixth, int seventh, int eighth, int ninth, int tenth) {
    g_144d20_calls++;
    return 0;
}
float func_002690d0(void *entity, void *other) { return 10000.0f; }
int func_002b7bb0(void *self, int mode, int flag, int step) { return 0; }
int func_002b76b0(void *self, int mode, int flag, int step, int zero) { return 0; }
void func_002c22e0(void *self, void *other, void *entity) {}
void func_002bf1e0(void *self, int a1, int a2, int a3) {}
int func_001fe830(void *candidate, void *target, float scale, int *candidate_position,
                  int *target_position, int zero_a, int unknown_a, int zero_b,
                  int zero_c, int zero_d, int zero_e) {
    return 0;
}
void func_002bb730(void *self, int candidate_id, int target_id, int team, float x,
                   float y, int zero_a, int zero_b, int unknown, int zero_c, int limit) {}
int func_00147170(void *entity) { return 0; }
int func_00147190(void *entity) { return 0; }
int func_001471a0(void *entity) { return 0; }
float D_004120 = 10.0f;
}
