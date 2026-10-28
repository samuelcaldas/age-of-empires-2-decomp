#include "render_blit_converter.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

static int test_palette_lut_generation(void) {
    RenderPaletteColor pal[4];
    pal[0].r = 255; pal[0].g = 0;   pal[0].b = 0;   pal[0].a = 255; /* Pure Red */
    pal[1].r = 0;   pal[1].g = 255; pal[1].b = 0;   pal[1].a = 255; /* Pure Green */
    pal[2].r = 0;   pal[2].g = 0;   pal[2].b = 255; pal[2].a = 255; /* Pure Blue */
    pal[3].r = 128; pal[3].g = 128; pal[3].b = 128; pal[3].a = 128; /* Gray half-alpha */

    unsigned short lut16[4];
    unsigned int lut32[4];

    render_palette_to_rgb565(pal, lut16, 4);
    render_palette_to_argb8888(pal, lut32, 4);

    /* RGB565: R (5 bits: 31 << 11 = 0xF800), G (6 bits: 63 << 5 = 0x07E0), B (5 bits: 31 = 0x001F) */
    assert(lut16[0] == 0xF800);
    assert(lut16[1] == 0x07E0);
    assert(lut16[2] == 0x001F);

    /* ARGB8888: 0xAARRGGBB */
    assert(lut32[0] == 0xFFFF0000);
    assert(lut32[1] == 0xFF00FF00);
    assert(lut32[2] == 0xFF0000FF);
    assert(lut32[3] == 0x80808080);
    return 0;
}

static int test_blit_8_to_16_opaque(void) {
    /* 4x2 8bpp source */
    unsigned char src_pixels[8] = {
        0, 1, 2, 0,
        1, 2, 0, 1
    };
    RenderSurface8 src;
    src.pixels = src_pixels;
    src.width = 4;
    src.height = 2;
    src.stride = 4;

    /* 6x4 16bpp dest */
    unsigned short dst_pixels[6 * 4];
    memset(dst_pixels, 0, sizeof(dst_pixels));
    RenderSurface16 dst;
    dst.pixels = dst_pixels;
    dst.width = 6;
    dst.height = 4;
    dst.stride = 6 * sizeof(unsigned short);

    unsigned short lut16[3] = { 0x1111, 0x2222, 0x3333 };

    /* Blit at (1, 1), no color key (-1), clip rect covers full dest */
    RenderClipRect clip = { 0, 0, 6, 4 };
    int ret = render_blit_8_to_16(&src, &dst, 1, 1, lut16, -1, &clip);
    assert(ret == 0);

    /* Row 0 of dst untouched */
    assert(dst_pixels[0] == 0);
    /* Row 1: col 0 is 0, cols 1..4 are src row 0 */
    assert(dst_pixels[6 * 1 + 0] == 0);
    assert(dst_pixels[6 * 1 + 1] == 0x1111);
    assert(dst_pixels[6 * 1 + 2] == 0x2222);
    assert(dst_pixels[6 * 1 + 3] == 0x3333);
    assert(dst_pixels[6 * 1 + 4] == 0x1111);
    assert(dst_pixels[6 * 1 + 5] == 0);

    /* Row 2: cols 1..4 are src row 1 */
    assert(dst_pixels[6 * 2 + 1] == 0x2222);
    assert(dst_pixels[6 * 2 + 2] == 0x3333);
    assert(dst_pixels[6 * 2 + 3] == 0x1111);
    assert(dst_pixels[6 * 2 + 4] == 0x2222);
    return 0;
}

static int test_blit_8_to_16_colorkey(void) {
    /* Color key 0: transparent */
    unsigned char src_pixels[4] = { 0, 1, 2, 0 };
    RenderSurface8 src = { src_pixels, 4, 1, 4 };

    unsigned short dst_pixels[4] = { 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA };
    RenderSurface16 dst = { dst_pixels, 4, 1, 4 * sizeof(unsigned short) };

    unsigned short lut16[3] = { 0x0000, 0x5555, 0x6666 };
    RenderClipRect clip = { 0, 0, 4, 1 };

    int ret = render_blit_8_to_16(&src, &dst, 0, 0, lut16, 0 /* colorkey */, &clip);
    assert(ret == 0);

    /* Index 0 was transparent: preserved */
    assert(dst_pixels[0] == 0xAAAA);
    assert(dst_pixels[1] == 0x5555);
    assert(dst_pixels[2] == 0x6666);
    assert(dst_pixels[3] == 0xAAAA);
    return 0;
}

