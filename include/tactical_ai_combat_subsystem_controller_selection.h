#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_SELECTION_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_SELECTION_H

struct SystemManager {
    char pad00[0x1C8];
    int m_mode;
    int m_field_1CC;
};

extern SystemManager *D_004E3180;
extern void *D_004E2EA0;

struct CombatSubsystemVtable {
    char pad00[0x28];
    void (*func_28)(void *self, int a1);
    char pad2C[0x108 - 0x2C];
    void (*func_108)(void *self, int a1, int a2, int a3, int t0, int t1);
    void (*func_10C)(void *self, int a1, int a2);
    void (*func_110)(void *self);
};

struct TargetObj {
    char pad00[0xC6C];
    float m_x;
    float m_y;
};

struct CombatSubsystemControllerInstance {
    CombatSubsystemVtable *m_vtable;
    char pad04[0x130 - 0x04];
    TargetObj *m_target;
    char pad134[0x190 - 0x134];
    unsigned char m_field_190;
};

extern "C" {
    int func_185DC0(SystemManager *mgr);
    void func_1F65A0(CombatSubsystemControllerInstance *self);
    int func_225590(int a0);
    int func_0032D400(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int a4, void *buf, void *t2);
    void func_205EE0(TargetObj *target);
    void func_205CA0(TargetObj *target, void *item, int a2);
    void func_205F70(TargetObj *target, void *a1);
    void func_2066E0(void *a0, void *a1, void *a2);
    void func_205B30(TargetObj *target, void *a1);
    void func_001830E0(void *a0);
    void func_00262FA0(void *a0, void *a1, void *a2);
    int func_123350(float val);
    void func_1378C0(void *a0, void *a1);
    void func_0032E580(CombatSubsystemControllerInstance *self, void *buf);
    void func_0032E6B0(CombatSubsystemControllerInstance *self);
    int func_0032AAD0(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int a4);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_SELECTION_H
