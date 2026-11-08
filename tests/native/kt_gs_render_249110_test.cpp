#include <cassert>
#include <iostream>
#include "kt_gs_render_249110.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00249110(dummy);
    assert(dummy[0] == 0xFF);
    std::cout << "kt_gs_render_249110 native test passed!" << std::endl;
    return 0;
}
