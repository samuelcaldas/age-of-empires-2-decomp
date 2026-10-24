#include "network_dplay_3380e0.h"

extern "C" {
    void func_117CAC(void *dst, int val, int size);
}

extern "C" void func_003381A0(void *self) {
    char *base = static_cast<char *>(self);
    func_117CAC(base + 4, 0, 1088);
    func_117CAC(base + 1092, 0, 216);
    func_117CAC(base + 1324, 0, 2048);
    base[4412] = 0;
    *reinterpret_cast<int *>(base + 4540) = 0;
    *reinterpret_cast<int *>(base + 4544) = 0;
    *reinterpret_cast<int *>(base + 1312) = 0;
    *reinterpret_cast<int *>(base + 0) = 0;
    *reinterpret_cast<int *>(base + 3372) = 0;
    *reinterpret_cast<int *>(base + 4552) = 0;
    *reinterpret_cast<int *>(base + 1316) = 1;
    base[4560] = 0;
    *reinterpret_cast<int *>(base + 3376) = 0;
    *reinterpret_cast<int *>(base + 3384) = 0;
    *reinterpret_cast<int *>(base + 3380) = 0;
    *reinterpret_cast<int *>(base + 4556) = 0;
    func_00338180(base);
}
