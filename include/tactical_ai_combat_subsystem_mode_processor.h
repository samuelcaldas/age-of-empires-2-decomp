#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_PROCESSOR_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_PROCESSOR_H

struct SystemSub28 {
    char pad00[0xA0];
    short m_state;
};

struct SystemManagerVtable {
    char pad00[0x18];
    void (*func_18)(void *self, int a1, int a2);
};

struct SystemManager {
    SystemManagerVtable *m_vtable;
    char pad04[0x24];
    SystemSub28 *m_sub28;
    char pad2C[0x1C8 - 0x2C];
    int m_mode;
    int m_subtype;
};

struct Object120Vtable {
    char pad00[0xDC];
    void (*func_DC)(void *self, float x, float y, float z);
};

struct Object120 {
    char pad00[0x1B30];
    Object120Vtable *m_vtable;
};

struct MeshInstanceVtable {
    char pad00[0x118];
    int (*func_118)(void *self, int a1, int a2);
};

struct CombatSubsystemMeshInstance {
    MeshInstanceVtable *m_vtable;
    char pad04[0x104];
    unsigned char m_type_108;
    char pad109[0x120 - 0x109];
    Object120 *m_obj_120;
    char pad124[0x17C - 0x124];
    int m_active;
};

extern SystemManager *D_004E3180;

extern "C" {
    int func_185DC0(void *mgr, int flag);
    void func_1A5390(void *self);
    void func_1F65A0(void *self);
    int func_1A5010(void *self, int a1, int a2, short *s_5C, short *s_5E, int *s_58);
    void func_205EE0(void *obj);
    int func_00328D50(CombatSubsystemMeshInstance *self, int a1, int a2, int unused, int flag);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_PROCESSOR_H
