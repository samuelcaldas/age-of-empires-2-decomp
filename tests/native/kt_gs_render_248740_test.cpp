#include <cassert>
#include <iostream>
#include "kt_gs_render_248740.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00248740(dummy);
    assert(dummy[0] == 0xE0);
    std::cout << "kt_gs_render_248740 native test passed!" << std::endl;
    return 0;
}
