#include <cassert>
#include <iostream>
#include "kt_gs_render_248d10.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00248D10(dummy);
    assert(dummy[0] == 0x80);
    std::cout << "kt_gs_render_248d10 native test passed!" << std::endl;
    return 0;
}
