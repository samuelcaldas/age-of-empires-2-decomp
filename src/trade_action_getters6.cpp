#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_002B61F0(void *self, int index) {
    if (index < 0 || index >= 239) {
        return -1;
    }
    return *reinterpret_cast<int *>(static_cast<char *>(self) + 0x858 + index * 4);
}
}
