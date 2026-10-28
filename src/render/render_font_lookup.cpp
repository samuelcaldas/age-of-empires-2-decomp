#pragma exceptions off
#include "render_font_lookup.h"

extern "C" {
int func_0021FF40(int font_id, int c) {
    return func_0021FEE0(D_0047BDE0[font_id].glyph_table, c);
}
}
