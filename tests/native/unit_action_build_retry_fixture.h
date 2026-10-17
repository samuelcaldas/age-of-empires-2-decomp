#ifndef UNIT_ACTION_BUILD_RETRY_FIXTURE_H
#define UNIT_ACTION_BUILD_RETRY_FIXTURE_H

#include <cstddef>
#include "unit_action_build_retry.h"

struct DummyMaster {
    char pad[8];
    short m_type;
};

struct DummyZone {
    char pad[0x8ECD];
    unsigned char f_8ECD;
    unsigned char f_8ECE;
};

struct DummyPlayerWorld {
    char pad[0x3C];
    DummyZone *m_zone;
};

struct DummyPlayer {
    char pad_b94[0xB94];
    void *m_map_zone;
    DummyPlayerWorld *m_player_world;
};

struct DummyWorld {
    char pad_54[0x54];
    DummyPlayer **m_players;
    char pad_58[0x98 - 0x54 - sizeof(void*)];
    short m_player_id;
};

struct DummyActor {
    char pad_b98[0xB98];
    DummyWorld *m_world;
};

struct DummyAction {
    void *vtable;
    DummyMaster *m_master;
    DummyActor *m_actor;
    char pad_c[0x44 - 0xC];
    float m_x;
    float m_y;
    char pad_4c[0x15A - 0x4C];
    char m_field15A;
};

struct DummyGameSingleton {
    char pad[0x1C8];
    int m_mode;
};

static int g_func_123350_called = 0;
static int g_func_1378c0_called = 0;
static int g_func_270BA0_called = 0;
static void *g_last_1378c0_zone = nullptr;
static int g_last_1378c0_tx = 0, g_last_1378c0_ty = 0;
static int g_mock_1378c0_return = 0;
static void *g_last_270BA0_self = nullptr;
static int g_last_270BA0_status = 0;

static DummyGameSingleton g_game_singleton;
void *D_004E3180 = &g_game_singleton;

extern "C" {
    int func_123350(float val) {
        g_func_123350_called++;
        return (int)val;
    }
    int func_1378c0(void *map_zone, int tile_x, int tile_y) {
        g_func_1378c0_called++;
        g_last_1378c0_zone = map_zone;
        g_last_1378c0_tx = tile_x;
        g_last_1378c0_ty = tile_y;
        return g_mock_1378c0_return;
    }
    void func_270BA0(ActionRebind *self, int status) {
        g_func_270BA0_called++;
        g_last_270BA0_self = self;
        g_last_270BA0_status = status;
    }
}

#endif // UNIT_ACTION_BUILD_RETRY_FIXTURE_H
