#include <cassert>
#include <iostream>
#include "kt_gs_render_246bd0.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00246BD0(dummy);
    assert(dummy[0] == 0x08);
    std::cout << "kt_gs_render_246bd0 native test passed!" << std::endl;
    return 0;
}
