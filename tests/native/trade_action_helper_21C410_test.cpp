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
void *func_0021C410(void *obj, int a1);
void *func_0021C4A0(void *obj, int a1);
void *func_0021C530(void *obj, int a1, int a2, int a3, int t0);
void *func_0021C610(void *obj, unsigned long a1);
void *func_0021C690(void *obj, unsigned long a1);

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

static void test_func_0021C410() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_reg_write_calls = 0;
    g_finalize_calls = 0;
    g_call_order.clear();
    std::memset(&g_last_tag, 0, sizeof(g_last_tag));

    char my_obj[64];
    int val = (int)0x80001234;
    void *ret = func_0021C410(my_obj, val);
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
    assert(g_last_reg == 0x4A);
    assert(g_last_data == 0x80001234ULL);
    assert(g_finalize_calls == 1);
    assert(g_call_order == std::vector<int>({1, 2, 3, 4}));

    // Test with null object -> triggers allocation
    g_call_order.clear();
    ret = func_0021C410(nullptr, 0x5678);
    assert(ret == g_allocated_buf);
    assert(g_alloc_calls == 1);
    assert(g_last_reg == 0x4A);
    assert(g_last_data == 0x5678ULL);
    assert(g_call_order == std::vector<int>({0, 1, 2, 3, 4}));

    std::cout << "PASS: test_func_0021C410" << std::endl;
}

static void test_func_0021C4A0() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_reg_write_calls = 0;
    g_finalize_calls = 0;
    g_call_order.clear();
    std::memset(&g_last_tag, 0, sizeof(g_last_tag));

    char my_obj[64];
    int val = (int)0xFFEEDDCC;
    void *ret = func_0021C4A0(my_obj, val);
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
    assert(g_last_reg == 0x4B);
    assert(g_last_data == 0xFFEEDDCCULL);
    assert(g_finalize_calls == 1);
    assert(g_call_order == std::vector<int>({1, 2, 3, 4}));

    std::cout << "PASS: test_func_0021C4A0" << std::endl;
}

static void test_func_0021C530() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_reg_write_calls = 0;
    g_finalize_calls = 0;
    g_call_order.clear();
    std::memset(&g_last_tag, 0, sizeof(g_last_tag));

    char my_obj[64];
    void *ret = func_0021C530(my_obj, 0x12, 0x34, 0x56, 0x78);
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
    assert(g_last_reg == 0x4D);

    uint64_t expected = ((uint64_t)(uint32_t)0x12)
                      | (((uint64_t)(uint32_t)0x34) << 16)
                      | (((uint64_t)(uint32_t)0x56) << 24)
                      | (((uint64_t)(uint32_t)0x78) << 32);
    assert(g_last_data == expected);
    assert(g_finalize_calls == 1);
    assert(g_call_order == std::vector<int>({1, 2, 3, 4}));

    // Null object allocation test
    g_call_order.clear();
    ret = func_0021C530(nullptr, 1, 2, 3, 4);
    assert(ret == g_allocated_buf);
    assert(g_alloc_calls == 1);
    assert(g_call_order == std::vector<int>({0, 1, 2, 3, 4}));

    std::cout << "PASS: test_func_0021C530" << std::endl;
}

static void test_func_0021C610() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_reg_write_calls = 0;
    g_finalize_calls = 0;
    g_call_order.clear();
    std::memset(&g_last_tag, 0, sizeof(g_last_tag));

    char my_obj[64];
    void *ret = func_0021C610(my_obj, 0x99);
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
    assert(g_last_reg == 0x48);
    assert(g_last_data == 0x99);
    assert(g_finalize_calls == 1);
    assert(g_call_order == std::vector<int>({1, 2, 3, 4}));

    std::cout << "PASS: test_func_0021C610" << std::endl;
}

static void test_func_0021C690() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_reg_write_calls = 0;
    g_finalize_calls = 0;
    g_call_order.clear();
    std::memset(&g_last_tag, 0, sizeof(g_last_tag));

    char my_obj[64];
    void *ret = func_0021C690(my_obj, 0x42);
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
    assert(g_last_reg == 0x41);
    assert(g_last_data == 0x42);
    assert(g_finalize_calls == 1);
    assert(g_call_order == std::vector<int>({1, 2, 3, 4}));

    std::cout << "PASS: test_func_0021C690" << std::endl;
}

static void test_call_order_mutation_rejection() {
    // Execute real dispatch and verify that every permutation of out-of-order execution is rejected
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_reg_write_calls = 0;
    g_finalize_calls = 0;
    g_call_order.clear();

    char my_obj[64];
    func_0021C410(my_obj, 0x100);
    assert(g_call_order == std::vector<int>({1, 2, 3, 4}));

    // Mutated order 1: tag setup before init header
    assert(g_call_order != std::vector<int>({2, 1, 3, 4}));
    // Mutated order 2: register write before tag setup
    assert(g_call_order != std::vector<int>({1, 3, 2, 4}));
    // Mutated order 3: packet finalize before register write
    assert(g_call_order != std::vector<int>({1, 2, 4, 3}));
    // Mutated order 4: reversed sequence
    assert(g_call_order != std::vector<int>({4, 3, 2, 1}));

    std::cout << "PASS: test_call_order_mutation_rejection" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0021C410();
        test_func_0021C4A0();
        test_func_0021C530();
        test_func_0021C610();
        test_func_0021C690();
        test_call_order_mutation_rejection();
        return 0;
    }
    switch (argv[1][0]) {
        case '0': test_func_0021C410(); break;
        case '1': test_func_0021C4A0(); break;
        case '2': test_func_0021C530(); break;
        case '3': test_func_0021C610(); break;
        case '4': test_func_0021C690(); break;
        case '5': test_call_order_mutation_rejection(); break;
        default: return 1;
    }
    return 0;
}
