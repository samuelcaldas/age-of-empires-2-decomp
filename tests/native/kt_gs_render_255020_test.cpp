#include <cassert>
#include "kt_gs_render_255020.h"

int main() {
    int dummy = 1;
    assert(func_00255020(&dummy, 5) == 105);
    assert(func_00255020(nullptr, 5) == 0);
    return 0;
}
