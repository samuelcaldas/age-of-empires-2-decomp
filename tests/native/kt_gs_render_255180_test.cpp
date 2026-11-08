#include <cassert>
#include "kt_gs_render_255180.h"

int main() {
    int dummy = 1;
    assert(func_00255180(&dummy, 5) == 40);
    assert(func_00255180(nullptr, 5) == 0);
    return 0;
}
