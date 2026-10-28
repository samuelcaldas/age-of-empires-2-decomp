#include "slp_rasterizer.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

static int test_block_copy_literal(void) {
    /* Test Case 0: Lesser and Greater Block Copy */
    /* Lesser block copy: 4 pixels of literal colors 0x10, 0x20, 0x30, 0x40 */
    /* opcode: count=4 -> command byte = (4 << 2) | 0 = 0x10. Followed by 4 bytes. EOL = 0x0F */
    unsigned char stream[] = {
        0x10, 0x11, 0x22, 0x33, 0x44,
        0x0F /* EOL */
    };
    unsigned char dest[16];
    memset(dest, 0xAA, sizeof(dest));

    int ret = slp_rasterize_scanline(stream, sizeof(stream), dest, 16, 0, NULL);
    assert(ret >= 0);
    assert(dest[0] == 0x11);
    assert(dest[1] == 0x22);
    assert(dest[2] == 0x33);
    assert(dest[3] == 0x44);
    assert(dest[4] == 0xAA); /* Untouched */

    /* Greater block copy: count = 5. command = 0x02. upper nibble = 0. next_byte = 5 */
    unsigned char stream2[] = {
        0x02, 0x05, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5,
        0x0F
    };
    memset(dest, 0x00, sizeof(dest));
    ret = slp_rasterize_scanline(stream2, sizeof(stream2), dest, 16, 0, NULL);
    assert(ret >= 0);
    assert(dest[0] == 0xA1);
    assert(dest[1] == 0xA2);
    assert(dest[2] == 0xA3);
    assert(dest[3] == 0xA4);
    assert(dest[4] == 0xA5);
    assert(dest[5] == 0x00);
    return 0;
}

static int test_transparent_skips(void) {
    /* Test Case 1: Lesser Skip and Greater Skip */
    /* Lesser skip: skip 3 pixels. opcode = (3 << 2) | 1 = 0x0D */
    /* Then 2 literal pixels: opcode = (2 << 2) | 0 = 0x08 */
    unsigned char stream[] = {
        0x0D, /* skip 3 */
        0x08, 0x55, 0x66, /* 2 pixels */
        0x0F /* EOL */
    };
    unsigned char dest[16];
    memset(dest, 0xEE, sizeof(dest));

    int ret = slp_rasterize_scanline(stream, sizeof(stream), dest, 16, 0, NULL);
    assert(ret >= 0);
    assert(dest[0] == 0xEE); /* Skipped */
    assert(dest[1] == 0xEE); /* Skipped */
    assert(dest[2] == 0xEE); /* Skipped */
    assert(dest[3] == 0x55); /* Drawn */
    assert(dest[4] == 0x66); /* Drawn */
    assert(dest[5] == 0xEE); /* Untouched */

    /* Greater skip: count = 4. command = 0x03. upper nibble = 0. next byte = 4 */
    unsigned char stream2[] = {
        0x03, 0x04, /* skip 4 */
        0x04, 0x77, /* 1 pixel */
        0x0F
    };
    memset(dest, 0xBB, sizeof(dest));
    ret = slp_rasterize_scanline(stream2, sizeof(stream2), dest, 16, 0, NULL);
    assert(ret >= 0);
    assert(dest[0] == 0xBB);
    assert(dest[3] == 0xBB);
    assert(dest[4] == 0x77);
    assert(dest[5] == 0xBB);
    return 0;
}

static int test_player_color_remap(void) {
    /* Test Case 2: Player Color Remap */
    /* Command 0x06: count = 3 -> opcode = (3 << 4) | 0x06 = 0x36 */
    /* indices: 0, 1, 2 */
    unsigned char stream[] = {
        0x36, 0x00, 0x01, 0x02,
        0x0F
    };
    unsigned char dest[16];
    memset(dest, 0x00, sizeof(dest));

    SlpRasterContext ctx;
    memset(&ctx, 0, sizeof(ctx));
    ctx.player_color_offset = 32; /* Remap base by +32 */

    int ret = slp_rasterize_scanline(stream, sizeof(stream), dest, 16, 0, &ctx);
    assert(ret >= 0);
    assert(dest[0] == 32);
    assert(dest[1] == 33);
    assert(dest[2] == 34);
    assert(dest[3] == 0);

    /* Test with player_table lookup */
    unsigned char remap_table[256];
    memset(remap_table, 0, sizeof(remap_table));
    remap_table[0x05] = 0xFE;
    remap_table[0x06] = 0xFF;
    ctx.player_color_offset = 0;
    ctx.player_table = remap_table;

    unsigned char stream2[] = {
        0x26, 0x05, 0x06, /* count=2 */
        0x0F
    };
    memset(dest, 0x00, sizeof(dest));
    ret = slp_rasterize_scanline(stream2, sizeof(stream2), dest, 16, 0, &ctx);
    assert(ret >= 0);
    assert(dest[0] == 0xFE);
    assert(dest[1] == 0xFF);
    return 0;
}

