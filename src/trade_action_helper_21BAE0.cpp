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

static unsigned int CalcColorDistanceSq(int r, int g, int b, const unsigned char *entry) {
    int dr = r - (int)entry[0];
    int dg = g - (int)entry[1];
    int db = b - (int)entry[2];
    return (unsigned int)(dr * dr + dg * dg + db * db);
}

int func_0021BB60(void *palette_obj, int target_color) {
    int target_r = target_color & 0xFF;
    int target_g = (target_color >> 8) & 0xFF;
    int target_b = (target_color >> 16) & 0xFF;

    unsigned char palette_buffer[256 * 4];
    func_0021B440(palette_obj, 0, 0, 256, palette_buffer);

    unsigned int best_distance = 0xFFFFFFFF;
    int best_index = 0;

    for (int i = 0; i < 256; ++i) {
        unsigned int distance = CalcColorDistanceSq(target_r, target_g, target_b, &palette_buffer[i * 4]);
        if (distance < best_distance) {
            best_distance = distance;
            best_index = i;
        }
    }

    return best_index;
}
}
