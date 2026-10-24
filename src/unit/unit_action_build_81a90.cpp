#pragma exceptions off
#include "unit_action_build_81a90.h"

extern "C" {
extern int D_4E3414;
extern void *D_4E3420;
extern void *D_4E3424;
extern void *D_4E3428;

int func_00298880(void *mgr, int id);
int func_00203010(void *mgr, int id);
int func_002E01E0(void *owner, short proto_id, int arg2, int arg3, int arg4, int arg5, float ratio);
int func_00297C20(void *mgr, int id);
int func_00298100(void *mgr, int id);
void func_00284720(void *mgr, int id, int zero);
}

void func_00281A90(int building_id) {
    if (!D_4E3414) {
        D_4E3414 = 1;

        if (building_id == 72) return;
        if (building_id == 117) return;
        if (building_id == 155) return;
        if (building_id == 487) return;
        if (building_id == -399) return;

        int v = (building_id < -397);
        if (v) v = (building_id < -399) ^ 1;
        if ((unsigned char)v) {
            building_id = func_00298880(D_4E3428, building_id);
            if (building_id == -1) {
                return;
            }
        } else {
            if (!func_00203010(D_4E3420, building_id)) {
                return;
            }
        }

        if (!func_002E01E0(D_4E3420, (short)building_id, 0, 1, 1, 1, 1.0f)) {
            return;
        }
    }

    int id = func_00297C20(D_4E3428, building_id);
    if (id == -1) {
        return;
    }

    building_id = func_00298100(D_4E3428, id);
    func_00284720(D_4E3424, building_id, 0);
}

void func_281A90(int building_id) {
    func_00281A90(building_id);
}
