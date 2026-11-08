#include <cassert>
#include <iostream>
#include "kt_gs_render_249450.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00249450(dummy);
    assert(dummy[0] == 0xE4);
    std::cout << "kt_gs_render_249450 native test passed!" << std::endl;
    return 0;
}
