#pragma exceptions off
#include "sub_list.h"
#include "trade_packet.h"

extern "C" {
extern char D_00C5DF00[1024];

int func_0021B440(void *palette_obj, int unused, int start_idx, int count, void *dst_buf) {
    if (dst_buf == 0) {
        return 1;
    }

    char *palette_data = *(char **)((char *)palette_obj + 4);
    char *dst = (char *)dst_buf;
    int end_idx = start_idx + count;

    int i = 0;
    while (start_idx < end_idx) {
        char *src = palette_data + start_idx * 4;
        char *out = dst + i * 4;
        out[0] = src[0];
        out[1] = src[1];
        out[2] = src[2];
        out[3] = src[3];
        start_idx++;
        i++;
    }

    return 0;
}

void func_0021B560(void *palette_obj, const char *palette_data) {
    if (palette_data == 0) {
        return;
    }

    for (int i = 0; i < 256; i++) {
        int swizzled_idx = ((i >> 5) << 5) | (((i >> 4) & 1) << 3) | (((i >> 3) & 1) << 4) | (i & 7);
        const char *src = palette_data + i * 4;
        char *dst = D_00C5DF00 + swizzled_idx * 4;
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
    }

    unsigned short clut_offset = *(unsigned short *)((char *)palette_obj + 2);
    int clut_base = clut_offset >> 4;
    int v1 = ((clut_base >> 2) << 5) | ((clut_base & 1) << 4);
    int v0 = (clut_base & 2) << 3;

    int t0 = (short)v1;
    int t1 = (short)v0;

    func_0021DE90(0x1F00, 0, 4, D_00C5DF00, t0, t1, 16, 16);
}

int func_0021B4C0(void *palette_obj, int unused, int start_idx, int count, void *src_buf, int trans_idx) {
    if (src_buf == 0) {
        return 0;
    }

    char *palette_data = *(char **)((char *)palette_obj + 4);
    const char *src = (const char *)src_buf;

    for (int i = 0; i < count; i++) {
        const char *in_col = src + i * 4;
        char *dst_col = palette_data + start_idx * 4;

        dst_col[0] = in_col[0];
        dst_col[1] = in_col[1];
        dst_col[2] = in_col[2];

        if (start_idx == trans_idx) {
            dst_col[3] = 0;
        }
        if (start_idx != trans_idx) {
            dst_col[3] = (char)0x80;
        }

        start_idx++;
    }

    func_0021B560(palette_obj, palette_data);
    return 0;
}
}
