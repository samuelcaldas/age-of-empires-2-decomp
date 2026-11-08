#include <cassert>
#include <iostream>
#include "kt_gs_render_248e50.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00248E50(dummy);
    assert(dummy[0] == 0x60);
    std::cout << "kt_gs_render_248e50 native test passed!" << std::endl;
    return 0;
}
