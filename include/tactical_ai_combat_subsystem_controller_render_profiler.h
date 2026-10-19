#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_RENDER_PROFILER_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_RENDER_PROFILER_H

struct SystemManager {};

extern SystemManager *D_004E3180;

struct TargetObj {};
struct Field24Obj {};

struct CombatSubsystemVtable {
    char pad00[0x30];
    void (*func_30)(void *self, int a1);
    void (*func_34)(void *self);
};

struct CombatSubsystemControllerInstance {
    CombatSubsystemVtable *m_vtable;
    char pad04[0x20 - 0x04];
    void *m_field_20;
    Field24Obj m_field_24;
    char pad34[0x10B - (0x24 + sizeof(Field24Obj))];
    unsigned char m_field_10B;
    char pad10C[0x12C - 0x10C];
    void *m_field_12C;
    TargetObj *m_target;
};

extern "C" {
    int func_2261C0(void);
    int func_184BF0(SystemManager *mgr, int channel);
    void func_1ABD90(void *a0, void *a1, unsigned char a2);
    void func_31AAB0(CombatSubsystemControllerInstance *self);
    void func_184B60(SystemManager *mgr, int channel, int val);
    void func_184BB0(SystemManager *mgr);
    void func_0032C500(CombatSubsystemControllerInstance *self);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_RENDER_PROFILER_H
