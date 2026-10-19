#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PULSE_RESET_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PULSE_RESET_H

struct SystemManager {};

extern SystemManager *D_004E3180;

struct CombatSubsystemControllerInstance {
    char pad00[0x190];
    unsigned char m_field_190;
    char pad191[0x341C - 0x191];
    int m_field_341C;
    int m_field_3420;
    int m_field_3424;
};

extern "C" {
    int func_1880D0(SystemManager *mgr);
    void func_185F00(SystemManager *mgr, int a1, int a2);
    void func_00324470(CombatSubsystemControllerInstance *self);
    void func_0032C480(CombatSubsystemControllerInstance *self);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PULSE_RESET_H
