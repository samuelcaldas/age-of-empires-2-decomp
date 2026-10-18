#include "render_manager_palette_table_test_support.h"

static void test_stream_constructor_non_type_10() {
    MockStream stream;
    init_mock_stream(&stream, 5);
    RenderPaletteTable tbl(&stream);
    assert(tbl.field_0 == 5);
    assert(tbl.field_8 == 100 && tbl.field_24 == 800);
    assert(tbl.table == 0);
    assert(tbl.field_28 == 0 && tbl.field_2C == 0);
    assert(tbl.field_30 == 0 && tbl.field_33 == 0);
}

static void test_stream_constructor_type_10() {
    MockStream stream;
    init_mock_stream(&stream, 10);
    RenderPaletteTable tbl(&stream);
    assert(tbl.field_0 == 10);
    assert(tbl.table != 0);
    assert(tbl.field_28 == 0 && tbl.field_33 == 0);
}

static void test_remap_constructor_with_palette() {
    unsigned char pal[1024] = {};
    for (int i = 0; i < 256; i++) {
        pal[i * 4 + 0] = static_cast<unsigned char>(i);
        pal[i * 4 + 1] = static_cast<unsigned char>(i);
        pal[i * 4 + 2] = static_cast<unsigned char>(i);
        pal[i * 4 + 3] = 0xFF;
    }
    RenderPaletteColor col = {255, 0, 0, 255};
    RenderPaletteTable tbl(0, 0, &col, pal);
    assert(tbl.field_0 == -1 && tbl.field_2C == -1);
    assert(tbl.field_30 == 255 && tbl.field_33 == 255);
    assert(tbl.table != 0);
    assert(tbl.table[0] == 0);
    assert(tbl.table[128] == 128);
}

static void test_remap_constructor_with_subobj() {
    SubObj6C sub = {};
    for (int i = 0; i < 256; i++) {
        sub.field_5C[i] = static_cast<char>(i);
    }
    RenderPaletteColor col = {0, 255, 0, 255};
    RenderPaletteTable tbl(&sub, 0, &col, 0);
    assert(tbl.table != 0);
    assert(tbl.field_0 == -1);
}

static void test_remap_null_color_and_destructor() {
    unsigned char pal[1024] = {};
    for (int i = 0; i < 256; i++) {
        pal[i * 4] = static_cast<unsigned char>(i);
    }
    RenderPaletteTable *tbl = new RenderPaletteTable(0, 50, 0, pal);
    assert(tbl->table != 0);
    delete tbl;
}

int main(int count, char **arguments) {
    if (count != 2) return 1;
    switch (std::atoi(arguments[1])) {
    case 0: test_stream_constructor_non_type_10(); return 0;
    case 1: test_stream_constructor_type_10(); return 0;
    case 2: test_remap_constructor_with_palette(); return 0;
    case 3: test_remap_constructor_with_subobj(); return 0;
    case 4: test_remap_null_color_and_destructor(); return 0;
    default: return 1;
    }
}
