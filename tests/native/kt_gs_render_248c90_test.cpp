#include <cassert>
#include <iostream>
#include "kt_gs_render_248c90.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00248C90(dummy);
    assert(dummy[0] == 0xF0);
    std::cout << "kt_gs_render_248c90 native test passed!" << std::endl;
    return 0;
}
