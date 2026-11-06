#include <cstdint>
#include <iostream>

extern "C" {
    int func_00229810(void* a0, void* a1, int a2);
}

int main() {
    std::cout << "Testing kt_gs_render_229810 interface..." << std::endl;
    int res = func_00229810(nullptr, nullptr, 0);
    (void)res;
    return 0;
}
