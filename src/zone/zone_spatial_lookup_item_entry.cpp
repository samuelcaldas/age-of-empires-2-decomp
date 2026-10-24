#pragma exceptions off

#include "zone_spatial_lookup_item_entry.h"

extern "C" {
void func_1D7CE0(void *self, void *item, int flag);
}

extern "C" void func_001D7CA0(void *self, void *item) {
    if (item != 0) {
        char *i = (char *)item;
        char *zm = (char *)self;
        char *a2 = *(char **)(zm + 0x8);
        short v1 = *(short *)(i + 0x58);
        void **v0 = *(void ***)(a2 + 0x68);
        void *target_item = v0[v1];
        short flag = *(short *)(a2 + 0x66);
        func_1D7CE0(self, target_item, flag);
    }
}
