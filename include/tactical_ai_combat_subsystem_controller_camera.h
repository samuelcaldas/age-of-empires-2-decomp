#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_CAMERA_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_CAMERA_H

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

extern SystemManager *D_004E3180;

struct TargetSubCA8 {};

struct TargetObj {
    char pad00[0xCA8];
    TargetSubCA8 *m_sub_ca8;
};

struct CombatSubsystemVtable {
    char pad00[0x28];
    void (*func_28)(void *self, int a1);
    char pad2C[0x108 - 0x2C];
    void (*func_108)(void *self, int a1, int a2, int a3, int t0, int t1);
};

struct CombatSubsystemControllerInstance {
    CombatSubsystemVtable *m_vtable;
    char pad04[0x130 - 0x04];
    TargetObj *m_target;
};

extern "C" {
    int func_185DC0(SystemManager *mgr);
    void func_205EE0(TargetObj *target);
    void func_1F6510(CombatSubsystemControllerInstance *self);
    int func_0032BCE0(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int a4);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_CAMERA_H
