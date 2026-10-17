#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

union StagingWord { unsigned char bytes[4]; int word; };
union StagingPtr { unsigned char bytes[4]; unsigned char *ptr; int word; };
union IdxWord { unsigned char bytes[4]; int word; };

extern "C" {
StagingWord D_004E2DA0;
StagingPtr D_004E2DA4;
int D_004E2DA8;
IdxWord D_004E2DAC;
unsigned char *D_004E2DB0, *D_004E2DB4;

int D_004E3070, D_004E3074, D_004E3078, D_004E307C, D_004E3080;
int D_004E3084, D_004E3088, D_004E308C, D_004E3090, D_004E3094;
int D_004E3098, D_004E309C, D_004E30A0, D_004E30A4, D_004E30A8;
int D_004E30AC, D_004E30B0, D_004E30B4, D_004E30B8, D_004E30BC;
int D_004E30C0, D_004E30C4, D_004E30C8, D_004E30CC, D_004E30D0;
int D_004E30D4, D_004E30D8, D_004E30DC, D_004E30E0, D_004E30E4;
int D_004E30E8, D_004E30EC, D_004E30F0, D_004E30F4, D_004E30F8;

static int g_proc_called = 0;
static void mock_proc() { g_proc_called++; }
void (*D_0038FF30[114])() = { mock_proc };

static int g_func_1522C0_called = 0;
void func_001522C0(unsigned char *destination, unsigned char *source) {
    (void)destination; (void)source;
    g_func_1522C0_called++;
}

void func_00181e40() {}
void func_0017e350(int x, int y, int w, int h, int p4, int p5, int p6, int p7);
}

static void reset_state() {
    g_proc_called = 0;
    g_func_1522C0_called = 0;
    D_004E30DC = 10;
    D_004E30E0 = 100;
    D_004E30E4 = 5;
    D_004E30E8 = 200;
}

static void test_clip_top_out_of_bounds() {
    reset_state();
    func_0017e350(0, 50, 0, 0, 5, 0, 0, 0);
    assert(g_func_1522C0_called == 0);
}

static void test_clip_bottom_out_of_bounds() {
    reset_state();
    func_0017e350(0, 50, 150, 0, 10, 0, 0, 0);
    assert(g_func_1522C0_called == 0);
}

static void test_clip_right_out_of_bounds() {
    reset_state();
    func_0017e350(0, 250, 20, 0, 10, 0, 0, 0);
    assert(g_func_1522C0_called == 0);
}

static void test_valid_scanline_dispatch() {
    reset_state();
    unsigned char dummy_segment[16] = {};
    unsigned char *row_ptr = dummy_segment;
    unsigned char **table = &row_ptr;
    D_004E3078 = (int)(intptr_t)table;
    D_004E3074 = (int)(intptr_t)table;
    D_004E2DA8 = 0;

    func_0017e350(0, 50, 20, 0, 0, 0, 0, 0);
    assert(g_func_1522C0_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int case_num = atoi(argv[1]);
    switch (case_num) {
        case 0: test_clip_top_out_of_bounds(); break;
        case 1: test_clip_bottom_out_of_bounds(); break;
        case 2: test_clip_right_out_of_bounds(); break;
        case 3: test_valid_scanline_dispatch(); break;
        default: return 1;
    }
    return 0;
}
