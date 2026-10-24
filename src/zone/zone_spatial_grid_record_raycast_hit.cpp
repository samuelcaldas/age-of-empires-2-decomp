#pragma exceptions off
#include "zone_spatial_grid_record_raycast_hit.h"

struct HitResult {
    void *node;
    int id;
    float x;
    float y;
};

struct SpatialGrid {
    char pad_00[0x12B590];
    HitResult *results;
    int *out_count;
    int max_count;
};

extern "C" int func_001F02A0(SpatialGrid *self, HitNode *node, Point2D *pos) {
    int cur_cnt = *self->out_count;
    if (cur_cnt < self->max_count) {
        HitResult *r = &self->results[cur_cnt];
        r->node = node;
        r->id = *(int *)((char *)node + 0x18);
        r->x = pos->x;
        r->y = pos->y;
        *self->out_count = cur_cnt + 1;
        return 1;
    }
    return 0;
}
