#pragma exceptions off

#include "zone_update_elevation_rect.h"

extern "C" {
void func_314EA0(short *x0, short *y0, short *x1, short *y1, int min_x, int min_y, int max_x, int max_y);
void func_1D1CC0(void *self, void *cell);
unsigned char func_1CFCD0(void *self, int x, int y);
void func_2082B0(void *map_comp, int x, int y);
void func_1C9FA0(void *self, int x0, int y0, int x1, int y1);
void func_1C9E00(void *self, int x0, int y0, int x1, int y1, int flag);
}

typedef void (*UpdateEntityElevationFn)(void *entity, float pos_x, float pos_y, float z);

extern "C" void func_001CF3E0(
    void *self,
    short x0,
    short y0,
    short x1,
    short y1,
    int delta_elev,
    int param6,
    int param7
) {
    char *zm = (char *)self;
    char *world = *(char **)(zm + 0x8EE8);

    void **player_list = *(void ***)(world + 0x54);
    void *player = 0;
    if (player_list != 0) {
        short player_id = *(short *)(world + 0x98);
        player = player_list[player_id];
    }

    int width = *(int *)(zm + 0x8);
    int height = *(int *)(zm + 0xC);

    func_314EA0(&x0, &y0, &x1, &y1, 0, 0, width - 1, height - 1);

    char *cells_base = *(char **)(zm + 0x8E8C);

    for (short y = y0; y <= y1; y++) {
        for (short x = x0; x <= x1; x++) {
            char *cell = *(char **)(cells_base + y * 4) + x * 28;

            if (*(int *)(cell + 0x10) != 0) {
                func_1D1CC0(self, cell);
            }

            int elev = (int)*(unsigned char *)(cell + 0x6) + (short)param6;
            if (elev < 0) {
                elev = 0;
            }
            if (elev > 8) {
                elev = 8;
            }
            *(unsigned char *)(cell + 0x6) = (unsigned char)elev;
        }
    }

    if (y0 > 0) y0--;
    if (y1 < height - 1) y1++;
    if (x0 > 0) x0--;
    if (x1 < width - 1) x1++;

    for (short y = y0; y <= y1; y++) {
        for (short x = x0; x <= x1; x++) {
            char *cell = *(char **)(cells_base + y * 4) + x * 28;

            if (*(int *)(cell + 0x10) != 0) {
                func_1D1CC0(self, cell);
            }

            unsigned char slope = func_1CFCD0(self, x, y);
            *(unsigned char *)(cell + 0x4) = slope;

            int num_items = *(unsigned char *)(cell + 0xD);
            if (num_items > 0) {
                void **items_list = *(void ***)(cell + 0x14);
                for (int i = 0; i < num_items; i++) {
                    void *entity = items_list[i];
                    void **vtable = *(void ***)entity;
                    float pos_x = *(float *)((char *)entity + 0x44);
                    float pos_y = *(float *)((char *)entity + 0x48);

                    ((UpdateEntityElevationFn)vtable[17])(entity, pos_x, pos_y, 0.0f);
                }
            }

            if (*(unsigned char *)(world + 0x31) != 3) {
                if (player != 0) {
                    char *vis_comp = (char *)((void **)*(void **)(world + 0x54))[1] + 0xBC4;
                    func_2082B0(vis_comp, x, y);
                }
            }
        }
    }

    func_1C9FA0(self, x0, y0, x1, y1);
    func_1C9E00(self, x0, y0, x1, y1, 0);
}
