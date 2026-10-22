#include "network_object_lifecycle_3380e0.h"
extern "C" {
extern const char D_00492C50[];
extern const char D_004D20F0[];
}
int func_00338140(void *callback, void *unused) {
    typedef int (*Callback)(const char *, const char *, int, int);
    (void)unused;
    ((Callback)callback)(D_00492C50, D_004D20F0, 6, 0);
    return 0;
}
