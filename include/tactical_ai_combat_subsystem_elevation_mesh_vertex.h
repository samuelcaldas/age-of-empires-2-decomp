#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_VERTEX_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_VERTEX_H

struct Entity {
    char pad00[0x44];
    float m_x;
    float m_y;
};

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

extern Entity **D_004E350C;

extern "C" {
    int func_123350(float val);
    void func_00328230(ElevationMeshDescriptor *self, int id, int tag);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_VERTEX_H
