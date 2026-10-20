#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_ORDER_DISPATCH_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_ORDER_DISPATCH_H

struct TargetSub12C {
    char pad00[120];
    void *m_sub_target;
};

struct SlotEntry {
    char pad00[0x34];
    int action_id;
    char pad38[0x40 - 0x38];
    int flag;
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
    void func_0032E6B0(CombatSubsystemControllerInstance *self, int action_id, int a2, int a3, int t0);
    void func_0032E820(CombatSubsystemControllerInstance *self);
    void sub_260ED0(void *target_sub);
    void func_0032E640(CombatSubsystemControllerInstance *self, int id);
    void *sub_260E50(void *target_sub, int action_id, int a2, int param, int a3);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_ORDER_DISPATCH_H
