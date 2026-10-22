#include "network_dplay_3380e0.h"

extern "C" {
    void func_339270(void);
    void func_100670(void *ptr);
}

extern "C" void *func_00338260(void *self, int delete_flag) {
    if (self != 0) {
        char *base = static_cast<char *>(self);
        func_339270();
        func_00338180(base);
        func_003381A0(base);
        *reinterpret_cast<int *>(base + 1308) = 0;
        short flag = static_cast<short>(delete_flag);
        if (flag > 0) {
            func_100670(base);
        }
    }
    return self;
}
