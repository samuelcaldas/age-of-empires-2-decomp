#include <cassert>
#include <iostream>
#include "kt_gs_render_249510.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00249510(dummy);
    assert(dummy[0] == 0xC0);
    std::cout << "kt_gs_render_249510 native test passed!" << std::endl;
    return 0;
}
