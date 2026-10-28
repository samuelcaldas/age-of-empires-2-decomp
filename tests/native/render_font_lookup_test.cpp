#include <cassert>
#include <iostream>
#include "render_font_lookup.h"

extern "C" {
void *D_004E32FC = nullptr;
}

// Mock D_0047BDE0 font table for testing
static struct GlyphRange font0_ranges[] = {
    {'A', 'Z', 10, 0},
    {0xFFFF, 0, 0, 0}
};

static struct GlyphRange font1_ranges[] = {
    {'0', '9', 100, 0},
    {0xFFFF, 0, 0, 0}
};

struct FontEntry D_0047BDE0[4] = {
    {{0}, font0_ranges, nullptr, 8, 16, {0, 0}, nullptr, nullptr, 0},
    {{0}, font1_ranges, nullptr, 8, 16, {0, 0}, nullptr, nullptr, 0},
    {{0}, nullptr, nullptr, 0, 0, {0, 0}, nullptr, nullptr, 0},
    {{0}, nullptr, nullptr, 0, 0, {0, 0}, nullptr, nullptr, 0}
};

static void test_case_0_font_lookup_valid_char() {
    // Font 0: 'A' -> 10, 'Z' -> 35
    assert(func_0021FF40(0, 'A') == 10);
    assert(func_0021FF40(0, 'B') == 11);
    assert(func_0021FF40(0, 'Z') == 35);
    std::cout << "PASS: case 0 valid char" << std::endl;
}

static void test_case_1_font_lookup_missing_char() {
    // Font 0 does not contain digits
    assert(func_0021FF40(0, '0') == -1);
    assert(func_0021FF40(0, 'a') == -1);
    assert(func_0021FF40(0, 0) == -1);
    std::cout << "PASS: case 1 missing char" << std::endl;
}

static void test_case_2_multiple_fonts_routing() {
    // Font 1: '0' -> 100, '9' -> 109
    assert(func_0021FF40(1, '0') == 100);
    assert(func_0021FF40(1, '9') == 109);
    // Font 1 does not contain 'A'
    assert(func_0021FF40(1, 'A') == -1);
    std::cout << "PASS: case 2 multiple fonts routing" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_case_0_font_lookup_valid_char();
        test_case_1_font_lookup_missing_char();
        test_case_2_multiple_fonts_routing();
        return 0;
    }

    switch (argv[1][0]) {
    case '0':
        test_case_0_font_lookup_valid_char();
        break;
    case '1':
        test_case_1_font_lookup_missing_char();
        break;
    case '2':
        test_case_2_multiple_fonts_routing();
        break;
    default:
        std::cerr << "Unknown test case: " << argv[1] << std::endl;
        return 1;
    }
    return 0;
}
