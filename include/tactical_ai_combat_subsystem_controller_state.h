#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_STATE_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_STATE_H

struct SystemManager {
    char pad00[0x1C8];
    int m_mode;
    int m_field_1CC;
};

extern SystemManager *D_004E3180;

struct ViewVtable {
    char pad00[0x28];
    void (*func_28)(void *self, int a1);
};

struct CombatSubsystemControllerInstance {
    ViewVtable *m_vtable;
};

extern "C" {
    int func_00329FA0(CombatSubsystemControllerInstance *self);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_STATE_H
