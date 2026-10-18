#ifndef RENDER_MANAGER_PALETTE_BLEND_TEST_SUPPORT_H
#define RENDER_MANAGER_PALETTE_BLEND_TEST_SUPPORT_H

#include "render_manager_palette_blend.h"
#include <cassert>

static void set_entry(unsigned char *palette, int index, int red, int green, int blue, int alpha) {
    int offset = index * 4;
    palette[offset] = static_cast<unsigned char>(red);
    palette[offset + 1] = static_cast<unsigned char>(green);
    palette[offset + 2] = static_cast<unsigned char>(blue);
    palette[offset + 3] = static_cast<unsigned char>(alpha);
}

static void assert_entry(const unsigned char *palette, int index, int red, int green, int blue, int alpha) {
    int offset = index * 4;
    assert(palette[offset] == red);
    assert(palette[offset + 1] == green);
    assert(palette[offset + 2] == blue);
    assert(palette[offset + 3] == alpha);
}

static void fill_palette(unsigned char *palette, int red, int green, int blue, int alpha) {
    for (int index = 0; index < 256; index++) {
        set_entry(palette, index, red, green, blue, alpha);
    }
}

#endif
