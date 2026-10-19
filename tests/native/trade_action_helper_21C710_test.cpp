#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

struct u128 {
    uint32_t words[4];
};

static std::vector<int> g_call_order;

extern "C" {
void *func_0021C710(void *obj, unsigned long a1);
void *func_0021C790(void *obj, unsigned long a1);
void *func_0021C810(void *obj, int a1, int a2, int a3);
void *func_0021C8D0(void *obj, int a1, int a2, int a3);

uint32_t D_00392B30[4] = {0x00008000, 0x10000000, 0x0000000E, 0x00000000};

static int g_alloc_calls = 0;
static char g_allocated_buf[256];
void *func_123908(void *unused) {
    g_alloc_calls++;
    g_call_order.push_back(0);
    return g_allocated_buf;
}

static int g_init_calls = 0;
static int g_init_a1 = -1, g_init_a2 = -1, g_init_a3 = -1;
void *func_104448(void *obj, int a1, int a2, int a3) {
    g_init_calls++;
    g_init_a1 = a1;
    g_init_a2 = a2;
    g_init_a3 = a3;
    g_call_order.push_back(1);
    return obj;
}

static int g_set_tag_calls = 0;
static u128 g_last_tag;
void *func_1045E8(void *obj, u128 tag) {
    g_set_tag_calls++;
    g_last_tag = tag;
    g_call_order.push_back(2);
    return obj;
}

static int g_reg_write_calls = 0;
static int g_last_reg = -1;
static uint64_t g_last_data = 0;
void *func_1046A8(void *obj, int reg, uint64_t data) {
    g_reg_write_calls++;
    g_last_reg = reg;
    g_last_data = data;
    g_call_order.push_back(3);
    return obj;
}

static int g_finalize_calls = 0;
void *func_104600(void *obj) {
    g_finalize_calls++;
    g_call_order.push_back(4);
    return obj;
}
}

static void test_func_0021C710() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_reg_write_calls = 0;
    g_finalize_calls = 0;
    g_call_order.clear();
    std::memset(&g_last_tag, 0, sizeof(g_last_tag));

    char my_obj[64];
    void *ret = func_0021C710(my_obj, 0x33);
    assert(ret == my_obj);
    assert(g_alloc_calls == 0);
    assert(g_init_calls == 1);
    assert(g_init_a1 == 0 && g_init_a2 == 0 && g_init_a3 == 0);
    assert(g_set_tag_calls == 1);
    assert(g_last_tag.words[0] == 0x00008000);
    assert(g_last_tag.words[1] == 0x10000000);
    assert(g_last_tag.words[2] == 0x0000000E);
    assert(g_last_tag.words[3] == 0x00000000);
    assert(g_reg_write_calls == 1);
    assert(g_last_reg == 0x14);
    assert(g_last_data == 0x33ULL);
    assert(g_finalize_calls == 1);
    assert(g_call_order == std::vector<int>({1, 2, 3, 4}));

    // Null object triggers allocation
    g_call_order.clear();
    ret = func_0021C710(nullptr, 0x44);
    assert(ret == g_allocated_buf);
    assert(g_alloc_calls == 1);
    assert(g_last_reg == 0x14);
    assert(g_last_data == 0x44ULL);
    assert(g_call_order == std::vector<int>({0, 1, 2, 3, 4}));

    std::cout << "PASS: test_func_0021C710" << std::endl;
}

static void test_func_0021C790() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_reg_write_calls = 0;
    g_finalize_calls = 0;
    g_call_order.clear();
    std::memset(&g_last_tag, 0, sizeof(g_last_tag));

    char my_obj[64];
    void *ret = func_0021C790(my_obj, 0x77);
    assert(ret == my_obj);
    assert(g_alloc_calls == 0);
    assert(g_init_calls == 1);
    assert(g_init_a1 == 0 && g_init_a2 == 0 && g_init_a3 == 0);
    assert(g_set_tag_calls == 1);
    assert(g_last_tag.words[0] == 0x00008000);
    assert(g_last_tag.words[1] == 0x10000000);
    assert(g_last_tag.words[2] == 0x0000000E);
    assert(g_last_tag.words[3] == 0x00000000);
    assert(g_reg_write_calls == 1);
    assert(g_last_reg == 0x16);
    assert(g_last_data == 0x77ULL);
    assert(g_finalize_calls == 1);
    assert(g_call_order == std::vector<int>({1, 2, 3, 4}));

    // Null object test
    g_call_order.clear();
    ret = func_0021C790(nullptr, 0x88);
    assert(ret == g_allocated_buf);
    assert(g_alloc_calls == 1);
    assert(g_call_order == std::vector<int>({0, 1, 2, 3, 4}));

    std::cout << "PASS: test_func_0021C790" << std::endl;
}

