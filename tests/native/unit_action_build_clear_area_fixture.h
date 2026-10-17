#ifndef UNIT_ACTION_BUILD_CLEAR_AREA_FIXTURE_H
#define UNIT_ACTION_BUILD_CLEAR_AREA_FIXTURE_H

#include <cstddef>
#include <vector>
#include "unit_action_build_clear_area.h"

struct DummyCell {
    char pad_00[13];
    unsigned char m_count;
    char pad_0e[6];
    void **m_entities;
    char pad_18[4];
};

struct DummySpatial {
    char pad_00[8];
    int m_width;
    int m_height;
    char pad_10[36476];
    DummyCell **m_grid;
};

struct DummyPlayerWorld {
    char pad_00[60];
    DummySpatial *m_spatial;
};

struct DummyClearWorld {
    char pad_00[2968];
    DummyPlayerWorld *m_player_world;
};

struct DummyClearMaster {
    unsigned char m_type;
    char pad_01[31];
    float m_rad_x;
    float m_rad_y;
};

struct DummyClearEntity {
    void *vtable;
    DummyClearMaster *m_master;
    char pad_08[60];
    float m_x;
    float m_y;
};

struct DummyClearAction {
    void *vtable;
    DummyClearMaster *m_master;
    DummyClearWorld *m_world;
    char pad_0C[56];
    float m_x;
    float m_y;
};

static int g_func_123350_called = 0;
static int g_func_26ad20_ret = 1;
static std::vector<void*> g_cleared_entities;

extern "C" {
    int func_123350(float val) {
        g_func_123350_called++;
        return (int)val;
    }
    int func_26ad20(void *entity, int flag) {
        (void)entity; (void)flag;
        return g_func_26ad20_ret;
    }
    void func_26e750(void *entity) {
        g_cleared_entities.push_back(entity);
    }
}

#endif // UNIT_ACTION_BUILD_CLEAR_AREA_FIXTURE_H
