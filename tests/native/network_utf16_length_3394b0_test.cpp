#include <cassert>
#include "network_utf16_length_3394b0.h"

int main() {
    const unsigned short empty[] = {0};
    const unsigned short one[] = {'A', 0};
    const unsigned short several[] = {'S', 'E', 'S', 'S', 'I', 'O', 'N', 0};
    assert(func_003394B0(empty) == 0);
    assert(func_003394B0(one) == 1);
    assert(func_003394B0(several) == 7);
    return 0;
}
