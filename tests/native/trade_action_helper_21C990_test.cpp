#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

extern "C" {
void *func_0021C990(void *obj, int a1, int a2, int a3, const short *uv_rect, const short *xy_pts, int t2, int t3, int z);
void *func_0021CC90(void *obj, int a1, int a2, int a3, const short *uv_rect, const short *rect, int t2, int t3, int z);

uint32_t D_00392B40[4] = {0x00000000, 0x00000000, 0x0000000E, 0x00000000};
uint16_t D_00CA158C = 640;
uint16_t D_00CA158E = 448;

static int g_alloc_calls = 0;
static char g_allocated_buf[256];
void *func_123908(void *unused) {
    g_alloc_calls++;
    return g_allocated_buf;
}

static int g_init_calls = 0;
void *func_104448(void *obj, int a1, int a2, int a3) {
    g_init_calls++;
    return obj;
}

static int g_set_tag_calls = 0;
static uint64_t g_last_tag[2];
void *func_1045E8(void *obj, uint64_t *tag) {
    g_set_tag_calls++;
    g_last_tag[0] = tag[0];
    g_last_tag[1] = tag[1];
    return obj;
}

struct RegWrite {
    int reg;
    uint64_t data;
};
static std::vector<RegWrite> g_writes;

void *func_1046A8(void *obj, int reg, uint64_t data) {
    g_writes.push_back({reg, data});
    return obj;
}

static int g_finalize_calls = 0;
void *func_104600(void *obj) {
    g_finalize_calls++;
    return obj;
}
}

static void test_func_0021C990() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_writes.clear();
    g_finalize_calls = 0;

    char my_obj[64];
    short uv[4] = {10, 20, 30, 40}; // u=10, v=20, w=30, h=40
    // 4 points (x, y) spaced by 8 bytes (4 shorts: x, y, 0, 0)
    short pts[16] = {
        100, 200, 0, 0,
        150, 200, 0, 0,
        100, 250, 0, 0,
        150, 250, 0, 0
    };

    void *ret = func_0021C990(my_obj, 0x11, 2, 0x22, uv, pts, 0x55, 1, 10);
    assert(ret == my_obj);
    assert(g_alloc_calls == 0);
    assert(g_init_calls == 1);
    assert(g_set_tag_calls == 1);
    assert(g_finalize_calls == 1);

    // t3 = 1 -> writes reg 0x07 with 0x11
    assert(g_writes.size() == 10); // 1 (0x07) + 1 (0x01) + 4*(0x03, 0x04)
    assert(g_writes[0].reg == 0x07);
    assert(g_writes[0].data == 0x11);

    assert(g_writes[1].reg == 0x01);
    assert(g_writes[1].data == 0x22);

    // UV0 = (10 << 4) | ((20 << 4) << 16) = 160 | (320 << 16)
    assert(g_writes[2].reg == 0x03);
    assert(g_writes[2].data == (160 | (320 << 16)));

    // XYZ0 reg 0x04: upper 32 bits = 0x55 << 32
    assert(g_writes[3].reg == 0x04);
    assert((g_writes[3].data >> 32) == 0x55);

    std::cout << "PASS: test_func_0021C990" << std::endl;
}

static void test_func_0021CC90() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_writes.clear();
    g_finalize_calls = 0;

    char my_obj[64];
    short uv[4] = {5, 10, 15, 20};
    short rect[4] = {50, 60, 100, 80}; // x=50, y=60, w=100, h=80

    // t3 = 0 -> writes reg 0x06 with a1
    void *ret = func_0021CC90(my_obj, 0x99, 1, 0x33, uv, rect, 0x77, 0, 5);
    assert(ret == my_obj);
    assert(g_writes.size() == 10);
    assert(g_writes[0].reg == 0x06);
    assert(g_writes[0].data == 0x99);

    assert(g_writes[1].reg == 0x01);
    assert(g_writes[1].data == 0x33);

    std::cout << "PASS: test_func_0021CC90" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0021C990();
        test_func_0021CC90();
        return 0;
    }
    if (argv[1][0] == '0') {
        test_func_0021C990();
    } else if (argv[1][0] == '1') {
        test_func_0021CC90();
    }
    return 0;
}
