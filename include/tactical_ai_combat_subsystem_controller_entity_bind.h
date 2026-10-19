#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_ENTITY_BIND_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_ENTITY_BIND_H

struct CombatSubsystemControllerInstance {};

extern "C" {
    int func_0032E4B0(CombatSubsystemControllerInstance *self, int x, int y, char *out_name, int a4);
    int func_0032D400(CombatSubsystemControllerInstance *self, int mode, int flag, int x, int y, void *buf, void *target_sub, int recurse_flag);
    void *sub_1C8C00(void *handle);
    char *sub_1F6EA0(CombatSubsystemControllerInstance *self, void *sub_res);
    char *strcpy(char *dest, const char *src);
    void sub_1C8C10(void *handle);
    int sub_1F6EF0(CombatSubsystemControllerInstance *self, int x, int y, char *out_name, int a4);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_ENTITY_BIND_H
