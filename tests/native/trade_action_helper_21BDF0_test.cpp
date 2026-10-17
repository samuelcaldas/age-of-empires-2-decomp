#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
void func_0021BDF0();
void func_0021BFB0();

char D_00C5E300[256];
void *D_004E32E4 = nullptr;

static int g_alloc_size = 0;
static void *g_mock_allocated = nullptr;
void *func_100850(unsigned int size) {
    g_alloc_size = size;
    return g_mock_allocated;
}

static void *g_ctor_obj = nullptr;
static void *g_ctor_cfg = nullptr;
static int g_ctor_arg = 0;
void func_2F61F0(void *obj, void *cfg, int arg) {
    g_ctor_obj = obj;
    g_ctor_cfg = cfg;
    g_ctor_arg = arg;
}

static int g_reset_streams_calls = 0;
void func_00219F60() {
    g_reset_streams_calls++;
}

static int g_virtual_call_count = 0;
static void MockVirtualMethod3(void *self) {
    g_virtual_call_count++;
}
}

static void test_func_0021BDF0_success() {
    g_alloc_size = 0;
    g_ctor_obj = nullptr;
    g_reset_streams_calls = 0;
    D_004E32E4 = nullptr;
    std::memset(D_00C5E300, 0, sizeof(D_00C5E300));

    // Prepare mock object with vtable
    void *vtable[5] = {nullptr, nullptr, nullptr, (void *)MockVirtualMethod3, nullptr};
    void *mock_obj[4] = {vtable, nullptr, nullptr, nullptr};
    g_mock_allocated = mock_obj;

    func_0021BDF0();

    assert(g_alloc_size == 0x1948);
    assert(g_ctor_obj == mock_obj);
    assert(g_ctor_cfg == D_00C5E300);
    assert(g_ctor_arg == 1);
    assert(g_reset_streams_calls == 1);
    assert(D_004E32E4 == mock_obj);

    // Verify key fields in D_00C5E300
    assert(std::strcmp(D_00C5E300 + 0x18, "palette") == 0);
    assert(std::strcmp(D_00C5E300 + 0x28, "mcursors") == 0);
    assert(*(int *)(D_00C5E300 + 0x04) == 1);
    assert(*(int *)(D_00C5E300 + 0x08) == 3);
    assert(*(short *)(D_00C5E300 + 0x40) == 9);
    assert(*(short *)(D_00C5E300 + 0x42) == 15);
    assert(*(short *)(D_00C5E300 + 0x44) == 99);
    assert(*(int *)(D_00C5E300 + 0xA4) == 640);
    assert(*(int *)(D_00C5E300 + 0xA8) == 448);

    // Test func_0021BFB0 dispatch
    g_virtual_call_count = 0;
    func_0021BFB0();
    assert(g_virtual_call_count == 1);

    std::cout << "PASS: test_func_0021BDF0_success" << std::endl;
}

static void test_func_0021BDF0_alloc_failure() {
    g_alloc_size = 0;
    g_ctor_obj = nullptr;
    g_reset_streams_calls = 0;
    char dummy_existing[16];
    D_004E32E4 = dummy_existing; // Pre-set to non-null to verify it gets cleared
    g_mock_allocated = nullptr; // allocation fails

    func_0021BDF0();

    assert(g_alloc_size == 0x1948);
    assert(g_ctor_obj == nullptr); // constructor skipped
    assert(g_reset_streams_calls == 1); // stream reset called on failure too
    assert(D_004E32E4 == nullptr); // cleared to nullptr

    std::cout << "PASS: test_func_0021BDF0_alloc_failure" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0021BDF0_success();
        test_func_0021BDF0_alloc_failure();
        return 0;
    }
    if (argv[1][0] == '0') {
        test_func_0021BDF0_success();
    } else if (argv[1][0] == '1') {
        test_func_0021BDF0_alloc_failure();
    }
    return 0;
}
