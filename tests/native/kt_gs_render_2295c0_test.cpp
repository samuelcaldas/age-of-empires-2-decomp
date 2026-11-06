#include <cstdint>
#include <iostream>

extern "C" {
    void* func_002295C0(void* a0, int a1, int a2, int a3);
}

int main() {
    std::cout << "Testing kt_gs_render_2295c0 interface..." << std::endl;
    void* p = func_002295C0(nullptr, 0, 0, 0);
    (void)p;
    return 0;
}
