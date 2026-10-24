#pragma exceptions off
#include "tactical_ai_tile_eval.h"

void func_00308C20(WaypointCostManager *self, int x, int y, int mark, int radius) {
    int tx = (short)x;
    int ty = (short)y;

    int a2 = (int)self->m_field158 - 1 - tx;
    int a3 = ty + a2;
    WaypointCostCell *cell = &self->m_grid[a3];

    unsigned char passable = *(unsigned char *)((char *)cell + 2);
    if (passable == 0) {
        return;
    }

    void *sub292 = *(void **)((char *)self + 292);
    if (sub292) {
        void *p288 = *(void **)((char *)self + 288);
        if (p288 && D_50A5A0) {
            int mask = *(int *)((char *)p288 + 3108);
            int sight = *(int *)((char *)D_50A5A0 + (ty * 4));
            if ((mask & sight) == 0) {
                return;
            }
        }
    }

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

    int rad = (short)radius;
    short y_min = center_y - rad;
    short y_max = center_y + rad;
    short x_min = center_x - rad;
    short x_max = center_x + rad;

    func_1aca60(self->m_field20, x_min, y_min, x_max, y_min, mark);
    func_1aca60(self->m_field20, x_max, y_min, x_max, y_max, mark);
    func_1aca60(self->m_field20, x_max, y_max, x_min, y_max, mark);
    func_1aca60(self->m_field20, x_min, y_max, x_min, y_min, mark);
}
