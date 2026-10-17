#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_SERIALIZER_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_SERIALIZER_H

struct ElevationMeshDescriptor {
    void **m_table_0;             // 0x00
    int *m_table_4;               // 0x04
    int *m_table_8;               // 0x08
    char pad0C[4];
    int m_count;                  // 0x10
};

extern "C" {
    void func_00226F70(void *stream, const void *src, int size);

    // Write the descriptor to a valid stream; self and its active tables must be valid.
    void func_00328020(ElevationMeshDescriptor *self, void *stream);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_SERIALIZER_H
