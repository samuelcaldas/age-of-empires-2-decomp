#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_TERRAIN_ACTION_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_TERRAIN_ACTION_H

struct SystemManagerVtable {
    char pad00[0x14];
    void (*func_14)(void *self, int a1, int a2);
    void (*func_18)(void *self, int a1, int a2); // slot 6, offset 0x18 (24 bytes)
    void (*func_1C)(void *self, int a1, int a2);
};

struct SystemManager {
    SystemManagerVtable *m_vtable;
    char pad04[0x1C8 - 0x04];
    int m_mode;
    int m_field_1CC;
};

struct TargetMethodVtable {
    char pad00[0xA8];
    int (*func_168)(void *self, void *sp104, void *sp110, int a3, int t0, int t1, int t2, int t3);
    char padAC[0xB4 - 0xAC];
    int (*func_180)(void *self, int sp92, ...);
};

struct TargetSubField6960 {
    TargetMethodVtable *m_vtable;
};

struct TargetObj {
    char pad00[0x1B30];
    TargetSubField6960 *m_sub6960;
};

struct CombatSubsystemControllerInstance {
    void *m_vtable;
    char pad04[0x130 - 0x04];
    TargetObj *m_target;
};

extern int D_004E2EA0;
extern SystemManager *D_004E3180;

extern "C" {
    int func_0032E0E0(CombatSubsystemControllerInstance *self, int a1, int a2);
    void func_0032E820(CombatSubsystemControllerInstance *self);
    int func_0032D400(CombatSubsystemControllerInstance *self, int mode, int flag, int x, int y, void *buf, void *target_sub, int recurse_flag);
    void func_0032E580(CombatSubsystemControllerInstance *self, void *buf);
    void func_0032E6B0(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_TERRAIN_ACTION_H
