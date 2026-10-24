#include "tactical_ai_combat_subsystem_elevation_mesh_remove.h"

int func_00328300(ElevationMeshDescriptor *self, int id, int tag) {
    if (self->m_count == 0) return -1;
    MeshVertex *vertices;
    int count = self->m_table_8[tag];
    if (count == 0) return 0;
    vertices = (MeshVertex *)self->m_table_0[tag];
    for (int i = 0; i <= count - 1; i++) {
        if (vertices[i].m_id == id) {
            int last = count - 1;
            if (i < last) {
                vertices[i] = vertices[last];
            }
            self->m_table_8[tag]--;
            return i;
        }
    }
    return -1;
}
