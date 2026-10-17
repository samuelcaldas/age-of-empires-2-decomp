#pragma exceptions off

#include "zone_get_tile_terrain.h"

extern "C" int func_001CF350(void *self, int x, int y) {
    char *cells_base = *(char **)((char *)self + 0x8E8C);
    char *cell = *(char **)(cells_base + y * 4) + x * 28;

    unsigned char terrain = *(unsigned char *)(cell + 5);
    if (terrain >= 33) {
        return 0;
    }

    char *entry = (char *)self + terrain * 416;
    if (*(unsigned char *)(entry + 0x8C) != 0) {
        return terrain;
    }

    if (*(short *)(entry + 0x14C) >= 0) {
        return terrain;
    }

    return 0;
}
