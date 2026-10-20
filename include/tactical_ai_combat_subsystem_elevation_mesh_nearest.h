#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_NEAREST_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_NEAREST_H

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
    int func_123350(float val);
    MeshVertex *func_003283C0(ElevationMeshDescriptor *self, int target_x, int target_y, int,
                              int tag, const int *exclude_list, int exclude_count);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_NEAREST_H
