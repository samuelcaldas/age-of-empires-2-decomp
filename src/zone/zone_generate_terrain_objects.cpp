#pragma exceptions off

#include "zone_generate_terrain_objects.h"

extern "C" {
int func_1CF350(void *self, int x, int y);
void func_1D09C0(void *self, void *cell, int index);
int func_1AAB30();
}

typedef int (*PlacementCheckFn)(
    void *entity,
    void *player,
    int a2,
    int a3,
    int t0,
    int t1,
    int t2,
    int t3,
    float pos_x,
    float pos_y,
    long long s0,
    long long s1
);

typedef void (*PlaceEntityFn)(
    void *entity,
    void *player,
    float pos_x,
    float pos_y,
    float z
);

typedef void (*DeleteEntityFn)(void *entity);

extern "C" void func_001CDF30(
    void *self,
    void *player,
    int a2,
    int y,
    int x,
    int filter_type,
    int flag_delete_mode,
    int range_min,
    int range_max
) {
    int terrain = (unsigned char)func_1CF350(self, x, y);

    char *table_entry = (char *)self + terrain * 416;
    short count = *(short *)(table_entry + 0x228);
    if (count <= 0) {
        return;
    }

    char *cells_base = *(char **)((char *)self + 0x8E8C);
    char *cell = *(char **)(cells_base + y * 4) + x * 28;

    void **items_list = *(void ***)(cell + 0x14);
    int num_items = *(unsigned char *)(cell + 0xD);

    short filter = (short)filter_type;
    char *filter_table_entry = (char *)self + filter * 416;

    for (int i = 0; i < num_items; i++) {
        void *item = items_list[i];
        void *item_info = *(void **)((char *)item + 0x4);
        void *item_player = *(void **)((char *)item + 0x8);

        if (item_player != player) {
            continue;
        }

        short val = *(short *)((char *)item_info + 0x8);
        if (val < range_min || val > range_max) {
            continue;
        }

        if (filter < 0) {
            if (flag_delete_mode == 0) {
                func_1D09C0(self, cell, i);
            } else {
                void **vtable = *(void ***)item;
                ((DeleteEntityFn)vtable[31])(item);
            }
            i--;
            num_items--;
        } else {
            short table_count = *(short *)(filter_table_entry + 0x228);
            int match_idx = table_count - 1;
            while (match_idx >= 0) {
                short table_id = *(short *)(filter_table_entry + 0x192 + match_idx * 2);
                if (table_id == val) {
                    break;
                }
                match_idx--;
            }
            if (match_idx < 0) {
                if (flag_delete_mode == 0) {
                    func_1D09C0(self, cell, i);
                } else {
                    void **vtable = *(void ***)item;
                    ((DeleteEntityFn)vtable[31])(item);
                }
                i--;
                num_items--;
            }
        }
    }

    float center_x = (float)x + 0.5f;
    float center_y = (float)y + 0.5f;

    for (short obj_idx = 0; obj_idx < count; obj_idx++) {
        short obj_id = *(short *)(table_entry + 0x192 + obj_idx * 2);
        if (obj_id == -1) {
            continue;
        }

        void *entity = ((void **)*(void **)((char *)player + 0x70))[obj_id];
        if (entity == 0) {
            continue;
        }

        unsigned char mode = *(unsigned char *)(table_entry + 0x20A + obj_idx);
        short density = *(short *)(table_entry + 0x1CE + obj_idx * 2);

        while (density > 0) {
            float pos_x;
            float pos_y;

            if (mode == 1) {
                pos_x = center_x;
                pos_y = center_y;
            } else if (mode == 0) {
                pos_x = (float)x + (float)func_1AAB30() / 32767.0f;
                pos_y = (float)y + (float)func_1AAB30() / 32767.0f;
            }

            if (density < 1000) {
                int rnd = (func_1AAB30() * 1000) / 32767;
                if (rnd >= density) {
                    break;
                }
            }

            void *comp = *(void **)((char *)entity + 0xA0);
            void **comp_vtable = *(void ***)comp;

            int can_place = ((PlacementCheckFn)comp_vtable[15])(
                entity, player, 0, 0, 1, 0, 1, 0, pos_x, pos_y, 1, 0
            );

            if (can_place == 0) {
                ((PlaceEntityFn)comp_vtable[13])(entity, player, pos_x, pos_y, 0.0f);
            }

            density -= 1000;
        }
    }
}
