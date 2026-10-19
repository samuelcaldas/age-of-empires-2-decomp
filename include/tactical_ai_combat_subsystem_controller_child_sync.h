#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_CHILD_SYNC_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_CHILD_SYNC_H

struct ViewVtable {
    char pad00[0x28];
    void (*func_28)(void *self, int a1);
};

struct ViewObj {
    ViewVtable *m_vtable;
};

struct CombatSubsystemControllerInstance {
    char pad00[0x3408];
    ViewObj *m_view;
};

extern "C" {
    int func_00323B50(CombatSubsystemControllerInstance *self);
    int func_0032C420(CombatSubsystemControllerInstance *self);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_CHILD_SYNC_H
