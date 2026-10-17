#pragma exceptions off

#include "zone_check_tile_has_attr.h"

extern "C" int func_001D5A30(void *self, int x, int y) {
    char *zm = (char *)self;
    if (x < 0) {
        return 0;
    }
    int max_x = *(int *)(zm + 0xE4);
    if (x >= max_x) {
        return 0;
    }
    if (y < 0) {
        return 0;
    }
    int max_y = *(int *)(zm + 0xE8);
    if (y >= max_y) {
        return 0;
    }

    char **rows = *(char ***)(zm + 0x98);
    char *cell = rows[y] + x * 28;

    unsigned char count = *(unsigned char *)(cell + 0xD);
    if (count == 0) {
        return 0;
    }

    void **items = *(void ***)(cell + 0x14);
    for (int i = 0; i < (int)count; i++) {
        char *item = (char *)items[i];
        char *info = *(char **)(item + 4);
        short attr = *(short *)(info + 0xE);
        if (attr == 8 || attr == 0x20) {
            return 1;
        }
    }

    return 0;
}
