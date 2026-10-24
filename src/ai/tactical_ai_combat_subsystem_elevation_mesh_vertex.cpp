#include "tactical_ai_combat_subsystem_elevation_mesh_vertex.h"

void func_00328230(ElevationMeshDescriptor *self, int id, int tag) {
    if (self->m_count == 0) return;
    Entity *entity = D_004E350C[id];
    if (!entity) return;

    char *buf = (char *)self->m_table_0[tag] + (self->m_table_8[tag] * 8);
    int x = func_123350(entity->m_x);
    int y = func_123350(entity->m_y);

    *(int *)(buf + 0) = id;
    buf[4] = 0;
    buf[5] = 0;
    buf[6] = (char)x;
    buf[7] = (char)y;

    self->m_table_8[tag]++;
}
