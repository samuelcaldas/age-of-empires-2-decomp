#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include "render_font_context.h"

extern "C" {
void *D_004E32FC = nullptr;
}

static void test_case_0_context_roundtrip() {
    func_0021FEC0(nullptr);
    assert(func_0021FED0() == nullptr);

    int stack_var = 42;
    func_0021FEC0(&stack_var);
    assert(func_0021FED0() == &stack_var);

    void *heap_var = std::malloc(128);
    assert(heap_var != nullptr);
    func_0021FEC0(heap_var);
    assert(func_0021FED0() == heap_var);
    std::free(heap_var);

    func_0021FEC0(reinterpret_cast<void *>(0x12345678));
    assert(func_0021FED0() == reinterpret_cast<void *>(0x12345678));

    std::cout << "PASS: case 0 context roundtrip" << std::endl;
}

static void test_case_1_empty_sentinel_table() {
    struct GlyphRange table[] = {
        {0xFFFF, 0, 0, 0}
    };

    assert(func_0021FEE0(table, 'A') == -1);
    assert(func_0021FEE0(table, 0) == -1);
    assert(func_0021FEE0(table, 0xFFFF) == -1);

    std::cout << "PASS: case 1 empty sentinel table" << std::endl;
}

static void test_case_2_single_range_boundaries() {
    struct GlyphRange table[] = {
        {'A', 'Z', 100, 0},
        {0xFFFF, 0, 0, 0}
    };

    // Below range
    assert(func_0021FEE0(table, '@') == -1); // 64
    assert(func_0021FEE0(table, 0) == -1);

    // Exact lower boundary
    assert(func_0021FEE0(table, 'A') == 100);

    // Inside range
    assert(func_0021FEE0(table, 'B') == 101);
    assert(func_0021FEE0(table, 'Y') == 124);

    // Exact upper boundary
    assert(func_0021FEE0(table, 'Z') == 125); // 100 + ('Z' - 'A') = 100 + 25 = 125

    // Above range
    assert(func_0021FEE0(table, '[') == -1); // 91
    assert(func_0021FEE0(table, 200) == -1);

    std::cout << "PASS: case 2 single range boundaries" << std::endl;
}

static void test_case_3_disjoint_ranges_and_gaps() {
    struct GlyphRange table[] = {
        {'0', '9', 10, 0},   // '0'=48 .. '9'=57 -> 10 .. 19
        {'A', 'Z', 100, 0},  // 'A'=65 .. 'Z'=90 -> 100 .. 125
        {0xFFFF, 0, 0, 0}
    };

    // Range 1 tests
    assert(func_0021FEE0(table, '0') == 10);
    assert(func_0021FEE0(table, '5') == 15);
    assert(func_0021FEE0(table, '9') == 19);

    // Gap between '9' (57) and 'A' (65): ':', ';', '<', '=', '>', '?', '@'
    assert(func_0021FEE0(table, ':') == -1); // 58
    assert(func_0021FEE0(table, '@') == -1); // 64

    // Range 2 tests
    assert(func_0021FEE0(table, 'A') == 100);
    assert(func_0021FEE0(table, 'Z') == 125);

    // Beyond range 2
    assert(func_0021FEE0(table, 'a') == -1);

    std::cout << "PASS: case 3 disjoint ranges and gaps" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_case_0_context_roundtrip();
        test_case_1_empty_sentinel_table();
        test_case_2_single_range_boundaries();
        test_case_3_disjoint_ranges_and_gaps();
        return 0;
    }

    switch (argv[1][0]) {
    case '0':
        test_case_0_context_roundtrip();
        break;
    case '1':
        test_case_1_empty_sentinel_table();
        break;
    case '2':
        test_case_2_single_range_boundaries();
        break;
    case '3':
        test_case_3_disjoint_ranges_and_gaps();
        break;
    default:
        std::cerr << "Unknown test case: " << argv[1] << std::endl;
        return 1;
    }

    return 0;
}
