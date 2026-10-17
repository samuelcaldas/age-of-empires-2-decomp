#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_FILTER_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_FILTER_H

struct CellCoord {
    int x;
    int y;
};

struct EntityDesc {
    char pad00[3];
    unsigned char m_active;
    char pad04[0x8D];
    unsigned char m_tag;
};

struct Entity {
    char pad00[4];
    EntityDesc *m_desc;
    char pad08[0x1C];
    short m_id;
};

struct ZoneCell {
    char pad00[0x0D];
    unsigned char m_entity_count;
    char pad0E[6];
    Entity **m_entities;
    char pad18[4];
};

struct MapZone {
    char pad00[0x8E8C];
    ZoneCell **m_cell_rows;
};

struct GameMgr {
    char pad00[0x3C];
    MapZone *m_map_zone;
};

struct CombatWorld {
    char pad00[0xB98];
    GameMgr *m_game_mgr;
};

struct ElevationMeshDescriptor {
    void **m_table_0;
    int *m_table_4;
    int *m_table_8;
    CombatWorld *m_world;
    int m_count;
};

extern "C" {
    void func_208480(void *region, CellCoord **coords, int *count);
    void func_328230(ElevationMeshDescriptor *self, short id, unsigned char tag);
    void func_00328100(ElevationMeshDescriptor *self, void *region);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_FILTER_H
