#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_MODE_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_MODE_H

struct SystemManager;
extern SystemManager *D_004E3180;

struct CombatSubsystemControllerInstance {
    char pad00[0x3410];
    int m_field_3410;
    int m_field_3414;
    int m_field_3418;
    int m_field_341C;
    int m_field_3420;
    int m_field_3424;
    int m_field_3428;
    int m_field_342C;
};

extern "C" {
    int func_1880D0(SystemManager *mgr);
    unsigned int func_184C10(SystemManager *mgr);
    unsigned int func_184BD0(SystemManager *mgr, int a1);
    int func_185DC0(SystemManager *mgr);
    void func_185F00(SystemManager *mgr, int a1, int a2);
    void func_00329350(CombatSubsystemControllerInstance *self, int a1);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_MODE_H