static int test_shadow_dither(void) {
    /* Test Case 3: Shadow / Dither (Command 0x0B) */
    /* count = 2 -> opcode = (2 << 4) | 0x0B = 0x2B */
    unsigned char stream[] = {
        0x2B,
        0x0F
    };
    unsigned char dest[16];
    dest[0] = 100;
    dest[1] = 200;
    dest[2] = 50;

    unsigned char shadow_tbl[256];
    for (int i = 0; i < 256; ++i) {
        shadow_tbl[i] = (unsigned char)(i / 2); /* 50% darkening table */
    }

    SlpRasterContext ctx;
    memset(&ctx, 0, sizeof(ctx));
    ctx.shadow_table = shadow_tbl;

    int ret = slp_rasterize_scanline(stream, sizeof(stream), dest, 16, 0, &ctx);
    assert(ret >= 0);
    assert(dest[0] == 50);
    assert(dest[1] == 100);
    assert(dest[2] == 50); /* untouched */
    return 0;
}

static int test_bounds_and_padding(void) {
    /* Test Case 4: Left padding and buffer boundary overflow guard */
    unsigned char stream[] = {
        0x10, 0x11, 0x12, 0x13, 0x14, /* 4 pixels */
        0x0F
    };
    unsigned char dest[16];
    memset(dest, 0xCC, sizeof(dest));

    /* left_padding = 2, width = 5 -> pixels written at index 2, 3, 4, 5 (total 4 pixels). */
    /* dest buffer limit is 5. So pixel at index 2,3,4 can be written, but index 5 is >= dest_width (5), clamped. */
    int ret = slp_rasterize_scanline(stream, sizeof(stream), dest, 5, 2, NULL);
    assert(ret >= 0);
    assert(dest[0] == 0xCC); /* padding untouched */
    assert(dest[1] == 0xCC); /* padding untouched */
    assert(dest[2] == 0x11);
    assert(dest[3] == 0x12);
    assert(dest[4] == 0x13);
    assert(dest[5] == 0xCC); /* out of bounds: was NOT overwritten! */
    return 0;
}

static int test_frame_rasterize(void) {
    /* Test Case 5: Multi-scanline frame rasterization */
    /* 2 rows, width 8, height 2 */
    /* Row 0 at offset 0: skip 1, write 2 pixels (0x01, 0x02) */
    /* Row 1 at offset 5: write 3 pixels (0x03, 0x04, 0x05) */
    unsigned char slp_data[] = {
        /* row 0 */
        0x05, /* skip 1 */
        0x08, 0x01, 0x02, /* 2 pixels */
        0x0F, /* EOL */
        /* row 1 */
        0x0C, 0x03, 0x04, 0x05, /* 3 pixels */
        0x0F  /* EOL */
    };
    unsigned int cmd_offsets[2] = { 0, 5 };
    unsigned short outline[4] = {
        1, 1, /* row 0: left pad 1, right pad 1 */
        0, 0  /* row 1: left pad 0, right pad 0 */
    };

    unsigned char framebuffer[16];
    memset(framebuffer, 0x00, sizeof(framebuffer));

    SlpRasterContext ctx;
    memset(&ctx, 0, sizeof(ctx));
    ctx.dest_buffer = framebuffer;
    ctx.dest_stride = 8;
    ctx.dest_width = 8;
    ctx.dest_height = 2;

    int ret = slp_rasterize_frame(slp_data, sizeof(slp_data),
                                  cmd_offsets, outline, 8, 2, &ctx);
    assert(ret == 0);

    /* Row 0: outline left_pad=1, then skip 1 -> pixel at index 2,3 */
    assert(framebuffer[0] == 0x00);
    assert(framebuffer[1] == 0x00);
    assert(framebuffer[2] == 0x01);
    assert(framebuffer[3] == 0x02);
    assert(framebuffer[4] == 0x00);

    /* Row 1 (stride 8): 3 pixels starting at 0 */
    assert(framebuffer[8] == 0x03);
    assert(framebuffer[9] == 0x04);
    assert(framebuffer[10] == 0x05);
    assert(framebuffer[11] == 0x00);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <case_index>\n", argv[0]);
        return 1;
    }
    int idx = atoi(argv[1]);
    switch (idx) {
        case 0: return test_block_copy_literal();
        case 1: return test_transparent_skips();
        case 2: return test_player_color_remap();
        case 3: return test_shadow_dither();
        case 4: return test_bounds_and_padding();
        case 5: return test_frame_rasterize();
        default:
            fprintf(stderr, "unknown case: %d\n", idx);
            return 2;
    }
}
