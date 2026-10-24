#pragma exceptions off
#include "tactical_ai_grid_marker.h"

void func_00308A70(WaypointCostManager *self, int x, int y, int mark, int radius) {
    int rad = (short)radius;
    int tx = (short)x;
    int ty = (short)y;

    int a2 = (int)self->m_field158 - 1 - tx;
    int a3 = ty + a2;
    WaypointCostCell *cell = &self->m_grid[a3];

    int min_coord = (tx < ty) ? tx : ty;
    float f1 = cell->m_field20;
    int v0;
    if (f1 < 1.0f) {
        v0 = func_123350(f1 * (float)(short)min_coord);
    } else {
        v0 = func_123350((float)(short)min_coord * cell->m_field18);
    }

    short cell_field00 = cell->m_field00;
    short *a2_tbl = (short *)((char *)self->m_field150 + (int)cell_field00 * 6);
    short offset_v1 = a2_tbl[1];

    int cy = (int)self->m_field10 + (int)self->m_field15C + (int)cell_field00;
    short center_y = (short)cy;
    short center_x = (short)((int)self->m_field0C + (int)offset_v1 + (int)(short)v0);

    short y_min = center_y - rad;
    short y_max = center_y + rad;
    short x_min = center_x - rad;
    short x_max = center_x + rad;

    func_1acf10(self->m_field20, x_min, y_min, x_max, y_max, mark);
    func_1acf10(self->m_field20, x_max, y_min, x_min, y_max, mark);
}
