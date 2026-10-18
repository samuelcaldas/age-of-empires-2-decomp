#ifndef RENDER_MANAGER_PALETTE_TABLE_H
#define RENDER_MANAGER_PALETTE_TABLE_H

#include "render_manager_palette.h"
#include "render_manager_palette_blend.h"

struct RenderPaletteTableData {
    int field_0;
    unsigned char *table;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    unsigned char field_30;
    unsigned char field_31;
    unsigned char field_32;
    unsigned char field_33;
};

class RenderPaletteTable : public RenderPaletteTableData {
public:
    RenderPaletteTable(void *stream);
    RenderPaletteTable(SubObj6C *sub, int percent,
                       const RenderPaletteColor *color, const unsigned char *palette);
    virtual ~RenderPaletteTable();
};

#endif
