#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_QUERY_SECONDARY_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_QUERY_SECONDARY_H

struct Object120Vtable {
    char pad00[0xB4];
    unsigned char (*func_B4)(void *self, int flag, float x, float y);
};

struct Object120 {
    char pad00[0x1B30];
    Object120Vtable *m_vtable;
};

struct SystemManagerVtable {
    char pad00[0x18];
    void (*func_18)(void *self, int a1, int a2);
};

struct SystemManager {
    SystemManagerVtable *m_vtable;
};

struct CombatSubsystemMeshInstance {
    char pad00[0x120];
    Object120 *m_obj_120;
};

extern int D_004E2EA0;
extern SystemManager *D_004E3180;

extern "C" {
    int func_1A5010(void *self, int a1, int a2, short *s_3C, short *s_3E, int *s_38);
    int func_00329070(CombatSubsystemMeshInstance *self, int a1, int a2);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_QUERY_SECONDARY_H
