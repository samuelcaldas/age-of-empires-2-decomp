#include "zone_path_eval.h"

int func_001C7850(void *self, void *arg1, int arg2, int arg3) {
    (void)self;
    (void)arg1;
    // ELF analysis indicates arg2 and arg3 participate in coordinate/bounds evaluation
    if (arg2 < 0 || arg3 < 0) {
        return -2;
    }
    return 0;
}
