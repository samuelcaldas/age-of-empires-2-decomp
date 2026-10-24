#pragma exceptions off

#include "zone_reset_bucket_counters.h"

extern "C" void func_001D0EE0(void *self, void *bucket) {
    char *b = (char *)bucket;
    *(int *)(b + 0x34) = 0;
    *(int *)(b + 0x38) = 0;
    *(int *)(b + 0x3C) = 0;
    *(int *)(b + 0x40) = 0;
}
