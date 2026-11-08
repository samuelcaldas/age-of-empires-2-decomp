#include <cassert>
#include <iostream>
#include "kt_gs_render_248a10.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00248A10(dummy);
    assert(dummy[0] == 0xD0);
    std::cout << "kt_gs_render_248a10 native test passed!" << std::endl;
    return 0;
}
