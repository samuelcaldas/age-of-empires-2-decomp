#include <cassert>
#include <iostream>
#include "kt_gs_render_249140.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00249140(dummy);
    assert(dummy[0] == 0x70);
    std::cout << "kt_gs_render_249140 native test passed!" << std::endl;
    return 0;
}
