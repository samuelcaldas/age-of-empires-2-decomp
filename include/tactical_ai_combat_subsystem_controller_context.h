#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_CONTEXT_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_CONTEXT_H

struct SystemManagerVtable {
    char pad00[0x18];
    void (*func_18)(void *self, int a1, int a2);
};

struct ManagerSubA0 {
    char pad00[0xA0];
    int m_val_a0;
};

struct SystemManager {
    SystemManagerVtable *m_vtable;
    char pad04[0x28 - 0x04];
    ManagerSubA0 *m_sub_a0;
    char pad2C[0x1C8 - 0x2C];
    int m_mode;
    int m_field_1CC;
};

extern SystemManager *D_004E3180;
extern int D_004E2EA0;

struct ViewVtable {
    char pad00[0x8C];
    void (*func_8C)(void *self, int a1);
};

struct ViewObj {
    ViewVtable *m_vtable;
};

struct TargetVtable {
    char pad00[0xA8];
    void (*func_A8)(void *self, void *a1, void *a2, int a3, int t0, int t1, int t2, int t3);
    char padAC[0xDC - 0xAC];
    void (*func_DC)(void *self);
};

struct TargetSubCA8 {};

struct TargetObj {
    TargetVtable *m_vtable;
    char pad04[0xCA8 - 0x04];
    TargetSubCA8 *m_sub_ca8;
    char padCAC[0x1B30 - 0xCAC];
    TargetVtable *m_sub_1b30_vtable;
};

struct CombatSubsystemControllerInstance;

struct CombatSubsystemVtable {
    char pad00[0x28];
    void (*func_28)(void *self, int a1);
    char pad2C[0x110 - 0x2C];
    void (*func_110)(void *self);
    char pad114[0x12C - 0x114];
    void (*func_12C)(void *self, int a1, int a2, int a3, int t0);
};

struct CombatSubsystemControllerInstance {
    CombatSubsystemVtable *m_vtable;
    char pad04[0x108 - 0x04];
    unsigned char m_field_108;
    char pad109[0x130 - 0x109];
    TargetObj *m_target;
    char pad134[0x190 - 0x134];
    unsigned char m_field_190;
};

extern "C" {
    void func_1F65A0(CombatSubsystemControllerInstance *self);
    int func_0032D400(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0, void *buf, void *target_sub, int flag);
    int func_185DC0(SystemManager *mgr);
    int func_225590(int a0);
    void func_0032E580(CombatSubsystemControllerInstance *self, void *buf);
    void func_0032E6B0(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0);
    void func_31A720(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0);
    void func_0032E820(CombatSubsystemControllerInstance *self);
    void func_205EE0(void *target);
    int func_0032BF70(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_CONTEXT_H
