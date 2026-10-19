#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PULSE_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PULSE_H

struct SystemManager {};

extern SystemManager *D_004E3180;

struct ViewVtable {
    char pad00[0x28];
    void (*func_28)(void *self, int a1);
};

struct ViewObj {
    ViewVtable *m_vtable;
};

struct CombatSubsystemControllerInstance {
    char pad00[0x190];
    unsigned char m_field_190;
    char pad191[0x3408 - 0x191];
    ViewObj *m_view;
    char pad340C[0x341C - 0x340C];
    int m_field_341C;
    int m_field_3420;
    int m_field_3424;
};

extern "C" {
    int func_00323860(CombatSubsystemControllerInstance *self);
    int func_1880D0(SystemManager *mgr);
    int func_184C10(SystemManager *mgr);
    int func_184BD0(SystemManager *mgr, int a1);
    int func_185DC0(SystemManager *mgr);
    void func_185F00(SystemManager *mgr, int a1, int a2);
    int func_0032C320(CombatSubsystemControllerInstance *self);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PULSE_H
