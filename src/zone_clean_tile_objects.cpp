#pragma exceptions off

#include "zone_clean_tile_objects.h"

extern "C" {
int func_1CF350(void *self, int x, int y);
void func_1D09C0(void *self, void *cell, int index);
}

typedef int (*PlacementCheckFn)(
    void *item_info,
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
    long long s1,
    long long s2,
    long long s3
);

typedef void (*DeleteEntityFn)(void *item);

extern "C" int func_001CE3B0(
    void *self,
    void *a1,
    int y,
    int x,
    int filter_type,
    int flag_delete_mode,
    int range_min,
    int range_max
) {
    int result = -1;

    func_1CF350(self, x, y);

    char *cells_base = *(char **)((char *)self + 0x8E8C);
    char *cell = *(char **)(cells_base + y * 4) + x * 28;

    void **items_list = *(void ***)(cell + 0x14);
    int num_items = *(unsigned char *)(cell + 0xD);
    if (num_items <= 0) {
        return result;
    }

    short filter = (short)filter_type;
    char *filter_table_entry = (char *)self + filter * 416;

    for (int i = 0; i < num_items; i++) {
        void *item = items_list[i];
        void *item_info = *(void **)((char *)item + 0x4);

        short val = *(short *)((char *)item_info + 0x8);
        if (val < range_min || val > range_max) {
            continue;
        }

        result = val;

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
            } else {
                void *comp = *(void **)((char *)item_info + 0xA0);
                void **comp_vtable = *(void ***)comp;
                void *item_player = *(void **)((char *)item + 0x8);
                float pos_x = *(float *)((char *)item + 0x44);
                float pos_y = *(float *)((char *)item + 0x48);

                int placement_err = ((PlacementCheckFn)comp_vtable[15])(
                    item_info, item_player, 0, 0, 1, 1, 1, 0, pos_x, pos_y, 0, 0, 0, 0
                );

                if (placement_err != 0) {
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
    }

    return result;
}
