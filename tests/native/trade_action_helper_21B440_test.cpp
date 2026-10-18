#include <cassert>
#include <cstring>
#include <iostream>
#include "trade_packet.h"

extern "C" char D_00C5DF00[1024] = {0};

static int c21de90_calls = 0;
static int last_21de90_a0 = -1;
static int last_21de90_a1 = -1;
static int last_21de90_a2 = -1;
static void *last_21de90_buf = nullptr;
static int last_21de90_t0 = -1;
static int last_21de90_t1 = -1;
static int last_21de90_t2 = -1;
static int last_21de90_t3 = -1;

extern "C" {
int func_0021B440(void *palette_obj, int unused, int start_idx, int count, void *dst_buf);
int func_0021B4C0(void *palette_obj, int unused, int start_idx, int count, void *src_buf, int trans_idx);
void func_0021DE90(int a0, int a1, int a2, void *clut_buf, int t0, int t1, int t2, int t3) {
    c21de90_calls++;
    last_21de90_a0 = a0;
    last_21de90_a1 = a1;
    last_21de90_a2 = a2;
    last_21de90_buf = clut_buf;
    last_21de90_t0 = t0;
    last_21de90_t1 = t1;
    last_21de90_t2 = t2;
    last_21de90_t3 = t3;
}
}

static void reset_mocks() {
    c21de90_calls = 0;
    last_21de90_a0 = -1;
    last_21de90_a1 = -1;
    last_21de90_a2 = -1;
    last_21de90_buf = nullptr;
    last_21de90_t0 = -1;
    last_21de90_t1 = -1;
    last_21de90_t2 = -1;
    last_21de90_t3 = -1;
    std::memset(D_00C5DF00, 0, sizeof(D_00C5DF00));
}

void test_case_copy_palette() {
    reset_mocks();
    unsigned char palette_buf[1024];
    for (int i = 0; i < 256; i++) {
        palette_buf[i * 4 + 0] = (unsigned char)i;
        palette_buf[i * 4 + 1] = (unsigned char)(i + 1);
        palette_buf[i * 4 + 2] = (unsigned char)(i + 2);
        palette_buf[i * 4 + 3] = (unsigned char)(i + 3);
    }

    unsigned char pal_obj[0x20];
    *(unsigned char **)(pal_obj + 4) = palette_buf;

    assert(func_0021B440(pal_obj, 0, 10, 4, nullptr) == 1);

    unsigned char dst[16];
    int res = func_0021B440(pal_obj, 0, 10, 4, dst);
    assert(res == 0);
    assert(dst[0] == 10);
    assert(dst[1] == 11);
    assert(dst[2] == 12);
    assert(dst[3] == 13);
    assert(dst[12] == 13); // 4th color
}

void test_case_set_palette_and_alpha() {
    reset_mocks();
    unsigned char palette_buf[1024];
    std::memset(palette_buf, 0, sizeof(palette_buf));

    unsigned char pal_obj[0x20];
    *(unsigned char **)(pal_obj + 4) = palette_buf;
    *(unsigned short *)(pal_obj + 2) = 0x20; // clut_offset

    unsigned char src[8];
    // Color 0
    src[0] = 0x11; src[1] = 0x22; src[2] = 0x33; src[3] = 0x44;
    // Color 1
    src[4] = 0x55; src[5] = 0x66; src[6] = 0x77; src[7] = 0x88;

    // Set 2 colors starting at index 5, with trans_idx = 5
    int res = func_0021B4C0(pal_obj, 0, 5, 2, src, 5);
    assert(res == 0);

    // Color 5 is trans_idx -> alpha must be 0
    assert(palette_buf[5 * 4 + 0] == 0x11);
    assert(palette_buf[5 * 4 + 1] == 0x22);
    assert(palette_buf[5 * 4 + 2] == 0x33);
    assert(palette_buf[5 * 4 + 3] == 0x00); // alpha = 0

    // Color 6 is not trans_idx -> alpha must be 0x80
    assert(palette_buf[6 * 4 + 0] == 0x55);
    assert(palette_buf[6 * 4 + 1] == 0x66);
    assert(palette_buf[6 * 4 + 2] == 0x77);
    assert((unsigned char)palette_buf[6 * 4 + 3] == 0x80);

    // Verify func_0021B560 and func_0021DE90 were called
    assert(c21de90_calls == 1);
    assert(last_21de90_a0 == 0x1F00);
    assert(last_21de90_a2 == 4);
    assert(last_21de90_buf == D_00C5DF00);
    assert(last_21de90_t2 == 16);
    assert(last_21de90_t3 == 16);
}

void test_case_swizzle_formula() {
    reset_mocks();
    unsigned char palette_buf[1024];
    for (int i = 0; i < 256; i++) {
        palette_buf[i * 4 + 0] = (unsigned char)i;
        palette_buf[i * 4 + 1] = 0;
        palette_buf[i * 4 + 2] = 0;
        palette_buf[i * 4 + 3] = 0;
    }

    unsigned char pal_obj[0x20];
    *(unsigned short *)(pal_obj + 2) = 0;

    func_0021B560(pal_obj, (char *)palette_buf);
    assert(last_21de90_t2 == 16);
    assert(last_21de90_t3 == 16);

    // For index 8 (binary 00001000):
    // bit 3 is 1, bit 4 is 0.
    // Swizzled: bit 4 becomes 1, bit 3 becomes 0 -> index 16 (00010000)!
    unsigned char val_at_16 = (unsigned char)D_00C5DF00[16 * 4];
    assert(val_at_16 == 8);

    // For index 16 (binary 00010000):
    // bit 4 is 1, bit 3 is 0.
    // Swizzled: becomes index 8!
    unsigned char val_at_8 = (unsigned char)D_00C5DF00[8 * 4];
    assert(val_at_8 == 16);
}

void test_case_null_palette_data_upload() {
    reset_mocks();
    std::memset(D_00C5DF00, 0x5A, sizeof(D_00C5DF00));

    unsigned char pal_obj[0x20];
    std::memset(pal_obj, 0, sizeof(pal_obj));
    *(unsigned short *)(pal_obj + 2) = 0x20; // clut_offset = 0x20

    func_0021B560(pal_obj, nullptr);

    assert(c21de90_calls == 1);
    assert(last_21de90_a0 == 0x1F00);
    assert(last_21de90_a1 == 0);
    assert(last_21de90_a2 == 4);
    assert(last_21de90_buf == D_00C5DF00);
    assert(last_21de90_t2 == 16);
    assert(last_21de90_t3 == 16);
    // Verify D_00C5DF00 was not modified by swizzling
    for (size_t i = 0; i < sizeof(D_00C5DF00); i++) {
        assert(static_cast<unsigned char>(D_00C5DF00[i]) == 0x5A);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_copy_palette();
    else if (c == 1) test_case_set_palette_and_alpha();
    else if (c == 2) test_case_swizzle_formula();
    else if (c == 3) test_case_null_palette_data_upload();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
