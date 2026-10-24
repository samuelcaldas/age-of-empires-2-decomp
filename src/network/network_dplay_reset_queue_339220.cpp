#include "network_dplay_3380e0.h"

extern "C" {
    void func_117CAC(void *dst, int val, int size);
}

extern "C" int func_00339220(void *self) {
    char *base = static_cast<char *>(self);
    func_117CAC(base + 1324, 0, 2048);
    int *fields = static_cast<int *>(self);
    fields[843] = 0;
    fields[844] = 0;
    fields[846] = 0;
    fields[845] = 0;
    return 0;
}
