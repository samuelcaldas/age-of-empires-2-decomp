#include <cassert>
#include <iostream>
#include "kt_gs_render_248520.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00248520(dummy);
    assert(dummy[0] == 0xB0);
    std::cout << "kt_gs_render_248520 native test passed!" << std::endl;
    return 0;
}
