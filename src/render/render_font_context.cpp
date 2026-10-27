#pragma exceptions off
#include "render_font_context.h"

extern "C" {
extern void *D_004E32FC;

void func_0021FEC0(void *ctx) {
    D_004E32FC = ctx;
}

void *func_0021FED0(void) {
    return D_004E32FC;
}

int func_0021FEE0(const struct GlyphRange *table, int c) {
    int ret = -1;
    while (1) {
        if (table->first == 0xFFFF) {
            break;
        }
        if (c >= table->first && c <= table->last) {
            ret = table->glyph_offset + c - table->first;
            break;
        }
        table++;
    }
    return ret;
}
}
