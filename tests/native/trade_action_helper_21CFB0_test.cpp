#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

extern "C" {
void *func_0021CFB0(void *obj, int a1, int a2, int a3, const int *xy_rect, const int *uv_rect, int t2, int t3, int z);

uint32_t D_00392B60[4] = {0x00000000, 0x00000000, 0x0000000E, 0x00000000};
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

static void test_func_0021CFB0_mode_t3_nonzero() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_writes.clear();
    g_finalize_calls = 0;

    char my_obj[64];
    int xy[4] = {10, 20, 100, 200}; // x0=10, y0=20, x1=100, y1=200
    int uv[4] = {0, 0, 64, 64};     // u0=0, v0=0, u1=64, v1=64

    void *ret = func_0021CFB0(my_obj, 0x55, 2, 0x33, xy, uv, 0x77, 1, 5);
    assert(ret == my_obj);
    assert(g_alloc_calls == 0);
    assert(g_init_calls == 1);
    assert(g_set_tag_calls == 1);
    assert(g_finalize_calls == 1);

    // t3 = 1 -> writes reg 0x07 with 0x55
    assert(g_writes.size() == 10);
    assert(g_writes[0].reg == 0x07);
    assert(g_writes[0].data == 0x55);

    // reg 0x01 with a3 (0x33)
    assert(g_writes[1].reg == 0x01);
    assert(g_writes[1].data == 0x33);

    // reg 0x03 UV0: u0=0, v0=0
    assert(g_writes[2].reg == 0x03);
    assert(g_writes[2].data == 0);

    // reg 0x04 XYZ0: upper 32 bits = 0x77 << 32
    assert(g_writes[3].reg == 0x04);
    assert((g_writes[3].data >> 32) == 0x77);

    // UV1: u1=64<<4=1024, v0=0
    assert(g_writes[4].reg == 0x03);
    assert(g_writes[4].data == 1024);

    // UV2: u0=0, v1=64<<4=1024 (shifted 16)
    assert(g_writes[6].reg == 0x03);
    assert(g_writes[6].data == (1024ULL << 16));

    // UV3: u1=1024, v1=1024<<16
    assert(g_writes[8].reg == 0x03);
    assert(g_writes[8].data == (1024 | (1024ULL << 16)));

    std::cout << "PASS: test_func_0021CFB0_mode_t3_nonzero" << std::endl;
}

static void test_func_0021CFB0_null_obj_and_t3_zero() {
    g_alloc_calls = 0;
    g_writes.clear();

    int xy[4] = {0, 0, 50, 50};
    int uv[4] = {10, 10, 20, 20};

    // t3 = 0 -> writes reg 0x06 with 0x99
    void *ret = func_0021CFB0(nullptr, 0x99, 1, 0x11, xy, uv, 0x44, 0, 0);
    assert(ret == g_allocated_buf);
    assert(g_alloc_calls == 1);
    assert(g_writes[0].reg == 0x06);
    assert(g_writes[0].data == 0x99);

    std::cout << "PASS: test_func_0021CFB0_null_obj_and_t3_zero" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0021CFB0_mode_t3_nonzero();
        test_func_0021CFB0_null_obj_and_t3_zero();
        return 0;
    }
    if (argv[1][0] == '0') {
        test_func_0021CFB0_mode_t3_nonzero();
    } else if (argv[1][0] == '1') {
        test_func_0021CFB0_null_obj_and_t3_zero();
    }
    return 0;
}
