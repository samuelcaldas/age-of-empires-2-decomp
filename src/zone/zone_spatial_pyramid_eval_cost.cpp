#pragma exceptions off

#include "zone_spatial_pyramid_eval_cost.h"

extern "C" int func_001D35C0(void *self, int level, int x, int y, int cur_x, int cur_y) {
    char *zm = (char *)self;
    void ***root = *(void ****)(zm + 0x0);
    char *cell = (char *)root[level][x] + y * 2;

    if (cell[0] == 0) {
        return 0;
    }

    int target_x = *(int *)(zm + 0x104);
    int target_y = *(int *)(zm + 0x108);

    int dx = target_x - cur_x;
    int dy = target_y - cur_y;

    int dist_sq = dx * dx + dy * dy;
    return dist_sq;
}