static void test_func_0021C810() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_reg_write_calls = 0;
    g_finalize_calls = 0;
    g_call_order.clear();
    std::memset(&g_last_tag, 0, sizeof(g_last_tag));

    char my_obj[64];
    void *ret = func_0021C810(my_obj, 10, 20, 30);
    assert(ret == my_obj);
    assert(g_alloc_calls == 0);
    assert(g_init_calls == 1);
    assert(g_init_a1 == 0 && g_init_a2 == 0 && g_init_a3 == 0);
    assert(g_set_tag_calls == 1);
    assert(g_last_tag.words[0] == 0x00008000);
    assert(g_last_tag.words[1] == 0x10000000);
    assert(g_last_tag.words[2] == 0x0000000E);
    assert(g_last_tag.words[3] == 0x00000000);
    assert(g_reg_write_calls == 1);
    assert(g_last_reg == 0x3B);
    uint64_t expected = ((uint64_t)(uint32_t)10)
                      | (((uint64_t)(uint32_t)20) << 15)
                      | (((uint64_t)(uint32_t)30) << 32);
    assert(g_last_data == expected);
    assert(g_finalize_calls == 1);
    assert(g_call_order == std::vector<int>({1, 2, 3, 4}));

    // Null object test
    g_call_order.clear();
    ret = func_0021C810(nullptr, 1, 2, 3);
    assert(ret == g_allocated_buf);
    assert(g_alloc_calls == 1);
    assert(g_call_order == std::vector<int>({0, 1, 2, 3, 4}));

    std::cout << "PASS: test_func_0021C810" << std::endl;
}

static void test_func_0021C8D0() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_reg_write_calls = 0;
    g_finalize_calls = 0;
    g_call_order.clear();
    std::memset(&g_last_tag, 0, sizeof(g_last_tag));

    char my_obj[64];
    void *ret = func_0021C8D0(my_obj, 5, 15, 25);
    assert(ret == my_obj);
    assert(g_alloc_calls == 0);
    assert(g_init_calls == 1);
    assert(g_init_a1 == 0 && g_init_a2 == 0 && g_init_a3 == 0);
    assert(g_set_tag_calls == 1);
    assert(g_last_tag.words[0] == 0x00008000);
    assert(g_last_tag.words[1] == 0x10000000);
    assert(g_last_tag.words[2] == 0x0000000E);
    assert(g_last_tag.words[3] == 0x00000000);
    assert(g_reg_write_calls == 1);
    assert(g_last_reg == 0x4F);
    uint64_t expected = ((uint64_t)(uint32_t)5)
                      | (((uint64_t)(uint32_t)15) << 24)
                      | (((uint64_t)(uint32_t)25) << 32);
    assert(g_last_data == expected);
    assert(g_finalize_calls == 1);
    assert(g_call_order == std::vector<int>({1, 2, 3, 4}));

    // Null object test
    g_call_order.clear();
    ret = func_0021C8D0(nullptr, 5, 15, 25);
    assert(ret == g_allocated_buf);
    assert(g_alloc_calls == 1);
    assert(g_call_order == std::vector<int>({0, 1, 2, 3, 4}));

    std::cout << "PASS: test_func_0021C8D0" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0021C710();
        test_func_0021C790();
        test_func_0021C810();
        test_func_0021C8D0();
        return 0;
    }
    if (argv[1][0] == '0') {
        test_func_0021C710();
    } else if (argv[1][0] == '1') {
        test_func_0021C790();
    } else if (argv[1][0] == '2') {
        test_func_0021C810();
    } else if (argv[1][0] == '3') {
        test_func_0021C8D0();
    }
    return 0;
}
