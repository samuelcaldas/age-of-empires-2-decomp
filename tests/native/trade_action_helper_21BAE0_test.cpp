#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
int func_0021BAE0(void *palette_obj, int start_idx, int count, void *dst_buf);
int func_0021BB20(void *palette_obj, int start_idx, int count, void *src_buf);
int func_0021BB60(void *palette_obj, int target_color);

static void *g_last_pal_obj = nullptr;
static int g_last_unused = -1;
static int g_last_start_idx = -1;
static int g_last_count = -1;
static void *g_last_buf = nullptr;
static int g_last_trans = -1;
static int g_call_count_21B440 = 0;
static int g_call_count_21B4C0 = 0;

static unsigned char g_mock_palette[256 * 4];

int func_0021B440(void *palette_obj, int unused, int start_idx, int count, void *dst_buf) {
    g_call_count_21B440++;
    g_last_pal_obj = palette_obj;
    g_last_unused = unused;
    g_last_start_idx = start_idx;
    g_last_count = count;
    g_last_buf = dst_buf;
    if (dst_buf != nullptr && count <= 256) {
        std::memcpy(dst_buf, g_mock_palette, count * 4);
    }
    return 0;
}

int func_0021B4C0(void *palette_obj, int unused, int start_idx, int count, void *src_buf, int trans_idx) {
    g_call_count_21B4C0++;
    g_last_pal_obj = palette_obj;
    g_last_unused = unused;
    g_last_start_idx = start_idx;
    g_last_count = count;
    g_last_buf = src_buf;
    g_last_trans = trans_idx;
    return 0;
}
}

static void test_func_0021BAE0() {
    g_call_count_21B440 = 0;
    char dummy_obj[16];
    char dst_buf[64];

    int ret = func_0021BAE0(dummy_obj, 10, 16, dst_buf);
    assert(ret == 16);
    assert(g_call_count_21B440 == 1);
    assert(g_last_pal_obj == dummy_obj);
    assert(g_last_unused == 0);
    assert(g_last_start_idx == 10);
    assert(g_last_count == 16);
    assert(g_last_buf == dst_buf);

    std::cout << "PASS: test_func_0021BAE0" << std::endl;
}

static void test_func_0021BB20() {
    g_call_count_21B4C0 = 0;
    char dummy_obj[16];
    char src_buf[64];

    int ret = func_0021BB20(dummy_obj, 5, 8, src_buf);
    assert(ret == 8);
    assert(g_call_count_21B4C0 == 1);
    assert(g_last_pal_obj == dummy_obj);
    assert(g_last_unused == 0);
    assert(g_last_start_idx == 5);
    assert(g_last_count == 8);
    assert(g_last_buf == src_buf);
    assert(g_last_trans == 0xFF);

    std::cout << "PASS: test_func_0021BB20" << std::endl;
}

static void test_func_0021BB60() {
    g_call_count_21B440 = 0;
    std::memset(g_mock_palette, 0, sizeof(g_mock_palette));

    // Entry 42 has color R=100, G=150, B=200
    g_mock_palette[42 * 4 + 0] = 100;
    g_mock_palette[42 * 4 + 1] = 150;
    g_mock_palette[42 * 4 + 2] = 200;
    g_mock_palette[42 * 4 + 3] = 0xFF;

    // Entry 100 has color R=105, G=152, B=201
    g_mock_palette[100 * 4 + 0] = 105;
    g_mock_palette[100 * 4 + 1] = 152;
    g_mock_palette[100 * 4 + 2] = 201;
    g_mock_palette[100 * 4 + 3] = 0xFF;

    char dummy_obj[16];
    // Target color: R=101, G=151, B=200 -> 0x00C89765
    int target_color = 101 | (151 << 8) | (200 << 16);

    int best = func_0021BB60(dummy_obj, target_color);
    assert(best == 42);
    assert(g_call_count_21B440 == 1);
    assert(g_last_start_idx == 0);
    assert(g_last_count == 256);

    // Edge case 1: exact match at index 0
    g_mock_palette[0 * 4 + 0] = 12;
    g_mock_palette[0 * 4 + 1] = 34;
    g_mock_palette[0 * 4 + 2] = 56;
    best = func_0021BB60(dummy_obj, 12 | (34 << 8) | (56 << 16));
    assert(best == 0);

    // Edge case 2: exact match at index 255
    g_mock_palette[255 * 4 + 0] = 210;
    g_mock_palette[255 * 4 + 1] = 220;
    g_mock_palette[255 * 4 + 2] = 230;
    best = func_0021BB60(dummy_obj, 210 | (220 << 8) | (230 << 16));
    assert(best == 255);

    // Edge case 3: identical distance tie breaker preserves first encountered index
    g_mock_palette[10 * 4 + 0] = 50;
    g_mock_palette[10 * 4 + 1] = 50;
    g_mock_palette[10 * 4 + 2] = 50;
    g_mock_palette[20 * 4 + 0] = 50;
    g_mock_palette[20 * 4 + 1] = 50;
    g_mock_palette[20 * 4 + 2] = 50;
    best = func_0021BB60(dummy_obj, 50 | (50 << 8) | (50 << 16));
    assert(best == 10);

    std::cout << "PASS: test_func_0021BB60" << std::endl;
}

static void test_func_0021BB60_alpha_mask() {
    g_call_count_21B440 = 0;
    std::memset(g_mock_palette, 0, sizeof(g_mock_palette));

    // Entry 77 has color R=0x12, G=0x34, B=0x56, A=0x00
    g_mock_palette[77 * 4 + 0] = 0x12;
    g_mock_palette[77 * 4 + 1] = 0x34;
    g_mock_palette[77 * 4 + 2] = 0x56;
    g_mock_palette[77 * 4 + 3] = 0x00;

    // Entry 88 has color R=0x14, G=0x36, B=0x58, A=0xFF
    g_mock_palette[88 * 4 + 0] = 0x14;
    g_mock_palette[88 * 4 + 1] = 0x36;
    g_mock_palette[88 * 4 + 2] = 0x58;
    g_mock_palette[88 * 4 + 3] = 0xFF;

    char dummy_obj[16];
    // Target color with high bits set: 0xFF563412 (R=0x12, G=0x34, B=0x56, Alpha=0xFF)
    int target_color = (int)0xFF563412;

    int best = func_0021BB60(dummy_obj, target_color);
    assert(best == 77);
    assert(g_call_count_21B440 == 1);

    std::cout << "PASS: test_func_0021BB60_alpha_mask" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0021BAE0();
        test_func_0021BB20();
        test_func_0021BB60();
        test_func_0021BB60_alpha_mask();
        return 0;
    }
    if (argv[1][0] == '0') {
        test_func_0021BAE0();
    } else if (argv[1][0] == '1') {
        test_func_0021BB20();
    } else if (argv[1][0] == '2') {
        test_func_0021BB60();
    } else if (argv[1][0] == '3') {
        test_func_0021BB60_alpha_mask();
    }
    return 0;
}
