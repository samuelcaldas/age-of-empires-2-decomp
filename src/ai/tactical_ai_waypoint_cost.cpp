#pragma exceptions off
#include "tactical_ai_waypoint_cost.h"

void func_00307640(WaypointCostManager *self) {
    int any_drawn = 0;

    for (int s0 = 0; s0 < 5; s0++) {
        if (!self->m_array1[s0]) {
            continue;
        }

        int tile_x = func_123350(self->m_array4[s0]);
        int tile_y = func_123350(self->m_array5[s0]);

        int a2 = (int)self->m_field158 - 1 - tile_x;
        int a3 = tile_y + a2;
        WaypointCostCell *cell = &self->m_grid[a3];

        int min_coord = (tile_x < tile_y) ? tile_x : tile_y;
        float f1 = cell->m_field20;
        int v0;
        if (f1 < 1.0f) {
            v0 = func_123350(f1 * (float)(short)min_coord);
        } else {
            v0 = func_123350((float)(short)min_coord * cell->m_field18);
        }

        short cell_field00 = cell->m_field00;
        short *a1 = (short *)((char *)self->m_field150 + (int)cell_field00 * 6);
        short offset_v1 = a1[1];

        int s3_val = (int)self->m_field10 + (int)self->m_field15C + (int)cell_field00;
        int s2_val = (int)self->m_field0C + (int)offset_v1 + (int)(short)v0;
        short center_y = (short)s3_val;
        short center_x = (short)s2_val;

        int now = func_2261c0();
        int elapsed = now - self->m_array2[s0];

        int radius = 0;
        int mark = 0;
        if ((unsigned int)elapsed < 700U) {
            radius = 16;
            mark = 71;
        } else if ((unsigned int)elapsed < 1000U) {
            radius = 11;
            mark = 70;
        } else if ((unsigned int)elapsed < 1300U) {
            radius = 8;
            mark = 69;
        } else if ((unsigned int)elapsed < 1600U) {
            radius = 6;
            mark = 68;
        } else if ((unsigned int)elapsed < 1900U) {
            radius = 4;
            mark = 67;
        } else if ((unsigned int)elapsed < 2400U) {
            radius = 2;
            mark = 66;
        }

        if (radius == 0) {
            continue;
        }

        int rad = radius & 0xFF;
        int x_max = (int)center_x + rad;
        int y_max = (int)center_y + rad;
        int x_min = (int)center_x - rad;
        int y_min = (int)center_y - rad;

        int draw_left = 1;
        int draw_right = 1;
        int draw_bottom = 1;
        int draw_top = 1;

        int min_x_bound = (int)self->m_field0C + 1;
        if (x_min < min_x_bound) {
            x_min = min_x_bound;
            draw_left = 0;
        }

        int max_x_bound = (int)self->m_field0C + self->m_field14 - 1;
        if (max_x_bound < x_max) {
            x_max = max_x_bound;
            draw_right = 0;
        }

        int min_y_bound = (int)self->m_field10 + 1;
        if (y_min < min_y_bound) {
            y_min = min_y_bound;
            draw_bottom = 0;
        }

        int max_y_bound = (int)self->m_field10 + self->m_field18 - 1;
        if (max_y_bound < y_max) {
            y_max = max_y_bound;
            draw_top = 0;
        }

        int height = y_max - y_min;
        if (draw_left != 0) {
            func_1ad450(self->m_field20, x_min, y_min, height + 1, mark);
            func_1ad450(self->m_field20, x_min + 1, y_min + 1, height - 1, mark);
        }

        if (draw_right != 0) {
            func_1ad450(self->m_field20, x_max, y_min, height + 1, mark);
            func_1ad450(self->m_field20, x_max - 1, y_min + 1, height - 1, mark);
        }

        int width = x_max - x_min;
        if (draw_bottom != 0) {
            func_1ad270(self->m_field20, x_min, y_min, width + 1, mark);
            func_1ad270(self->m_field20, x_min + 1, y_min + 1, width - 1, mark);
        }

        if (draw_top != 0) {
            func_1ad270(self->m_field20, x_min, y_max, width + 1, mark);
            func_1ad270(self->m_field20, x_min + 1, y_max - 1, width - 1, mark);
        }

        any_drawn = 1;
    }

    if (any_drawn != 0) {
        typedef void (*Method10Fn)(void *, int);
        void **vtable = *(void ***)self;
        Method10Fn fn = (Method10Fn)*(void **)((char *)vtable + 40);
        fn(self, 2);
    }
}
