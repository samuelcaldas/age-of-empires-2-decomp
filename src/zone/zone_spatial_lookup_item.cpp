#pragma exceptions off

#include "zone_spatial_lookup_item.h"

extern "C" {
int func_1D7BF0(void *self, void *item, int flag);
}

extern "C" int func_001D7BB0(void *self, void *item) {
    if (item == 0) {
        return 0;
    }

    char *i = (char *)item;
    char *zm = (char *)self;
    char *a2 = *(char **)(zm + 0x8);

    short v1 = *(short *)(i + 0x58);
    void **v0 = *(void ***)(a2 + 0x68);
    void *target_item = v0[v1];
    short flag = *(short *)(a2 + 0x66);

    return func_1D7BF0(self, target_item, flag);
}
