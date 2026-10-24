#pragma exceptions off
#include "unit_action_build_worker_add.h"

struct MasterHelper {
    unsigned char m_class;
    char pad_01[13];
    short m_type;
};

struct TargetHelper {
    char pad_00[4];
    MasterHelper *m_master;
    char pad_08[280 - 8];
    unsigned char m_flag118;
};

struct WorldHelper {
    char pad_00[2981];
    unsigned char m_flagBA5;
    char pad_BA6[6];
    void *m_nodeBAC;
};

struct ActionHelper {
    char pad_00[8];
    WorldHelper *m_world;
    char pad_0C[364 - 12];
    short m_worker_count;
    short m_building_count;
};

void func_0026F430(ActionRebind *self, void *target) {
    func_278D50(self, target);

    TargetHelper *t = (TargetHelper*)target;
    ActionHelper *a = (ActionHelper*)self;

    if (t->m_master->m_class == 70) {
        if (t->m_flag118 != 0) {
            a->m_building_count++;
        }
    }

    if (t->m_master->m_type == 42) {
        if (a->m_world->m_flagBA5 != 0) {
            a->m_worker_count++;
            void *node = a->m_world->m_nodeBAC;
            *(float*)((char*)node + 28) += 1.0f;
        }
    }
}
