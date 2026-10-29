#pragma exceptions off

#include "zone_check_tile_has_attr.h"

extern "C" int func_001D5A30(void *self, int x, int y) {
    char *zm = (char *)self;
    if (x < 0 || !(x < *(int *)(zm + 0xE4)) || y < 0 || !(y < *(int *)(zm + 0xE8))) {
        return 0;
    }

    char **rows = *(char ***)(zm + 0x98);
    int x_offset = (x * 7) << 2;
    char *cell = rows[y] + x_offset;

    unsigned char count = *(unsigned char *)(cell + 0xD);
    if (!count) {
        return 0;
    }

    int i = 0;
    while (i < (int)count) {
        void **items = *(void ***)(rows[y] + x_offset + 0x14);
        char *item = (char *)items[i];
        char *info = *(char **)(item + 4);
        short attr = *(short *)(info + 0xE);
        if (attr == 8 || attr == 0x20) {
            return 1;
        }
        i++;
    }

    return 0;
}
