#pragma exceptions off
#include "sub_list.h"
#include "zone_path_queries.h"

extern "C" {

int func_123350(float val);

void func_001C8480(void *obj, char val) {
    if (!*(unsigned char *)((char *)obj + 0x43)) {
        *(char *)((char *)obj + 0x42) = val;
    }
}

int func_001C84A0(void *master, float *p_x, float *p_y, void *map, int snap) {
    void *s0 = *(void **)((char *)map + 0x3C);
    int map_w = *(int *)((char *)s0 + 0x8);
    int map_h = *(int *)((char *)s0 + 0xC);

    float rx = *(float *)((char *)master + 0x20);
    float ry = *(float *)((char *)master + 0x24);

    float max_x = (float)map_w - 0.0001f;
    float max_y = (float)map_h - 0.0001f;

    float min_bound_x = *p_x - rx;
    float max_bound_x = *p_x + rx;
    float min_bound_y = *p_y - ry;
    float max_bound_y = *p_y + ry;

    if (min_bound_x < 0.0f) {
        *p_x = *p_x - min_bound_x;
        max_bound_x -= min_bound_x;
    }
    if (min_bound_y < 0.0f) {
        *p_y = *p_y - min_bound_y;
        max_bound_y -= min_bound_y;
    }
    if (max_bound_x >= max_x) {
        *p_x += (max_x - max_bound_x);
    }
    if (max_bound_y >= max_y) {
        *p_y += (max_y - max_bound_y);
    }

    if (!snap) {
        return 1;
    }

    float frac_rx = rx - (float)func_123350(rx);
    if (frac_rx == 0.0f) {
        float cur_x = *p_x;
        float frac_x = cur_x - (float)func_123350(cur_x);
        if (frac_x <= 0.5f) {
            *p_x = (float)func_123350(cur_x) + 0.5f;
        } else {
            *p_x = (float)func_123350(cur_x) + 1.0f;
        }
    } else {
        float cur_x = *p_x;
        float frac_x = cur_x - (float)func_123350(cur_x);
        if (frac_x <= 0.5f) {
            *p_x = (float)func_123350(cur_x);
        } else {
            *p_x = (float)func_123350(cur_x) + 0.5f;
        }
    }

    float frac_ry = ry - (float)func_123350(ry);
    if (frac_ry == 0.0f) {
        float cur_y = *p_y;
        float frac_y = cur_y - (float)func_123350(cur_y);
        if (frac_y <= 0.5f) {
            *p_y = (float)func_123350(cur_y) + 0.5f;
        } else {
            *p_y = (float)func_123350(cur_y) + 1.0f;
        }
    } else {
        float cur_y = *p_y;
        float frac_y = cur_y - (float)func_123350(cur_y);
        if (frac_y <= 0.5f) {
            *p_y = (float)func_123350(cur_y);
        } else {
            *p_y = (float)func_123350(cur_y) + 0.5f;
        }
    }

    return 1;
}

void func_001C8770() {}
void func_001C8A40() {}

void *func_001C8BF0(void *self) {
    return *(void **)((char *)self + 0x84);
}

void *func_001C8C00(void *self) {
    return *(void **)((char *)self + 0x88);
}

}
