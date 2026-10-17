#ifndef UNIT_ACTION_BUILD_NOTIFY_WORKERS_FIXTURE_H
#define UNIT_ACTION_BUILD_NOTIFY_WORKERS_FIXTURE_H

#include "unit_action_build_notify_workers.h"

struct DummyWorkerWorldNode {
    char pad_00[16];
    float m_f16;
    char pad_14[24];
    float m_f44;
    char pad_30[80];
    float m_f128;
    char pad_84[192];
    float m_f324;
};

struct DummyWorkerWorld {
    char pad_00[2976];
    int m_player_count;
    char pad_BA0[8];
    DummyWorkerWorldNode *m_node;
};

struct DummyNotifyWorkersAction {
    void *vtable;
    char pad_04[4];
    DummyWorkerWorld *m_world;
    char pad_0C[320];
    void *m_list;
    void *m_slots;
    short m_field154;
    char pad_156[1];
    unsigned char m_count;
};

static int g_func_202B10_called = 0;
static int g_func_202B10_ret = 1;
static int g_func_270530_called = 0;
static int g_func_270450_called = 0;
static int g_func_366D10_called = 0;
static int g_func_35D7C0_called = 0;
static int g_addhead_called = 0;
static int g_deletehead_called = 0;

static void *dummy_singleton_vt[32] = {};
void *D_004E3180 = dummy_singleton_vt;

char dummy_d4e35dc_buf[4000] = {};
void *D_4E35DC = dummy_d4e35dc_buf;

static void mock_m17(void *sing, int msg, int pcount, int tid, int z1, int z2) {
    (void)sing; (void)msg; (void)pcount; (void)tid; (void)z1; (void)z2;
}

extern "C" {
    int func_202B10() {
        g_func_202B10_called++;
        return g_func_202B10_ret;
    }
    float func_2E6C60(void *world, int task_id) {
        (void)world; (void)task_id;
        return 5.0f;
    }
    void func_00270530(ActionRebind *self) {
        (void)self;
        g_func_270530_called++;
    }
    void func_00270450(ActionRebind *self) {
        (void)self;
        g_func_270450_called++;
    }
    void* func_366D10(void *param) {
        (void)param;
        g_func_366D10_called++;
        static char item_buf[32];
        return item_buf;
    }
    void func_35D7C0(void *item, void *self, short task_id, int mode, int opt) {
        (void)item; (void)self; (void)task_id; (void)mode; (void)opt;
        g_func_35D7C0_called++;
    }
    void AddHead__8BaseListFPv(void *list, void *item) {
        (void)list; (void)item;
        g_addhead_called++;
    }
    void DeleteHead__8BaseListFv(void *list) {
        (void)list;
        g_deletehead_called++;
    }
}

#endif // UNIT_ACTION_BUILD_NOTIFY_WORKERS_FIXTURE_H
