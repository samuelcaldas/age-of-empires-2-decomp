#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_EVENT_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_EVENT_H

struct SystemManager {
    char pad00[0x1C8];
    int m_mode;
    int m_field_1CC;
};

extern SystemManager *D_004E3180;

struct CombatSubsystemVtable {
    char pad00[0x28];
    void (*func_28)(void *self, int a1);
    char pad2C[0x108 - 0x2C];
    void (*func_108)(void *self, int a1, int a2, int a3, int t0, int t1);
    void (*func_10C)(void *self, int a1, int a2);
    void (*func_110)(void *self);
};

struct CombatSubsystemControllerInstance {
    CombatSubsystemVtable *m_vtable;
    char pad04[0xE0 - 0x04];
    int m_field_E0;
    int m_field_E4;
    char padE8[0x190 - 0xE8];
    unsigned char m_field_190;
};

extern "C" {
    int func_185DC0(SystemManager *mgr);
    void func_1F65A0(CombatSubsystemControllerInstance *self);
    int func_0032A8F0(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int a4);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_EVENT_H