static int test_blit_8_to_32_colorkey(void) {
    unsigned char src_pixels[4] = { 1, 0, 2, 1 };
    RenderSurface8 src = { src_pixels, 4, 1, 4 };

    unsigned int dst_pixels[4] = { 0, 0, 0, 0 };
    RenderSurface32 dst = { dst_pixels, 4, 1, 4 * sizeof(unsigned int) };

    unsigned int lut32[3] = { 0x00000000, 0xFF112233, 0xFF445566 };
    RenderClipRect clip = { 0, 0, 4, 1 };

    int ret = render_blit_8_to_32(&src, &dst, 0, 0, lut32, 0 /* colorkey */, &clip);
    assert(ret == 0);

    assert(dst_pixels[0] == 0xFF112233);
    assert(dst_pixels[1] == 0x00000000); /* skipped by colorkey */
    assert(dst_pixels[2] == 0xFF445566);
    assert(dst_pixels[3] == 0xFF112233);
    return 0;
}

static int test_blit_clipping(void) {
    /* 4x4 src blitted at (-2, -1) with clip (0, 0, 4, 4) */
    unsigned char src_pixels[16];
    for (int i = 0; i < 16; ++i) src_pixels[i] = (unsigned char)(i + 1);
    RenderSurface8 src = { src_pixels, 4, 4, 4 };

    unsigned int dst_pixels[16];
    memset(dst_pixels, 0, sizeof(dst_pixels));
    RenderSurface32 dst = { dst_pixels, 4, 4, 4 * sizeof(unsigned int) };

    unsigned int lut32[32];
    for (int i = 0; i < 32; ++i) lut32[i] = (unsigned int)(0xFF000000 | i);

    RenderClipRect clip = { 0, 0, 4, 4 };
    int ret = render_blit_8_to_32(&src, &dst, -2, -1, lut32, -1, &clip);
    assert(ret == 0);

    /* Source coords mapped:
       dest (0, 0) corresponds to src (-2 + 2, -1 + 1) -> src (2, 1) -> index 1*4 + 2 = 6 -> src_pixel = 7
       dest (1, 0) corresponds to src (3, 1) -> index 1*4 + 3 = 7 -> src_pixel = 8
       dest (2, 0) corresponds to src (4, 1) -> out of src width (4) -> not drawn
    */
    assert(dst_pixels[0] == (0xFF000000 | 7));
    assert(dst_pixels[1] == (0xFF000000 | 8));
    assert(dst_pixels[2] == 0);
    assert(dst_pixels[3] == 0);
    return 0;
}

static int test_blit_complete_rejection(void) {
    /* Dest at (10, 10), clip rect is (0, 0, 5, 5) -> fully outside */
    unsigned char src_pixels[4] = { 1, 2, 3, 4 };
    RenderSurface8 src = { src_pixels, 2, 2, 2 };

    unsigned int dst_pixels[25];
    memset(dst_pixels, 0x77, sizeof(dst_pixels));
    RenderSurface32 dst = { dst_pixels, 5, 5, 5 * sizeof(unsigned int) };

    unsigned int lut32[10] = { 0 };
    RenderClipRect clip = { 0, 0, 5, 5 };

    int ret = render_blit_8_to_32(&src, &dst, 10, 10, lut32, -1, &clip);
    assert(ret == 0);
    /* dst is completely untouched */
    assert(dst_pixels[0] == 0x77777777);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <case_index>\n", argv[0]);
        return 1;
    }
    int idx = atoi(argv[1]);
    switch (idx) {
        case 0: return test_palette_lut_generation();
        case 1: return test_blit_8_to_16_opaque();
        case 2: return test_blit_8_to_16_colorkey();
        case 3: return test_blit_8_to_32_colorkey();
        case 4: return test_blit_clipping();
        case 5: return test_blit_complete_rejection();
        default:
            fprintf(stderr, "unknown case: %d\n", idx);
            return 2;
    }
}
