#ifndef RENDER_FONT_CONTEXT_H
#define RENDER_FONT_CONTEXT_H

#ifdef __cplusplus
extern "C" {
#endif

struct GlyphRange {
    unsigned short first;
    unsigned short last;
    unsigned short glyph_offset;
    unsigned short pad;
};

void func_0021FEC0(void *ctx);
void *func_0021FED0(void);
int func_0021FEE0(const struct GlyphRange *table, int c);

#ifdef __cplusplus
}
#endif

#endif // RENDER_FONT_CONTEXT_H
