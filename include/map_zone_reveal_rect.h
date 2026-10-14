#ifndef MAP_ZONE_REVEAL_RECT_H
#define MAP_ZONE_REVEAL_RECT_H

#include "map_zone_los.h"

struct StancePlayer {
    char pad_00[3072];
    int m_stance[1];
};

struct ZonePlayerMgr {
    char pad_00[84];
    StancePlayer **m_players;
    char pad_58[64];
    short m_player_id;
};

struct ZoneMapReveal {
    unsigned char **m_row_ptrs;
    ZonePlayerMgr *m_player_mgr;
    ZoneWorld *m_world;
    ZoneFieldC *m_fieldC;
    void *m_tile_data;
    int m_width;
    int m_height;
    int m_field1C;
    int pad_20;
    int m_field24;
    int m_field28;
    int m_field2C;
};

extern "C" {
    int func_001384C0(ZoneMapReveal *self, int min_x, int min_y, int max_x, int max_y, int flag);
}

#endif // MAP_ZONE_REVEAL_RECT_H
