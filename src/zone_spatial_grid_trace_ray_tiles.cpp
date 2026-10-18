#pragma exceptions off
#include "zone_spatial_grid_trace_ray_tiles.h"

struct SpatialGrid {
    char pad_00[0x12B424];
    int width;
    int height;
    float f_width;
    float f_height;
    void *table1;
    int **grid_table;
};

extern "C" int func_001EF460(SpatialGrid *self, float fx0, float fy0, float fx1, float fy1, Point2D *out_points, int *out_count) {
    float start_x = fx0;
    float start_y = fy0;
    float end_x = fx1;
    float end_y = fy1;

    int count = 0;
    int cur_x = func_123350(start_x);
    int cur_y = func_123350(start_y);

    int target_x = func_123350(end_x);
    int target_y = func_123350(end_y);

    while (cur_x != target_x || cur_y != target_y) {
        float out_pt_x = 0.0f;
        float out_pt_y = 0.0f;

        if (end_x > start_x) {
            float edge_x = (float)(cur_x + 1);
            func_001EF410(&out_pt_x, &out_pt_y, start_x, start_y, end_x, end_y, edge_x, (float)cur_y, edge_x, (float)(cur_y + 1));
            cur_x++;
        } else if (end_x < start_x) {
            float edge_x = (float)cur_x;
            func_001EF410(&out_pt_x, &out_pt_y, start_x, start_y, end_x, end_y, edge_x, (float)cur_y, edge_x, (float)(cur_y + 1));
            cur_x--;
        }

        if (end_y > start_y) {
            float edge_y = (float)(cur_y + 1);
            func_001EF410(&out_pt_x, &out_pt_y, start_x, start_y, end_x, end_y, (float)cur_x, edge_y, (float)(cur_x + 1), edge_y);
            cur_y++;
        } else if (end_y < start_y) {
            float edge_y = (float)cur_y;
            func_001EF410(&out_pt_x, &out_pt_y, start_x, start_y, end_x, end_y, (float)cur_x, edge_y, (float)(cur_x + 1), edge_y);
            cur_y--;
        }

        if (out_points != 0) {
            out_points[count].x = out_pt_x;
            out_points[count].y = out_pt_y;
        }
        count++;

        if (cur_x < 0 || cur_x >= self->width || cur_y < 0 || cur_y >= self->height) {
            break;
        }
    }

    if (out_count != 0) {
        *out_count = count;
    }
    return 1;
}
