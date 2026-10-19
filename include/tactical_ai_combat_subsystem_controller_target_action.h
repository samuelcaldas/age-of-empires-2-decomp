#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_TARGET_ACTION_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_TARGET_ACTION_H

struct SystemManager {
    char pad00[0x1C8];
    int m_mode;
    int m_field_1CC;
};

extern int D_004E2EA0;
extern SystemManager *D_004E3180;

struct TargetObj {};
struct CombatSubsystemVtable {};

struct CombatSubsystemControllerInstance {
    CombatSubsystemVtable *m_vtable;
    char pad04[0x12C - 0x04];
    void *m_field_12C;
    TargetObj *m_target;
    char pad134[0x3408 - 0x134];
    void *m_view;
};

extern "C" {
    void func_0032E820(CombatSubsystemControllerInstance *self);
    int func_0032D400(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0, void *buf, void *target_sub, int flag);
    void func_0032E580(CombatSubsystemControllerInstance *self, void *buf);
    void func_0032E6B0(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0);
    void func_332E60(void *a0);
    int func_0032CBA0(CombatSubsystemControllerInstance *self, int a1, int a2, int a3);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_TARGET_ACTION_H
