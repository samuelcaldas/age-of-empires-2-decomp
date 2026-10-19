#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PICK_QUERY_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PICK_QUERY_H

struct CombatSubsystemVtable {
    char pad00[0x120];
    int (*func_120)(void *self, int a1, int a2, int a3, int t0, int t1, int t2, int t3);
};

struct CombatSubsystemControllerInstance {
    CombatSubsystemVtable *m_vtable;
    char pad04[0x12C - 0x04];
    void *m_field_12C;
    void *m_target;
    char pad134[0x3408 - 0x134];
    void *m_view;
};

extern "C" {
    int func_0032D400(CombatSubsystemControllerInstance *self, int mode, int flag, int x, int y, void *buf, void *target_sub, int recurse_flag);
    int sub_31C7F0(CombatSubsystemControllerInstance *self, int mode, int flag, int x, int y, void *buf, void *target_sub, int recurse_flag);
    void func_117AF8(void *dest, int unused, int count);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PICK_QUERY_H
