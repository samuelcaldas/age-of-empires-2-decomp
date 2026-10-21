#include <cassert>
#include <cstring>
#include "network_receive_data_338a20.h"

int D_004E3564 = 3;
extern "C" int func_104D60(int) { return 0; }
extern "C" int func_104D40(int) { return 0; }
extern "C" int func_117AF8(void *destination, const void *source, int size) {
    return (int)(long)std::memcpy(destination, source, size);
}
int main() {
    unsigned char object[5000] = {};
    unsigned char payload[8] = {};
    int player = 0, type = 0, size = 0;
    int *entry = (int *)(object + 1324);
    entry[0] = 5; entry[1] = 7; entry[3] = 3;
    std::memcpy(entry + 4, "abc", 3);
    *(int *)(object + 3372) = 1;
    assert(func_00338A20(object, &player, &type, payload, &size, 1) == 0);
    assert(player == 7 && type == 5 && size == 3);
    assert(std::memcmp(payload, "abc", 3) == 0);
    assert(*(int *)(object + 3372) == 0 && *(int *)(object + 3376) == 20);
    assert(func_00338A20(object, &player, &type, payload, &size, 1) == (int)0x887700BE);
}
