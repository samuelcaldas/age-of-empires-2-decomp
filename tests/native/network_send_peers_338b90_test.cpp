#include <cassert>
#include "network_send_peers_338b90.h"
static int calls;
static int last_length;
extern "C" int func_003383B0(void *, const void *, int, const void *, int size) {
    ++calls;
    last_length = size;
    return 0;
}
int main() {
    unsigned char object[5000] = {};
    *(int *)object = 1;
    for (int slot = 0; slot < 8; ++slot) {
        *(int *)(object + 4 + slot * 136 + 4) = slot + 1;
    }
    calls = 0;
    assert(func_00338B90(object, 0, 4, 0, 12, 0) == 0);
    assert(calls == 7 && last_length == 12);
    calls = 0;
    assert(func_00338B90(object, 0, 4, 0, 12, 6) == 0);
    assert(calls == 1);
}
