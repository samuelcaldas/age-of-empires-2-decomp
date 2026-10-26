#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>

extern "C" {
void *func_0021BFD0(void *obj, int val);
void *func_0021C050(void *obj);
void *func_0021C0D0(void *obj, int a1, int a2, int a3, int t0, int t1);
void *func_0021C1D0(void *obj, int a1, int a2, int a3, int t0, int t1);
void *func_0021C2D0(void *obj, int a1, int a2, int a3, int t0, int t1, int t2, int t3, int sp90);

uint32_t D_00392B30[4] = {0x00008000, 0x10000000, 0x0000000E, 0x00000000};

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
static uint32_t g_last_tag[4];
void *func_1045E8(void *obj, uint32_t *tag) {
    g_set_tag_calls++;
    std::memcpy(g_last_tag, tag, sizeof(g_last_tag));
    return obj;
}

static int g_reg_write_calls = 0;
static int g_last_reg = -1;
static uint64_t g_last_data = 0;
void *func_1046A8(void *obj, int reg, uint64_t data) {
    g_reg_write_calls++;
    g_last_reg = reg;
    g_last_data = data;
    return obj;
}

static int g_finalize_calls = 0;
void *func_104600(void *obj) {
    g_finalize_calls++;
    return obj;
}
}

static void test_func_0021BFD0() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_reg_write_calls = 0;
    g_finalize_calls = 0;

    // Test with existing object
    char my_obj[64];
    void *ret = func_0021BFD0(my_obj, 0x1234);
    assert(ret == my_obj);
    assert(g_alloc_calls == 0);
    assert(g_init_calls == 1);
    assert(g_set_tag_calls == 1);
    assert(g_reg_write_calls == 1);
    assert(g_last_reg == 0x08);
    assert(g_last_data == 0x1234);
    assert(g_finalize_calls == 1);

    // Test with null object -> triggers allocation
    ret = func_0021BFD0(nullptr, 0x5678);
    assert(ret == g_allocated_buf);
    assert(g_alloc_calls == 1);
    assert(g_last_data == 0x5678);

    std::cout << "PASS: test_func_0021BFD0" << std::endl;
}

static void test_func_0021C050() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_reg_write_calls = 0;
    g_finalize_calls = 0;

    char my_obj[64];
    void *ret = func_0021C050(my_obj);
    assert(ret == my_obj);
    assert(g_alloc_calls == 0);
    assert(g_init_calls == 1);
    assert(g_set_tag_calls == 1);
    assert(g_reg_write_calls == 1);
    assert(g_last_reg == 0x3F);
    assert(g_last_data == 0);
    assert(g_finalize_calls == 1);

    std::cout << "PASS: test_func_0021C050" << std::endl;
}

static void test_func_0021C0D0() {
    g_reg_write_calls = 0;
    char my_obj[64];

    // a1=1, a2=2, a3=3, t0=1, t1=2
    // bitfield: 1 | (2 << 2) | (3 << 4) | (1 << 6) | ((uint64_t)2 << 32)
    // 1 + 8 + 48 + 64 = 121 (0x79) | (2ULL << 32)
    void *ret = func_0021C0D0(my_obj, 1, 2, 3, 1, 2);
    assert(ret == my_obj);
    assert(g_reg_write_calls == 1);
    assert(g_last_reg == 0x42);
    uint64_t expected = (uint64_t)1 | ((uint64_t)2 << 2) | ((uint64_t)3 << 4) | ((uint64_t)1 << 6) | ((uint64_t)2 << 32);
    assert(g_last_data == expected);

    std::cout << "PASS: test_func_0021C0D0" << std::endl;
}

static void test_func_0021C1D0() {
    g_reg_write_calls = 0;
    char my_obj[64];

    void *ret = func_0021C1D0(my_obj, 1, 2, 3, 1, 2);
    assert(ret == my_obj);
    assert(g_reg_write_calls == 1);
    assert(g_last_reg == 0x43);
    uint64_t expected = (uint64_t)1 | ((uint64_t)2 << 2) | ((uint64_t)3 << 4) | ((uint64_t)1 << 6) | ((uint64_t)2 << 32);
    assert(g_last_data == expected);

    std::cout << "PASS: test_func_0021C1D0" << std::endl;
}

static void test_func_0021C2D0() {
    g_reg_write_calls = 0;
    char my_obj[64];

    // a1=1, a2=1, a3=2, t0=3, t1=1, t2=0, t3=1, sp90=1
    // v1 = 1 | (1 << 1) | (2 << 4) | (3 << 12) | (1 << 14) | (0 << 15) | (1 << 16) | (1 << 17)
    // = 1 | 2 | 32 | 12288 | 16384 | 0 | 65536 | 131072
    void *ret = func_0021C2D0(my_obj, 1, 1, 2, 3, 1, 0, 1, 1);
    assert(ret == my_obj);
    assert(g_reg_write_calls == 1);
    assert(g_last_reg == 0x48);
    uint64_t expected = 1 | (1 << 1) | (2 << 4) | (3 << 12) | (1 << 14) | (0 << 15) | (1 << 16) | (1 << 17);
    assert(g_last_data == expected);

    std::cout << "PASS: test_func_0021C2D0" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0021BFD0();
        test_func_0021C050();
        test_func_0021C0D0();
        test_func_0021C1D0();
        test_func_0021C2D0();
        return 0;
    }
    if (argv[1][0] == '0') {
        test_func_0021BFD0();
    } else if (argv[1][0] == '1') {
        test_func_0021C050();
    } else if (argv[1][0] == '2') {
        test_func_0021C0D0();
    } else if (argv[1][0] == '3') {
        test_func_0021C1D0();
    } else if (argv[1][0] == '4') {
        test_func_0021C2D0();
    }
    return 0;
}
