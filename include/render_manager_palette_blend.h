#ifndef RENDER_MANAGER_PALETTE_BLEND_H
#define RENDER_MANAGER_PALETTE_BLEND_H

struct RenderPaletteColor {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
};

extern "C" {
/** Blend 256 RGBA entries, preserving alpha and both excluded palette indices. */
void func_00189260(const unsigned char *source, unsigned char *destination,
                   RenderPaletteColor color, int percent,
                   int skip_first, int skip_second);
}

#endif
