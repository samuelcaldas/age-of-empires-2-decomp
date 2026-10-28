#ifndef RENDER_FONT_LOOKUP_H
#define RENDER_FONT_LOOKUP_H

#include "render_font_context.h"

#ifdef __cplusplus
extern "C" {
#endif

struct FontEntry {
    unsigned char unk0[8];
    const struct GlyphRange *glyph_table;
    unsigned char *glyph_data;
    unsigned char width;
    unsigned char height;
    unsigned char pad[2];
    unsigned char *metrics;
    unsigned int *offsets;
    unsigned int unk1c;
};

extern struct FontEntry D_0047BDE0[];

int func_0021FF40(int font_id, int c);

#ifdef __cplusplus
}
#endif

#endif // RENDER_FONT_LOOKUP_H
