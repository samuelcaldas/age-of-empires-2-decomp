#pragma exceptions off

#include "zone_set_tile_terrain.h"

extern "C" {
void func_1D1CC0(void *self, void *cell);
void func_1C9E00(void *self, int x0, int y0, int x1, int y1, int flag);
void func_2082B0(void *map_comp, int x, int y);
int func_001CE3B0(void *self, void *a1, int y, int x, int filter_type, int flag_delete_mode, int range_min, int range_max);
void func_001CE650(void *self, void *player, int a2, int y, int x, int t1, int flag_single_spawn);
void func_1D00C0(void *self, int x, int y);
}

extern "C" void func_001CF830(
    void *self,
    void *world,
    int x,
    int y,
    int terrain,
    int param6,
    int param7
) {
    char *zm = (char *)self;
    char *cells_base = *(char **)(zm + 0x8E8C);
    char *cell = *(char **)(cells_base + y * 4) + x * 28;

    void *player = *(void **)(*(char **)((char *)world + 0x54));

    unsigned char old_terrain = *(unsigned char *)(cell + 5);
    if ((int)old_terrain == (unsigned char)terrain) {
        return;
    }

    *(unsigned char *)(cell + 5) = (unsigned char)terrain;

    if (*(int *)(cell + 0x10) != 0) {
        func_1D1CC0(self, cell);
    }

    if (player == 0) {
        return;
    }

    func_1C9E00(self, x, y, x, y, 0);

    if (*(unsigned char *)((char *)world + 0x31) != 3) {
        char *vis_comp = (char *)((void **)*(void **)((char *)world + 0x54))[1] + 0xBC4;
        func_2082B0(vis_comp, x, y);
    }

    int res = func_001CE3B0(self, world, y, x, (int)old_terrain, 1, param6, param7);
    func_001CE650(self, player, (int)old_terrain, y, x, res, 0);
    func_1D00C0(self, x, y);
}
