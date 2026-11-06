#include <cstdint>
#include <iostream>

extern "C" {
    void func_00228B60(void* a0);
}

int main() {
    std::cout << "Testing kt_gs_render_228b60 interface..." << std::endl;
    func_00228B60(nullptr);
    return 0;
}
