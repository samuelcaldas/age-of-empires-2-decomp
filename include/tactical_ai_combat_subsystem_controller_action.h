#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_ACTION_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_ACTION_H

struct SystemManager {
    char pad00[0x1C8];
    int m_mode;
    int m_field_1CC;
    char pad1D0[0x40C - 0x1D0];
    short m_field_40C;
};

extern SystemManager *D_004E3180;

struct TargetSubCA8 {
    void *m_vtable;
};

struct TargetObj {
    char pad00[0x70];
    void **m_list_70;
    char pad74[0xC6C - 0x74];
    float m_x;
    float m_y;
    char padC74[0xCA8 - 0xC74];
    TargetSubCA8 *m_sub_ca8;
};

struct CombatSubsystemVtable {
    char pad00[0x28];
    void (*func_28)(void *self, int a1);
    char pad2C[0x108 - 0x2C];
    void (*func_108)(void *self, int a1, int a2, int a3, int t0, int t1);
};

struct CombatSubsystemControllerInstance {
    CombatSubsystemVtable *m_vtable;
    char pad04[0x12C - 0x04];
    void *m_field_12C;
    TargetObj *m_target;
};

extern "C" {
    int func_185DC0(SystemManager *mgr);
    int func_0032D400(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0, void *t1, TargetSubCA8 *t2);
    void func_205EE0(TargetObj *target);
    void func_205CA0(TargetObj *target, void *a1, int a2);
    void func_00268410(void *a0, short *a1, short *a2, short *a3, short *t0);
    void func_0032E580(CombatSubsystemControllerInstance *self, void *a1);
    int func_123350(float val);
    void func_0031A720(void *a0, void *a1, void *a2);
    void func_001830E0(void *a0);
    void func_00262FA0(void *a0, void *a1, void *a2);
    void func_186010(SystemManager *mgr, void *a1, void *a2, void *a3);
    void func_1F6510(void *a0, void *a1, void *a2, void *a3);
    int func_0032A060(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int a4);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_ACTION_H
