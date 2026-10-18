#include "tactical_ai_combat_subsystem_elevation_mesh_nearest.h"

MeshVertex *func_003283C0(ElevationMeshDescriptor *self, int target_x, int target_y, int,
                          int tag, const int *exclude_list, int exclude_count) {
    if (tag < 0 || self->m_count == 0 || tag >= self->m_count) {
        return 0;
    }

    int count = self->m_table_8[tag];
    if (count == 0) {
        return 0;
    }

    MeshVertex *best_vertex = 0;
    MeshVertex *vertices = (MeshVertex *)self->m_table_0[tag];
    int dx;
    int dy;
    int best_dist = 9999;

    for (int i = 0; i < count; i++, vertices++) {
        int vx = (unsigned char)vertices->m_x;
        if (target_x < vx) {
            dx = vx - target_x;
        } else {
            dx = target_x - vx;
        }

        int vy = (unsigned char)vertices->m_y;
        if (target_y < vy) {
            dy = vy - target_y;
        } else {
            dy = target_y - vy;
        }

        int dist;
        if (dy < dx) {
            dist = (dx - dy) + func_123350(0.61f + 1.4f * (float)dy);
        } else {
            dist = (dy - dx) + func_123350(0.61f + 1.4f * (float)dx);
        }

        if (dist < best_dist) {
            int excluded = 0;
            if (exclude_count != 0 && exclude_list != 0) {
                for (int k = 0; k < exclude_count; k++) {
                    if (vertices->m_id == exclude_list[k]) {
                        excluded = 1;
                        break;
                    }
                }
            }

            if (!excluded) {
                best_dist = dist;
                best_vertex = vertices;
            }
        }
    }

    if (best_dist >= 256) {
        best_dist = 255;
    }

    if (best_vertex != 0) {
        best_vertex->m_flags_4 = (char)best_dist;
    }

    return best_vertex;
}
