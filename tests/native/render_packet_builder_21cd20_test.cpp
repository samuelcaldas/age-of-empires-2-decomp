#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

extern "C" {
void *func_0021CD20(void *obj, int a1, int a2, const short *xy_pts, int t0, int t1, int t2);
void *func_0021CF30(void *obj, int a1, int a2, const short *rect, int t0, int t1);

uint32_t D_00392B50[4] = {0x00000000, 0x00000000, 0x0000000E, 0x00000000};
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

static void test_func_0021CD20() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_writes.clear();
    g_finalize_calls = 0;

    char my_obj[64];
    // 4 points (x, y) spaced by 8 bytes (4 shorts: x, y, 0, 0)
    short pts[16] = {
        100, 200, 0, 0,
        150, 200, 0, 0,
        100, 250, 0, 0,
        150, 250, 0, 0
    };

    void *ret = func_0021CD20(my_obj, 1, 0x22, pts, 0x55, 2, 10);
    assert(ret == my_obj);
    assert(g_alloc_calls == 0);
    assert(g_init_calls == 1);
    assert(g_set_tag_calls == 1);
    assert(g_finalize_calls == 1);

    // writes reg 0x01 (data = 0x22) + 4 writes to reg 0x04
    assert(g_writes.size() == 5);
    assert(g_writes[0].reg == 0x01);
    assert(g_writes[0].data == 0x22);

    // Reg 0x04 writes (XYZ)
    for (int i = 1; i <= 4; ++i) {
        assert(g_writes[i].reg == 0x04);
        assert((g_writes[i].data >> 32) == 0x55);
    }

    // Test with null object -> triggers allocation
    ret = func_0021CD20(nullptr, 1, 0x22, pts, 0x55, 2, 10);
    assert(ret == g_allocated_buf);
    assert(g_alloc_calls == 1);

    std::cout << "PASS: test_func_0021CD20" << std::endl;
}

static void test_func_0021CF30() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_writes.clear();
    g_finalize_calls = 0;

    char my_obj[64];
    short rect[4] = {50, 60, 100, 80}; // x=50, y=60, w=100, h=80

    void *ret = func_0021CF30(my_obj, 2, 0x44, rect, 0x66, 3);
    assert(ret == my_obj);
    assert(g_writes.size() == 5);
    assert(g_writes[0].reg == 0x01);
    assert(g_writes[0].data == 0x44);

    for (int i = 1; i <= 4; ++i) {
        assert(g_writes[i].reg == 0x04);
        assert((g_writes[i].data >> 32) == 0x66);
    }

    std::cout << "PASS: test_func_0021CF30" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0021CD20();
        test_func_0021CF30();
        return 0;
    }
    if (argv[1][0] == '0') {
        test_func_0021CD20();
    } else if (argv[1][0] == '1') {
        test_func_0021CF30();
    }
    return 0;
}
