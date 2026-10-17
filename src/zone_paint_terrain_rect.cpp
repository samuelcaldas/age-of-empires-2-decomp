#pragma exceptions off

#include "zone_paint_terrain_rect.h"

extern "C" {
void func_314EA0(short *x0, short *y0, short *x1, short *y1, int min_x, int min_y, int max_x, int max_y);
void func_1CDF30(void *self, void *world, void *player, int y, int x, int terrain, int flag_delete_mode, int range_min, int range_max);
void func_1D1CC0(void *self, void *cell);
void func_1D00C0(void *self, int x, int y);
void func_1C9E00(void *self, int x0, int y0, int x1, int y1, int flag);
}

extern "C" void func_001CF9B0(
    void *self,
    void *world,
    void *player,
    short x0,
    short y0,
    short x1,
    short y1,
    int terrain_type,
    unsigned char flag
) {
    char *zm = (char *)self;
    int max_terrain = *(short *)(zm + 0x8EA8);
    unsigned char t_type = (unsigned char)terrain_type;
    if (t_type >= max_terrain) {
        return;
    }

    char *entry = zm + t_type * 416;
    if (*(unsigned char *)(entry + 0x8C) == 0) {
        short fallback = *(short *)(entry + 0x14C);
        if (fallback < 0) {
            return;
        }
        entry = zm + fallback * 416;
        if (*(unsigned char *)(entry + 0x8C) != 1) {
            return;
        }
        t_type = (unsigned char)fallback;
    }

    int width = *(int *)(zm + 0x8);
    int height = *(int *)(zm + 0xC);

    func_314EA0(&x0, &y0, &x1, &y1, 0, 0, width - 1, height - 1);

    if (flag == 0 && world == 0) {
        return;
    }

    char *cells_base = *(char **)(zm + 0x8E8C);

    for (short y = y0; y <= y1; y++) {
        for (short x = x0; x <= x1; x++) {
            char *cell = *(char **)(cells_base + y * 4) + x * 28;

            if (*(unsigned char *)(cell + 5) != t_type) {
                if (flag == 0) {
                    *(unsigned char *)(cell + 5) = (unsigned char)terrain_type;
                    if (world != 0) {
                        func_1CDF30(self, world, player, y, x, -1, 0, -1, -1);
                    }
                }
            }
        }
    }

    // Expand bounds by 1 tile
    if (y0 > 0) y0--;
    if (y1 < height - 1) y1++;
    if (x0 > 0) x0--;
    if (x1 < width - 1) x1++;

    for (short y = y0; y <= y1; y++) {
        for (short x = x0; x <= x1; x++) {
            char *cell = *(char **)(cells_base + y * 4) + x * 28;

            if (*(int *)(cell + 0x10) == 0) {
                func_1D1CC0(self, cell);
            }
            func_1D00C0(self, x, y);
        }
    }

    func_1C9E00(self, x0, y0, x1, y1, 0);
}
