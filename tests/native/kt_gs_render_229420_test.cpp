#include <cstdint>
#include <iostream>

extern "C" {
    void func_00229420(void* a0);
    int func_00229560(void* a0, void* a1);
}

int main() {
    std::cout << "Testing kt_gs_render_229420 interface..." << std::endl;
    func_00229420(nullptr);
    return 0;
}
