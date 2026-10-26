#include <cassert>
#include <iostream>

extern "C" {
void func_0021BFB0();
void *D_004E32E4 = nullptr;

static int g_virtual_call_count = 0;
static void MockVirtualMethod3(void *self) {
    g_virtual_call_count++;
}
}

static void test_func_0021BFB0_dispatch() {
    void *vtable[5] = {nullptr, nullptr, nullptr, (void *)MockVirtualMethod3, nullptr};
    void *mock_obj[4] = {vtable, nullptr, nullptr, nullptr};
    D_004E32E4 = mock_obj;

    g_virtual_call_count = 0;
    func_0021BFB0();
    assert(g_virtual_call_count == 1);

    std::cout << "PASS: test_func_0021BFB0_dispatch" << std::endl;
}

int main(int argc, char **argv) {
    test_func_0021BFB0_dispatch();
    return 0;
}
