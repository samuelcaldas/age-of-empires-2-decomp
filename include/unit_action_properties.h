#ifndef UNIT_ACTION_PROPERTIES_H
#define UNIT_ACTION_PROPERTIES_H

#include "unit_action_targets.h"

typedef void (*Method7CFn)(void *world, short arg1, int a2, float f0);

struct WorldSub1B30Props {
    char pad_00[124];
    Method7CFn Method7C;
    char pad_7C[272 - 128];
    Method110Fn Method110;
    Method114Fn Method114;
};

struct WorldProps {
    char pad_00[0x70];
    void **m_entities;
    char pad_74[0xBA0 - 0x74];
    void *m_fieldBA0;
    char pad_BA4[0x1B30 - 0xBA4];
    WorldSub1B30Props *m_field1B30;
};

extern "C" {
    int func_123350(float val);

    void func_00267750(ActionExtended *self, int prop_id, float val);
    void func_002678A0(ActionExtended *self, int prop_id, float val);
    void func_002679A0(ActionExtended *self, int prop_id, float val);
}

#endif // UNIT_ACTION_PROPERTIES_H
