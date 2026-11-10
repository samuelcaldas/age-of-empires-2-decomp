#pragma exceptions off
#include "sub_list.h"

class TargetObj {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual void vfn64();
    virtual void vfn65();
    virtual void vfn66();
    virtual void vfn67();
    virtual void vfn68();
    virtual void vfn69();
    virtual void vfn70();
    virtual void vfn71();
    virtual void vfn72();
    virtual void vfn73();
    virtual void vfn74();
    virtual void vfn75();
    virtual void vfn76();
    virtual void vfn77();
    virtual void vfn78();
    virtual void vfn79();
    virtual void vfn80();
    virtual void vfn81();
    virtual void vfn82();
    virtual void vfn83();
    virtual void vfn84();
    virtual void vfn85();
    virtual void vfn86();
    virtual void vfn87();
    virtual void vfn88();
    virtual void vfn89();
    virtual void vfn90();
    virtual void vfn91();
    virtual void vfn92();
    virtual void vfn94();
    virtual int Method17C(float x, float y, int a3, int a4, float z, float f4); // index 95 -> offset 0x17C
    virtual void vfn95();
    virtual void vfn96();
    virtual void vfn97();
    virtual void vfn98();
    virtual void vfn99();
    virtual void vfn100();
    virtual void vfn101();
    virtual void vfn102();
    virtual void vfn103();
    virtual void vfn104();
    virtual void vfn105();
    virtual void vfn106();
    virtual int Method1B4(int *pos, int a2, int a3, int a4, int a5, int a6); // index 107 -> offset 436

    char pad_04[0x4];
    void *m_world;
};

struct TradeAction {
    char pad_00[0x38];
    TargetObj *m_target;
    char pad_3C[0x0C];
    short m_field48;
};

extern "C" {
int func_123350(float val);
float func_269190(TargetObj *t, float x, float y, float z);
short func_001471B0(TradeAction *self, short cmd);
int func_0014BD20(TradeAction *self, int a1, float x, float y, float z);

int func_0014AEF0(TradeAction *self, short target_id, int flag, float x, float y, float z) {
    if (!flag && self->m_field48 != -1) {
        return 0;
    }

    if (x < 0.0f) {
        x = 0.0f;
    } else {
        void *world = self->m_target->m_world;
        void *mgr = *(void **)((char *)world + 2968);
        void *map = *(void **)((char *)mgr + 60);
        int map_w = *(int *)((char *)map + 8);
        if (!(x < (float)map_w)) {
            x = (float)map_w - 1.0f;
        }
    }

    if (y < 0.0f) {
        y = 0.0f;
    } else {
        void *world = self->m_target->m_world;
        void *mgr = *(void **)((char *)world + 2968);
        void *map = *(void **)((char *)mgr + 60);
        int map_h = *(int *)((char *)map + 12);
        if (!(y < (float)map_h)) {
            y = (float)map_h - 1.0f;
        }
    }

    int tile_coords[3];
    int *py = &tile_coords[1];
    tile_coords[0] = func_123350(x);
    *py = func_123350(y);
    tile_coords[2] = func_123350(*(float *)((char *)self->m_target + 76));

    if (self->m_target->Method1B4(tile_coords, -1, 0, -1, -1, 0)) {
        goto L_passable;
    }

    {
        int i = -1;
        float orig_dist = func_269190(self->m_target, x, y, *(float *)((char *)self->m_target + 76));
        goto L_loop_inc;
        while (1) {
            switch (i) {
            case 0: tile_coords[0] -= 2; *py -= 2; break;
            case 1: tile_coords[0] += 2; break;
            case 2: tile_coords[0] += 2; break;
            case 3: *py += 2; break;
            case 4: *py += 2; break;
            case 5: tile_coords[0] -= 2; break;
            case 6: tile_coords[0] -= 2; break;
            case 7: *py -= 2; break;
            }

            if (tile_coords[0] < 0) {
                tile_coords[0] = 0;
            } else {
                void *world = self->m_target->m_world;
                void *mgr = *(void **)((char *)world + 2968);
                void *map = *(void **)((char *)mgr + 60);
                int map_w = *(int *)((char *)map + 8);
                if (tile_coords[0] >= map_w) {
                    tile_coords[0] = map_w - 1;
                }
            }

            if (*py < 0) {
                *py = 0;
            } else {
                void *world = self->m_target->m_world;
                void *mgr = *(void **)((char *)world + 2968);
                void *map = *(void **)((char *)mgr + 60);
                int map_h = *(int *)((char *)map + 12);
                if (*py >= map_h) {
                    *py = map_h - 1;
                }
            }

            if (target_id == 0) {
                float dist = func_269190(self->m_target, (float)tile_coords[0] + 0.5f, (float)*py + 0.5f, *(float *)((char *)self->m_target + 76));
                if (dist < orig_dist) {
                    goto L_check_pass;
                }
                goto L_loop_inc;
            }
        L_check_pass:
            if (self->m_target->Method1B4(tile_coords, -1, 0, -1, -1, 0) == 1) {
                goto L_passable;
            }
        L_loop_inc:
            i++;
            if (i >= 8) break;
        }
        return 0;
    }

L_passable:
    if (self->m_target->Method17C((float)tile_coords[0] + 0.5f, (float)*py + 0.5f, flag, 0, z, 0.0f) == 1) {
        func_001471B0(self, 610);
        func_0014BD20(self, -1, x, y, z);
        return 1;
    }
    return 0;
}

int func_0014B300(void *self) {
    return 0;
}

}
