#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_UPDATE_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_UPDATE_H

struct SystemSub28 {
    char pad00[0xA0];
    short m_state;
};

struct SystemManager {
    char pad00[0x28];
    SystemSub28 *m_sub28;
    char pad2C[0x1C8 - 0x2C];
    int m_mode;
    int m_subtype;
};

struct MeshInstanceVtable {
    char pad00[0x118];
    int (*func_118)(void *self, int a1, int a2);
    void (*func_11C)(void *self, int a1, int a2);
    void (*func_120)(void *self, int a1, int a2);
};

struct CombatSubsystemMeshInstance {
    MeshInstanceVtable *m_vtable;
    char pad04[0x17C - 0x04];
    int m_active;
};

extern SystemManager *D_004E3180;

extern "C" {
    int func_185DC0(void *mgr, int flag);
    void func_1A5390(void *self);
    void func_1F65A0(void *self);
    int func_1A5010(void *self, int a1, int a2, short *s_4C, short *s_4E, int *s_48);
    int func_00328930(CombatSubsystemMeshInstance *self, int a1, int a2);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_UPDATE_H
