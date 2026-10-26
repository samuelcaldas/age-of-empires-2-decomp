#pragma exceptions off
#include "sub_list.h"

extern "C" {
static void fill_rect(char *dst, int pitch, int width, int height, unsigned char val) {
    for (int y = 0; y < height; y++) {
        char *row = dst + y * pitch;
        for (int x = 0; x < width; x++) {
            row[x] = (char)val;
        }
    }
}

static void blit_transparent(char *dst, int dst_pitch, const char *src, int src_pitch, int width, int height, int trans_color) {
    for (int y = 0; y < height; y++) {
        const char *src_row = src + y * src_pitch;
        char *dst_row = dst + y * dst_pitch;
        for (int x = 0; x < width; x++) {
            unsigned char pixel = (unsigned char)src_row[x];
            if (pixel != (unsigned char)trans_color) {
                dst_row[x] = (char)pixel;
            }
        }
    }
}

static void blit_opaque(char *dst, int dst_pitch, const char *src, int src_pitch, int width, int height) {
    for (int y = 0; y < height; y++) {
        const char *src_row = src + y * src_pitch;
        char *dst_row = dst + y * dst_pitch;
        for (int x = 0; x < width; x++) {
            dst_row[x] = src_row[x];
        }
    }
}

int func_0021B130(void *self, const int *rect1, void *target, const int *rect3, int flags_t0, void *arg5) {
    char *self_bytes = (char *)self;
    int self_pitch = *(int *)(self_bytes + 0x40);
    char *self_base = *(char **)(self_bytes + 0x54);

    char *target_base = 0;
    int target_pitch = 0;
    if (target != 0) {
        char *target_bytes = (char *)target;
        target_pitch = *(int *)(target_bytes + 0x40);
        target_base = *(char **)(target_bytes + 0x54);
    }

    char *dst = self_base + self_pitch * rect1[1] + rect1[0];
    char *src = 0;
    if (target != 0) {
        src = target_base + target_pitch * rect3[1] + rect3[0];
    }

    int width = rect1[2] - rect1[0];
    int height = rect1[3] - rect1[1];

    if ((flags_t0 & 0x400) != 0) {
        unsigned char fill_val = *(unsigned char *)((char *)arg5 + 0x50);
        fill_rect(dst, self_pitch, width, height, fill_val);
        return 0;
    }

    int trans_color = 0;
    if (arg5 != 0) {
        trans_color = *(int *)((char *)arg5 + 0x5C);
    }
    if (arg5 == 0) {
        trans_color = *(int *)(self_bytes + 0x70);
    }

    if ((flags_t0 & 0x8000) != 0) {
        blit_transparent(dst, self_pitch, src, target_pitch, width, height, trans_color);
        return 0;
    }

    if ((flags_t0 & 1) != 0) {
        blit_transparent(dst, self_pitch, src, target_pitch, width, height, 0);
        return 0;
    }

    blit_opaque(dst, self_pitch, src, target_pitch, width, height);
    return 0;
}
}
