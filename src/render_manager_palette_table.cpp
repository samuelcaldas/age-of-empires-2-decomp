#pragma exceptions off
#pragma divbyzerocheck on
#pragma inline_depth(8)

#include "render_manager_palette_table.h"

extern "C" {
extern const unsigned char D_003921F4[];

int func_226D90(void *stream, void *dst, int size);
void *func_100730(int size);
void func_100630(void *ptr);
void func_100670(void *ptr);
int func_21BC30(const void *arg0, void *buf, int arg2, int capacity, int arg4);
void *func_117AF8(void *dst, const void *src, int len);
void func_1AE350(SubObj6C *sub, void *dest_palette);
void func_00189260(const unsigned char *source, unsigned char *destination,
                   RenderPaletteColor color, int percent,
                   int skip_first, int skip_second);
}

enum {
    PALETTE_COUNT = 256,
    PALETTE_ENTRY_BYTES = 4,
    PALETTE_BUFFER_BYTES = 1024,
    COLOR_DEFAULT_COMPONENT = 255,
    REMAP_MAX_DIST = 20000
};

RenderPaletteTable::RenderPaletteTable(void *stream) {
    func_226D90(stream, &field_0, 4);
    func_226D90(stream, &field_8, 4);
    func_226D90(stream, &field_C, 4);
    func_226D90(stream, &field_10, 4);
    func_226D90(stream, &field_14, 4);
    func_226D90(stream, &field_18, 4);
    func_226D90(stream, &field_1C, 4);
    func_226D90(stream, &field_20, 4);
    func_226D90(stream, &field_24, 4);
    table = 0;
    if (field_0 == 10) {
        table = static_cast<unsigned char *>(func_100730(PALETTE_COUNT));
        func_21BC30(D_003921F4, reinterpret_cast<void *>(0x01ED7000), 0, PALETTE_COUNT, 1);
        func_117AF8(table, reinterpret_cast<void *>(0x01ED7000), PALETTE_COUNT);
    }
    field_28 = 0;
    field_2C = 0;
    field_30 = 0;
    field_31 = 0;
    field_32 = 0;
    field_33 = 0;
}

RenderPaletteTable::RenderPaletteTable(SubObj6C *sub, int percent,
                                       const RenderPaletteColor *color, const unsigned char *palette) {
    unsigned char blended_palette[PALETTE_BUFFER_BYTES];
    unsigned char local_palette[PALETTE_BUFFER_BYTES];
    if (palette == 0) {
        func_1AE350(sub, local_palette);
    } else {
        for (int i = 0; i < PALETTE_COUNT; i++) {
            local_palette[i * PALETTE_ENTRY_BYTES + 0] = palette[i * PALETTE_ENTRY_BYTES + 0];
            local_palette[i * PALETTE_ENTRY_BYTES + 1] = palette[i * PALETTE_ENTRY_BYTES + 1];
            local_palette[i * PALETTE_ENTRY_BYTES + 2] = palette[i * PALETTE_ENTRY_BYTES + 2];
            local_palette[i * PALETTE_ENTRY_BYTES + 3] = palette[i * PALETTE_ENTRY_BYTES + 3];
        }
    }

    RenderPaletteColor blend_color;
    if (!color) {
        blend_color.red = 0;
        blend_color.blue = 0;
        blend_color.green = 0;
        blend_color.alpha = 0;
    } else {
        blend_color.red = color->red;
        blend_color.blue = color->blue;
        blend_color.green = color->green;
        blend_color.alpha = color->alpha;
    }

    field_0 = -1;
    field_8 = -1;
    field_C = -1;
    field_10 = -1;
    field_14 = -1;
    field_18 = -1;
    field_1C = -1;
    field_20 = -1;
    field_24 = -1;
    field_28 = -1;
    field_2C = -1;
    field_30 = COLOR_DEFAULT_COMPONENT;
    field_31 = COLOR_DEFAULT_COMPONENT;
    field_32 = COLOR_DEFAULT_COMPONENT;
    field_33 = COLOR_DEFAULT_COMPONENT;
    table = static_cast<unsigned char *>(func_100730(PALETTE_COUNT));

    func_00189260(local_palette, blended_palette, blend_color, percent, -1, -1);

    for (int i = 0; i < PALETTE_COUNT; i++) {
        unsigned char tr = blended_palette[i * PALETTE_ENTRY_BYTES + 0];
        unsigned char tg = blended_palette[i * PALETTE_ENTRY_BYTES + 1];
        unsigned char tb = blended_palette[i * PALETTE_ENTRY_BYTES + 2];
        int min_dist = REMAP_MAX_DIST;
        int best_idx = 0;
        for (int j = 0; j < PALETTE_COUNT; j++) {
            int dr = tr - local_palette[j * PALETTE_ENTRY_BYTES + 0];
            int dg = tg - local_palette[j * PALETTE_ENTRY_BYTES + 1];
            int db = tb - local_palette[j * PALETTE_ENTRY_BYTES + 2];
            int dist = dr * dr + dg * dg + db * db;
            if (dist < min_dist) {
                min_dist = dist;
                best_idx = j;
            }
        }
        table[i] = static_cast<unsigned char>(best_idx);
    }
}

RenderPaletteTable::~RenderPaletteTable() {
    if (table != 0) {
        func_100630(table);
        table = 0;
    }
}
