#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_COORD_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_COORD_H

struct SystemManager {
    char pad00[0x1C8];
    int m_mode;
};

extern SystemManager *D_004E3180;

struct CombatSubsystemControllerInstance;

struct CombatSubsystemVtable {
    char pad00[0x10C];
    void (*func_10C)(void *self, int a1, int a2);
    void (*func_110)(void *self);
};

struct CombatSubsystemControllerInstance {
    CombatSubsystemVtable *m_vtable;
    char pad04[0x190 - 0x04];
    unsigned char m_field_190;
};

extern "C" {
    int func_185DC0(SystemManager *mgr);
    void func_1F65A0(CombatSubsystemControllerInstance *self);
    int func_0032BE50(CombatSubsystemControllerInstance *self, int a1, int a2);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_COORD_H
