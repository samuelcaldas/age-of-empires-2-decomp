#include "tactical_ai_combat_subsystem_elevation_mesh_filter.h"

void func_00328100(ElevationMeshDescriptor *self, void *region) {
    CellCoord *coords;
    int count;
    func_208480(region, &coords, &count);
    if (count <= 0) return;
    if (self->m_count == 0) return;

    ZoneCell *cell;
    ZoneCell **cell_rows = self->m_world->m_game_mgr->m_map_zone->m_cell_rows;
    for (int i = 0; i < count; i++, coords++) {
        cell = &cell_rows[coords->y][coords->x];
        for (int j = 0; j < cell->m_entity_count; j++) {
            Entity *entity = cell->m_entities[j];
            if (entity) {
                EntityDesc *desc = entity->m_desc;
                if (desc->m_active) {
                    func_328230(self, entity->m_id, desc->m_tag);
                }
            }
        }
    }
}
