#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_REMOVE_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_REMOVE_H

struct MeshVertex {
    int m_id;
    char m_flags_4;
    char m_flags_5;
    char m_x;
    char m_y;
};

struct ElevationMeshDescriptor {
    void **m_table_0;
    int *m_table_4;
    int *m_table_8;
    void *m_world;
    int m_count;
};

extern "C" {
    int func_00328300(ElevationMeshDescriptor *self, int id, int tag);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_REMOVE_H
