#include <cstdint>
#include <iostream>

extern "C" {
    void func_00228F20(void* a0);
    void func_002292D0(void* a0, int a1, int* a2, int* a3);
}

int main() {
    std::cout << "Testing kt_gs_render_228f20 interface..." << std::endl;
    func_00228F20(nullptr);
    return 0;
}
