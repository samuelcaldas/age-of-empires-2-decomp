#include "render_manager_palette_blend_test_support.h"
#include <cstdlib>
#include <cstring>

static void test_percentages_signed_truncation_and_alpha() {
    unsigned char source[1024] = {}, destination[1024] = {};
    RenderPaletteColor color = {255, 128, 0, 0xEE};
    fill_palette(source, 10, 20, 30, 0xA7);
    set_entry(source, 0, 100, 50, 25, 0x4C);
    set_entry(source, 2, 10, 110, 100, 0x6B);
    func_00189260(source, destination, color, 0, -1, 256);
    assert_entry(destination, 0, 100, 50, 25, 0x4C);
    assert_entry(destination, 1, 10, 20, 30, 0xA7);
    func_00189260(source, destination, color, 100, -1, 256);
    assert_entry(destination, 0, 122, 61, 0, 0x4C);
    assert_entry(destination, 1, 43, 21, 0, 0xA7);
    func_00189260(source, destination, color, 50, -1, 256);
    assert_entry(destination, 0, 111, 55, 13, 0x4C);
    assert_entry(destination, 1, 26, 20, 15, 0xA7);
    assert_entry(destination, 2, 75, 90, 50, 0x6B);
}

static void test_rgb_permutations_and_extreme_channels() {
    unsigned char source[1024] = {}, destination[1024] = {};
    RenderPaletteColor color = {255, 128, 0, 0x42};
    set_entry(source, 0, 10, 20, 30, 0x31); set_entry(source, 1, 10, 30, 20, 0x32);
    set_entry(source, 2, 20, 10, 30, 0x33); set_entry(source, 3, 20, 30, 10, 0x34);
    set_entry(source, 4, 30, 10, 20, 0x35); set_entry(source, 5, 30, 20, 10, 0x36);
    set_entry(source, 6, 0, 0, 0, 0x37); set_entry(source, 7, 255, 255, 255, 0x38);
    func_00189260(source, destination, color, 100, -1, 256);
    assert_entry(destination, 0, 43, 21, 0, 0x31); assert_entry(destination, 1, 43, 21, 0, 0x32);
    assert_entry(destination, 2, 43, 21, 0, 0x33); assert_entry(destination, 3, 43, 21, 0, 0x34);
    assert_entry(destination, 4, 43, 21, 0, 0x35); assert_entry(destination, 5, 43, 21, 0, 0x36);
    assert_entry(destination, 6, 0, 0, 0, 0x37); assert_entry(destination, 7, 255, 128, 0, 0x38);
    color = {0, 255, 127, 0xEE};
    set_entry(source, 8, 0, 255, 128, 0x9B);
    func_00189260(source, destination, color, 100, -1, 256);
    assert_entry(destination, 8, 0, 255, 127, 0x9B);
}

static void test_skip_endpoints_duplicates_and_sentinels() {
    unsigned char source[1024] = {}, destination[1024] = {};
    RenderPaletteColor color = {255, 128, 0, 0xEE};
    fill_palette(source, 10, 20, 30, 0xB6);
    func_00189260(source, destination, color, 100, 0, 255);
    assert_entry(destination, 0, 10, 20, 30, 0xB6); assert_entry(destination, 255, 10, 20, 30, 0xB6);
    assert_entry(destination, 1, 43, 21, 0, 0xB6);
    func_00189260(source, destination, color, 100, 37, 37);
    assert_entry(destination, 36, 43, 21, 0, 0xB6); assert_entry(destination, 37, 10, 20, 30, 0xB6);
    assert_entry(destination, 38, 43, 21, 0, 0xB6);
    func_00189260(source, destination, color, 100, -1, 256);
    assert_entry(destination, 0, 43, 21, 0, 0xB6); assert_entry(destination, 255, 43, 21, 0, 0xB6);
}

static void test_full_extent_and_destination_canaries() {
    unsigned char source_storage[1026] = {}, destination_storage[1026] = {};
    unsigned char *source = source_storage + 1, *destination = destination_storage + 1;
    RenderPaletteColor color = {255, 128, 0, 0xEE};
    source_storage[0] = 0xA1; source_storage[1025] = 0xA2;
    destination_storage[0] = 0xB1; destination_storage[1025] = 0xB2;
    for (int index = 0; index < 256; index++) set_entry(source, index, 10, 20, 30, index);
    std::memset(destination, 0xA5, 1024);
    func_00189260(source, destination, color, 100, -1, 256);
    for (int index = 0; index < 256; index++) assert_entry(destination, index, 43, 21, 0, index);
    assert(source_storage[0] == 0xA1 && source_storage[1025] == 0xA2);
    assert(destination_storage[0] == 0xB1 && destination_storage[1025] == 0xB2);
}

static void test_in_place_palette_aliasing() {
    unsigned char palette[1024] = {};
    RenderPaletteColor color = {255, 128, 0, 0xEE};
    fill_palette(palette, 10, 20, 30, 0x5D);
    func_00189260(palette, palette, color, 50, -1, 256);
    for (int index = 0; index < 256; index++) assert_entry(palette, index, 26, 20, 15, 0x5D);
}

static void test_extrapolated_percentages_wrap_without_clamping() {
    unsigned char source[1024] = {}, destination[1024] = {};
    RenderPaletteColor color = {255, 128, 0, 0xEE};
    fill_palette(source, 100, 50, 25, 0x6A);
    func_00189260(source, destination, color, 200, -1, 256);
    assert_entry(destination, 0, 144, 72, 231, 0x6A);
    func_00189260(source, destination, color, -50, -1, 256);
    assert_entry(destination, 0, 89, 45, 37, 0x6A);
}

int main(int count, char **arguments) {
    if (count != 2) return 1;
    switch (std::atoi(arguments[1])) {
    case 0: test_percentages_signed_truncation_and_alpha(); return 0;
    case 1: test_rgb_permutations_and_extreme_channels(); return 0;
    case 2: test_skip_endpoints_duplicates_and_sentinels(); return 0;
    case 3: test_full_extent_and_destination_canaries(); return 0;
    case 4: test_in_place_palette_aliasing(); return 0;
    case 5: test_extrapolated_percentages_wrap_without_clamping(); return 0;
    default: return 1;
    }
}
