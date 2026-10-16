#pragma exceptions off

#include "zone_calc_subtile_screen_coords.h"

extern "C" {
int func_123350(float f);
}

extern "C" void func_001D0350(
    void *self,
    short *out_screen_x,
    short *out_screen_y,
    int base_x,
    int base_y,
    float x,
    float y,
    float z
) {
    char *zm = (char *)self;
    int half_w = *(short *)(zm + 0x8EB4);
    int half_h = *(short *)(zm + 0x8EB2);

    float sum_xy = x + y;
    int offset_x = func_123350((float)half_w * sum_xy);
    *out_screen_x = (short)(base_x + offset_x);

    float diff_term = (1.0f + y - x) - z;
    int offset_y = func_123350((float)half_h * diff_term);
    *out_screen_y = (short)(base_y + offset_y - half_h);
}
