#pragma exceptions off
#include "unit_action_build_7450.h"

extern "C" {
    int func_123350(float val);
    int func_114308(int val);
}

typedef int (*VtableTileCheckFn)(void *self, void *target, int tile_x, int tile_y,
                                float min_x, float min_y, float max_x, float max_y,
                                void *map, void *cur_target, float *cached_angle, int *counter);

#if defined(__LP64__) || defined(_LP64)
#define SELF_OWNER_OFFSET 0x10
#define OWNER_B98_OFFSET  0x1730
#define B98_MAP_OFFSET    0x78
#else
#define SELF_OWNER_OFFSET 0x8
#define OWNER_B98_OFFSET  0xB98
#define B98_MAP_OFFSET    0x3C
#endif

static bool check_elevation_clearance(void *self, void *target) {
    float self_z = *(float *)((char *)self + 0x4C);
    float target_z = *(float *)((char *)target + 0x4C);
    return self_z <= target_z;
}

static bool compute_ray_steps(float dx, float dy, float &step_x, float &step_y, int &steps) {
    if (dx == 0.0f && dy == 0.0f) {
        return false;
    }
    float adx = ((dx < 0.0f) ? -dx : dx);
    float ady = ((dy < 0.0f) ? -dy : dy);
    float max_delta = (ady <= adx) ? adx : ady;
    int rounded = func_123350(max_delta);
    steps = func_114308(rounded) << 1;
    step_x = dx / (float)steps;
    step_y = dy / (float)steps;
    return true;
}

static void setup_offsets(float step_x, float step_y, int &ox1, int &oy1, int &ox2, int &oy2) {
    float ax = ((step_x < 0.0f) ? -step_x : step_x);
    float ay = ((step_y < 0.0f) ? -step_y : step_y);
    if (ax <= ay) {
        ox1 = 0; oy1 = -1;
        ox2 = 1; oy2 = 0;
        return;
    }
    ox1 = -1; oy1 = 0;
    ox2 = 0; oy2 = 1;
}

static bool ray_step(void *self, void *target, void *map, VtableTileCheckFn check_fn,
                     int tx, int ty, int ox1, int oy1, int ox2, int oy2,
                     float min_x, float min_y, float max_x, float max_y,
                     float *cached_angle, int *counter) {
    if (check_fn(self, target, tx, ty, min_x, min_y, max_x, max_y, map, 0, cached_angle, counter) != 0) {
        return true;
    }
    if (check_fn(self, target, tx + ox1, ty + oy1, min_x, min_y, max_x, max_y, map, 0, cached_angle, counter) != 0) {
        return true;
    }
    return check_fn(self, target, tx + ox2, ty + oy2, min_x, min_y, max_x, max_y, map, 0, cached_angle, counter) != 0;
}

int func_277450(void *self, void *target) {
    if (check_elevation_clearance(self, target)) {
        return 1;
    }

    float self_x = *(float *)((char *)self + 0x44);
    float self_y = *(float *)((char *)self + 0x48);
    float target_x = *(float *)((char *)target + 0x44);
    float target_y = *(float *)((char *)target + 0x48);

    float step_x = 0.0f, step_y = 0.0f;
    int steps = 0;
    if (!compute_ray_steps(target_x - self_x, target_y - self_y, step_x, step_y, steps)) {
        return 0;
    }

    int ox1 = 0, oy1 = 0, ox2 = 0, oy2 = 0;
    setup_offsets(step_x, step_y, ox1, oy1, ox2, oy2);

    void *owner = *(void **)((char *)self + SELF_OWNER_OFFSET);
    void *world = *(void **)((char *)owner + OWNER_B98_OFFSET);
    void *map = *(void **)((char *)world + B98_MAP_OFFSET);

    void **vtbl = *(void ***)self;
    VtableTileCheckFn check_fn = (VtableTileCheckFn)vtbl[217];

    float cur_x = self_x, cur_y = self_y;
    int last_x = -999, last_y = -999;
    float cached_angle = -1.0f;
    int counter = 0;

    for (int i = 0; i < steps; ++i) {
        cur_x += step_x;
        cur_y += step_y;
        int tx = func_123350(cur_x);
        int ty = func_123350(cur_y);
        if (tx == last_x && ty == last_y) {
            continue;
        }
        last_x = tx;
        last_y = ty;
        if (ray_step(self, target, map, check_fn, tx, ty, ox1, oy1, ox2, oy2,
                     self_x, self_y, target_x, target_y, &cached_angle, &counter)) {
            break;
        }
    }

    return (counter > 0) ? 1 : 0;
}
