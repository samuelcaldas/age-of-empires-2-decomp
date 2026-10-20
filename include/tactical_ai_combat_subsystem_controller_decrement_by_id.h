#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_DECREMENT_BY_ID_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_DECREMENT_BY_ID_H

struct TableEntry {
    int active;
    int pad4;
    int count;
    int decrement;
    int id;
};

struct CombatSubsystemControllerInstance {
    char pad00[9104];
    TableEntry *m_table;
    int pad9108;
    int m_count;
};

extern "C" {
    void func_0032E640(CombatSubsystemControllerInstance *self, int id);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_DECREMENT_BY_ID_H
