#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_0021B440(void *palette_obj, int unused, int start_idx, int count, void *dst_buf);
int func_0021B4C0(void *palette_obj, int unused, int start_idx, int count, void *src_buf, int trans_idx);

int func_0021BAE0(void *palette_obj, int start_idx, int count, void *dst_buf) {
    func_0021B440(palette_obj, 0, start_idx, count, dst_buf);
    return count;
}

int func_0021BB20(void *palette_obj, int start_idx, int count, void *src_buf) {
    func_0021B4C0(palette_obj, 0, start_idx, count, src_buf, 0xFF);
    return count;
}

int func_0021BB60(void *palette_obj, int target_color) {
    unsigned int best_dist = (unsigned int)-1;
    int r = target_color & 0xFF;
    int g = ((unsigned int)target_color >> 8) & 0xFF;
    int b = ((unsigned int)target_color >> 16) & 0xFF;

    unsigned char buf[1024];
    func_0021B440(palette_obj, 0, 0, 256, buf);

    int best_idx = 0;

    for (int i = 0; i < 256; i++) {
        const unsigned char *entry = &buf[i * 4];
        unsigned int dist = (r - entry[0]) * (r - entry[0]);
        dist += (g - entry[1]) * (g - entry[1]);
        dist += (b - entry[2]) * (b - entry[2]);
        if (dist < best_dist) {
            best_dist = dist;
            best_idx = i;
        }
    }

    return best_idx;
}
}
