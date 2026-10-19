#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_CLEANUP_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_CLEANUP_H

struct TargetSub12C {
    char pad00[120];
    void *m_sub_target;
};

struct SlotSub {
    char pad00[52];
    short action_id;
};

struct SlotEntry {
    char pad00[0x28];
    SlotSub *m_sub;
    char pad2C[0x40 - 0x2C];
    unsigned char flag;
};

struct CombatSubsystemControllerInstance {
    char pad00[300];
    TargetSub12C *m_sub12c;
    char pad130[13364 - 304];
    SlotEntry *m_slots[10];
    int m_slot_action_ids[10];
    int m_slot_count;
};

extern "C" {
    void sub_260ED0(void *target_sub);
    void func_0032E820(CombatSubsystemControllerInstance *self);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_CLEANUP_H
