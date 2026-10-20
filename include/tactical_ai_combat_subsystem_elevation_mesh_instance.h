#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_INSTANCE_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_INSTANCE_H

struct CombatSubsystemMeshInstance {
    void *m_vtable;
    char pad04[0xD8];
    int m_field_DC;
};

extern void *D_4DEBF0[];

extern "C" {
    void *func_1A2C20(void *self);
    void *func_003285D0(CombatSubsystemMeshInstance *self);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_ELEVATION_MESH_INSTANCE_H
