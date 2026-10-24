#pragma exceptions off

#include "zone_spawn_terrain_objects.h"

extern "C" {
int func_1CF350(void *self, int x, int y);
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

extern "C" void func_001CE650(
    void *self,
    void *player,
    int a2,
    int y,
    int x,
    int t1,
    int flag_single_spawn
) {
    int terrain = (unsigned char)func_1CF350(self, x, y);

    char *table_entry = (char *)self + terrain * 416;
    short count = *(short *)(table_entry + 0x228);

    float center_x = (float)x + 0.5f;
    float center_y = (float)y + 0.5f;

    for (short obj_idx = 0; obj_idx < count; obj_idx++) {
        short obj_id = *(short *)(table_entry + 0x192 + obj_idx * 2);
        if (obj_id == -1) {
            continue;
        }

        short density = *(short *)(table_entry + 0x1CE + obj_idx * 2);
        unsigned char mode = *(unsigned char *)(table_entry + 0x20A + obj_idx);

        void *entity = ((void **)*(void **)((char *)player + 0x70))[obj_id];
        if (entity == 0) {
            continue;
        }

        if (flag_single_spawn == 0) {
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
        } else if (flag_single_spawn == 1) {
            float pos_x;
            float pos_y;

            if (mode == 1) {
                pos_x = center_x;
                pos_y = center_y;
            } else if (mode == 0) {
                pos_x = (float)x + (float)func_1AAB30() / 32767.0f;
                pos_y = (float)y + (float)func_1AAB30() / 32767.0f;
            }

            void *comp = *(void **)((char *)entity + 0xA0);
            void **comp_vtable = *(void ***)comp;

            int can_place = ((PlacementCheckFn)comp_vtable[15])(
                entity, player, 0, 0, 1, 0, 1, 0, pos_x, pos_y, 1, 0
            );

            if (can_place == 0) {
                ((PlaceEntityFn)comp_vtable[13])(entity, player, pos_x, pos_y, 0.0f);
            }
        }
    }
}
