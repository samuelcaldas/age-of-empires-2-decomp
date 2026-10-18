#pragma exceptions off
#include "unit_action_build_a30.h"

float func_00271A30(void *self, float target_x, float target_y,
                    float speed_factor, float rate_factor) {
    float origin_x = *(float *)((char *)self + 0x44);
    float origin_y = *(float *)((char *)self + 0x48);
    float dx = (target_x > origin_x) ? (target_x - origin_x) : (origin_x - target_x);
    float dy = (target_y > origin_y) ? (target_y - origin_y) : (origin_y - target_y);

#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)self + 0x8);
    void *owner = *(void **)((char *)self + 0x10);
#else
    void *proto = *(void **)((char *)self + 0x4);
    void *owner = *(void **)((char *)self + 0x8);
#endif

    float half_width = *(float *)((char *)proto + 0x20);
    float half_height = *(float *)((char *)proto + 0x24);

    dx -= 2.0f * half_width + 1.0f;
    dy -= 2.0f * half_height + 1.0f;
    if (dx < 0.0f) dx = 0.0f;
    if (dy < 0.0f) dy = 0.0f;

    float dist = func_1234E0(dx * dx + dy * dy);
    if (dist < 0.1f) {
        dist = 0.1f;
    }

    void *mgr = *(void **)((char *)owner + 0xB98);
    void *cfg = *(void **)((char *)mgr + 0x3C);
    float denom = (float)*(int *)((char *)cfg + 0x8);

    float factor = 0.3f + (dist / denom);
    float work = 2.0f * dist * speed_factor * factor;
    return work / rate_factor;
}
