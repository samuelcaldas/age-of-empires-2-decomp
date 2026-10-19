#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_FORMATION_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_FORMATION_H

struct SystemManagerVtable {
    char pad00[0x18];
    void (*func_18)(void *self, int a1, int a2);
};

struct SystemManager {
    SystemManagerVtable *m_vtable;
    char pad04[0x1C8 - 0x04];
    int m_mode;
    int m_field_1CC;
};

extern int D_004E2EA0;
extern SystemManager *D_004E3180;

struct TargetVtable {
    char pad00[0x28];
    void (*func_28)(void *self, int a1);
};

struct TargetObj {
    TargetVtable *m_vtable;
};

struct ViewVtable {
    char pad00[0x48];
    void (*func_48)(void *self, int a1, int a2);
    void (*func_4C)(void *self, int a1, int a2);
};

struct ViewObj {
    ViewVtable *m_vtable;
};

struct CombatSubsystemVtable {};

struct CombatSubsystemControllerInstance {
    CombatSubsystemVtable *m_vtable;
    char pad04[0x12C - 0x04];
    void *m_field_12C;
    TargetObj *m_target;
    char pad134[0x3408 - 0x134];
    ViewObj *m_view;
};

extern "C" {
    int func_0032D400(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0, void *buf, void *target_sub, int flag);
    void func_0032E580(CombatSubsystemControllerInstance *self, void *buf);
    int func_186010(SystemManager *mgr, int a1);
    void func_1AAB30(void *a0, int a1);
    void func_26A680(void *a0);
    void func_1830E0(void *a0, int a1);
    void func_262FA0(void *a0);
    void func_332E60(void *a0);
    int func_0032C600(CombatSubsystemControllerInstance *self, int a1, int a2, int a3);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_FORMATION_H
