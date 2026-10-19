#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

extern "C" {
void *func_0021D2C0(void *obj, int a1, int a2, const short *xy_pts, int t0, int t1, int t2, int t3);
void *func_0021D4E0(void *obj, int a1, int a2, int a3, const short *xy_pts, int t0, int t1, int t2, int t3);

uint32_t D_00392B70[4] = {0x00000000, 0x00000000, 0x0000000E, 0x00000000};
uint32_t D_00392B80[4] = {0x00000000, 0x00000000, 0x0000000E, 0x00000000};
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

static void test_func_0021D2C0() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_writes.clear();
    g_finalize_calls = 0;

    char my_obj[64];
    short pts[16] = {
        10, 20, 0, 0,
        30, 20, 0, 0,
        10, 40, 0, 0,
        30, 40, 0, 0
    };

    void *ret = func_0021D2C0(my_obj, 1, 0x55, pts, 0x12, 3, 5, 1);
    assert(ret == my_obj);
    assert(g_alloc_calls == 0);
    assert(g_init_calls == 1);
    assert(g_set_tag_calls == 1);
    assert(g_finalize_calls == 1);

    assert(g_writes.size() == 5);
    assert(g_writes[0].reg == 0x01);
    assert(g_writes[0].data == 0x55);

    for (int i = 1; i <= 4; ++i) {
        assert(g_writes[i].reg == 0x04);
        assert((g_writes[i].data >> 32) == 0x12);
    }

    std::cout << "PASS: test_func_0021D2C0" << std::endl;
}

static void test_func_0021D4E0() {
    g_alloc_calls = 0;
    g_writes.clear();

    char my_obj[64];
    short pts[16] = {
        0, 0, 0, 0,
        10, 0, 0, 0,
        0, 10, 0, 0,
        10, 10, 0, 0
    };

    void *ret = func_0021D4E0(my_obj, 0x99, 2, 0x33, pts, 0x34, 0, 2, 1);
    assert(ret == my_obj);
    assert(g_writes.size() == 6);
    assert(g_writes[0].reg == 0x07);
    assert(g_writes[0].data == 0x99);
    assert(g_writes[1].reg == 0x01);
    assert(g_writes[1].data == 0x33);

    std::cout << "PASS: test_func_0021D4E0" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0021D2C0();
        test_func_0021D4E0();
        return 0;
    }
    if (argv[1][0] == '0') {
        test_func_0021D2C0();
    } else if (argv[1][0] == '1') {
        test_func_0021D4E0();
    }
    return 0;
}
