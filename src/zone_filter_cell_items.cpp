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
    char *c = (char *)cell;
    int num_items = *(unsigned char *)(c + 0xD);
    void **items_list = *(void ***)(c + 0x14);

    unsigned char f_mode = (unsigned char)filter_mode;

    for (int i = 0; i < num_items; i++) {
        void *entity = items_list[i];
        if (entity == 0) {
            continue;
        }

        int s7 = 0;
        int s2 = 0;
        int s1 = 0;

        if (f_mode != 0xF) {
            void *info = *(void **)((char *)entity + 0x4);
            unsigned char info_type = *(unsigned char *)info;
            if (info_type < 50) {
                // skip
            } else if (*(unsigned char *)((char *)entity + 0xC6) != 0) {
                int flags = *(int *)((char *)entity + 0xF4);
                if ((flags & D_004E34C0) != 0) {
                    s2 = 1;
                    s1 = s2;
                } else if ((flags & D_004E34BC) != 0) {
                    s7 = 1;
                    s1 = s7;
                }

                if (*(short *)((char *)info + 0xE) == 0x22) {
                    s2 = 1;
                    s1 = s2;
                }

                unsigned char b57 = *(unsigned char *)((char *)info + 0x57);
                void *player = *(void **)((char *)entity + 0x8);

                if (s1 != 0 && f_mode == 0) {
                    func_326A80(t1, 0, 0x28);
                }

                if (f_mode == 0xF || s2 != 0) {
                    if (b57 == 3) {
                        void *world = *(void **)((char *)player + 0xB98);
                        int p_idx = *(int *)((char *)player + 0xBA0);
                        short p_id = *(short *)((char *)world + 0x98);
                        void *p = ((void **)*(void **)((char *)world + 0x54))[p_id];
                        if (*(int *)((char *)p + p_idx * 4 + 0xC00) != 0) {
                            void **vtable = *(void ***)entity;
                            ((RenderEntityFn)vtable[6])(entity, a2, a3, t0, *(int *)((char *)player + 0xC68));
                        }
                    } else {
                        void **vtable = *(void ***)entity;
                        ((RenderEntityFn)vtable[6])(entity, a2, a3, t0, *(int *)((char *)player + 0xC68));
                    }
                }
            }
        }
    }
}
