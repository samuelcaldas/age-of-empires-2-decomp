#pragma exceptions off

#include "zone_filter_cell_items.h"

extern "C" {
extern int D_004E34C0;
extern int D_004E34BC;
extern int D_004E33F4;

void func_326A80(void *a0, int a1, int a2);
void func_264A70(void *entity, void *a1, void *a2, void *a3);
}

typedef void (*RenderEntityFn)(void *entity, void *a1, void *a2, void *a3, int c68);

extern "C" void func_001D1150(
    void *self,
    void *cell,
    void *a2,
    void *a3,
    void *t0,
    void *t1,
    int filter_mode
) {
    unsigned char mode = (unsigned char)filter_mode;
    int i = 0;

    while (i < *(unsigned char *)((char *)cell + 0xD)) {
        void *entity = *(void **)(*(char **)((char *)cell + 0x14) + (i << 2));
        if (entity == 0) {
            i++;
            continue;
        }

        int s7 = 0;
        int s2 = 0;
        int s1 = 0;

        if (mode != 0xF) {
            void *info = *(void **)((char *)entity + 0x4);
            if (*(unsigned char *)info >= 50 && *(unsigned char *)((char *)entity + 0xC6) != 0) {
                int flags = *(int *)((char *)entity + 0xF4);
                if ((flags & D_004E34C0) != 0) {
                    s2 = 1;
                    s1 = s2;
                } else if ((flags & D_004E34BC) != 0) {
                    s7 = 1;
                    s1 = s7;
                }
            }
        }

        void *info = *(void **)((char *)entity + 0x4);
        if (*(short *)((char *)info + 0xE) == 0x22) {
            s2 = 1;
            s1 = s2;
        }

        unsigned char b57 = *(unsigned char *)((char *)info + 0x57);
        void *player = *(void **)((char *)entity + 0x8);
        if (s1 != 0 && mode == 0) {
            func_326A80(t1, 0, 0x28);
        }

        if ((mode == 0xF || s2 != 0) && b57 != 3) {
            int saved_global = 0;
            if (mode != 0xF) {
                saved_global = D_004E33F4;
                D_004E33F4 = 0;
            }
            void **vtable = *(void ***)entity;
            ((RenderEntityFn)vtable[6])(
                entity, a2, a3, t0, *(int *)((char *)player + 0xC68));
            if (mode != 0xF) {
                D_004E33F4 = saved_global;
            }
        } else if (mode == 0x80 || s7 != 0) {
            if (b57 == 3) {
                void *world = *(void **)((char *)player + 0xB98);
                int player_index = *(int *)((char *)player + 0xBA0);
                short world_player_index = *(short *)((char *)world + 0x98);
                void *world_player = ((void **)*(void **)((char *)world + 0x54))[
                    world_player_index];
                if (*(int *)((char *)world_player + player_index * 4 + 0xC00) != 0) {
                    void **vtable = *(void ***)entity;
                    ((RenderEntityFn)vtable[6])(
                        entity, a2, a3, t0, *(int *)((char *)entity + 0x70));
                }
            } else if (b57 != 0) {
                void **vtable = *(void ***)entity;
                ((RenderEntityFn)vtable[6])(
                    entity, a2, a3, t0, *(int *)((char *)player + 0xC68));
            } else if (*(unsigned char *)((char *)entity + 0x36) != 0) {
                func_264A70(entity, a2, a3, t0);
            }
        }

        if (s1 != 0 && mode == 0) {
            func_326A80(t1, 0, 5);
        }
        i++;
    }
}
