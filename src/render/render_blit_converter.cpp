#include "render_blit_converter.h"

extern "C" {

void render_palette_to_rgb565(const RenderPaletteColor *palette,
                              unsigned short *out_lut565,
                              int count) {
    if (!palette || !out_lut565 || count <= 0) {
        return;
    }
    for (int i = 0; i < count; ++i) {
        unsigned short r5 = (unsigned short)((palette[i].r >> 3) & 0x1F);
        unsigned short g6 = (unsigned short)((palette[i].g >> 2) & 0x3F);
        unsigned short b5 = (unsigned short)((palette[i].b >> 3) & 0x1F);
        out_lut565[i] = (unsigned short)((r5 << 11) | (g6 << 5) | b5);
    }
}

void render_palette_to_argb8888(const RenderPaletteColor *palette,
                                unsigned int *out_lut32,
                                int count) {
    if (!palette || !out_lut32 || count <= 0) {
        return;
    }
    for (int i = 0; i < count; ++i) {
        out_lut32[i] = ((unsigned int)palette[i].a << 24) |
                       ((unsigned int)palette[i].r << 16) |
                       ((unsigned int)palette[i].g << 8)  |
                       ((unsigned int)palette[i].b);
    }
}

int render_blit_8_to_16(const RenderSurface8 *src,
                        RenderSurface16 *dst,
                        int dst_x,
                        int dst_y,
                        const unsigned short *lut16,
                        int color_key,
                        const RenderClipRect *clip) {
    if (!src || !dst || !src->pixels || !dst->pixels || !lut16) {
        return -1;
    }
    if (src->width <= 0 || src->height <= 0 || dst->width <= 0 || dst->height <= 0) {
        return -2;
    }

    int cx0 = 0;
    int cy0 = 0;
    int cx1 = dst->width;
    int cy1 = dst->height;

    if (clip) {
        if (clip->x0 > cx0) cx0 = clip->x0;
        if (clip->y0 > cy0) cy0 = clip->y0;
        if (clip->x1 < cx1) cx1 = clip->x1;
        if (clip->y1 < cy1) cy1 = clip->y1;
    }

    if (cx0 >= cx1 || cy0 >= cy1) {
        return 0;
    }

    int rect_x0 = dst_x;
    int rect_y0 = dst_y;
    int rect_x1 = dst_x + src->width;
    int rect_y1 = dst_y + src->height;

    int draw_x0 = (rect_x0 > cx0) ? rect_x0 : cx0;
    int draw_y0 = (rect_y0 > cy0) ? rect_y0 : cy0;
    int draw_x1 = (rect_x1 < cx1) ? rect_x1 : cx1;
    int draw_y1 = (rect_y1 < cy1) ? rect_y1 : cy1;

    if (draw_x0 >= draw_x1 || draw_y0 >= draw_y1) {
        return 0;
    }

    int src_start_x = draw_x0 - dst_x;
    int src_start_y = draw_y0 - dst_y;
    int blit_w = draw_x1 - draw_x0;
    int blit_h = draw_y1 - draw_y0;

    for (int row = 0; row < blit_h; ++row) {
        const unsigned char *s = src->pixels + ((src_start_y + row) * src->stride) + src_start_x;
        unsigned short *d = (unsigned short *)((char *)dst->pixels + ((draw_y0 + row) * dst->stride)) + draw_x0;

        for (int col = 0; col < blit_w; ++col) {
            unsigned char idx = s[col];
            if (color_key < 0 || idx != (unsigned char)color_key) {
                d[col] = lut16[idx];
            }
        }
    }

    return 0;
}

int render_blit_8_to_32(const RenderSurface8 *src,
                        RenderSurface32 *dst,
                        int dst_x,
                        int dst_y,
                        const unsigned int *lut32,
                        int color_key,
                        const RenderClipRect *clip) {
    if (!src || !dst || !src->pixels || !dst->pixels || !lut32) {
        return -1;
    }
    if (src->width <= 0 || src->height <= 0 || dst->width <= 0 || dst->height <= 0) {
        return -2;
    }

    int cx0 = 0;
    int cy0 = 0;
    int cx1 = dst->width;
    int cy1 = dst->height;

    if (clip) {
        if (clip->x0 > cx0) cx0 = clip->x0;
        if (clip->y0 > cy0) cy0 = clip->y0;
        if (clip->x1 < cx1) cx1 = clip->x1;
        if (clip->y1 < cy1) cy1 = clip->y1;
    }

    if (cx0 >= cx1 || cy0 >= cy1) {
        return 0;
    }

    int rect_x0 = dst_x;
    int rect_y0 = dst_y;
    int rect_x1 = dst_x + src->width;
    int rect_y1 = dst_y + src->height;

    int draw_x0 = (rect_x0 > cx0) ? rect_x0 : cx0;
    int draw_y0 = (rect_y0 > cy0) ? rect_y0 : cy0;
    int draw_x1 = (rect_x1 < cx1) ? rect_x1 : cx1;
    int draw_y1 = (rect_y1 < cy1) ? rect_y1 : cy1;

    if (draw_x0 >= draw_x1 || draw_y0 >= draw_y1) {
        return 0;
    }

    int src_start_x = draw_x0 - dst_x;
    int src_start_y = draw_y0 - dst_y;
    int blit_w = draw_x1 - draw_x0;
    int blit_h = draw_y1 - draw_y0;

    for (int row = 0; row < blit_h; ++row) {
        const unsigned char *s = src->pixels + ((src_start_y + row) * src->stride) + src_start_x;
        unsigned int *d = (unsigned int *)((char *)dst->pixels + ((draw_y0 + row) * dst->stride)) + draw_x0;

        for (int col = 0; col < blit_w; ++col) {
            unsigned char idx = s[col];
            if (color_key < 0 || idx != (unsigned char)color_key) {
                d[col] = lut32[idx];
            }
        }
    }

    return 0;
}

} /* extern "C" */
