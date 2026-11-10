#ifndef RENDER_BLIT_CONVERTER_H
#define RENDER_BLIT_CONVERTER_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct RenderPaletteColor {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} RenderPaletteColor;

typedef struct RenderClipRect {
    int x0;
    int y0;
    int x1; /* exclusive right boundary */
    int y1; /* exclusive bottom boundary */
} RenderClipRect;

typedef struct RenderSurface8 {
    const unsigned char *pixels;
    int width;
    int height;
    int stride; /* in bytes */
} RenderSurface8;

typedef struct RenderSurface16 {
    unsigned short *pixels;
    int width;
    int height;
    int stride; /* in bytes */
} RenderSurface16;

typedef struct RenderSurface32 {
    unsigned int *pixels;
    int width;
    int height;
    int stride; /* in bytes */
} RenderSurface32;

/**
 * Convert an array of RGBA palette entries to a 16-bit RGB565 lookup table.
 */
void render_palette_to_rgb565(const RenderPaletteColor *palette,
                              unsigned short *out_lut565,
                              int count);

/**
 * Convert an array of RGBA palette entries to a 32-bit ARGB8888 lookup table.
 */
void render_palette_to_argb8888(const RenderPaletteColor *palette,
                                unsigned int *out_lut32,
                                int count);

/**
 * Blit an 8bpp surface into a 16bpp RGB565 destination surface.
 *
 * @param src Source 8-bit paletized surface
 * @param dst Destination 16-bit RGB565 surface
 * @param dst_x Destination X origin
 * @param dst_y Destination Y origin
 * @param lut16 Precomputed 256-entry RGB565 lookup table
 * @param color_key Palette index to treat as transparent (-1 for none)
 * @param clip Destination clipping rectangle (NULL to use full dst bounds)
 * @return 0 on success, negative error code on failure
 */
int render_blit_8_to_16(const RenderSurface8 *src,
                        RenderSurface16 *dst,
                        int dst_x,
                        int dst_y,
                        const unsigned short *lut16,
                        int color_key,
                        const RenderClipRect *clip);

/**
 * Blit an 8bpp surface into a 32bpp ARGB8888 destination surface.
 *
 * @param src Source 8-bit paletized surface
 * @param dst Destination 32-bit ARGB8888 surface
 * @param dst_x Destination X origin
 * @param dst_y Destination Y origin
 * @param lut32 Precomputed 256-entry ARGB8888 lookup table
 * @param color_key Palette index to treat as transparent (-1 for none)
 * @param clip Destination clipping rectangle (NULL to use full dst bounds)
 * @return 0 on success, negative error code on failure
 */
int render_blit_8_to_32(const RenderSurface8 *src,
                        RenderSurface32 *dst,
                        int dst_x,
                        int dst_y,
                        const unsigned int *lut32,
                        int color_key,
                        const RenderClipRect *clip);

#ifdef __cplusplus
}
#endif

#endif /* RENDER_BLIT_CONVERTER_H */
