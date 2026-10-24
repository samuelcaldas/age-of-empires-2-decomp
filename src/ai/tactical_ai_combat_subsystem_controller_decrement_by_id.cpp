#include "tactical_ai_combat_subsystem_controller_decrement_by_id.h"

void func_0032E640(CombatSubsystemControllerInstance *self, int id) {
    for (int i = 0; i < self->m_count; ++i) {
        TableEntry *entry = &self->m_table[i];
        if (entry->active == 1) {
            if (entry->id == id) {
                entry->count -= entry->decrement;
            }
        }
    }
}
