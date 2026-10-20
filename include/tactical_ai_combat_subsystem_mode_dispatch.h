#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_DISPATCH_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_DISPATCH_H

struct SystemManager {
    char pad00[0x1C8];
    int m_mode;
};

struct CombatSubsystemMeshInstance {
    char pad00[0x17C];
    int m_active;
};

extern SystemManager *D_004E3180;

extern "C" {
    int func_185DC0(void *mgr, int flag);
    void func_1A5390(void *self);
    void func_1F65A0(void *self);
    int func_1A52D0(void *self, int a1, int a2);
    int func_00328820(CombatSubsystemMeshInstance *self, int a1, int a2);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_DISPATCH_H
